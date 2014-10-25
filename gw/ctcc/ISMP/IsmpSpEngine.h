/* IsmpSpEngine.h
   Generated by wsdl2h 2.8.15 from IsmpSpEngine.wsdl and typemap.dat
   2013-08-09 08:40:48 GMT

   DO NOT INCLUDE THIS FILE DIRECTLY INTO YOUR PROJECT BUILDS
   USE THE soapcpp2-GENERATED SOURCE CODE FILES FOR YOUR PROJECT BUILDS

   gSOAP XML Web services tools.
   Copyright (C) 2000-2013 Robert van Engelen, Genivia Inc. All Rights Reserved.
   Part of this software is released under one of the following licenses:
   GPL or Genivia's license for commercial use.
*/

/** @page page_notes Usage Notes

NOTE:

 - Run soapcpp2 on IsmpSpEngine.h to generate the SOAP/XML processing logic.
   Use soapcpp2 -I to specify paths for #import
   To build with STL, 'stlvector.h' is imported from 'import' dir in package.
   Use soapcpp2 -j to generate improved proxy and server classes.
 - Use wsdl2h -c and -s to generate pure C code or C++ code without STL.
 - Use 'typemap.dat' to control namespace bindings and type mappings.
   It is strongly recommended to customize the names of the namespace prefixes
   generated by wsdl2h. To do so, modify the prefix bindings in the Namespaces
   section below and add the modified lines to 'typemap.dat' to rerun wsdl2h.
 - Use Doxygen (www.doxygen.org) on this file to generate documentation.
 - Use wsdl2h -R to generate REST operations.
 - Use wsdl2h -nname to use name as the base namespace prefix instead of 'ns'.
 - Use wsdl2h -Nname for service prefix and produce multiple service bindings
 - Use wsdl2h -d to enable DOM support for xsd:anyType.
 - Use wsdl2h -g to auto-generate readers and writers for root elements.
 - Use wsdl2h -b to auto-generate bi-directional operations (duplex ops).
 - Struct/class members serialized as XML attributes are annotated with a '@'.
 - Struct/class members that have a special role are annotated with a '$'.

WARNING:

   DO NOT INCLUDE THIS ANNOTATED FILE DIRECTLY IN YOUR PROJECT SOURCE CODE.
   USE THE FILES GENERATED BY soapcpp2 FOR YOUR PROJECT'S SOURCE CODE:
   THE soapStub.h FILE CONTAINS THIS CONTENT WITHOUT ANNOTATIONS.

LICENSE:

@verbatim
--------------------------------------------------------------------------------
gSOAP XML Web services tools
Copyright (C) 2000-2013, Robert van Engelen, Genivia Inc. All Rights Reserved.

This software is released under one of the following two licenses:
GPL or Genivia's license for commercial use.
--------------------------------------------------------------------------------
GPL license.

This program is free software; you can redistribute it and/or modify it under
the terms of the GNU General Public License as published by the Free Software
Foundation; either version 2 of the License, or (at your option) any later
version.

This program is distributed in the hope that it will be useful, but WITHOUT ANY
WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A
PARTICULAR PURPOSE. See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with
this program; if not, write to the Free Software Foundation, Inc., 59 Temple
Place, Suite 330, Boston, MA 02111-1307 USA

Author contact information:
engelen@genivia.com / engelen@acm.org

This program is released under the GPL with the additional exemption that
compiling, linking, and/or using OpenSSL is allowed.
--------------------------------------------------------------------------------
A commercial-use license is available from Genivia, Inc., contact@genivia.com
--------------------------------------------------------------------------------
@endverbatim

*/


//gsoapopt cw

/******************************************************************************\
 *                                                                            *
 * Definitions                                                                *
 *   http://sp.ismp.chinatelecom.com                                          *
 *                                                                            *
\******************************************************************************/


/******************************************************************************\
 *                                                                            *
 * Import                                                                     *
 *                                                                            *
\******************************************************************************/


/******************************************************************************\
 *                                                                            *
 * Schema Namespaces                                                          *
 *                                                                            *
\******************************************************************************/


