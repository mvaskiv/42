FROM debian:9

RUN apt-get update
RUN apt-get install -y gcc cmake vim gdb lldb valgrind
RUN mkdir /project/

WORKDIR /project/

ENTRYPOINT vim
