/*
 * Copyright 2004,2005 The Apache Software Foundation.
 *
 * Licensed under the Apache License, Version 2.0 (the "License")
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
 
#ifndef REMOTE_REGISTRY_CONSTANTS_H
#define REMOTE_REGISTRY_CONSTANTS_H

#ifdef __cplusplus
extern "C"
{
#endif

/**
 * @defgroup remote_registry_constants
 * @ingroup remote_registry
 * @{
 */
    
    #define REMOTE_REGISTRY_ACTIVE_STATE  100
    #define REMOTE_REGISTRY_DELETED_STATE 101

	#define REMOTE_REGISTRY "remote_registry"
    #define REMOTE_REGISTRY_USER_AGENT "RESTClient C Library"
    #define REMOTE_REGISTRY_ATOM_DATA_FILE_NAME "atom_data.xml"
    #define REMOTE_REGISTRY_REGISTRY_URL "registry_url"
    #define REMOTE_REGISTRY_REGISTRY_USERNAME "registry_username"
    #define REMOTE_REGISTRY_REGISTRY_PASSWORD "registry_password"

    #define REMOTE_REGISTRY_COMMENT_PARAMTER ";comments"
    #define REMOTE_REGISTRY_COMMENT_MEDIA_TYPE "plain/text"
    #define REMOTE_REGISTRY_RATING_PARAMTER ";ratings"
	#define REMOTE_REGISTRY_RATING_MEDIA_TYPE "plain/text"
    #define REMOTE_REGISTRY_TAG_PARAMTER ";tags"
    #define REMOTE_REGISTRY_TAGPATHS_PARAMTER "tagpaths"
    #define REMOTE_REGISTRY_ADDUSER_PARAMETER "adduser"
    #define REMOTE_REGISTRY_ATOM_NS "http://www.w3.org/2005/Atom"
    #define REMOTE_REGISTRY_ATOM_NS_PREFIX ""
    #define REMOTE_REGISTRY_WSO2_TAG_NS "tag:wso2.org,2008:foo"
    #define REMOTE_REGISTRY_REGISTRY_NS "http://wso2.org/registry"
    #define REMOTE_REGISTRY_REGISTRY_NS_PREFIX "ns"
	#define REMOTE_REGISTRY_CONTENT_TYPE_HEADER_NAME "Content-Type: "
	#define REMOTE_REGISTRY_BASE_URL_POSTFIX "/atom"

    #define REMOTE_REGISTRY_FEED_CONTENT_TYPE "application/atom+xml;charset=UTF-8"
    #define REMOTE_REGISTRY_FEED_ENTRY_CONTENT_TYPE "application/atom+xml; type=entry;charset=UTF-8"
    #define REMOTE_REGISTRY_FEED_CONTENT_TYPE_SENDING "application/atom+xml"
    #define REMOTE_REGISTRY_FEED_ENTRY_CONTENT_TYPE_SENDING "application/atom+xml;type=entry"

	/* constants on entry element names and attribute keys */
	#define REMOTE_REGISTRY_FEED_KEY_ID "id"
	#define REMOTE_REGISTRY_FEED_KEY_CHILD_COUNT "childCount"
	#define REMOTE_REGISTRY_FEED_KEY_MEDIA_TYPE "mediaType"
	#define REMOTE_REGISTRY_FEED_KEY_DIR "dir"
	#define REMOTE_REGISTRY_FEED_KEY_ENTRY "entry"
	#define REMOTE_REGISTRY_FEED_KEY_FEED "feed"
	#define REMOTE_REGISTRY_FEED_KEY_LINK "link"
	#define REMOTE_REGISTRY_FEED_ATTR_HREF "href"
	#define REMOTE_REGISTRY_FEED_ATTR_REL "rel"
	#define REMOTE_REGISTRY_FEED_ATTR_SELF "self"
	#define REMOTE_REGISTRY_FEED_ATTR_ALTERNATE "alternate"
	#define REMOTE_REGISTRY_FEED_ATTR_PATH "path"
	#define REMOTE_REGISTRY_FEED_ATTR_EDIT "edit"
	#define REMOTE_REGISTRY_FEED_ATTR_EDIT_MEDIA "edit-media"
	#define REMOTE_REGISTRY_FEED_KEY_CONTENT "content"
	#define REMOTE_REGISTRY_FEED_VALUE_EMPTY_CONTENT ""
	#define REMOTE_REGISTRY_FEED_ATTR_SRC "src"
	#define REMOTE_REGISTRY_FEED_KEY_AUTHOR "author"
	#define REMOTE_REGISTRY_FEED_KEY_NAME "name"
	#define REMOTE_REGISTRY_FEED_KEY_PROPERTIES "properties"
	#define REMOTE_REGISTRY_FEED_KEY_TITLE "title"
	#define REMOTE_REGISTRY_FEED_ATTR_TYPE "type"
	#define REMOTE_REGISTRY_FEED_ATTR_TYPE_BASE64_VALUE "application/octet-stream"
	#define REMOTE_REGISTRY_FEED_ATTR_TYPE_TEXT_VALUE "text"
	#define REMOTE_REGISTRY_FEED_ATTR_TYPE_TEXT "text"
	#define REMOTE_REGISTRY_FEED_KEY_SUMMARY "summary"
	#define REMOTE_REGISTRY_FEED_KEY_UPDATED "updated"
	#define REMOTE_REGISTRY_FEED_KEY_PROPERTIES "properties"
	#define REMOTE_REGISTRY_FEED_KEY_PROPERTY "property"
	#define REMOTE_REGISTRY_FEED_KEY_PROPERTY_KEY_NAME "name"
	#define REMOTE_REGISTRY_FEED_KEY_PROPERTY_KEY_VALUE "value"
	#define REMOTE_REGISTRY_FEED_KEY_PARENT_PATH "parentPath"
	#define REMOTE_REGISTRY_FEED_KEY_CONTENT_MODIFIED "contentModified"
	#define REMOTE_REGISTRY_FEED_KEY_TRUE_VALUE "true"
	#define REMOTE_REGISTRY_ETAG_HADER_KEY "ETag: "

	#define REMOTE_REGISTRY_DEFAULT_CACHE_LIMIT 50000

/** @} */
#ifdef __cplusplus
}
#endif
 
#endif /*REMOTE_REGISTRY_CONSTANTS_H*/
