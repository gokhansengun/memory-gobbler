# Summary

A program which gobble memory gradually to test various cases with memory issues in containers.

It basically iteratively allocates a few amount of memory and keeps it.

# Usage

Takes 3 optional parameters.

First parameter is how much memory in MBs to be allocated to the end default 10 MB.
Second parameter defines how much memory in each iteration will be allocated and set, default is 1 MB.
Third parameter is the sleep of milliseconds between each iteration default is 1000 ms.

## Example

1. Allocate a total of 10 MBs memory in 10 iterations waiting 1 sec between

    ```bash
    docker run --rm gsengun/memory-gobbler:0.1
    ```

1. Allocate a total of 1000 MBs memory in 50 iterations (with 20 MBs each) waiting 200 ms between

    ```bash
    docker run --rm gsengun/memory-gobbler:0.1 1000 20 200
    ```
