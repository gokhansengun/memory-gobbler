FROM ubuntu:18.04 AS compiler

RUN apt-get update
RUN apt-get install -y build-essential

COPY gobbler.c /

RUN gcc -static gobbler.c -o gobbler

FROM alpine:3.7

COPY --from=compiler /gobbler /usr/local/bin

ENTRYPOINT [ "/usr/local/bin/gobbler" ]

