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
#include <OMNode.h>
#include <Environment.h>
#include <OMElement.h>
#include <typeinfo>
using namespace std;
using namespace wso2wsf;

OMNode::OMNode()
{
    _wsf_axiom_node = NULL;
}

OMNode::~OMNode()
{
    freeTree();
}

void OMNode::setAxiomNode(axiom_node_t * node)
{
    _wsf_axiom_node = node;
}

axiom_node_t * OMNode::getAxiomNode()
{
    return _wsf_axiom_node;
}

string OMNode::toString()
{
	/** Delete the allocated xml string returned from axiom_node_to_string method */
	char *xml = axiom_node_to_string(_wsf_axiom_node, Environment::getEnv());
	if(xml)
	{
		string str = xml;
		AXIS2_FREE(Environment::getEnv()->allocator, xml);
		return str;
	}
	return "";
}

string OMNode::subTreeToString()
{
	/** Delete the allocated xml string returned from axiom_node_sub_tree_to_string method */
	char *xml = axiom_node_sub_tree_to_string(_wsf_axiom_node, Environment::getEnv());
	if(xml)
	{
		string str = xml;
		AXIS2_FREE(Environment::getEnv()->allocator, xml);
		return str; 
	}
	return "";
}

void OMNode::freeTree()
{
    if (!_wsf_axiom_node)
    {
        return;
    }
    axiom_node_free_tree(_wsf_axiom_node, Environment::getEnv());
    _wsf_axiom_node = NULL;
}

bool OMNode::insertSiblingAfter(OMNode * to_insert)
{
    axis2_status_t status = axiom_node_insert_sibling_after(
        _wsf_axiom_node, Environment::getEnv(), to_insert->_wsf_axiom_node);
    return (status == AXIS2_SUCCESS);
}

bool OMNode::insertSiblingBefore(OMNode * to_insert)
{
    axis2_status_t status = axiom_node_insert_sibling_before(
        _wsf_axiom_node, Environment::getEnv(), to_insert->_wsf_axiom_node);
    return (status == AXIS2_SUCCESS);
}

bool OMNode::isComplete()
{
    axis2_bool_t complete = axiom_node_is_complete(_wsf_axiom_node, Environment::getEnv());
    if (complete)
    {
        return true;
    }
    return false;
}

OMNode * OMNode::detach()
{
	axiom_node_t * node = NULL;
	if (getAxiomNode())
	{
		node = axiom_node_detach(getAxiomNode(), Environment::getEnv());
	}
	if (!node)
	{
		return NULL;
	}
	else
	{
		setAxiomNode(node);
		OMElement * dp = dynamic_cast<OMElement *>(_parent);
		if(dp)
		{
			dp->removeChildLocal(this);
			dp = NULL;
		}
		
		return this;
	}
}

/**
* get parent of node.
* @return pointer to parent node of node, return NULL if no parent exists or
* when an error occurred.
*/
OMNode *OMNode::getParent()
{
	return _parent;
}

/**
* get the previous sibling.
* @return a pointer to previous sibling , NULL if a previous sibling does not exits
* (happens when this node is the first child of a node).
*/
OMNode * OMNode::getPreviousSibling()
{
	OMElement * dp;
	dp = dynamic_cast<OMElement *>(_parent);
	if(!dp)
	{
		return NULL;
	}
	std::vector<OMNode *> children = dp->getChildren();
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

/**
* get next sibling.
* @return next sibling of this node.
*/
OMNode * OMNode::getNextSibling()
{
	OMElement * dp;
	dp = dynamic_cast<OMElement *>(_parent);
	if(!dp)
	{
		return NULL;
	}
	std::vector<OMNode *> children = dp->getChildren();
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

void OMNode::setParent(OMNode *parent)
{
	if(!parent)
		return;

	if(this->_parent == parent)
	{
		return;
	}
	else if(this->_parent)
	{
		detach();
	}
	this->_parent = parent;
	return;
}

