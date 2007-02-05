/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM nsIWSRequest.idl
 */

#ifndef __gen_nsIWSRequest_h__
#define __gen_nsIWSRequest_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#ifndef __gen_nsIVariant_h__
#include "nsIVariant.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIWSRequest */
#define NS_IWSREQUEST_IID_STR "1a2a3848-f779-4141-aedd-9a4e2018f123"

#define NS_IWSREQUEST_IID \
  {0x1a2a3848, 0xf779, 0x4141, \
    { 0xae, 0xdd, 0x9a, 0x4e, 0x20, 0x18, 0xf1, 0x23 }}

/**
 * WSRequest is design to invoke web-services in a very similar way you
 * invoke AJAX calls. It acts as the soap wrapper for XMLHttpRequest and use
 * axis2/c web service engine for soap processing.
 * nsIWSRequest describes web-services specific API for WSRequest
 */
class NS_NO_VTABLE nsIWSRequest : public nsISupports {
 public: 

  NS_DEFINE_STATIC_IID_ACCESSOR(NS_IWSREQUEST_IID)

  /* void open (in nsIVariant optionSet, in AUTF8String url); */
  NS_IMETHOD Open(nsIVariant *optionSet, const nsACString & url) = 0;

};

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIWSREQUEST \
  NS_IMETHOD Open(nsIVariant *optionSet, const nsACString & url); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIWSREQUEST(_to) \
  NS_IMETHOD Open(nsIVariant *optionSet, const nsACString & url) { return _to Open(optionSet, url); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIWSREQUEST(_to) \
  NS_IMETHOD Open(nsIVariant *optionSet, const nsACString & url) { return !_to ? NS_ERROR_NULL_POINTER : _to->Open(optionSet, url); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsWSRequest : public nsIWSRequest
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIWSREQUEST

  nsWSRequest();

private:
  ~nsWSRequest();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsWSRequest, nsIWSRequest)

nsWSRequest::nsWSRequest()
{
  /* member initializers and constructor code */
}

nsWSRequest::~nsWSRequest()
{
  /* destructor code */
}

/* void open (in nsIVariant optionSet, in AUTF8String url); */
NS_IMETHODIMP nsWSRequest::Open(nsIVariant *optionSet, const nsACString & url)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIWSRequest_h__ */
