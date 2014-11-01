 #encoding:utf-8
import sys
import os
from Mydb import mysql
import random
import logging
 ###=========
def get_random_content(messages):      
    ran_number = random.randint(0,len(messages)-1)
    return messages[ran_number]['content']

def app_default(cmd_info,record):
    #print cmd_info
    #print get_random_content(cmd_info['messages'])
    #sys.exit()
    return get_random_content(cmd_info['messages'])


def app_card(cmd_info,record):
   
    #insert into wraith_card_record
    sql =  "insert into wraith_card_record set mo_message='%s', phone_number='%s',in_time=NOW(),fee='%d',message_id='%s'"%(record['mo_message'],record['phone_number'],int(cmd_info['fee'])/100,record['id'])
    logging.info(sql)
    mysql.query(sql)
    
    return ''