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

#ifndef OMELEMENT_H
#define OMELEMENT_H

#include <OMNode.h>
#include <OMNamespace.h>
#include <OMAttribute.h>
#include <axiom_element.h>
#include <string>
#include <vector>

/**
 * @brief namespace wso2wsf Namespace of WSO2 Web Services Framework.
 */
namespace wso2wsf
{
    /**
     * @defgroup om_element OM Element
     * @ingroup wso2wsf
     * @{
     */

    /**
     * @brief class OMElement A particular kind of node that represents
     * an element infoset information item. An element has a collection of
     * children, attributes, and namespaces. In contrast with DOM, this
     * interface exposes namespaces separately from the attributes.
     */
    class OMElement: public OMNode
    {
    private:
        /**
         * @var _added_namespaces private variable holds an array of
         * namespaces that were added.
         */
        std::vector<OMNamespace *> _added_namespaces;

        /**
         * @var _default_namespace private variable holds the reference to the
         * default namespaces that was added.
         */
        OMNamespace * _default_namespace;

        /**
         * @var _namespace private variable holds the reference to the
         * namespace added in constructor.
         */
        OMNamespace * _namespace;

        /**
         * @var _added_attributes private variable holds an array of
         * attributes that were added.
         */
        std::vector<OMAttribute *> _added_attributes;

        /**
         * @var _child_nodes private variable holds an array of
         * child nodes of this element.
         */
        std::vector<OMNode *> _child_nodes;

        /**
         * @var _wsf_axiom_node private variable holds reference for
         * axiom_element struct.
         */
        axiom_element_t * _wsf_axiom_element;

        /**
         * @var _parent private variable holds reference to parent element.
         */
        OMNode * _parent;

        /**
         * Find a namespace in the scope of the document.
         * Start to find from the given node and go up the hierarchy.
         * @param uri namespace uri.
         * @param prefix namespace prefix. can be NULL.
         * @return pointer to the namespace, if found, else NULL. On error, returns
         * NULL and sets error code in environment,s error.
         */
        OMNamespace * findNamespace(std::string uri, std::string prefix);

    public:
        /**
         * Removes the given node from parent in C++ Level. child should have a parent
         * and the parent must be this node. If you want to remove a child globally, use
         * the detach method in the child node instead.
         * @param child child node.
         * @return status of the op. true on success else false.
         */
        virtual bool removeChildLocal(OMNode * child);

        /**
         * Adds given node as child to parent in C++ Level. child should not have a parent
         * if child has a parent it will be detached from existing parent
         * @param child child node.
         * @return status of the op. true on success else false.
         */
        virtual void addChildLocal(OMNode * child);

        /**
         * Method to retrieve children of this node.
         * @return childern of this node.
         */
        virtual std::vector<OMNode *> getChilderen();

        /**
         * Method to set children of this node.
         * @param children child node array.
         * @return childern of this node.
         */
        virtual void setChilderen(std::vector<OMNode *> children);

        /**
         * Creates an om element struct.
         * @param parent parent element.
         * @param node node used to build the element. cannot be NULL.
         */
        OMElement(OMNode * parent, axiom_node_t * node);

        /**
         * Creates an om element struct.
         * @param parent parent element.
         * @param localname local name of the elment. cannot be NULL.
         * @param ns namespace of the element. can be NULL.
         */
        OMElement(OMNode * parent, std::string localname, OMNamespace * ns);

        /**
         * Creates an om element struct.
         * @param parent parent element.
         * @param localname local name of the elment. cannot be NULL.
         */
        OMElement(OMNode * parent, std::string localname);

        /**
         * Creates an om element struct.
         * @param localname local name of the elment. cannot be NULL.
         * @param ns namespace of the element. can be NULL.
         */
        OMElement(std::string localname, OMNamespace * ns);

        /**
         * Creates an om element struct.
         * @param localname local name of the elment. cannot be NULL.
         */
        OMElement(std::string localname);

        /**
         * desctructor that frees resources. Please note that all associated attributes,
         * namespaces, and child nodes will also be removed.
         */
        virtual ~OMElement();

        /**
         * Frees an om node and all of its children.
         * @param node node to be freed.
         */
        void freeTree();

        /**
         * Inserts a sibling node after the given node.
         * @param to_insert the node to be inserted. Cannot be NULL.
         * @return status of the op, true on success else false.
         */
        bool insertSiblingAfter(OMNode * to_insert);

