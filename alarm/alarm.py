#encoding:gb2312
import smtplib  
import sys
import os
os.chdir(sys.path[0])
sys.path.append('../pub')
from Mydb import mysql
import logging
from logging.handlers import RotatingFileHandler

from email.mime.text import MIMEText  
mailto_list=["tengkeping@gmail.com"] 
mail_host="smtp.qq.com"  #���÷�����
mail_user="24214044"    #�û���
mail_pass="qepapap608058"   #���� 
mail_postfix="qq.com"  #������ĺ�׺
  
def send_mail(to_list,sub,content):  #to_list���ռ��ˣ�sub�����⣻content���ʼ�����
    me="system alarm"+"<"+mail_user+"@"+mail_postfix+">"   #�����hello�����������ã��յ��ź󣬽�����������ʾ
    msg = MIMEText(content,_subtype='html',_charset='gb2312')    #����һ��ʵ������������Ϊhtml��ʽ�ʼ�
    msg['Subject'] = sub    #��������
    msg['From'] = me  
    msg['To'] = ";".join(to_list)  
    try:  
        s = smtplib.SMTP()  
        s.connect(mail_host)  #����smtp������
        s.login(mail_user,mail_pass)  #��½������
        s.sendmail(me, to_list, msg.as_string())  #�����ʼ�
        s.close()  
        return True  
    except Exception, e:  
        print str(e)  
        return False  
    
def init_env():
    #chdir
    os.chdir(sys.path[0])
    
    logfile = '/home/tkp/cdopr/logs/alarm/alarm.log'
    Rthandler = RotatingFileHandler(logfile, maxBytes=1000*1024,backupCount=500)
    formatter = logging.Formatter('[%(asctime)s][%(levelname)s][1.00]:  %(message)s - %(filename)s:%(lineno)d')
    Rthandler.setFormatter(formatter)
    logger=logging.getLogger()
    logger.addHandler(Rthandler)
    logger.setLevel(logging.NOTSET)
    
def check():
    
    fuck=0
    errmsg=''
    ######
    sql = "select count(*) as num from wraith_message where mo_status is NULL"
    n = int(mysql.queryAll(sql)[0]['num'])
    
    #print n
    if(n<20):
        errmsg='wait number: %d'%n
        fuck=1
    ###### 
    #print n,fuck,errmsg
    return fuck,errmsg
def send_alarm(errmsg):            
    
    if send_mail(mailto_list,"system alarm",errmsg):  
        result='ok'
    else:  
        result='fail'
    logging.info('send mail:%s,%s',errmsg,result) 
          
def main():
    init_env()
    logging.info("starting...")
    fuck,errmsg = check()
    if(fuck):
        send_alarm(errmsg)

           
if __name__ == '__main__':  
     main()
     
     