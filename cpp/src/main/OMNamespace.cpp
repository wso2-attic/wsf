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
#include <WSFError.h>
#include <OMAttribute.h>
using namespace std;
using namespace wso2wsf;

axiom_namespace_t * OMNamespace::getAxiomNamespace()
{
    return _wsf_axiom_namespace;
}

OMNamespace::OMNamespace(std::string str_uri)
{
    const axis2_char_t *uri = NULL;
    if(str_uri != "")
    {
        uri = str_uri.c_str();
    }
	_wsf_axiom_namespace = axiom_namespace_create(Environment::getEnv(), uri , NULL);
	_refcounter = 0;
}


OMNamespace::OMNamespace(std::string str_uri, std::string str_prefix)
{
    const axis2_char_t *uri = NULL;
    if(str_uri != "")
    {
        uri = str_uri.c_str();
    }
    const axis2_char_t *prefix = NULL;
    if(str_prefix != "")
    {
        prefix = str_prefix.c_str();
    }
    _wsf_axiom_namespace = axiom_namespace_create(Environment::getEnv(), uri, prefix);
	_refcounter = 0;
}

OMNamespace::OMNamespace(OMNamespace & ns)
{
    const axis2_char_t *uri = axiom_namespace_get_uri(
        ns._wsf_axiom_namespace, Environment::getEnv());
    const axis2_char_t *prefix = axiom_namespace_get_prefix(
        ns._wsf_axiom_namespace, Environment::getEnv());
    _wsf_axiom_namespace = axiom_namespace_create(Environment::getEnv(), uri, prefix);
	_refcounter = 0;
}

OMNamespace::OMNamespace(axiom_namespace_t *ns)
{
	_wsf_axiom_namespace = ns;
	_refcounter = 0;
}

OMNamespace::~OMNamespace()
{
    if (_wsf_axiom_namespace)
    {
        axiom_namespace_free(_wsf_axiom_namespace, Environment::getEnv());
    }
}

void OMNamespace::setAxiomNamespace(axiom_namespace_t * ns)
{
    _wsf_axiom_namespace = ns;
}

bool OMNamespace::equals(OMNamespace * ns)
{
    return ((ns->getURI() == getURI()) && (ns->getPrefix() == getPrefix()));
}

string OMNamespace::getURI()
{
    axis2_char_t *value = axiom_namespace_get_uri(_wsf_axiom_namespace, Environment::getEnv());
    if(value)
    {
        return value;
    }
    else
    {
        return "";
    }
}

string OMNamespace::getPrefix()
{
    axis2_char_t *value = axiom_namespace_get_prefix(_wsf_axiom_namespace, Environment::getEnv());
    if(value)
    {
        return value;
    }
    else
    {
        return "";
    }
}

string OMNamespace::toString()
{
    axis2_char_t *value = axiom_namespace_to_string(_wsf_axiom_namespace, Environment::getEnv());
    if(value)
    {
        return value;
    }
    else
    {
        return "";
    }
}

int OMNamespace::incrementRef()
{
	return ++_refcounter;
}

int OMNamespace::decrementRef()
{
	return --_refcounter;
}

