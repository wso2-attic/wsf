/*
 * Copyright 2005-2009 WSO2, Inc. http://wso2.com
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

#include <stdio.h>
#include <Qname.h>
using namespace std;
using namespace wso2wsf;

/** @brief getScope
  *
  * @todo: document this function
  */
std::string Qname::getLocalPart()
{
    return axutil_qname_get_localpart(_qname, getEnv());
}

/** @brief getValue
  *
  * @todo: document this function
  */
std::string Qname::getNamespaceURI()
{
    return axutil_qname_get_uri(_qname, getEnv());
}

/** @brief getName
  *
  * @todo: document this function
  */
std::string Qname::getPrefix()
{
    return axutil_qname_get_prefix(_qname,getEnv());
}

/** @brief 
  *
  * @todo: document this function
  */
Qname::Qname(axutil_qname_t *qname)
{
	_qname = qname;
}

Qname::Qname(std::string localPart)
{
	_qname = axutil_qname_create(getEnv(), localPart.c_str(), NULL, NULL);
}

/** @brief 
  *
  * @todo: document this function
  */
Qname::Qname(std::string localpart, std::string namespaceURI, std::string prefix)
{
	_qname = axutil_qname_create(getEnv(), localpart.c_str(), namespaceURI.c_str() , prefix.c_str());
}

Qname::Qname(std::string localpart, std::string namespaceURI)
{
	_qname = axutil_qname_create(getEnv(), localpart.c_str(), namespaceURI.c_str(), NULL);
}

bool Qname::equals(Qname *qnameToTest)
{
	if(axutil_qname_equals(_qname, getEnv(), qnameToTest->_qname))
		return true;
	else	return false; 

}


axutil_qname_t* Qname::getQname()
{
	return _qname;
}

