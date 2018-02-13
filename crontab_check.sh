#!/bin/bash

hashread=$(md5sum /etc/crontab | cut -d ' ' -f1)
BASEDIR=$(dirname "$0")
line="0 0 * * * /home/$USER/Documents/crontab_check.sh"

if [[ ! $(crontab -l | grep 'crontab_check') ]]
then
	(crontab -l; echo "$line") | crontab -
	(echo $hashread > /home/$USER/Documents/cron_last_hash)
	(cp $BASEDIR/crontab_check.sh /home/$USER/Documents/)
fi
hashoriginal=$(cat /home/$USER/Documents/cron_last_hash)
if [[ $hashread != $hashoriginal ]]
then
	(echo "md5 mismatch" | mail -s "intruders" root@debian)
fi
