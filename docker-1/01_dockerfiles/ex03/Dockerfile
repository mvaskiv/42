FROM ubuntu

RUN apt-get update
RUN apt-get install -y ca-certificates curl openssh-server postfix

WORKDIR /tmp/

ENV GITLAB_OMNIBUS_CONFIG="external_url 'http://192.168.99.100:30080'; gitlab_rails['gitlab_shell_ssh_port']=30022;"

RUN curl -LO https://packages.gitlab.com/install/repositories/gitlab/gitlab-ce/script.deb.sh
RUN bash /tmp/script.deb.sh
RUN EXTERNAL_URL="http://gitlab.example.com" apt-get install gitlab-ce 

EXPOSE 10022
EXPOSE 30022
EXPOSE 30080

ENTRYPOINT gitlab-ctl reconfigure
