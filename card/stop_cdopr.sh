kill `ps ax -H|egrep "card_mg.py"|grep -v grep|grep -v mn.sh|awk '{print $1}'` > /dev/null 2>&1
