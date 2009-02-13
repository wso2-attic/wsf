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
#include <WSFError.h>
#include <OMElement.h>
#include <OMText.h>
#include <typeinfo>
using namespace std;
using namespace wso2wsf;

/** @brief getNextSibling
  *
  * @todo: document this function
  */
OMNode * OMText::getPreviousSibling()
{
    OMElement * dp;
    try
    {
        dp = dynamic_cast<OMElement *>(_parent);
    }
    catch(bad_cast)
    {
        return NULL;
    }
    std::vector<OMNode *> children = dp->getChilderen();
    if (children.size() <= 1)
    {
        return NULL;
    }
    vector<OMNode *>::iterator i = children.begin();
    while((*i) != this)
    {
        if (i == children.end())
        {
            return NULL;
        }
        i++;
    }
    return *(i - 1);
}

/** @brief getPreviousSibling
  *jruby
  * @todo: document this function
  */
OMNode * OMText::getNextSibling()
{
    OMElement * dp;
    try
    {
        dp = dynamic_cast<OMElement *>(_parent);
    }
    catch(bad_cast)
    {
        return NULL;
    }
    std::vector<OMNode *> children = dp->getChilderen();
    if (children.size() <= 0)
    {
        return NULL;
    }
    vector<OMNode *>::iterator i = children.end() - 1;
    while((*i) != this)
    {
        if (i == children.begin())
        {
            return NULL;
        }
        i--;
    }
    return *(i + 1);
}

/** @brief getParent
  *
  * @todo: document this function
  */
OMNode * OMText::getParent()
{
    return _parent;
}

/** @brief detach
  *
  * @todo: document this function
  */
OMNode * OMText::detach()
{
    axiom_node_t * node = NULL;
    if (getAxiomNode())
    {
        node = axiom_node_detach(getAxiomNode(), getEnv());
    }
    if (!node)
    {
        return NULL;
    }
    else
    {
        setAxiomNode(node);
        try
        {
            OMElement * dp = dynamic_cast<OMElement *>(_parent);
            dp->removeChildLocal(this);
            dp = NULL;
        }
        catch(bad_cast)
        {}
        return this;
    }
}

/** @brief setContentId
  *
  * @todo: document this function
  */
bool OMText::setContentId(std::string content_id)
{
    axis2_status_t status =
        axiom_text_set_content_id(_wsf_axiom_text, getEnv(), content_id.c_str());
    return (status == AXIS2_SUCCESS);
}

/** @brief getContentId
  *
  * @todo: document this function
  */
string OMText::getContentId()
{
    return axiom_text_get_content_id(_wsf_axiom_text, getEnv());
}

/** @brief getDataHandler
  *
  * @todo: document this function
  */
OMDataHandler * OMText::getDataHandler()
{
    if (_data_handler != NULL)
    {
        return _data_handler;
    }
    axiom_data_handler_t * data_handler_c = axiom_text_get_data_handler(_wsf_axiom_text, getEnv());
    _data_handler = new OMDataHandler();
    _data_handler->setAxiomDataHandler(data_handler_c);
    return _data_handler;
}

/** @brief isBinary
  *
  * @todo: document this function
  */
void OMText::isBinary(bool is_binary)
{
    axiom_text_set_is_binary(_wsf_axiom_text, getEnv(), is_binary ? AXIS2_TRUE : AXIS2_FALSE);
}

/** @brief optimize
  *
  * @todo: document this function
  */
void OMText::optimize(bool optimize)
{
    axiom_text_set_optimize(_wsf_axiom_text, getEnv(), optimize ? AXIS2_TRUE : AXIS2_FALSE);
}

/** @brief getText
  *
  * @todo: document this function
  */
string OMText::getText()
{
    return axiom_text_get_text(_wsf_axiom_text, getEnv());
}

/** @brief getValue
  *
  * @todo: document this function
  */
string OMText::getValue()
{
    return axiom_text_get_value(_wsf_axiom_text, getEnv());
}

/** @brief setValue
  *
  * @todo: document this function
  */
