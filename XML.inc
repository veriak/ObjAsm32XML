;----------------------------------------------------------------------------------------
; XML Masm32 Library
;
; Copyright 2007 Veria Kalantary
; veria.kalantary@gmail.com
; https://github.com/veriak
;
;----------------------------------------------------------------------------------------

include Com.inc

covar2method2Proto      typedef proto :DWORD, :VARIANT
covar2method2           typedef ptr covar2method2Proto
covar3method3Proto      typedef proto :DWORD, :DWORD, :VARIANT
covar3method3           typedef ptr covar3method3Proto
covar3method4Proto      typedef proto :DWORD, :DWORD, :VARIANT, :DWORD
covar3method4           typedef ptr covar3method4Proto
covarbool2method2Proto  typedef proto :DWORD, :VARIANT_BOOL
covarbool2method2       typedef ptr covarbool2method2Proto
covarbool2method3Proto  typedef proto :DWORD, :VARIANT_BOOL, :DWORD
covarbool2method3       typedef ptr covarbool2method3Proto

_vtIXMLDOMImplementation MACRO CastName:REQ
	_vtIDispatch CastName
	&CastName&_hasFeature				comethod4       ? 
ENDM

IXMLDOMImplementation struct
	_vtIXMLDOMImplementation IXMLDOMImplementation	
IXMLDOMImplementation ends

_vtIXMLDOMNode MACRO CastName:REQ
	_vtIDispatch CastName
	&CastName&_get_nodeName				comethod2       ?        
    &CastName&_get_nodeValue			comethod2       ?        
    &CastName&_put_nodeValue			covar2method2   ?
    &CastName&_get_nodeType				comethod2       ?
    &CastName&_get_parentNode			comethod2       ?
    &CastName&_get_childNodes			comethod2       ?
    &CastName&_get_firstChild			comethod2       ?
    &CastName&_get_lastChild			comethod2       ?
    &CastName&_get_previousSibling		comethod2       ?
    &CastName&_get_nextSibling			comethod2       ?
    &CastName&_get_attributes			comethod2       ?
    &CastName&_insertBefore				covar3method4   ?
    &CastName&_replaceChild				comethod4       ?
    &CastName&_removeChild				comethod3       ?
    &CastName&_appendChild				comethod3       ?
    &CastName&_hasChildNodes			comethod2       ?
    &CastName&_get_ownerDocument		comethod2       ?
    &CastName&_cloneNode				covarbool2method3	?
    &CastName&_get_nodeTypeString		comethod2       ?
    &CastName&_get_text					comethod2       ?
    &CastName&_put_text					comethod2       ?
    &CastName&_get_specified			comethod2       ?
    &CastName&_get_definition			comethod2       ?
    &CastName&_get_nodeTypedValue		comethod2       ?
    &CastName&_put_nodeTypedValue		comethod2       ?
    &CastName&_get_dataType				comethod2       ?
    &CastName&_put_dataType				comethod2       ?
    &CastName&_get_xml					comethod2       ?
    &CastName&_transformNode			comethod3       ?
   	&CastName&_selectNodes				comethod3       ?
   	&CastName&_selectSingleNode			comethod3       ?
   	&CastName&_get_parsed				comethod2       ?
   	&CastName&_get_namespaceURI			comethod2       ?
   	&CastName&_get_prefix				comethod2       ?
   	&CastName&_get_baseName				comethod2       ?
   	&CastName&_transformNodeToObject	covar3method3   ? 
ENDM

IXMLDOMNode struct
	_vtIXMLDOMNode IXMLDOMNode	
IXMLDOMNode ends

_vtIXMLDOMDocumentFragment MACRO CastName:REQ
	_vtIXMLDOMNode CastName	 
ENDM

IXMLDOMDocumentFragment struct
	_vtIXMLDOMDocumentFragment IXMLDOMDocumentFragment	
IXMLDOMDocumentFragment ends

