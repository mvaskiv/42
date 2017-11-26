ifconfig -a | grep 'ether ' | tr -d ' ' | cut -c 6-22
