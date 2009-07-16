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

axiom_attribute_t * OMAttribute::getAxiomAttribute()
{
    return _wsf_axiom_attribute;
}

OMAttribute::OMAttribute(std::string name, std::string value, OMNamespace * ns)
{
    _namespace = NULL;
    
    if (!ns)
    {
        _wsf_axiom_attribute = axiom_attribute_create(Environment::getEnv(), name.c_str(), value.c_str(), NULL);
    }
    else
    {
        _wsf_axiom_attribute = axiom_attribute_create(Environment::getEnv(), name.c_str(), value.c_str(), ns->getAxiomNamespace());
        if (_wsf_axiom_attribute)
        {
            _namespace = ns;
        }
    }
}

OMAttribute::OMAttribute(std::string name, std::string value)
{
    _namespace = NULL;

    _wsf_axiom_attribute = axiom_attribute_create(Environment::getEnv(), name.c_str(), value.c_str(), NULL);
}

OMAttribute::OMAttribute(OMAttribute & attribute)
{
    _wsf_axiom_attribute = axiom_attribute_create(Environment::getEnv(), (attribute.getName()).c_str(),
        (attribute.getValue()).c_str(), (attribute.getNamespace())->getAxiomNamespace());
    _namespace = new OMNamespace(*attribute.getNamespace());
}

OMAttribute::~OMAttribute()
{
    if (_wsf_axiom_attribute)
    {
        axiom_attribute_free(_wsf_axiom_attribute, Environment::getEnv());
        if (_namespace)
        {
            delete _namespace;
        }
    }
    else if (_namespace)
    {
		_namespace->setAxiomNamespace(NULL);
        delete _namespace;
    }
}

void OMAttribute::setAxiomAttribute(axiom_attribute_t * attribute)
{
    _wsf_axiom_attribute = attribute;
}

bool OMAttribute::equals(OMAttribute * attribute)
{
    bool is_same_attribute = 
        ((attribute->getName() == getName()) && (attribute->getValue() == getValue()));
    bool is_same_namespace = false;
    
    if(attribute->_namespace == _namespace)
    {
        /* pointer values are equal */
        is_same_namespace = true;
    }
    else
    {
        if((attribute->_namespace) && (_namespace))
        {
            /* they are not null, so can check whether content is equal */
            is_same_namespace = _namespace->equals(attribute->_namespace);
        }
        else
        {
            /* one is NULL */
            is_same_namespace = false;
         }
    }
    return is_same_attribute && is_same_namespace;
}

string OMAttribute::getValue()
{
    return axiom_attribute_get_value(_wsf_axiom_attribute, Environment::getEnv());
}

string OMAttribute::getName()
{
    return axiom_attribute_get_localname(_wsf_axiom_attribute, Environment::getEnv());
}

OMNamespace * OMAttribute::getNamespace()
{
    return _namespace;
}

void OMAttribute::setValue(std::string value)
{
    axiom_attribute_set_value(_wsf_axiom_attribute, Environment::getEnv(), value.c_str());
}

string OMAttribute::toString()
{
    axutil_qname_t * qname =
        axiom_attribute_get_qname(_wsf_axiom_attribute, Environment::getEnv());
    return axutil_qname_to_string(qname, Environment::getEnv());
}

