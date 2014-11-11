#encoding:utf-8

import sys
import os
os.chdir(sys.path[0])
sys.path.append('../pub')
from Mydb import mysql
import string
import random
import time

def main():
    
    for i in range(string.atoi(sys.argv[1])):
        #phone_number='133%s'%("".join(random.sample('01234567890123456789012345678901234567890123456789',8)))
        card_no="".join(random.sample('012345678901234567890123456789012345678901234567890123456789',20))
        card_sec="".join(random.sample('012345678901234567890123456789012345678901234567890123456789',20))
        #gwid=random.randint(1,20)
        sql = "insert into wraith_card_no(card_no,card_sec,card_value)values('%s','%s','10')"%(card_no,card_sec)
        print sql
        mysql.cur.execute(sql)
        
        #time.sleep(2)
if __name__ == "__main__":
    main()