_vtIXMLDOMDocument MACRO CastName:REQ
	_vtIXMLDOMNode CastName	 
	&CastName&_get_doctype				comethod2       ?
    &CastName&_get_implementation		comethod2       ?
    &CastName&_get_documentElement		comethod2       ?
    &CastName&_putref_documentElement	comethod2       ?
    &CastName&_createElement			comethod3       ?
    &CastName&_createDocumentFragment	comethod2       ?
    &CastName&_createTextNode			comethod3       ?
    &CastName&_createComment			comethod3       ?
    &CastName&_createCDATASection		comethod3       ?
    &CastName&_createProcessingInstruction	comethod4       ?
    &CastName&_createAttribute			comethod3       ?
    &CastName&_createEntityReference	comethod3       ?
    &CastName&_getElementsByTagName		comethod3       ?
    &CastName&_createNode				comethod5       ?
    &CastName&_nodeFromID				comethod3       ?
    &CastName&_load						comethod3       ?
    &CastName&_get_readyState			comethod2       ?
    &CastName&_get_parseError			comethod2       ?
    &CastName&_get_url					comethod2       ?
    &CastName&_get_async				comethod2       ?
    &CastName&_put_async				covarbool2method2	?
    &CastName&_abort					comethod1       ?
    &CastName&_loadXML					comethod3       ?
    &CastName&_save						covar2method2   ?
    &CastName&_get_validateOnParse		comethod2       ?
    &CastName&_put_validateOnParse		covarbool2method2   ?
    &CastName&_get_resolveExternals		comethod2       ?
    &CastName&_put_resolveExternals		covarbool2method2   ?
    &CastName&_get_preserveWhiteSpace	comethod2       ?
    &CastName&_put_preserveWhiteSpace	covarbool2method2   ?
    &CastName&_put_onreadystatechange	comethod2       ?
    &CastName&_put_ondataavailable		comethod2       ?
    &CastName&_put_ontransformnode		comethod2       ?
ENDM

IXMLDOMDocument struct
	_vtIXMLDOMDocument IXMLDOMDocument	
IXMLDOMDocument ends

_vtIXMLDOMNodeList MACRO CastName:REQ
	_vtIDispatch CastName
	&CastName&_get_item					comethod3       ?
    &CastName&_get_length				comethod2       ?
    &CastName&_nextNode					comethod2       ?
    &CastName&_reset					comethod1       ?
    &CastName&_get__newEnum				comethod2       ?
ENDM

IXMLDOMNodeList struct
	_vtIXMLDOMNodeList IXMLDOMNodeList	
IXMLDOMNodeList ends

_vtIXMLDOMNamedNodeMap MACRO CastName:REQ
	_vtIDispatch CastName
	&CastName&_getNamedItem				comethod3       ?
    &CastName&_setNamedItem				comethod3       ?
    &CastName&_removeNamedItem			comethod3       ?
    &CastName&_get_item					comethod3       ?
    &CastName&_get_length				comethod2       ?
    &CastName&_getQualifiedItem			comethod4       ?
    &CastName&_removeQualifiedItem		comethod4       ?
    &CastName&_nextNode					comethod2       ?
    &CastName&_reset					comethod1       ?
    &CastName&_get__newEnum				comethod2       ?
ENDM

IXMLDOMNamedNodeMap struct
	_vtIXMLDOMNamedNodeMap IXMLDOMNamedNodeMap	
IXMLDOMNamedNodeMap ends

_vtIXMLDOMCharacterData MACRO CastName:REQ
	_vtIXMLDOMNode CastName
	&CastName&_get_data					comethod2       ?
    &CastName&_put_data					comethod2       ?
    &CastName&_get_length				comethod2       ?
    &CastName&_substringData			comethod4       ?
    &CastName&_appendData				comethod2       ?
    &CastName&_insertData				comethod3       ?
    &CastName&_deleteData				comethod3       ?
   	&CastName&_replaceData				comethod4       ?
ENDM

IXMLDOMCharacterData struct
	_vtIXMLDOMCharacterData IXMLDOMCharacterData	
IXMLDOMCharacterData ends

_vtIXMLDOMAttribute MACRO CastName:REQ
	_vtIXMLDOMNode CastName
	&CastName&_get_name					comethod2       ?        
    &CastName&_get_value				comethod2       ?
    &CastName&_put_value				covar2method2   ?
ENDM

IXMLDOMAttribute struct
	_vtIXMLDOMAttribute IXMLDOMAttribute	
IXMLDOMAttribute ends

_vtIXMLDOMElement MACRO CastName:REQ
	_vtIXMLDOMNode CastName
	&CastName&_get_tagName				comethod2       ?
    &CastName&_getAttribute				comethod3       ?
    &CastName&_setAttribute				comethod3       ?
    &CastName&_removeAttribute			comethod2       ?
    &CastName&_getAttributeNode			comethod3       ?
    &CastName&_setAttributeNode			comethod3       ?
    &CastName&_removeAttributeNode		comethod3       ?
    &CastName&_getElementsByTagName		comethod3       ?
    &CastName&_normalize				comethod1       ?        
