/*
 * Copyright 2004,2005 The Apache Software Foundation.
 *
 * Licensed under the Apache License, Version 2.0 (the "License")" "
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */


#ifndef OXS_CONSTANTS_H
#define OXS_CONSTANTS_H

#ifdef __cplusplus
extern "C"
{
#endif

    /*Default values*/
    /*Key transfer algo*/
#define OXS_DEFAULT_KT_ALGO_HREF    OXS_HREF_RSA_PKCS1
#define OXS_DEFAULT_SYM_ALGO        OXS_HREF_AES_256_CBC
#define OXS_STR_DEFAULT             OXS_STR_EMBEDDED


    /****************************************************************
       Global prefixes 
    ****************************************************************/
#define OXS_XENC "xenc"
#define OXS_DS "ds"
#define OXS_WSSE "wsse"
#define OXS_WSSE_XMLNS "http://docs.oasis-open.org/wss/2004/01/oasis-200401-wss-wssecurity-secext-1.0.xsd"
#define OXS_WSU "wsu"
    /****************************************************************
        ID Prefixes
    ****************************************************************/
#define OXS_ENCDATA_ID "EncDataID"
#define OXS_ENCKEY_ID "EncKeyID"
#define OXS_SIG_ID "SigID"
#define OXS_CERT_ID "CertID"
#define OXS_EMBEDDED_ID "EmbeddedID"

    /****************************************************************
       Global namespaces 
    ****************************************************************/
#define OXS_DSIG_NS                "http://www.w3.org/2000/09/xmldsig#"
#define OXS_ENC_NS                 "http://www.w3.org/2001/04/xmlenc#"
#define OXS_WSSE_NS                "http://schemas.xmlsoap.org/ws/2002/04/secext"

    /****************************************************************
        DSig Nodes  
    ****************************************************************/
#define OXS_NODE_SIGNATURE         "Signature"
#define OXS_NODE_SIGNEDINFO        "SignedInfo"
#define OXS_NODE_CANONICALIZATION_METHOD "CanonicalizationMethod"
#define OXS_NODE_SIGNATURE_METHOD    "SignatureMethod"
#define OXS_NODE_SIGNATURE_VALUE     "SignatureValue"
#define OXS_NODE_DIGEST_METHOD       "DigestMethod"
#define OXS_NODE_DIGEST_VALUE        "DigestValue"
#define OXS_NODE_OBJECT             "Object"
#define OXS_NODE_MANIFEST           "Manifest"
#define OXS_NODE_SIGNATUREPROPERTIES "SignatureProperties"

    /****************************************************************
       Encryption Nodes 
    ****************************************************************/
#define OXS_NODE_ENCRYPTED_DATA             "EncryptedData"
#define OXS_NODE_ENCRYPTION_METHOD          "EncryptionMethod"
#define OXS_NODE_ENCRYPTION_PROPERTIES      "EncryptionProperties"
#define OXS_NODE_ENCRYPTION_PROPERTY        "EncryptionProperty"
#define OXS_NODE_CIPHER_DATA                "CipherData"
#define OXS_NODE_CIPHER_VALUE               "CipherValue"
#define OXS_NODE_CIPHER_REFERENCE           "CipherReference"
#define OXS_NODE_REFERENCE_LIST             "ReferenceList"
#define OXS_NODE_DATA_REFERENCE             "DataReference"
#define OXS_NODE_KEY_REFERENCE              "KeyReference"
#define OXS_NODE_CARRIED_KEYNAME            "CarriedKeyName"
#define OXS_TYPE_ENC_CONTENT                "http://www.w3.org/2001/04/xmlenc#Content"
#define OXS_TYPE_ENC_ELEMENT                "http://www.w3.org/2001/04/xmlenc#Element"

    /****************************************************************
       KeyInfo Nodes
    ****************************************************************/
#define OXS_NODE_KEY_INFO               "KeyInfo"
#define OXS_NODE_REFERENCE             "Reference"
#define OXS_NODE_TRANSFORMS            "Transforms"
#define OXS_NODE_TRANSFORM             "Transform"

    /****************************************************************
        KeyInfo Nodes
    ****************************************************************/
#define OXS_NODE_BINARY_SECURITY_TOKEN     "BinarySecurityToken"
#define OXS_NODE_KEY_IDENTIFIER     "KeyIdentifier"
#define OXS_NODE_SECURITY_TOKEN_REFRENCE    "SecurityTokenReference"
#define OXS_NODE_EMBEDDED    "Embedded"


    /****************************************************************
        Attributes
    ****************************************************************/
#define OXS_ATTR_ID            "Id"
#define OXS_ATTR_URI           "URI"
#define OXS_ATTR_TYPE          "Type"
#define OXS_ATTR_MIMETYPE      "MimeType"
#define OXS_ATTR_ENCODING      "Encoding"
#define OXS_ATTR_ALGORITHM     "Algorithm"
#define OXS_ATTR_FILTER        "Filter"
#define OXS_ATTR_RECIPIENT     "Recipient"
#define OXS_ATTR_TARGET        "Target"
#define OXS_ATTR_ENCODING_TYPE  "EncodingType"
#define OXS_ATTR_VALUE_TYPE     "ValueType"


    /****************************************************************
       AES 
    ****************************************************************/

#define OXS_NAME_AES_128_CBC        "aes128-cbc"
#define OXS_HREF_AES_128_CBC        "http://www.w3.org/2001/04/xmlenc#aes128-cbc"

#define OXS_NAME_AES_192_CBC        "aes192-cbc"
#define OXS_HREF_AES_192_CBC        "http://www.w3.org/2001/04/xmlenc#aes192-cbc"

#define OXS_NAME_AES_256_CBC        "aes256-cbc"
#define OXS_HREF_AES_256_CBC        "http://www.w3.org/2001/04/xmlenc#aes256-cbc"

#define OXS_NAME_KW_AES_128         "kw-aes128"
#define OXS_HREF_KW_AES_128         "http://www.w3.org/2001/04/xmlenc#kw-aes128"

#define OXS_NAME_KW_AES_192         "kw-aes192"
#define OXS_HREF_KW_AES_192         "http://www.w3.org/2001/04/xmlenc#kw-aes192"

#define OXS_NAME_KW_AES_256         "kw-aes256"
#define OXS_HREF_KW_AES_256         "http://www.w3.org/2001/04/xmlenc#kw-aes256"

    /****************************************************************
      BASE64 
    ****************************************************************/
#define OXS_NAME_BASE64           "base64"
#define OXS_HREF_BASE64           "http://www.w3.org/2000/09/xmldsig#base64"


    /****************************************************************
     DES 
    ****************************************************************/
#define OXS_NAME_DES_KEY_VALUE       "des"

#define OXS_NAME_DES3_CBC           "tripledes-cbc"
#define OXS_HREF_DES3_CBC           "http://www.w3.org/2001/04/xmlenc#tripledes-cbc"

#define OXS_NAME_KW_DES3            "kw-tripledes"
#define OXS_HREF_KW_DES3            "http://www.w3.org/2001/04/xmlenc#kw-tripledes"



    /****************************************************************
        DSA 
    ****************************************************************/
#define OXS_NAME_DSA_KEY_VALUE          "dsa"
#define OXS_NODE_DSA_KEY_VALUE          "DSAKeyValue"
#define OXS_HREF_DSA_KEY_VALUE          "http://www.w3.org/2000/09/xmldsig#DSAKeyValue"

#define OXS_NAME_DSA_SHA1          "dsa-sha1"
#define OXS_HREF_DSA_SHA1          "http://www.w3.org/2000/09/xmldsig#dsa-sha1"

    /****************************************************************
       EncryptedKey
    ****************************************************************/
#define OXS_NAME_ENCRYPTED_KEY         "enc-key"
#define OXS_NODE_ENCRYPTED_KEY         "EncryptedKey"
#define OXS_HREF_ENCRYPTED_KEY         "http://www.w3.org/2001/04/xmlenc#EncryptedKey"

    /****************************************************************
       C14N
    ****************************************************************/

#define OXS_HREF_XML_C14N                   "http://www.w3.org/TR/2001/REC-xml-c14n-20010315"
#define OXS_HREF_XML_EXC_C14N     "http://www.w3.org/2001/10/xml-exc-c14n#"

#define OXS_HREF_XML_C14N_WITH_COMMENTS         "http://www.w3.org/TR/2001/REC-xml-c14n-20010315#WithComments"
#define OXS_HREF_XML_EXC_C14N_WITH_COMMENTS "http://www.w3.org/2001/10/xml-exc-c14n#WithComments"
    /****************************************************************
       Transforms
    ****************************************************************/
#define OXS_HREF_TRANSFORM_XML_EXC_C14N     OXS_HREF_XML_EXC_C14N
#define OXS_HREF_TRANSFORM_STR_TRANSFORM     "http://docs.oasis-open.org/wss/2004/01/oasis-200401-wss-soap-message-security-1.0#STR-Transform"
#define OXS_HREF_TRANSFORM_ENVELOPED_SIGNATURE "http://www.w3.org/2000/09/xmldsig#enveloped-signature"

    /****************************************************************
        KeyNAME
    ****************************************************************/
#define OXS_NAME_KEY_NAME          "key-name"
#define OXS_NODE_KEY_NAME          "KeyName"


    /****************************************************************
        KeyValue 
    ****************************************************************/
#define OXS_NAME_KEY_VALUE         "key-value"
#define OXS_NODE_KEY_VALUE         "KeyValue"


    /****************************************************************
        MD5 
    ****************************************************************/
#define OXS_NAME_MD5              "md5"
#define OXS_HREF_MD5              "http://www.w3.org/2001/04/xmldsig-more#md5"

    /****************************************************************
        RetrievalMethod
    ****************************************************************/
#define OXS_NAME_RETRIEVAL_METHOD      "retrieval-method"
#define OXS_NODE_RETRIEVAL_METHOD      "RetrievalMethod"

    /****************************************************************
        RSA 
    ****************************************************************/
#define OXS_NAME_RSAKEY_VALUE          "rsa"
#define OXS_NODE_RSAKEY_VALUE          "RSAKeyValue"
#define OXS_HREF_RSAKEY_VALUE          "http://www.w3.org/2000/09/xmldsig#RSAKeyValue"

#define OXS_NAME_RSA_MD5           "rsa-md5"
#define OXS_HREF_RSA_MD5           "http://www.w3.org/2001/04/xmldsig-more#rsa-md5"

#define OXS_NAME_RSA_RIPEMD160         "rsa-ripemd160"
#define OXS_HREF_RSA_RIPEMD160         "http://www.w3.org/2001/04/xmldsig-more#rsa-ripemd160"

#define OXS_NAME_RSA_SHA1          "rsa-sha1"
#define OXS_HREF_RSA_SHA1          "http://www.w3.org/2000/09/xmldsig#rsa-sha1"

#define OXS_NAME_RSA_SHA224        "rsa-sha224"
#define OXS_HREF_RSA_SHA224        "http://www.w3.org/2001/04/xmldsig-more#rsa-sha224"

#define OXS_NAME_RSA_SHA256        "rsa-sha256"
#define OXS_HREF_RSA_SHA256        "http://www.w3.org/2001/04/xmldsig-more#rsa-sha256"

#define OXS_NAME_RSA_SHA384        "rsa-sha384"
#define OXS_HREF_RSA_SHA384        "http://www.w3.org/2001/04/xmldsig-more#rsa-sha384"

#define OXS_NAME_RSA_SHA512        "rsa-sha512"
#define OXS_HREF_RSA_SHA512        "http://www.w3.org/2001/04/xmldsig-more#rsa-sha512"

#define OXS_NAME_RSA_PKCS1         "rsa-1_5"
#define OXS_HREF_RSA_PKCS1         "http://www.w3.org/2001/04/xmlenc#rsa-1_5"

#define OXS_NAME_RSA_OAEP          "rsa-oaep-mgf1p"
#define OXS_HREF_RSA_OAEP          "http://www.w3.org/2001/04/xmlenc#rsa-oaep-mgf1p"
#define OXS_NODE_RSA_OAEP_PARAMS        "OAEPparams"


    /****************************************************************
        SHA1 
    ****************************************************************/
#define OXS_NAME_SHA1             "sha1"
#define OXS_HREF_SHA1             "http://www.w3.org/2000/09/xmldsig#sha1"

#define OXS_NAME_SHA224           "sha224"
#define OXS_HREF_SHA224           "http://www.w3.org/2001/04/xmldsig-more#sha224"

#define OXS_NAME_SHA256           "sha256"
#define OXS_HREF_SHA256           "http://www.w3.org/2001/04/xmlenc#sha256"

#define OXS_NAME_SHA384           "sha384"
#define OXS_HREF_SHA384           "http://www.w3.org/2001/04/xmldsig-more#sha384"

#define OXS_NAME_SHA512           "sha512"
#define OXS_HREF_SHA512           "http://www.w3.org/2001/04/xmlenc#sha512"

    /****************************************************************
        X509 
    ****************************************************************/
#define OXS_NAME_X509_DATA         "x509"
#define OXS_NODE_X509_DATA         "X509Data"
#define OXS_HREF_X509_DATA         "http://www.w3.org/2000/09/xmldsig#X509Data"

#define OXS_NODE_X509_CERTIFICATE      "X509Certificate"
#define OXS_NODE_X509_CRL          "X509CRL"
#define OXS_NODE_X509_SUBJECT_NAME      "X509SubjectName"
#define OXS_NODE_X509_ISSUER_SERIAL     "X509IssuerSerial"
#define OXS_NODE_X509_ISSUER_NAME       "X509IssuerName"
#define OXS_NODE_X509_SERIAL_NUMBER     "X509SerialNumber"
#define OXS_NODE_X509_SKI          "X509SKI"

#define OXS_NAME_RAW_X509_CERT          "raw-x509-cert"
#define OXS_HREF_RAW_X509_CERT          "http://www.w3.org/2000/09/xmldsig#rawX509Certificate"

#define OXS_NAME_X509_STORE        "x509-store"

    /****************************************************************
        SOAP 1.1/1.2
    ****************************************************************/
#define OXS_NODE_ENVELOPE         "Envelope"
#define OXS_NODE_HEADER           "Header"
#define OXS_NODE_BODY                 "Body"
#define OXS_NODE_FAULT                "Fault"
#define OXS_NODE_FAULT_CODE        "faultcode"
#define OXS_NODE_FAULT_STRING              "faultstring"
#define OXS_NODE_FAULT_ACTOR               "faultactor"
#define OXS_NODE_FAULT_DETAIL              "detail"
#define OXS_NODE_CODE             "Code"
#define OXS_NODE_REASON           "Reason"
#define OXS_NODE_NODE             "Node"
#define OXS_NODE_ROLE             "Role"
#define OXS_NODE_DETAIL           "Detail"
#define OXS_NODE_VALUE            "Value"
#define OXS_NODE_SUBCODE          "Subcode"
#define OXS_NODE_TEXT             "Text"


#define OXS_SOAP_FAULT_CODE_VERSION_MISMATCH     "VersionMismatch"
#define OXS_SOAP_FAULT_CODE_MUST_UNDERSTAND      "MustUnderstand"
#define OXS_SOAP_FAULT_CODE_CLIENT          "Client"
#define OXS_SOAP_FAULT_CODE_SERVER          "Server"
#define OXS_SOAP_FAULT_CODE_RECEIVER        "Receiver"
#define OXS_SOAP_FAULT_CODE_SENDER          "Sender"
#define OXS_SOAP_FAULT_DATA_ENCODNING_UNKNOWN    "DataEncodingUnknown"

    /****************************************************************
        Ext
    ****************************************************************/
#define OXS_ENCODING_BASE64BINARY "http://docs.oasis-open.org/wss/2004/01/oasis-200401-wss-soap-message-security-1.0#Base64Binary"
#define OXS_VALUE_X509V3 "http://docs.oasis-open.org/wss/2004/01/oasis-200401-wss-x509-token-profile-1.0#X509v3"
#define OXS_X509_SUBJ_KI "http://docs.oasis-open.org/wss/2004/01/oasis-200401-wss-x509-token-profile-1.0#X509SubjectKeyIdentifier"

    /****************************************************************
        ST References
    ****************************************************************/
#define OXS_STR_DIRECT_REFERENCE "DirectReference"
#define OXS_STR_KEY_IDENTIFIER  OXS_NODE_KEY_IDENTIFIER
#define OXS_STR_EMBEDDED        OXS_NODE_EMBEDDED
#define OXS_STR_ISSUER_SERIAL "IssuerSerial"
#define OXS_STR_THUMB_PRINT "ThumbPrint"
#define OXS_STR_EXTERNAL_URI "ExternalUri"
#define OXS_STR_ENCRYPTED_KEY "Encryptedkey"

    /*************************************************************************/



#ifdef __cplusplus
}
#endif

#endif /* OXS_CONSTANTS_H*/