bool OMText::setValue(std::string value)
{
    axis2_status_t status =
        axiom_text_set_value(_wsf_axiom_text, getEnv(), value.c_str());
    return (status == AXIS2_SUCCESS);
}

/** @brief ~OMText
  *
  * @todo: document this function
  */
 OMText::~OMText()
{
    if (_data_handler)
    {
        _data_handler->setAxiomDataHandler(NULL);
        delete _data_handler;
    }
}

/** @brief OMText
  *
  * @todo: document this function
  */
 OMText::OMText(OMNode * parent, axiom_node_t * node) throw (OMException)
{
    _wsf_axiom_text = NULL;
    _data_handler = NULL;
    _parent = NULL;

    if (node && (axiom_node_get_node_type(node, getEnv()) == AXIOM_TEXT))
    {
        _wsf_axiom_text = (axiom_text_t *)axiom_node_get_data_element(node, getEnv());
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
    else
    {
        throw OMException(CREATION_OF_OM_TEXT_OBJECT_FAILED);
    }
}

/** @brief OMText
  *
  * @todo: document this function
  */
 OMText::OMText() throw (OMException)
{
    axiom_node_t * node;
    
    _data_handler = NULL;
    _parent = NULL;
    _wsf_axiom_text = axiom_text_create(getEnv(), NULL, NULL, &node);
    if (_wsf_axiom_text)
    {
        setAxiomNode(node);
        _parent = NULL;
    }
    else
    {
        throw OMException(CREATION_OF_OM_TEXT_OBJECT_FAILED);
    }
}

/** @brief OMText
  *
  * @todo: document this function
  */
 OMText::OMText(OMDataHandler * data_handler) throw (OMException)
{
    axiom_node_t * node;
    axiom_data_handler_t * data_handler_c = NULL;

    _data_handler = NULL;
    _parent = NULL;
    if (data_handler != NULL)
    {
        data_handler_c = data_handler->getAxiomDataHandler();
    }
    _wsf_axiom_text = axiom_text_create_with_data_handler(getEnv(), NULL, data_handler_c, &node);
    if (_wsf_axiom_text)
    {
        setAxiomNode(node);
        _parent = NULL;
    }
    else
    {
        throw OMException(CREATION_OF_OM_TEXT_OBJECT_FAILED);
    }
}

/** @brief OMText
  *
  * @todo: document this function
  */
 OMText::OMText(OMNode * parent, OMDataHandler * data_handler) throw (OMException)
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
    _wsf_axiom_text = axiom_text_create_with_data_handler(getEnv(), parent_c, data_handler_c, &node);
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
    else
    {
        throw OMException(CREATION_OF_OM_TEXT_OBJECT_FAILED);
    }
}

/** @brief OMText
  *
  * @todo: document this function
  */
 OMText::OMText(std::string value) throw (OMException)
{
    axiom_node_t * node;

    _data_handler = NULL;
    _parent = NULL;
    if (value == "")
    {
        _wsf_axiom_text = axiom_text_create(getEnv(), NULL, NULL, &node);
    }
    else
    {
        _wsf_axiom_text = axiom_text_create(getEnv(), NULL, value.c_str(), &node);
    }
    if (_wsf_axiom_text)
    {
        setAxiomNode(node);
        _parent = NULL;
    }
    else
    {
        throw OMException(CREATION_OF_OM_TEXT_OBJECT_FAILED);
    }
}

/** @brief OMText
  *
  * @todo: document this function
  */
 OMText::OMText(OMNode * parent, std::string value) throw (OMException)
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
        _wsf_axiom_text = axiom_text_create(getEnv(), parent_c, NULL, &node);
    }
    else
    {
        _wsf_axiom_text = axiom_text_create(getEnv(), parent_c, value.c_str(), &node);
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
    else
    {
        throw OMException(CREATION_OF_OM_TEXT_OBJECT_FAILED);
    }
}

/** @brief nodeType
  *
  * @todo: document this function
  */
axiom_types_t OMText::nodeType()
{
    return AXIOM_TEXT;
}