/* NOTE:

It is strongly recommended to customize the names of the namespace prefixes
generated by wsdl2h. To do so, modify the prefix bindings below and add the
modified lines to typemap.dat to rerun wsdl2h:

ns1 = "http://sp.ismp.chinatelecom.com"
ns2 = "http://req.sp.ismp.chinatelecom.com"
ns3 = "http://rsp.sp.ismp.chinatelecom.com"

*/

#define SOAP_NAMESPACE_OF_ns2	"http://req.sp.ismp.chinatelecom.com"
//gsoap ns2   schema namespace:	http://req.sp.ismp.chinatelecom.com
//gsoap ns2   schema elementForm:	qualified
//gsoap ns2   schema attributeForm:	unqualified

#define SOAP_NAMESPACE_OF_ns1	"http://sp.ismp.chinatelecom.com"
//gsoap ns1   schema namespace:	http://sp.ismp.chinatelecom.com
//gsoap ns1   schema elementForm:	qualified
//gsoap ns1   schema attributeForm:	unqualified

#define SOAP_NAMESPACE_OF_ns3	"http://rsp.sp.ismp.chinatelecom.com"
//gsoap ns3   schema namespace:	http://rsp.sp.ismp.chinatelecom.com
//gsoap ns3   schema elementForm:	qualified
//gsoap ns3   schema attributeForm:	unqualified

/******************************************************************************\
 *                                                                            *
 * Built-in Schema Types and Top-Level Elements and Attributes                *
 *                                                                            *
\******************************************************************************/



/******************************************************************************\
 *                                                                            *
 * Schema Types and Top-Level Elements and Attributes                         *
 *   http://req.sp.ismp.chinatelecom.com                                      *
 *                                                                            *
\******************************************************************************/


/******************************************************************************\
 *                                                                            *
 * Schema Types and Top-Level Elements and Attributes                         *
 *   http://sp.ismp.chinatelecom.com                                          *
 *                                                                            *
\******************************************************************************/


/******************************************************************************\
 *                                                                            *
 * Schema Types and Top-Level Elements and Attributes                         *
 *   http://rsp.sp.ismp.chinatelecom.com                                      *
 *                                                                            *
\******************************************************************************/


/******************************************************************************\
 *                                                                            *
 * Schema Complex Types and Top-Level Elements                                *
 *   http://req.sp.ismp.chinatelecom.com                                      *
 *                                                                            *
\******************************************************************************/


/// "http://req.sp.ismp.chinatelecom.com":OrderRelationUpdateNotifyReq is a complexType.
struct ns2__OrderRelationUpdateNotifyReq
{
/// Element OPType of type xs:int.
    int                                  OPType                         1;	///< Required element.
/// Element packageID of type xs:string.
    char*                                packageID                      0;	///< Nillable pointer.
/// Element oldPackageID of type xs:string.
    char*                                oldPackageID                   0;	///< Nillable pointer.
/// Element productID of type xs:string.
    char*                                productID                      0;	///< Nillable pointer.
/// Element oldProductID of type xs:string.
    char*                                oldProductID                   0;	///< Nillable pointer.
/// Element streamingNo of type xs:string.
    char*                                streamingNo                   ;	///< Nillable pointer.
/// Element userID of type xs:string.
    char*                                userID                        ;	///< Nillable pointer.
/// Element userIDType of type xs:int.
    int                                  userIDType                     1;	///< Required element.
/// Size of array of char** is 0..unbounded
   $int                                  __sizeVerUserID                0;
/// Array char** of length 0..unbounded
    char**                               VerUserID                      0;	///< Nillable pointer.
};

