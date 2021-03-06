/* soapClient.c
   Generated by gSOAP 2.8.15 from ctcc_sms_notification_service_2_1.h

Copyright(C) 2000-2013, Robert van Engelen, Genivia Inc. All Rights Reserved.
The generated code is released under ONE of the following licenses:
GPL or Genivia's license for commercial use.
This program is released under the GPL with the additional exemption that
compiling, linking, and/or using OpenSSL is allowed.
*/

#if defined(__BORLANDC__)
#pragma option push -w-8060
#pragma option push -w-8004
#endif
#include "soapH.h"
#ifdef __cplusplus
extern "C" {
#endif

SOAP_SOURCE_STAMP("@(#) soapClient.c ver 2.8.15 2013-07-13 12:59:03 GMT")


SOAP_FMAC5 int SOAP_FMAC6 soap_call___ns1__notifySmsReception(struct soap *soap, const char *soap_endpoint, const char *soap_action, struct ns2__notifySmsReception *ns2__notifySmsReception, struct ns2__notifySmsReceptionResponse *ns2__notifySmsReceptionResponse)
{	struct __ns1__notifySmsReception soap_tmp___ns1__notifySmsReception;
	if (soap_endpoint == NULL)
		soap_endpoint = "http://localhost:9080/SmsNotificationService/services/SmsNotification";
	if (soap_action == NULL)
		soap_action = "";
	soap->encodingStyle = NULL;
	soap_tmp___ns1__notifySmsReception.ns2__notifySmsReception = ns2__notifySmsReception;
	soap_begin(soap);
	soap_serializeheader(soap);
	soap_serialize___ns1__notifySmsReception(soap, &soap_tmp___ns1__notifySmsReception);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put___ns1__notifySmsReception(soap, &soap_tmp___ns1__notifySmsReception, "-ns1:notifySmsReception", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_connect(soap, soap_url(soap, soap_endpoint, NULL), soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put___ns1__notifySmsReception(soap, &soap_tmp___ns1__notifySmsReception, "-ns1:notifySmsReception", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!ns2__notifySmsReceptionResponse)
		return soap_closesock(soap);
	soap_default_ns2__notifySmsReceptionResponse(soap, ns2__notifySmsReceptionResponse);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	soap_get_ns2__notifySmsReceptionResponse(soap, ns2__notifySmsReceptionResponse, "ns2:notifySmsReceptionResponse", "ns2:notifySmsReceptionResponse");
	if (soap->error)
		return soap_recv_fault(soap, 0);
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	return soap_closesock(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 soap_call___ns1__notifySmsDeliveryReceipt(struct soap *soap, const char *soap_endpoint, const char *soap_action, struct ns2__notifySmsDeliveryReceipt *ns2__notifySmsDeliveryReceipt, struct ns2__notifySmsDeliveryReceiptResponse *ns2__notifySmsDeliveryReceiptResponse)
{	struct __ns1__notifySmsDeliveryReceipt soap_tmp___ns1__notifySmsDeliveryReceipt;
	if (soap_endpoint == NULL)
		soap_endpoint = "http://localhost:9080/SmsNotificationService/services/SmsNotification";
	if (soap_action == NULL)
		soap_action = "";
	soap->encodingStyle = NULL;
	soap_tmp___ns1__notifySmsDeliveryReceipt.ns2__notifySmsDeliveryReceipt = ns2__notifySmsDeliveryReceipt;
	soap_begin(soap);
	soap_serializeheader(soap);
	soap_serialize___ns1__notifySmsDeliveryReceipt(soap, &soap_tmp___ns1__notifySmsDeliveryReceipt);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put___ns1__notifySmsDeliveryReceipt(soap, &soap_tmp___ns1__notifySmsDeliveryReceipt, "-ns1:notifySmsDeliveryReceipt", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_connect(soap, soap_url(soap, soap_endpoint, NULL), soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put___ns1__notifySmsDeliveryReceipt(soap, &soap_tmp___ns1__notifySmsDeliveryReceipt, "-ns1:notifySmsDeliveryReceipt", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!ns2__notifySmsDeliveryReceiptResponse)
		return soap_closesock(soap);
	soap_default_ns2__notifySmsDeliveryReceiptResponse(soap, ns2__notifySmsDeliveryReceiptResponse);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	soap_get_ns2__notifySmsDeliveryReceiptResponse(soap, ns2__notifySmsDeliveryReceiptResponse, "ns2:notifySmsDeliveryReceiptResponse", "ns2:notifySmsDeliveryReceiptResponse");
	if (soap->error)
		return soap_recv_fault(soap, 0);
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	return soap_closesock(soap);
}

#ifdef __cplusplus
}
#endif

#if defined(__BORLANDC__)
#pragma option pop
#pragma option pop
#endif

/* End of soapClient.c */
