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
#include <OMElement.h>
#include <OMText.h>
#include <typeinfo>
using namespace std;
using namespace wso2wsf;

bool OMText::setContentId(std::string content_id)
{
    axis2_status_t status =
        axiom_text_set_content_id(_wsf_axiom_text, Environment::getEnv(), content_id.c_str());
    return (status == AXIS2_SUCCESS);
}

string OMText::getContentId()
{
    return axiom_text_get_content_id(_wsf_axiom_text, Environment::getEnv());
}

OMDataHandler * OMText::getDataHandler()
{
    if (_data_handler != NULL)
    {
        return _data_handler;
    }
    axiom_data_handler_t * data_handler_c = axiom_text_get_data_handler(_wsf_axiom_text, Environment::getEnv());
    _data_handler = new OMDataHandler();
    _data_handler->setAxiomDataHandler(data_handler_c);
    return _data_handler;
}

void OMText::isBinary(bool is_binary)
{
    axiom_text_set_is_binary(_wsf_axiom_text, Environment::getEnv(), is_binary ? AXIS2_TRUE : AXIS2_FALSE);
}

void OMText::optimize(bool optimize)
{
    axiom_text_set_optimize(_wsf_axiom_text, Environment::getEnv(), optimize ? AXIS2_TRUE : AXIS2_FALSE);
}

string OMText::getText()
{
	const axis2_char_t *textvalue = axiom_text_get_text(_wsf_axiom_text, Environment::getEnv());
	if(textvalue)
		return textvalue;
	return "";
}

string OMText::getValue()
{
    const axis2_char_t *value =  axiom_text_get_value(_wsf_axiom_text, Environment::getEnv());
	if(value)
		return value;
	return "";
}

bool OMText::setValue(std::string value)
{
    axis2_status_t status =
        axiom_text_set_value(_wsf_axiom_text, Environment::getEnv(), value.c_str());
    return (status == AXIS2_SUCCESS);
}

OMText::~OMText()
{
    if (_data_handler)
    {
        _data_handler->setAxiomDataHandler(NULL);
        delete _data_handler;
    }
}

OMText::OMText(OMNode * parent, axiom_node_t * node)
{
    _wsf_axiom_text = NULL;
    _data_handler = NULL;
    _parent = NULL;

    if (node && (axiom_node_get_node_type(node, Environment::getEnv()) == AXIOM_TEXT))
    {
        _wsf_axiom_text = (axiom_text_t *)axiom_node_get_data_element(node, Environment::getEnv());
    }
    if (_wsf_axiom_text)
    {
        setAxiomNode(node);
        _parent = parent;
        if (_parent != NULL)
        {
            try
            {
                OMElement * dp = dynamic_cast<OMElement *>(_parent);
                dp->addChildLocal(this);
            }
            catch(bad_cast)
            {}
        }
    }
}

OMText::OMText()
{
    axiom_node_t * node;
    
    _data_handler = NULL;
    _parent = NULL;
    _wsf_axiom_text = axiom_text_create(Environment::getEnv(), NULL, NULL, &node);
    if (_wsf_axiom_text)
    {
        setAxiomNode(node);
        _parent = NULL;
    }
}

OMText::OMText(OMDataHandler * data_handler)
{
    axiom_node_t * node;
    axiom_data_handler_t * data_handler_c = NULL;

    _data_handler = NULL;
    _parent = NULL;
    if (data_handler != NULL)
    {
        data_handler_c = data_handler->getAxiomDataHandler();
    }
    _wsf_axiom_text = axiom_text_create_with_data_handler(Environment::getEnv(), NULL, data_handler_c, &node);
    if (_wsf_axiom_text)
    {
        setAxiomNode(node);
        _parent = NULL;
    }
}

OMText::OMText(OMNode * parent, OMDataHandler * data_handler)
{
    axiom_node_t * node;
    axiom_node_t * parent_c = NULL;
    axiom_data_handler_t * data_handler_c = NULL;

    _data_handler = NULL;
    _parent = NULL;
    if (parent != NULL)
    {
        parent_c = parent->getAxiomNode();
    }
    if (data_handler != NULL)
    {
        data_handler_c = data_handler->getAxiomDataHandler();
    }
    _wsf_axiom_text = axiom_text_create_with_data_handler(Environment::getEnv(), parent_c, data_handler_c, &node);
    if (_wsf_axiom_text)
    {
        setAxiomNode(node);
        _parent = parent;
        if (_parent != NULL)
        {
           OMElement * dp = dynamic_cast<OMElement *>(_parent);
		   if(dp)
		   {
                dp->addChildLocal(this);
            }
        }
    }
}

OMText::OMText(std::string value)
{
    axiom_node_t * node;

    _data_handler = NULL;
    _parent = NULL;
    if (value == "")
    {
        _wsf_axiom_text = axiom_text_create(Environment::getEnv(), NULL, NULL, &node);
    }
    else
    {
        _wsf_axiom_text = axiom_text_create(Environment::getEnv(), NULL, value.c_str(), &node);
    }
    if (_wsf_axiom_text)
    {
        setAxiomNode(node);
        _parent = NULL;
    }
}

OMText::OMText(OMNode * parent, std::string value)
{
    axiom_node_t * node;
    axiom_node_t * parent_c = NULL;

    _data_handler = NULL;
    _parent = NULL;
    if (parent != NULL)
    {
        parent_c = parent->getAxiomNode();
    }
    if (value == "")
    {
        _wsf_axiom_text = axiom_text_create(Environment::getEnv(), parent_c, NULL, &node);
    }
    else
    {
        _wsf_axiom_text = axiom_text_create(Environment::getEnv(), parent_c, value.c_str(), &node);
    }
    if (_wsf_axiom_text)
    {
        setAxiomNode(node);
        _parent = parent;
        if (_parent != NULL)
        {
			OMElement * dp = dynamic_cast<OMElement *>(_parent);
			if(dp)
			{
                dp->addChildLocal(this);
            }
        }
    }
}

axiom_types_t OMText::nodeType()
{
    return AXIOM_TEXT;
}

