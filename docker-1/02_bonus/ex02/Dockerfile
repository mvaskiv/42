FROM ubuntu:16.04

RUN echo deb http://archive.ubuntu.com/ubuntu/ precise main universe > /etc/apt/sources.list.d/precise.list
RUN apt-get update
RUN apt-get -y install openvpn iptables socat curl sudo

RUN modprobe ip_tables
RUN echo 'ip_tables' >> /etc/modules

ADD bin /usr/local/sbin
VOLUME /etc/openvpn

EXPOSE 443/tcp
EXPOSE 8080/tcp
EXPOSE 1194/udp

CMD run

#run --privileged
