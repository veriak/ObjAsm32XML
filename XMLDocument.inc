;----------------------------------------------------------------------------------------
; ObjAsm32 DOMXml
;
; Copyright 2007 Veria Kalantary
; veria.kalantary@gmail.com
; https://github.com/veriak
;
;----------------------------------------------------------------------------------------

include XML.inc

;	//	CXMLNode Object Definition
Object CXMLNode, ,
	StaticMethod    	Done
	StaticMethod		Init						
	StaticMethod		SetNode,				PIXMLDOMElement	 				
	StaticMethod		AddChild, 				LPCSTR    
    StaticMethod  		GetName 	
    StaticMethod  		SetValue, 				LPCSTR
    StaticMethod  		GetValue,				PVARIANT
    StaticMethod  		SetText, 				LPCSTR
    StaticMethod  		GetText,			  
    StaticMethod		SetAttribute, 			LPCSTR, LPCSTR
    StaticMethod		GetAttribute, 			LPCSTR
    StaticMethod		HasAttribute, 			LPCSTR    
    StaticMethod		HasChildNodes
    StaticMethod		GetChildNodes
    StaticMethod		GetChildNodesCount					
    StaticMethod		GetChildNode,			DWORD
    StaticMethod  		GetXML
    StaticMethod  		GetParentNode
    StaticMethod  		GetFirstChild
    StaticMethod  		GetLastChild
    StaticMethod  		PreviousSibling
    StaticMethod  		NextSibling
    StaticMethod		GetType
    StaticMethod		IsTextElement			
	Private								
    StaticMethod		AppendChildToParent, 	PIXMLDOMNode
    
	DefineVariable		pNode,					PIXMLDOMElement,	?				
ObjectEnd
PXMLNode	typedef ptr CXMLNode

;	//	CXMLDocument Object Definition
Object CXMLDocument, ,
	StaticMethod    	Done
	StaticMethod		Init	
	StaticMethod		Clear
	StaticMethod		GetDocumentElement		
	StaticMethod		CreateElement,			LPCSTR	
	StaticMethod		AppendChildToParent, 	PIXMLDOMNode, PIXMLDOMNode
	StaticMethod		AddChild,				LPCSTR 
	StaticMethod		LoadFromXML,			LPCSTR
	StaticMethod		LoadFromFile,			LPCSTR
	StaticMethod		SaveToXML,				DWORD
	StaticMethod		SaveToFile,				LPCSTR
	StaticMethod		SetXML,					LPCSTR
	StaticMethod		GetXML
    Private							
	StaticMethod		LoadXMLFile, 			LPCSTR    
    
	DefineVariable		pDoc,					PIXMLDOMDocument,	?    	
	Embed				DocumentElement,		CXMLNode				
ObjectEnd
PXMLDocument	typedef ptr CXMLDocument 


;	//	CXMLNode Object Implementation
Method CXMLNode.Done, uses esi 	
	SetObject esi
	coinvoke [esi].pNode, IXMLDOMNode, Release
   	mov [esi].pNode, NULL
MethodEnd

Method CXMLNode.Init, uses esi			
	SetObject esi 
MethodEnd    

Method CXMLNode.SetNode, uses esi, pNode:PIXMLDOMElement	
	SetObject esi	
   	m2m [esi].pNode, pNode
MethodEnd

Method CXMLNode.AppendChildToParent, uses esi, pChild:PIXMLDOMNode
    LOCAL pNewNode: PIXMLDOMNode    
    SetObject esi 
    coinvoke [esi].pNode, IXMLDOMNode, appendChild, pChild, addr pNewNode    
    .if eax != S_OK
    	.if pNewNode
    		coinvoke pNewNode, IXMLDOMNode, Release 
    	.endif
    .endif    
MethodEnd

Method CXMLNode.AddChild, uses esi, NodeName:LPCSTR	 
	LOCAL bstr: BSTR
	LOCAL pDoc: PIXMLDOMDocument
	LOCAL pChild: PIXMLDOMElement			
	SetObject esi	  		
	invoke CoCreateInstance, addr CLSID_DOMDocument, NULL, CLSCTX_INPROC_SERVER or CLSCTX_LOCAL_SERVER, \
									addr IID_IXMLDOMDocument, addr pDoc																													
	coinvoke pDoc, IXMLDOMDocument, put_async, VARIANT_FALSE					
	invoke StrToBstr, NodeName
	mov bstr, eax			
   	coinvoke pDoc, IXMLDOMDocument, createElement, bstr, addr pChild   	   	
   	invoke FreeBstr, addr bstr   		   	
   	OCall esi.AppendChildToParent, pChild   	
   	coinvoke pDoc, IXMLDOMDocument, Release
   	mov eax, pChild		   	
