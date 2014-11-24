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
	phone_number=random.choice(['13011111111','13022222222','13033333333','13055555555','13044444444'])
        sp_number='10660766'
        #mo_message=random.choice(['801', '802', '803'])
        mo_message=random.choice(['801'])
        linkid="".join(random.sample('012345678901234567890123456789012345678901234567890123456789',20))
        #gwid=random.randint(1,20)
        gwid=42
        
        sql = "insert into wraith_message(motime,phone_number,mo_message,sp_number,linkid,gwid,report)values(NOW(),'%s','%s','%s','%s','%s','1')"%(phone_number,mo_message,sp_number,linkid,gwid)
        print sql
        mysql.cur.execute(sql)
        
        #time.sleep(2)
if __name__ == "__main__":
    main()