/// "http://req.sp.ismp.chinatelecom.com":SPWithdrawSubscriptionReq is a complexType.
struct ns2__SPWithdrawSubscriptionReq
{
/// Element userIDType of type xs:int.
    int                                  userIDType                     1;	///< Required element.
/// Element userID of type xs:string.
    char*                                userID                        ;	///< Nillable pointer.
/// Element IDType of type xs:int.
    int                                  IDType                         1;	///< Required element.
/// Element ID of type xs:string.
    char*                                ID                            ;	///< Nillable pointer.
/// Element streamingNo of type xs:string.
    char*                                streamingNo                   ;	///< Nillable pointer.
/// Element SPID of type xs:string.
    char*                                SPID                          ;	///< Nillable pointer.
/// Element SPAdmin of type xs:string.
    char*                                SPAdmin                       ;	///< Nillable pointer.
/// Element SPAdminPwd of type xs:string.
    char*                                SPAdminPwd                    ;	///< Nillable pointer.
};

/// "http://req.sp.ismp.chinatelecom.com":ServiceConsumeNotifyReq is a complexType.
struct ns2__ServiceConsumeNotifyReq
{
/// Element featureStr of type xs:string.
    char*                                featureStr                    ;	///< Nillable pointer.
/// Element linkID of type xs:string.
    char*                                linkID                        ;	///< Nillable pointer.
/// Element productID of type xs:string.
    char*                                productID                     ;	///< Nillable pointer.
/// Element streamingNo of type xs:string.
    char*                                streamingNo                   ;	///< Nillable pointer.
/// Element userID of type xs:string.
    char*                                userID                        ;	///< Nillable pointer.
/// Element userIDType of type xs:int.
    int                                  userIDType                     1;	///< Required element.
};

/// "http://req.sp.ismp.chinatelecom.com":NotifyManagementInfoReq is a complexType.
struct ns2__NotifyManagementInfoReq
{
/// Element ID of type xs:string.
    char*                                ID                            ;	///< Nillable pointer.
/// Element IDType of type xs:int.
    int                                  IDType                         1;	///< Required element.
/// Element status of type xs:int.
    int                                  status                         1;	///< Required element.
/// Element streamingNo of type xs:string.
    char*                                streamingNo                   ;	///< Nillable pointer.
};

/******************************************************************************\
 *                                                                            *
 * Schema Complex Types and Top-Level Elements                                *
 *   http://sp.ismp.chinatelecom.com                                          *
 *                                                                            *
\******************************************************************************/


/******************************************************************************\
 *                                                                            *
 * Schema Complex Types and Top-Level Elements                                *
 *   http://rsp.sp.ismp.chinatelecom.com                                      *
 *                                                                            *
\******************************************************************************/


/// "http://rsp.sp.ismp.chinatelecom.com":Response is a complexType.
struct ns3__Response
{
/// Element resultCode of type xs:int.
    int                                  resultCode                     1;	///< Required element.
/// Element streamingNo of type xs:string.
    char*                                streamingNo                   ;	///< Nillable pointer.
};

/// "http://rsp.sp.ismp.chinatelecom.com":NotifyManagementInfoRsp is a complexType.
struct ns3__NotifyManagementInfoRsp
{
/// Element resultCode of type xs:int.
    int                                  resultCode                     1;	///< Required element.
/// Element streamingNo of type xs:string.
    char*                                streamingNo                   ;	///< Nillable pointer.
};

/******************************************************************************\
 *                                                                            *
 * Additional Top-Level Elements                                              *
 *   http://req.sp.ismp.chinatelecom.com                                      *
 *                                                                            *
\******************************************************************************/


/******************************************************************************\
 *                                                                            *
 * Additional Top-Level Attributes                                            *
 *   http://req.sp.ismp.chinatelecom.com                                      *
 *                                                                            *
\******************************************************************************/


/******************************************************************************\
 *                                                                            *
 * Additional Top-Level Elements                                              *
 *   http://sp.ismp.chinatelecom.com                                          *
 *                                                                            *
\******************************************************************************/


/// Top-level root element "http://sp.ismp.chinatelecom.com":orderRelationUpdateNotifyReq of type "http://req.sp.ismp.chinatelecom.com":OrderRelationUpdateNotifyReq.
/// Note: use wsdl2h option -g to auto-generate a top-level root element declaration and processing code.

