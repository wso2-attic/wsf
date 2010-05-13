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

#ifndef OMELEMENT_H
#define OMELEMENT_H

#include <WSFDefines.h>
#include <OMNode.h>
#include <OMNamespace.h>
#include <OMAttribute.h>
#include <axiom_element.h>
#include <string>
#include <vector>

/**
 * @file OMElement.h
 * @brief OMElement reperesents an XML element in Axiom.
 */

/**
 * @brief namespace wso2wsf Namespace of WSO2 Web Services Framework.
 */
namespace wso2wsf
{
    /**
     * @defgroup OMElement  OMElement
     * @ingroup wso2wsf
     * @{
     */

    /**
     * @brief class OMElement A particular kind of node that represents
     * an element infoset information item. An element has a collection of
     * children, attributes, and namespaces. In contrast with DOM, this
     * interface exposes namespaces separately from the attributes.
     */
    class OMElement : public OMNode
    {
    private:
        /**
         * _added_namespaces private variable holds an array of namespaces that were added.
         */
        std::vector<OMNamespace *> _added_namespaces;

        /**
         * _default_namespace private variable holds the reference to the default namespaces that was added.
         */
        OMNamespace * _default_namespace;

        /**
         * _namespace private variable holds the reference to the namespace added in constructor.
         */
        OMNamespace * _namespace;

        /**
         * _added_attributes private variable holds an array of attributes that were added.
         */
        std::vector<OMAttribute *> _added_attributes;

        /**
         * _child_nodes private variable holds an array of child nodes of this element.
         */
        std::vector<OMNode *> _child_nodes;

        /**
         * _wsf_axiom_element private variable holds reference for axiom_element struct.
         */
        axiom_element_t * _wsf_axiom_element;

        /**
         * creates and Initializes om element.
         * @param parent parent element.
         * @param localname local name of the element. cannot be NULL.
         * @param ns namespace of the element. can be NULL.
         */
        void WSF_CALL init(OMNode * parent, std::string localname, OMNamespace * ns);

    public:

		/**
		* Find a namespace in the scope of the document.
		* Start to find from the given node and go up the hierarchy.
		* @param uri namespace uri.
		* @param prefix namespace prefix. can be NULL.
		* @return pointer to the namespace, if found, else NULL. On error, returns
		* NULL and sets error code in environment,s error.
		*/
		OMNamespace * WSF_CALL findNamespace(std::string uri, std::string prefix);

        /**
         * Creates an om element struct.
         * @param localname local name of the element. cannot be empty.
         */
        WSF_EXTERN WSF_CALL OMElement(std::string localname);

        /**
         * Creates an om element struct.
         * @param localname local name of the element. cannot be NULL.
         * @param ns namespace of the element. can be NULL.
         */
        WSF_EXTERN WSF_CALL OMElement(std::string localname, OMNamespace * ns);

        /**
         * Creates an om element struct.
         * @param parent parent element.
         * @param localname local name of the element. cannot be NULL.
         */
        WSF_EXTERN WSF_CALL OMElement(OMNode * parent, std::string localname);
        
        /**
         * Creates an om element struct.
         * @param parent parent element.
         * @param localname local name of the element. cannot be NULL.
         * @param ns namespace of the element. can be NULL.
         */
        WSF_EXTERN WSF_CALL OMElement(OMNode * parent, std::string localname, OMNamespace * ns);

        /**
         * Creates an om element struct.
         * @param parent parent element.
         * @param node node used to build the element. cannot be NULL.
         */
        WSF_EXTERN WSF_CALL OMElement(OMNode * parent, axiom_node_t * node);

		/**
         * destructor that frees resources. Please note that all associated attributes,
         * namespaces, and child nodes will also be removed.
         */
        virtual WSF_CALL ~OMElement();


        /**
         * Removes the given node from parent in C++ Level. child should have a parent
         * and the parent must be this node. If you want to remove a child globally, use
         * the detach method in the child node instead.
         * @param child child node.
         * @return status of the op. true on success else false.
         */
        virtual bool WSF_CALL removeChildLocal(OMNode * child);

        /**
         * Adds given node as child to parent in C++ Level. child should not have a parent
         * if child has a parent it will be detached from existing parent
         * @param child child node.
         * @return status of the op. true on success else false.
         */
        virtual void WSF_CALL addChildLocal(OMNode * child);

        /**
         * Method to retrieve children of this node.
         * @return children of this node.
         */
        WSF_EXTERN virtual std::vector<OMNode *> WSF_CALL getChildren();

        /**
         * Method to set children of this node.
         * @param children child node array.
         * @return children of this node.
         */
        WSF_EXTERN virtual void WSF_CALL setChildren(std::vector<OMNode *> children);

        /**
         * Frees an om node and all of its children.
         */
        WSF_EXTERN void WSF_CALL freeTree();

        /**
         * Inserts a sibling node after the given node.
         * @param to_insert the node to be inserted. Cannot be NULL.
         * @return status of the op, true on success else false.
         */
        WSF_EXTERN bool WSF_CALL insertSiblingAfter(OMNode * to_insert);

        /**
         * Inserts a sibling node before the given current node.
         * @param to_insert the node to be inserted. Cannot be NULL.
         * @return status of the op, AXIS2_SUCCESS on success else AXIS2_FAILURE.
         */
        WSF_EXTERN bool WSF_CALL insertSiblingBefore(OMNode * to_insert);

