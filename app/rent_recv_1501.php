<?php


require_once('/home/log4php/php/Logger.php');
require_once('mysql.php');
require_once('des.php');

Logger::configure('log4php_config.xml');
$logging = Logger::getLogger('recvfqishun');


if(!isset($_REQUEST['data']))
{
	$logging->info("arguments error:");
	echo "arguments error!";
	exit;
} 

// mt 加密前参数以@#分隔 依次为手机号@#指令@#长号码@#linkid@下行内容
$data=$_REQUEST['data'];
//$logging->info("data:".$data);

$key='wraith55';
$Des_Crypt = new Des_Crypt($key);
$data = $Des_Crypt->decrypt($data,$key,true);
$data = urldecode($data);
$logging->info("data:".$data);
$data_array = explode("@#",$data);


$phone_number = $data_array[0];
$cmd = $data_array[1];
$sp_number = $data_array[2]; 
$linkid = $data_array[3];
$mt_message = $data_array[4];

//update mt message
$sql = sprintf("update wraith_message set mt_message='%s' where linkid='%s' limit 1",$mt_message,$linkid);
$logging->info($sql);
mysqli_query($mysqli, "set names utf8");
$res = mysqli_query($mysqli, $sql);
if (!$res) {
	$logging->info("Failed to run query: (" . $mysqli->errno . ") " . $mysqli->error);
	exit;
}