/// Top-level root element "http://sp.ismp.chinatelecom.com":orderRelationUpdateNotifyReturn of type "http://rsp.sp.ismp.chinatelecom.com":Response.
/// Note: use wsdl2h option -g to auto-generate a top-level root element declaration and processing code.

/// Top-level root element "http://sp.ismp.chinatelecom.com":spWithdrawSubscriptionReqPara of type "http://req.sp.ismp.chinatelecom.com":SPWithdrawSubscriptionReq.
/// Note: use wsdl2h option -g to auto-generate a top-level root element declaration and processing code.

/// Top-level root element "http://sp.ismp.chinatelecom.com":spWithdrawSubscriptionReturn of type "http://rsp.sp.ismp.chinatelecom.com":Response.
/// Note: use wsdl2h option -g to auto-generate a top-level root element declaration and processing code.

/// Top-level root element "http://sp.ismp.chinatelecom.com":serviceConsumeNotifyReqPara of type "http://req.sp.ismp.chinatelecom.com":ServiceConsumeNotifyReq.
/// Note: use wsdl2h option -g to auto-generate a top-level root element declaration and processing code.

/// Top-level root element "http://sp.ismp.chinatelecom.com":serviceConsumeNotifyReturn of type "http://rsp.sp.ismp.chinatelecom.com":Response.
/// Note: use wsdl2h option -g to auto-generate a top-level root element declaration and processing code.

/// Top-level root element "http://sp.ismp.chinatelecom.com":notifyManagementInfoReq of type "http://req.sp.ismp.chinatelecom.com":NotifyManagementInfoReq.
/// Note: use wsdl2h option -g to auto-generate a top-level root element declaration and processing code.

/// Top-level root element "http://sp.ismp.chinatelecom.com":notifyManagementInfoReturn of type "http://rsp.sp.ismp.chinatelecom.com":NotifyManagementInfoRsp.
/// Note: use wsdl2h option -g to auto-generate a top-level root element declaration and processing code.

/******************************************************************************\
 *                                                                            *
 * Additional Top-Level Attributes                                            *
 *   http://sp.ismp.chinatelecom.com                                          *
 *                                                                            *
\******************************************************************************/


/******************************************************************************\
 *                                                                            *
 * Additional Top-Level Elements                                              *
 *   http://rsp.sp.ismp.chinatelecom.com                                      *
 *                                                                            *
\******************************************************************************/


/******************************************************************************\
 *                                                                            *
 * Additional Top-Level Attributes                                            *
 *   http://rsp.sp.ismp.chinatelecom.com                                      *
 *                                                                            *
\******************************************************************************/


/******************************************************************************\
 *                                                                            *
 * Services                                                                   *
 *                                                                            *
\******************************************************************************/


//gsoap ns1  service name:	IsmpSpEngineSoapBinding 
//gsoap ns1  service type:	IsmpSpEngine 
//gsoap ns1  service port:	http://localhost:8383/WsdlProject/services/IsmpSpEngine 
//gsoap ns1  service namespace:	http://sp.ismp.chinatelecom.com 
//gsoap ns1  service transport:	http://schemas.xmlsoap.org/soap/http 

/** @mainpage Service Definitions

@section Service_bindings Service Bindings

  - @ref IsmpSpEngineSoapBinding

@section Service_more More Information

  - @ref page_notes "Usage Notes"

  - @ref page_XMLDataBinding "XML Data Binding"

  - @ref SOAP_ENV__Header "SOAP Header Content" (when applicable)

  - @ref SOAP_ENV__Detail "SOAP Fault Detail Content" (when applicable)


*/

/**

@page IsmpSpEngineSoapBinding Binding "IsmpSpEngineSoapBinding"

@section IsmpSpEngineSoapBinding_operations Operations of Binding  "IsmpSpEngineSoapBinding"

  - @ref __ns1__orderRelationUpdateNotify

  - @ref __ns1__spWithdrawSubscription

  - @ref __ns1__serviceConsumeNotify

  - @ref __ns1__notifyManagementInfo

@section IsmpSpEngineSoapBinding_ports Endpoints of Binding  "IsmpSpEngineSoapBinding"

  - http://localhost:8383/WsdlProject/services/IsmpSpEngine

Note: use wsdl2h option -Nname to change the service binding prefix name


*/

