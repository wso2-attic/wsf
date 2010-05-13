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
#include <Environment.h>
#include <OMText.h>
#include <typeinfo>
using namespace std;
using namespace wso2wsf;

void OMElement::init(OMNode * parent, std::string localname, OMNamespace * ns)
{
    axiom_node_t * node;
    axiom_node_t * parent_c = NULL;
    axiom_namespace_t * ns_c = NULL;
    _default_namespace = NULL;
    _namespace = NULL;
    _parent = NULL;
    if(parent)
    {
        parent_c = parent->getAxiomNode();
    }

    if(ns)
    {
        ns_c = ns->getAxiomNamespace();
    }
    
    _wsf_axiom_element = axiom_element_create(Environment::getEnv(), parent_c, localname.c_str(), ns_c, &node);
    
    if(_wsf_axiom_element)
    {
        setAxiomNode(node);
        _parent = parent;
        if(_parent)
        {
                OMElement * dp = dynamic_cast<OMElement *>(_parent);
				if(dp)
				{
                dp->addChildLocal(this);
				}
				else
				{
					std::cout<<"Casting failed for parent"<<std::endl;
				}
        }
        _namespace = ns;
    }
}

OMElement::OMElement(std::string localname)
{
    init(NULL, localname, NULL);
}

OMElement::OMElement(std::string localname, OMNamespace * ns)
{
    init(NULL, localname, ns);
}

OMElement::OMElement(OMNode * parent, std::string localname)
{
    init(parent, localname, NULL);
}

OMElement::OMElement(OMNode * parent, std::string localname, OMNamespace * ns)
{
    init(parent, localname, ns);
}

OMElement::OMElement(OMNode * parent, axiom_node_t * node)
{
    _default_namespace = NULL;
    _wsf_axiom_element = NULL;
    _namespace = NULL;
    _parent = NULL;

    if (node && (axiom_node_get_node_type(node, Environment::getEnv()) == AXIOM_ELEMENT))
    {
        _wsf_axiom_element = (axiom_element_t *)axiom_node_get_data_element(node, Environment::getEnv());
    }
    if (_wsf_axiom_element)
    {
        setAxiomNode(node);
        _parent = parent;
        if (_parent)
        {
            OMElement * dp = dynamic_cast<OMElement *>(_parent);
			if(dp)
			{
                dp->addChildLocal(this);
			}
        }
        axiom_namespace_t * ns = axiom_element_get_namespace(_wsf_axiom_element, Environment::getEnv(), node);
        if (ns)
        {
            _namespace = new OMNamespace(ns);
        }
    }

    //Go through the children node and add them as child. 
    axiom_node_t * node_new = NULL;
    axiom_children_iterator_t * children_iterator = NULL;
    children_iterator = axiom_element_get_children(_wsf_axiom_element, Environment::getEnv(), getAxiomNode());
    if (children_iterator)
    {
        while (axiom_children_iterator_has_next(children_iterator, Environment::getEnv()))
        {
            node_new = axiom_children_iterator_next(children_iterator, Environment::getEnv());
            if(!node_new)
            {
                continue;
            }

            //we need to add only AXIOM_ELEMENT and AXIOM_TEXT
            if (axiom_node_get_node_type(node_new, Environment::getEnv()) == AXIOM_ELEMENT)
            {
                axiom_element_t * element = (axiom_element_t *)axiom_node_get_data_element(node_new, Environment::getEnv());
                if(!element)
                {
                    continue;
                }
                OMElement* element_cpp = new OMElement(this, node_new);
            }
            else if (axiom_node_get_node_type(node_new, Environment::getEnv()) == AXIOM_TEXT)
            {
                axiom_text_t * text = (axiom_text_t *)axiom_node_get_data_element(node_new, Environment::getEnv());
                if(!text)
                {
                    continue;
                }
                OMText * text_cpp = new OMText(this, node_new);
            }
        }
    }
}