MethodEnd

Method CXMLNode.GetName, uses esi
	LOCAL bstr: BSTR	
	SetObject esi
	coinvoke [esi].pNode, IXMLDOMNode, get_nodeName, addr bstr
	invoke BstrToStr, bstr
	push eax
	invoke FreeBstr, addr bstr
	pop eax	
MethodEnd
	    
Method CXMLNode.SetValue, uses esi, Value:LPCSTR	
	LOCAL var: VARIANT
	SetObject esi
	invoke VariantInit, addr var	
	mov var.vt, VT_BSTR		
	invoke StrToBstr, Value
	mov var.bstrVal, eax   	
	coinvoke [esi].pNode, IXMLDOMNode, put_nodeValue, var
	invoke VariantClear, addr var	  			   			
MethodEnd

Method CXMLNode.GetValue, uses esi, pVar:PVARIANT	
	SetObject esi
	coinvoke [esi].pNode, IXMLDOMNode, get_nodeValue, pVar	
MethodEnd 

Method CXMLNode.SetText, uses esi, Value:LPCSTR
	LOCAL bstr: BSTR
	SetObject esi
	invoke StrToBstr, Value	
	mov bstr, eax    			
	coinvoke [esi].pNode, IXMLDOMNode, put_text, bstr	
	invoke FreeBstr, addr bstr  			   			
MethodEnd

Method CXMLNode.GetText, uses esi
	LOCAL bstr: BSTR	
	SetObject esi
	coinvoke [esi].pNode, IXMLDOMNode, get_text, addr bstr
	invoke BstrToStr, bstr
	push eax
	invoke FreeBstr, addr bstr
	pop eax
MethodEnd 
    
Method CXMLNode.SetAttribute, uses esi, Attribute:LPCSTR, Value:LPCSTR
	LOCAL pDoc: PIXMLDOMDocument
	LOCAL pAttribute: PIXMLDOMAttribute
   	LOCAL pAttributeOld: PIXMLDOMAttribute   		
	LOCAL bstr: BSTR
	LOCAL var: VARIANT	
	SetObject esi	
	mov pAttributeOld, NULL
	invoke CoCreateInstance, addr CLSID_DOMDocument, NULL, CLSCTX_INPROC_SERVER or CLSCTX_LOCAL_SERVER, \
									addr IID_IXMLDOMDocument, addr pDoc	
	coinvoke pDoc, IXMLDOMDocument, put_async, VARIANT_FALSE																																																						
	invoke StrToBstr, Attribute	
	mov bstr, eax	
	mov var.vt, VT_BSTR		
	invoke StrToBstr, Value 
   	mov var.bstrVal, eax   		   		   		   	
  	coinvoke pDoc, IXMLDOMDocument, createAttribute, bstr, addr pAttribute  		  		   		   		
 	coinvoke pAttribute, IXMLDOMAttribute, put_value, var 	 	 	
   	coinvoke [esi].pNode, IXMLDOMElement, setAttributeNode, pAttribute, addr pAttributeOld   		
   	invoke FreeBstr, addr bstr  		   		
  	.if pAttributeOld != NULL  	  			
    	coinvoke pAttributeOld, IXMLDOMAttribute, Release
    	mov pAttributeOld, NULL    	
   	.endif   
   	coinvoke pAttribute, IXMLDOMAttribute, Release
    mov pAttribute, NULL
    invoke VariantClear, addr var
   	coinvoke pDoc, IXMLDOMDocument, Release   	   	
MethodEnd

Method CXMLNode.GetAttribute, uses esi, Attribute:LPCSTR	
	LOCAL var: VARIANT
	LOCAL bstr: BSTR
	SetObject esi
	invoke StrToBstr, Attribute
	mov bstr, eax
	coinvoke [esi].pNode, IXMLDOMElement, getAttribute, bstr, addr var	 	
   	invoke FreeBstr, addr bstr 
   	invoke BstrToStr, var.bstrVal
	push eax
	invoke FreeBstr, addr bstr
	pop eax  			   		   	 
MethodEnd