        /**
         * Inserts a sibling node before the given current node.
         * @param to_insert the node to be inserted. Cannot be NULL.
         * @return status of the op, AXIS2_SUCCESS on success else AXIS2_FAILURE.
         */
        bool insertSiblingBefore(OMNode * to_insert);

        /**
         * Declare a namespace in current element (in the scope of this element).
         * It checks to see if it is already declared. If no_find is true, this will
         * not search the namespace in the scope nor will declare in the current
         * element, as in set_namespace. This will just assign the given namespace
         * to the element.
         * @param ns pointer to the namespace struct to be declared.
         * @param no_find true for no-find mode.
         * @return satus of the op. true on success else false.
         */
        bool setNamespace(OMNamespace * ns, bool no_find);

        /**
         * get the namespace of om_element.
         * @param is_default whether the retrieved namespace is default.
         * @return pointer to Namespace. NULL if there is no namespace.
         * associated with the element.
         */
        OMNamespace * getNamespace(bool is_default);

        /**
         * declared a default namespace explicitly.
         * @param uri namespace uri of the default namespace.
         * @return the declared namespace.
         */
        bool declareDefaultNamespace(std::string uri);

        /**
         * Adds an attribute to current element
         * @param attribute attribute to be added.
         * @return satus of the op. true on success else false.
         */
        bool addAttribute(OMAttribute * attribute);

        /**
         * Gets (finds) the attribute with the given name.
         * @param name name of the attribute to be found. should not be NULL.
         * @param ns namespace of the attribute to be found. can be NULL.
         * @return a pointer to the attribute with given name if found, else NULL.
         * On error, returns NULL and sets the error code in environment's error struct.
         */
        OMAttribute * getAttribute(std::string name, OMNamespace * ns);

        /**
         * Gets (finds) the attribute with the given name and namespace.
         * @param name name of the attribute to be found. should not be NULL.
         * @param ns namespace of the attribute to be found. can be NULL.
         * @return a pointer to the attribute with given name if found, else NULL.
         * On error, returns NULL and sets the error code in environment's error struct.
         */
        OMAttribute * getAttribute(std::string name);

        /**
         * Gets (finds) the attribute value with the given name and namespace.
         * @param name name of the attribute to be found. should not be NULL.
         * @param ns namespace of the attribute to be found. can be NULL.
         * @return the attribute value with given name if found, else NULL.
         */
        std::string getAttributeValue(std::string name, OMNamespace * ns);

        /**
         * Gets (finds) the attribute value with the given name.
         * @param name name of the attribute to be found. should not be NULL.
         * @param ns namespace of the attribute to be found. can be NULL.
         * @return the attribute value with given name if found, else NULL.
         */
        std::string getAttributeValue(std::string name);

        /**
         * removes an attribute from the element attribute list
         * user must free this attribute, element free function does not free
         * attributes that are not is it's attribute list.
         * @param attribute attribute to be removed.
         * @return true if attribute was found and removed, else false.
         */
        bool removeAttribute(OMAttribute * attribute);

        /**
         * returns the localname of this element
         * @return localname of element, returns NULL on error.
         */
        std::string getLocalname();

        /**
         * Sets the text of the given element.
         * caution - This method will wipe out all the text elements (and hence any
         * mixed content) before setting the text.
         * @param text text to be set.
         * @return true if text was set, else false.
         */
        bool setText(std::string text);

        /**
         * select all the text children and concat them to a single string.
         * @return the contanated text of all text childrens text values
         * return null if no text children is avilable or on error.
         */
        std::string getText();

        /**
         * Adds given node as child to parent. child should not have a parent
         * if child has a parent it will be detached from existing parent
         * @param child child node.
         * @return satus of the op. true on success else false.
         */
        bool addChild(OMNode * child);

        /**
         * returns the first child om element of this om element node.
         * @return om element if one is availble otherwise return NULL.
         */
        OMElement * getFirstElement();

        /**
         * returns the om_element corresponding to given local name and
         * the namespace.
         * @param localname local name of element.
         * @param ns namespace of element.
         * retrieved element.
         */
        OMElement * getChildElement(std::string localname, OMNamespace * ns);

        /**
         * returns the serilized text of this element and its children.
         * @return a string of xml, returns NULL on error.
         */
        std::string toString();

        /**
         * builds this om_element_node completely, This is only possible
         * if the om_stax_builder is associated with the om_element_node,
         * @return true if this element node was successfully completed,
         * otherwise returns false.
         */
        bool build();