        /**
         * Declare a namespace in current element (in the scope of this element).
         * It checks to see if it is already declared. 
         * @param ns pointer to the namespace struct to be declared.
         * @return status of the op. true on success else false.
         */
        WSF_EXTERN bool WSF_CALL setNamespace(OMNamespace * ns);

        /**
         * Get the OMNamespace of associated with this element. If the object is not yet built, it will be built and 
         * returned. 
         * @return pointer to Namespace. NULL if there is no namespace.
         */
        WSF_EXTERN OMNamespace* WSF_CALL getNamespace();


        /**
         * Get the existing OMNamespace of om_element. If this is not yet build, NULL will be 
         * returned. The parameter is_default is deprecated and will be dropped in future releases.
         * @param is_default whether the retrieved namespace is default. 
         * @return pointer to Namespace. NULL if there is no namespace.
         * associated with the element.
         */
        WSF_EXTERN OMNamespace * WSF_CALL getNamespaceLocal(bool is_default = false);

        /**
         * declared a default namespace explicitly.
         * @param uri namespace uri of the default namespace.
         * @return the declared namespace.
         */
        WSF_EXTERN bool WSF_CALL declareDefaultNamespace(std::string uri);

        /**
         * Adds an attribute to current element
         * @param attribute attribute to be added.
         * @return status of the op. true on success else false.
         */
        WSF_EXTERN bool WSF_CALL addAttribute(OMAttribute * attribute);

        /**
         * Gets (finds) the attribute with the given name.
         * @param name name of the attribute to be found. should not be NULL.
         * @param ns namespace of the attribute to be found. can be NULL.
         * @return a pointer to the attribute with given name if found, else NULL.
         * On error, returns NULL and sets the error code in environment's error struct.
         */
        WSF_EXTERN OMAttribute * WSF_CALL getAttribute(std::string name, OMNamespace * ns);

        /**
         * Gets (finds) the attribute with the given name and namespace.
         * @param name name of the attribute to be found. should not be NULL.
         * @return a pointer to the attribute with given name if found, else NULL.
         * On error, returns NULL and sets the error code in environment's error struct.
         */
        WSF_EXTERN OMAttribute * WSF_CALL getAttribute(std::string name);

        /**
         * Gets (finds) the attribute value with the given name and namespace.
         * @param name name of the attribute to be found. should not be NULL.
         * @param ns namespace of the attribute to be found. can be NULL.
         * @return the attribute value with given name if found, else NULL.
         */
        WSF_EXTERN std::string WSF_CALL getAttributeValue(std::string name, OMNamespace * ns);

        /**
         * Gets (finds) the attribute value with the given name.
         * @param name name of the attribute to be found. should not be NULL.
         * @return the attribute value with given name if found, else NULL.
         */
        WSF_EXTERN std::string WSF_CALL getAttributeValue(std::string name);

        /*
         * removes an attribute from the element attribute list
         * user must free this attribute, element free function does not free
         * attributes that are not is it's attribute list.
         * @param attribute attribute to be removed.
         * @return true if attribute was found and removed, else false.
         */
        //WSF_EXTERN bool WSF_CALL removeAttribute(OMAttribute * attribute);

        /**
         * returns the localname of this element
         * @return localname of element, returns NULL on error.
         */
        WSF_EXTERN std::string WSF_CALL getLocalname();

        /**
         * Sets the text of the given element.
         * caution - This method will wipe out all the text elements (and hence any
         * mixed content) before setting the text.
         * @param text text to be set.
         * @return true if text was set, else false.
         */
        WSF_EXTERN bool WSF_CALL setText(std::string text);

        /**
         * select all the text children and concatenate them to a single string.
         * @return the contaminated text of all text children text values
         * return null if no text children is available or on error.
         */
        WSF_EXTERN std::string WSF_CALL getText();

        /**
         * Adds given node as child to parent. child should not have a parent
         * if child has a parent it will be detached from existing parent
         * @param child child node.
         * @return status of the op. true on success else false.
         */
        WSF_EXTERN bool WSF_CALL addChild(OMNode * child);

        /**
         * returns the first child om element of this om element node.
         * @return om element if one is available otherwise return NULL.
         */
        WSF_EXTERN OMElement * WSF_CALL getFirstElement();

        /**
         * returns the om_element corresponding to given local name and
         * the namespace.
         * @param localname local name of element.
         * @param ns namespace of element.
         * retrieved element.
         */
        WSF_EXTERN OMElement * WSF_CALL getChildElement(std::string localname, OMNamespace * ns);

        /*
         * builds this om_element_node completely, This is only possible
         * if the om_stax_builder is associated with the om_element_node,
         * @return true if this element node was successfully completed,
         * otherwise returns false.
         */
        //WSF_EXTERN bool WSF_CALL build();

        /**
          * get the first child of node
          * @return pointer to first child node , NULL is returned on error with
          * error code set in environments error
          */
        WSF_EXTERN OMNode * WSF_CALL getFirstChild();

        /**
         * get the last child
         * @return pointer to last child of this node , return NULL on error.
         */
        WSF_EXTERN OMNode * WSF_CALL getLastChild();

        /**
         * get the node type of this element
         * Node type can be one of AXIOM_ELEMENT, AXIOM_COMMENT, AXIOM_TEXT
         * AXIOM_DOCTYPE, AXIOM_PROCESSING_INSTRUCTION
         * @return node type
         */
        WSF_EXTERN axiom_types_t WSF_CALL nodeType();

		static WSF_EXTERN OMElement* WSF_CALL getOMElementFromString(std::string xmlstring);


    };
    /** @} */
}
#endif // OMELEMENT_H
