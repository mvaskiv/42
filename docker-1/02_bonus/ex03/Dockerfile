FROM ubuntu:16.04

RUN apt-get update
RUN apt-get install -y wget apt-transport-https sudo

RUN wget -qO - https://dl.winehq.org/wine-builds/Release.key | apt-key add -
RUN echo deb https://dl.winehq.org/wine-builds/ubuntu/ precise main universe > /etc/apt/sources.list.d/precise.list
RUN apt-get update
RUN apt-get build-dep -y wine
RUN apt-get install -y wine


# COPY app/ /app
# WORKDIR /app
# RUN wine [program] [arguments ...]