ENDM

IXMLDOMElement struct
	_vtIXMLDOMElement IXMLDOMElement	
IXMLDOMElement ends

_vtIXMLDOMText MACRO CastName:REQ
	_vtIXMLDOMCharacterData CastName
	&CastName&_splitText				comethod3       ? 
ENDM

IXMLDOMText struct
	_vtIXMLDOMText IXMLDOMText	
IXMLDOMText ends

_vtIXMLDOMComment MACRO CastName:REQ
	_vtIXMLDOMCharacterData CastName	 
ENDM

IXMLDOMComment struct
	_vtIXMLDOMComment IXMLDOMComment	
IXMLDOMComment ends

_vtIXMLDOMProcessingInstruction MACRO CastName:REQ
	_vtIXMLDOMNode CastName
	&CastName&_get_target				comethod2       ?   
    &CastName&_get_data					comethod2       ?
    &CastName&_put_data					comethod2       ? 
ENDM

IXMLDOMProcessingInstruction struct
	_vtIXMLDOMProcessingInstruction IXMLDOMProcessingInstruction	
IXMLDOMProcessingInstruction ends

_vtIXMLDOMCDATASection MACRO CastName:REQ
	_vtIXMLDOMText CastName	   
ENDM

IXMLDOMCDATASection struct
	_vtIXMLDOMCDATASection IXMLDOMCDATASection	
IXMLDOMCDATASection ends

_vtIXMLDOMDocumentType MACRO CastName:REQ
	_vtIXMLDOMNode CastName	 
	&CastName&_get_name					comethod2       ?
    &CastName&_get_entities				comethod2       ?
    &CastName&_get_notations			comethod2       ?
ENDM

IXMLDOMDocumentType struct
	_vtIXMLDOMDocumentType IXMLDOMDocumentType	
IXMLDOMDocumentType ends

_vtIXMLDOMNotation MACRO CastName:REQ
	_vtIXMLDOMNode CastName	 
	&CastName&_get_publicId				comethod2       ?
    &CastName&_get_systemId				comethod2       ?
ENDM

IXMLDOMNotation struct
	_vtIXMLDOMNotation IXMLDOMNotation	
IXMLDOMNotation ends

_vtIXMLDOMEntity MACRO CastName:REQ
	_vtIXMLDOMNode CastName	 
	&CastName&_get_publicId				comethod2       ?
    &CastName&_get_systemId				comethod2       ?
    &CastName&_get_notationName			comethod2       ?
ENDM

IXMLDOMEntity struct
	_vtIXMLDOMEntity IXMLDOMEntity	
IXMLDOMEntity ends

_vtIXMLDOMEntityReference MACRO CastName:REQ
	_vtIXMLDOMNode CastName	 
ENDM

IXMLDOMEntityReference struct
	_vtIXMLDOMEntityReference IXMLDOMEntityReference	
IXMLDOMEntityReference ends

_vtIXMLDOMParseError MACRO CastName:REQ
	_vtIDispatch CastName	
	&CastName&_get_errorCode			comethod2       ?        
    &CastName&_get_url					comethod2       ?
    &CastName&_get_reason				comethod2       ?
    &CastName&_get_srcText				comethod2       ?
    &CastName&_get_line					comethod2       ?
    &CastName&_get_linepos				comethod2       ?
    &CastName&_get_filepos				comethod2       ?
ENDM

IXMLDOMParseError struct
	_vtIXMLDOMParseError IXMLDOMParseError	
IXMLDOMParseError ends

_vtIXMLHttpRequest MACRO CastName:REQ
	_vtIDispatch CastName	 
	&CastName&_open						comethod6       ?        
    &CastName&_setRequestHeader			comethod3       ?        
    &CastName&_getResponseHeader		comethod3       ?
    &CastName&_getAllResponseHeaders	comethod2       ?        
    &CastName&_send						comethod2       ?        
    &CastName&_abort					comethod1       ?
    &CastName&_get_status				comethod2       ?
    &CastName&_get_statusText			comethod2       ?
    &CastName&_get_responseXML			comethod2       ?
    &CastName&_get_responseText			comethod2       ?
    &CastName&_get_responseBody			comethod2       ?
    &CastName&_get_responseStream		comethod2       ?
    &CastName&_get_readyState			comethod2       ?
    &CastName&_put_onreadystatechange	comethod2       ?
ENDM

IXMLHttpRequest struct
	_vtIXMLHttpRequest IXMLHttpRequest	
IXMLHttpRequest ends

