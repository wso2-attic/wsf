<!--
  ~ Licensed to the Apache Software Foundation (ASF) under one
  ~ or more contributor license agreements. See the NOTICE file
  ~ distributed with this work for additional information
  ~ regarding copyright ownership. The ASF licenses this file
  ~ to you under the Apache License, Version 2.0 (the
  ~ "License"); you may not use this file except in compliance
  ~ with the License. You may obtain a copy of the License at
  ~
  ~ http://www.apache.org/licenses/LICENSE-2.0
  ~
  ~ Unless required by applicable law or agreed to in writing,
  ~ software distributed under the License is distributed on an
  ~ "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
  ~ KIND, either express or implied. See the License for the
  ~ specific language governing permissions and limitations
  ~ under the License.
  -->

<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
    <xsl:output method="text"/>

     <!-- cater for the multiple classes - wrappped mode -->
    <xsl:template match="/beans">
        <xsl:variable name="name"><xsl:value-of select="@name"/></xsl:variable>
        <xsl:variable name="axis2_name"><xsl:value-of select="@name"/></xsl:variable>
        <xsl:variable name="caps_axis2_name"><xsl:value-of select="@caps-name"/></xsl:variable>
        #ifndef <xsl:value-of select="$caps_axis2_name"/>_H
        #define <xsl:value-of select="$caps_axis2_name"/>_H

        /**
        * <xsl:value-of select="$name"/>.h
        *
        * This file was auto-generated from WSDL
        * by the Apache Axis2/Java version: #axisVersion# #today#
        */

        #include &lt;stdio.h&gt;
        #include &lt;OMElement.h&gt;
        #include &lt;ServiceClient.h&gt;
        #include &lt;ADBDefines.h&gt;


        /**
        *  <xsl:value-of select="$axis2_name"/> wrapped class classes ( classes for CPP )
        */

        <xsl:apply-templates/>

        #endif /* <xsl:value-of select="$caps_axis2_name"/>_H */
    </xsl:template>

    <!--cater for the multiple classes - unwrappped mode -->
    <xsl:template match="/">
        <xsl:apply-templates/>
    </xsl:template>


    <xsl:template match="class">
        <xsl:variable name="name"><xsl:value-of select="@name"/></xsl:variable>
        <xsl:variable name="axis2_name"><xsl:value-of select="@name"/></xsl:variable>
        <xsl:variable name="caps_axis2_name"><xsl:value-of select="@caps-name"/></xsl:variable>
        <xsl:variable name="istype"><xsl:value-of select="@type"></xsl:value-of></xsl:variable>


       <xsl:variable name="originalName"><xsl:value-of select="@originalName"/></xsl:variable>
       <xsl:variable name="nsuri"><xsl:value-of select="@nsuri"/></xsl:variable>
       <xsl:variable name="nsprefix"><xsl:value-of select="@nsprefix"/></xsl:variable>
       <xsl:variable name="anon"><xsl:value-of select="@anon"/></xsl:variable>
       <xsl:variable name="ordered"><xsl:value-of select="@ordered"/></xsl:variable>
       <xsl:variable name="particleClass"><xsl:value-of select="@particleClass"/></xsl:variable> <!-- particle classes are used to represent schema groups -->
       <xsl:variable name="hasParticleType"><xsl:value-of select="@hasParticleType"/></xsl:variable> <!-- particle classes are used to represent schema groups -->
       <xsl:variable name="simple"><xsl:value-of select="@simple"/></xsl:variable>
       <xsl:variable name="choice"><xsl:value-of select="@choice"/></xsl:variable>
        <xsl:variable name="enableNS2P"><xsl:value-of select="@enableNS2P"/></xsl:variable>
        <!-- checking for is union -->
        <xsl:variable name="isUnion" select="@union"/>
      <xsl:choose>
        <xsl:when test="@enableNS2P">
          #ifndef <xsl:value-of select="@cppNamespace"/>_<xsl:value-of select="$caps_axis2_name"/>_H
          #define <xsl:value-of select="@cppNamespace"/>_<xsl:value-of select="$caps_axis2_name"/>_H
        </xsl:when>
        <xsl:otherwise>
          #ifndef <xsl:value-of select="$caps_axis2_name"/>_H
          #define <xsl:value-of select="$caps_axis2_name"/>_H

        </xsl:otherwise>
      </xsl:choose>
      
       /**
        * <xsl:value-of select="$axis2_name"/>.h
        *
        * This file was auto-generated from WSDL
        * by the Apache Axis2/Java version: #axisVersion# #today#
        */

       /**
        *  <xsl:value-of select="$axis2_name"/> class
        */

        namespace <xsl:value-of select="@cppNamespace"/>{
            class <xsl:value-of select="$name"/>;
        }
        

        <xsl:for-each select="property">
          <xsl:if test="@ours">
            <xsl:choose>
              <xsl:when test="$enableNS2P">
                <xsl:variable name="filenameStr" select="@filename"/>
                #include "<xsl:value-of select="$filenameStr"/>.h"
              </xsl:when>
              <xsl:otherwise>
                #include "<xsl:value-of select="substring-after(@type,'::')"/>.h"
              </xsl:otherwise>
            </xsl:choose>
          </xsl:if>
        </xsl:for-each>
        <!--include special headers-->
        <xsl:for-each select="property[@type='axutil_date_time_t*']">
          <xsl:if test="position()=1">
        #include &lt;axutil_date_time.h&gt;
          </xsl:if>
        </xsl:for-each>
        <xsl:for-each select="property[@type='axutil_base64_binary_t*']">
          <xsl:if test="position()=1">
        #include &lt;axutil_base64_binary.h&gt;
          </xsl:if>
        </xsl:for-each>
        <xsl:for-each select="property[@type='axutil_duration_t*']">
          <xsl:if test="position()=1">
        #include &lt;axutil_duration.h&gt;
          </xsl:if>
        </xsl:for-each>
        <xsl:for-each select="memberType">
          <xsl:if test="@ours">
          <xsl:variable name="propertyType" select="@type"/>
        #include "<xsl:value-of select="substring-after($propertyType,'::')"/>.h"
          </xsl:if>
        </xsl:for-each>
        <xsl:if test="not($istype)">
        #include &lt;axutil_qname.h&gt;
        </xsl:if>

        #include &lt;stdio.h&gt;
        #include &lt;OMElement.h&gt;
        #include &lt;ServiceClient.h&gt;
        #include &lt;ADBDefines.h&gt;

namespace <xsl:value-of select="@cppNamespace"/>
{
        <xsl:variable name="isEnum">
          <xsl:choose>
            <xsl:when test="count(property)=1 and property/enumFacet and property/@type='std::string'">1</xsl:when>
            <xsl:otherwise>0</xsl:otherwise>
          </xsl:choose>
        </xsl:variable>