OMElement::~OMElement()
{
    for(vector<OMAttribute *>::iterator ite = _added_attributes.begin(); 
        ite != _added_attributes.end(); ++ite)
    {
       (*ite)->setAxiomAttribute(NULL);
        delete *ite;
    }
    _added_attributes.clear();
   
    if (_default_namespace)
    {
        _default_namespace->setAxiomNamespace(NULL);
        delete _default_namespace;
    }
    if (_namespace)
    {
		//_namespace->setAxiomNamespace(NULL);
		//delete _namespace;
    }
   for (vector<OMNamespace *>::iterator ite = _added_namespaces.begin();
            ite != _added_namespaces.end(); ++ite)
    {
        (*ite)->setAxiomNamespace(NULL);
        delete *ite;
    }
    _added_namespaces.clear();

	if (_child_nodes.size() > 0)
	{
		for (vector<OMNode *>::iterator i = _child_nodes.begin();
			i < _child_nodes.end(); i++)
		{
			(*i)->setAxiomNode(NULL);
			delete (*i);
		}
		_child_nodes.clear();
	}
}

OMNamespace * OMElement::findNamespace(std::string uri, std::string prefix)
{
    axiom_namespace_t * ns =axiom_element_find_namespace(
        _wsf_axiom_element, Environment::getEnv(), getAxiomNode(), uri.c_str(), prefix.c_str());
    if(!ns)
    {
        return NULL;
    }
    for (vector<OMNamespace *>::iterator i = _added_namespaces.begin();
        i != _added_namespaces.end(); ++i)
    {
        /* Compare Prefix first as it is generally smaller in size */
        if ((strcmp((*i)->getPrefix().c_str(), prefix.c_str()) == 0)
            && (strcmp((*i)->getURI().c_str(), uri.c_str()) == 0))
        {
            return *i;
        }
    }
    OMNamespace * ns_cpp = new OMNamespace(uri, prefix);
    _added_namespaces.push_back(ns_cpp);
    return ns_cpp;
}

OMAttribute * OMElement::getAttribute(std::string name, OMNamespace * ns)
{
    for (vector<OMAttribute *>::iterator i = _added_attributes.begin();
        i < _added_attributes.end(); i++)
    {
        /* Compare ns first as it is smaller in size */
        if (((*i)->getNamespace()->getURI() == ns->getURI())
            && ((*i)->getName() == name))
        {
            return *i;
        }
    }

    axutil_qname_t * qn = NULL;
    if (ns)
    {
        const axis2_char_t *uri = NULL;
        const axis2_char_t *prefix = NULL;
        string str_uri = ns->getURI();
        if(str_uri != "")
        {
            uri = str_uri.c_str();
        }
        string str_prefix = ns->getPrefix();
        if(str_prefix != "")
        {
            prefix = str_prefix.c_str();
        }
        qn = axutil_qname_create(Environment::getEnv(), name.c_str(), uri, prefix);
    }
    else
    {
        qn = axutil_qname_create(Environment::getEnv(), name.c_str(), NULL, NULL);
    }
    axiom_attribute_t * at = axiom_element_get_attribute(_wsf_axiom_element, Environment::getEnv(), qn);
    axutil_qname_free(qn, Environment::getEnv());
    if (!at)
    {
        return NULL;
    }

    OMAttribute * at_cpp = new OMAttribute(name, axiom_attribute_get_value(at, Environment::getEnv()), ns);
    _added_attributes.push_back(at_cpp);
    return at_cpp;
}

OMAttribute * OMElement::getAttribute(std::string name)
{
    return getAttribute(name, NULL);
}

bool OMElement::addAttribute(OMAttribute * attribute)
{
    axis2_status_t status = axiom_element_add_attribute(_wsf_axiom_element, Environment::getEnv(),
        attribute->getAxiomAttribute(), getAxiomNode());
    if (status == AXIS2_SUCCESS)
    {
        _added_attributes.push_back(attribute);
        return true;
    }
    return false;
}

bool OMElement::declareDefaultNamespace(std::string uri)
{
    axiom_namespace_t * ns = axiom_namespace_create(Environment::getEnv(), const_cast<char *>(uri.c_str()), NULL);
    axiom_element_declare_namespace(_wsf_axiom_element, Environment::getEnv(), getAxiomNode(), ns);
    if (ns)
    {
        if (_default_namespace)
        {
            _default_namespace->setAxiomNamespace(NULL);
            delete _default_namespace;
        }
        _default_namespace = new OMNamespace(uri, "");
		axiom_namespace_free(ns, Environment::getEnv());
        return true;
    }
    return false;
}



axiom_types_t OMElement::nodeType()
{
    return AXIOM_ELEMENT;
}


OMNode * OMElement::getLastChild()
{
    if (_child_nodes.size() <= 0)
    {
        return NULL;
    }
    return *(_child_nodes.end() - 1);
}