        /**
         * Detaches given node from the parent and reset the links
         * @return a pointer to detached node,returns NULL on error with error
         * code set to environment's error struct
         */
        OMNode * detach();

        /** get parent of node
         * @return pointer to parent node of node, return NULL if no parent exists or
         * when an error occured.
         */
        OMNode * getParent();

        /**
          * get the first child of node
          * @return pointer to first child node , NULL is returned on error with
          * error code set in environments error
          */
        OMNode * getFirstChild();

        /**
         * get the last child
         * @return pointer to last child of this node , return NULL on error.
         */
        OMNode * getLastChild();

        /**
         * get the previous sibling
         * @return a pointer to previous sibling , NULL if a previous sibling does not exits
         * (happens when this node is the first child of a node )
         */
        OMNode * getPreviousSibling();

        /**
         * get next sibling
         * @return next sibling of this node.
         */
        OMNode * getNextSibling();

        /**
         * get the node type of this element
         * Node type can be one of AXIOM_ELEMENT, AXIOM_COMMENT, AXIOM_TEXT
         * AXIOM_DOCTYPE, AXIOM_PROCESSING_INSTRUCTION
         * @return node type
         */
        axiom_types_t nodeType();

//        /**
//         * get  the attribute list of the element
//         * @param om_element om element
//         * @param env environment must not be null
//         * @returns axutil_hash poiner to attributes hash
//         * This hash table is read only
//         */
//        AXIS2_EXTERN axutil_hash_t *AXIS2_CALL
//        axiom_element_get_all_attributes(
//            axiom_element_t * om_element,
//            const axutil_env_t * env);

//        /**
//         * get the namespace list of the element
//         * @param om_element om element
//         * @param env environment
//         * @returns axutil_hash pointer to namespaces hash
//         * this hash table is read only
//         */
//        AXIS2_EXTERN axutil_hash_t *AXIS2_CALL
//        axiom_element_get_namespaces(
//            axiom_element_t * om_element,
//            const axutil_env_t * env);

//        /**
//         *@return qname of this element
//         * the returned qname should not be externaly freed
//         * when om_element struct is freed qname is also
//         * freed
//         * @returns axutil_qname_t struct , NULL on failure
//         */
//        AXIS2_EXTERN axutil_qname_t *AXIS2_CALL
//        axiom_element_get_qname(
//            axiom_element_t * om_element,
//            const axutil_env_t * env,
//            axiom_node_t * ele_node);

//        /**
//         *   returns a list of children iterator
//         *   iterators free function must be called by user
//         */
//        AXIS2_EXTERN axiom_children_iterator_t *AXIS2_CALL
//
//        axiom_element_get_children(
//            axiom_element_t * om_element,
//            const axutil_env_t * env,
//            axiom_node_t * element_node);

//        /**
//         *   returns a list of children iterator with qname
//         *   returned iterator is freed when om element struct
//         *  is freed
//         * @param om_element
//         * @param env
//         * @param element_qname
//         * @param element_node
//         * @returns children qname iterator struct
//         */
//
//        AXIS2_EXTERN axiom_children_qname_iterator_t *AXIS2_CALL
//
//        axiom_element_get_children_with_qname(
//            axiom_element_t * om_element,
//            const axutil_env_t * env,
//            axutil_qname_t * element_qname,
//            axiom_node_t * element_node);

//        /**
//         * returns an iterator with child elements of type AXIOM_ELEMENT
//         * iterator is freed when om_element node is freed
//         * @param om_element
//         * @param element_node
//         * @param env enviroment must not be null
//         * @returns axiom_child_element_iterator_t , NULL on error
//         */
//        AXIS2_EXTERN axiom_child_element_iterator_t *AXIS2_CALL
//
//        axiom_element_get_child_elements(
//            axiom_element_t * om_element,
//            const axutil_env_t * env,
//            axiom_node_t * element_node);



//        /**
//         *  Extract attributes , returns a clones hash table of attributes,
//         *  if attributes are associated with a namespace it is also cloned
//         */
//        AXIS2_EXTERN axutil_hash_t *AXIS2_CALL
//        axiom_element_extract_attributes(
//            axiom_element_t * om_element,
//            const axutil_env_t * env,
//            axiom_node_t * ele_node);

    };
    /** @} */
}
#endif // OMELEMENT_H
