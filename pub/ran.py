#encoding:utf-8

import sys
import os
import string
import random
import logging
import redis

class Impb:
    
    r = False
    def __init__(self):
        self.r = redis.StrictRedis(host='localhost', port=16379, db=4)
        
    def in_po(self,p,phone_number):
        po=100*p
        a=random.randint(1,100)
        if(a <= po):
            if(self.r.exists(phone_number)):#同一个用户一天只能扣量一次
                re=False
            else:
                re=True
                self.r.setex(phone_number,86400,1)
        else:
            re=False
        
        #logging.info("p:%f,re:%s",po,re)
        #print "p:%f,re:%s"%(po,re)
        return re
def main():
    
    for i in range(string.atoi(sys.argv[1])):
       print in_po(0.21)
        #phone_number='133%s'%("".join(random.sample('01234567890123456789012345678901234567890123456789',8)))
        #mo_message=random.choice(['112', '1232'])
        #gwid=random.randint(1,20)
        
if __name__ == "__main__":
    main()