OMElement * OMElement::getFirstElement()
{
    for (vector<OMNode *>::iterator i = _child_nodes.begin();
        i < _child_nodes.end(); i++)
    {
        OMElement * dp = dynamic_cast<OMElement *>(*i);
		if(dp)
		{
			return dp;
		}
    }
    return NULL;
}

OMNode * OMElement::getFirstChild()
{
    if (_child_nodes.size() <= 0)
    {
        return NULL;
    }
    return *_child_nodes.begin();
}

OMNamespace * OMElement::getNamespace()
{
    /*if (is_default)
    {
        axiom_namespace_t * ns =
            axiom_element_get_default_namespace(_wsf_axiom_element, Environment::getEnv(), getAxiomNode());
        if (!ns)
        {
            return NULL;
        }
        if (!_default_namespace)
        {
            _default_namespace = new OMNamespace(axiom_namespace_get_uri(ns, Environment::getEnv()),
                axiom_namespace_get_prefix(ns, Environment::getEnv()));
        }
        return _default_namespace;
    }
    if (_namespace)
    {
        return _namespace;
    }*/
    axiom_namespace_t * ns =
        axiom_element_get_namespace(_wsf_axiom_element, Environment::getEnv(), getAxiomNode());
    if(!ns)
    {
        return NULL;
    }
    _namespace = new OMNamespace(ns);
    return _namespace;
}

OMNamespace * OMElement::getNamespaceLocal(bool is_default)
{
    if (is_default)
    {
        return _default_namespace;
    }
    return _namespace;
}

bool OMElement::setNamespace(OMNamespace * ns)
{
    axis2_status_t status = AXIS2_FAILURE;
    /*if (no_find)
    {
        status = axiom_element_set_namespace_with_no_find_in_current_scope(
            _wsf_axiom_element, Environment::getEnv(), ns->getAxiomNamespace());
        if (status == AXIS2_SUCCESS)
        {
            _namespace = ns;
            return true;
        }
    }
    else
    {
        status = axiom_element_declare_namespace(
            _wsf_axiom_element, Environment::getEnv(), getAxiomNode(), ns->getAxiomNamespace());
    }*/
	status = axiom_element_declare_namespace(
		_wsf_axiom_element, Environment::getEnv(), getAxiomNode(), ns->getAxiomNamespace());
    if (status == AXIS2_SUCCESS)
    {
        _added_namespaces.push_back(ns);
        return true;
    }
    return false;
}

void OMElement::freeTree()
{
    if (getParent())
    {
        detach();
    }
	/** If this element has its axiom node set, free it. 
		This will completely free the underlying C Axiom Structure for the entire tree.
		Therefore before removing the C++ Nodes, all of their axiom nodes must be set to NULL*/
	if(getAxiomNode())
	{
		axiom_node_free_tree(getAxiomNode(), Environment::getEnv());
		setAxiomNode(NULL);
	}
    if (_child_nodes.size() <= 0)
    {
        return;
    }

	for (vector<OMNode *>::iterator i = _child_nodes.begin();
		i < _child_nodes.end(); i++)
	{
		(*i)->setAxiomNode(NULL);
		delete (*i);
	}
	_child_nodes.clear();
}

bool OMElement::insertSiblingAfter(OMNode * to_insert)
{
    for (vector<OMNode *>::iterator i = _child_nodes.begin();
        i < _child_nodes.end(); i++)
    {
        if ((*i) == this)
        {
            _child_nodes.insert(i + 1, to_insert);
			OMNode::insertSiblingAfter(to_insert);
            return true;
        }
    }
    return false;
}

bool OMElement::insertSiblingBefore(OMNode * to_insert)
{
    for (vector<OMNode *>::iterator i = _child_nodes.begin();
        i < _child_nodes.end(); i++)
    {
        if ((*i) == this)
        {
            _child_nodes.insert(i, to_insert);
			OMNode::insertSiblingBefore(to_insert);
			return true;
        }
    }
	
	return false;
}

/*bool OMElement::build()
{
    axis2_status_t status =
        axiom_element_build(_wsf_axiom_element, Environment::getEnv(), getAxiomNode());
    return (status == AXIS2_SUCCESS);
}*/