        <xsl:if test="$isEnum=1">
            <xsl:variable name="enum">ADB<xsl:value-of select="property/@cname"/>Enum</xsl:variable>
            <xsl:variable name="propertyCapsCName" select="property/@caps-cname"/>
        /* Enumeration for this type */
        typedef enum {
            <xsl:for-each select="property/enumFacet">
                <xsl:text/><xsl:value-of select="$propertyCapsCName"/>_<xsl:value-of select="@id"/>
                <xsl:if test="position()!=last()">,
            </xsl:if>
          </xsl:for-each>
        } <xsl:value-of select="$enum"/>;
        </xsl:if>

        <!-- checking for is union -->
        <xsl:variable name="isUnion" select="@union"/>
        

        class <xsl:value-of select="$axis2_name"/> {

        private:
             <xsl:if test="not($istype)">
                axutil_qname_t* qname;
            </xsl:if>

            <xsl:for-each select="property">
                <xsl:variable name="propertyType">
                   <xsl:choose>                                                               <!-- <xsl:if test="@ours"><xsl:text>*</xsl:text></xsl:if> -->
                     <xsl:when test="@isarray">std::vector&lt;<xsl:value-of select="@type"/><xsl:if test="@ours or @type='std::string' or @type='unsigned char' or @type='unsigned short' or @type='uint64_t' or @type='unsigned int' or @type='short' or @type='char' or @type='int' or @type='float' or @type='double' or @type='int64_t'"><xsl:text>*</xsl:text></xsl:if>&gt;*</xsl:when>
                     <xsl:when test="not(@type)">wso2wsf::OMElement*</xsl:when> <!-- these are anonymous -->
                     <xsl:otherwise><xsl:value-of select="@type"/><xsl:if test="@ours"><xsl:text>*</xsl:text></xsl:if></xsl:otherwise>
                   </xsl:choose>
                </xsl:variable>
                <xsl:variable name="propertyName"><xsl:value-of select="@name"></xsl:value-of></xsl:variable>
                <xsl:variable name="CName"><xsl:value-of select="@cname"></xsl:value-of></xsl:variable>

                <!-- All propertys will have property_<PropertyName> -->
                <xsl:value-of select="$propertyType"/><xsl:text> property_</xsl:text><xsl:value-of select="$CName"/>;

                <!-- For arrays is_valid_* tracks for whether at least one element of the array is non-NULL -->
                <xsl:text>bool isValid</xsl:text><xsl:value-of select="$CName"/>;
            </xsl:for-each>

            <!-- The section covers the storage for list types, -->
            <xsl:for-each select="itemtype">
                <xsl:variable name="propertyType">std::vector&lt;<xsl:value-of select="@type"/><xsl:if test="@ours or @type='std::string' or @type='unsigned char' or @type='unsigned short' or @type='uint64_t' or @type='unsigned int' or @type='short' or @type='char' or @type='int' or @type='float' or @type='double' or @type='int64_t'"><xsl:text>*</xsl:text></xsl:if>&gt;*</xsl:variable>
                <xsl:variable name="propertyName"><xsl:value-of select="$name"></xsl:value-of></xsl:variable>
                <xsl:variable name="CName"><xsl:value-of select="$name"></xsl:value-of></xsl:variable>
 
                <xsl:value-of select="$propertyType"/><xsl:text> property_</xsl:text><xsl:value-of select="$CName"/>;
                <xsl:text>bool isValid</xsl:text><xsl:value-of select="$CName"/>;
            </xsl:for-each>


            <xsl:if test="$choice">
                std::string currentChoice;
            </xsl:if>

            <!-- next it covers the union types -->
            <xsl:if test="$isUnion">
                /* for unions we are keeping members in a struct */

            struct {
            <xsl:for-each select="memberType">
                <xsl:variable name="member_type"><xsl:value-of select="@type"/><xsl:if test="@ours">*</xsl:if></xsl:variable>
                <xsl:variable name="name"><xsl:text>_</xsl:text><xsl:value-of select="@originalName"/></xsl:variable>
                <xsl:text></xsl:text><xsl:value-of select="$member_type"/><xsl:text> </xsl:text><xsl:value-of select="$name"/>;
            </xsl:for-each>
            } memberType;

                /* here too we keep the choice */
                std::string currentValue;
            </xsl:if>

        /*** Private methods ***/
          <xsl:for-each select="property">
            <xsl:variable name="propertyType">
            <xsl:choose>
                <xsl:when test="@isarray">std::vector&lt;<xsl:value-of select="@type"/><xsl:if test="@ours or @type='std::string' or @type='unsigned char' or @type='unsigned short' or @type='uint64_t' or @type='unsigned int' or @type='short' or @type='char' or @type='int' or @type='float' or @type='double' or @type='int64_t'"><xsl:text>*</xsl:text></xsl:if>&gt;*</xsl:when>
                <xsl:when test="not(@type)">wso2wsf::OMElement*</xsl:when> <!-- these are anonymous -->
                <xsl:otherwise><xsl:value-of select="@type"/><xsl:if test="@ours"><xsl:text>*</xsl:text></xsl:if></xsl:otherwise>
            </xsl:choose>
            </xsl:variable>
            <xsl:variable name="propertyName"><xsl:value-of select="@name"></xsl:value-of></xsl:variable>
            <xsl:variable name="CName"><xsl:value-of select="@cname"></xsl:value-of></xsl:variable>

            <xsl:variable name="nativePropertyType"> <!--these are used in arrays to take the native type-->
               <xsl:choose>
                 <xsl:when test="not(@type)">wso2wsf::OMElement*</xsl:when> <!-- these are anonymous -->
                 <xsl:otherwise><xsl:value-of select="@type"/><xsl:if test="@ours"><xsl:text>*</xsl:text></xsl:if></xsl:otherwise>
               </xsl:choose>
            </xsl:variable>
              <xsl:variable name="PropertyTypeArrayParam"> <!--these are used in arrays to take the type stored in the arraylist-->
                 <xsl:choose>
                   <xsl:when test="not(@type)">wso2wsf::OMElement*</xsl:when> <!-- these are anonymous -->
                   <xsl:when test="@type='unsigned char' or @type='unsigned short' or @type='uint64_t' or @type='unsigned int' or @type='short' or @type='char' or @type='int' or @type='float' or @type='double' or @type='int64_t'"><xsl:value-of select="@type"/><xsl:text>*</xsl:text></xsl:when>
                   <xsl:otherwise><xsl:value-of select="@type"/><xsl:if test="@ours"><xsl:text>*</xsl:text></xsl:if></xsl:otherwise>
                 </xsl:choose>
              </xsl:variable>
            <xsl:variable name="paramComment">
                <xsl:choose>
                    <xsl:when test="@isarray"><xsl:text>Array of </xsl:text><xsl:value-of select="$PropertyTypeArrayParam"/><xsl:text>s.</xsl:text></xsl:when>
                    <xsl:otherwise><xsl:value-of select="$nativePropertyType"/></xsl:otherwise>
                </xsl:choose>
            </xsl:variable>

            <xsl:if test="not(@nillable or @optional)">
                <xsl:if test="@isarray">
         <!--
         bool WSF_CALL
         set<xsl:value-of select="$CName"/>NilAt(int i);
         -->
                </xsl:if>

