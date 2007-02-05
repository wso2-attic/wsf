

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 6.00.0366 */
/* at Wed Jan 24 10:05:10 2007
 */
/* Compiler settings for .\WSRequest.idl:
    Oicf, W1, Zp8, env=Win32 (32b run)
    protocol : dce , ms_ext, c_ext
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
//@@MIDL_FILE_HEADING(  )

#pragma warning( disable: 4049 )  /* more than 64k source lines */


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 440
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __WSO2_h__
#define __WSO2_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IWSRequest_FWD_DEFINED__
#define __IWSRequest_FWD_DEFINED__
typedef interface IWSRequest IWSRequest;
#endif 	/* __IWSRequest_FWD_DEFINED__ */


#ifndef ___IWSRequestEvents_FWD_DEFINED__
#define ___IWSRequestEvents_FWD_DEFINED__
typedef interface _IWSRequestEvents _IWSRequestEvents;
#endif 	/* ___IWSRequestEvents_FWD_DEFINED__ */


#ifndef __WSRequest_FWD_DEFINED__
#define __WSRequest_FWD_DEFINED__

#ifdef __cplusplus
typedef class WSRequest WSRequest;
#else
typedef struct WSRequest WSRequest;
#endif /* __cplusplus */

#endif 	/* __WSRequest_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 

void * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void * ); 

#ifndef __IWSRequest_INTERFACE_DEFINED__
#define __IWSRequest_INTERFACE_DEFINED__