OMElement * OMElement::getChildElement(std::string localname, OMNamespace * ns)
{
    for (vector<OMNode *>::iterator i = _child_nodes.begin();
        i < _child_nodes.end(); i++)
    {
        OMElement * dp = dynamic_cast<OMElement *>(*i);
        if (dp && dp->getLocalname() == localname)
        {
            OMNamespace *existing_ns = dp->getNamespace();
            string str_existing_ns;
            string str_ns;
            if(existing_ns)
            {
                str_existing_ns = existing_ns->getURI();
            }
            if(ns)
            {
                str_ns = ns->getURI();
            }
            if(str_existing_ns == str_ns)
            {
                return dp;
            }
        }
    }
    return NULL;
}



bool OMElement::addChild(OMNode * child)
{
    for (vector<OMNode *>::iterator i = _child_nodes.begin();
        i < _child_nodes.end(); i++)
    {
        if ((*i) == child)
        {
            axiom_node_t * node = NULL;
            axiom_children_iterator_t * children_iterator = NULL;
            children_iterator = axiom_element_get_children(_wsf_axiom_element, Environment::getEnv(), getAxiomNode());
            if (children_iterator)
            {
                while (axiom_children_iterator_has_next(children_iterator, Environment::getEnv()))
                {
                    node = axiom_children_iterator_next(children_iterator, Environment::getEnv());
                    if (node == child->getAxiomNode())
                    {
                        return false;
                    }
                }
            }
        }
    }
    axis2_status_t status =
        axiom_node_add_child(getAxiomNode(), Environment::getEnv(), child->getAxiomNode());
    if (status == AXIS2_SUCCESS)
    {
        addChildLocal(child);
        return true;
    }
    return false;
}

bool OMElement::removeChildLocal(OMNode * child)
{
    for (vector<OMNode *>::iterator i = _child_nodes.begin();
        i < _child_nodes.end(); i++)
    {
        if ((*i) == child)
        {
            _child_nodes.erase(i);
            return true;
        }
    }
    return false;
}

void OMElement::addChildLocal(OMNode * child)
{
	child->setParent(this);
    _child_nodes.push_back(child);
}

string OMElement::getText()
{
    axis2_char_t *text = axiom_element_get_text(
        _wsf_axiom_element, Environment::getEnv(), getAxiomNode());
    if(text)
    {
        return text;
    }
    else
    {
        return "";
    }
}

bool OMElement::setText(std::string text)
{
    axis2_status_t status =
        axiom_element_set_text(_wsf_axiom_element, Environment::getEnv(), text.c_str(), getAxiomNode());
    return (status == AXIS2_SUCCESS);
}

string OMElement::getLocalname()
{
	axis2_char_t *localname = axiom_element_get_localname(_wsf_axiom_element, Environment::getEnv());
	if(localname)
		return localname;
	return "";
}

/*bool OMElement::removeAttribute(OMAttribute * attribute)
{
    for (vector<OMAttribute *>::iterator i = _added_attributes.begin();
        i < _added_attributes.end(); i++)
    {
        if ((*i) == attribute)
        {
            axis2_status_t status = axiom_element_remove_attribute(_wsf_axiom_element, Environment::getEnv(),
                attribute->getAxiomAttribute());
            if (status == AXIS2_SUCCESS)
            {
                (*i)->setAxiomAttribute(NULL);
                delete *i;
                _added_attributes.erase(i);
                return true;
            }
            return false;
        }
    }
    return false;
}*/

string OMElement::getAttributeValue(std::string name, OMNamespace * ns)
{
    return getAttribute(name, ns)->getValue();
}

string OMElement::getAttributeValue(std::string name)
{
    return getAttributeValue(name, NULL);
}

std::vector<OMNode *> OMElement::getChildren()
{
    return _child_nodes;
}

void OMElement::setChildren(std::vector<OMNode *> children)
{
    if (_child_nodes.size() > 0)
    {
        for (vector<OMNode *>::iterator i = _child_nodes.begin();
            i < _child_nodes.end(); i++)
        {
            OMElement * dp = dynamic_cast<OMElement *>(*i);
			if(dp)
			{
                dp->freeTree();
            }
            if(*i)
			{
				(*i)->setAxiomNode(NULL);
				delete (*i);
			}
        }
        _child_nodes.clear();
    }
    _child_nodes = children;
}

OMElement* WSF_CALL OMElement::getOMElementFromString(std::string xmlstring)
{
	if(xmlstring.empty())
		return NULL;

	axiom_node_t *node = axiom_node_create_from_buffer(Environment::getEnv(), (axis2_char_t*)xmlstring.c_str());
	if(!node)
		return NULL;
	return new OMElement(NULL, node);
}
