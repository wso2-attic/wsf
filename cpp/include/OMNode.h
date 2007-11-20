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

#ifndef OMNODE_H
#define OMNODE_H

#include <stdio.h>
#include <AxisObject.h>
#include <axutil_utils.h>
#include <axiom_node.h>
#include <AxisFault.h>
#include <string>

/**
 * @file OMNode.h
 */

/**
 * @brief namespace wso2wsf Namespace of WSO2 Web Services Framework.
 */
namespace wso2wsf
{
    /**
    * @defgroup om_node OM Node
    * @ingroup wso2wsf
    * @{
    */

    /**
     * @brief class OMNode Defines the base interface used by most of the XML object model
     * within Axis. This tree model for XML captures the idea of deferring the construction
     * of child nodes until they are needed. The isComplete function identifies whether or
     * not a particular node has been fully parsed. A node may not be fully parsed, for
     * example, if all of the children of an element have not yet been parsed.
     */
    class OMNode : public AxisObject
    {
        /**
         * Overloaded insertion operator, is used for printing the node onto a console.
         * @param str existing stream.
         * @param node OMNode object.
         * @return a modified output stream is returned.
         */
        friend std::ostream & operator <<(std::ostream & str, OMNode const & node);

        /**
         * Overloaded insertion operator, is used for printing the node onto a console.
         * @param str existing stream.
         * @param node OMNode object.
         * @return a modified output stream is returned.
         */
        friend std::ostream & operator <<(std::ostream & str, OMNode const * node);

    private:
        /**
         * @var _wsf_axiom_node protected variable holds reference for
         * axiom_node struct.
         */
        axiom_node_t * _wsf_axiom_node;

        /**
         * Indicates whether parser has parsed this information item completely or not
         * @param node node struct.
         * @return true if node is completly build
         * false if node is not completed.
         */
        bool isComplete();

    public:
        /**
         * Method to set the reference to the axiom_node struct.
         * @param node axiom_node reference.
         */
        void setAxiomNode(axiom_node_t * node);

        /**
         * Method to get the reference to the axiom_node struct.
         * @return reference to the axiom_node struct.
         */
        axiom_node_t * getAxiomNode();

        /**
         * Creates a node struct.
         */
        OMNode();

        /**
         * desctructor that can be overriden.
         */
        virtual ~OMNode();

        /**
         * Converts this node to a string.
         * @return converted node as string.
         */
        virtual std::string toString();

        /**
         * Frees an om node and all of its children.
         * @param node node to be freed.
         */
        virtual void freeTree();

        /**
         * Inserts a sibling node after the given node.
         * @param to_insert the node to be inserted. Cannot be NULL.
         * @return status of the op, true on success else false.
         */
        virtual bool insertSiblingAfter(OMNode * to_insert);

        /**
         * Inserts a sibling node before the given current node.
         * @param to_insert the node to be inserted. Cannot be NULL.
         * @return status of the op, AXIS2_SUCCESS on success else AXIS2_FAILURE.
         */
        virtual bool insertSiblingBefore(OMNode * to_insert);

        /**
         * Detaches given node from the parent and reset the links.
         * @return a pointer to detached node,returns NULL on error with error
         * code set to environment's error struct.
         */
        virtual OMNode * detach() = 0;

        /**
         * get parent of node.
         * @return pointer to parent node of node, return NULL if no parent exists or
         * when an error occured.
         */
        virtual OMNode * getParent() = 0;

        /**
         * get the previous sibling.
         * @return a pointer to previous sibling , NULL if a previous sibling does not exits
         * (happens when this node is the first child of a node).
         */
        virtual OMNode * getPreviousSibling() = 0;

        /**
         * get next sibling.
         * @return next sibling of this node.
         */
        virtual OMNode * getNextSibling() = 0;

        /**
         * get the node type of this element.
         * Node type can be one of AXIOM_ELEMENT, AXIOM_COMMENT, AXIOM_TEXT
         * AXIOM_DOCTYPE, AXIOM_PROCESSING_INSTRUCTION.
         * @return node type.
         */
        virtual axiom_types_t nodeType() = 0;

        /**
         * Converts sub tree starting from given node to string.
         * @return converted node as string.
         */
        virtual std::string subTreeToString();
    };
    /** @} */

    inline std::ostream & operator <<(std::ostream & str, OMNode const & node)
    {
        return str << const_cast<OMNode &>(node).toString();
    }

    inline std::ostream & operator <<(std::ostream & str, OMNode const * node)
    {
        return str << const_cast<OMNode *>(node)->toString();
    }
}
#endif // OMNODE_H
