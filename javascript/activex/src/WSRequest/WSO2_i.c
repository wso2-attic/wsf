

/* this ALWAYS GENERATED file contains the IIDs and CLSIDs */

/* link this file in with the server and any clients */


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


#ifdef __cplusplus
extern "C"{
#endif 


#include <rpc.h>
#include <rpcndr.h>

#ifdef _MIDL_USE_GUIDDEF_

#ifndef INITGUID
#define INITGUID
#include <guiddef.h>
#undef INITGUID
#else
#include <guiddef.h>
#endif

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        DEFINE_GUID(name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8)

#else // !_MIDL_USE_GUIDDEF_

#ifndef __IID_DEFINED__
#define __IID_DEFINED__

typedef struct _IID
{
    unsigned long x;
    unsigned short s1;
    unsigned short s2;
    unsigned char  c[8];
} IID;

#endif // __IID_DEFINED__

#ifndef CLSID_DEFINED
#define CLSID_DEFINED
typedef IID CLSID;
#endif // CLSID_DEFINED

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        const type name = {l,w1,w2,{b1,b2,b3,b4,b5,b6,b7,b8}}

#endif !_MIDL_USE_GUIDDEF_

MIDL_DEFINE_GUID(IID, IID_IWSRequest,0x2BBF90C9,0x1AAA,0x4BBF,0x98,0xD1,0x88,0x7A,0x10,0xA8,0x8B,0x88);


MIDL_DEFINE_GUID(IID, LIBID_WSO2Lib,0x2DCA4302,0xE2CB,0x4C69,0xB3,0xCB,0xC5,0xD6,0xAE,0xEA,0xC0,0xC5);


MIDL_DEFINE_GUID(IID, DIID__IWSRequestEvents,0xFE361199,0x4922,0x47FE,0xBD,0xB8,0x31,0x9B,0xF9,0x73,0xDC,0x90);


MIDL_DEFINE_GUID(CLSID, CLSID_WSRequest,0xF3C3309A,0x9AA4,0x4EB6,0x85,0x9B,0x9D,0xAC,0x9C,0x8B,0x62,0xEB);

#undef MIDL_DEFINE_GUID

#ifdef __cplusplus
}
#endif



