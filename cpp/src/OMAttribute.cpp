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

/** @brief getAxiomAttribute
  *
  * @todo: document this function
  */
axiom_attribute_t * OMAttribute::getAxiomAttribute()
{
    return _wsf_axiom_attribute;
}

/** @brief OMAttribute
  *
  * @todo: document this function
  */
 OMAttribute::OMAttribute(std::string name, std::string value, OMNamespace * ns) throw (OMException)
{
    _namespace = NULL;
    
    if (!ns)
    {
        _wsf_axiom_attribute = axiom_attribute_create(getEnv(), name.c_str(), value.c_str(), NULL);
    }
    else
    {
        _wsf_axiom_attribute = axiom_attribute_create(getEnv(), name.c_str(), value.c_str(), ns->getAxiomNamespace());
        if (_wsf_axiom_attribute)
        {
            _namespace = ns;
        }
    }
    if (!_wsf_axiom_attribute)
    {
        throw &OMException("Unable to create OMAttribute object", this);
    }
}

/** @brief OMAttribute
  *
  * @todo: document this function
  */
 OMAttribute::OMAttribute(std::string name, std::string value) throw (OMException)
{
    _namespace = NULL;

    _wsf_axiom_attribute = axiom_attribute_create(getEnv(), name.c_str(), value.c_str(), NULL);
    if (!_wsf_axiom_attribute)
    {
        throw &OMException("Unable to create OMAttribute object", this);
    }
}

/** @brief OMAttribute
  *
  * @todo: document this function
  */
 OMAttribute::OMAttribute(OMAttribute & attribute) throw (OMException)
{
    _namespace = NULL;

    _wsf_axiom_attribute = axiom_attribute_create(getEnv(), (attribute.getName()).c_str(),
        (attribute.getValue()).c_str(), (attribute.getNamespace())->getAxiomNamespace());
    if (!_wsf_axiom_attribute)
    {
        throw &OMException("Unable to create OMAttribute object", this);
    }
}

/** @brief ~OMAttribute
  *
  * @todo: document this function
  */
 OMAttribute::~OMAttribute()
{
    if (_wsf_axiom_attribute)
    {
        axiom_attribute_free(_wsf_axiom_attribute, getEnv());
        if (_namespace)
        {
            _namespace->setAxiomNamespace(NULL);
            delete _namespace;
        }
    }
    else if (_namespace)
    {
        delete _namespace;
    }
}

/** @brief ~OMAttribute
  *
  * @todo: document this function
  */
void OMAttribute::setAxiomAttribute(axiom_attribute_t * attribute)
{
    _wsf_axiom_attribute = attribute;
}

/** @brief equals
  *
  * @todo: document this function
  */
bool OMAttribute::equals(OMAttribute * attribute)
{
    return ((attribute->getName() == getName()) && (attribute->getValue() == getValue())
        && (attribute->getNamespace() == getNamespace()));
}

/** @brief getValue
  *
  * @todo: document this function
  */
string OMAttribute::getValue()
{
    return axiom_attribute_get_value(_wsf_axiom_attribute, getEnv());
}

/** @brief getName
  *
  * @todo: document this function
  */
string OMAttribute::getName()
{
    return axiom_attribute_get_localname(_wsf_axiom_attribute, getEnv());
}

/** @brief getNamespace
  *
  * @todo: document this function
  */
OMNamespace * OMAttribute::getNamespace()
{
    return _namespace;
}

/** @brief setValue
  *
  * @todo: document this function
  */
void OMAttribute::setValue(std::string value)
{
    axiom_attribute_set_value(_wsf_axiom_attribute, getEnv(), value.c_str());
}

/** @brief toString
  *
  * @todo: document this function
  */
string OMAttribute::toString()
{
    axutil_qname_t * qname =
        axiom_attribute_get_qname(_wsf_axiom_attribute, getEnv());
    return axutil_qname_to_string(qname, getEnv());
}