/******************************************************************************\
 *                                                                            *
 * Service Binding                                                            *
 *   IsmpSpEngineSoapBinding                                                  *
 *                                                                            *
\******************************************************************************/


/******************************************************************************\
 *                                                                            *
 * Service Operation                                                          *
 *   __ns1__orderRelationUpdateNotify                                         *
 *                                                                            *
\******************************************************************************/


/// Operation "__ns1__orderRelationUpdateNotify" of service binding "IsmpSpEngineSoapBinding"

/**

Operation details:

  - SOAP document/literal style messaging

  - Addressing input action: "http://sp.ismp.chinatelecom.com/IsmpSpEngine/orderRelationUpdateNotifyRequest"

  - Addressing output action: "http://sp.ismp.chinatelecom.com/IsmpSpEngine/orderRelationUpdateNotifyResponse"

C stub function (defined in soapClient.c[pp] generated by soapcpp2):
@code
  int soap_call___ns1__orderRelationUpdateNotify(
    struct soap *soap,
    NULL, // char *endpoint = NULL selects default endpoint for this operation
    NULL, // char *action = NULL selects default action for this operation
    // input parameters:
    struct ns2__OrderRelationUpdateNotifyReq* ns1__orderRelationUpdateNotifyReq,
    // output parameters:
    struct ns3__Response*               ns1__orderRelationUpdateNotifyReturn
  );
@endcode

C server function (called from the service dispatcher defined in soapServer.c[pp]):
@code
  int __ns1__orderRelationUpdateNotify(
    struct soap *soap,
    // input parameters:
    struct ns2__OrderRelationUpdateNotifyReq* ns1__orderRelationUpdateNotifyReq,
    // output parameters:
    struct ns3__Response*               ns1__orderRelationUpdateNotifyReturn
  );
@endcode

*/

//gsoap ns1  service method-protocol:	orderRelationUpdateNotify SOAP
//gsoap ns1  service method-style:	orderRelationUpdateNotify document
//gsoap ns1  service method-encoding:	orderRelationUpdateNotify literal
//gsoap ns1  service method-input-action:	orderRelationUpdateNotify http://sp.ismp.chinatelecom.com/IsmpSpEngine/orderRelationUpdateNotifyRequest
//gsoap ns1  service method-output-action:	orderRelationUpdateNotify http://sp.ismp.chinatelecom.com/IsmpSpEngine/orderRelationUpdateNotifyResponse
int __ns1__orderRelationUpdateNotify(
    struct ns2__OrderRelationUpdateNotifyReq* ns1__orderRelationUpdateNotifyReq,	///< Input parameter
    struct ns3__Response*               ns1__orderRelationUpdateNotifyReturn	///< Output parameter
);

/******************************************************************************\
 *                                                                            *
 * Service Operation                                                          *
 *   __ns1__spWithdrawSubscription                                            *
 *                                                                            *
\******************************************************************************/


/// Operation "__ns1__spWithdrawSubscription" of service binding "IsmpSpEngineSoapBinding"

/**

Operation details:

  - SOAP document/literal style messaging

  - Addressing input action: "http://sp.ismp.chinatelecom.com/IsmpSpEngine/spWithdrawSubscriptionRequest"

  - Addressing output action: "http://sp.ismp.chinatelecom.com/IsmpSpEngine/spWithdrawSubscriptionResponse"

C stub function (defined in soapClient.c[pp] generated by soapcpp2):
@code
  int soap_call___ns1__spWithdrawSubscription(
    struct soap *soap,
    NULL, // char *endpoint = NULL selects default endpoint for this operation
    NULL, // char *action = NULL selects default action for this operation
    // input parameters:
    struct ns2__SPWithdrawSubscriptionReq* ns1__spWithdrawSubscriptionReqPara,
    // output parameters:
    struct ns3__Response*               ns1__spWithdrawSubscriptionReturn
  );
@endcode

C server function (called from the service dispatcher defined in soapServer.c[pp]):
@code
  int __ns1__spWithdrawSubscription(
    struct soap *soap,
    // input parameters:
    struct ns2__SPWithdrawSubscriptionReq* ns1__spWithdrawSubscriptionReqPara,
    // output parameters:
    struct ns3__Response*               ns1__spWithdrawSubscriptionReturn
  );
@endcode

*/

