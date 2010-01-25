

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 6.00.0366 */
/* at Mon Mar 03 10:18:56 2008
 */
/* Compiler settings for .\FlickrUploader.idl:
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

#ifndef __FlickrUploader_h__
#define __FlickrUploader_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IShellExtInterface_FWD_DEFINED__
#define __IShellExtInterface_FWD_DEFINED__
typedef interface IShellExtInterface IShellExtInterface;
#endif 	/* __IShellExtInterface_FWD_DEFINED__ */


#ifndef __ShellExtInterface_FWD_DEFINED__
#define __ShellExtInterface_FWD_DEFINED__

#ifdef __cplusplus
typedef class ShellExtInterface ShellExtInterface;
#else
typedef struct ShellExtInterface ShellExtInterface;
#endif /* __cplusplus */

#endif 	/* __ShellExtInterface_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 

void * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void * ); 

#ifndef __IShellExtInterface_INTERFACE_DEFINED__
#define __IShellExtInterface_INTERFACE_DEFINED__

/* interface IShellExtInterface */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IShellExtInterface;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("AACDC34F-5042-4334-BA80-7BFE0C7E5BF9")
    IShellExtInterface : public IUnknown
    {
    public:
    };
    
#else 	/* C style interface */

    typedef struct IShellExtInterfaceVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IShellExtInterface * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IShellExtInterface * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IShellExtInterface * This);
        
        END_INTERFACE
    } IShellExtInterfaceVtbl;

    interface IShellExtInterface
    {
        CONST_VTBL struct IShellExtInterfaceVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IShellExtInterface_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IShellExtInterface_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IShellExtInterface_Release(This)	\
    (This)->lpVtbl -> Release(This)


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IShellExtInterface_INTERFACE_DEFINED__ */



#ifndef __FlickrUploaderLib_LIBRARY_DEFINED__
#define __FlickrUploaderLib_LIBRARY_DEFINED__

/* library FlickrUploaderLib */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_FlickrUploaderLib;

EXTERN_C const CLSID CLSID_ShellExtInterface;

#ifdef __cplusplus

class DECLSPEC_UUID("01F2BC2E-AAA8-4B80-89AA-C43D27F648D3")
ShellExtInterface;
#endif
#endif /* __FlickrUploaderLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