        bool WSF_CALL
        set<xsl:value-of select="$CName"/>Nil();
            </xsl:if>
          </xsl:for-each>



        /******************************* public functions *********************************/

        public:

        /**
         * Constructor for class <xsl:value-of select="$axis2_name"/>
         */

        <xsl:value-of select="$axis2_name"/>();

        /**
         * Destructor <xsl:value-of select="$axis2_name"/>
         */
        ~<xsl:value-of select="$axis2_name"/>();


       <xsl:variable name="arg_list">
            <xsl:for-each select="property">
                <xsl:variable name="propertyType">
                <xsl:choose>
                    <xsl:when test="@isarray">std::vector&lt;<xsl:value-of select="@type"/><xsl:if test="@ours or @type='std::string' or @type='unsigned char' or @type='unsigned short' or @type='uint64_t' or @type='unsigned int' or @type='short' or @type='char' or @type='int' or @type='float' or @type='double' or @type='int64_t'"><xsl:text>*</xsl:text></xsl:if>&gt;*</xsl:when>
                    <xsl:when test="not(@type)">wso2wsf::OMElement*</xsl:when> <!-- these are anonymous -->
                    <xsl:otherwise><xsl:value-of select="@type"/><xsl:if test="@ours"><xsl:text>*</xsl:text></xsl:if></xsl:otherwise>
                </xsl:choose>
                </xsl:variable>
                <xsl:variable name="CName"><xsl:value-of select="@cname"></xsl:value-of></xsl:variable>
                <xsl:if test="position() > 1"><xsl:text>,</xsl:text></xsl:if>
                <xsl:value-of select="$propertyType"/><xsl:text> arg_</xsl:text><xsl:value-of select="$CName"/>
            </xsl:for-each>
        </xsl:variable>
        <xsl:variable name="arg_list_comment">
            <xsl:for-each select="property">
                <xsl:variable name="propertyType">
                <xsl:choose>
                    <xsl:when test="@isarray">std::vector&lt;<xsl:value-of select="@type"/><xsl:if test="@ours or @type='std::string' or @type='unsigned char' or @type='unsigned short' or @type='uint64_t' or @type='unsigned int' or @type='short' or @type='char' or @type='int' or @type='float' or @type='double' or @type='int64_t'"><xsl:text>*</xsl:text></xsl:if>&gt;*</xsl:when>
                    <xsl:when test="not(@type)">wso2wsf::OMElement*</xsl:when> <!-- these are anonymous -->
                    <xsl:otherwise><xsl:value-of select="@type"/><xsl:if test="@ours"><xsl:text>*</xsl:text></xsl:if></xsl:otherwise>
                </xsl:choose>
                </xsl:variable>
                <xsl:variable name="CName"><xsl:value-of select="@cname"></xsl:value-of></xsl:variable>
                <xsl:text>
         * @param </xsl:text><xsl:value-of select="$CName"/><xsl:text> </xsl:text><xsl:value-of select="$propertyType"/>
            </xsl:for-each>
        </xsl:variable>

        /**
         * Constructor for creating <xsl:value-of select="$axis2_name"/>
         * @param <xsl:value-of select="$arg_list_comment"/>
         * @return newly created <xsl:value-of select="$axis2_name"/> object
         */
        <xsl:if test="count(property) > 0">
        <xsl:value-of select="$axis2_name"/>(<xsl:value-of select="$arg_list"/>);
        </xsl:if>
	
	

        /**
         * resetAll for <xsl:value-of select="$axis2_name"/>
         */
        WSF_EXTERN bool WSF_CALL resetAll();
        <!--
        <xsl:choose>
            <xsl:when test="count(property)">
                <xsl:variable name="firstProperty" select="property[1]"/>
                <xsl:variable name="propertyType">
                <xsl:choose>
                    <xsl:when test="$firstProperty/@isarray">axutil_array_list_t*</xsl:when>
                    <xsl:when test="not($firstProperty/@type)">axiom_node_t*</xsl:when>
                    <xsl:otherwise><xsl:value-of select="$firstProperty/@type"/></xsl:otherwise>
                </xsl:choose>
                </xsl:variable>
                <xsl:variable name="CName">_<xsl:value-of select="$firstProperty/@cname"></xsl:value-of></xsl:variable>


                /**
                 * Free <xsl:value-of select="$axis2_name"/>_t object and return the property value.
                 * You can use this to free the adb object as returning the property value. If there are
                 * many properties, it will only return the first property. Other properties will get freed with the adb object.
                 * @param <xsl:text> _</xsl:text><xsl:value-of select="$name"/> <xsl:text> </xsl:text><xsl:value-of select="$axis2_name"/>_t object to free
                 * @param env pointer to environment struct
                 * @return the property value holded by the ADB object, if there are many properties only returns the first.
                 */
                <xsl:value-of select="$propertyType"/> AXIS2_CALL
                <xsl:value-of select="$axis2_name"/>_free_popping_value(
                        <xsl:value-of select="$axis2_name"/>_t*<xsl:text> _</xsl:text><xsl:value-of select="$name"/>,
                        const axutil_env_t *env);
            </xsl:when>
            <xsl:otherwise>

                /**
                 * Free <xsl:value-of select="$axis2_name"/>_t object and return the property value.
                 * You can use this to free the adb object as returning the property value. If there are
                 * many properties, it will only return the first property. Other properties will get freed with the adb object.
                 * @param <xsl:text> _</xsl:text><xsl:value-of select="$name"/> <xsl:text> </xsl:text><xsl:value-of select="$axis2_name"/>_t object to free
                 * @param env pointer to environment struct
                 * @return the property value holded by the ADB object, if there are many properties only returns the first.
                 */
                void* AXIS2_CALL
                <xsl:value-of select="$axis2_name"/>_free_popping_value(
                        <xsl:value-of select="$axis2_name"/>_t*<xsl:text> _</xsl:text><xsl:value-of select="$name"/>,
                        const axutil_env_t *env);
            </xsl:otherwise>
        </xsl:choose>
        -->
        /********************************** Class get set methods **************************************/
        <xsl:if test="@choice">/******** In a case of a choose among elements, the last one to set will be chooosen *********/</xsl:if>
        <xsl:if test="count(property[@array])!=0">/******** Deprecated for array types, Use 'Getters and Setters for Arrays' instead ***********/</xsl:if>

        <xsl:if test="@list">/******* This is a list, please use Getters and 'Setters for Array' Instead of following *****/</xsl:if>

        <xsl:for-each select="property">
            <xsl:variable name="propertyType">
            <xsl:choose>
                <xsl:when test="@isarray">std::vector&lt;<xsl:value-of select="@type"/><xsl:if test="@ours or @type='std::string' or @type='unsigned char' or @type='unsigned short' or @type='uint64_t' or @type='unsigned int' or @type='short' or @type='char' or @type='int' or @type='float' or @type='double' or @type='int64_t'"><xsl:text>*</xsl:text></xsl:if>&gt;*</xsl:when>
                <xsl:when test="not(@type)">wso2wsf::OMElement*</xsl:when> <!-- these are anonymous -->
                <xsl:otherwise><xsl:value-of select="@type"/><xsl:if test="@ours"><xsl:text>*</xsl:text></xsl:if></xsl:otherwise>
            </xsl:choose>
            </xsl:variable>
            <xsl:variable name="propertyName"><xsl:value-of select="@name"></xsl:value-of></xsl:variable>
            <xsl:variable name="CName"><xsl:value-of select="@cname"></xsl:value-of></xsl:variable>

