FROM ruby:2.2

RUN apt-get update
RUN apt-get install -y nodejs gem
RUN gem install rails

ONBUILD RUN mkdir /opt/app/
ONBUILD WORKDIR /opt/app

ONBUILD COPY app/ /opt/app/
ONBUILD RUN gem install bundler
ONBUILD RUN bundle install
