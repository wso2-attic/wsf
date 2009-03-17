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

#include <PasswordCallback.h>
using namespace std;
using namespace wso2wsf;

class PWCB: public PasswordCallback
{
public:
    WSF_CALL PWCB();
    WSF_CALL ~PWCB();
    string WSF_CALL getPassword(string& username);
    string WSF_CALL getPKCS12Password(string& username);
};

WSF_PASSWORD_CALLBACK_INIT(PWCB);

PWCB::PWCB()
{
    //you can write any construction logic
}

PWCB::~PWCB()
{
    //you can write any destruction logic
}

string PWCB::getPassword(string& username)
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

string PWCB::getPKCS12Password(string& username)
{
    string pw;
	if(username == "a")
	{
		pw = "a12345";
	}
	else if(username == "b")
	{
		pw = "b12345";
	}
	return pw;
}