            <xsl:variable name="nativePropertyType"> <!--these are used in arrays to take the native type-->
               <xsl:choose>
                 <xsl:when test="not(@type)">wso2wsf::OMElement*</xsl:when> <!-- these are anonymous -->
                 <xsl:otherwise><xsl:value-of select="@type"/><xsl:if test="@ours or @type='std::string' or @type='unsigned char' or @type='unsigned short' or @type='uint64_t' or @type='unsigned int' or @type='short' or @type='char' or @type='int' or @type='float' or @type='double' or @type='int64_t'"><xsl:text>*</xsl:text></xsl:if></xsl:otherwise>
               </xsl:choose>
            </xsl:variable>
              <xsl:variable name="PropertyTypeArrayParam"> <!--these are used in arrays to take the type stored in the arraylist-->
                 <xsl:choose>
                   <xsl:when test="not(@type)">wso2wsf::OMElement*</xsl:when> <!-- these are anonymous -->
                   <xsl:when test="@type='unsigned short' or @type='uint64_t' or @type='unsigned int' or @type='unsigned char' or @type='short' or @type='char' or @type='int' or @type='float' or @type='double' or @type='int64_t'"><xsl:value-of select="@type"/><xsl:text>*</xsl:text></xsl:when>
                   <xsl:otherwise><xsl:value-of select="@type"/><xsl:if test="@ours"><xsl:text>*</xsl:text></xsl:if></xsl:otherwise>
                 </xsl:choose>
              </xsl:variable>
            <xsl:variable name="paramComment">
                <xsl:choose>
                    <xsl:when test="@isarray"><xsl:text>Array of </xsl:text><xsl:value-of select="$PropertyTypeArrayParam"/><xsl:text>s.</xsl:text></xsl:when>
                    <xsl:otherwise><xsl:value-of select="$nativePropertyType"/></xsl:otherwise>
                </xsl:choose>
            </xsl:variable>
            <xsl:variable name="constValue">
                <xsl:choose>
                   <xsl:when test="@isarray"></xsl:when>
                   <xsl:when test="@type='std::string' or @type='unsigned short' or @type='uint64_t' or @type='unsigned int' or @type='unsigned char' or @type='short' or @type='char' or @type='int' or @type='float' or @type='double' or @type='int64_t'">const </xsl:when>
                </xsl:choose>
            </xsl:variable>
        

        /**
         * Getter for <xsl:value-of select="$propertyName"/>. <xsl:if test="@isarray">Deprecated for array types, Use get<xsl:value-of select="$CName"/>At instead</xsl:if>
         * @return <xsl:value-of select="$paramComment"/>
         */
        WSF_EXTERN <xsl:value-of select="$propertyType"/> WSF_CALL
        get<xsl:value-of select="$CName"/>();

        /**
         * Setter for <xsl:value-of select="$propertyName"/>.<xsl:if test="@isarray">Deprecated for array types, Use set<xsl:value-of select="$CName"/>At
         * or add<xsl:value-of select="$CName"/> instead.</xsl:if>
         * @param arg_<xsl:value-of select="$CName"/><xsl:text> </xsl:text> <xsl:value-of select="$paramComment"/>
         * @return true on success, false otherwise
         */
        WSF_EXTERN bool WSF_CALL
        set<xsl:value-of select="$CName"/>(<xsl:value-of select="$constValue"/><xsl:value-of select="$propertyType"/><xsl:text> </xsl:text> arg_<xsl:value-of select="$CName"/>);

        /**
         * Re setter for <xsl:value-of select="$propertyName"/>
         * @return true on success, false
         */
        WSF_EXTERN bool WSF_CALL
        reset<xsl:value-of select="$CName"/>();
        </xsl:for-each>

        <!-- The following take care of list items -->

        <xsl:for-each select="itemtype">
            <xsl:variable name="propertyType">std::vector&lt;<xsl:value-of select="@type"/><xsl:if test="@ours or @type='std::string' or @type='unsigned char' or @type='unsigned short' or @type='uint64_t' or @type='unsigned int' or @type='short' or @type='char' or @type='int' or @type='float' or @type='double' or @type='int64_t'"><xsl:text>*</xsl:text></xsl:if>&gt;*</xsl:variable>
            <xsl:variable name="propertyName"><xsl:value-of select="$name"></xsl:value-of></xsl:variable>
            <xsl:variable name="CName"><xsl:value-of select="$name"></xsl:value-of></xsl:variable>

            <xsl:variable name="nativePropertyType"> <!--these are used in arrays to take the native type-->
               <xsl:choose>
                 <xsl:when test="not(@type)">wso2wsf::OMElement*</xsl:when> <!-- these are anonymous -->
                 <xsl:otherwise><xsl:value-of select="@type"/><xsl:if test="@ours"><xsl:text>*</xsl:text></xsl:if>
                </xsl:otherwise>
               </xsl:choose>
            </xsl:variable>
              <xsl:variable name="PropertyTypeArrayParam"> <!--these are used in arrays to take the type stored in the arraylist-->
                 <xsl:choose>
                   <xsl:when test="not(@type)">wso2wsf::OMElement*</xsl:when> <!-- these are anonymous -->
                   <xsl:when test="@type='unsigned short' or @type='uint64_t' or @type='unsigned int' or @type='unsigned char' or @type='short' or @type='char' or @type='int' or @type='float' or @type='double' or @type='int64_t'"><xsl:value-of select="@type"/><xsl:text>*</xsl:text></xsl:when>
                   <xsl:otherwise><xsl:value-of select="@type"/><xsl:if test="@ours"><xsl:text>*</xsl:text></xsl:if>
                    </xsl:otherwise>
                 </xsl:choose>
              </xsl:variable>
            <xsl:variable name="paramComment"><xsl:text>Array of </xsl:text><xsl:value-of select="$PropertyTypeArrayParam"/><xsl:text>s.</xsl:text></xsl:variable>
            <xsl:variable name="constValue">
                <xsl:choose>
                   <xsl:when test="@type='std::string' or @type='unsigned short' or @type='uint64_t' or @type='unsigned int' or @type='unsigned char' or @type='short' or @type='char' or @type='int' or @type='float' or @type='double' or @type='int64_t'">const </xsl:when>
                </xsl:choose>
            </xsl:variable>

        /**
         * Getter for <xsl:value-of select="$propertyName"/>. Deprecated for array types, Use get<xsl:value-of select="$CName"/>At().
         * @return <xsl:value-of select="$paramComment"/>
         */
        WSF_EXTERN <xsl:value-of select="$propertyType"/> WSF_CALL
        get<xsl:value-of select="$CName"/>();

