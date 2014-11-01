#encoding:utf-8
import sys
import os
os.chdir(sys.path[0])
sys.path.append('../pub')
from Mydb import mysql
import time
import logging
from logging.handlers import RotatingFileHandler

mt_messages={}
max_id=0

##########################################
def init_env():
    
    #chdir
    os.chdir(sys.path[0])
    
    #init logging
    logfile = '/home/tkp/cdopr/logs/card/card_mg.log'
    Rthandler = RotatingFileHandler(logfile, maxBytes=1000*1024,backupCount=500)
    formatter = logging.Formatter('[%(asctime)s][%(levelname)s][1.00]:  %(message)s - %(filename)s:%(lineno)d')
    Rthandler.setFormatter(formatter)
    logger=logging.getLogger()
    logger.addHandler(Rthandler)
    logger.setLevel(logging.NOTSET)
def get_mt_messages_from_db():
    sql = "select * from wraith_card_message where 1"
    logging.info('%s',sql)
    records = mysql.queryAll(sql)
    for record in records:
        mt_messages[int(record['id'])] = record['message']
        
    return 




##########################################

def get_seq(record):
    card_value=int(record['mo_message'][-2:])
    sql = "select count(*) as seq from wraith_card_record where id<'%s' and  report=1 and order_id is NULL and phone_number='%s' and right(mo_message,2)='%d'"%(record['id'],record['phone_number'],card_value)
    #logging.info('%s',sql)
    records = mysql.queryAll(sql)
    seq = int(records[0]['seq'])+1
    return seq
    
def finish_order(record):
    card_value=int(record['mo_message'][-2:])
    sql = "select sum(fee) as sum from wraith_card_record where id='%s' or (id < %s and report=1 and order_id is NULL and phone_number='%s' and right(mo_message,2)='%d')"%(record['id'],record['id'],record['phone_number'],card_value)
    #logging.info('%s',sql)
    records = mysql.queryAll(sql)
    sum = int(records[0]['sum'])
    #logging.info("card_value:%d, already_get:%d",card_value,sum)
    if(sum >= card_value):
        #logging.info("true")
        return 1
    else:
        #logging.info("false")
        return 0


def get_mt_msg(record,seq,is_last):
    if(is_last == 1):
        return mt_messages[100]
    elif(seq == 1):
        return mt_messages[1]
    else:
        return mt_messages[2]

def update_mt_msg(record,mt_msg):
    
    seq=get_seq(record)
    sql="update wraith_message set mt_message='%s' where id='%s'"%(mt_msg,record['message_id']);
    #logging.info('sql:%s',sql)
    mysql.query(sql);
  
def update_record_info(record,mt_msg,card_no,card_sec,seq,is_last):      
    sql = "update wraith_card_record set send_mt_msg='1',mt_message='%s',seq='%d', card_no='%s',card_sec='%s',is_last='%s' where id='%s' "%(mt_msg,seq,card_no,card_sec,is_last,record['id'])
    #logging.info('%s',sql)
    mysql.query(sql)
    
    
    return

def update_record_status(record):
    sql = "update wraith_card_record set send_mt_message='1',mt_message='', where id='%s' "%(field,value,record['id'])
    #logging.info('%s',sql)
    mysql.query(sql)
    return


def fetch_A_card(card_value):
    sql = "select card_no,card_sec from wraith_card_no where status=0 and card_value='%s' limit 1"%(card_value)
    #logging.info('%s',sql)
    records = mysql.queryAll(sql)
    if(mysql.rowcount()):
        card_no = records[0]['card_no']
        card_sec = records[0]['card_sec']
        #logging.info("card_no:%s",card_no)
        sql="update wraith_card_no set status=1,update_time=NOW() where card_no='%s' limit 1"%(card_no)
        #logging.info('%s',sql)
        mysql.query(sql)
        return card_no,card_sec
    else:
        logging.info("no card!!!!!!")
        return ('0','0')
    
def send_mt_message(record):
    card_value=record['mo_message'][-2:]
    is_last = finish_order(record)
    seq = get_seq(record)  
    mt_msg=get_mt_msg(record,seq,is_last)
    if(is_last):
        card_no, card_sec = fetch_A_card(card_value);
    else:
        card_no=card_sec='000'
        
    mt_msg=mt_msg.replace('$CARD_NO',card_no)
    mt_msg=mt_msg.replace('$CARD_SEC',card_sec)
    mt_msg=mt_msg.replace('$CARD_VALUE',card_value)
    mt_msg=mt_msg.replace('$FEE',record['fee'])
    

    update_mt_msg(record,mt_msg)
    update_record_info(record,mt_msg,card_no,card_sec,seq,is_last)
    logging.info("sendmt:seq[%s]is_last[%s]mt_msg[%s]cardno[%s]card_sec[%s]"%(seq,is_last,mt_msg,card_no,card_sec))
##########################################


def update_report(record):
    sql='update wraith_card_record set report=(select report from wraith_message where id=%s) where id=%s'%(record['message_id'],record['id']);
    #logging.info('sql:%s',sql)
    mysql.query(sql);
    #affected_num = mysql.conn.affected_rows()
    #logging.info('affected_rows:%d'%(affected_num))
    return


##########################################

    
def delete_card(card_no):
    sql="update wraith_card_no set status=2,update_time=NOW() where card_no='%s' limit 1"%(card_no)
    #logging.info('%s',sql)
    mysql.query(sql)
    
def gen_order(record):
    card_value=int(record['mo_message'][-2:])
    sql="update wraith_card_record set order_id='%s' where id<=%s and report=1 and order_id is NULL and phone_number='%s' and right(mo_message,2)='%d'"%('1',record['id'],record['phone_number'],card_value)
    #logging.info('%s',sql)
    mysql.query(sql)
    return

 
###############    
def send_mt_message_batch():
    sql="select * from wraith_card_record where in_time > NOW()-interval 3 hour and send_mt_msg=0 order by id asc limit 1"
    #logging.info('%s',sql)
    records = mysql.queryAll(sql)
    for record in records:
        send_mt_message(record)
 
def update_report_batch():
    sql="select * from wraith_card_record where in_time > NOW()-interval 3 hour and send_mt_msg=1 and report is NULL order by id asc limit 1"
    #logging.info('%s',sql)
    records = mysql.queryAll(sql)
    for record in records:
        update_report(record)
        

def gen_order_batch():
    sql="select * from wraith_card_record where in_time > NOW()-interval 3 hour and report=1 and is_last=1 and order_id is NULL limit 1"
    #logging.info('%s',sql)
    records = mysql.queryAll(sql)
    for record in records:
        gen_order(record)
        delete_card(record['card_no'])     
##################################
def main():
    
    init_env()
    get_mt_messages_from_db()
    logging.info('starting...')
    
    while True:
        send_mt_message_batch()
        update_report_batch()
        gen_order_batch()
        time.sleep(0.1)
        
if __name__ == "__main__":
    main()
    
    