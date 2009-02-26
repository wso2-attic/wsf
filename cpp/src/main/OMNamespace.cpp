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

OMNamespace::OMNamespace(std::string uri, std::string prefix)
{
    _wsf_axiom_namespace = axiom_namespace_create(getEnv(), uri.c_str(), prefix.c_str());
}

OMNamespace::OMNamespace(OMNamespace & ns)
{
    _wsf_axiom_namespace = axiom_namespace_create(
        getEnv(), (ns.getURI()).c_str(), (ns.getPrefix()).c_str());
}

OMNamespace::~OMNamespace()
{
    if (_wsf_axiom_namespace)
    {
        axiom_namespace_free(_wsf_axiom_namespace, getEnv());
    }
}

void OMNamespace::setAxiomNamespace(axiom_namespace_t * ns)
{
    if (_wsf_axiom_namespace)
    {
        axiom_namespace_free(_wsf_axiom_namespace, getEnv());
    }
    _wsf_axiom_namespace = ns;
}

bool OMNamespace::equals(OMNamespace * ns)
{
    return ((ns->getURI() == getURI()) && (ns->getPrefix() == getPrefix()));
}

string OMNamespace::getURI()
{
    return axiom_namespace_get_uri(_wsf_axiom_namespace, getEnv());
}

string OMNamespace::getPrefix()
{
    return axiom_namespace_get_prefix(_wsf_axiom_namespace, getEnv());
}

string OMNamespace::toString()
{
    return axiom_namespace_to_string(_wsf_axiom_namespace, getEnv());
}