Method CXMLNode.HasAttribute, uses esi, Attribute:LPCSTR	
	LOCAL pAttribute: PIXMLDOMAttribute
	LOCAL bstr: BSTR
	SetObject esi
	invoke StrToBstr, Attribute
	mov bstr, eax
	coinvoke [esi].pNode, IXMLDOMElement, getAttributeNode, bstr, addr pAttribute	 	
   	invoke FreeBstr, addr bstr  
   	.if pAttribute == NULL
   		mov eax, FALSE
   	.else	
   		mov eax, TRUE
   	.endif		   		
MethodEnd

Method CXMLNode.HasChildNodes, uses esi
	LOCAL hasChild: VARIANT_BOOL 		
	SetObject esi	
	coinvoke [esi].pNode, IXMLDOMNode, hasChildNodes, addr hasChild
	.if hasChild == 0
		mov eax, FALSE
	.else	
		mov eax, TRUE
	.endif	
MethodEnd

Method CXMLNode.GetChildNodes, uses esi 	
	LOCAL pChildNodes: PIXMLDOMNodeList	
	SetObject esi	
	coinvoke [esi].pNode, IXMLDOMNode, get_childNodes, addr pChildNodes	
	mov eax, pChildNodes 
MethodEnd

Method CXMLNode.GetChildNodesCount, uses esi 	
	LOCAL pChildNodes: PIXMLDOMNodeList	
	LOCAL dwChildCount: DWORD
	SetObject esi	
	coinvoke [esi].pNode, IXMLDOMNode, get_childNodes, addr pChildNodes	
	coinvoke pChildNodes, IXMLDOMNodeList, get_length, addr dwChildCount
	coinvoke pChildNodes, IXMLDOMNodeList, Release		
	mov eax, dwChildCount 
MethodEnd

Method CXMLNode.GetChildNode, uses esi, dwIndex:DWORD
	LOCAL bstr: BSTR 	
	LOCAL pNodes: PIXMLDOMNodeList
	LOCAL pNode: PIXMLDOMNode
	LOCAL pElement: PIXMLDOMElement	
	SetObject esi	
	coinvoke [esi].pNode, IXMLDOMNode, get_childNodes, addr pNodes
	coinvoke pNodes, IXMLDOMNodeList, get_item, dwIndex, addr pNode
	coinvoke pNode, IXMLDOMNode, get_nodeTypeString, addr bstr				
	invoke BstrStrCmp, addr bstr, StrM("text") 					 
	.if eax	== 0													
		mov eax, pNode
	.else					
		coinvoke pNode, IXMLDOMNode, QueryInterface, addr IID_IXMLDOMElement, addr pElement
		coinvoke pNode, IXMLDOMNode, Release		 
		mov eax, pElement 												
	.endif									
MethodEnd

Method CXMLNode.GetXML, uses esi	
	LOCAL bstr: BSTR
	SetObject esi
	coinvoke [esi].pNode, IXMLDOMNode, get_xml, addr bstr	
	invoke BstrToStr, bstr
	push eax
	invoke FreeBstr, addr bstr
	pop eax   		     	
MethodEnd

Method CXMLNode.GetParentNode, uses esi
	LOCAL pNode: PIXMLDOMNode
	LOCAL pElement: PIXMLDOMElement	
	SetObject esi		
	coinvoke [esi].pNode, IXMLDOMNode, get_parentNode, addr pNode
	coinvoke pNode, IXMLDOMNode, QueryInterface, addr IID_IXMLDOMElement, addr pElement
	coinvoke pNode, IXMLDOMNode, Release		 
	mov eax, pElement 
MethodEnd

Method CXMLNode.GetFirstChild, uses esi
	LOCAL pNode: PIXMLDOMNode
	LOCAL pElement: PIXMLDOMElement	
	SetObject esi		
	coinvoke [esi].pNode, IXMLDOMNode, get_firstChild, addr pNode
	coinvoke pNode, IXMLDOMNode, QueryInterface, addr IID_IXMLDOMElement, addr pElement
	coinvoke pNode, IXMLDOMNode, Release		 
	mov eax, pElement 
MethodEnd

Method CXMLNode.GetLastChild, uses esi
	LOCAL pNode: PIXMLDOMNode
	LOCAL pElement: PIXMLDOMElement	
	SetObject esi		
	coinvoke [esi].pNode, IXMLDOMNode, get_lastChild, addr pNode
	coinvoke pNode, IXMLDOMNode, QueryInterface, addr IID_IXMLDOMElement, addr pElement
	coinvoke pNode, IXMLDOMNode, Release		 
	mov eax, pElement 
