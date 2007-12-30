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

#ifndef OMTEXT_H
#define OMTEXT_H

#include <WSFDefines.h>
#include <axiom_text.h>
#include <OMNode.h>
#include <OMElement.h>
#include <OMDataHandler.h>
#include <OMException.h>

/**
 * @file OMText.h
 */

/**
 * @brief namespace wso2wsf Namespace of WSO2 Web Services Framework.
 */
namespace wso2wsf
{
    /**
     * @defgroup om_text OM Text
     * @ingroup wso2wsf
     * @{
     */

    /**
     * @brief class OMText This object can contain data as a String, char[] or a DataHandler.
     */
    class OMText : public OMNode
    {
    private:
        /**
         * @var _wsf_axiom_text protected variable holds reference for
         * axiom_text struct.
         */
        axiom_text_t * _wsf_axiom_text;

        /**
         * @var _data_handler protected variable holds reference for
         * axiom_data_handler struct.
         */
        OMDataHandler * _data_handler;

        /**
         * @var _parent private variable holds reference to parent element.
         */
        OMNode * _parent;

    public:
        /**
         * Creates an om text struct.
         * @param parent parent element.
         * @param value Text value. Optinal, can be NULL.
         * @exception OMException an exception is thrown if something goes wrong
         * while creating the object.
         */
        WSF_EXTERN WSF_CALL OMText(OMNode * parent, std::string value) throw(OMException);

        /**
         * Creates an om text struct.
         * @param value Text value. Optinal, can be NULL.
         * @exception OMException an exception is thrown if something goes wrong
         * while creating the object.
         */
        WSF_EXTERN WSF_CALL OMText(std::string value) throw(OMException);

        /**
         * Creates an om text struct.
         * @param parent parent element.
         * @param value Text value. Optinal, can be NULL.
         * @exception OMException an exception is thrown if something goes wrong
         * while creating the object.
         */
        WSF_EXTERN WSF_CALL OMText(OMNode * parent, OMDataHandler * data_handler) throw(OMException);

        /**
         * Creates an om text struct.
         * @param data_handler the data handler. Optinal, can be NULL.
         * @exception OMException an exception is thrown if something goes wrong
         * while creating the object.
         */
        WSF_EXTERN WSF_CALL OMText(OMDataHandler * data_handler) throw(OMException);

        /**
         * Creates an om text struct.
         * @exception OMException an exception is thrown if something goes wrong
         * while creating the object.
         */
        WSF_EXTERN WSF_CALL OMText() throw(OMException);

        /**
         * Creates an om text struct.
         * @param parent parent element.
         * @param node node used to build the element. cannot be NULL.
         * @exception OMException an exception is thrown if something goes wrong
         * while creating the object.
         */
        WSF_CALL OMText(OMNode * parent, axiom_node_t * node) throw(OMException);

        /**
         * Desctructor that frees resources.
         */
        WSF_CALL ~OMText();

        /**
         * Sets the text value
         * @param value text.
         * @return status of the op. true on success,
         * false on error.
         */
        WSF_EXTERN bool WSF_CALL setValue(std::string value);

        /**
         * Gets text value
         * @return text value, "" is returned if there is no text value.
         */
        WSF_EXTERN std::string WSF_CALL getValue();

        /**
         * Gets text value from the text node even when MTOM optimized
         * @return text value base64 encoded text when MTOM optimized,
         * "" is returned if there is no text value.
         */
        WSF_EXTERN std::string WSF_CALL getText();

        /**
         * Sets optimized.
         * @param optimize optimize value or not.
         */
        WSF_EXTERN void WSF_CALL optimize(bool optimize);

        /**
         * Sets whether to use binary or not.
         * @param is_binary binary or not.
         */
        WSF_EXTERN void WSF_CALL isBinary(bool is_binary);

        /**
         * Retrieves data handler.
         * @return data handler is returned.
         */
        WSF_EXTERN OMDataHandler * WSF_CALL getDataHandler();

        /**
         * Gets the content id.
         * @return content id is returned.
         */
        WSF_EXTERN std::string WSF_CALL getContentId();

        /**
         * Sets the content id.
         * @param content_id content id to be set.
         * @return status of the op. true on success,
         * false on error.
         */
        WSF_EXTERN bool WSF_CALL setContentId(std::string content_id);

        /**
         * Detaches given node from the parent and reset the links.
         * @return a pointer to detached node,returns NULL on error with error
         * code set to environment's error struct.
         */
        WSF_EXTERN virtual OMNode * WSF_CALL detach();

        /**
         * get parent of node.
         * @return pointer to parent node of node, return NULL if no parent exists or
         * when an error occured.
         */
        WSF_EXTERN virtual OMNode * WSF_CALL getParent();

        /**
         * get the previous sibling.
         * @return a pointer to previous sibling , NULL if a previous sibling does not exits
         * (happens when this node is the first child of a node).
         */
        WSF_EXTERN virtual OMNode * WSF_CALL getPreviousSibling();

        /**
         * get next sibling.
         * @return next sibling of this node.
         */
        WSF_EXTERN virtual OMNode * WSF_CALL getNextSibling();

        /**
         * get the node type of this element.
         * Node type can be one of AXIOM_ELEMENT, AXIOM_COMMENT, AXIOM_TEXT
         * AXIOM_DOCTYPE, AXIOM_PROCESSING_INSTRUCTION.
         * @return node type.
         */
        WSF_EXTERN virtual axiom_types_t WSF_CALL nodeType();
    };
    /** @} */
}
#endif // OMTEXT_H