//gsoap ns1  service method-protocol:	spWithdrawSubscription SOAP
//gsoap ns1  service method-style:	spWithdrawSubscription document
//gsoap ns1  service method-encoding:	spWithdrawSubscription literal
//gsoap ns1  service method-input-action:	spWithdrawSubscription http://sp.ismp.chinatelecom.com/IsmpSpEngine/spWithdrawSubscriptionRequest
//gsoap ns1  service method-output-action:	spWithdrawSubscription http://sp.ismp.chinatelecom.com/IsmpSpEngine/spWithdrawSubscriptionResponse
int __ns1__spWithdrawSubscription(
    struct ns2__SPWithdrawSubscriptionReq* ns1__spWithdrawSubscriptionReqPara,	///< Input parameter
    struct ns3__Response*               ns1__spWithdrawSubscriptionReturn	///< Output parameter
);

/******************************************************************************\
 *                                                                            *
 * Service Operation                                                          *
 *   __ns1__serviceConsumeNotify                                              *
 *                                                                            *
\******************************************************************************/


/// Operation "__ns1__serviceConsumeNotify" of service binding "IsmpSpEngineSoapBinding"

/**

Operation details:

  - SOAP document/literal style messaging

  - Addressing input action: "http://sp.ismp.chinatelecom.com/IsmpSpEngine/serviceConsumeNotifyRequest"

  - Addressing output action: "http://sp.ismp.chinatelecom.com/IsmpSpEngine/serviceConsumeNotifyResponse"

C stub function (defined in soapClient.c[pp] generated by soapcpp2):
@code
  int soap_call___ns1__serviceConsumeNotify(
    struct soap *soap,
    NULL, // char *endpoint = NULL selects default endpoint for this operation
    NULL, // char *action = NULL selects default action for this operation
    // input parameters:
    struct ns2__ServiceConsumeNotifyReq* ns1__serviceConsumeNotifyReqPara,
    // output parameters:
    struct ns3__Response*               ns1__serviceConsumeNotifyReturn
  );
@endcode

C server function (called from the service dispatcher defined in soapServer.c[pp]):
@code
  int __ns1__serviceConsumeNotify(
    struct soap *soap,
    // input parameters:
    struct ns2__ServiceConsumeNotifyReq* ns1__serviceConsumeNotifyReqPara,
    // output parameters:
    struct ns3__Response*               ns1__serviceConsumeNotifyReturn
  );
@endcode

*/

//gsoap ns1  service method-protocol:	serviceConsumeNotify SOAP
//gsoap ns1  service method-style:	serviceConsumeNotify document
//gsoap ns1  service method-encoding:	serviceConsumeNotify literal
//gsoap ns1  service method-input-action:	serviceConsumeNotify http://sp.ismp.chinatelecom.com/IsmpSpEngine/serviceConsumeNotifyRequest
//gsoap ns1  service method-output-action:	serviceConsumeNotify http://sp.ismp.chinatelecom.com/IsmpSpEngine/serviceConsumeNotifyResponse
int __ns1__serviceConsumeNotify(
    struct ns2__ServiceConsumeNotifyReq* ns1__serviceConsumeNotifyReqPara,	///< Input parameter
    struct ns3__Response*               ns1__serviceConsumeNotifyReturn	///< Output parameter
);

/******************************************************************************\
 *                                                                            *
 * Service Operation                                                          *
 *   __ns1__notifyManagementInfo                                              *
 *                                                                            *
\******************************************************************************/


/// Operation "__ns1__notifyManagementInfo" of service binding "IsmpSpEngineSoapBinding"