        /**
         * Setter for <xsl:value-of select="$propertyName"/>. Deprecated for array types, Use set<xsl:value-of select="$CName"/>At()
         * or add<xsl:value-of select="$CName"/> instead.
         * @param arg_<xsl:value-of select="$CName"/><xsl:text> </xsl:text> <xsl:value-of select="$paramComment"/>
         * @return true on success, false otherwise
         */
        bool WSF_CALL
        set<xsl:value-of select="$CName"/>(<xsl:value-of select="$propertyType"/><xsl:text> </xsl:text> arg_<xsl:value-of select="$CName"/>);

        /**
         * Reset method for <xsl:value-of select="$propertyName"/>
         * @return true on success, false otherwise
         */
        bool WSF_CALL
        reset<xsl:value-of select="$CName"/>();

        </xsl:for-each>


        <xsl:if test="count(property[@array])!=0 or count(itemtype)!=0">
        /****************************** Get Set methods for Arrays **********************************/
        /************ Array Specific Operations: get_at, set_at, add, remove_at, sizeof *****************/

        /**
         * E.g. use of get_at, set_at, add and sizeof
         *
         * for(i = 0; i &lt; adb_element->sizeofProperty(); i ++ )
         * {
         *     // Getting ith value to property_object variable
         *     property_object = adb_element->getPropertyAt(i);
         *
         *     // Setting ith value from property_object variable
         *     adb_element->setPropertyAt(i, property_object);
         *
         *     // Appending the value to the end of the array from property_object variable
         *     adb_element->addProperty(property_object);
         *
         *     // Removing the ith value from an array
         *     adb_element->removePropertyAt(i);
         *     
         * }
         *
         */

        </xsl:if>

        <xsl:for-each select="property">
            <xsl:variable name="propertyType">
            <xsl:choose>
                <xsl:when test="@isarray">std::vector&lt;<xsl:value-of select="@type"/><xsl:if test="@ours or @type='std::string' or @type='unsigned char' or @type='unsigned short' or @type='uint64_t' or @type='unsigned int' or @type='short' or @type='char' or @type='int' or @type='float' or @type='double' or @type='int64_t'"><xsl:text>*</xsl:text></xsl:if>&gt;*</xsl:when>
                <xsl:when test="not(@type)">wso2wsf::OMElement*</xsl:when> <!-- these are anonymous -->
                <xsl:otherwise><xsl:value-of select="@type"/><xsl:if test="@ours"><xsl:text>*</xsl:text></xsl:if></xsl:otherwise>
            </xsl:choose>
            </xsl:variable>
            <xsl:variable name="propertyName"><xsl:value-of select="@name"></xsl:value-of></xsl:variable>
            <xsl:variable name="CName"><xsl:value-of select="@cname"></xsl:value-of></xsl:variable>

            <xsl:variable name="nativePropertyType"> <!--these are used in arrays to take the native type-->
               <xsl:choose>
                 <xsl:when test="not(@type)">wso2wsf::OMElement*</xsl:when> <!-- these are anonymous -->
                 <xsl:otherwise><xsl:value-of select="@type"/><xsl:if test="@ours"><xsl:text>*</xsl:text></xsl:if></xsl:otherwise>
               </xsl:choose>
            </xsl:variable>
              <xsl:variable name="PropertyTypeArrayParam"> <!--these are used in arrays to take the type stored in the arraylist-->
                 <xsl:choose>
                   <xsl:when test="not(@type)">wso2wsf::OMElement*</xsl:when> <!-- these are anonymous -->
                   <xsl:when test="@type='unsigned short' or @type='uint64_t' or @type='unsigned int' or @type='unsigned char' or @type='short' or @type='char' or @type='int' or @type='float' or @type='double' or @type='int64_t'"><xsl:value-of select="@type"/><xsl:text>*</xsl:text></xsl:when>
                   <xsl:otherwise><xsl:value-of select="@type"/></xsl:otherwise>
                 </xsl:choose>
              </xsl:variable>
            <xsl:variable name="paramComment">
                <xsl:choose>
                    <xsl:when test="@isarray"><xsl:text>Array of </xsl:text><xsl:value-of select="$PropertyTypeArrayParam"/><xsl:text>s.</xsl:text></xsl:when>
                    <xsl:otherwise><xsl:value-of select="$nativePropertyType"/></xsl:otherwise>
                </xsl:choose>
            </xsl:variable>
            <xsl:variable name="constValue">
                <xsl:choose>
                   <xsl:when test="@type='std::string' or @type='unsigned short' or @type='uint64_t' or @type='unsigned int' or @type='unsigned char' or @type='short' or @type='char' or @type='int' or @type='float' or @type='double' or @type='int64_t'">const </xsl:when>
                </xsl:choose>
            </xsl:variable>


        <xsl:if test="@isarray">
        
        /**
         * Get the ith element of <xsl:value-of select="$propertyName"/>.
        * @param i index of the item to be obtained
         * @return ith <xsl:value-of select="$nativePropertyType"/> of the array
         */
        WSF_EXTERN <xsl:value-of select="$nativePropertyType"/> WSF_CALL
        get<xsl:value-of select="$CName"/>At(int i);

        /**
         * Set the ith element of <xsl:value-of select="$propertyName"/>. (If the ith already exist, it will be replaced)
         * @param i index of the item to return
         * @param <xsl:text>arg_</xsl:text> <xsl:value-of select="$CName"/> element to set <xsl:value-of select="$nativePropertyType"/> to the array
         * @return ith <xsl:value-of select="$nativePropertyType"/> of the array
         */
        WSF_EXTERN bool WSF_CALL
        set<xsl:value-of select="$CName"/>At(int i,
                <xsl:value-of select="$constValue"/><xsl:value-of select="$nativePropertyType"/><xsl:text> arg_</xsl:text> <xsl:value-of select="$CName"/>);


        /**
         * Add to <xsl:value-of select="$propertyName"/>.
         * @param <xsl:text>arg_</xsl:text> <xsl:value-of select="$CName"/> element to add <xsl:value-of select="$nativePropertyType"/> to the array
         * @return true on success, false otherwise.
         */
        WSF_EXTERN bool WSF_CALL
        add<xsl:value-of select="$CName"/>(
            <xsl:value-of select="$constValue"/><xsl:value-of select="$nativePropertyType"/><xsl:text> arg_</xsl:text> <xsl:value-of select="$CName"/>);

        /**
         * Get the size of the <xsl:value-of select="$propertyName"/> array.
         * @return the size of the <xsl:value-of select="$propertyName"/> array.
         */
        WSF_EXTERN int WSF_CALL
        sizeof<xsl:value-of select="$CName"/>();

        /**
         * Remove the ith element of <xsl:value-of select="$propertyName"/>.
         * @param i index of the item to remove
         * @return true on success, false otherwise.
         */
        WSF_EXTERN bool WSF_CALL
        remove<xsl:value-of select="$CName"/>At(int i);