_vtIXMLDSOControl MACRO CastName:REQ
	_vtIDispatch CastName
	&CastName&_get_XMLDocument			comethod2       ?
    &CastName&_put_XMLDocument			comethod2       ?
    &CastName&_get_JavaDSOCompatible	comethod2       ?
    &CastName&_put_JavaDSOCompatible	comethod2       ?
    &CastName&_get_readyState			comethod2       ?
ENDM

IXMLDSOControl struct
	_vtIXMLDSOControl IXMLDSOControl	
IXMLDSOControl ends

_vtIXMLElementCollection MACRO CastName:REQ
	_vtIDispatch CastName
	&CastName&_put_length				comethod2       ?
    &CastName&_get_length				comethod2       ?
    &CastName&_get__newEnum				comethod2       ?
    &CastName&_item						comethod4       ?
ENDM

IXMLElementCollection struct
	_vtIXMLElementCollection IXMLElementCollection	
IXMLElementCollection ends

_vtIXMLDocument MACRO CastName:REQ
	_vtIDispatch CastName
	&CastName&_get_root					comethod2       ?
    &CastName&_get_fileSize				comethod2       ?
    &CastName&_get_fileModifiedDate		comethod2       ?
    &CastName&_get_fileUpdatedDate		comethod2       ?
    &CastName&_get_URL					comethod2       ?
    &CastName&_put_URL					comethod2       ?
    &CastName&_get_mimeType				comethod2       ?
    &CastName&_get_readyState			comethod2       ?
    &CastName&_get_charset				comethod2       ?
    &CastName&_put_charset				comethod2       ?
    &CastName&_get_version				comethod2       ?
    &CastName&_get_doctype				comethod2       ?
    &CastName&_get_dtdURL				comethod2       ?
    &CastName&_createElement			comethod4       ?
ENDM

IXMLDocument struct
	_vtIXMLDocument IXMLDocument	
IXMLDocument ends

_vtIXMLDocument2 MACRO CastName:REQ
	_vtIDispatch CastName
	&CastName&_get_root					comethod2       ?
    &CastName&_get_fileSize				comethod2       ?
    &CastName&_get_fileModifiedDate		comethod2       ?
    &CastName&_get_fileUpdatedDate		comethod2       ?
    &CastName&_get_URL					comethod2       ?
    &CastName&_put_URL					comethod2       ?
    &CastName&_get_mimeType				comethod2       ?
    &CastName&_get_readyState			comethod2       ?
    &CastName&_get_charset				comethod2       ?
    &CastName&_put_charset				comethod2       ?
    &CastName&_get_version				comethod2       ?
    &CastName&_get_doctype				comethod2       ?
    &CastName&_get_dtdURL				comethod2       ?
    &CastName&_createElement			comethod4       ?
    &CastName&_get_async				comethod2       ?
    &CastName&_put_async				covarbool2method2	?
ENDM

IXMLDocument2 struct
	_vtIXMLDocument2 IXMLDocument2	
IXMLDocument2 ends

_vtIXMLElement MACRO CastName:REQ
	_vtIDispatch CastName
	&CastName&_get_tagName				comethod2       ?
    &CastName&_put_tagName				comethod2       ?
    &CastName&_get_parent				comethod2       ?
    &CastName&_setAttribute				comethod3       ?
    &CastName&_getAttribute				comethod3       ?
    &CastName&_removeAttribute			comethod2       ?
    &CastName&_get_children				comethod2       ?
    &CastName&_get_type					comethod2       ?
    &CastName&_get_text					comethod2       ?
    &CastName&_put_text					comethod2       ?
    &CastName&_addChild					comethod4       ?
    &CastName&_removeChild				comethod2       ?
ENDM

IXMLElement struct
	_vtIXMLElement IXMLElement	
IXMLElement ends

_vtIXMLElement2 MACRO CastName:REQ
	_vtIDispatch CastName
	&CastName&_get_tagName				comethod2       ?
    &CastName&_put_tagName				comethod2       ?
    &CastName&_get_parent				comethod2       ?
    &CastName&_setAttribute				comethod3       ?
    &CastName&_getAttribute				comethod3       ?
    &CastName&_removeAttribute			comethod2       ?
    &CastName&_get_children				comethod2       ?
    &CastName&_get_type					comethod2       ?
    &CastName&_get_text					comethod2       ?
    &CastName&_put_text					comethod2       ?
    &CastName&_addChild					comethod4       ?
    &CastName&_removeChild				comethod2       ?
    &CastName&_get_attributes			comethod2       ?