/**

Operation details:

  - SOAP document/literal style messaging

  - Addressing input action: "http://sp.ismp.chinatelecom.com/IsmpSpEngine/notifyManagementInfoRequest"

  - Addressing output action: "http://sp.ismp.chinatelecom.com/IsmpSpEngine/notifyManagementInfoResponse"

C stub function (defined in soapClient.c[pp] generated by soapcpp2):
@code
  int soap_call___ns1__notifyManagementInfo(
    struct soap *soap,
    NULL, // char *endpoint = NULL selects default endpoint for this operation
    NULL, // char *action = NULL selects default action for this operation
    // input parameters:
    struct ns2__NotifyManagementInfoReq* ns1__notifyManagementInfoReq,
    // output parameters:
    struct ns3__NotifyManagementInfoRsp* ns1__notifyManagementInfoReturn
  );
@endcode

C server function (called from the service dispatcher defined in soapServer.c[pp]):
@code
  int __ns1__notifyManagementInfo(
    struct soap *soap,
    // input parameters:
    struct ns2__NotifyManagementInfoReq* ns1__notifyManagementInfoReq,
    // output parameters:
    struct ns3__NotifyManagementInfoRsp* ns1__notifyManagementInfoReturn
  );
@endcode

*/

//gsoap ns1  service method-protocol:	notifyManagementInfo SOAP
//gsoap ns1  service method-style:	notifyManagementInfo document
//gsoap ns1  service method-encoding:	notifyManagementInfo literal
//gsoap ns1  service method-input-action:	notifyManagementInfo http://sp.ismp.chinatelecom.com/IsmpSpEngine/notifyManagementInfoRequest
//gsoap ns1  service method-output-action:	notifyManagementInfo http://sp.ismp.chinatelecom.com/IsmpSpEngine/notifyManagementInfoResponse
int __ns1__notifyManagementInfo(
    struct ns2__NotifyManagementInfoReq* ns1__notifyManagementInfoReq,	///< Input parameter
    struct ns3__NotifyManagementInfoRsp* ns1__notifyManagementInfoReturn	///< Output parameter
);

/**

@page IsmpSpEngineSoapBinding Binding "IsmpSpEngineSoapBinding"

@section IsmpSpEngineSoapBinding_policy_enablers Policy Enablers of Binding  "IsmpSpEngineSoapBinding"

Based on policies, this service imports

  - WS-Policy reminders and enablers:
    - WS-Addressing 1.0 (2005/08, accepts 2004/08):
	@code
	#import "wsa5.h" // to be added to this header file for the soapcpp2 build step
	@endcode
	@code
	#include "plugin/wsaapi.h"
	soap_register_plugin(soap, soap_wsa); // register the wsa plugin in your code
	// See the user guide gsoap/doc/wsa/html/index.html
	@endcode
    - WS-Addressing (2004/08):
	@code
	#import "wsa.h" // to be added to this header file for the soapcpp2 build step
	@endcode
	@code
	#include "plugin/wsaapi.h"
	soap_register_plugin(soap, soap_wsa); // register the wsa plugin in your code
	// See the user guide gsoap/doc/wsa/html/index.html
	@endcode
    - WS-ReliableMessaging 1.0:
	@code
	#import "wsrm5.h" // to be added to this header file for the soapcpp2 build step
	@endcode
	@code
	#include "plugin/wsrmapi.h"
	soap_register_plugin(soap, soap_wsa); // register the wsa plugin in your code
	soap_register_plugin(soap, soap_wsrm); // register the wsrm plugin in your code
	// See the user guide gsoap/doc/wsrm/html/index.html
	@endcode
    - WS-ReliableMessaging 1.1:
	@code
	#import "wsrm.h" // to be added to this header file for the soapcpp2 build step
	@endcode
	@code
	#include "plugin/wsrmapi.h"
	soap_register_plugin(soap, soap_wsa); // register the wsa plugin in your code
	soap_register_plugin(soap, soap_wsrm); // register the wsrm plugin in your code
	// See the user guide gsoap/doc/wsrm/html/index.html
	@endcode
    - WS-Security (SOAP Message Security) 1.0 (accepts 1.1):
	@code
	#import "wsse.h" // to be added to this header file for the soapcpp2 build step
	@endcode
	@code
	#include "plugin/wsseapi.h"
	soap_register_plugin(soap, soap_wsse); // register the wsse plugin in your code
	// See the user guide gsoap/doc/wsse/html/index.html
	@endcode
    - WS-Security (SOAP Message Security) 1.1 (accepts 1.0):
	@code
	#import "wsse11.h" // to be added to this header file for the soapcpp2 build step
	@endcode
	@code
	#include "plugin/wsseapi.h"
	soap_register_plugin(soap, soap_wsse); // register the wsse plugin in your code
	// See the user guide gsoap/doc/wsse/html/index.html
	@endcode
    - HTTP Digest Authentication:
	@code
	#include "plugin/httpda.h"
	soap_register_plugin(soap, soap_http_da); // register the HTTP DA plugin in your code
	// See the user guide gsoap/doc/httpda/html/index.html
	@endcode
*/


