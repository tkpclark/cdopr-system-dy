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

def get_order_count(record):
    card_value=int(record['mo_message'][-2:])
    sql = "select count(*) as count from wraith_card_record where report=1 and order_id=0 and phone_number='%s' and right(mo_message,2)='%d'"%(record['phone_number'],card_value)
    logging.info('%s',sql)
    records = mysql.queryAll(sql)
    count = int(records[0]['count'])
    return count
    
def finish_order(record):
    card_value=int(record['mo_message'][-2:])
    sql = "select sum(fee) as sum from wraith_card_record where id='%s' or (report=1 and order_id=0 and phone_number='%s' and right(mo_message,2)='%d')"%(record['id'],record['phone_number'],card_value)
    logging.info('%s',sql)
    records = mysql.queryAll(sql)
    sum = int(records[0]['sum'])
    logging.info("card_value:%d, already_get:%d",card_value,sum)
    if(sum >= card_value):
        logging.info("true")
        return True
    else:
        logging.info("false")
        return False
    
def get_mt_messages_from_db():
    sql = "select * from wraith_card_message where 1"
    logging.info('%s',sql)
    records = mysql.queryAll(sql)
    for record in records:
        mt_messages[int(record['id'])] = record['message']
        
    print mt_messages
    return 

def update_mt_message(record):
    if(finish_order(record) == True):
        seq=3
    else:
        count = get_order_count(record)
        if count == 0:
            seq=1
        else:
            seq=2
    logging.info("seq:%d",seq)
    sql="update wraith_message set mt_message='%s' where id='%s'"%(mt_messages[seq],record['message_id']);
    logging.info('sql:%s',sql)
    mysql.query(sql);
    return
    return 

def update_report(record):
    sql='update wraith_card_record set report=(select report from wraith_message where id=%s) where id=%s'%(record['message_id'],record['id']);
    logging.info('sql:%s',sql)
    mysql.query(sql);
    affected_num = mysql.conn.affected_rows()
    logging.info('affected_rows:%d'%(affected_num))
    return

def update_record_status(record,field,value):
    sql = "update wraith_card_record set %s='%s' where id='%s' "%(field,value,record['id'])
    logging.info('%s',sql)
    mysql.query(sql)
    return


def fetch_A_card(card_value):
    sql = "select card_no from wraith_card_no where status=0 and card_value='%s' limit 1"%(card_value)
    logging.info('%s',sql)
    records = mysql.queryAll(sql)
    if(mysql.rowcount()):
        card_no = records[0]['card_no']
        logging.info("card_no:%s",card_no)
        
        sql="update wraith_card_no set status=1,update_time=NOW() where card_no='%s'"%(card_no)
        logging.info('%s',sql)
        mysql.query(sql)
        return card_no
    else:
        logging.info("no card!!!!!!")
        return False

def gen_order(record):
    card_value=record['mo_message'][-2:]
    card_no = fetch_A_card(card_value);
    if(card_no != False):
        sql="insert into wraith_card_order set phone_number='%s',card_no='%s',card_value='%s',order_time=NOW()"%(record['phone_number'],card_no,card_value)
        logging.info('%s',sql)
        mysql.query(sql)
        
        card_value=int(record['mo_message'][-2:])
        sql="update wraith_card_record set order_id='%s' where report=1 and order_id=0 and phone_number='%s' and right(mo_message,2)='%d'"%(mysql.getLastInsertId,record['phone_number'],card_value)
        logging.info('%s',sql)
        mysql.query(sql)
    return

def routin():
    sql="select * from wraith_card_record where in_time > NOW()-interval 3 hour and order_id=0"
    logging.info('%s',sql)
    records = mysql.queryAll(sql)
    for record in records:
        logging.info("==========")
        #更新状态报告
        logging.info(record)
        logging.info("++++update report++++")
        if record['report'] == 'None':
            update_report(record)
            
        #未发mt的先发mt
        logging.info("++++send mt_message++++")
        if record['send_mt_msg'] == '0':
            update_mt_message(record)
            update_record_status(record,'send_mt_msg',1)
            
        #如果消息是成功的，则归入某订单，
        logging.info("++++check_order++++")
        if record['report'] == '1':
            if finish_order(record):
                gen_order(record)
               
    time.sleep(5)
    return

def main():
    
    init_env()
    get_mt_messages_from_db()
    logging.info('starting...')
    
    while True:
        routin()

if __name__ == "__main__":
    main()