/* interface IWSRequest */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IWSRequest;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("2BBF90C9-1AAA-4BBF-98D1-887A10A88B88")
    IWSRequest : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE open( 
            VARIANT *method,
            BSTR sUrl,
            /* [optional] */ VARIANT bAsync,
            /* [optional] */ VARIANT sUserName,
            /* [optional] */ VARIANT sPasswd) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_onreadystatechange( 
            /* [retval][out] */ VARIANT *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_onreadystatechange( 
            /* [in] */ VARIANT newVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE send( 
            VARIANT payLoad) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_responseText( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_responseXML( 
            /* [retval][out] */ VARIANT *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_readyState( 
            /* [retval][out] */ SHORT *pVal) = 0;
        
        virtual /* [restricted][helpstring][id] */ HRESULT STDMETHODCALLTYPE change( 
            /* [in] */ VARIANT newVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IWSRequestVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IWSRequest * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IWSRequest * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IWSRequest * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IWSRequest * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IWSRequest * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IWSRequest * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IWSRequest * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *open )( 
            IWSRequest * This,
            VARIANT *method,
            BSTR sUrl,
            /* [optional] */ VARIANT bAsync,
            /* [optional] */ VARIANT sUserName,
            /* [optional] */ VARIANT sPasswd);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_onreadystatechange )( 
            IWSRequest * This,
            /* [retval][out] */ VARIANT *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_onreadystatechange )( 
            IWSRequest * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *send )( 
            IWSRequest * This,
            VARIANT payLoad);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_responseText )( 
            IWSRequest * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_responseXML )( 
            IWSRequest * This,
            /* [retval][out] */ VARIANT *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_readyState )( 
            IWSRequest * This,
            /* [retval][out] */ SHORT *pVal);
        
        /* [restricted][helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *change )( 
            IWSRequest * This,
            /* [in] */ VARIANT newVal);
        
        END_INTERFACE
    } IWSRequestVtbl;

    interface IWSRequest
    {
        CONST_VTBL struct IWSRequestVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IWSRequest_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IWSRequest_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IWSRequest_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IWSRequest_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IWSRequest_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IWSRequest_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IWSRequest_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IWSRequest_open(This,method,sUrl,bAsync,sUserName,sPasswd)	\
    (This)->lpVtbl -> open(This,method,sUrl,bAsync,sUserName,sPasswd)

#define IWSRequest_get_onreadystatechange(This,pVal)	\
    (This)->lpVtbl -> get_onreadystatechange(This,pVal)

#define IWSRequest_put_onreadystatechange(This,newVal)	\
    (This)->lpVtbl -> put_onreadystatechange(This,newVal)

#define IWSRequest_send(This,payLoad)	\
    (This)->lpVtbl -> send(This,payLoad)

#define IWSRequest_get_responseText(This,pVal)	\
    (This)->lpVtbl -> get_responseText(This,pVal)

#define IWSRequest_get_responseXML(This,pVal)	\
    (This)->lpVtbl -> get_responseXML(This,pVal)

#define IWSRequest_get_readyState(This,pVal)	\
    (This)->lpVtbl -> get_readyState(This,pVal)

#define IWSRequest_change(This,newVal)	\
    (This)->lpVtbl -> change(This,newVal)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IWSRequest_open_Proxy( 
    IWSRequest * This,
    VARIANT *method,
    BSTR sUrl,
    /* [optional] */ VARIANT bAsync,
    /* [optional] */ VARIANT sUserName,
    /* [optional] */ VARIANT sPasswd);


void __RPC_STUB IWSRequest_open_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IWSRequest_get_onreadystatechange_Proxy( 
    IWSRequest * This,
    /* [retval][out] */ VARIANT *pVal);


void __RPC_STUB IWSRequest_get_onreadystatechange_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IWSRequest_put_onreadystatechange_Proxy( 
    IWSRequest * This,
    /* [in] */ VARIANT newVal);


void __RPC_STUB IWSRequest_put_onreadystatechange_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IWSRequest_send_Proxy( 
    IWSRequest * This,
    VARIANT payLoad);


void __RPC_STUB IWSRequest_send_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IWSRequest_get_responseText_Proxy( 
    IWSRequest * This,
    /* [retval][out] */ BSTR *pVal);


void __RPC_STUB IWSRequest_get_responseText_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IWSRequest_get_responseXML_Proxy( 
    IWSRequest * This,
    /* [retval][out] */ VARIANT *pVal);


void __RPC_STUB IWSRequest_get_responseXML_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IWSRequest_get_readyState_Proxy( 
    IWSRequest * This,
    /* [retval][out] */ SHORT *pVal);


void __RPC_STUB IWSRequest_get_readyState_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [restricted][helpstring][id] */ HRESULT STDMETHODCALLTYPE IWSRequest_change_Proxy( 
    IWSRequest * This,
    /* [in] */ VARIANT newVal);


void __RPC_STUB IWSRequest_change_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IWSRequest_INTERFACE_DEFINED__ */



#ifndef __WSO2Lib_LIBRARY_DEFINED__
#define __WSO2Lib_LIBRARY_DEFINED__

/* library WSO2Lib */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_WSO2Lib;

#ifndef ___IWSRequestEvents_DISPINTERFACE_DEFINED__
#define ___IWSRequestEvents_DISPINTERFACE_DEFINED__

/* dispinterface _IWSRequestEvents */
/* [helpstring][uuid] */ 


EXTERN_C const IID DIID__IWSRequestEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("FE361199-4922-47FE-BDB8-319BF973DC90")
    _IWSRequestEvents : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _IWSRequestEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            _IWSRequestEvents * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            _IWSRequestEvents * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            _IWSRequestEvents * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            _IWSRequestEvents * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            _IWSRequestEvents * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            _IWSRequestEvents * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            _IWSRequestEvents * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        END_INTERFACE
    } _IWSRequestEventsVtbl;

    interface _IWSRequestEvents
    {
        CONST_VTBL struct _IWSRequestEventsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _IWSRequestEvents_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define _IWSRequestEvents_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define _IWSRequestEvents_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define _IWSRequestEvents_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define _IWSRequestEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define _IWSRequestEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define _IWSRequestEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___IWSRequestEvents_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_WSRequest;

#ifdef __cplusplus

class DECLSPEC_UUID("F3C3309A-9AA4-4EB6-859B-9DAC9C8B62EB")
WSRequest;
#endif
#endif /* __WSO2Lib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  BSTR_UserSize(     unsigned long *, unsigned long            , BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserMarshal(  unsigned long *, unsigned char *, BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserUnmarshal(unsigned long *, unsigned char *, BSTR * ); 
void                      __RPC_USER  BSTR_UserFree(     unsigned long *, BSTR * ); 

unsigned long             __RPC_USER  VARIANT_UserSize(     unsigned long *, unsigned long            , VARIANT * ); 
unsigned char * __RPC_USER  VARIANT_UserMarshal(  unsigned long *, unsigned char *, VARIANT * ); 
unsigned char * __RPC_USER  VARIANT_UserUnmarshal(unsigned long *, unsigned char *, VARIANT * ); 
void                      __RPC_USER  VARIANT_UserFree(     unsigned long *, VARIANT * ); 

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


