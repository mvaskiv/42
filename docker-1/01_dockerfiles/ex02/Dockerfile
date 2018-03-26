FROM ruby:2.2

RUN apt-get update
RUN apt-get install -y nodejs gem
RUN gem install rails
RUN mkdir /app/

WORKDIR /opt/app

COPY /app/Gemfile /opt/app/
RUN gem install bundler
RUN bundle install

COPY ./* /opt/app/

EXPOSE 3000

ENTRYPOINT ["bundle", "exec"]

CMD ["rails", "server", "-b", "0.0.0.0"]
