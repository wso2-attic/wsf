/*
 * Copyright 2005,2009 WSO2, Inc. http://wso2.com
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
    return axiom_node_to_string(_wsf_axiom_node, getEnv());
}

string OMNode::subTreeToString()
{
    return axiom_node_sub_tree_to_string(_wsf_axiom_node, getEnv());
}

void OMNode::freeTree()
{
    if (!_wsf_axiom_node)
    {
        return;
    }
    axiom_node_free_tree(_wsf_axiom_node, getEnv());
    _wsf_axiom_node = NULL;
}

bool OMNode::insertSiblingAfter(OMNode * to_insert)
{
    axis2_status_t status = axiom_node_insert_sibling_after(
        _wsf_axiom_node, getEnv(), to_insert->_wsf_axiom_node);
    return (status == AXIS2_SUCCESS);
}

bool OMNode::insertSiblingBefore(OMNode * to_insert)
{
    axis2_status_t status = axiom_node_insert_sibling_before(
        _wsf_axiom_node, getEnv(), to_insert->_wsf_axiom_node);
    return (status == AXIS2_SUCCESS);
}

bool OMNode::isComplete()
{
    axis2_bool_t complete = axiom_node_is_complete(_wsf_axiom_node, getEnv());
    if (complete)
    {
        return true;
    }
    return false;
}
