#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

#define NANO_SECONDS (unsigned int) 1e9
#define MICRO_SECONDS (unsigned int) 1e6
#define MILLI_SECONDS (unsigned int) 1e3

// based on the code below
// https://unix.stackexchange.com/questions/1367/how-to-test-swap-partition/1368#1368
// usage: maxMb eachMb sleepInMs
int main(int argc, char** argv) {
    int max = 10;
    int mb = 0;
    int sleepInMs = 1000;
    int eachMb = 1;
    char* buffer;

    // make stdout and stderr unbuffered so as to see the console output immediately in the contianer
    setvbuf(stdout, NULL, _IONBF, 0);
    setvbuf(stderr, NULL, _IONBF, 0);

    if (argc > 1)
        max = atoi(argv[1]);

    if (argc > 2)
        eachMb = atoi(argv[2]);

    if (argc > 3)
        sleepInMs = atoi(argv[3]);

    while ((buffer = malloc(eachMb * 1024 * 1024)) != NULL && mb < max) {
        memset(buffer, 0, eachMb * 1024 * 1024);
        mb += eachMb;

        printf("Allocated %d MB\n", mb);

        struct timespec ts;
        ts.tv_sec = sleepInMs / MILLI_SECONDS;
        ts.tv_nsec = sleepInMs * MICRO_SECONDS - ts.tv_sec * NANO_SECONDS;
        nanosleep(&ts, NULL);
    }

    while (1) {
        printf("Allocations are done, just waiting now ...\n");

        struct timespec ts;
        ts.tv_sec = 2;
        ts.tv_nsec = 0;
        nanosleep(&ts, NULL);
    }

    return 0;
}
