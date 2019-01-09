;----------------------------------------------------------------------------------------
; COM Masm32 Library
;
; Copyright 2007 Veria Kalantary
; veria.kalantary@gmail.com
; https://github.com/veriak
;
;----------------------------------------------------------------------------------------

include \masm32\com\include\colib.inc
includelib \masm32\com\colib\colib.lib

_vtIPersist MACRO CastName:REQ
	_vtIUnknown CastName	
    &CastName&_GetClassID				comethod2       ?
ENDM

IPersist struct
	_vtIPersist IPersist	
IPersist ends

_vtIPersistFile MACRO CastName:REQ
	_vtIPersist CastName
	&CastName&_IsDirty              	comethod1       ?	
    &CastName&_Load                 	comethod3       ?
    &CastName&_Save                 	comethod3       ?
    &CastName&_SaveCompleted        	comethod2       ?
    &CastName&_GetCurFile           	comethod2       ?
ENDM

IPersistFile struct
	_vtIPersistFile IPersistFile	
IPersistFile ends

_vtIPersistStream MACRO CastName:REQ
	_vtIPersist CastName
	&CastName&_IsDirty              	comethod1       ?	
    &CastName&_Load                 	comethod2       ?
    &CastName&_Save                 	comethod3       ?
    &CastName&_GetSizeMax	        	comethod2       ?    
ENDM

IPersistStream struct
	_vtIPersistStream IPersistStream	
IPersistStream ends

_vtIMoniker MACRO CastName:REQ
	_vtIPersistStream CastName		
	&CastName&_BindToObject 			comethod5       ?
	&CastName&_BindToStorage 			comethod5       ?
	&CastName&_Reduce 					comethod5       ?
	&CastName&_ComposeWith 				comethod4       ?
	&CastName&_Enum 					comethod3       ?
	&CastName&_IsEqual 					comethod2       ?
	&CastName&_Hash 					comethod2       ?
	&CastName&_IsRunning 				comethod4       ?
	&CastName&_GetTimeOfLastChange 		comethod4       ?
	&CastName&_Inverse 					comethod2       ?
	&CastName&_CommonPrefixWith 		comethod3       ?
	&CastName&_RelativePathTo 			comethod3       ?
	&CastName&_GetDisplayName 			comethod4       ?
	&CastName&_ParseDisplayName 		comethod6       ?
	&CastName&_IsSystemMoniker  		comethod2       ?
ENDM

IMoniker struct
	_vtIMoniker IMoniker	
IMoniker ends

_vtIEnumMoniker MACRO CastName:REQ
	_vtIUnknown CastName	
    &CastName&_Next						comethod4       ?		 
	&CastName&_Skip  					comethod2       ?
	&CastName&_Reset  					comethod1       ?
	&CastName&_Clone 					comethod2       ?
ENDM

IEnumMoniker struct
	_vtIEnumMoniker IEnumMoniker	
IEnumMoniker ends

_vtIDataObject MACRO CastName:REQ
	_vtIUnknown CastName	
    &CastName&_GetData  				comethod3       ?	 
	&CastName&_GetDataHere  	 		comethod3       ?
	&CastName&_QueryGetData   			comethod2       ?
	&CastName&_GetCanonicalFormatEtc   	comethod3       ?
	&CastName&_SetData 					comethod4       ?
 	&CastName&_EnumFormatEtc 			comethod3       ?
	&CastName&_DAdvise					comethod5       ?
	&CastName&_DUnadvise 				comethod2       ?
 	&CastName&_EnumDAdvise 				comethod2       ?
ENDM

IDataObject struct
	_vtIDataObject IDataObject	
IDataObject ends

_vtISequentialStream MACRO CastName:REQ
	_vtIUnknown CastName
	&CastName&_Read  					comethod4       ?	  
	&CastName&_Write 					comethod4       ?
ENDM

ISequentialStream struct
	_vtISequentialStream ISequentialStream	
ISequentialStream ends

_vtIStream MACRO CastName:REQ
	_vtISequentialStream CastName	
	&CastName&_Seek 					comethod4       ?	
	&CastName&_SetSize 					comethod2       ?
	&CastName&_CopyTo 					comethod5       ?
	&CastName&_Commit 					comethod2       ? 
	&CastName&_Revert					comethod1       ? 
	&CastName&_LockRegion				comethod4       ? 
	&CastName&_UnlockRegion				comethod4       ? 
	&CastName&_Stat 					comethod3       ? 
	&CastName&_Clone 					comethod2       ?      	 	 
ENDM

IStream struct
	_vtIStream IStream	
IStream ends

PIUnknown				typedef	ptr		IUnknown
PIPersist				typedef	ptr		IPersist
PIPersistFile			typedef	ptr		IPersistFile
PIPersistStream			typedef	ptr		IPersistStream
PIMoniker				typedef	ptr		IMoniker
PIEnumMoniker			typedef	ptr		IEnumMoniker
PIDataObject			typedef	ptr		IDataObject
PISequentialStream		typedef	ptr		IISequentialStream
PIStream				typedef	ptr		IStream

PPIDataObject			typedef	ptr		PIDataObject

.const
	IID_IUnknown        		GUID sIID_IUnknown
	IID_IClassFactory   		GUID sIID_IClassFactory
	IID_NULL					GUID <00000000h, 0000h, 0000h, <00h, 00h, 00h, 00h, 00h, 00h, 00h, 00h>> 
	IID_IPersist				GUID <0000010ch, 0000h, 0000h, <0C0h, 00h, 00h, 00h, 00h, 00h, 00h, 46h>>
	IID_IPersistFile			GUID <0000010bh, 0000h, 0000h, <0C0h, 00h, 00h, 00h, 00h, 00h, 00h, 46h>>
	IID_IPersistStream			GUID <00000109h, 0000h, 0000h, <0C0h, 00h, 00h, 00h, 00h, 00h, 00h, 46h>>
	IID_IMoniker				GUID <0000000Fh, 0000h, 0000h, <0C0h, 00h, 00h, 00h, 00h, 00h, 00h, 46h>>
	IID_IEnumMoniker			GUID <00000102h, 0000h, 0000h, <0C0h, 00h, 00h, 00h, 00h, 00h, 00h, 46h>>
	IID_IDataObject				GUID <0000010eh, 0000h, 0000h, <0C0h, 00h, 00h, 00h, 00h, 00h, 00h, 46h>>
	IID_ISequentialStream		GUID <0c733a30h, 2a1ch, 11ceh, <0adh, 0e5h, 00h, 0aah, 00h, 44h, 77h, 3dh>>	
	IID_IStream					GUID <0000000ch, 0000h, 0000h, <0C0h, 00h, 00h, 00h, 00h, 00h, 00h, 46h>>