MethodEnd

Method CXMLNode.PreviousSibling, uses esi
	LOCAL pNode: PIXMLDOMNode
	LOCAL pElement: PIXMLDOMElement	
	SetObject esi		
	coinvoke [esi].pNode, IXMLDOMNode, get_previousSibling, addr pNode
	coinvoke pNode, IXMLDOMNode, QueryInterface, addr IID_IXMLDOMElement, addr pElement
	coinvoke pNode, IXMLDOMNode, Release		 
	mov eax, pElement 
MethodEnd

Method CXMLNode.NextSibling, uses esi
	LOCAL pNode: PIXMLDOMNode
	LOCAL pElement: PIXMLDOMElement
	SetObject esi
	coinvoke [esi].pNode, IXMLDOMNode, get_nextSibling, addr pNode
	coinvoke pNode, IXMLDOMNode, QueryInterface, addr IID_IXMLDOMElement, addr pElement
	coinvoke pNode, IXMLDOMNode, Release		 
	mov eax, pElement 	
MethodEnd

Method CXMLNode.GetType, uses esi	
	LOCAL bstr: BSTR
	SetObject esi
	coinvoke [esi].pNode, IXMLDOMNode, get_nodeTypeString, addr bstr
	invoke BstrToStr, bstr
	push eax
	invoke FreeBstr, addr bstr
	pop eax	
MethodEnd

Method CXMLNode.IsTextElement, uses esi	
	LOCAL bstr: BSTR
	LOCAL pNode: PIXMLDOMNode
	LOCAL pNodes: PIXMLDOMNodeList
	
	SetObject esi					
	OCall esi.GetType	
	push eax 
	invoke lstrcmp, eax, StrM("element")
	.if eax == 0
		pop eax		
		invoke GlobalFree, eax
		OCall esi.HasChildNodes
		.if eax
			OCall esi.GetChildNodesCount
			.if eax == 1
				coinvoke [esi].pNode, IXMLDOMNode, get_childNodes, addr pNodes
				coinvoke pNodes, IXMLDOMNodeList, get_item, 0, addr pNode	
				coinvoke pNode, IXMLDOMNode, get_nodeTypeString, addr bstr				
				invoke BstrStrCmp, addr bstr, StrM("text") 					 
				.if eax	== 0													
					mov eax, TRUE
				.else					
					mov eax, FALSE												
				.endif								
				jmp @@exit
			.endif					
		.endif	
	.else
		pop eax
		invoke GlobalFree, eax	
	.endif				
	mov eax, FALSE 
@@exit:			
MethodEnd

;	//	CXMLDocument Object Implementation
Method CXMLDocument.Done, uses esi 	
	SetObject esi
	coinvoke [esi].pDoc, IXMLDOMDocument, Release	
MethodEnd
 
Method CXMLDocument.Init, uses esi			
	SetObject esi 						        		
	invoke CoCreateInstance, addr CLSID_DOMDocument, NULL, CLSCTX_INPROC_SERVER or CLSCTX_LOCAL_SERVER, \
									addr IID_IXMLDOMDocument, addr [esi].pDoc																																							
	coinvoke [esi].pDoc, IXMLDOMDocument, put_async, VARIANT_FALSE				
MethodEnd    

Method CXMLDocument.Clear, uses esi
	LOCAL bIsSuccessful: WORD	
	SetObject esi
	coinvoke [esi].pDoc, IXMLDOMDocument, loadXML, NULL, addr bIsSuccessful
MethodEnd

Method CXMLDocument.LoadXMLFile, uses esi, lpFileName:LPCSTR
	LOCAL hFile: DWORD
	LOCAL lpBuff: DWORD
	LOCAL dwRead: DWORD	
	SetObject esi
	invoke CreateFile, lpFileName, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING,\
											FILE_ATTRIBUTE_NORMAL, 0
	.if eax != INVALID_HANDLE_VALUE
		mov	hFile, eax
		invoke GetFileSize, hFile, NULL
		push eax
		inc	eax
		invoke GlobalAlloc, GPTR, eax
		mov	lpBuff, eax
		invoke GlobalLock, lpBuff
		pop	edx
		invoke ReadFile, hFile, lpBuff, edx, addr dwRead, NULL
		invoke CloseHandle, hFile
		mov eax, lpBuff		
	.else
		invoke MessageBox, NULL, StrM("Can not open XML file"), NULL, \
									MB_OK or MB_ICONERROR
		mov	eax, FALSE
	.endif
