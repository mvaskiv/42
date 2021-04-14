FROM debian

RUN apt-get update
RUN apt-get install -y apt-utils wget tar bzip2 lbzip2
RUN wget -P ~/ http://dl.4players.de/ts/releases/3.0.13.8/teamspeak3-server_linux_amd64-3.0.13.8.tar.bz2
RUN tar xfv ~/teamspeak3-server_linux_amd64-3.0.13.8.tar.bz2

EXPOSE 9987/udp
EXPOSE 30033
EXPOSE 10011

ENTRYPOINT /teamspeak3-server_linux_amd64/ts3server_minimal_runscript.sh
