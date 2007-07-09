/*
 * Copyright 2004,2005 The Apache Software Foundation.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
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

#ifndef RP_DEFINES_H
#define RP_DEFINES_H

/** @defgroup rp_defines
 * @ingroup rp_defines
 * @{
 */
#ifdef __cplusplus
extern "C"
{
#endif

#define RP_POLICY "Policy"
#define RP_EXACTLY_ONE "ExactlyOne"
#define RP_ALL "All"

#define RP_TOKEN_USERNAME 1
#define RP_TOKEN_X509 2
#define RP_TOKEN_SECURITY_CONTEXT 3
#define RP_TOKEN_HTTPS 4

#define RP_BINDING_SYMMETRIC 5
#define RP_BINDING_ASYMMETRIC 6
#define RP_BINDING_TRANSPORT 7

#define RP_SUPPORTING_SIGNED_SUPPORTING 8
#define RP_SUPPORTING_SIGNED_ENDORSING_SUPPORTING 9
#define RP_SUPPORTING_SUPPORTING 10
#define RP_SUPPORTING_ENDORSING_SUPPORTING 11

#define RP_WSS_WSS10 12
#define RP_WSS_WSS11 13

#define RP_SUPPORTING_TOKEN 14

#define RP_SYMMETRIC_BINDING "SymmetricBinding"
#define RP_ASYMMETRIC_BINDING "AsymmetricBinding"
#define RP_TRANSPORT_BINDING "TransportBinding"

#define RP_SIGNED_SUPPORTING_TOKENS "SignedSupportingTokens"
#define RP_SIGNED_ENDORSING_SUPPORTING_TOKENS "SignedEndorsingSupportingTokens"
#define RP_SUPPORTING_TOKENS "SupportingTokens"
#define RP_ENDORSING_SUPPORTING_TOKENS "EndorsingSupportingTokens"

#define RP_SIGNED_PARTS "SignedParts"
#define RP_SIGNED_ELEMENTS "SignedElements"
#define RP_ENCRYPTED_PARTS "EncryptedParts"
#define RP_ENCRYPTED_ELEMENTS "EncryptedElements"
#define RP_SIGNED_ITEMS "SignedItems"
#define RP_ENCRYPTED_ITEMS "EncryptedItems"    

#define RP_BODY "Body"
#define RP_HEADER "Header"
#define RP_NAME "Name"
#define RP_NAMESPACE "Namespace"
#define RP_ELEMENT "Element"    

#define RP_XPATH "XPath"
#define RP_XPATH_VERSION "XPathVersion"

#define RP_WSS10 "Wss10"
#define RP_WSS11 "Wss11"

#define RP_MUST_SUPPORT_REF_KEY_IDENTIFIER "MustSupportRefKeyIdentifier"
#define RP_MUST_SUPPORT_REF_ISSUER_SERIAL "MustSupportRefIssuerSerial"
#define RP_MUST_SUPPORT_REF_EXTERNAL_URI "MustSupportRefExternalURI"
#define RP_MUST_SUPPORT_REF_EMBEDDED_TOKEN "MustSupportRefEmbeddedToken"
#define RP_MUST_SUPPORT_REF_THUMBPRINT "MustSupportRefThumbprint"
#define RP_MUST_SUPPORT_REF_ENCRYPTED_KEY "MustSupportRefEncryptedkey"
#define RP_REQUIRE_SIGNATURE_CONFIRMATION "RequireSignatureConfirmation"

#define RP_PROTECTION_TOKEN "ProtectionToken"
#define RP_ENCRYPTION_TOKEN "EncryptionToken"
#define RP_SIGNATURE_TOKEN "SignatureToken"
#define RP_INITIATOR_TOKEN "InitiatorToken"
#define RP_RECIPIENT_TOKEN "RecipientToken"
#define RP_TRANSPORT_TOKEN "TransportToken"

#define RP_ALGORITHM_SUITE "AlgorithmSuite"
#define RP_LAYOUT "Layout"
#define RP_INCLUDE_TIMESTAMP "IncludeTimestamp"
#define RP_ENCRYPT_BEFORE_SIGNING "EncryptBeforeSigning"
#define RP_SIGN_BEFORE_ENCRYPTING "SignBeforeEncrypting"
#define RP_ENCRYPT_SIGNATURE "EncryptSignature"
#define RP_PROTECT_TOKENS "ProtectTokens"
#define RP_ONLY_SIGN_ENTIRE_HEADERS_AND_BODY "OnlySignEntireHeadersAndBody"

#define RP_ALGO_SUITE_BASIC256 "Basic256"
#define RP_ALGO_SUITE_BASIC192 "Basic192"
#define RP_ALGO_SUITE_BASIC128 "Basic128"
#define RP_ALGO_SUITE_TRIPLE_DES "TripleDes"
#define RP_ALGO_SUITE_BASIC256_RSA15 "Basic256Rsa15"
#define RP_ALGO_SUITE_BASIC192_RSA15 "Basic192Rsa15"
#define RP_ALGO_SUITE_BASIC128_RSA15 "Basic128Rsa15"
#define RP_ALGO_SUITE_TRIPLE_DES_RSA15 "TripleDesRsa15"
#define RP_ALGO_SUITE_BASIC256_SHA256 "Basic256Sha256"
#define RP_ALGO_SUITE_BASIC192_SHA256 "Basic192Sha256"
#define RP_ALGO_SUITE_BASIC128_SHA256 "Basic128Sha256"
#define RP_ALGO_SUITE_TRIPLE_DES_SHA256 "TripleDesSha256"
#define RP_ALGO_SUITE_BASIC256_SHA256_RSA15 "Basic256Sha256Rsa15"
#define RP_ALGO_SUITE_BASIC192_SHA256_RSA15 "Basic192Sha256Rsa15"
#define RP_ALGO_SUITE_BASIC128_SHA256_RSA15 "Basic128Sha256Rsa15"
#define RP_ALGO_SUITE_TRIPLE_DES_SHA256_RSA15 "TripleDesSha256Rsa15"

#define RP_HMAC_SHA1 "http://www.w3.org/2000/09/xmldsig#hmac-sha1"
#define RP_RSA_SHA1 "http://www.w3.org/2000/09/xmldsig#rsa-sha1"
#define RP_SHA1 "http://www.w3.org/2000/09/xmldsig#sha1"
#define RP_SHA256 "http://www.w3.org/2001/04/xmlenc#sha256"
#define RP_SHA512 "http://www.w3.org/2001/04/xmlenc#sha512"
#define RP_AES128 "http://www.w3.org/2001/04/xmlenc#aes128-cbc"
#define RP_AES192 "http://www.w3.org/2001/04/xmlenc#aes192-cbc"
#define RP_AES256 "http://www.w3.org/2001/04/xmlenc#aes256-cbc"
#define RP_TRIPLE_DES "http://www.w3.org/2001/04/xmlenc#tripledes-cbc"
#define RP_KW_AES128 "http://www.w3.org/2001/04/xmlenc#kw-aes256"
#define RP_KW_AES192 "http://www.w3.org/2001/04/xmlenc#kw-aes192"
#define RP_KW_AES256 "http://www.w3.org/2001/04/xmlenc#kw-aes128"
#define RP_KW_TRIPLE_DES "http://www.w3.org/2001/04/xmlenc#kw-tripledes"
#define RP_KW_RSA_OAEP "http://www.w3.org/2001/04/xmlenc#rsa-oaep-mgf1p"
#define RP_KW_RSA15 "http://www.w3.org/2001/04/xmlenc#rsa-1_5"
#define RP_P_SHA1 "http://schemas.xmlsoap.org/ws/2005/02/sc/dk/p_sha1"
#define RP_P_SHA1_L128 "http://schemas.xmlsoap.org/ws/2005/02/sc/dk/p_sha1"
#define RP_P_SHA1_L192 "http://schemas.xmlsoap.org/ws/2005/02/sc/dk/p_sha1"
#define RP_P_SHA1_L256  "http://schemas.xmlsoap.org/ws/2005/02/sc/dk/p_sha1"
#define RP_X_PATH "http://www.w3.org/TR/1999/REC-xpath-19991116"
#define RP_XPATH20 "http://www.w3.org/2002/06/xmldsig-filter2"
#define RP_C14N "http://www.w3.org/2001/10/xml-c14n#"
#define RP_EX_C14N "http://www.w3.org/2001/10/xml-exc-c14n#"
#define RP_SNT "http://www.w3.org/TR/soap12-n11n"
#define RP_STRT10 "http://docs.oasis-open.org/wss/2004/01/oasis-200401-wss-soap-message-security-1.0#STR-Transform"
#define RP_INCLUSIVE_C14N "InclusiveC14N"
#define RP_SOAP_NORMALIZATION_10 "SoapNormalization10"
#define RP_STR_TRANSFORM_10 "STRTransform10"
#define RP_XPATH10 "XPath10"
#define RP_XPATH_FILTER20 "XPathFilter20"

#define RP_LAYOUT_STRICT "Strict"
#define RP_LAYOUT_LAX "Lax"
#define RP_LAYOUT_LAX_TIMESTAMP_FIRST "LaxTimestampFirst"
#define RP_LAYOUT_LAX_TIMESTAMP_LAST "LaxTimestampLast"

#define RP_USERNAME_TOKEN "UsernameToken"
#define RP_X509_TOKEN "X509Token"
#define RP_SECURITY_CONTEXT_TOKEN "SecurityContextToken"
#define RP_HTTPS_TOKEN "HttpsToken"

#define RP_INCLUDE_TOKEN "IncludeToken"
#define RP_INCLUDE_ALWAYS "http://schemas.xmlsoap.org/ws/2005/07/securitypolicy/IncludeToken/Always"
#define RP_INCLUDE_NEVER "http://schemas.xmlsoap.org/ws/2005/07/securitypolicy/IncludeToken/Never"
#define RP_INCLUDE_ONCE "http://schemas.xmlsoap.org/ws/2005/07/securitypolicy/IncludeToken/Once"
#define RP_INCLUDE_ALWAYS_TO_RECIPIENT "http://schemas.xmlsoap.org/ws/2005/07/securitypolicy/IncludeToken/AlwaysToRecipient"

#define RP_REQUIRE_KEY_IDENTIFIRE_REFERENCE "RequireKeyIdentifireReference"
#define RP_REQUIRE_ISSUER_SERIAL_REFERENCE "RequireIssuerSerialReference"
#define RP_REQUIRE_EMBEDDED_TOKEN_REFERENCE "RequireEmbeddedTokenReference"
#define RP_REQUIRE_THUMBPRINT_REFERENCE "RequireThumbprintReference"
#define RP_REQUIRE_DERIVED_KEYS "RequireDerivedKeys"
#define RP_WSS_X509_V1_TOKEN_10 "WssX509V1Token10"
#define RP_WSS_X509_V3_TOKEN_10 "WssX509V3Token10"
#define RP_WSS_X509_PKCS7_TOKEN_10 "WssX509Pkcs7Token10"
#define RP_WSS_X509_PKI_PATH_V1_TOKEN_10 "WssX509PkiPathV1Token10"
#define RP_WSS_X509_V1_TOKEN_11 "WssX509V1Token11"
#define RP_WSS_X509_V3_TOKEN_11 "WssX509V3Token11"
#define RP_WSS_X509_PKCS7_TOKEN_11 "WssX509Pkcs7Token11"
#define RP_WSS_X509_PKI_PATH_V1_TOKEN_11 "WssX509PkiPathV1Token11"

#define RP_WSS_USERNAME_TOKEN_10 "WssUsernameToken10"
#define RP_WSS_USERNAME_TOKEN_11 "WssUsernameToken11"

#define RP_REQUIRE_EXTERNAL_URI_REFERENCE "RequireExternalUriReference"
#define RP_SC10_SECURITY_CONTEXT_TOKEN "SC10SecurityContextToken"

#define RP_REQUIRE_CLIENT_CERTIFICATE "RequireClientCertificate"

#define RP_RAMPART_CONFIG "RampartConfig"
#define RP_USER "User"
#define RP_ENCRYPTION_USER "EncryptionUser"
#define RP_PASSWORD_CALLBACK_CLASS "PasswordCallbackClass"
#define RP_AUTHN_MODULE_NAME "AuthnModuleName"
#define RP_PASSWORD_TYPE "PasswordType"
#define RP_PLAINTEXT "plainText"
#define RP_DIGEST "Digest"
#define RP_RECEIVER_CERTIFICATE "ReceiverCertificate"
#define RP_CERTIFICATE "Certificate"
#define RP_PRIVATE_KEY "PrivateKey"
#define RP_TIME_TO_LIVE "TimeToLive"
#define RP_RD "ReplayDetection"    

#define RP_SP_NS "http://schemas.xmlsoap.org/ws/2005/07/securitypolicy"
#define RP_SECURITY_NS "http://docs.oasis-open.org/wss/2004/01/oasis-200401-wss-wssecurity-secext-1.0.xsd"
#define RP_POLICY_NS "http://schemas.xmlsoap.org/ws/2004/09/policy"
#define RP_RAMPART_NS "http://ws.apache.org/rampart/c/policy"
#define RP_POLICY_PREFIX "wsp"
#define RP_RAMPART_PREFIX "rampc"
#define RP_SP_PREFIX "sp"

#ifdef __cplusplus
}
#endif
#endif
