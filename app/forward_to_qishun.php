<?php
	require_once('/home/log4php/php/Logger.php');
	//require_once('AES_official.php');
	
	Logger::configure('log4php_config.xml');
	$logging = Logger::getLogger('send2qishun');

	require_once('des.php');

	//齐顺
	//mo 加密前参数依次为 手机号#指令#长号码#linkid
	//mr 加密前参数依次为 手机号#指令#长号码#linkid#状态报告
	
	global $logging;
	global $mysqli;

	///des
	$key='wraith55';
	$Des_Crypt = new Des_Crypt($key);
	
	if($_REQUEST['forward_type']=="mo")//send mo
	{
		$data = sprintf("%s#%s#%s#%s",$_REQUEST['phone_number'],$_REQUEST['message'],$_REQUEST['sp_number'],$_REQUEST['linkid']);
		//plaintext
		$logging->info("data plain text:".$data);
		$data = $Des_Crypt->encrypt($data,$key,true);
		$data = urlencode($data);
		$url = "http://124.160.238.117/mobile/servlet/ReceiverSpzyData?data=".$data;
	}
	else if($_REQUEST['forward_type']=="mr")//send mr
	{
		$data = sprintf("%s#%s#%s#%s#%s",$_REQUEST['phone_number'],$_REQUEST['message'],$_REQUEST['sp_number'],$_REQUEST['linkid'],$_REQUEST['report']);
		//plaintext
		$logging->info("data plain text:".$data);
		$data = $Des_Crypt->encrypt($data,$key,true);
		$data = urlencode($data);
		$url = "http://124.160.238.117/mobile/servlet/ReceiverSpzyMR?data=".$data;
	}
	else//wait for report
	{
		exit;
	}
	

	$logging->info("url:".$url);
	
	$resp = "(null)";
	$resp = file_get_contents($url);
	$resp = trim($resp);
	$logging->info("resp:".$resp);
	echo $resp;