ENDM

IXMLElement2 struct
	_vtIXMLElement2 IXMLElement2	
IXMLElement2 ends

_vtIXMLAttribute MACRO CastName:REQ
	_vtIDispatch CastName
	&CastName&_get_name					comethod2       ?
    &CastName&_get_value				comethod2       ?
ENDM

IXMLAttribute struct
	_vtIXMLAttribute IXMLAttribute	
IXMLAttribute ends

_vtIXMLError MACRO CastName:REQ
	_vtIUnknown CastName
	&CastName&_GetErrorInfo				comethod2       ?    
ENDM

IXMLError struct
	_vtIXMLError IXMLError	
IXMLError ends


	PIXMLDOMImplementation			typedef ptr	IXMLDOMImplementation 
	PIXMLDOMNode					typedef ptr IXMLDOMNode
	PIXMLDOMDocumentFragment		typedef ptr IXMLDOMDocumentFragment
	PIXMLDOMDocument				typedef ptr IXMLDOMDocument
	PIXMLDOMNodeList				typedef ptr	IXMLDOMNodeList	
	PIXMLDOMNamedNodeMap			typedef ptr	IXMLDOMNamedNodeMap
	PIXMLDOMCharacterData			typedef ptr	IXMLDOMCharacterData
	PIXMLDOMAttribute				typedef ptr	IXMLDOMAttribute
	PIXMLDOMElement					typedef ptr	IXMLDOMElement
	PIXMLDOMText					typedef ptr	IXMLDOMText
	PIXMLDOMComment					typedef ptr	IXMLDOMComment
	PIXMLDOMProcessingInstruction	typedef ptr	IXMLDOMProcessingInstruction
	PIXMLDOMCDATASection			typedef ptr	IXMLDOMCDATASection
	PIXMLDOMDocumentType			typedef ptr	IXMLDOMDocumentType
	PIXMLDOMNotation				typedef ptr	IXMLDOMNotation
	PIXMLDOMEntity					typedef ptr	IXMLDOMEntity
	PIXMLDOMEntityReference			typedef ptr	IXMLDOMEntityReference
	PIXMLDOMParseError				typedef ptr	IXMLDOMParseError
	PIXMLHttpRequest				typedef ptr	IXMLHttpRequest
	PIXMLDSOControl					typedef ptr	IXMLDSOControl
	PIXMLElementCollection			typedef ptr	IXMLElementCollection
	PIXMLDocument					typedef ptr	IXMLDocument
	PIXMLDocument2					typedef ptr	IXMLDocument2
	PIXMLElement					typedef ptr	IXMLElement
	PIXMLElement2					typedef ptr	IXMLElement2
	PIXMLAttribute					typedef ptr	IXMLAttribute
	PIXMLError						typedef ptr	IXMLError
	
	PPIXMLDOMElement				typedef ptr	PIXMLDOMElement
	PPIXMLDOMNode					typedef ptr PIXMLDOMNode
	