MethodEnd

Method CXMLDocument.GetDocumentElement, uses esi
	LOCAL pNode: PIXMLDOMElement
    SetObject esi
    coinvoke [esi].pDoc, IXMLDOMDocument, get_documentElement, addr pNode
    mov eax, pNode 
MethodEnd

Method CXMLDocument.AppendChildToParent, uses esi, pChild:PIXMLDOMNode, pParent:PIXMLDOMNode
    LOCAL pNewNode: PIXMLDOMNode    
    SetObject esi
    coinvoke pParent, IXMLDOMNode, appendChild, pChild, addr pNewNode
    .if eax != S_OK
    	.if pNewNode
    		coinvoke pNewNode, IXMLDOMNode, Release 
    	.endif
    .endif        
MethodEnd

Method CXMLDocument.CreateElement, uses esi, NodeName:LPCSTR	 
	LOCAL bstr: BSTR
	LOCAL pChild: PIXMLDOMElement			
	SetObject esi	
	invoke StrToBstr, NodeName
	mov bstr, eax		
   	coinvoke [esi].pDoc, IXMLDOMDocument, createElement, bstr, addr pChild
   	invoke FreeBstr, addr bstr	   	
   	mov eax, pChild		
MethodEnd

Method CXMLDocument.AddChild, uses esi, NodeName:LPCSTR	 
	LOCAL bstr: BSTR
	LOCAL pChild: PIXMLDOMElement			
	SetObject esi	
	OCall esi.CreateElement, NodeName
	push eax
	OCall esi.AppendChildToParent, eax, [esi].pDoc
	pop eax	 
MethodEnd

Method CXMLDocument.LoadFromXML, uses esi, pXML:LPCSTR
	LOCAL bIsSuccessful: WORD
	LOCAL lpXMLBuff: DWORD
	LOCAL lpwXMLBuff: DWORD
	LOCAL dwBuffSize: DWORD	
	SetObject esi
	m2m lpXMLBuff, pXML	
	Invoke MultiByteToWideChar, CP_ACP, 0, lpXMLBuff, -1, lpwXMLBuff, 0
	.if eax != 0
		shl eax, 1
		mov dwBuffSize, eax
		inc eax			
		invoke GlobalAlloc, GPTR, eax
		mov lpwXMLBuff, eax
		Invoke MultiByteToWideChar, CP_ACP, 0, lpXMLBuff, -1, lpwXMLBuff, dwBuffSize
	.else
		invoke GlobalFree, lpXMLBuff
		ret	
	.endif		
	invoke GlobalFree, lpXMLBuff		
	coinvoke [esi].pDoc, IXMLDOMDocument, loadXML, lpwXMLBuff, addr bIsSuccessful
	invoke GlobalFree, lpwXMLBuff	
	OCall esi.GetDocumentElement
	mov [esi].DocumentElement.pNode, eax			
MethodEnd

Method CXMLDocument.LoadFromFile, uses esi, lpFileName:LPCSTR
	SetObject esi
	OCall esi.LoadXMLFile, lpFileName
	push eax
	OCall esi.LoadFromXML, eax
	pop eax
	invoke GlobalFree, eax
MethodEnd

Method CXMLDocument.SaveToXML, uses esi, pBstr:DWORD	
	SetObject esi
	coinvoke [esi].pDoc, IXMLDOMDocument, get_xml, pBstr	   		     	
MethodEnd

Method CXMLDocument.SaveToFile, uses esi, lpFileName:DWORD
	LOCAL bstr: BSTR
	LOCAL var: VARIANT
	SetObject esi
	coinvoke [esi].pDoc, IXMLDOMDocument, get_xml, addr bstr   		     	
   	mov var.vt, VT_BSTR
	invoke StrToBstr, lpFileName
   	mov var.bstrVal, eax
   	coinvoke [esi].pDoc, IXMLDOMDocument, save, var
MethodEnd

Method CXMLDocument.SetXML, uses esi, pXML:LPCSTR
	SetObject esi
	OCall esi::CXMLDocument.LoadFromXML, pXML				
MethodEnd

Method CXMLDocument.GetXML, uses esi	
	LOCAL bstr: BSTR
	SetObject esi
	OCall esi.SaveToXML, addr bstr	
	invoke BstrToStr, bstr
	push eax
	invoke FreeBstr, addr bstr
	pop eax   		     	
MethodEnd