        </xsl:if> <!-- xsl:if test="@isarray" -->
        </xsl:for-each> <!-- xsl:for-each select="property" -->

        <!-- The section covers the list types -->
        <xsl:for-each select="itemtype">
            <xsl:variable name="propertyType">std::vector&lt;<xsl:value-of select="@type"/><xsl:if test="@ours or @type='std::string' or @type='unsigned char' or @type='unsigned short' or @type='uint64_t' or @type='unsigned int' or @type='short' or @type='char' or @type='int' or @type='float' or @type='double' or @type='int64_t'"><xsl:text>*</xsl:text></xsl:if>&gt;*</xsl:variable>
            <xsl:variable name="propertyName"><xsl:value-of select="$name"></xsl:value-of></xsl:variable>
            <xsl:variable name="CName"><xsl:value-of select="$name"></xsl:value-of></xsl:variable>

            <xsl:variable name="nativePropertyType"> <!--these are used in arrays to take the native type-->
               <xsl:choose>
                 <xsl:when test="not(@type)">wso2wsf::OMElement*</xsl:when> <!-- these are anonymous -->
                 <xsl:otherwise><xsl:value-of select="@type"/></xsl:otherwise>
               </xsl:choose>
            </xsl:variable>
              <xsl:variable name="PropertyTypeArrayParam"> <!--these are used in arrays to take the type stored in the arraylist-->
                 <xsl:choose>
                   <xsl:when test="not(@type)">wso2wsf::OMElement*</xsl:when> <!-- these are anonymous -->
                   <xsl:when test="@type='unsigned short' or @type='uint64_t' or @type='unsigned int' or @type='unsigned char' or @type='short' or @type='char' or @type='int' or @type='float' or @type='double' or @type='int64_t'"><xsl:value-of select="@type"/><xsl:text>*</xsl:text></xsl:when>
                   <xsl:otherwise><xsl:value-of select="@type"/></xsl:otherwise>
                 </xsl:choose>
              </xsl:variable>
            <xsl:variable name="paramComment"><xsl:text>Array of </xsl:text><xsl:value-of select="$PropertyTypeArrayParam"/><xsl:text>s.</xsl:text></xsl:variable>
            <xsl:variable name="constValue">
                <xsl:choose>
                   <xsl:when test="@type='std::string' or @type='unsigned short' or @type='uint64_t' or @type='unsigned int' or @type='unsigned char' or @type='short' or @type='char' or @type='int' or @type='float' or @type='double' or @type='int64_t'">const </xsl:when>
                </xsl:choose>
            </xsl:variable>
         
        /**
         * Get the ith element of <xsl:value-of select="$propertyName"/>.
         * @param <xsl:text> _</xsl:text><xsl:value-of select="$name"/> <xsl:text> </xsl:text><xsl:value-of select="$axis2_name"/>_t object
         * @param env pointer to environment struct
         * @param i index of the item to return
         * @return ith <xsl:value-of select="$nativePropertyType"/> of the array
         */
        WSF_EXTERN <xsl:value-of select="$nativePropertyType"/> WSF_CALL
        get<xsl:value-of select="$CName"/>At(int i);

        /**
         * Set the ith element of <xsl:value-of select="$propertyName"/>. (If the ith already exist, it will be replaced)
         * @param i index of the item to return
         * @param <xsl:text>arg_</xsl:text> <xsl:value-of select="$CName"/> element to set <xsl:value-of select="$nativePropertyType"/> to the array
         * @return ith <xsl:value-of select="$nativePropertyType"/> of the array
         */
        WSF_EXTERN bool WSF_CALL
        set<xsl:value-of select="$CName"/>At(int i,
        <xsl:value-of select="$constValue"/><xsl:value-of select="$nativePropertyType"/><xsl:text> arg_</xsl:text> <xsl:value-of select="$CName"/>);


        /**
         * Add to <xsl:value-of select="$propertyName"/>.
         * @param <xsl:text>arg_</xsl:text> <xsl:value-of select="$CName"/> element to add <xsl:value-of select="$nativePropertyType"/> to the array
         * @return true on success, false otherwise.
         */
        WSF_EXTERN bool WSF_CALL
        add<xsl:value-of select="$CName"/>(
            <xsl:value-of select="$constValue"/><xsl:value-of select="$nativePropertyType"/><xsl:text> arg_</xsl:text> <xsl:value-of select="$CName"/>);

        /**
         * Get the size of the <xsl:value-of select="$propertyName"/> array.
         * @return the size of the <xsl:value-of select="$propertyName"/> array.
         */
        WSF_EXTERN int AXIS2_CALL
        sizeof<xsl:value-of select="$CName"/>();

        /**
         * Remove the ith element of <xsl:value-of select="$propertyName"/>.
         * @param i index of the item to remove
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        bool WSF_CALL
        remove<xsl:value-of select="$CName"/>At(int i);

        /**
        * Getter for <xsl:value-of select="$propertyName"/> by  Property Number <xsl:value-of select="position()"/>
        */
        <xsl:value-of select="$propertyType"/> WSF_CALL
        getProperty<xsl:value-of select="position()"/>();

       </xsl:for-each>

        <xsl:if test="$isEnum=1">
          <xsl:for-each select="property">
            <xsl:variable name="propertyName"><xsl:value-of select="@name"></xsl:value-of></xsl:variable>
            <xsl:variable name="CName"><xsl:value-of select="@cname"></xsl:value-of></xsl:variable>
            <xsl:variable name="enum">ADB<xsl:value-of select="@cname"/>Enum</xsl:variable>
            <xsl:variable name="constValue">
              <xsl:choose>
                <xsl:when test="@isarray"></xsl:when>
                <xsl:when test="@type='std::string' or @type='unsigned short' or @type='uint64_t' or @type='unsigned int' or @type='unsigned char' or @type='short' or @type='char' or @type='int' or @type='float' or @type='double' or @type='int64_t'">const </xsl:when>
              </xsl:choose>
            </xsl:variable>
            
            /************************** Getters and Setters For Enumerations ********************************/
            /********************* Enumeration Specific Operations: get_enum, set_enum **********************/
            
            /**
            * Enum getter for <xsl:value-of select="$propertyName"/>.
            * @return <xsl:value-of select="$enum"/>; -1 on failure
            */
            <xsl:value-of select="$enum"/> WSF_CALL
            get<xsl:value-of select="$CName"/>Enum();
            
            /**
            * Enum setter for <xsl:value-of select="$propertyName"/>.
            * @param arg_<xsl:value-of select="$CName"/><xsl:text> </xsl:text> <xsl:value-of select="$enum"/>
            * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
            */
            bool WSF_CALL
            set<xsl:value-of select="$CName"/>Enum(
            <xsl:value-of select="$constValue"/><xsl:value-of select="$enum"/><xsl:text> </xsl:text>arg_<xsl:value-of select="$CName"/>);
            
          </xsl:for-each>
        </xsl:if>


        /******************************* Checking and Setting NIL values *********************************/
        <xsl:if test="count(property[@array])!=0">/* Use 'Checking and Setting NIL values for Arrays' to check and set nil for individual elements */</xsl:if>