/******************************************************************************\
 *                                                                            *
 * XML Data Binding                                                           *
 *                                                                            *
\******************************************************************************/


/**

@page page_XMLDataBinding XML Data Binding

SOAP/XML services use data bindings contractually bound by WSDL and auto-
generated by wsdl2h and soapcpp2 (see Service Bindings). Plain data bindings
are adopted from XML schemas as part of the WSDL types section or when running
wsdl2h on a set of schemas to produce non-SOAP-based XML data bindings.

The following readers and writers are C/C++ data type (de)serializers auto-
generated by wsdl2h and soapcpp2. Run soapcpp2 on this file to generate the
(de)serialization code, which is stored in soapC.c[pp]. Include "soapH.h" in
your code to import these data type and function declarations. Only use the
soapcpp2-generated files in your project build. Do not include the wsdl2h-
generated .h file in your code.

Data can be read in XML and deserialized from:
  - a file descriptor, using soap->recvfd = fd
  - a socket, using soap->socket = ...
  - a C++ stream, using soap->is = ...
  - a buffer, using the soap->frecv() callback

Data can be serialized in XML and written to:
  - a file descriptor, using soap->sendfd = fd
  - a socket, using soap->socket = ...
  - a C++ stream, using soap->os = ...
  - a buffer, using the soap->fsend() callback

The following options are available for (de)serialization control:
  - soap->encodingStyle = NULL; to remove SOAP 1.1/1.2 encodingStyle
  - soap_mode(soap, SOAP_XML_TREE); XML without id-ref (no cycles!)
  - soap_mode(soap, SOAP_XML_GRAPH); XML with id-ref (including cycles)
  - soap_set_namespaces(soap, struct Namespace *nsmap); to set xmlns bindings


@section ns2 Top-level root elements of schema "http://req.sp.ismp.chinatelecom.com"

@section ns1 Top-level root elements of schema "http://sp.ismp.chinatelecom.com"

  - <ns1:orderRelationUpdateNotifyReq> (use wsdl2h option -g to auto-generate)

  - <ns1:orderRelationUpdateNotifyReturn> (use wsdl2h option -g to auto-generate)

  - <ns1:spWithdrawSubscriptionReqPara> (use wsdl2h option -g to auto-generate)

  - <ns1:spWithdrawSubscriptionReturn> (use wsdl2h option -g to auto-generate)

  - <ns1:serviceConsumeNotifyReqPara> (use wsdl2h option -g to auto-generate)

  - <ns1:serviceConsumeNotifyReturn> (use wsdl2h option -g to auto-generate)

  - <ns1:notifyManagementInfoReq> (use wsdl2h option -g to auto-generate)

  - <ns1:notifyManagementInfoReturn> (use wsdl2h option -g to auto-generate)

@section ns3 Top-level root elements of schema "http://rsp.sp.ismp.chinatelecom.com"

*/

/* End of IsmpSpEngine.h */
