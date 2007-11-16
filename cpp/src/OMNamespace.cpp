/*
 * Copyright 2005,2006 WSO2, Inc. http://wso2.com
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
#include <OMAttribute.h>
using namespace std;
using namespace wso2wsf;

/** @brief getAxiomNamespace
  *
  * @todo: document this function
  */
axiom_namespace_t * OMNamespace::getAxiomNamespace()
{
    return _wsf_axiom_namespace;
}

/** @brief OMNamespace
  *
  * @todo: document this function
  */
 OMNamespace::OMNamespace(std::string uri, std::string prefix)
{
    _wsf_axiom_namespace = axiom_namespace_create(getEnv(), uri.c_str(), prefix.c_str());
}

/** @brief OMNamespace
  *
  * @todo: document this function
  */
 OMNamespace::OMNamespace(OMNamespace & ns)
{
    OMNamespace(ns.getURI(), ns.getPrefix());
}

/** @brief ~OMNamespace
  *
  * @todo: document this function
  */
 OMNamespace::~OMNamespace()
{
    if (_wsf_axiom_namespace)
    {
        axiom_namespace_free(_wsf_axiom_namespace, getEnv());
    }
}

/** @brief ~OMNamespace
  *
  * @todo: document this function
  */
void OMNamespace::setAxiomNamespace(axiom_namespace_t * ns)
{
    _wsf_axiom_namespace = ns;
}

/** @brief equals
  *
  * @todo: document this function
  */
bool OMNamespace::equals(OMNamespace * ns)
{
    return ((ns->getURI() == getURI()) && (ns->getPrefix() == getPrefix()));
}

/** @brief getURI
  *
  * @todo: document this function
  */
string OMNamespace::getURI()
{
    return axiom_namespace_get_uri(_wsf_axiom_namespace, getEnv());
}

/** @brief getPrefix
  *
  * @todo: document this function
  */
string OMNamespace::getPrefix()
{
    return axiom_namespace_get_prefix(_wsf_axiom_namespace, getEnv());
}

/** @brief toString
  *
  * @todo: document this function
  */
string OMNamespace::toString()
{
    return axiom_namespace_to_string(_wsf_axiom_namespace, getEnv());
}