        /**
         * NOTE: set_nil is only available for nillable properties
         */

        <xsl:for-each select="property">
            <xsl:variable name="propertyType">
            <xsl:choose>
                <xsl:when test="@isarray">std::vector&lt;<xsl:value-of select="@type"/><xsl:if test="@ours"><xsl:text>*</xsl:text></xsl:if>&gt;*</xsl:when>
                <xsl:when test="not(@type)">wso2wsf::OMElement*</xsl:when> <!-- these are anonymous -->
                <xsl:otherwise><xsl:value-of select="@type"/></xsl:otherwise>
            </xsl:choose>
            </xsl:variable>
            <xsl:variable name="propertyName"><xsl:value-of select="@name"></xsl:value-of></xsl:variable>
            <xsl:variable name="CName"><xsl:value-of select="@cname"></xsl:value-of></xsl:variable>

            <xsl:variable name="nativePropertyType"> <!--these are used in arrays to take the native type-->
               <xsl:choose>
                 <xsl:when test="not(@type)">wso2wsf::OMElement*</xsl:when> <!-- these are anonymous -->
                 <xsl:otherwise><xsl:value-of select="@type"/></xsl:otherwise>
               </xsl:choose>
            </xsl:variable>
              <xsl:variable name="PropertyTypeArrayParam"> <!--these are used in arrays to take the type stored in the arraylist-->
                 <xsl:choose>
                   <xsl:when test="not(@type)">wso2wsf::OMElement*</xsl:when> <!-- these are anonymous -->
                   <xsl:when test="@type='unsigned short' or @type='uint64_t' or @type='unsigned int' or @type='unsigned char' or @type='short' or @type='char' or @type='int' or @type='float' or @type='double' or @type='int64_t'"><xsl:value-of select="@type"/><xsl:text>*</xsl:text></xsl:when>
                   <xsl:otherwise><xsl:value-of select="@type"/></xsl:otherwise>
                 </xsl:choose>
              </xsl:variable>
            <xsl:variable name="paramComment">
                <xsl:choose>
                    <xsl:when test="@isarray"><xsl:text>Array of </xsl:text><xsl:value-of select="$PropertyTypeArrayParam"/><xsl:text>s.</xsl:text></xsl:when>
                    <xsl:otherwise><xsl:value-of select="$nativePropertyType"/></xsl:otherwise>
                </xsl:choose>
            </xsl:variable>

        /**
         * Check whether <xsl:value-of select="$propertyName"/> is Nill
         * @return true if the element is Nil, false otherwise
         */
        bool WSF_CALL
        is<xsl:value-of select="$CName"/>Nil();


        <xsl:if test="@nillable or @optional">
        /**
         * Set <xsl:value-of select="$propertyName"/> to Nill (same as using reset)
         * @return true on success, false otherwise.
         */
        bool WSF_CALL
        set<xsl:value-of select="$CName"/>Nil();
        </xsl:if>

        </xsl:for-each> <!-- for-each select="proprety" -->

        <xsl:if test="count(property[@array])!=0">

        /*************************** Checking and Setting 'NIL' values in Arrays *****************************/

        /**
         * NOTE: You may set this to remove specific elements in the array
         *       But you can not remove elements, if the specific property is declared to be non-nillable or sizeof(array) &lt; minOccurs
         */
        </xsl:if>

        <xsl:for-each select="property">
            <xsl:variable name="propertyType">
            <xsl:choose>
                <xsl:when test="@isarray">std::vector&lt;<xsl:value-of select="@type"/><xsl:if test="@ours"><xsl:text>*</xsl:text></xsl:if>&gt;*</xsl:when>
                <xsl:when test="not(@type)">wso2wsf::OMElement*</xsl:when> <!-- these are anonymous -->
                <xsl:otherwise><xsl:value-of select="@type"/></xsl:otherwise>
            </xsl:choose>
            </xsl:variable>
            <xsl:variable name="propertyName"><xsl:value-of select="@name"></xsl:value-of></xsl:variable>
            <xsl:variable name="CName"><xsl:value-of select="@cname"></xsl:value-of></xsl:variable>

            <xsl:variable name="nativePropertyType"> <!--these are used in arrays to take the native type-->
               <xsl:choose>
                 <xsl:when test="not(@type)">wso2wsf::OMElement*</xsl:when> <!-- these are anonymous -->
                 <xsl:otherwise><xsl:value-of select="@type"/></xsl:otherwise>
               </xsl:choose>
            </xsl:variable>
              <xsl:variable name="PropertyTypeArrayParam"> <!--these are used in arrays to take the type stored in the arraylist-->
                 <xsl:choose>
                   <xsl:when test="not(@type)">wso2wsf::OMElement*</xsl:when> <!-- these are anonymous -->
                   <xsl:when test="@type='unsigned short' or @type='uint64_t' or @type='unsigned int' or @type='unsigned char' or @type='short' or @type='char' or @type='int' or @type='float' or @type='double' or @type='int64_t'"><xsl:value-of select="@type"/><xsl:text>*</xsl:text></xsl:when>
                   <xsl:otherwise><xsl:value-of select="@type"/></xsl:otherwise>
                 </xsl:choose>
              </xsl:variable>
            <xsl:variable name="paramComment">
                <xsl:choose>
                    <xsl:when test="@isarray"><xsl:text>Array of </xsl:text><xsl:value-of select="$PropertyTypeArrayParam"/><xsl:text>s.</xsl:text></xsl:when>
                    <xsl:otherwise><xsl:value-of select="$nativePropertyType"/></xsl:otherwise>
                </xsl:choose>
            </xsl:variable>
        <xsl:if test="@isarray">
        /**
         * Check whether <xsl:value-of select="$propertyName"/> is Nill at position i
         * @param i index of the item to return.
         * @return true if the value is Nil at position i, false otherwise
         */
        bool WSF_CALL
        is<xsl:value-of select="$CName"/>NilAt(int i);
 
       
        /**
         * Set <xsl:value-of select="$propertyName"/> to NILL at the  position i.
         * @param i . The index of the item to be set Nill.
         * @return true on success, false otherwise.
         */
        bool WSF_CALL
        set<xsl:value-of select="$CName"/>NilAt(int i);

        </xsl:if> <!-- closes isarray -->
        </xsl:for-each>

        /**************************** Serialize and De serialize functions ***************************/
        /*********** These functions are for use only inside the generated code *********************/

        <xsl:if test="@simple">
        /**
         * Deserialize the content from a string to an ADB object
         * @param node_value to deserialize
         * @param parent_element The parent element if it is an element, NULL otherwise
         * @return true on success, false otherwise
         */
       bool WSF_CALL
       deserializeFromString(const axis2_char_t *node_value, axiom_node_t *parent);
        </xsl:if>
        /**
         * Deserialize the ADB object to an XML
         * @param dp_parent double pointer to the parent node to be deserialized
         * @param dp_is_early_node_valid double pointer to a flag (is_early_node_valid?)
         * @param dont_care_minoccurs Dont set errors on validating minoccurs, 
         *              (Parent will order this in a case of choice)
         * @return true on success, false otherwise
         */
        bool WSF_CALL
        deserialize(axiom_node_t** omNode, bool *isEarlyNodeValid, bool dontCareMinoccurs);
                         