.const
	CLSID_DOMDocument 					GUID <2933bf90h, 7b36h, 11d2h, <0b2h, 0eh, 00h, 0c0h, 4fh, 98h, 3eh, 60h>>
    CLSID_DOMFreeThreadedDocument 		GUID <2933bf91h, 7b36h, 11d2h, <0b2h, 0eh, 00h, 0c0h, 4fh, 98h, 3eh, 60h>>
        
	IID_IXMLDOMImplementation			GUID <2933BF8Fh, 7B36h, 11d2h, <0B2h, 0Eh, 00h, 0C0h, 4Fh, 98h, 3Eh, 60h>>
	IID_IXMLDOMNode						GUID <2933BF80h, 7B36h, 11d2h, <0B2h, 0Eh, 00h, 0C0h, 4Fh, 98h, 3Eh, 60h>>
	IID_IXMLDOMDocumentFragment			GUID <3efaa413h, 272fh, 11d2h, <83h, 6fh, 00h, 00h, 0f8h, 7ah, 77h, 82h>>
	IID_IXMLDOMDocument					GUID <2933BF81h, 7B36h, 11d2h, <0B2h, 0Eh, 00h, 0C0h, 4Fh, 98h, 3Eh, 60h>>
	IID_IXMLDOMNodeList					GUID <2933BF82h, 7B36h, 11d2h, <0B2h, 0Eh, 00h, 0C0h, 4Fh, 98h, 3Eh, 60h>>
	IID_IXMLDOMNamedNodeMap				GUID <2933BF83h, 7B36h, 11d2h, <0B2h, 0Eh, 00h, 0C0h, 4Fh, 98h, 3Eh, 60h>>
	IID_IXMLDOMCharacterData			GUID <2933BF84h, 7B36h, 11d2h, <0B2h, 0Eh, 00h, 0C0h, 4Fh, 98h, 3Eh, 60h>>
	IID_IXMLDOMAttribute				GUID <2933BF85h, 7B36h, 11d2h, <0B2h, 0Eh, 00h, 0C0h, 4Fh, 98h, 3Eh, 60h>>
	IID_IXMLDOMElement					GUID <2933BF86h, 7B36h, 11d2h, <0B2h, 0Eh, 00h, 0C0h, 4Fh, 98h, 3Eh, 60h>>
	IID_IXMLDOMText						GUID <2933BF87h, 7B36h, 11d2h, <0B2h, 0Eh, 00h, 0C0h, 4Fh, 98h, 3Eh, 60h>>
	IID_IXMLDOMComment					GUID <2933BF88h, 7B36h, 11d2h, <0B2h, 0Eh, 00h, 0C0h, 4Fh, 98h, 3Eh, 60h>>
	IID_IXMLDOMProcessingInstruction	GUID <2933BF89h, 7B36h, 11d2h, <0B2h, 0Eh, 00h, 0C0h, 4Fh, 98h, 3Eh, 60h>>
	IID_IXMLDOMCDATASection				GUID <2933BF8Ah, 7B36h, 11d2h, <0B2h, 0Eh, 00h, 0C0h, 4Fh, 98h, 3Eh, 60h>>
	IID_IXMLDOMDocumentType				GUID <2933BF8Bh, 7B36h, 11d2h, <0B2h, 0Eh, 00h, 0C0h, 4Fh, 98h, 3Eh, 60h>>
	IID_IXMLDOMNotation					GUID <2933BF8Ch, 7B36h, 11d2h, <0B2h, 0Eh, 00h, 0C0h, 4Fh, 98h, 3Eh, 60h>>
	IID_IXMLDOMEntity					GUID <2933BF8Dh, 7B36h, 11d2h, <0B2h, 0Eh, 00h, 0C0h, 4Fh, 98h, 3Eh, 60h>>
	IID_IXMLDOMEntityReference			GUID <2933BF8Eh, 7B36h, 11d2h, <0B2h, 0Eh, 00h, 0C0h, 4Fh, 98h, 3Eh, 60h>>
	IID_IXMLDOMParseError				GUID <3efaa426h, 272fh, 11d2h, <83h, 6fh, 00h, 00h, 0f8h, 7ah, 77h, 82h>>
	IID_IXMLHttpRequest					GUID <0ED8C108Dh, 4349h, 11D2h, <91h, 0A4h, 00h, 0C0h, 4Fh, 79h, 69h, 0E8h>>
	IID_IXMLDSOControl					GUID <310afa62h, 0575h, 11d2h, <9ch, 0a9h, 00h, 60h, 0b0h, 0ech, 3dh, 39h>>
	IID_IXMLElementCollection			GUID <65725580h, 9B5Dh, 11d0h, <9Bh, 0FEh, 00h, 0C0h, 4Fh, 0C9h, 9Ch, 8Eh>>
	IID_IXMLDocument					GUID <0F52E2B61h, 18A1h, 11d1h, <0B1h, 05h, 00h, 80h, 5Fh, 49h, 91h, 6Bh>>
	IID_IXMLDocument2					GUID <2B8DE2FEh, 8D2Dh, 11d1h, <0B2h, 0FCh, 00h, 0C0h, 4Fh, 0D9h, 15h, 0A9h>>
	IID_IXMLElement						GUID <3F7F31ACh, 0E15Fh, 11d0h, <9Ch, 25h, 00h, 0C0h, 4Fh, 0C9h, 9Ch, 8Eh>>
	IID_IXMLElement2					GUID <2B8DE2FFh, 8D2Dh, 11d1h, <0B2h, 0FCh, 00h, 0C0h, 4Fh, 0D9h, 15h, 0A9h>>
	IID_IXMLAttribute					GUID <0D4D4A0FCh, 3B73h, 11d1h, <0B2h, 0B4h, 00h, 0C0h, 4Fh, 0B9h, 25h, 96h>>
	IID_IXMLError						GUID <948C5AD3h, 0C58Dh, 11d0h, <9Ch, 0Bh, 00h, 0C0h, 4Fh, 0C9h, 9Ch, 8Eh>>