docker build -t serv . ; docker run --rm -it -p 9987:9987/udp -p 10011:10011/tcp -p 30033:30033/tcp serv
