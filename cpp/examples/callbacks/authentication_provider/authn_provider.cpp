/*
 * Copyright 2005,2009 WSO2, Inc. http://wso2.com
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <AuthenticationProvider.h>
#include <rampart_crypto_util.h>

using namespace std;
using namespace wso2wsf;

class AuthnProvider: public AuthenticationProvider
{
public:
    WSF_CALL AuthnProvider();
    WSF_CALL ~AuthnProvider();
    
    bool WSF_CALL checkPassword(string& username, string& password, MessageContext* msgctx);
    bool WSF_CALL checkDigestPassword(
        string& username, string& nonce, string& created, string& digest, MessageContext* msgctx);

private:
    string& WSF_CALL getPassword(string& username);
};

WSF_AUTHENTICATION_PROVIDER_INIT(AuthnProvider);

AuthnProvider::AuthnProvider()
{
    //you can write any construction logic
}

AuthnProvider::~AuthnProvider()
{
    //you can write any destruction logic
}

string& AuthnProvider::getPassword(string& username)
{
    string pw;

    if(username == "Raigama")
    {
        pw = "RaigamaPW" ;
    }
    else if(username == "Gampola")
    {
        pw = "GampolaPW";
    }
    else if(username == "alice")
    {
        pw = "password";
    }
    else if(username == "bob")
    {
        pw = "bobPW";
    }
    else if(username == "Bob")
    {
        pw = "boB";
    }
    else if(username == "Alice")
    {
        pw = "abcd!1234";
        /*pw = "ecilA";*/
    }
    /*These are for sample keystores*/
    else if(username == "a")
    {
        pw = "a12345";
    }
    else if(username == "b")
    {
        pw = "b12345";
    }
    else if(username == "x")
    {
        pw = "x12345";
    }
    else if(username == "abcd")
    {
        pw = "dcba";
    }
    else if(username == "y")
    {
        pw = "y12345";
    }
    else
    {
        /*Append 12345 for any name not specified above*/
        pw = username + "12345";
    }
    return pw;
}

bool AuthnProvider::checkPassword(std::string& username, std::string& password, MessageContext* msgctx)
{
    string local_pw = getPassword(username);
    return (local_pw == password);
}
bool AuthnProvider::checkDigestPassword(
    string& username, string& nonce, string& created, string& digest, MessageContext* msgctx)
{
    string local_pw = getPassword(username);
    string local_digest = rampart_crypto_sha1(
        Environment::getEnv(), nonce.c_str(), created.c_str(), local_pw.c_str());
    return (local_digest == digest);
}