            <!-- Here the double pointer is used to change the parent pointer - This can be happned when deserialize is called in a particle class -->

       /**
         * Declare namespace in the most parent node 
         * @param parent_element parent element
         * @param namespaces hash of namespace uri to prefix
         * @param next_ns_index pointer to an int which contain the next namespace index
         */
        void WSF_CALL
        declareParentNamespaces(axiom_element_t *parent_element, axutil_hash_t *namespaces, int *next_ns_index);


        <xsl:if test="@simple">
        /**
         * Serialize ADB object to a string
         * @param namespaces hash which contains a mapping of namespace uris to prefixes
         * @return serialized string
         */
         char* WSF_CALL
         serializeToString(axutil_hash_t *namespaces);
        </xsl:if>

        /**
         * Serialize the ADB object to an xml
         * @param <xsl:value-of select="$name"/>_om_node node to serialize from
         * @param <xsl:value-of select="$name"/>_om_element parent element to serialize from
         * @param tag_closed Whether the parent tag is closed or not
         * @param namespaces hash of namespace uris to prefixes
         * @param next_ns_index an int which contains the next namespace index
         * @return axiom_node_t on success,NULL otherwise.
         */
        axiom_node_t* WSF_CALL
        serialize(axiom_node_t* <xsl:value-of select="$name"/>_om_node, axiom_element_t *<xsl:value-of select="$name"/>_om_element, int tag_closed, axutil_hash_t *namespaces, int *next_ns_index);

        /**
         * Check whether the <xsl:value-of select="$axis2_name"/> is a particle class (E.g. group, inner sequence)
         * @return true if this is a particle class, false otherwise.
         */
        bool WSF_CALL
        isParticle();



        /******************************* get the value by the property number  *********************************/
        /************NOTE: This method is introduced to resolve a problem in unwrapping mode *******************/

      <xsl:for-each select="property">
            <xsl:variable name="propertyType">
            <xsl:choose>
                <xsl:when test="@isarray">std::vector&lt;<xsl:value-of select="@type"/><xsl:if test="@ours or @type='std::string' or @type='unsigned char' or @type='unsigned short' or @type='uint64_t' or @type='unsigned int' or @type='short' or @type='char' or @type='int' or @type='float' or @type='double' or @type='int64_t'"><xsl:text>*</xsl:text></xsl:if>&gt;*</xsl:when>
                <xsl:when test="not(@type)">wso2wsf::OMElement*</xsl:when> <!-- these are anonymous -->
                <xsl:otherwise><xsl:value-of select="@type"/><xsl:if test="@ours"><xsl:text>*</xsl:text></xsl:if></xsl:otherwise>
            </xsl:choose>
            </xsl:variable>
            <xsl:variable name="propertyName"><xsl:value-of select="@name"></xsl:value-of></xsl:variable>
            <xsl:variable name="CName"><xsl:value-of select="@cname"></xsl:value-of></xsl:variable>

            <xsl:variable name="nativePropertyType"> <!--these are used in arrays to take the native type-->
               <xsl:choose>
                 <xsl:when test="not(@type)">std::vector&lt;<xsl:value-of select="@type"/><xsl:if test="@ours or @type='std::string' or @type='unsigned char' or @type='unsigned short' or @type='uint64_t' or @type='unsigned int' or @type='short' or @type='char' or @type='int' or @type='float' or @type='double' or @type='int64_t'"><xsl:text>*</xsl:text></xsl:if>&gt;*</xsl:when> <!-- these are anonymous -->
                 <xsl:otherwise><xsl:value-of select="@type"/></xsl:otherwise>
               </xsl:choose>
            </xsl:variable>
            <xsl:variable name="PropertyTypeArrayParam"> <!--these are used in arrays to take the type stored in the arraylist-->
               <xsl:choose>
                 <xsl:when test="not(@type)">wso2wsf::OMElement*</xsl:when> <!-- these are anonymous -->
                 <xsl:when test="@type='unsigned short' or @type='uint64_t' or @type='unsigned int' or @type='unsigned char' or @type='short' or @type='char' or @type='int' or @type='float' or @type='double' or @type='int64_t'"><xsl:value-of select="@type"/><xsl:text>*</xsl:text></xsl:when>
                 <xsl:otherwise><xsl:value-of select="@type"/></xsl:otherwise>
               </xsl:choose>
            </xsl:variable>
            <xsl:variable name="paramComment">
                <xsl:choose>
                    <xsl:when test="@isarray"><xsl:text>Array of </xsl:text><xsl:value-of select="$PropertyTypeArrayParam"/><xsl:text>s.</xsl:text></xsl:when>
                    <xsl:otherwise><xsl:value-of select="$nativePropertyType"/></xsl:otherwise>
                </xsl:choose>
            </xsl:variable>
        

        /**
         * Getter for <xsl:value-of select="$propertyName"/> by property number (<xsl:value-of select="position()"/>)
         * @return <xsl:value-of select="$paramComment"/>
         */

        <xsl:value-of select="$propertyType"/> WSF_CALL
        getProperty<xsl:value-of select="position()"/>();

    </xsl:for-each>

    <xsl:for-each select="memberType">
        <xsl:variable name="member_type"><xsl:value-of select="@type"/><xsl:if test="@ours">*</xsl:if></xsl:variable>
        <xsl:variable name="member_name"><xsl:text></xsl:text><xsl:value-of select="@originalName"/></xsl:variable>

        /**
         * Getter for <xsl:value-of select="$member_name"/>
         * @return <xsl:value-of select="$member_name"/> If it is the last set value
         */
        <xsl:value-of select="$member_type"/> WSF_CALL
        get<xsl:value-of select="$member_name"/>();

        /**
         * Setter for <xsl:value-of select="$member_name"/> 
         * @param memberType <xsl:value-of select="$member_name"/>
         * @return true on success, false otherwise
         */
        bool WSF_CALL
        set<xsl:value-of select="$member_name"/>(<xsl:value-of select="$member_type"/> memberType);

        /**
         * Check if the <xsl:value-of select="$member_name"/>  is valid
         * @return true if <xsl:value-of select="$member_name"/> is valid and false otherwise.
         */
        bool WSF_CALL
        isValid<xsl:value-of select="$member_name"/>();

    </xsl:for-each>

    <xsl:if test="$isUnion">
        /**
         * Reset any value inside the union, this will take the union to NULL state
         * @return true on success, false otherwise
         */
        bool WSF_CALL
        resetMembers();

        /**
         * Retrieve the current member type
         * @return Current member type as a string
         */
        std::string AXIS2_CALL
        currentMemberType();
    </xsl:if>

};

}        
 #endif /* <xsl:value-of select="$caps_axis2_name"/>_H */
    </xsl:template>
</xsl:stylesheet>
