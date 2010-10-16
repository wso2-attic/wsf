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

     <!-- cater for the multiple classes - wrappped mode - currently not well supported.-->
    <xsl:template match="/beans">
        <xsl:variable name="name"><xsl:value-of select="@name"/></xsl:variable>
        <xsl:variable name="axis2_name"><xsl:value-of select="@name"/></xsl:variable>
        /**
         * <xsl:value-of select="$axis2_name"/>.cpp
         *
         * This file was auto-generated from WSDL
         * by the Apache Axis2/Java version: #axisVersion# #today#
         */
         
        #include "<xsl:value-of select="$axis2_name"/>.h"
        
        <xsl:apply-templates/>
    </xsl:template>
    <!--cater for the multiple classes - unwrappped mode -->
    <xsl:template match="/">
        <xsl:apply-templates/>
    </xsl:template>

    <xsl:template match="class">
        <!-- Stores the name of a property  -->
        <xsl:variable name="name"><xsl:value-of select="@name"/></xsl:variable>
        <!-- another variable keeping track of the name -->
        <xsl:variable name="just_name"><xsl:value-of select="@name"/></xsl:variable>
        <xsl:variable name="axis2_name"><xsl:value-of select="@name"/></xsl:variable>
        <xsl:variable name="istype"><xsl:value-of select="@type"/></xsl:variable>

        <xsl:variable name="originalName"><xsl:value-of select="@originalName"/></xsl:variable>
        <xsl:variable name="nsuri"><xsl:value-of select="@nsuri"/></xsl:variable>
        <xsl:variable name="nsprefix"><xsl:value-of select="@nsprefix"/></xsl:variable>
        <xsl:variable name="anon"><xsl:value-of select="@anon"/></xsl:variable>
        <xsl:variable name="ordered"><xsl:value-of select="@ordered"/></xsl:variable>
        <xsl:variable name="particleClass"><xsl:value-of select="@particleClass"/></xsl:variable> <!-- particle classes are used to represent schema groups -->
        <xsl:variable name="hasParticleType"><xsl:value-of select="@hasParticleType"/></xsl:variable> <!-- particle classes are used to represent schema groups -->
       
        <xsl:variable name="simple"><xsl:value-of select="@simple"/></xsl:variable>
        <xsl:variable name="choice"><xsl:value-of select="@choice"/></xsl:variable>

        <!-- Check if this type is a supported enum -->
        <xsl:variable name="isEnum">
          <xsl:choose>
            <xsl:when test="count(property)=1 and property/enumFacet and property/@type='std::string'">1</xsl:when>
            <xsl:otherwise>0</xsl:otherwise>
          </xsl:choose>
        </xsl:variable>
        <xsl:variable name="CPPNamespace">
        <xsl:choose>
            <xsl:when test="@cppNamespace">
                <xsl:value-of select="@cppNamespace"/><xsl:text>::</xsl:text>
            </xsl:when>
            <xsl:otherwise></xsl:otherwise>
        </xsl:choose>
        </xsl:variable>
        <xsl:variable name="CPPNamespaceFilePrefix">
        <xsl:choose>
            <xsl:when test="@cppNamespace">
                <xsl:value-of select="@cppNamespace"/><xsl:text>_</xsl:text>
            </xsl:when>
            <xsl:otherwise></xsl:otherwise>
        </xsl:choose>
        </xsl:variable>

        <!-- checking for is union -->
        <xsl:variable name="isUnion" select="@union"/>

        /**
         * <xsl:value-of select="$axis2_name"/>.cpp
         *
         * This file was auto-generated from WSDL
         * by the Apache Axis2/C version: SNAPSHOT  Built on : Mar 10, 2008 (08:35:52 GMT+00:00)
         */
        <xsl:choose>
          <xsl:when test="@enableNS2P">
            #include "<xsl:value-of select="$CPPNamespaceFilePrefix"/><xsl:value-of select="$axis2_name"/>.h"
          </xsl:when>
          <xsl:otherwise>
            #include "<xsl:value-of select="$axis2_name"/>.h"
          </xsl:otherwise>
        </xsl:choose>
        
        #include &lt;Environment.h&gt;
        #include &lt;WSFError.h&gt;


        using namespace wso2wsf;
        using namespace std;
        <xsl:if test="@cppNamespace">
        using namespace <xsl:value-of select="@cppNamespace"/>;
        </xsl:if>


        <xsl:choose>
            <xsl:when test="$istype">
                /*
                 * This type was generated from the piece of schema that had
                 * name = <xsl:value-of select="$originalName"/>
                 * Namespace URI = <xsl:value-of select="$nsuri"/>
                 * Namespace Prefix = <xsl:value-of select="$nsprefix"/>
                 */
           </xsl:when>
           <xsl:otherwise>
               /*
                * Implementation of the <xsl:value-of select="$originalName"/><xsl:if test="$nsuri">|<xsl:value-of select="$nsuri"/></xsl:if> Element
                */
           </xsl:otherwise>
        </xsl:choose>


        <xsl:value-of select="$CPPNamespace"/><xsl:value-of select="$axis2_name"/>::<xsl:value-of select="$axis2_name"/>()
        {

        <xsl:if test="not($istype)">
            qname = NULL;
        </xsl:if>

        <xsl:for-each select="property">
            <xsl:variable name="CName"><xsl:value-of select="@cname"></xsl:value-of></xsl:variable>
            <xsl:choose>
              <xsl:when test="@isarray or @ours or @type='axutil_qname_t*' or @type='axutil_duration_t*' or @type='axutil_uri_t*' or @type='axutil_date_time_t*' or @type='axutil_base64_binary_t*'">
                property_<xsl:value-of select="$CName"/>  = NULL;
              </xsl:when>
                <xsl:when test="@type='std::string'">
                    property_<xsl:value-of select="$CName"/>;
                </xsl:when>
              <!-- todo for others -->
            </xsl:choose>
            isValid<xsl:value-of select="$CName"/>  = false;
        </xsl:for-each>

            <xsl:if test="not($istype)">
              <xsl:choose>
                <xsl:when test="$nsuri and $nsuri != ''">
                  qname =  axutil_qname_create (Environment::getEnv(),
                        "<xsl:value-of select="$originalName"/>",
                        "<xsl:value-of select="$nsuri"/>",
                        NULL);
                </xsl:when>
                <xsl:otherwise>
        qname =  axutil_qname_create (Environment::getEnv(),"<xsl:value-of select="$originalName"/>", NULL, NULL);
                </xsl:otherwise>
              </xsl:choose>
            </xsl:if>

            <xsl:if test="$choice">
                currentChoice = "";
            </xsl:if>
            <xsl:if test="$isUnion">
                currentValue = "";
            </xsl:if>
        }

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

        <!-- the following two functions was added in support of the unwrapped mode -->
       <xsl:if test="count(property) > 0">
        <xsl:value-of select="$CPPNamespace"/><xsl:value-of select="$axis2_name"/>::<xsl:value-of select="$axis2_name"/>(<xsl:value-of select="$arg_list"/>)
        {
             <xsl:if test="not($istype)">
                   qname = NULL;
             </xsl:if>

            <xsl:for-each select="property">
            <xsl:variable name="CName"><xsl:value-of select="@cname"></xsl:value-of></xsl:variable>
            <xsl:choose>
             <xsl:when test="@isarray or @ours or @type='axutil_qname_t*' or @type='axutil_duration_t*' or @type='axutil_uri_t*' or @type='axutil_date_time_t*' or @type='axutil_base64_binary_t*'">
               property_<xsl:value-of select="$CName"/>  = NULL;
             </xsl:when>
             <xsl:when test="@type='std::string'">
                 property_<xsl:value-of select="$CName"/>;
             </xsl:when>
             <!-- todo for others -->
            </xsl:choose>
            isValid<xsl:value-of select="$CName"/>  = true;
            </xsl:for-each>

           <xsl:if test="not($istype)">
             <xsl:choose>
               <xsl:when test="$nsuri and $nsuri != ''">
                 qname =  axutil_qname_create (Environment::getEnv(),
                       "<xsl:value-of select="$originalName"/>",
                       "<xsl:value-of select="$nsuri"/>",
                       NULL);
               </xsl:when>
               <xsl:otherwise>
                qname =  axutil_qname_create (Environment::getEnv(),"<xsl:value-of select="$originalName"/>", NULL, NULL);
               </xsl:otherwise>
             </xsl:choose>
           </xsl:if>

           <xsl:if test="$choice">
               currentChoice = "";
           </xsl:if>
           <xsl:if test="$isUnion">
               currentValue = "";
           </xsl:if>


            <xsl:for-each select="property">
              <xsl:variable name="CName"><xsl:value-of select="@cname"></xsl:value-of></xsl:variable>
                    property_<xsl:value-of select="@cname"/> = arg_<xsl:value-of select="$CName"/>;
            </xsl:for-each>

            <xsl:if test="@isUnion">
            /* this function is not implemented for union types */
            </xsl:if>
        }
        </xsl:if>
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
                <xsl:variable name="CName"><xsl:value-of select="$firstProperty/@cname"></xsl:value-of></xsl:variable>

                <xsl:value-of select="$propertyType"/> WSF_CALL
                <xsl:value-of select="$axis2_name"/>_free_popping_value(
                        <xsl:value-of select="$axis2_name"/>_t*<xsl:text> </xsl:text><xsl:value-of select="$name"/>,
                        const axutil_env_t *env)
                {
                    <xsl:value-of select="$propertyType"/> value;

                    <xsl:if test="@isUnion">
                    /* this function is not completely implemented for union types */
                    </xsl:if>
                    
                    value = <xsl:value-of select="$name"/>->property_<xsl:value-of select="$CName"/>;

                    <xsl:if test="$firstProperty/@ours or $firstProperty/@isarray or $propertyType='axis2_char_t*' or $propertyType='axutil_qname_t*' or $propertyType='axutil_duration_t*' or $propertyType='axutil_uri_t*' or $propertyType='axutil_date_time_t*' or $propertyType='axutil_base64_binary_t*'">
                      <xsl:value-of select="$name"/>->property_<xsl:value-of select="$CName"/> = (<xsl:value-of select="$propertyType"/>)NULL;
                    </xsl:if>
                    <xsl:value-of select="$axis2_name"/>_free(<xsl:value-of select="$name"/>, env);

                    return value;
                }
            </xsl:when>
            <xsl:otherwise>
                void* WSF_CALL
                <xsl:value-of select="$axis2_name"/>_free_popping_value(
                        <xsl:value-of select="$axis2_name"/>_t*<xsl:text> </xsl:text><xsl:value-of select="$name"/>,
                        const axutil_env_t *env)
                {
                    <xsl:value-of select="$axis2_name"/>_free(<xsl:value-of select="$name"/>, env);
                    return NULL;
                }
            </xsl:otherwise>

        </xsl:choose>

        bool WSF_CALL
        <xsl:value-of select="$axis2_name"/>_free(
                <xsl:value-of select="$axis2_name"/>_t*<xsl:text> </xsl:text><xsl:value-of select="$name"/>,
                const axutil_env_t *env)
        {
            <xsl:if test="property/@isarray">
                int i = 0;
                int count = 0;
                void *element = NULL;
            </xsl:if>

            AXIS2_PARAM_CHECK(Environment::getEnv()->error, <xsl:value-of select="$name"/>, AXIS2_FAILURE);

            <xsl:for-each select="property">
                <xsl:variable name="CName"><xsl:value-of select="@cname"></xsl:value-of></xsl:variable>
                <xsl:value-of select="$axis2_name"/>_reset_<xsl:value-of select="$CName"/>(<xsl:value-of select="$name"/>, Environment::getEnv());
            </xsl:for-each>


            <xsl:for-each select="itemtype">
                <xsl:variable name="CName"><xsl:value-of select="$just_name"></xsl:value-of></xsl:variable>
                <xsl:value-of select="$axis2_name"/>_reset_<xsl:value-of select="$CName"/>(<xsl:value-of select="$name"/>, Environment::getEnv());
            </xsl:for-each>

            <xsl:if test="$isUnion">
            <xsl:value-of select="$axis2_name"/>_reset_members(<xsl:value-of select="$name"/>, Environment::getEnv());
            </xsl:if>

            <xsl:if test="not(@type)">
              if(<xsl:value-of select="$name"/>->qname)
              {
                  axutil_qname_free (<xsl:value-of select="$name"/>->qname, Environment::getEnv());
                  <xsl:value-of select="$name"/>->qname = NULL;
              }
            </xsl:if>

            if(<xsl:value-of select="$name"/>)
            {
                AXIS2_FREE(Environment::getEnv()->allocator, <xsl:value-of select="$name"/>);
                <xsl:value-of select="$name"/> = NULL;
            }

            return AXIS2_SUCCESS;
        }
       -->

        <xsl:value-of select="$CPPNamespace"/><xsl:value-of select="$axis2_name"/>::~<xsl:value-of select="$axis2_name"/>()
        {
            resetAll();
        }

        bool WSF_CALL <xsl:value-of select="$CPPNamespace"/><xsl:value-of select="$axis2_name"/>::resetAll()
        {
            //calls reset method for all the properties owned by this method which are pointers.

            <xsl:for-each select="property">
            <xsl:variable name="CName"><xsl:value-of select="@cname"></xsl:value-of></xsl:variable>
            <xsl:choose>
             <xsl:when test="@isarray or @ours or @type='axutil_qname_t*' or @type='axutil_duration_t*' or @type='axutil_uri_t*' or @type='axutil_date_time_t*' or @type='axutil_base64_binary_t*'">
             reset<xsl:value-of select="$CName"/>();//<xsl:value-of select="@type"/>
             </xsl:when>
            </xsl:choose>
            </xsl:for-each>


        <xsl:if test="not($istype)">
          if(qname != NULL)
          {
            axutil_qname_free( qname, Environment::getEnv());
            qname = NULL;
          }
        </xsl:if>
            return true;

        }

        <xsl:if test="@simple">
            bool WSF_CALL
            <xsl:value-of select="$axis2_name"/>::deserializeFromString(
                                            const axis2_char_t *node_value,
                                            axiom_node_t *parent)
            {
              bool status = true;
            <xsl:if test="property/@type='axutil_qname_t*' or itemtype/@type='axutil_qname_t*'">
              const axis2_char_t *cp_ro = NULL;
              bool prefix_found = false;
              axiom_namespace_t *qname_ns;
            </xsl:if>

            <xsl:if test="itemtype">
               int i;
               axis2_char_t *token_value = NULL;
               axis2_char_t *original_node_value = NULL;
               axis2_char_t *dupd_node_value = NULL;
               bool the_last_token = false;
            </xsl:if>

              <xsl:for-each select="property"> <!-- only one property would be in a simpletype -->
                <xsl:if test="position()=1"> <!-- just to make sure it doesn't go for more than one time -->
                  <xsl:variable name="propertyType">
                     <xsl:choose>
                       <xsl:when test="@isarray">std::vector&lt;<xsl:value-of select="@type"/><xsl:if test="@ours or @type='std::string' or @type='unsigned char' or @type='unsigned short' or @type='uint64_t' or @type='unsigned int' or @type='short' or @type='char' or @type='int' or @type='float' or @type='double' or @type='int64_t'"><xsl:text>*</xsl:text></xsl:if>&gt;*</xsl:when>
                       <xsl:when test="not(@type)">wso2wsf::OMElement*</xsl:when> <!-- these are anonymous -->
                       <xsl:otherwise><xsl:value-of select="@type"/><xsl:if test="@ours">*</xsl:if></xsl:otherwise>
                     </xsl:choose>
                  </xsl:variable>
                  <xsl:variable name="nativePropertyType"> <!--these are used in arrays to take the native type-->
                     <xsl:choose>
                       <xsl:when test="not(@type)">wso2wsf::OMElement*</xsl:when> <!-- these are anonymous -->
                       <xsl:otherwise><xsl:value-of select="@type"/></xsl:otherwise>
                     </xsl:choose>
                  </xsl:variable>
                  <xsl:variable name="propertyName"><xsl:value-of select="@name"></xsl:value-of></xsl:variable>
                  <xsl:variable name="CName"><xsl:value-of select="@cname"></xsl:value-of></xsl:variable>

                  <!-- here only simple types possible -->
                  <xsl:choose>
                    <!-- add int s -->
                    <xsl:when test="$nativePropertyType='int' or $nativePropertyType='unsigned int'">
                        set<xsl:value-of select="$CName"/>(atoi(node_value));
                    </xsl:when>

                    <!-- add axis2_char_t s -->
                    <xsl:when test="$nativePropertyType='char' or $nativePropertyType='unsigned char'">
                       set<xsl:value-of select="$CName"/>((char)(*node_value)); <!-- This should be checked -->
                    </xsl:when>

                    <!-- add short s -->
                    <xsl:when test="$nativePropertyType='short' or $nativePropertyType='unsigned short'">
                       set<xsl:value-of select="$CName"/>(atoi(node_value));
                    </xsl:when>

                    <!-- add int64_t s -->
                    <xsl:when test="$nativePropertyType='int64_t'">
                       set<xsl:value-of select="$CName"/>(axutil_strtol(node_value, (char**)NULL, 0));
                    </xsl:when>
                    <xsl:when test="$nativePropertyType='uint64_t'">
                       set<xsl:value-of select="$CName"/>(axutil_strtoul(node_value, (char**)NULL, 0));
                    </xsl:when>

                    <!-- add float s -->
                    <xsl:when test="$nativePropertyType='float'">
                       set<xsl:value-of select="$CName"/>(atof(node_value));
                    </xsl:when>
                    <!-- add double s -->
                    <xsl:when test="$nativePropertyType='double'">
                       set<xsl:value-of select="$CName"/>(atof(node_value));
                    </xsl:when>

                    <!-- add axis2_char_t s -->
                    <xsl:when test="$nativePropertyType='std::string'">
                        set<xsl:value-of select="$CName"/>(node_value);
                    </xsl:when>

                    <!-- add axutil_qname_t s -->
                    <xsl:when test="$nativePropertyType='axutil_qname_t*'">

                        prefix_found = false;
                        for(cp_ro = node_value; *cp_ro; cp_ro ++)
                        {
                            if(*cp_ro == ':')
                            {
                                cp_ro ++;
                                prefix_found  = true;
                                break;
                            }
                        }

                        if(prefix_found)
                        {
                            /* node value contain the prefix */
                            char *prefix_value = AXIS2_MALLOC(env->allocator, (cp_ro - node_value - 1) + 1);
                            strncpy(prefix, node_value, (cp_ro - node_value - 1));
                            prefix[cp_ro - node_value - 1] = '\0';
                            qname_ns = axiom_element_find_namespace_uri((axiom_element_t*)axiom_node_get_data_element(parent, Environment::getEnv()), Environment::getEnv(), prefix_value, parent);
                            AXIS2_FREE(Environment::getEnv()->allocator, prefix_value);
                        }
                        else
                        {
                            /* Then it is the default namespace */
                            cp_ro = node_value;
                            qname_ns = axiom_element_get_default_namespace((axiom_element_t*)axiom_node_get_data_element(parent, Environment::getEnv()), Environment::getEnv(), parent);
                        }

                         <!-- we are done extracting info, just set the extracted value to the qname -->

                         set<xsl:value-of select="$CName"/>(
                                                        axutil_qname_create(
                                                              Environment::getEnv(),
                                                              cp_ro, /* cp contain the localname */
                                                              axiom_namespace_get_uri(qname_ns, Environment::getEnv()),
                                                              axiom_namespace_get_prefix(qname_ns, Environment::getEnv())));
                      </xsl:when>



                    <!-- add axutil_uri_t s -->
                    <xsl:when test="$nativePropertyType='axutil_uri_t*'">
                       set<xsl:value-of select="$CName"/>(axutil_uri_parse_string(Environment::getEnv(), node_value));
                    </xsl:when>

                    <!-- add axutil_duration_t s -->
                    <xsl:when test="$nativePropertyType='axutil_duration_t*'">
                       set<xsl:value-of select="$CName"/>(axutil_duration_create_from_string(Environment::getEnv(), node_value));
                    </xsl:when>

                    <!-- add bool s -->
                    <xsl:when test="$nativePropertyType='bool'">
                       if (!axutil_strcmp(node_value, "TRUE") || !axutil_strcmp(node_value, "true"))
                       {
                           set<xsl:value-of select="$CName"/>(true);
                       }
                       else
                       {
                           set<xsl:value-of select="$CName"/>(false);
                       }
                    </xsl:when>
                    <!-- add axis2_byte_t s -->
                    <xsl:when test="$nativePropertyType='axis2_byte_t' or $nativePropertyType='axis2_unsigned_byte_t'">
                       set<xsl:value-of select="$CName"/>(atoi(node_value));
                    </xsl:when>
                    <!-- add date_time_t* s -->
                    <xsl:when test="$nativePropertyType='axutil_date_time_t*'">
                       axutil_date_time_t* element = axutil_date_time_create(Environment::getEnv());
                       axutil_date_time_deserialize_date_time(element, Environment::getEnv(), node_value);
                       set<xsl:value-of select="$CName"/>(element);
                    </xsl:when>
                    <!-- add hex_binary_t* s -->
                    <xsl:when test="$nativePropertyType='axutil_base64_binary_t*'">
                       axutil_base64_binary_t* element = axutil_base64_binary_create(Environment::getEnv());
                       axutil_base64_binary_set_encoded_binary(element, Environment::getEnv(), node_value);
                       set<xsl:value-of select="$CName"/>(element);
                    </xsl:when>
                    <xsl:when test="@ours">
                      <xsl:value-of select="$nativePropertyType"/>* element =  new <xsl:value-of select="$nativePropertyType"/>();
                      element->deserializeFromString(attrib_text, parent);
                      set<xsl:value-of select="$CName"/>(element);
                    </xsl:when>
                    <xsl:otherwise>
                       <!--TODO: add new attributes types -->
                       /* can not handle the attribute type <xsl:value-of select="$nativePropertyType"/>*/
                       status = false;
                    </xsl:otherwise>
                  </xsl:choose>
                </xsl:if>
              </xsl:for-each>

            <!-- The section covers the list types, this is a loop always occurs just 1 time-->
            <xsl:for-each select="itemtype">
                <xsl:variable name="propertyType">std::vector&lt;<xsl:value-of select="@type"/><xsl:if test="@ours or @type='std::string' or @type='unsigned char' or @type='unsigned short' or @type='uint64_t' or @type='unsigned int' or @type='short' or @type='char' or @type='int' or @type='float' or @type='double' or @type='int64_t'"><xsl:text>*</xsl:text></xsl:if>&gt;*</xsl:variable>
                <xsl:variable name="propertyName"><xsl:value-of select="$just_name"></xsl:value-of></xsl:variable>
                <xsl:variable name="CName"><xsl:value-of select="$just_name"></xsl:value-of></xsl:variable>

                <xsl:variable name="nativePropertyType"> <!--these are used in arrays to take the native type-->
                   <xsl:choose>
                     <xsl:when test="not(@type)">wso2wsf::OMElement*</xsl:when> <!-- these are anonymous -->
                     <xsl:otherwise><xsl:value-of select="@type"/></xsl:otherwise>
                   </xsl:choose>
                </xsl:variable>
                  <xsl:variable name="PropertyTypeArrayParam"> <!--these are used in arrays to take the type stored in the arraylist-->
                     <xsl:choose>
                       <xsl:when test="not(@type)">wso2wsf::OMElement*</xsl:when> <!-- these are anonymous -->
                       <xsl:when test="@type='unsigned char' or @type='unsigned short' or @type='uint64_t' or @type='unsigned int' or @type='short' or @type='char' or @type='int' or @type='float' or @type='double' or @type='int64_t'"><xsl:value-of select="@type"/></xsl:when>
                       <xsl:otherwise><xsl:value-of select="@type"/><xsl:if test="@ours"><xsl:text>*</xsl:text></xsl:if></xsl:otherwise>
                     </xsl:choose>
                  </xsl:variable>

                <xsl:variable name="propertyInstanceName">element</xsl:variable>
                <xsl:variable name="justPropertyInstanceName">element</xsl:variable>

                /* just to make sure we are not altering the original */
                dupd_node_value = original_node_value = (axis2_char_t*)axutil_strdup(Environment::getEnv(), node_value);

                for(token_value = dupd_node_value, the_last_token = false; !the_last_token; dupd_node_value ++)
                {
                    if(*dupd_node_value == ' ' || *dupd_node_value == '\t' || *dupd_node_value == '\r'
                            || *dupd_node_value == '\n' || *dupd_node_value == '\0')
                    {
                        if(*dupd_node_value == '\0')
                        {
                            the_last_token = true;
                        }
                        else
                        {
                            *dupd_node_value = '\0';
                        }


                <xsl:choose>
                  <!-- add int s -->
                  <xsl:when test="$nativePropertyType='int' or $nativePropertyType='unsigned int'">
                     add<xsl:value-of select="$CName"/>(atoi(token_value));
                  </xsl:when>

                  <!-- add axis2_char_t s -->
                  <xsl:when test="$nativePropertyType='char' or $nativePropertyType='unsigned char'">
                     add<xsl:value-of select="$CName"/>((char)(*token_value)); <!-- This should be checked -->
                  </xsl:when>

                  <!-- add short s -->
                  <xsl:when test="$nativePropertyType='short' or $nativePropertyType='unsigned short'">
                     add<xsl:value-of select="$CName"/>(atoi(token_value));
                  </xsl:when>

                  <!-- add int64_t s -->
                  <xsl:when test="$nativePropertyType='int64_t'">
                     add<xsl:value-of select="$CName"/>(axutil_strtol(token_value, (char**)NULL, 0));
                  </xsl:when>
                  <xsl:when test="$nativePropertyType='uint64_t'">
                     add<xsl:value-of select="$CName"/>(axutil_strtoul(token_value, (char**)NULL, 0));
                  </xsl:when>

                  <!-- add float s -->
                  <xsl:when test="$nativePropertyType='float'">
                     add<xsl:value-of select="$CName"/>(atof(token_value));
                  </xsl:when>
                  <!-- add double s -->
                  <xsl:when test="$nativePropertyType='double'">
                     add<xsl:value-of select="$CName"/>(atof(token_value));
                  </xsl:when>

                  <!-- add axis2_char_t s -->
                  <xsl:when test="$nativePropertyType='std::string'">
                     add<xsl:value-of select="$CName"/>(token_value);
                  </xsl:when>

                  <!-- add axutil_qname_t s -->
                  <xsl:when test="$nativePropertyType='axutil_qname_t*'">

                    prefix_found = false;
                    for(cp = token_value; *cp; cp ++)
                    {
                        if(*cp == ':')
                        {
                            *cp = '\0';
                            cp ++;
                            prefix_found  = true;
                            break;
                        }
                    }

                    if(prefix_found)
                    {
                        /* node value contain the prefix */
                        qname_ns = axiom_element_find_namespace_uri((axiom_element_t*)axiom_node_get_data_element(parent, Environment::getEnv()), Environment::getEnv(), token_value, parent);
                    }
                    else
                    {
                        /* Then it is the default namespace */
                        cp = token_value;
                        qname_ns = axiom_element_get_default_namespace((axiom_element_t*)axiom_node_get_data_element(parent, Environment::getEnv()), Environment::getEnv(), parent);
                    }

                     <!-- we are done extracting info, just set the extracted value to the qname -->

                     add<xsl:value-of select="$CName"/>(axutil_qname_create(
                                                          Environment::getEnv(),
                                                          cp, /* cp contain the localname */
                                                          axiom_namespace_get_uri(qname_ns, Environment::getEnv()),
                                                          axiom_namespace_get_prefix(qname_ns, Environment::getEnv())));
                  </xsl:when>

                 <!-- add axutil_uri_t s -->
                  <xsl:when test="$nativePropertyType='axutil_uri_t*'">
                     add<xsl:value-of select="$CName"/>(axutil_uri_parse_string(Environment::getEnv(), token_value));
                  </xsl:when>

                  <!-- add axutil_duration_t s -->
                  <xsl:when test="$nativePropertyType='axutil_duration_t*'">
                     add<xsl:value-of select="$CName"/>(axutil_duration_create_from_string(Environment::getEnv(), token_value));
                  </xsl:when>

                  <!-- add bool s -->
                  <xsl:when test="$nativePropertyType='bool'">
                     if (!axutil_strcmp(token_value, "TRUE") || !axutil_strcmp(token_value, "true"))
                     {
                         add<xsl:value-of select="$CName"/>(true);
                     }
                     else
                     {
                         add<xsl:value-of select="$CName"/>(false);
                     }
                  </xsl:when>
                  <!-- add axis2_byte_t s -->
                  <xsl:when test="$nativePropertyType='axis2_byte_t' or $nativePropertyType='axis2_unsigned_byte_t'">
                     add<xsl:value-of select="$CName"/>(atoi(token_value));
                  </xsl:when>
                  <!-- add date_time_t* s -->
                  <xsl:when test="$nativePropertyType='axutil_date_time_t*'">
                     axutil_date_time_t* element = axutil_date_time_create(Environment::getEnv());
                     axutil_date_time_deserialize_date_time(element, Environment::getEnv(), token_value);
                     add<xsl:value-of select="$CName"/>(element);
                  </xsl:when>
                  <!-- add hex_binary_t* s -->
                  <xsl:when test="$nativePropertyType='axutil_base64_binary_t*'">
                     axutil_base64_binary_t* element = axutil_base64_binary_create(Environment::getEnv());
                     axutil_base64_binary_set_encoded_binary(element, Environment::getEnv(), token_value);
                     add<xsl:value-of select="$CName"/>(element);
                  </xsl:when>
                  <xsl:when test="@ours">
                      <xsl:value-of select="$nativePropertyType"/>* element =  new <xsl:value-of select="$nativePropertyType"/>();
                      element->deserializeFromString(attrib_text, parent);
                      set<xsl:value-of select="$CName"/>(element);
                  </xsl:when>
                  <xsl:otherwise>
                     <!--TODO: add new attributes types -->
                     /* can not handle the attribute type <xsl:value-of select="$nativePropertyType"/>*/
                     status = true;
                  </xsl:otherwise>
                </xsl:choose>
                    token_value = dupd_node_value + 1;
                  }
              }
              AXIS2_FREE(Environment::getEnv()->allocator, original_node_value);

             </xsl:for-each>

             <xsl:if test="$isUnion">

               /*
                * axis2_qname_t *qname = NULL;
                * axiom_attribute_t *the_attri = NULL;
                *
                * qname = axutil_qname_create(Environment::getEnv(), "type", "http://www.w3.org/2001/XMLSchema-instance", "xsi");
                * the_attri = axiom_element_get_attribute(current_element, Environment::getEnv(), qname);
                */
               /* currently thereis a bug in the axiom_element_get_attribute, so we have to go to this bad method */

               axiom_attribute_t *the_attri = NULL;
               axis2_char_t *attrib_text = NULL;
               axutil_hash_t *attribute_hash = NULL;
               void *element = NULL;
               axiom_element_t *current_element = NULL;

               current_element = (axiom_element_t*)axiom_node_get_data_element(parent, Environment::getEnv());

               attribute_hash = axiom_element_get_all_attributes(current_element, Environment::getEnv());

               attrib_text = NULL;
               if(attribute_hash)
               {
                    axutil_hash_index_t *hi;
                    void *val;
                    const void *key;

                    for (hi = axutil_hash_first(attribute_hash, Environment::getEnv()); hi; hi = axutil_hash_next(Environment::getEnv(), hi))
                    {
                        axutil_hash_this(hi, &amp;key, NULL, &amp;val);

                        if(strstr((axis2_char_t*)key, "type|http://www.w3.org/2001/XMLSchema-instance"))
                        {
                            the_attri = (axiom_attribute_t*)val;
                            break;
                        }
                    }
               }

               if(the_attri)
               {
                   attrib_text = axiom_attribute_get_value(the_attri, Environment::getEnv());
               }
               else
               {
                   /* this is hoping that attribute is stored in "http://www.w3.org/2001/XMLSchema-instance", this happnes when name is in default namespace */
                   attrib_text = axiom_element_get_attribute_value_by_name(current_element, Environment::getEnv(), "type");
               }

               if(attrib_text)
               {
                    /* skipping the namespace prefix */
                    axis2_char_t *temp_attrib = NULL;
                    temp_attrib = strchr(attrib_text, ':');
                    if(temp_attrib)
                    {
                        /* take the string after the ':' character */
                        attrib_text = temp_attrib + 1;
                    }
               }

               if(!attrib_text) {
                    /* nothing is here, reset things */
                    status = resetMembers();
               }
             <xsl:for-each select="memberType">
                <xsl:variable name="member_type" select="@type"/>
                <xsl:variable name="member_name"><xsl:text></xsl:text><xsl:value-of select="@originalName"/></xsl:variable>
               else if(!axutil_strcmp(attrib_text, "<xsl:value-of select="@originalName"/>"))
               {

                <xsl:choose>
                  <!-- add int s -->
                  <xsl:when test="$member_type='int' or $member_type='unsigned int'">
                     set<xsl:value-of select="$member_name"/>(atoi(attrib_text));
                  </xsl:when>

                  <!-- add axis2_char_t s -->
                  <xsl:when test="$member_type='char' or $member_type='unsigned char'">
                     set<xsl:value-of select="$member_name"/>((char)(*attrib_text)); <!-- This should be checked -->
                  </xsl:when>

                  <!-- add short s -->
                  <xsl:when test="$member_type='short' or $member_type='unsigned short'">
                     set<xsl:value-of select="$member_name"/>(atoi(attrib_text));
                  </xsl:when>

                  <!-- add int64_t s -->
                  <xsl:when test="$member_type='int64_t'">
                     set<xsl:value-of select="$member_name"/>(axutil_strtol(attrib_text, (char**)NULL, 0));
                  </xsl:when>
                  <xsl:when test="$member_type='uint64_t'">
                     set<xsl:value-of select="$member_name"/>(axutil_strtoul(attrib_text, (char**)NULL, 0));
                  </xsl:when>

                  <!-- add float s -->
                  <xsl:when test="$member_type='float'">
                     set<xsl:value-of select="$member_name"/>(atof(attrib_text));
                  </xsl:when>
                  <!-- add double s -->
                  <xsl:when test="$member_type='double'">
                     set<xsl:value-of select="$member_name"/>(atof(attrib_text));
                  </xsl:when>

                  <!-- add axis2_char_t s -->
                  <xsl:when test="$member_type='std::string'">
                     set<xsl:value-of select="$member_name"/>(attrib_text);
                  </xsl:when>

                  <!-- add axutil_qname_t s -->
                  <xsl:when test="$member_type='axutil_qname_t*'">

                    prefix_found = false;
                    for(cp = attrib_text; *cp; cp ++)
                    {
                        if(*cp == ':')
                        {
                            *cp = '\0';
                            cp ++;
                            prefix_found  = true;
                            break;
                        }
                    }

                    if(prefix_found)
                    {
                        /* node value contain the prefix */
                        qname_ns = axiom_element_find_namespace_uri((axiom_element_t*)axiom_node_get_data_element(parent, Environment::getEnv()), Environment::getEnv(), attrib_text, parent);
                    }
                    else
                    {
                        /* Then it is the default namespace */
                        cp = attrib_text;
                        qname_ns = axiom_element_get_default_namespace((axiom_element_t*)axiom_node_get_data_element(parent, Environment::getEnv()), Environment::getEnv(), parent);
                    }

                     <!-- we are done extracting info, just set the extracted value to the qname -->

                     set<xsl:value-of select="$member_name"/>(
                                                    axutil_qname_create(
                                                          Environment::getEnv(),
                                                          cp, /* cp contain the localname */
                                                          axiom_namespace_get_uri(qname_ns, Environment::getEnv()),
                                                          axiom_namespace_get_prefix(qname_ns, Environment::getEnv())));
                  </xsl:when>

                 <!-- add axutil_uri_t s -->
                  <xsl:when test="$member_type='axutil_uri_t*'">
                     set<xsl:value-of select="$member_name"/>(axutil_uri_parse_string(Environment::getEnv(), attrib_text));
                  </xsl:when>

                  <!-- add axutil_duration_t s -->
                  <xsl:when test="$member_type='axutil_duration_t*'">
                     set<xsl:value-of select="$member_name"/>(axutil_duration_create_from_string(Environment::getEnv(), attrib_text));
                  </xsl:when>

                  <!-- add bool s -->
                  <xsl:when test="$member_type='bool'">
                     if (!axutil_strcmp(attrib_text, "TRUE") || !axutil_strcmp(token_value, "true"))
                     {
                         set<xsl:value-of select="$member_name"/>(true);
                     }
                     else
                     {
                         set<xsl:value-of select="$member_name"/>(false);
                     }
                  </xsl:when>
                  <!-- add axis2_byte_t s -->
                  <xsl:when test="$member_type='axis2_byte_t' or $member_type='axis2_unsigned_byte_t'">
                     set<xsl:value-of select="$member_name"/>(atoi(attrib_text));
                  </xsl:when>
                  <!-- add date_time_t* s -->
                  <xsl:when test="$member_type='axutil_date_time_t*'">
                     axutil_date_time_t* element = axutil_date_time_create(Environment::getEnv());
                     axutil_date_time_deserialize_date_time(element, Environment::getEnv(), attrib_text);
                     set<xsl:value-of select="$member_name"/>(element);
                  </xsl:when>
                  <!-- add hex_binary_t* s -->
                  <xsl:when test="$member_type='axutil_base64_binary_t*'">
                     axutil_base64_binary_t* element = axutil_base64_binary_create(Environment::getEnv());
                     axutil_base64_binary_set_encoded_binary(element, Environment::getEnv(), attrib_text);
                     set<xsl:value-of select="$member_name"/>(element);
                  </xsl:when>
                  <xsl:when test="@ours">
                      <xsl:value-of select="$member_type"/> *element =new <xsl:value-of select="$member_type"/>();
                      element->deserializeFromString(attrib_text, parent);
                      set<xsl:value-of select="$member_name"/>(element);
                  </xsl:when>
                  <xsl:otherwise>
                     <!--TODO: add new attributes types -->
                     /* can not handle the attribute type <xsl:value-of select="$member_type"/>*/
                     status = false;
                  </xsl:otherwise>
                </xsl:choose>

               }
             </xsl:for-each>
             </xsl:if>
              return status;
            }
        </xsl:if>

        bool WSF_CALL
        <xsl:value-of select="$CPPNamespace"/><xsl:value-of select="$axis2_name"/>::deserialize(axiom_node_t** dp_parent,bool *dp_is_early_node_valid, bool dont_care_minoccurs)
        {
          axiom_node_t *parent = *dp_parent;
          
          bool status = AXIS2_SUCCESS;
          <xsl:if test="count(property[@attribute])!=0">
          axiom_attribute_t *parent_attri = NULL;
          axiom_element_t *parent_element = NULL;
          axis2_char_t *attrib_text = NULL;

          axutil_hash_t *attribute_hash = NULL;

          </xsl:if>
        <!--
          <xsl:if test="property/@ours or (property/@isarray and (property/@type='unsigned short' or property/@type='unsigned char' or property/@type='unsigned int' or property/@type='uint64_t' or property/@type='short' or property/@type='int' or property/@type='char' or property/@type='int64_t' or property/@type='float' or property/@type='axis2_unsigned_byte_t' or property/@type='axis2_byte_t' or property/@type='bool' or property/@type='double')) or property/@type='axutil_date_time_t*' or property/@type='axutil_base64_binary_t*'">
              <xsl:value-of select="property/@type"/><xsl:if test="property/@ours">*</xsl:if> element;
              
          </xsl:if>
          <xsl:if test="property/@ours or property/@type='axutil_date_time_t*' or property/@type='axutil_base64_binary_t*'">
                      void *element = NULL;
          </xsl:if>

          <xsl:if test="property/@isarray and (property/@type='unsigned short' or property/@type='unsigned char' or property/@type='unsigned int' or property/@type='uint64_t' or property/@type='short' or property/@type='int' or property/@type='char' or property/@type='int64_t' or property/@type='float' or property/@type='axis2_unsigned_byte_t' or property/@type='axis2_byte_t' or property/@type='bool' or property/@type='double')">
              <xsl:value-of select="property/@type"/><xsl:if test="property/@ours">*</xsl:if> element;
          </xsl:if>
          -->

          <!-- these two are requried -->
          <xsl:if test="count(property)!=0  or count(itemtype)!=0 or $isUnion"> <!-- check for at least one element exists -->
         const axis2_char_t* text_value = NULL;
         axutil_qname_t *mqname = NULL;
          </xsl:if>

          <!-- qname specifc values -->
            <xsl:if test="property/@type='axutil_qname_t*'">
         axis2_char_t *cp = NULL;
          bool prefix_found = false;
          axiom_namespace_t *qname_ns;
          </xsl:if>

        <xsl:choose>
            <xsl:when test="@simple and (count(property)!=0 or count(itemtype)!=0 or $isUnion)">
            
        status = AXIS2_FAILURE;
        if(parent)
        {
            axis2_char_t *attrib_text = NULL;
            attrib_text = axiom_element_get_attribute_value_by_name((axiom_element_t*)axiom_node_get_data_element(parent, Environment::getEnv()), Environment::getEnv(), "nil");
            if (attrib_text != NULL &amp;&amp; !axutil_strcasecmp(attrib_text, "true"))
            {
              <xsl:choose>
               <xsl:when test="not(@nillable)">
               /* but the wsdl says that, this is non nillable */
                WSF_LOG_ERROR_MSG(Environment::getEnv()->log, WSF_LOG_SI, "NULL value is set to a non nillable element <xsl:value-of select="$originalName"/>");
                status = AXIS2_FAILURE;
               </xsl:when>
               <xsl:otherwise>
                status = set<xsl:value-of select="$name"/>Nil();
               </xsl:otherwise>
              </xsl:choose>
            }
            else
            {
                axiom_node_t *text_node = NULL;
                text_node = axiom_node_get_first_child(parent, Environment::getEnv());
                axiom_text_t *text_element = NULL;
                if (text_node &amp;&amp;
                        axiom_node_get_node_type(text_node, Environment::getEnv()) == AXIOM_TEXT)
                    text_element = (axiom_text_t*)axiom_node_get_data_element(text_node, Environment::getEnv());
                text_value = "";
                if(text_element &amp;&amp; axiom_text_get_value(text_element, Environment::getEnv()))
                {
                    text_value = (axis2_char_t*)axiom_text_get_value(text_element, Environment::getEnv());
                }
                status = deserializeFromString(text_value, parent);
                }
            }
            </xsl:when>
            <xsl:otherwise>

            <xsl:if test="property/@isarray">
               int i = 0;
            </xsl:if>
            <xsl:if test="(@ordered or @choice) and property/@isarray">
               int sequence_broken = 0;
               axiom_node_t *tmp_node = NULL;
            </xsl:if>
            <xsl:variable name="element_qname_var_requred">
                  <xsl:for-each select="property">
                    <xsl:if test="(not(@attribute) and @isarray) or not($ordered)">
                        yes
                    </xsl:if>
                  </xsl:for-each>
            </xsl:variable>
            <xsl:if test="contains($element_qname_var_requred, 'yes')">
                 <!-- TODO axutil_qname_t *element_qname = NULL; -->
            </xsl:if>
            axutil_qname_t *element_qname = NULL; 
            <xsl:if test="count(property)!=0">
               axiom_node_t *first_node = NULL;
               bool is_early_node_valid = true;
               axiom_node_t *current_node = NULL;
               axiom_element_t *current_element = NULL;
            </xsl:if>

            <xsl:if test="property">
              <!-- We are expected to have NULL elements in particle classes -->
              <xsl:if test="not($particleClass)">
              <!-- Wait until AXIOM_ELEMENT -->
              while(parent &amp;&amp; axiom_node_get_node_type(parent, Environment::getEnv()) != AXIOM_ELEMENT)
              {
                  parent = axiom_node_get_next_sibling(parent, Environment::getEnv());
              }
              if (NULL == parent)
              {   <!--
                /* This should be checked before everything
                WSF_LOG_ERROR_MSG(Environment::getEnv()->log, WSF_LOG_SI,
                            "Failed in building adb object for <xsl:value-of select="$originalName"/> : "
                            "NULL element can not be passed to deserialize"); */
                    -->
                return AXIS2_FAILURE;
              }
              </xsl:if>
            </xsl:if>
            <xsl:for-each select="property">
              <xsl:if test="position()=1"> <!-- check for at least one element exists -->
                 <xsl:choose>
                    <xsl:when test="not($istype)">

                    current_element = (axiom_element_t *)axiom_node_get_data_element(parent, Environment::getEnv());
                    mqname = axiom_element_get_qname(current_element, Environment::getEnv(), parent);
                    if (axutil_qname_equals(mqname, Environment::getEnv(), this->qname)<xsl:if test="not($nsuri) or $nsuri=''"> || !axutil_strcmp("<xsl:value-of select="$originalName"/>", axiom_element_get_localname(current_element, Environment::getEnv()))</xsl:if>)
                    {
                        <xsl:choose>
                          <xsl:when test="$anon">
                          first_node = axiom_node_get_first_child(parent, Environment::getEnv());
                          </xsl:when>
                          <xsl:otherwise>
                          first_node = parent;
                          </xsl:otherwise>
                        </xsl:choose>
                    }
                    else
                    {
                        WSF_LOG_ERROR_MSG(Environment::getEnv()->log, WSF_LOG_SI,
                              "Failed in building adb object for <xsl:value-of select="$originalName"/> : "
                              "Expected %s but returned %s",
                              axutil_qname_to_string(qname, Environment::getEnv()),
                              axutil_qname_to_string(mqname, Environment::getEnv()));
                        <!-- TODO: ADB specific error should be defined and set here -->
                        return AXIS2_FAILURE;
                    }
                    </xsl:when>
                    <xsl:when test="$particleClass">
                         first_node = parent;
                    </xsl:when>
                    <xsl:otherwise>
                      <!-- for types, parent refers to the container element -->
                      first_node = axiom_node_get_first_child(parent, Environment::getEnv());
                      <!-- Let followers to check the situation
                      if(first_node == NULL)
                      {
                          WSF_LOG_ERROR_MSG(Environment::getEnv()->log, WSF_LOG_SI,
                                            "Failed in building adb object for <xsl:value-of select="$originalName"/> : "
                                            "It is expected to have a child element");
                          TODO: ADB specific error should be defined and set here 
                          return AXIS2_FAILURE; 
                      } 
                      -->
                    </xsl:otherwise>
                 </xsl:choose>
               </xsl:if>
            </xsl:for-each>
            
            </xsl:otherwise> <!--otherwise for @simple check -->
          </xsl:choose>

          <!-- attributes are common to simple types(when used in simple content) and other types -->
            <xsl:for-each select="property/@attribute">
              <xsl:if test="position()=1">
                 parent_element = (axiom_element_t *)axiom_node_get_data_element(parent, Environment::getEnv());
                 attribute_hash = axiom_element_get_all_attributes(parent_element, Environment::getEnv());
              </xsl:if>
            </xsl:for-each>

            <xsl:for-each select="property">
              <xsl:variable name="propertyType">
                 <xsl:choose>
                   <xsl:when test="@isarray">std::vector&lt;<xsl:value-of select="@type"/><xsl:if test="@ours or @type='std::string' or @type='unsigned char' or @type='unsigned short' or @type='uint64_t' or @type='unsigned int' or @type='short' or @type='char' or @type='int' or @type='float' or @type='double' or @type='int64_t'"><xsl:text>*</xsl:text></xsl:if>&gt;</xsl:when>
                   <xsl:when test="not(@type)">wso2wsf::OMElement*</xsl:when> <!-- these are anonymous -->
                   <xsl:otherwise><xsl:value-of select="@type"/><xsl:if test="@ours"><xsl:text>*</xsl:text></xsl:if></xsl:otherwise>
                 </xsl:choose>
              </xsl:variable>
              <xsl:variable name="nativePropertyType"> <!--these are used in arrays to take the native type-->
                 <xsl:choose>
                   <xsl:when test="not(@type)">wso2wsf::OMElement*</xsl:when> <!-- these are anonymous -->
                   <xsl:otherwise><xsl:value-of select="@type"/></xsl:otherwise>
                 </xsl:choose>
              </xsl:variable>
              <xsl:variable name="propertyName"><xsl:value-of select="@name"></xsl:value-of></xsl:variable>
              <xsl:variable name="CName"><xsl:value-of select="@cname"></xsl:value-of></xsl:variable>

              <xsl:variable name="propertyInstanceName"><!--these are used in arrays to take the native type-->
                 <xsl:choose>
                   <xsl:when test="@isarray">(<xsl:value-of select="$nativePropertyType"/>)element</xsl:when>
                   <xsl:otherwise>property_<xsl:value-of select="$CName"/></xsl:otherwise>
                 </xsl:choose>
              </xsl:variable>
              <xsl:variable name="justPropertyInstanceName"><!--these are used in arrays to take the native type-->
                 <xsl:choose>
                   <xsl:when test="@isarray">element</xsl:when>
                   <xsl:otherwise>property_<xsl:value-of select="$CName"/></xsl:otherwise>
                 </xsl:choose>
              </xsl:variable>
              <xsl:variable name="parentPropertyInstanceName">property_<xsl:value-of select="$CName"/></xsl:variable>
              <xsl:choose>
                <xsl:when test="@attribute">
                <!-- here we have two options, either it can be axiom_attribute_t* which happens in anyAttribute case -->
                <xsl:choose>
                <xsl:when test="$nativePropertyType='wso2wsf::OMAttribute*' and @isarray">
                  parent_attri = NULL;
                  attrib_text = NULL;
                  if(attribute_hash)
                  {
                       axutil_hash_index_t *hi;
                       void *val;
                       const void *key;
                       axis2_char_t *dup_key;


                       char *seperator = NULL;
                       axis2_char_t *uri = NULL;
                       axiom_namespace_t *ns = NULL;

                       axiom_attribute_t *new_attrib = NULL;

                       for (hi = axutil_hash_first(attribute_hash, Environment::getEnv()); hi; hi = axutil_hash_next(Environment::getEnv(), hi))
                       {
                           axutil_hash_this(hi, &amp;key, NULL, &amp;val);
                          
                           dup_key = (axis2_char_t*)axutil_strdup(Environment::getEnv(), key);
                           seperator = strstr(dup_key, "|");
                          
                           uri = NULL;
                           if(seperator) /* this means the attribute is qualified with a namespace */
                           {
                             *seperator = '\0';
                             seperator ++; /* represent the namespace */
                             uri = seperator;
                           }
                           <!--
                           ns  = axiom_namespace_create(Environment::getEnv(), uri, NULL);
                           parent_attri = (axiom_attribute_t*)val;
                           attrib_text = axiom_attribute_get_value(parent_attri, Environment::getEnv());

                           new_attrib = axiom_attribute_create(Environment::getEnv(), dup_key, attrib_text, ns);
                           add<xsl:value-of select="$CName"/>(new OMAttribute(new_attrib));
                           AXIS2_FREE(Environment::getEnv()->allocator, dup_key);
                           -->
                            wso2wsf::OMNamespace *ns1  = new wso2wsf::OMNamespace(uri);
                            parent_attri = (axiom_attribute_t*)val;
                            attrib_text = axiom_attribute_get_value(parent_attri, Environment::getEnv());

                            wso2wsf::OMAttribute *new_attrib1 = new wso2wsf::OMAttribute( dup_key, attrib_text, ns1);
                            add<xsl:value-of select="$CName"/>(new_attrib1);
                            AXIS2_FREE(Environment::getEnv()->allocator, dup_key);

                       }
                  }
                </xsl:when>
                <xsl:otherwise>
                <!-- Just waiting for fix the axiom_element_get_attribute 
                  <xsl:choose>
                    <xsl:when test="@nsuri and @nsuri != ''">
                      qname = axutil_qname_create(Environment::getEnv(), "<xsl:value-of select="$propertyName"/>", "<xsl:value-of select="@nsuri"/>", NULL);
                    </xsl:when>
                    <xsl:otherwise>
                      qname = axutil_qname_create(Environment::getEnv(), "<xsl:value-of select="$propertyName"/>", NULL, NULL);
                    </xsl:otherwise>
                  </xsl:choose>

                  parent_attri = axiom_element_get_attribute(parent_element, Environment::getEnv(), qname);
                  if(parent_attri != NULL)
                  {
                    attrib_text = axiom_attribute_get_value(parent_attri, Environment::getEnv());
                  }
                  else
                  {
                    attrib_text = axiom_element_get_attribute_value_by_name(parent_element, Environment::getEnv(), "<xsl:value-of select="$propertyName"/>");
                  }
                  if(qname)
                  {
                     axutil_qname_free(qname, Environment::getEnv());
                  } -->
                
                  parent_attri = NULL;
                  attrib_text = NULL;
                  if(attribute_hash)
                  {
                       axutil_hash_index_t *hi;
                       void *val;
                       const void *key;

                       for (hi = axutil_hash_first(attribute_hash, Environment::getEnv()); hi; hi = axutil_hash_next(Environment::getEnv(), hi))
                       {
                           axutil_hash_this(hi, &amp;key, NULL, &amp;val);
                           
                           <xsl:choose>
                             <xsl:when test="@nsuri and @nsuri != ''">
                               if(strstr((axis2_char_t*)key, "<xsl:value-of select="$propertyName"/>|<xsl:value-of select="@nsuri"/>"))
                             </xsl:when>
                             <xsl:otherwise>
                               if(!strcmp((axis2_char_t*)key, "<xsl:value-of select="$propertyName"/>"))
                             </xsl:otherwise>
                           </xsl:choose>
                               {
                                   parent_attri = (axiom_attribute_t*)val;
                                   break;
                               }
                       }
                  }

                  if(parent_attri)
                  {
                    attrib_text = axiom_attribute_get_value(parent_attri, Environment::getEnv());
                  }
                  else
                  {
                    /* this is hoping that attribute is stored in "<xsl:value-of select="$propertyName"/>", this happnes when name is in default namespace */
                    attrib_text = axiom_element_get_attribute_value_by_name(parent_element, Environment::getEnv(), "<xsl:value-of select="$propertyName"/>");
                  }

                  if(attrib_text != NULL)
                  {
                      <!-- here only simple type possible -->
                      <xsl:choose>
                        <!-- add int s -->
                        <xsl:when test="$nativePropertyType='int' or $nativePropertyType='unsigned int'">
                           set<xsl:value-of select="$CName"/>(atoi(attrib_text));
                        </xsl:when>

                        <!-- add axis2_char_t s -->
                        <xsl:when test="$nativePropertyType='char' or $nativePropertyType='unsigned char'">
                           set<xsl:value-of select="$CName"/>((char)(*attrib_text));
                        </xsl:when>

                        <!-- add short s -->
                        <xsl:when test="$nativePropertyType='short' or $nativePropertyType='unsigned short'">
                           set<xsl:value-of select="$CName"/>(atoi(attrib_text));
                        </xsl:when>

                        <!-- add int64_t s -->
                        <xsl:when test="$nativePropertyType='int64_t'">
                           set<xsl:value-of select="$CName"/>(axutil_strtol(attrib_text, (char**)NULL, 0));
                        </xsl:when>
                        <xsl:when test="$nativePropertyType='uint64_t'">
                           set<xsl:value-of select="$CName"/>(axutil_strtoul(attrib_text, (char**)NULL, 0));
                        </xsl:when>

                        <!-- add float s -->
                        <xsl:when test="$nativePropertyType='float'">
                           set<xsl:value-of select="$CName"/>(atof(attrib_text));
                        </xsl:when>
                        <!-- add double s -->
                        <xsl:when test="$nativePropertyType='double'">
                           set<xsl:value-of select="$CName"/>(atof(attrib_text));
                        </xsl:when>

                        <!-- add axis2_char_t s -->
                        <xsl:when test="$nativePropertyType='std::string'">
                           set<xsl:value-of select="$CName"/>(attrib_text);
                        </xsl:when>


                        <!-- add axutil_qname_t s -->
                        <xsl:when test="$nativePropertyType='axutil_qname_t*'">
                          prefix_found = false;
                          for(cp = attrib_text; *cp; cp ++)
                          {
                              if(*cp == ':')
                              {
                                  *cp = '\0';
                                  cp ++;
                                  prefix_found  = true;
                                  break;
                              }
                          }

                          if(prefix_found)
                          {
                              /* node value contain the prefix */
                              qname_ns = axiom_element_find_namespace_uri((axiom_element_t*)axiom_node_get_data_element(parent, Environment::getEnv()), Environment::getEnv(), attrib_text, parent);
                          }
                          else
                          {
                              /* Then it is the default namespace */
                              cp = attrib_text;
                              qname_ns = axiom_element_get_default_namespace((axiom_element_t*)axiom_node_get_data_element(parent, Environment::getEnv()), Environment::getEnv(), parent);
                          }

                           <!-- we are done extracting info, just set the extracted value to the qname -->

                           set<xsl:value-of select="$CName"/>(
                                                          axutil_qname_create(
                                                                Environment::getEnv(),
                                                                cp, /* cp contain the localname */
                                                                axiom_namespace_get_uri(qname_ns, Environment::getEnv()),
                                                                axiom_namespace_get_prefix(qname_ns, Environment::getEnv())));
                        </xsl:when>


                        <!-- add axutil_uri_t s -->
                        <xsl:when test="$nativePropertyType='axutil_uri_t*'">
                           set<xsl:value-of select="$CName"/>(axutil_uri_parse_string(Environment::getEnv(), attrib_text));
                        </xsl:when>

                        <!-- add axutil_duration_t s -->
                        <xsl:when test="$nativePropertyType='axutil_duration_t*'">
                           set<xsl:value-of select="$CName"/>(axutil_duration_create_from_string(Environment::getEnv(), attrib_text));
                        </xsl:when>
                        <!-- add bool s -->
                        <xsl:when test="$nativePropertyType='bool'">
                           if (!axutil_strcmp(attrib_text, "TRUE") || !axutil_strcmp(attrib_text, "true"))
                           {
                               set<xsl:value-of select="$CName"/>(true);
                           }
                           else
                           {
                               set<xsl:value-of select="$CName"/>(false);
                           }
                        </xsl:when>
                        <xsl:when test="$nativePropertyType='axis2_byte_t' or $nativePropertyType='axis2_unsigned_byte_t'">
                           set<xsl:value-of select="$CName"/>(atoi(attrib_text));
                        </xsl:when>
                        <!-- add date_time_t* s -->
                        <xsl:when test="$nativePropertyType='axutil_date_time_t*'">
                           axutil_date_time_t* element = axutil_date_time_create(Environment::getEnv());
                           axutil_date_time_deserialize_date_time(element, Environment::getEnv(),
                                                                      attrib_text);
                           set<xsl:value-of select="$CName"/>(element);
                        </xsl:when>
                        <!-- add hex_binary_t* s -->
                        <xsl:when test="$nativePropertyType='axutil_base64_binary_t*'">
                           axutil_base64_binary_t* element = axutil_base64_binary_create(Environment::getEnv());
                           axutil_base64_binary_set_encoded_binary(element), Environment::getEnv(),
                                                                      attrib_text);
                            set<xsl:value-of select="$CName"/>(element);
                        </xsl:when>
                        <xsl:when test="@ours">
                            <xsl:value-of select="@type"/>* element =  new <xsl:value-of select="@type"/>();
                            element->deserializeFromString(attrib_text, parent);
                           set<xsl:value-of select="$CName"/>(element);
                        </xsl:when>
                        <xsl:otherwise>
                          <!--TODO: add new attributes types -->
                          /* can not handle the attribute type <xsl:value-of select="$nativePropertyType"/>*/
                        </xsl:otherwise>
                      </xsl:choose>
                    }
                  </xsl:otherwise>
                  </xsl:choose>
                </xsl:when>
                <xsl:when test="$simple"></xsl:when> <!-- just to avoid preceeding code to be parsed in a simple type -->
                <xsl:otherwise> <!-- when it is an element not(@attribute) -->
                  <!-- handles arrays -->
                   <xsl:if test="@isarray">
                       { <!-- Scoping for arr_list -->
                    /*
                     * building <xsl:value-of select="$CName"/> array
                     */
                       std::vector&lt;<xsl:value-of select="@type"/><xsl:if test="@ours or @type='std::string' or @type='unsigned char' or @type='unsigned short' or @type='uint64_t' or @type='unsigned int' or @type='short' or @type='char' or @type='int' or @type='float' or @type='double' or @type='int64_t'"><xsl:text>*</xsl:text></xsl:if>&gt;* arr_list =new std::vector&lt;<xsl:value-of select="@type"/><xsl:if test="@ours or @type='std::string' or @type='unsigned char' or @type='unsigned short' or @type='uint64_t' or @type='unsigned int' or @type='short' or @type='char' or @type='int' or @type='float' or @type='double' or @type='int64_t'"><xsl:text>*</xsl:text></xsl:if>&gt;();
                   </xsl:if>

                     <!-- for each non attribute properties there will always be an element-->
                     /*
                      * building <xsl:value-of select="$propertyName"/> element
                      */
                     <!-- array and non array build is so different so big choose, when is requried-->
                     <!-- the method of picking the element is depend on the $ordered -->
                     <xsl:choose>
                       <xsl:when test="not(@isarray)">  <!--not an array so continue normal -->
                           <xsl:choose>
                             <xsl:when test="$ordered or not($anon or $istype) or $choice"> <!-- since non-anon and choices has just only one sub element-->
                               <xsl:choose>
                                 <xsl:when test="position()=1">
                                   current_node = first_node;
                                   is_early_node_valid = false;
                                   <!-- Wait until AXIOM_ELEMENT -->
                                   <xsl:if test="not(@any)">
                                    while(current_node &amp;&amp; axiom_node_get_node_type(current_node, Environment::getEnv()) != AXIOM_ELEMENT)
                                    {
                                        current_node = axiom_node_get_next_sibling(current_node, Environment::getEnv());
                                    }
                                    if(current_node != NULL)
                                    {
                                        current_element = (axiom_element_t *)axiom_node_get_data_element(current_node, Environment::getEnv());
                                        mqname = axiom_element_get_qname(current_element, Environment::getEnv(), current_node);
                                    }
                                   </xsl:if>
                                 </xsl:when>
                                 <xsl:otherwise>
                                    /*
                                     * because elements are ordered this works fine
                                     */
                                  
                                   <!-- current node should contain the ordered value -->
                                   if(current_node != NULL &amp;&amp; is_early_node_valid)
                                   {
                                       current_node = axiom_node_get_next_sibling(current_node, Environment::getEnv());
                                       <!-- Wait until AXIOM_ELEMENT -->
                                       <xsl:if test="not(@any)">
                                        while(current_node &amp;&amp; axiom_node_get_node_type(current_node, Environment::getEnv()) != AXIOM_ELEMENT)
                                        {
                                            current_node = axiom_node_get_next_sibling(current_node, Environment::getEnv());
                                        }
                                        if(current_node != NULL)
                                        {
                                            current_element = (axiom_element_t *)axiom_node_get_data_element(current_node, Environment::getEnv());
                                            mqname = axiom_element_get_qname(current_element, Environment::getEnv(), current_node);
                                        }
                                       </xsl:if>
                                   }
                                   is_early_node_valid = false;
                                 </xsl:otherwise>
                               </xsl:choose> <!-- close for position -1 -->

                               <xsl:choose>
                                 <xsl:when test="@any"></xsl:when>
                                 <xsl:when test="@nsuri and @nsuri != ''">
                                 element_qname = axutil_qname_create(Environment::getEnv(), "<xsl:value-of select="$propertyName"/>", "<xsl:value-of select="@nsuri"/>", NULL);
                                 </xsl:when>
                                 <xsl:otherwise>
                                 element_qname = axutil_qname_create(Environment::getEnv(), "<xsl:value-of select="$propertyName"/>", NULL, NULL);
                                 </xsl:otherwise>
                               </xsl:choose>

                             </xsl:when>
                             <xsl:otherwise> <!-- otherwise for ($ordered), -->
                               /*
                                * because elements are not ordered we should surf all the sibling to pick the right one
                                */
                               for (current_node = first_node; current_node != NULL;
                                             current_node = axiom_node_get_next_sibling(current_node, Environment::getEnv()))
                               {
                                  if(axiom_node_get_node_type(current_node, Environment::getEnv()) != AXIOM_ELEMENT)
                                  {
                                     continue;
                                  }
                                  
                                  current_element = (axiom_element_t *)axiom_node_get_data_element(current_node, Environment::getEnv());
                                  mqname = axiom_element_get_qname(current_element, Environment::getEnv(), current_node);
                                <xsl:choose>
                                  <xsl:when test="@nsuri and @nsuri != ''">
                                  element_qname = axutil_qname_create(Environment::getEnv(), "<xsl:value-of select="$propertyName"/>", "<xsl:value-of select="@nsuri"/>", NULL);
                                  </xsl:when>
                                  <xsl:otherwise>
                                  element_qname = axutil_qname_create(Environment::getEnv(), "<xsl:value-of select="$propertyName"/>", NULL, NULL);
                                  </xsl:otherwise>
                                </xsl:choose>
                                  if (axutil_qname_equals(element_qname, Environment::getEnv(), mqname)<xsl:if test="not(@nsuri) or @nsuri=''"> || !axutil_strcmp("<xsl:value-of select="$propertyName"/>", axiom_element_get_localname(current_element, Environment::getEnv()))</xsl:if>)
                                  {
                                       /* found the required element */
                                       break;
                                  }
                               }
                             </xsl:otherwise> <!-- close for $ordered or not($anon or $istype) -->
                           </xsl:choose>

                           if (<xsl:if test="@ours">isParticle() || </xsl:if> <!-- is particle test should be done here -->
                                (current_node <xsl:if test="not(@any)">  &amp;&amp; current_element &amp;&amp; (axutil_qname_equals(element_qname, Environment::getEnv(), mqname)<xsl:if test="not(@nsuri) or @nsuri=''"> || !axutil_strcmp("<xsl:value-of select="$propertyName"/>", axiom_element_get_localname(current_element, Environment::getEnv()))</xsl:if>)</xsl:if>))
                           {
                              if( current_node <xsl:if test="not(@any)">  &amp;&amp; current_element &amp;&amp; (axutil_qname_equals(element_qname, Environment::getEnv(), mqname)<xsl:if test="not(@nsuri) or @nsuri=''"> || !axutil_strcmp("<xsl:value-of select="$propertyName"/>", axiom_element_get_localname(current_element, Environment::getEnv()))</xsl:if>)</xsl:if>)
                              {
                                is_early_node_valid = true;
                              }
                              <!-- changes to following choose tag should be changed in another 2 places -->
                                 <xsl:choose>
                                    <xsl:when test="@ours">
                                      <xsl:value-of select="@type"/>* element = new <xsl:value-of select="@type"/>();

                                      status =  element->deserialize(&amp;current_node, &amp;is_early_node_valid, <xsl:choose><xsl:when test="$choice">true</xsl:when><xsl:otherwise>false</xsl:otherwise></xsl:choose>);
                                      if(AXIS2_FAILURE == status)
                                      {
                                          WSF_LOG_ERROR_MSG(Environment::getEnv()->log, WSF_LOG_SI, "failed in building adb object for element <xsl:value-of select="$propertyName"/>");
                                      }
                                      else
                                      {
                                          status = set<xsl:value-of select="$CName"/>(element);
                                      }
                                    </xsl:when>
                                    <xsl:when test="$nativePropertyType='std::string'">
                                      text_value = axiom_element_get_text(current_element, Environment::getEnv(), current_node);
                                      if(text_value != NULL)
                                      {
                                            status = set<xsl:value-of select="$CName"/>(text_value);
                                      }
                                      <xsl:if test="not(@nillable)">
                                      else
                                      {
                                            /*
                                             * axis2_qname_t *qname = NULL;
                                             * axiom_attribute_t *the_attri = NULL;
                                             * 
                                             * qname = axutil_qname_create(Environment::getEnv(), "nil", "http://www.w3.org/2001/XMLSchema-instance", "xsi");
                                             * the_attri = axiom_element_get_attribute(current_element, Environment::getEnv(), qname);
                                             */
                                            /* currently thereis a bug in the axiom_element_get_attribute, so we have to go to this bad method */

                                            axiom_attribute_t *the_attri = NULL;
                                            axis2_char_t *attrib_text = NULL;
                                            axutil_hash_t *attribute_hash = NULL;

                                            attribute_hash = axiom_element_get_all_attributes(current_element, Environment::getEnv());

                                            attrib_text = NULL;
                                            if(attribute_hash)
                                            {
                                                 axutil_hash_index_t *hi;
                                                 void *val;
                                                 const void *key;
                                        
                                                 for (hi = axutil_hash_first(attribute_hash, Environment::getEnv()); hi; hi = axutil_hash_next(Environment::getEnv(), hi))
                                                 {
                                                     axutil_hash_this(hi, &amp;key, NULL, &amp;val);
                                                     
                                                     if(strstr((axis2_char_t*)key, "nil|http://www.w3.org/2001/XMLSchema-instance"))
                                                     {
                                                         the_attri = (axiom_attribute_t*)val;
                                                         break;
                                                     }
                                                 }
                                            }

                                            if(the_attri)
                                            {
                                                attrib_text = axiom_attribute_get_value(the_attri, Environment::getEnv());
                                            }
                                            else
                                            {
                                                /* this is hoping that attribute is stored in "http://www.w3.org/2001/XMLSchema-instance", this happnes when name is in default namespace */
                                                attrib_text = axiom_element_get_attribute_value_by_name(current_element, Environment::getEnv(), "nil");
                                            }

                                            if(attrib_text &amp;&amp; 0 == axutil_strcmp(attrib_text, "1"))
                                            {
                                                WSF_LOG_ERROR_MSG(Environment::getEnv()->log, WSF_LOG_SI, "NULL value is set to a non nillable element <xsl:value-of select="$propertyName"/>");
                                                status = AXIS2_FAILURE;
                                            }
                                            else
                                            {
                                                /* after all, we found this is a empty string */
                                                status = set<xsl:value-of select="$CName"/>("");
                                            }
                                      }
                                      </xsl:if>
                                    </xsl:when>
                                    <xsl:when test="$nativePropertyType='axutil_uri_t*'">
                                      text_value = axiom_element_get_text(current_element, Environment::getEnv(), current_node);
                                      if(text_value != NULL)
                                      {
                                          status = set<xsl:value-of select="$CName"/>(axutil_uri_parse_string(Environment::getEnv(), text_value));
                                      }
                                      <xsl:if test="not(@nillable)">
                                      else
                                      {
                                          WSF_LOG_ERROR_MSG(Environment::getEnv()->log, WSF_LOG_SI, "NULL value is set to a non nillable element <xsl:value-of select="$propertyName"/>");
                                          status = AXIS2_FAILURE;
                                      }
                                      </xsl:if> 
                                    </xsl:when>
                                    <xsl:when test="$nativePropertyType='axutil_duration_t*'">
                                      text_value = axiom_element_get_text(current_element, Environment::getEnv(), current_node);
                                      if(text_value != NULL)
                                      {
                                          status = set<xsl:value-of select="$CName"/>(axutil_duration_create_from_string(Environment::getEnv(), text_value));
                                      }
                                      <xsl:if test="not(@nillable)">
                                      else
                                      {
                                          WSF_LOG_ERROR_MSG(Environment::getEnv()->log, WSF_LOG_SI, "NULL value is set to a non nillable element <xsl:value-of select="$propertyName"/>");
                                          status = AXIS2_FAILURE;
                                      }
                                      </xsl:if> 
                                    </xsl:when>
                                    <xsl:when test="$nativePropertyType='axutil_qname_t*'">
                                      text_value = axiom_element_get_text(current_element, Environment::getEnv(), current_node);
                                      if(text_value != NULL)
                                      {
                                            prefix_found = false;
                                            for(cp = (axis2_char_t*)text_value; *cp; cp ++)
                                            {
                                                if(*cp == ':')
                                                {
                                                    *cp = '\0';
                                                    cp ++;
                                                    prefix_found  = true;
                                                    break;
                                                }
                                            }
                                          
                                            if(prefix_found)
                                            {
                                                /* node value contain  the prefix */
                                                qname_ns = axiom_element_find_namespace_uri(current_element, Environment::getEnv(), text_value, current_node);
                                            }
                                            else
                                            {
                                                /* Then it is the default namespace */
                                                cp = (axis2_char_t*)text_value;
                                                qname_ns = axiom_element_get_default_namespace(current_element, Environment::getEnv(), current_node);
                                            }
                                          
                                            <!-- we are done extracting info, just set the extracted value to the qname -->
                                           
                                            status = set<xsl:value-of select="$CName"/>(
                                                    axutil_qname_create(
                                                          Environment::getEnv(),
                                                          cp, /* cp contain the localname */
                                                          axiom_namespace_get_uri(qname_ns, Environment::getEnv()),
                                                          axiom_namespace_get_prefix(qname_ns, Environment::getEnv())));
                                       }
                                       <xsl:if test="not(@nillable)">
                                         else
                                         {
                                             WSF_LOG_ERROR_MSG(Environment::getEnv()->log, WSF_LOG_SI, "NULL value is set to a non nillable element <xsl:value-of select="$propertyName"/>");
                                             status = AXIS2_FAILURE;
                                         }
                                       </xsl:if>

                                    </xsl:when>
                                    <xsl:when test="$nativePropertyType='char' or $nativePropertyType='unsigned char'">
                                      text_value = axiom_element_get_text(current_element, Environment::getEnv(), current_node);
                                      if(text_value != NULL)
                                      {
                                          status = set<xsl:value-of select="$CName"/>(
                                                             (char)(*text_value));
                                      }
                                      <xsl:if test="not(@nillable)">
                                      else
                                      {
                                          WSF_LOG_ERROR_MSG(Environment::getEnv()->log, WSF_LOG_SI, "NULL value is set to a non nillable element <xsl:value-of select="$propertyName"/>");
                                          status = AXIS2_FAILURE;
                                      }
                                      </xsl:if> 

                                    </xsl:when>
                                    <xsl:when test="$nativePropertyType='int' or $nativePropertyType='unsigned int'">
                                      text_value = axiom_element_get_text(current_element, Environment::getEnv(), current_node);
                                      if(text_value != NULL)
                                      {
                                            status = set<xsl:value-of select="$CName"/>(atoi(text_value));
                                      }
                                      <xsl:if test="not(@nillable)">
                                      else
                                      {
                                          WSF_LOG_ERROR_MSG(Environment::getEnv()->log, WSF_LOG_SI, "NULL value is set to a non nillable element <xsl:value-of select="$propertyName"/>");
                                          status = AXIS2_FAILURE;
                                      }
                                      </xsl:if> 
                                   </xsl:when>
                                    <xsl:when test="$nativePropertyType='axis2_byte_t' or $nativePropertyType='axis2_unsigned_byte_t'">
                                      text_value = axiom_element_get_text(current_element, Environment::getEnv(), current_node);
                                      if(text_value != NULL)
                                      {
                                            status = set<xsl:value-of select="$CName"/>(atoi(text_value));
                                      }
                                      <xsl:if test="not(@nillable)">
                                      else
                                      {
                                          WSF_LOG_ERROR_MSG(Environment::getEnv()->log, WSF_LOG_SI, "NULL value is set to a non nillable element <xsl:value-of select="$propertyName"/>");
                                          status = AXIS2_FAILURE;
                                      }
                                      </xsl:if> 

                                   </xsl:when>
                                    <xsl:when test="$nativePropertyType='short' or $nativePropertyType='unsigned short'">
                                      text_value = axiom_element_get_text(current_element, Environment::getEnv(), current_node);
                                      if(text_value != NULL)
                                      {
                                            status = set<xsl:value-of select="$CName"/>(atoi(text_value));
                                      }
                                      <xsl:if test="not(@nillable)">
                                      else
                                      {
                                          WSF_LOG_ERROR_MSG(Environment::getEnv()->log, WSF_LOG_SI, "NULL value is set to a non nillable element <xsl:value-of select="$propertyName"/>");
                                          status = AXIS2_FAILURE;
                                      }
                                      </xsl:if> 

                                    </xsl:when>
                                    <xsl:when test="$nativePropertyType='float'">
                                      text_value = axiom_element_get_text(current_element, Environment::getEnv(), current_node);
                                      if(text_value != NULL)
                                      {
                                            status = set<xsl:value-of select="$CName"/>(atof(text_value));
                                      }
                                      <xsl:if test="not(@nillable)">
                                      else
                                      {
                                          WSF_LOG_ERROR_MSG(Environment::getEnv()->log, WSF_LOG_SI, "NULL value is set to a non nillable element <xsl:value-of select="$propertyName"/>");
                                          status = AXIS2_FAILURE;
                                      }
                                      </xsl:if>

                                     </xsl:when>
                                    <xsl:when test="$nativePropertyType='double'">
                                      text_value = axiom_element_get_text(current_element, Environment::getEnv(), current_node);
                                      if(text_value != NULL)
                                      {
                                            status = set<xsl:value-of select="$CName"/>(atof(text_value));
                                      }
                                      <xsl:if test="not(@nillable)">
                                      else
                                      {
                                          WSF_LOG_ERROR_MSG(Environment::getEnv()->log, WSF_LOG_SI, "NULL value is set to a non nillable element <xsl:value-of select="$propertyName"/>");
                                          status = AXIS2_FAILURE;
                                      }
                                      </xsl:if>

                                    </xsl:when>
                                    <xsl:when test="$nativePropertyType='int64_t'">
                                      text_value = axiom_element_get_text(current_element, Environment::getEnv(), current_node);
                                      if(text_value != NULL)
                                      {
                                            status = set<xsl:value-of select="$CName"/>(axutil_strtol(text_value, (char**)NULL, 0));
                                      }
                                      <xsl:if test="not(@nillable)">
                                      else
                                      {
                                          WSF_LOG_ERROR_MSG(Environment::getEnv()->log, WSF_LOG_SI, "NULL value is set to a non nillable element <xsl:value-of select="$propertyName"/>");
                                          status = AXIS2_FAILURE;
                                      }
                                      </xsl:if>
                                    </xsl:when>
                                    <xsl:when test="$nativePropertyType='uint64_t'">
                                      text_value = axiom_element_get_text(current_element, Environment::getEnv(), current_node);
                                      if(text_value != NULL)
                                      {
                                            status = set<xsl:value-of select="$CName"/>(axutil_strtoul(text_value, (char**)NULL, 0));
                                      }
                                      <xsl:if test="not(@nillable)">
                                      else
                                      {
                                          WSF_LOG_ERROR_MSG(Environment::getEnv()->log, WSF_LOG_SI, "NULL value is set to a non nillable element <xsl:value-of select="$propertyName"/>");
                                          status = AXIS2_FAILURE;
                                      }
                                      </xsl:if>
                                    </xsl:when>
                                    <xsl:when test="$nativePropertyType='wso2wsf::OMElement*'">
                                      text_value = NULL; /* just to avoid warning */
                                      <xsl:choose>
                                        <xsl:when test="@any">
                                        {
                                          axiom_node_t *current_property_node = current_node;
                                          current_node = axiom_node_get_next_sibling(current_node, Environment::getEnv());
                                          axiom_node_detach(current_property_node, Environment::getEnv());
                                          status = set<xsl:value-of select="$CName"/>(new OMElement(NULL,current_property_node));
                                        }
                                        </xsl:when>
                                        <xsl:otherwise>
                                          if(axiom_node_get_first_child(current_node, Environment::getEnv()))
                                          {
                                              axiom_node_t *current_property_node = axiom_node_get_first_child(current_node, Environment::getEnv());
                                              axiom_node_detach(current_property_node, Environment::getEnv());
                                              status = set<xsl:value-of select="$CName"/>(new OMElement(NULL,current_property_node));
                                          }
                                          else
                                          {
                                              status = set<xsl:value-of select="$CName"/>(NULL);
                                          }
                                        </xsl:otherwise>
                                      </xsl:choose>

                                    </xsl:when>
                                    <xsl:when test="$nativePropertyType='bool'">
                                      text_value = axiom_element_get_text(current_element, Environment::getEnv(), current_node);
                                      if(text_value != NULL)
                                      {
                                            if (!axutil_strcasecmp(text_value , "true"))
                                            {
                                                status = set<xsl:value-of select="$CName"/>(true);
                                            }
                                            else
                                            {
                                                status = set<xsl:value-of select="$CName"/>(false);
                                            }
                                      }
                                      <xsl:if test="not(@nillable)">
                                      else
                                      {
                                          WSF_LOG_ERROR_MSG(Environment::getEnv()->log, WSF_LOG_SI, "NULL value is set to a non nillable element <xsl:value-of select="$propertyName"/>");
                                          status = AXIS2_FAILURE;
                                      }
                                      </xsl:if>
                                    </xsl:when>
                                    <xsl:when test="$nativePropertyType='axutil_date_time_t*'">
                                      text_value = axiom_element_get_text(current_element, Environment::getEnv(), current_node);
                                      if(text_value != NULL)
                                      {
                                          axutil_date_time_t* element = axutil_date_time_create(Environment::getEnv());
                                          status = axutil_date_time_deserialize_date_time((axutil_date_time_t*)element, Environment::getEnv(),
                                                                          text_value);
                                          if(AXIS2_FAILURE ==  status)
                                          {
                                              if(element != NULL)
                                              {
                                                  axutil_date_time_free(element, Environment::getEnv());
                                              }
					                          WSF_LOG_ERROR_MSG(Environment::getEnv()->log, WSF_LOG_SI ,"failed in building element <xsl:value-of select="$propertyName"/> ");
                                          }
                                          else
                                          {
                                            status = set<xsl:value-of select="$CName"/>(element);
                                          }
                                      }
                                      <xsl:if test="not(@nillable)">
                                      else
                                      {
				                            WSF_LOG_ERROR_MSG(Environment::getEnv()->log,WSF_LOG_SI, "NULL value is set to a non nillable element <xsl:value-of select="$propertyName"/>");
                                            status = AXIS2_FAILURE;
                                      }
                                      </xsl:if>

                                    </xsl:when>
                                    <xsl:when test="$nativePropertyType='axutil_base64_binary_t*'">
                                      text_value = axiom_element_get_text(current_element, Environment::getEnv(), current_node);
                                      if(text_value != NULL)
                                      {
                                          axutil_base64_binary_t* element = axutil_base64_binary_create(Environment::getEnv());
                                          status = axutil_base64_binary_set_encoded_binary((axutil_base64_binary_t*)element, Environment::getEnv(),
                                                                          text_value);
                                          if(AXIS2_FAILURE ==  status)
                                          {
                                              if(element != NULL)
                                              {
                                                 axutil_base64_binary_free(element, Environment::getEnv());
                                              }
					                          WSF_LOG_ERROR_MSG(Environment::getEnv()->log,WSF_LOG_SI, "failed in building element <xsl:value-of select="$propertyName"/> ");
                                          }
                                          else
                                          {
                                            status = set<xsl:value-of select="$CName"/>(element);
                                          }
                                      }
                                      <xsl:if test="not(@nillable)">
                                      else
                                      {
				                          WSF_LOG_ERROR_MSG(Environment::getEnv()->log,WSF_LOG_SI, "NULL value is set to a non nillable element <xsl:value-of select="$propertyName"/>");
                                          status = AXIS2_FAILURE;
                                      }
                                      </xsl:if>

                                    </xsl:when>
                                    <xsl:otherwise>
                                      <!-- TODO: add other types here -->
                                      /* Imposible test2 to handle the request type - so please do it manually */
                                      text_value = NULL;
                                    </xsl:otherwise>
                                 </xsl:choose>
                                 if(AXIS2_FAILURE ==  status)
                                 {
                                     WSF_LOG_ERROR_MSG( Environment::getEnv()->log,WSF_LOG_SI,"failed in setting the value for <xsl:value-of select="$propertyName"/> ");
                                     if(element_qname)
                                     {
                                         axutil_qname_free(element_qname, Environment::getEnv());
                                     }
                                     return AXIS2_FAILURE;
                                 }
                              }
                           <xsl:if test="not(@nillable) and not(@minOccurs=0) and not($choice)">
                              else if(!dont_care_minoccurs)
                              {
                                  if(element_qname)
                                  {
                                      axutil_qname_free(element_qname, Environment::getEnv());
                                  }
                                  /* this is not a nillable element*/
				  WSF_LOG_ERROR_MSG(Environment::getEnv()->log,WSF_LOG_SI, "non nillable or minOuccrs != 0 element <xsl:value-of select="$propertyName"/> missing");
                                  return AXIS2_FAILURE;
                              }
                           </xsl:if>
                        </xsl:when>
                        <xsl:otherwise> <!-- when it is all the way an array -->
                           <xsl:if test="@any">
                            /* 'any' arrays are not handling correctly when there are other elements mixed with the 'any' element. */
                           </xsl:if>
                           <xsl:choose>
                             <xsl:when test="$ordered or not($anon or $istype) or $choice"> <!-- all the elements should follow this -->
                                <xsl:choose>
                                  <xsl:when test="@any"></xsl:when>
                                  <xsl:when test="@nsuri and @nsuri != ''">
                                    element_qname = axutil_qname_create(Environment::getEnv(), "<xsl:value-of select="$propertyName"/>", "<xsl:value-of select="@nsuri"/>", NULL);
                                  </xsl:when>
                                  <xsl:otherwise>
                                    element_qname = axutil_qname_create(Environment::getEnv(), "<xsl:value-of select="$propertyName"/>", NULL, NULL);
                                  </xsl:otherwise>
                                </xsl:choose>
                               
                               for (i = 0, sequence_broken = 0, current_node = <xsl:choose>
                                             <xsl:when test="position()=1">first_node</xsl:when>
                                             <xsl:otherwise>(is_early_node_valid?axiom_node_get_next_sibling(current_node, Environment::getEnv()):current_node)</xsl:otherwise></xsl:choose>; !sequence_broken &amp;&amp; current_node != NULL;)
                                             <!-- We are not moving current_node to next sibling here if it an any type, because we already have done the move -->
                               {
                                  if(axiom_node_get_node_type(current_node, Environment::getEnv()) != AXIOM_ELEMENT)
                                  {
                                     current_node =axiom_node_get_next_sibling(current_node, Environment::getEnv());
                                     is_early_node_valid = false;
                                     continue;
                                  }
                                  <xsl:if test="not(@any)">
                                  current_element = (axiom_element_t *)axiom_node_get_data_element(current_node, Environment::getEnv());
                                  mqname = axiom_element_get_qname(current_element, Environment::getEnv(), current_node);

                                  if (axutil_qname_equals(element_qname, Environment::getEnv(), mqname)<xsl:if test="not(@nsuri) or @nsuri=''"> || !axutil_strcmp("<xsl:value-of select="$propertyName"/>", axiom_element_get_localname(current_element, Environment::getEnv()))</xsl:if>)
                                  {
                                  </xsl:if>
                                      is_early_node_valid = true;
                                      <!-- changes to following choose tag should be changed in another 2 places -->
                                     <xsl:choose>
                                        <xsl:when test="@ours">
                                          <xsl:value-of select="@type"/>* element = new <xsl:value-of select="@type"/>();
                                          
                                          status =  element->deserialize(&amp;current_node, &amp;is_early_node_valid, <xsl:choose><xsl:when test="$choice">true</xsl:when><xsl:otherwise>false</xsl:otherwise></xsl:choose>);
                                          
                                          if(AXIS2_FAILURE ==  status)
                                          {
					  WSF_LOG_ERROR_MSG(Environment::getEnv()->log,WSF_LOG_SI, "failed in building element <xsl:value-of select="$propertyName"/> ");
                                          }
                                          else
                                          {
                                            arr_list->push_back(element);
                                            <!-- axutil_array_list_add_at(arr_list, Environment::getEnv(), i, element); -->
                                          }
                                        </xsl:when>
                                        <xsl:when test="$nativePropertyType='std::string'">
                                          text_value = axiom_element_get_text(current_element, Environment::getEnv(), current_node);
                                          if(text_value != NULL)
                                          {
                                              arr_list->push_back(new string(text_value));
                                          }
                                          <xsl:if test="not(@nillable)">
                                          else
                                          {
                                              /*
                                               * axis2_qname_t *qname = NULL;
                                               * axiom_attribute_t *the_attri = NULL;
                                               * 
                                               * qname = axutil_qname_create(Environment::getEnv(), "nil", "http://www.w3.org/2001/XMLSchema-instance", "xsi");
                                               * the_attri = axiom_element_get_attribute(current_element, Environment::getEnv(), qname);
                                               */
                                           
                                              /* currently thereis a bug in the axiom_element_get_attribute, so we have to go to this bad method */
                                             
                                              axiom_attribute_t *the_attri = NULL;
                                              axis2_char_t *attrib_text = NULL;
                                              axutil_hash_t *attribute_hash = NULL;
                                             
                                              attribute_hash = axiom_element_get_all_attributes(current_element, Environment::getEnv());
                                             
                                              attrib_text = NULL;
                                              if(attribute_hash)
                                              {
                                                   axutil_hash_index_t *hi;
                                                   void *val;
                                                   const void *key;
                                             
                                                   for (hi = axutil_hash_first(attribute_hash, Environment::getEnv()); hi; hi = axutil_hash_next(Environment::getEnv(), hi))
                                                   {
                                                       axutil_hash_this(hi, &amp;key, NULL, &amp;val);
                                                       
                                                       if(strstr((axis2_char_t*)key, "nil|http://www.w3.org/2001/XMLSchema-instance"))
                                                       {
                                                           the_attri = (axiom_attribute_t*)val;
                                                           break;
                                                       }
                                                   }
                                              }
                                             
                                              if(the_attri)
                                              {
                                                  attrib_text = axiom_attribute_get_value(the_attri, Environment::getEnv());
                                              }
                                              else
                                              {
                                                  /* this is hoping that attribute is stored in "http://www.w3.org/2001/XMLSchema-instance", this happnes when name is in default namespace */
                                                  attrib_text = axiom_element_get_attribute_value_by_name(current_element, Environment::getEnv(), "nil");
                                              }
                                             
                                              if(attrib_text &amp;&amp; 0 == axutil_strcmp(attrib_text, "1"))
                                              {
					      WSF_LOG_ERROR_MSG(Environment::getEnv()->log,WSF_LOG_SI,"NULL value is set to a non nillable element <xsl:value-of select="$propertyName"/>");
                                                  status = AXIS2_FAILURE;
                                              }
                                              else
                                              {
                                                  /* after all, we found this is a empty string */
                                                  arr_list->push_back(new string(""));
                                              }
                                          }
                                          </xsl:if>
                                        </xsl:when>
                                        <xsl:when test="$nativePropertyType='axutil_qname_t*'">
                                          text_value = axiom_element_get_text(current_element, Environment::getEnv(), current_node);
                                          if(text_value != NULL)
                                          {
                                              prefix_found = false;
                                              for(cp = (axis2_char_t*)text_value; *cp; cp ++)
                                              {
                                                  if(*cp == ':')
                                                  {
                                                      *cp = '\0';
                                                      cp ++;
                                                      prefix_found  = true;
                                                      break;
                                                  }
                                              }
                                              
                                              if(prefix_found)
                                              {
                                                  /* node value contain  the prefix */
                                                  qname_ns = axiom_element_find_namespace_uri(current_element, Environment::getEnv(), text_value, current_node);
                                              }
                                              else
                                              {
                                                  /* Then it is the default namespace */
                                                  cp = (axis2_char_t*)text_value;
                                                  qname_ns = axiom_element_get_default_namespace(current_element, Environment::getEnv(), current_node);
                                              }
                                              
                                              <!-- we are done extracting info, just set the extracted value to the qname -->
                                              
                                              arr_list->push_back(
                                                      axutil_qname_create(
                                                            Environment::getEnv(),
                                                            cp, /* cp contain the localname */
                                                            axiom_namespace_get_uri(qname_ns, Environment::getEnv()),
                                                            axiom_namespace_get_prefix(qname_ns, Environment::getEnv())));
                                          }
                                          <xsl:if test="not(@nillable)">
                                          else
                                          {
					  WSF_LOG_ERROR_MSG(Environment::getEnv()->log,WSF_LOG_SI, "NULL value is set to a non nillable element <xsl:value-of select="$propertyName"/>");
                                                status = AXIS2_FAILURE;
                                          }
                                          </xsl:if>
                                        </xsl:when>
                                        <xsl:when test="$nativePropertyType='axutil_uri_t*'">
                                          text_value = axiom_element_get_text(current_element, Environment::getEnv(), current_node);
                                          if(text_value != NULL)
                                          {
                                              arr_list->push_back(axutil_uri_parse_string(Environment::getEnv(), text_value));
                                          }
                                          <xsl:if test="not(@nillable)">
                                          else
                                          {
					                        WSF_LOG_ERROR_MSG(Environment::getEnv()->log,WSF_LOG_SI, "NULL value is set to a non nillable element <xsl:value-of select="$propertyName"/>");
                                                status = AXIS2_FAILURE;
                                          }
                                          </xsl:if>
                                        </xsl:when>
                                        <xsl:when test="$nativePropertyType='axutil_duration_t*'">
                                          text_value = axiom_element_get_text(current_element, Environment::getEnv(), current_node);
                                          if(text_value != NULL)
                                          {
                                                arr_list->push_back(axutil_duration_create_from_string(Environment::getEnv(), text_value));
                                          }
                                          <xsl:if test="not(@nillable)">
                                          else
                                          {
					                            WSF_LOG_ERROR_MSG(Environment::getEnv()->log,WSF_LOG_SI,"NULL value is set to a non nillable element <xsl:value-of select="$propertyName"/>");
                                                status = AXIS2_FAILURE;
                                          }
                                          </xsl:if>
                                        </xsl:when>
                                        <xsl:when test="$nativePropertyType='char' or $nativePropertyType='unsigned char'">
                                          text_value = axiom_element_get_text(current_element, Environment::getEnv(), current_node);
                                          if(text_value != NULL)
                                          {
                                               <xsl:value-of select="$nativePropertyType"/>* element = AXIS2_MALLOC(Environment::getEnv()-> allocator, 64);
                                               *element = (char)(*text_value);
                                               arr_list->push_back(element);
                                          }
                                          <xsl:if test="not(@nillable)">
                                          else
                                          {
					                        WSF_LOG_ERROR_MSG( Environment::getEnv()->log,WSF_LOG_SI,"NULL value is set to a non nillable element <xsl:value-of select="$propertyName"/>");
                                                status = AXIS2_FAILURE;
                                          }
                                          </xsl:if>
                                        </xsl:when>
                                        <xsl:when test="$nativePropertyType='int' or $nativePropertyType='unsigned int'">
                                          text_value = axiom_element_get_text(current_element, Environment::getEnv(), current_node);
                                          if(text_value != NULL)
                                          {
                                              /* we keeps ints in arrays from their pointers */
                                              <xsl:value-of select="$nativePropertyType"/>* element = (<xsl:value-of select="$nativePropertyType"/>*)AXIS2_MALLOC(Environment::getEnv()-> allocator, sizeof(int));
                                              *element = atoi(text_value);

                                              arr_list->push_back(element);
                                          }
                                          <xsl:if test="not(@nillable)">
                                          else
                                          {
					                            WSF_LOG_ERROR_MSG(Environment::getEnv()->log,WSF_LOG_SI, "NULL value is set to a non nillable element <xsl:value-of select="$propertyName"/>");
                                                status = AXIS2_FAILURE;
                                          }
                                          </xsl:if>
                                        </xsl:when>
                                        <xsl:when test="$nativePropertyType='axis2_byte_t' or $nativePropertyType='axis2_unsigned_byte_t'">
                                          text_value = axiom_element_get_text(current_element, Environment::getEnv(), current_node);
                                          if(text_value != NULL)
                                          {
                                              /* we keeps ints in arrays from their pointers */
                                              <xsl:value-of select="$nativePropertyType"/>* element = (<xsl:value-of select="$nativePropertyType"/>*)AXIS2_MALLOC(Environment::getEnv()-> allocator, sizeof(axis2_byte_t));
                                              *element = atoi(text_value);

                                              arr_list->push_back(element);
                                          }
                                          <xsl:if test="not(@nillable)">
                                          else
                                          {
					                            WSF_LOG_ERROR_MSG(Environment::getEnv()->log,WSF_LOG_SI, "NULL value is set to a non nillable element <xsl:value-of select="$propertyName"/>");
                                                status = AXIS2_FAILURE;
                                          }
                                          </xsl:if>
                                        </xsl:when>
                                        <xsl:when test="$nativePropertyType='short' or $nativePropertyType='unsigned short'">
                                          text_value = axiom_element_get_text(current_element, Environment::getEnv(), current_node);
                                          if(text_value != NULL)
                                          {
                                              /* we keeps ints in arrays from their pointers  */
                                              <xsl:value-of select="$nativePropertyType"/>* element = (<xsl:value-of select="$nativePropertyType"/>*)AXIS2_MALLOC(Environment::getEnv()-> allocator, sizeof(short));
                                              *element = atoi(text_value);
                                               arr_list->push_back(element);
                                           }
                                          <xsl:if test="not(@nillable)">
                                          else
                                          {
                        					  WSF_LOG_ERROR_MSG(Environment::getEnv()->log,WSF_LOG_SI, "NULL value is set to a non nillable element <xsl:value-of select="$propertyName"/>");
                                              status = AXIS2_FAILURE;
                                          }
                                          </xsl:if>
                                        </xsl:when>
                                        <xsl:when test="$nativePropertyType='float'">
                                          text_value = axiom_element_get_text(current_element, Environment::getEnv(), current_node);
                                          if(text_value != NULL)
                                          {
                                              /* we keeps ints in arrays from their pointers */
                                              <xsl:value-of select="$nativePropertyType"/>* element = (<xsl:value-of select="$nativePropertyType"/>*)AXIS2_MALLOC(Environment::getEnv()-> allocator, sizeof(float));
                                              *element = atof(text_value);
                                              arr_list->push_back(element);
                                          }
                                          <xsl:if test="not(@nillable)">
                                          else
                                          {
					                            WSF_LOG_ERROR_MSG(Environment::getEnv()->log,WSF_LOG_SI, "NULL value is set to a non nillable element <xsl:value-of select="$propertyName"/>");
                                                status = AXIS2_FAILURE;
                                          }
                                          </xsl:if>
                                        </xsl:when>
                                        <xsl:when test="$nativePropertyType='double'">
                                          text_value = axiom_element_get_text(current_element, Environment::getEnv(), current_node);
                                          if(text_value != NULL)
                                          {
                                               /* we keeps float in arrays from their pointers */
                                               <xsl:value-of select="$nativePropertyType"/>* element = (<xsl:value-of select="$nativePropertyType"/>*)AXIS2_MALLOC(Environment::getEnv()-> allocator, sizeof(double));
                                               *element = atof(text_value);

                                               arr_list->push_back(element);
                                          }
                                          <xsl:if test="not(@nillable)">
                                          else
                                          {
					                            WSF_LOG_ERROR_MSG(Environment::getEnv()->log,WSF_LOG_SI, "NULL value is set to a non nillable element <xsl:value-of select="$propertyName"/>");
                                                status = AXIS2_FAILURE;
                                          }
                                          </xsl:if>
                                        </xsl:when>
                                        <xsl:when test="$nativePropertyType='int64_t'">
                                          text_value = axiom_element_get_text(current_element, Environment::getEnv(), current_node);
                                          if(text_value != NULL)
                                          {
                                              /* we keeps int64_t in arrays from their pointers */
                                              <xsl:value-of select="$nativePropertyType"/>* element = (<xsl:value-of select="$nativePropertyType"/>*)AXIS2_MALLOC(Environment::getEnv()-> allocator, sizeof(int64_t));
                                              *element = axutil_strtol(text_value, (char**)NULL, 0);
                                              arr_list->push_back(element);
                                          }
                                          <xsl:if test="not(@nillable)">
                                          else
                                          {
					                            WSF_LOG_ERROR_MSG(Environment::getEnv()->log,WSF_LOG_SI, "NULL value is set to a non nillable element <xsl:value-of select="$propertyName"/>");
                                                status = AXIS2_FAILURE;
                                          }
                                          </xsl:if>
                                        </xsl:when>
                                        <xsl:when test="$nativePropertyType='uint64_t'">
                                          text_value = axiom_element_get_text(current_element, Environment::getEnv(), current_node);
                                          if(text_value != NULL)
                                          {
                                              /* we keeps int64_t in arrays from their pointers */
                                              <xsl:value-of select="$nativePropertyType"/>* element = (<xsl:value-of select="$nativePropertyType"/>*)AXIS2_MALLOC(Environment::getEnv()-> allocator, sizeof(uint64_t));
                                              *element = axutil_strtoul(text_value, (char**)NULL, 0);
                                              arr_list->push_back(element);
                                          }
                                          <xsl:if test="not(@nillable)">
                                          else
                                          {
					                            WSF_LOG_ERROR_MSG(Environment::getEnv()->log,WSF_LOG_SI, "NULL value is set to a non nillable element <xsl:value-of select="$propertyName"/>");
                                                status = AXIS2_FAILURE;
                                          }
                                          </xsl:if>
                                        </xsl:when>
                                        <xsl:when test="$nativePropertyType='wso2wsf::OMElement*'">
                                          text_value = NULL; /* just to avoid warning */
                                          <xsl:choose>
                                            <xsl:when test="@any">
                                            {
                                              axiom_node_t *current_property_node = current_node;
                                              current_node = axiom_node_get_next_sibling(current_node, Environment::getEnv());
                                              axiom_node_detach(current_property_node, Environment::getEnv());
                                              arr_list->push_back(new OMElement(NULL, current_property_node));
                                            }
                                            </xsl:when>
                                            <xsl:otherwise>
                                              if(axiom_node_get_first_child(current_node, Environment::getEnv()))
                                              {
                                                  axiom_node_t *current_property_node = axiom_node_get_first_child(current_node, Environment::getEnv());
                                                  axiom_node_detach(current_property_node, Environment::getEnv());
                                                  arr_list->push_back(new OMElement(NULL,current_property_node));
                                              }
                                              else
                                              {
                                                  status = set<xsl:value-of select="$CName"/>(NULL);
                                              }
                                            </xsl:otherwise>
                                          </xsl:choose>
                                        </xsl:when>
                                        <xsl:when test="$nativePropertyType='bool'">
                                          text_value = axiom_element_get_text(current_element, Environment::getEnv(), current_node);
                                          if(text_value != NULL)
                                          {
                                               if (!axutil_strcasecmp (text_value , "true"))
                                               {
                                                  /* bools are also kept as pointers */
                                                  <xsl:value-of select="$nativePropertyType"/>* element = (<xsl:value-of select="$nativePropertyType"/>*)AXIS2_MALLOC(Environment::getEnv()->allocator,sizeof(bool));
                                                  *element = true;
                                                  arr_list->push_back(element);
                                               }
                                               else
                                               { /*                                                */
                                                  <xsl:value-of select="$nativePropertyType"/>* element = (<xsl:value-of select="$nativePropertyType"/>*)AXIS2_MALLOC(Environment::getEnv()->allocator,sizeof(bool));
                                                  *element = false;
                                                  arr_list->push_back(element);

                                               }
                                          }
                                          <xsl:if test="not(@nillable)">
                                          else
                                          {
					                            WSF_LOG_ERROR_MSG(Environment::getEnv()->log,WSF_LOG_SI, "NULL value is set to a non nillable element <xsl:value-of select="$propertyName"/>");
                                                status = AXIS2_FAILURE;
                                          }
                                          </xsl:if>
                                        </xsl:when>
                                        <xsl:when test="$nativePropertyType='axutil_date_time_t*'">
                                          text_value = axiom_element_get_text(current_element, Environment::getEnv(), current_node);
                                          if(text_value != NULL)
                                          {
                                              axutil_date_time_t* element = axutil_date_time_create(Environment::getEnv());
                                              status = axutil_date_time_deserialize_date_time(element, Environment::getEnv(),
                                                                              text_value);
                                              if(AXIS2_FAILURE ==  status)
                                              {
                                                  WSF_LOG_ERROR_MSG( Environment::getEnv()->log,WSF_LOG_SI,"failed in building element <xsl:value-of select="$propertyName"/> "
                                                                      " %d :: %s", Environment::getEnv()->error->error_number,
                                                                      AXIS2_ERROR_GET_MESSAGE(Environment::getEnv()->error));
                                              }
                                              else
                                              {
                                                arr_list->push_back(element);
                                              }
                                          }
                                          <xsl:if test="not(@nillable)">
                                          else
                                          {
                                                WSF_LOG_ERROR_MSG( Environment::getEnv()->log,WSF_LOG_SI,"NULL value is set to a non nillable element <xsl:value-of select="$propertyName"/>");
                                                status = AXIS2_FAILURE;
                                          }
                                          </xsl:if>
                                        </xsl:when>
                                        <xsl:when test="$nativePropertyType='axutil_base64_binary_t*'">
                                          text_value = axiom_element_get_text(current_element, Environment::getEnv(), current_node);
                                          if(text_value != NULL)
                                          {
                                              axutil_base64_binary_t* element = axutil_base64_binary_create(Environment::getEnv());
                                              status = axutil_base64_binary_set_encoded_binary(element, Environment::getEnv(),
                                                                              text_value);
                                              if(AXIS2_FAILURE ==  status)
                                              {
                                                  WSF_LOG_ERROR_MSG(Environment::getEnv()->log, WSF_LOG_SI, "failed in building element <xsl:value-of select="$propertyName"/> "
                                                                      " %d :: %s", Environment::getEnv()->error->error_number,
                                                                      AXIS2_ERROR_GET_MESSAGE(Environment::getEnv()->error));
                                              }
                                              else
                                              {
                                                arr_list->push_back(element);
                                              }
                                          }
                                          <xsl:if test="not(@nillable)">
                                          else
                                          {
                                                WSF_LOG_ERROR_MSG(Environment::getEnv()->log, WSF_LOG_SI, "NULL value is set to a non nillable element <xsl:value-of select="$propertyName"/>");
                                                status = AXIS2_FAILURE;
                                          }
                                          </xsl:if>
                                        </xsl:when>
                                        <xsl:otherwise>
                                          <!-- TODO: add other types here -->
                                          /* The request handling failed,for the request type - so please do it manually */
                                          text_value = NULL;
                                        </xsl:otherwise>
                                     </xsl:choose>
                                     if(AXIS2_FAILURE ==  status)
                                     {
                                         WSF_LOG_ERROR_MSG(Environment::getEnv()->log, WSF_LOG_SI, "failed in setting the value for <xsl:value-of select="$propertyName"/> ");
                                         if(element_qname)
                                         {
                                            axutil_qname_free(element_qname, Environment::getEnv());
                                         }
                                         if(arr_list)
                                         {
                                            delete arr_list;
                                         }
                                         return false;
                                     }

                                     i++;
                                    <xsl:if test="not(@any)">current_node = axiom_node_get_next_sibling(current_node, Environment::getEnv());</xsl:if>

                                 <xsl:if test="not(@any)">
                                  }
                                  else
                                  {
                                      is_early_node_valid = false;
                                      sequence_broken = 1;
                                  }
                                  </xsl:if>
                               }

                               <xsl:if test="not(@any)">
                                   if (i &lt; <xsl:value-of select="@minOccurs"/>)
                                   {
                                     /* found element out of order */
                                     WSF_LOG_ERROR_MSG( Environment::getEnv()->log,WSF_LOG_SI,"<xsl:value-of select="$propertyName"/> (@minOccurs = '<xsl:value-of select="@minOccurs"/>') only have %d elements", i);
                                     if(element_qname)
                                     {
                                        axutil_qname_free(element_qname, Environment::getEnv());
                                     }
                                     if(arr_list)
                                     {
                                        delete arr_list;
                                     }
                                     return false;
                                   }
                               </xsl:if>

                               if(0 == arr_list->size())
                               {
                                    delete arr_list;
                               }
                               else
                               {
                                    status = set<xsl:value-of select="$CName"/>(arr_list);
                               }

                             </xsl:when>
                             <xsl:otherwise> <!-- otherwse for "$ordered or not($anon or $istype)" -->
                                <xsl:choose>
                                  <xsl:when test="@any"></xsl:when>
                                  <xsl:when test="@nsuri and @nsuri != ''">
                                    element_qname = axutil_qname_create(Environment::getEnv(), "<xsl:value-of select="$propertyName"/>", "<xsl:value-of select="@nsuri"/>", NULL);
                                  </xsl:when>
                                  <xsl:otherwise>
                                    element_qname = axutil_qname_create(Environment::getEnv(), "<xsl:value-of select="$propertyName"/>", NULL, NULL);
                                  </xsl:otherwise>
                                </xsl:choose>
                                /*
                                 * because elements are not ordered we should surf all the siblings to pick the right one
                                 */
                               <!-- For non-ordered arrays we are not using is_early_node_valid? -->
                               for (i = 0, current_node = first_node; current_node != NULL; <xsl:if test="not(@any)">current_node = axiom_node_get_next_sibling(current_node, Environment::getEnv())</xsl:if>)
                                             <!-- We are not moving current_node to next sibling here if it an any type, because we already have done the move -->
                               {
                                  if(axiom_node_get_node_type(current_node, Environment::getEnv()) != AXIOM_ELEMENT)
                                  {
                                     <xsl:if test="@any">
                                     current_node = axiom_node_get_next_sibling(current_node, Environment::getEnv());
                                     </xsl:if>
                                     continue;
                                  }
                                  <xsl:if test="not(@any)">
                                  current_element = (axiom_element_t *)axiom_node_get_data_element(current_node, Environment::getEnv());
                                  mqname = axiom_element_get_qname(current_element, Environment::getEnv(), current_node);

                                  if (axutil_qname_equals(element_qname, Environment::getEnv(), mqname)<xsl:if test="not(@nsuri) or @nsuri=''"> || !axutil_strcmp("<xsl:value-of select="$propertyName"/>", axiom_element_get_localname(current_element, Environment::getEnv()))</xsl:if>)
                                  {
                                  </xsl:if>
                                       /* found the required element */
                                       is_early_node_valid = true;
                                      <!-- changes to following choose tag should be changed in another 2 places -->
                                     <xsl:choose>
                                        <xsl:when test="@ours">
                                          <xsl:value-of select="@type"/>* element = new <xsl:value-of select="@type"/>();
                                          
                                          status =  element->deserialize(&amp;current_node, &amp;is_early_node_valid, <xsl:choose><xsl:when test="$choice">true</xsl:when><xsl:otherwise>false</xsl:otherwise></xsl:choose>);
                                          if(AXIS2_FAILURE ==  status)
                                          {
                                              WSF_LOG_ERROR_MSG(Environment::getEnv()->log, WSF_LOG_SI, "failed in building element <xsl:value-of select="$propertyName"/> "
                                                                  " %d :: %s", Environment::getEnv()->error->error_number,
                                                                  AXIS2_ERROR_GET_MESSAGE(Environment::getEnv()->error));
                                          }
                                          else
                                          {
                                             arr_list->push_back(element);
                                          }
                                        </xsl:when>
                                        <xsl:when test="$nativePropertyType='std::string'">
                                          text_value = axiom_element_get_text(current_element, Environment::getEnv(), current_node);
                                          if(text_value != NULL)
                                          {
                                                arr_list->push_back(new std::string(text_value));
                                          }
                                          <xsl:if test="not(@nillable)">
                                          else
                                          {
                                             /*
                                               * axis2_qname_t *qname = NULL;
                                               * axiom_attribute_t *the_attri = NULL;
                                               * 
                                               * qname = axutil_qname_create(Environment::getEnv(), "nil", "http://www.w3.org/2001/XMLSchema-instance", "xsi");
                                               * the_attri = axiom_element_get_attribute(current_element, Environment::getEnv(), qname);
                                               */
                                           
                                              /* currently thereis a bug in the axiom_element_get_attribute, so we have to go to this bad method */
                                             
                                              axiom_attribute_t *the_attri = NULL;
                                              axis2_char_t *attrib_text = NULL;
                                              axutil_hash_t *attribute_hash = NULL;
                                             
                                              attribute_hash = axiom_element_get_all_attributes(current_element, Environment::getEnv());
                                             
                                              attrib_text = NULL;
                                              if(attribute_hash)
                                              {
                                                   axutil_hash_index_t *hi;
                                                   void *val;
                                                   const void *key;
                                             
                                                   for (hi = axutil_hash_first(attribute_hash, Environment::getEnv()); hi; hi = axutil_hash_next(Environment::getEnv(), hi))
                                                   {
                                                       axutil_hash_this(hi, &amp;key, NULL, &amp;val);
                                                       
                                                       if(strstr((axis2_char_t*)key, "nil|http://www.w3.org/2001/XMLSchema-instance"))
                                                       {
                                                           the_attri = (axiom_attribute_t*)val;
                                                           break;
                                                       }
                                                   }
                                              }
                                             
                                              if(the_attri)
                                              {
                                                  attrib_text = axiom_attribute_get_value(the_attri, Environment::getEnv());
                                              }
                                              else
                                              {
                                                  /* this is hoping that attribute is stored in "http://www.w3.org/2001/XMLSchema-instance", this happnes when name is in default namespace */
                                                  attrib_text = axiom_element_get_attribute_value_by_name(current_element, Environment::getEnv(), "nil");
                                              }
                                             
                                              if(attrib_text &amp;&amp; 0 == axutil_strcmp(attrib_text, "1"))
                                              {
                                                  WSF_LOG_ERROR_MSG( Environment::getEnv()->log,WSF_LOG_SI,"NULL value is set to a non nillable element <xsl:value-of select="$propertyName"/>");
                                                  status = AXIS2_FAILURE;
                                              }
                                              else
                                              {
                                                  /* after all, we found this is a empty string */
                                                  arr_list->push_back(new std::string(""));
                                              }
                                          }
                                          </xsl:if>
                                        </xsl:when>
                                        <xsl:when test="$nativePropertyType='axutil_qname_t*'">
                                          text_value = axiom_element_get_text(current_element, Environment::getEnv(), current_node);
                                          if(text_value != NULL)
                                          {
                                            prefix_found = false;
                                            for(cp = (axis2_char_t*)text_value; *cp; cp ++)
                                            {
                                                if(*cp == ':')
                                                {
                                                    *cp = '\0';
                                                    cp ++;
                                                    prefix_found  = true;
                                                    break;
                                                }
                                            }
                                          
                                            if(prefix_found)
                                            {
                                                /* node value contain  the prefix */
                                                qname_ns = axiom_element_find_namespace_uri(current_element, Environment::getEnv(), text_value, current_node);
                                            }
                                            else
                                            {
                                                /* Then it is the default namespace */
                                                cp = (axis2_char_t*)text_value;
                                                qname_ns = axiom_element_get_default_namespace(current_element, Environment::getEnv(), current_node);
                                            }
                                          
                                            <!-- we are done extracting info, just set the extracted value to the qname -->
                                           
                                            arr_list->push_back(
                                                    axutil_qname_create(
                                                          Environment::getEnv(),
                                                          cp, /* cp contain the localname */
                                                          axiom_namespace_get_uri(qname_ns, Environment::getEnv()),
                                                          axiom_namespace_get_prefix(qname_ns, Environment::getEnv())));
                                          }
                                          <xsl:if test="not(@nillable)">
                                          else
                                          {
                                                WSF_LOG_ERROR_MSG( Environment::getEnv()->log,WSF_LOG_SI,"NULL value is set to a non nillable element <xsl:value-of select="$propertyName"/>");
                                                status = AXIS2_FAILURE;
                                          }
                                          </xsl:if>
                                        </xsl:when>
                                        <xsl:when test="$nativePropertyType='axutil_uri_t*'">
                                          text_value = axiom_element_get_text(current_element, Environment::getEnv(), current_node);
                                          if(text_value != NULL)
                                          {
                                                arr_list->push_back(axutil_uri_parse_string(Environment::getEnv(), text_value));
                                          }
                                          <xsl:if test="not(@nillable)">
                                          else
                                          {
                                                WSF_LOG_ERROR_MSG( Environment::getEnv()->log,WSF_LOG_SI,"NULL value is set to a non nillable element <xsl:value-of select="$propertyName"/>");
                                                status = AXIS2_FAILURE;
                                          }
                                          </xsl:if>
                                        </xsl:when>
                                        <xsl:when test="$nativePropertyType='axutil_duration_t*'">
                                          text_value = axiom_element_get_text(current_element, Environment::getEnv(), current_node);
                                          if(text_value != NULL)
                                          {
                                                arr_list->push_back(axutil_duration_create_from_string(Environment::getEnv(), text_value));
                                          }
                                          <xsl:if test="not(@nillable)">
                                          else
                                          {
                                                WSF_LOG_ERROR_MSG( Environment::getEnv()->log,WSF_LOG_SI,"NULL value is set to a non nillable element <xsl:value-of select="$propertyName"/>");
                                                status = AXIS2_FAILURE;
                                          }
                                          </xsl:if>
                                        </xsl:when>
                                        <xsl:when test="$nativePropertyType='char' or $nativePropertyType='unsigned char'">
                                          text_value = axiom_element_get_text(current_element, Environment::getEnv(), current_node);
                                          if(text_value != NULL)
                                          {

                                              /* we keeps  in arrays from their pointers */
                                              <xsl:value-of select="$nativePropertyType"/>* element = AXIS2_MALLOC(Environment::getEnv()-> allocator, 64);
                                              *element = (char)(*text_value);

                                              arr_list->push_back(element);
                                          }
                                          <xsl:if test="not(@nillable)">
                                          else
                                          {
                                                WSF_LOG_ERROR_MSG( Environment::getEnv()->log,WSF_LOG_SI,"NULL value is set to a non nillable element <xsl:value-of select="$propertyName"/>");
                                                status = AXIS2_FAILURE;
                                          }
                                          </xsl:if>
                                        </xsl:when>
                                        <xsl:when test="$nativePropertyType='int' or $nativePropertyType='unsigned int'">
                                          text_value = axiom_element_get_text(current_element, Environment::getEnv(), current_node);
                                          if(text_value != NULL)
                                          {
                                              /* we keeps ints in arrays from their pointers */
                                              <xsl:value-of select="$nativePropertyType"/>* element = AXIS2_MALLOC(Environment::getEnv()-> allocator, sizeof(int));
                                              *element = atoi(text_value);

                                              arr_list->push_back(element);
                                          }
                                          <xsl:if test="not(@nillable)">
                                          else
                                          {
                                                WSF_LOG_ERROR_MSG( Environment::getEnv()->log,WSF_LOG_SI,"NULL value is set to a non nillable element <xsl:value-of select="$propertyName"/>");
                                                status = AXIS2_FAILURE;
                                          }
                                          </xsl:if>
                                        </xsl:when>
                                        <xsl:when test="$nativePropertyType='axis2_byte_t' or $nativePropertyType='axis2_unsigned_byte_t'">
                                          text_value = axiom_element_get_text(current_element, Environment::getEnv(), current_node);
                                          if(text_value != NULL)
                                          {
                                            /*                                    */
                                              <xsl:value-of select="$nativePropertyType"/>* element = AXIS2_MALLOC(Environment::getEnv()-> allocator, sizeof(int));
                                              *element = atoi(text_value);
                                              arr_list->push_back(element);
                                          }
                                          <xsl:if test="not(@nillable)">
                                          else
                                          {
                                                WSF_LOG_ERROR_MSG("Environment::getEnv()->log,WSF_LOG_SI,NULL value is set to a non nillable element <xsl:value-of select="$propertyName"/>");
                                                status = AXIS2_FAILURE;
                                          }
                                          </xsl:if>
                                        </xsl:when>
                                        <xsl:when test="$nativePropertyType='short' or $nativePropertyType='unsigned short'">
                                          text_value = axiom_element_get_text(current_element, Environment::getEnv(), current_node);
                                          if(text_value != NULL)
                                          {
                                               /* we keeps ints in arrays from their pointers */
                                               <xsl:value-of select="$nativePropertyType"/>* element = AXIS2_MALLOC(Environment::getEnv()-> allocator, sizeof(short));
                                               *element = atoi(text_value);
                                               arr_list->push_back(element);
                                          }
                                          <xsl:if test="not(@nillable)">
                                          else
                                          {
                                                WSF_LOG_ERROR_MSG( Environment::getEnv()->log,WSF_LOG_SI,"NULL value is set to a non nillable element <xsl:value-of select="$propertyName"/>");
                                                status = AXIS2_FAILURE;
                                          }
                                          </xsl:if>
                                        </xsl:when>
                                        <xsl:when test="$nativePropertyType='float'">
                                          /* we keeps float in arrays from their pointers */
                                          text_value = axiom_element_get_text(current_element, Environment::getEnv(), current_node);
                                          if(text_value != NULL)
                                          {
                                             /*                                       */
                                              <xsl:value-of select="$nativePropertyType"/>* element = AXIS2_MALLOC(Environment::getEnv()-> allocator, sizeof(float));
                                              *element = atof(text_value);
                                              arr_list->push_back(element);
                                          }
                                          <xsl:if test="not(@nillable)">
                                          else
                                          {
                                                WSF_LOG_ERROR_MSG( Environment::getEnv()->log,WSF_LOG_SI,"NULL value is set to a non nillable element <xsl:value-of select="$propertyName"/>");
                                                status = AXIS2_FAILURE;
                                          }
                                          </xsl:if>
                                        </xsl:when>
                                        <xsl:when test="$nativePropertyType='double'">
                                          /* we keeps float in arrays from their pointers */
                                          text_value = axiom_element_get_text(current_element, Environment::getEnv(), current_node);
                                          if(text_value != NULL)
                                          {
                                              <xsl:value-of select="$nativePropertyType"/>* element = AXIS2_MALLOC(Environment::getEnv()-> allocator, sizeof(double));
                                              *element = atof(text_value);
                                              arr_list->push_back(element);
                                          }
                                          <xsl:if test="not(@nillable)">
                                          else
                                          {
                                                WSF_LOG_ERROR_MSG( Environment::getEnv()->log,WSF_LOG_SI,"NULL value is set to a non nillable element <xsl:value-of select="$propertyName"/>");
                                                status = AXIS2_FAILURE;
                                          }
                                          </xsl:if>
                                        </xsl:when>
                                        <xsl:when test="$nativePropertyType='int64_t'">
                                          /* we keeps int64_t in arrays from their pointers */
                                          text_value = axiom_element_get_text(current_element, Environment::getEnv(), current_node);
                                          if(text_value != NULL)
                                          {
                                               <xsl:value-of select="$nativePropertyType"/>* element = AXIS2_MALLOC(Environment::getEnv()-> allocator, sizeof(int64_t));
                                               *element = axutil_strtol(text_value, (char**)NULL,0);
                                               arr_list->push_back(element);
                                          }
                                          <xsl:if test="not(@nillable)">
                                          else
                                          {
                                                WSF_LOG_ERROR_MSG( Environment::getEnv()->log,WSF_LOG_SI,"NULL value is set to a non nillable element <xsl:value-of select="$propertyName"/>");
                                                status = AXIS2_FAILURE;
                                          }
                                          </xsl:if>
                                        </xsl:when>
                                        <xsl:when test="$nativePropertyType='uint64_t'">
                                          /* we keeps int64_t in arrays from their pointers */
                                          text_value = axiom_element_get_text(current_element, Environment::getEnv(), current_node);
                                          if(text_value != NULL)
                                          {
                                                <xsl:value-of select="$nativePropertyType"/>* element = AXIS2_MALLOC(Environment::getEnv()-> allocator, sizeof(uint64_t));
                                                *element = axutil_strtol(text_value, (char**)NULL,0);
                                                arr_list->push_back(element);
                                          }
                                          <xsl:if test="not(@nillable)">
                                          else
                                          {
                                                WSF_LOG_ERROR_MSG( Environment::getEnv()->log,WSF_LOG_SI,"NULL value is set to a non nillable element <xsl:value-of select="$propertyName"/>");
                                                status = AXIS2_FAILURE;
                                          }
                                          </xsl:if>
                                        </xsl:when>
                                        <xsl:when test="$nativePropertyType='wso2wsf::OMElement*'">
                                          text_value = NULL; /* just to avoid warning */
                                          <xsl:choose>
                                            <xsl:when test="@any">
                                            {
                                              axiom_node_t *current_property_node = current_node;
                                              current_node = axiom_node_get_next_sibling(current_node, Environment::getEnv());
                                              axiom_node_detach(current_property_node, Environment::getEnv());
                                              arr_list->push_back(new OMElement(NULL,current_property_node));
                                            }
                                            </xsl:when>
                                            <xsl:otherwise>
                                              if(axiom_node_get_first_child(current_node, Environment::getEnv()))
                                              {
                                                  axiom_node_t *current_property_node = axiom_node_get_first_child(current_node, Environment::getEnv());
                                                  axiom_node_detach(current_property_node, Environment::getEnv());
                                                  arr_list->push_back(new OMElement(NULL,current_property_node));
                                              }
                                            </xsl:otherwise>
                                          </xsl:choose>
                                        </xsl:when>
                                        <xsl:when test="$nativePropertyType='bool'">
                                          text_value = axiom_element_get_text(current_element, Environment::getEnv(), current_node);
                                          if(text_value != NULL)
                                          {
                                              if (!axutil_strcasecmp (text_value , "true"))
                                              {
                                                  <xsl:value-of select="$nativePropertyType"/>* element = AXIS2_MALLOC(env->allocator,sizeof(bool));
                                                  *element = true;
                                                  arr_list->push_back(element);
                                              }
                                              else
                                              {
                                                  <xsl:value-of select="$nativePropertyType"/>* element = AXIS2_MALLOC(env->allocator,sizeof(bool));
                                                  *element = false;
                                                  arr_list->push_back(element);
                                              }
                                          }
                                          <xsl:if test="not(@nillable)">
                                          else
                                          {
                                                WSF_LOG_ERROR_MSG( Environment::getEnv()->log,WSF_LOG_SI,"NULL value is set to a non nillable element <xsl:value-of select="$propertyName"/>");
                                                status = AXIS2_FAILURE;
                                          }
                                          </xsl:if>
                                        </xsl:when>
                                        <xsl:when test="$nativePropertyType='axutil_date_time_t*'">
                                          axutil_date_time_t* element = axutil_date_time_create(Environment::getEnv());
                                          text_value = axiom_element_get_text(current_element, Environment::getEnv(), current_node);
                                          if(text_value != NULL)
                                          {
                                              status = axutil_date_time_deserialize_date_time(element, Environment::getEnv(),
                                                                              text_value);
                                              if(AXIS2_FAILURE ==  status)
                                              {
                                                  WSF_LOG_ERROR_MSG( Environment::getEnv()->log,WSF_LOG_SI,"failed in building element <xsl:value-of select="$propertyName"/> ");
                                              }
                                              else
                                              {
                                                arr_list->push_back(element);
                                              }
                                          }
                                          <xsl:if test="not(@nillable)">
                                          else
                                          {
                                                WSF_LOG_ERROR_MSG( Environment::getEnv()->log,WSF_LOG_SI,"NULL value is set to a non nillable element <xsl:value-of select="$propertyName"/>");
                                                status = AXIS2_FAILURE;
                                          }
                                          </xsl:if>

                                        </xsl:when>
                                        <xsl:when test="$nativePropertyType='axutil_base64_binary_t*'">
                                          axutil_base64_binary_t* element = axutil_base64_binary_create(Environment::getEnv());
                                          text_value = axiom_element_get_text(current_element, Environment::getEnv(), current_node);
                                          if(text_value != NULL)
                                          {
                                              status = axutil_base64_binary_set_encoded_binary(element, Environment::getEnv(), text_value);
                                              if(AXIS2_FAILURE ==  status)
                                              {
                                                  WSF_LOG_ERROR_MSG( Environment::getEnv()->log,WSF_LOG_SI,"failed in building element <xsl:value-of select="$propertyName"/> ");
                                              }
                                              else
                                              {
                                                 arr_list->push_back(element);
                                              }
                                          }
                                          <xsl:if test="not(@nillable)">
                                          else
                                          {
                                                WSF_LOG_ERROR_MSG( Environment::getEnv()->log,WSF_LOG_SI,"NULL value is set to a non nillable element <xsl:value-of select="$propertyName"/>");
                                                status = AXIS2_FAILURE;
                                          }
                                          </xsl:if>


                                        </xsl:when>
                                        <xsl:otherwise>
                                          <!-- TODO: add other types here -->
                                          /* The request handling failed.  - so please do it manually */
                                          text_value = NULL;
                                        </xsl:otherwise>
                                     </xsl:choose>
                                     if(AXIS2_FAILURE ==  status)
                                     {
                                         if(element_qname)
                                         {
                                             axutil_qname_free(element_qname, Environment::getEnv());
                                         }
                                         WSF_LOG_ERROR_MSG( Environment::getEnv()->log,WSF_LOG_SI,"failed in setting the value for <xsl:value-of select="$propertyName"/> ");
                                         return AXIS2_FAILURE;
                                     }

                                     i ++;
                                  <xsl:if test="not(@any)">
                                  }
                                  </xsl:if>
                               }
                               status = set<xsl:value-of select="$CName"/>(arr_list);
                             </xsl:otherwise> <!--closing otherwise for "$ordered  or not($anon or $istype)" -->
                           </xsl:choose> <!-- chooses for ordered or not @ordered or not($anon or $istype)-->
                            } <!-- scoping for arr_list -->
                        </xsl:otherwise> <!-- closing when it is all the way an array -->
                      </xsl:choose> <!-- check array or not -->
                   </xsl:otherwise> <!-- closing when it is an element not(@attribute) -->
                 </xsl:choose> <!--- chooosing for element or attribute -->
                 <xsl:if test="not(@simple)">
                  if(element_qname)
                  {
                     axutil_qname_free(element_qname, Environment::getEnv());
                     element_qname = NULL;
                  }
                 </xsl:if>
              </xsl:for-each> <!-- closing for each property -->

            <xsl:if test="$particleClass">
                *dp_parent = current_node;
                *dp_is_early_node_valid = is_early_node_valid;
            </xsl:if>
          return status;
       }

          bool WSF_CALL
          <xsl:value-of select="$CPPNamespace"/><xsl:value-of select="$axis2_name"/>::isParticle()
          {
            <xsl:choose>
              <xsl:when test="$particleClass">
                 return true;
              </xsl:when>
              <xsl:otherwise>
                 return false;
              </xsl:otherwise>
            </xsl:choose>
          }


          void WSF_CALL
          <xsl:value-of select="$CPPNamespace"/><xsl:value-of select="$axis2_name"/>::declareParentNamespaces(
                    axiom_element_t *parent_element,
                    axutil_hash_t *namespaces, int *next_ns_index)
          {
            <xsl:variable name="check_anything_to_declare">
                  <xsl:for-each select="property">
                    <xsl:if test="@type='axutil_qname_t*'">yes</xsl:if>
                  </xsl:for-each>
            </xsl:variable>
            <xsl:choose>
                <xsl:when test="contains($check_anything_to_declare, 'yes')">
                    axiom_namespace_t *element_ns = NULL;
                    axis2_char_t *qname_uri;
                    axis2_char_t *qname_prefix;
                </xsl:when>
                <xsl:otherwise>
                  /* Here this is an empty function, Nothing to declare */
                </xsl:otherwise>
            </xsl:choose>

                <xsl:for-each select="property">
                  <xsl:variable name="nativePropertyType"> <!--these are used in arrays to take the native type-->
                     <xsl:choose>
                       <xsl:when test="not(@type)">wso2wsf::OMElement*</xsl:when> <!-- these are anonymous -->
                       <xsl:otherwise><xsl:value-of select="@type"/></xsl:otherwise>
                     </xsl:choose>
                  </xsl:variable>
                  <xsl:variable name="CName"><xsl:value-of select="@cname"/></xsl:variable>
    
                  <xsl:variable name="propertyInstanceName"><!--these are used in arrays to take the native type-->
                     <xsl:choose>
                       <xsl:when test="@isarray">element</xsl:when>
                       <xsl:otherwise>property_<xsl:value-of select="$CName"/></xsl:otherwise>
                     </xsl:choose>
                  </xsl:variable>
                  <xsl:choose>
                    <!-- add axutil_qname_t namespaces -->
                    <xsl:when test="$nativePropertyType='axutil_qname_t*'">
                      qname_uri = axutil_qname_get_uri(<xsl:value-of select="$propertyInstanceName"/>, Environment::getEnv());
                      if(qname_uri &amp;&amp; !axutil_strcmp(qname_uri, ""))
                      {
                          if(!(qname_prefix = (axis2_char_t*)axutil_hash_get(namespaces, qname_uri, AXIS2_HASH_KEY_STRING)))
                          {
                              qname_prefix = (axis2_char_t*)AXIS2_MALLOC(Environment::getEnv()->allocator, sizeof (axis2_char_t) * ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT);

                              
                              sprintf(qname_prefix, "q%d", (*next_ns_index)++); <!-- just different prefix for the special case -->
                              axutil_hash_set(namespaces, qname_uri, AXIS2_HASH_KEY_STRING, qname_prefix);

                              if(parent_element)
                              {
                                    element_ns = axiom_namespace_create(Environment::getEnv(), qname_uri,
                                                                        qname_prefix);
                                    axiom_element_declare_namespace_assume_param_ownership(parent_element, Environment::getEnv(), element_ns);
                              }
                          }
                      }
                    </xsl:when>
                  </xsl:choose>
              </xsl:for-each> <!--closing the for-each select="property" -->
          }

        <xsl:if test="@simple">
            char* WSF_CALL
            <xsl:value-of select="$CPPNamespace"/><xsl:value-of select="$axis2_name"/>::serializeToString(axutil_hash_t *namespaces)
            {
                axis2_char_t *text_value = NULL;
                axis2_char_t *qname_uri = NULL;
                axis2_char_t *qname_prefix = NULL;
                <xsl:if test="itemtype">
                   int i;
                   int allocated_len = 0;
                   axis2_char_t *tmp_value;
                </xsl:if>

                <xsl:for-each select="property">
                  <xsl:if test="position()=1"> <!-- just to make sure it doesn't go for more than one time -->
                    <xsl:variable name="position"><xsl:value-of select="position()"/></xsl:variable>
                    <xsl:variable name="propertyType">
                       <xsl:choose>
                         <xsl:when test="@isarray">std::vector&lt;<xsl:value-of select="@type"/><xsl:if test="@ours or @type='std::string' or @type='unsigned char' or @type='unsigned short' or @type='uint64_t' or @type='unsigned int' or @type='short' or @type='char' or @type='int' or @type='float' or @type='double' or @type='int64_t'"><xsl:text>*</xsl:text></xsl:if>&gt;*</xsl:when>
                         <xsl:when test="not(@type)">wso2wsf::OMElement*</xsl:when> <!-- these are anonymous -->
                         <xsl:otherwise><xsl:value-of select="@type"/><xsl:if test="@ours"><xsl:text>*</xsl:text></xsl:if></xsl:otherwise>
                       </xsl:choose>
                    </xsl:variable>
                    <xsl:variable name="nativePropertyType"> <!--these are used in arrays to take the native type-->
                       <xsl:choose>
                         <xsl:when test="not(@type)">wso2wsf::OMelement*</xsl:when> <!-- these are anonymous -->
                         <xsl:otherwise><xsl:value-of select="@type"/><xsl:if test="@ours"><xsl:text>*</xsl:text></xsl:if></xsl:otherwise>
                       </xsl:choose>
                    </xsl:variable>
                    <xsl:variable name="propertyName"><xsl:value-of select="@originalName"/></xsl:variable>
                    <xsl:variable name="CName"><xsl:value-of select="@cname"/></xsl:variable>
      
                    <xsl:variable name="propertyInstanceName"><!--these are used in arrays to take the native type-->
                       <xsl:choose>
                         <xsl:when test="@isarray">
                           <xsl:choose>
                            <xsl:when test="@type='std::string' or @type='unsigned char' or @type='unsigned short' or @type='uint64_t' or @type='unsigned int' or @type='short' or @type='char' or @type='int' or @type='float' or @type='double' or @type='int64_t'">
                                <xsl:text>(*element)</xsl:text>
                            </xsl:when>
                           <xsl:otherwise>element</xsl:otherwise>
                        </xsl:choose></xsl:when>
                         <xsl:otherwise>property_<xsl:value-of select="$CName"/></xsl:otherwise>
                       </xsl:choose>
                    </xsl:variable>
                    <xsl:variable name="justPropertyInstanceName"><!--these are used in arrays to take the native type-->
                       <xsl:choose>
                         <xsl:when test="@isarray">element</xsl:when>
                         <xsl:otherwise>property_<xsl:value-of select="$CName"/></xsl:otherwise>
                       </xsl:choose>
                    </xsl:variable>


                   <xsl:choose>
                      <!-- add int s -->
                      <xsl:when test="$nativePropertyType='int' or $nativePropertyType='unsigned int'">
                         text_value = (axis2_char_t*) AXIS2_MALLOC (Environment::getEnv()-> allocator, sizeof (axis2_char_t) * ADB_DEFAULT_DIGIT_LIMIT);
                         sprintf (text_value, "%d", <xsl:value-of select="$propertyInstanceName"/>);
                      </xsl:when>
                      <!-- add axis2_byte_t s -->
                      <xsl:when test="$nativePropertyType='axis2_byte_t' or $nativePropertyType='axis2_unsigned_byte_t'">
                         text_value = (axis2_char_t*) AXIS2_MALLOC (Environment::getEnv()-> allocator, sizeof (axis2_char_t) * ADB_DEFAULT_DIGIT_LIMIT);
                         sprintf (text_value, "%d", <xsl:value-of select="$propertyInstanceName"/>);
                      </xsl:when>

                      <!-- add char s -->
                      <xsl:when test="$nativePropertyType='char' or $nativePropertyType='unsigned char'">
                         text_value = (axis2_char_t*) AXIS2_MALLOC (Environment::getEnv()-> allocator, sizeof (axis2_char_t) * ADB_DEFAULT_DIGIT_LIMIT);
                         sprintf (text_value, "%c", <xsl:value-of select="$propertyInstanceName"/>);
                      </xsl:when>

                      <!-- add short s -->
                      <xsl:when test="$nativePropertyType='short' or $nativePropertyType='unsigned short'">
                         text_value = (axis2_char_t*) AXIS2_MALLOC (Environment::getEnv()-> allocator, sizeof (axis2_char_t) * ADB_DEFAULT_DIGIT_LIMIT);
                         sprintf (text_value, "%d", <xsl:value-of select="$propertyInstanceName"/>);
                      </xsl:when>

                      <!-- add int64_t s -->
                      <xsl:when test="$nativePropertyType='int64_t'">
                         text_value = (axis2_char_t*) AXIS2_MALLOC (Environment::getEnv()-> allocator, sizeof (axis2_char_t) * ADB_DEFAULT_DIGIT_LIMIT);
                         sprintf (text_value, AXIS2_PRINTF_INT64_FORMAT_SPECIFIER, (int64_t)<xsl:value-of select="$propertyInstanceName"/>);
                      </xsl:when>

                      <xsl:when test="$nativePropertyType='uint64_t'">
                         text_value = (axis2_char_t*) AXIS2_MALLOC (Environment::getEnv()-> allocator, sizeof (axis2_char_t) * ADB_DEFAULT_DIGIT_LIMIT);
                         sprintf (text_value, AXIS2_PRINTF_UINT64_FORMAT_SPECIFIER, (uint64_t)<xsl:value-of select="$propertyInstanceName"/>);
                      </xsl:when>

                      <!-- add float s -->
                      <xsl:when test="$nativePropertyType='float'">
                         text_value = (axis2_char_t*) AXIS2_MALLOC (Environment::getEnv()-> allocator, sizeof (axis2_char_t) * ADB_DEFAULT_DIGIT_LIMIT);
                         sprintf (text_value, "%f", <xsl:value-of select="$propertyInstanceName"/>);
                      </xsl:when>

                      <!-- add double s -->
                      <xsl:when test="$nativePropertyType='double'">
                         text_value = (axis2_char_t*) AXIS2_MALLOC (Environment::getEnv()-> allocator, sizeof (axis2_char_t) * ADB_DEFAULT_DIGIT_LIMIT);
                         sprintf (text_value, "%f", <xsl:value-of select="$propertyInstanceName"/>);
                      </xsl:when>

                      <!-- add axis2_char_t* s -->
                      <xsl:when test="$nativePropertyType='std::string'">
                         text_value = (axis2_char_t*)axutil_xml_quote_string(Environment::getEnv(), (axis2_char_t*)<xsl:value-of select="$propertyInstanceName"/>.c_str(), false);
                         if (!text_value)
                         {
                             text_value = (axis2_char_t*)axutil_strdup(Environment::getEnv(), <xsl:value-of select="$propertyInstanceName"/>.c_str());
                         }
                      </xsl:when>

                      <!-- add axutil_uri_t s -->
                      <xsl:when test="$nativePropertyType='axutil_uri_t*'">
                         text_value = axutil_uri_to_string(<xsl:value-of select="$propertyInstanceName"/>, Environment::getEnv(), AXIS2_URI_UNP_OMITUSERINFO);
                      </xsl:when>

                      <!-- add axutil_duration_t s -->
                      <xsl:when test="$nativePropertyType='axutil_duration_t*'">
                         text_value = axutil_duration_serialize_duration(<xsl:value-of select="$propertyInstanceName"/>, Environment::getEnv());
                      </xsl:when>

                      <!-- add axutil_qname_t s -->
                      <xsl:when test="$nativePropertyType='axutil_qname_t*'">
                        <!-- namespaces are declared in _declare_parent_namespaces -->
                        qname_uri = axutil_qname_get_uri(<xsl:value-of select="$propertyInstanceName"/>, Environment::getEnv());
                        if(qname_uri == NULL)
                        {
                              text_value = (axis2_char_t*)axutil_strdup(Environment::getEnv(), axutil_qname_get_localpart(<xsl:value-of select="$propertyInstanceName"/>, Environment::getEnv()));
                        }
                        else
                        {
                          qname_prefix = (axis2_char_t*)axutil_hash_get(namespaces, qname_uri, AXIS2_HASH_KEY_STRING);
                          if(qname_prefix != NULL)
                          {
                              text_value = (axis2_char_t*) AXIS2_MALLOC (Environment::getEnv()-> allocator,
                                          sizeof (axis2_char_t) * (ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT +
                                                              axutil_strlen(axutil_qname_get_localpart(<xsl:value-of select="$propertyInstanceName"/>, Environment::getEnv())) + 2));
                              sprintf(text_value, "%s:%s", qname_prefix,
                                                        axutil_qname_get_localpart(<xsl:value-of select="$propertyInstanceName"/>, Environment::getEnv()));
                          }
                          else
                          {
                              WSF_LOG_ERROR_MSG( Environment::getEnv()->log,WSF_LOG_SI,"Failed in serialize_to_string value for <xsl:value-of select="$propertyName"/>, "
                                                          "Prefix is not declared beofre using");
                              return NULL;
                          }
                        }
                      </xsl:when>

                      <!-- add bool s -->
                      <xsl:when test="$nativePropertyType='bool'">
                         <!--text_value = (<xsl:value-of select="$propertyInstanceName"/>)?"true":"false";-->
                         text_value = (axis2_char_t*)(axutil_strdup(Environment::getEnv(), (<xsl:value-of select="$propertyInstanceName"/>)?"true":"false"));
                      </xsl:when>
                      <!-- add axis2_date_time_t s -->
                      <xsl:when test="$nativePropertyType='axutil_date_time_t*'">
                         text_value =  axutil_date_time_serialize_date_time(<xsl:value-of select="$propertyInstanceName"/>, Environment::getEnv());
                      </xsl:when>
                      <!-- add axis2_base64_binary_t s -->
                      <xsl:when test="$nativePropertyType='axutil_base64_binary_t*'">
                         text_value =  axutil_base64_binary_get_encoded_binary(<xsl:value-of select="$propertyInstanceName"/>, Environment::getEnv());
                      </xsl:when>
                      <xsl:when test="@ours">
                        if(<xsl:value-of select="$propertyInstanceName"/>)
                        {
                            text_value = <xsl:value-of select="$propertyInstanceName"/>->serializeToString(namespaces);
                        }
                      </xsl:when>
                      <xsl:otherwise>
                        <!--TODO: add new property types -->
                        /* can not handle the property type <xsl:value-of select="$nativePropertyType"/>*/
                        text_value = NULL;
                      </xsl:otherwise>
                    </xsl:choose>
                  </xsl:if>
                </xsl:for-each>

            <!-- The section covers the list types, this is a loop always occurs just 1 time-->
            <xsl:for-each select="itemtype">
                <xsl:variable name="propertyType">std::vector&lt;<xsl:value-of select="@type"/><xsl:if test="@ours or @type='std::string' or @type='unsigned char' or @type='unsigned short' or @type='uint64_t' or @type='unsigned int' or @type='short' or @type='char' or @type='int' or @type='float' or @type='double' or @type='int64_t'"><xsl:text>*</xsl:text></xsl:if>&gt;*</xsl:variable>
                <xsl:variable name="propertyName"><xsl:value-of select="$just_name"></xsl:value-of></xsl:variable>
                <xsl:variable name="CName"><xsl:value-of select="$just_name"></xsl:value-of></xsl:variable>
 
                <xsl:variable name="nativePropertyType"> <!--these are used in arrays to take the native type-->
                   <xsl:choose>
                     <xsl:when test="not(@type)">wso2wsf::OMElement*</xsl:when> <!-- these are anonymous -->
                     <xsl:otherwise><xsl:value-of select="@type"/><xsl:if test="@ours">*</xsl:if></xsl:otherwise>
                   </xsl:choose>
                </xsl:variable>
                  <xsl:variable name="PropertyTypeArrayParam"> <!--these are used in arrays to take the type stored in the arraylist-->
                     <xsl:choose>
                       <xsl:when test="not(@type)">wso2wsf::OMElement*</xsl:when> <!-- these are anonymous -->
                       <xsl:when test="@type='unsigned char' or @type='unsigned short' or @type='uint64_t' or @type='unsigned int' or @type='short' or @type='char' or @type='int' or @type='float' or @type='double' or @type='int64_t'"><xsl:value-of select="@type"/></xsl:when>
                       <xsl:otherwise><xsl:value-of select="@type"/><xsl:if test="@ours"><xsl:text>*</xsl:text></xsl:if></xsl:otherwise>
                     </xsl:choose>
                  </xsl:variable>
                
                <xsl:variable name="propertyInstanceName">element</xsl:variable>
                <xsl:variable name="justPropertyInstanceName">element</xsl:variable>

                for(i = 0, allocated_len = 2, text_value = (axis2_char_t*) axutil_strdup(Environment::getEnv(), "");
                            i &lt; sizeof<xsl:value-of select="$CName"/>(); i++)
                {
                  <xsl:value-of select="$nativePropertyType"/> element;
                  axis2_char_t *seperator = (i == sizeof<xsl:value-of select="$CName"/>() - 1)?"":ADB_DEFAULT_LIST_SEPERATOR;
                  element = get<xsl:value-of select="$CName"/>At(i);
                    
                 <xsl:choose>
                    <!-- add int s -->
                    <xsl:when test="$nativePropertyType='int' or $nativePropertyType='unsigned int'">
                       allocated_len += sizeof (axis2_char_t) * ADB_DEFAULT_DIGIT_LIMIT + 1;
                       text_value = (axis2_char_t*) AXIS2_REALLOC (Environment::getEnv()-> allocator, text_value, allocated_len);
                       sprintf (text_value, "%s%d%s", text_value, element, seperator);
                    </xsl:when>
                    <!-- add axis2_byte_t s -->
                    <xsl:when test="$nativePropertyType='axis2_byte_t' or $nativePropertyType='axis2_unsigned_byte_t'">
                       allocated_len += sizeof (axis2_char_t) * ADB_DEFAULT_DIGIT_LIMIT + 1;
                       text_value = (axis2_char_t*) AXIS2_REALLOC (Environment::getEnv()-> allocator, text_value, allocated_len);
                       sprintf (text_value, "%s%d%s", text_value, element, seperator);
                    </xsl:when>

                    <!-- add char s -->
                    <xsl:when test="$nativePropertyType='char' or $nativePropertyType='unsigned char'">
                       allocated_len += sizeof (axis2_char_t) * ADB_DEFAULT_DIGIT_LIMIT + 1;
                       text_value = (axis2_char_t*) AXIS2_REALLOC (Environment::getEnv()-> allocator, text_value, allocated_len);
                       sprintf (text_value, "%s%c%s", text_value, element, seperator);
                    </xsl:when>

                    <!-- add short s -->
                    <xsl:when test="$nativePropertyType='short' or $nativePropertyType='unsigned short'">
                       allocated_len += sizeof (axis2_char_t) * ADB_DEFAULT_DIGIT_LIMIT + 1;
                       text_value = (axis2_char_t*) AXIS2_REALLOC (Environment::getEnv()-> allocator, text_value, allocated_len);
                       sprintf (text_value, "%s%d%s", text_value, element, seperator);
                    </xsl:when>

                    <!-- add int64_t s -->
                    <xsl:when test="$nativePropertyType='int64_t'">
                       allocated_len += sizeof (axis2_char_t) * ADB_DEFAULT_DIGIT_LIMIT + 1;
                       text_value = (axis2_char_t*) AXIS2_REALLOC (Environment::getEnv()-> allocator, text_value, allocated_len);
                       sprintf (text_value, "%s" AXIS2_PRINTF_INT64_FORMAT_SPECIFIER "%s", text_value, element, seperator);
                    </xsl:when>

                    <xsl:when test="$nativePropertyType='uint64_t'">
                       allocated_len += sizeof (axis2_char_t) * ADB_DEFAULT_DIGIT_LIMIT + 1;
                       text_value = (axis2_char_t*) AXIS2_REALLOC (Environment::getEnv()-> allocator, text_value, allocated_len);
                       sprintf (text_value, "%s" AXIS2_PRINTF_UINT64_FORMAT_SPECIFIER "%s", text_value, element, seperator);
                    </xsl:when>

                    <!-- add float s -->
                    <xsl:when test="$nativePropertyType='float'">
                       allocated_len += sizeof (axis2_char_t) * ADB_DEFAULT_DIGIT_LIMIT + 1;
                       text_value = (axis2_char_t*) AXIS2_REALLOC (Environment::getEnv()-> allocator, text_value, allocated_len);
                       sprintf (text_value, "%s%f%s", text_value, element, seperator);
                    </xsl:when>

                    <!-- add double s -->
                    <xsl:when test="$nativePropertyType='double'">
                       allocated_len += sizeof (axis2_char_t) * ADB_DEFAULT_DIGIT_LIMIT + 1;
                       text_value = (axis2_char_t*) AXIS2_REALLOC (Environment::getEnv()-> allocator, text_value, allocated_len);
                       sprintf (text_value, "%s%f%s", text_value, element, seperator);
                    </xsl:when>

                    <!-- add axis2_char_t* s -->
                    <xsl:when test="$nativePropertyType='std::string'">
                       allocated_len += sizeof (axis2_char_t) * axutil_strlen(element.c_str()) + 1;
                       text_value = (axis2_char_t*) AXIS2_REALLOC (Environment::getEnv()-> allocator, text_value, allocated_len);
                       sprintf (text_value, "%s%s%s", text_value, element.c_str(), seperator);
                    </xsl:when>

                    <!-- add axutil_uri_t s -->
                    <xsl:when test="$nativePropertyType='axutil_uri_t*'">
                       tmp_value = axutil_uri_to_string(element, Environment::getEnv(), AXIS2_URI_UNP_OMITUSERINFO);
                       allocated_len += sizeof (axis2_char_t) * axutil_strlen(tmp_value) + 1;
                       text_value = (axis2_char_t*) AXIS2_REALLOC (Environment::getEnv()-> allocator, text_value, allocated_len);
                       sprintf (text_value, "%s%s%s", text_value, tmp_value, seperator);
                    </xsl:when>

                    <!-- add axutil_duration_t s -->
                    <xsl:when test="$nativePropertyType='axutil_duration_t*'">
                       tmp_value = axutil_duration_serialize_duration(element, Environment::getEnv());
                       allocated_len += sizeof (axis2_char_t) * axutil_strlen(tmp_value) + 1;
                       text_value = (axis2_char_t*) AXIS2_REALLOC (Environment::getEnv()-> allocator, text_value, allocated_len);
                       sprintf (text_value, "%s%s%s", text_value, tmp_value, seperator);
                    </xsl:when>

                    <!-- add axutil_qname_t s -->
                    <xsl:when test="$nativePropertyType='axutil_qname_t*'">
                      <!-- namespaces are declared in _declare_parent_namespaces -->
                      qname_uri = axutil_qname_get_uri(element, Environment::getEnv());
                      if(qname_uri == NULL)
                      {
                           tmp_value = axutil_qname_get_localpart(element, Environment::getEnv());
                           allocated_len += sizeof (axis2_char_t) * axutil_strlen(tmp_value) + 1;
                           text_value = (axis2_char_t*) AXIS2_REALLOC (Environment::getEnv()-> allocator, text_value, allocated_len);
                           sprintf (text_value, "%s%s%s", text_value, tmp_value, seperator);
                      }
                      else
                      {
                        qname_prefix = (axis2_char_t*)axutil_hash_get(namespaces, qname_uri, AXIS2_HASH_KEY_STRING);
                        if(qname_prefix != NULL)
                        {
                            tmp_value = axutil_qname_get_localpart(element, Environment::getEnv());
                            allocated_len += sizeof (axis2_char_t) * (ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT  + 1 +
                                                            axutil_strlen(tmp_value) + 2);
                            text_value = (axis2_char_t*) AXIS2_REALLOC (Environment::getEnv()-> allocator, text_value, allocated_len);
                            
                            sprintf(text_value, "%s%s:%s%s", text_value, qname_prefix,
                                                      tmp_value, seperator);
                        }
                        else
                        {
                            WSF_LOG_ERROR_MSG( Environment::getEnv()->log,WSF_LOG_SI,"Failed in serialize_to_string value for <xsl:value-of select="$propertyName"/>, "
                                                        "Prefix is not declared beofre using");
                            return NULL;
                        }
                     }
                    </xsl:when>

                    <!-- add bool s -->
                    <xsl:when test="$nativePropertyType='bool'">
                       <!--text_value = (<xsl:value-of select="$propertyInstanceName"/>)?"true":"false";-->
                           tmp_value = (axis2_char_t*)((element)?"true":"false");
                           allocated_len += sizeof (axis2_char_t) * axutil_strlen(tmp_value) + 1;
                           text_value = (axis2_char_t*) AXIS2_REALLOC (Environment::getEnv()-> allocator, text_value, allocated_len);
                           sprintf (text_value, "%s%s%s", text_value, tmp_value, seperator);
                    </xsl:when>
                    <!-- add axis2_date_time_t s -->
                    <xsl:when test="$nativePropertyType='axutil_date_time_t*'">
                           tmp_value = axutil_date_time_serialize_date_time(element, Environment::getEnv());
                           allocated_len += sizeof (axis2_char_t) * axutil_strlen(tmp_value) + 1;
                           text_value = (axis2_char_t*) AXIS2_REALLOC (Environment::getEnv()-> allocator, text_value, allocated_len);
                           sprintf (text_value, "%s%s%s", text_value, tmp_value, seperator);
                    </xsl:when>
                    <!-- add axis2_base64_binary_t s -->
                    <xsl:when test="$nativePropertyType='axutil_base64_binary_t*'">
                           tmp_value = axutil_base64_binary_get_encoded_binary(element, Environment::getEnv());
                           allocated_len += sizeof (axis2_char_t) * axutil_strlen(tmp_value) + 1;
                           text_value = (axis2_char_t*) AXIS2_REALLOC (Environment::getEnv()-> allocator, text_value, allocated_len);
                           sprintf (text_value, "%s%s%s", text_value, tmp_value, seperator);
                    </xsl:when>
                    <xsl:when test="@ours">
                        if(element)
                        {
                            text_value = element->serializeToString(namespaces);
                        }
                    </xsl:when>
                    <xsl:otherwise>
                      <!--TODO: add new property types -->
                      /* can not handle the property type <xsl:value-of select="$nativePropertyType"/>*/
                    </xsl:otherwise>
                  </xsl:choose>
                }
                </xsl:for-each>
                
                <xsl:if test="$isUnion">
                
                void *element = NULL;
                if(!currentValue.empty())
                {
                    text_value = NULL;
                }
                <xsl:for-each select="memberType">
                   <xsl:variable name="member_type" select="@type"/>
                   <xsl:variable name="member_name"><xsl:text></xsl:text><xsl:value-of select="@originalName"/></xsl:variable>   
                   <xsl:variable name="propertyInstanceName">memberType._<xsl:value-of select="$member_name"/></xsl:variable>
                  else if(!axutil_strcmp("<xsl:value-of select="@originalName"/>",currentValue.c_str()))
                  {
                   <xsl:choose>
                      <!-- add int s -->
                      <xsl:when test="$member_type='int' or $member_type='unsigned int'">
                         text_value = (axis2_char_t*) AXIS2_MALLOC (Environment::getEnv()-> allocator, sizeof (axis2_char_t) * ADB_DEFAULT_DIGIT_LIMIT);
                         sprintf (text_value, "%d", <xsl:value-of select="$propertyInstanceName"/>);
                      </xsl:when>
                      <!-- add axis2_byte_t s -->
                      <xsl:when test="$member_type='axis2_byte_t' or $member_type='axis2_unsigned_byte_t'">
                         text_value = (axis2_char_t*) AXIS2_MALLOC (Environment::getEnv()-> allocator, sizeof (axis2_char_t) * ADB_DEFAULT_DIGIT_LIMIT);
                         sprintf (text_value, "%d", <xsl:value-of select="$propertyInstanceName"/>);
                      </xsl:when>

                      <!-- add char s -->
                      <xsl:when test="$member_type='char' or $member_type='unsigned char'">
                         text_value = (axis2_char_t*) AXIS2_MALLOC (Environment::getEnv()-> allocator, sizeof (axis2_char_t) * ADB_DEFAULT_DIGIT_LIMIT);
                         sprintf (text_value, "%c", <xsl:value-of select="$propertyInstanceName"/>);
                      </xsl:when>

                      <!-- add short s -->
                      <xsl:when test="$member_type='short' or $member_type='unsigned short'">
                         text_value = (axis2_char_t*) AXIS2_MALLOC (Environment::getEnv()-> allocator, sizeof (axis2_char_t) * ADB_DEFAULT_DIGIT_LIMIT);
                         sprintf (text_value, "%d", <xsl:value-of select="$propertyInstanceName"/>);
                      </xsl:when>

                      <!-- add int64_t s -->
                      <xsl:when test="$member_type='int64_t'">
                         text_value = (axis2_char_t*) AXIS2_MALLOC (Environment::getEnv()-> allocator, sizeof (axis2_char_t) * ADB_DEFAULT_DIGIT_LIMIT);
                         sprintf (text_value, AXIS2_PRINTF_INT64_FORMAT_SPECIFIER, (int64_t)<xsl:value-of select="$propertyInstanceName"/>);
                      </xsl:when>

                      <xsl:when test="$member_type='uint64_t'">
                         text_value = (axis2_char_t*) AXIS2_MALLOC (Environment::getEnv()-> allocator, sizeof (axis2_char_t) * ADB_DEFAULT_DIGIT_LIMIT);
                         sprintf (text_value, AXIS2_PRINTF_UINT64_FORMAT_SPECIFIER, (uint64_t)<xsl:value-of select="$propertyInstanceName"/>);
                      </xsl:when>

                      <!-- add float s -->
                      <xsl:when test="$member_type='float'">
                         text_value = (axis2_char_t*) AXIS2_MALLOC (Environment::getEnv()-> allocator, sizeof (axis2_char_t) * ADB_DEFAULT_DIGIT_LIMIT);
                         sprintf (text_value, "%f", <xsl:value-of select="$propertyInstanceName"/>);
                      </xsl:when>

                      <!-- add double s -->
                      <xsl:when test="$member_type='double'">
                         text_value = (axis2_char_t*) AXIS2_MALLOC (Environment::getEnv()-> allocator, sizeof (axis2_char_t) * ADB_DEFAULT_DIGIT_LIMIT);
                         sprintf (text_value, "%f", <xsl:value-of select="$propertyInstanceName"/>);
                      </xsl:when>

                      <!-- add axis2_char_t* s -->
                      <xsl:when test="$member_type='std::string'">
                         text_value = (axis2_char_t*)axutil_strdup(Environment::getEnv(), <xsl:value-of select="$propertyInstanceName"/>.c_str());
                      </xsl:when>

                      <!-- add axutil_uri_t s -->
                      <xsl:when test="$member_type='axutil_uri_t*'">
                         text_value = axutil_uri_to_string(<xsl:value-of select="$propertyInstanceName"/>, Environment::getEnv(), AXIS2_URI_UNP_OMITUSERINFO);
                      </xsl:when>

                      <!-- add axutil_duration_t s -->
                      <xsl:when test="$member_type='axutil_duration_t*'">
                         text_value = axutil_duration_serialize_duration(<xsl:value-of select="$propertyInstanceName"/>, Environment::getEnv());
                      </xsl:when>

                      <!-- add axutil_qname_t s -->
                      <xsl:when test="$member_type='axutil_qname_t*'">
                        <!-- namespaces are declared in _declare_parent_namespaces -->
                        qname_uri = axutil_qname_get_uri(<xsl:value-of select="$propertyInstanceName"/>, Environment::getEnv());
                        if(qname_uri == NULL)
                        {
                              text_value = (axis2_char_t*)axutil_strdup(Environment::getEnv(), axutil_qname_get_localpart(<xsl:value-of select="$propertyInstanceName"/>, Environment::getEnv()));
                        }
                        else
                        {
                          qname_prefix = (axis2_char_t*)axutil_hash_get(namespaces, qname_uri, AXIS2_HASH_KEY_STRING);
                          if(qname_prefix != NULL)
                          {
                              text_value = (axis2_char_t*) AXIS2_MALLOC (Environment::getEnv()-> allocator,
                                          sizeof (axis2_char_t) * (ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT +
                                                              axutil_strlen(axutil_qname_get_localpart(<xsl:value-of select="$propertyInstanceName"/>, Environment::getEnv())) + 2));
                              sprintf(text_value, "%s:%s", qname_prefix,
                                                        axutil_qname_get_localpart(<xsl:value-of select="$propertyInstanceName"/>, Environment::getEnv()));
                          }
                          else
                          {
                              WSF_LOG_ERROR_MSG( Environment::getEnv()->log,WSF_LOG_SI,"Failed in serialize_to_string value for <xsl:value-of select="$member_name"/>, "
                                                          "Prefix is not declared beofre using");
                              return NULL;
                          }
                        }
                      </xsl:when>

                      <!-- add bool s -->
                      <xsl:when test="$member_type='bool'">
                         <!--text_value = (<xsl:value-of select="$propertyInstanceName"/>)?"true":"false";-->
                         text_value = (axis2_char_t*)(axutil_strdup(Environment::getEnv(), (<xsl:value-of select="$propertyInstanceName"/>)?"true":"false"));
                      </xsl:when>
                      <!-- add axis2_date_time_t s -->
                      <xsl:when test="$member_type='axutil_date_time_t*'">
                         text_value =  axutil_date_time_serialize_date_time(<xsl:value-of select="$propertyInstanceName"/>, Environment::getEnv());
                      </xsl:when>
                      <!-- add axis2_base64_binary_t s -->
                      <xsl:when test="$member_type='axutil_base64_binary_t*'">
                         text_value =  axutil_base64_binary_get_encoded_binary(<xsl:value-of select="$propertyInstanceName"/>, Environment::getEnv());
                      </xsl:when>
                      <xsl:when test="@ours">
                        if(<xsl:value-of select="$propertyInstanceName"/>)
                        {
                            text_value = <xsl:value-of select="$propertyInstanceName"/>->serializeToString(namespaces);
                        }
                      </xsl:when>
                      <xsl:otherwise>
                        <!--TODO: add new property types -->
                        /* can not handle the property type <xsl:value-of select="$member_type"/>*/
                        text_value = NULL;
                      </xsl:otherwise>
                    </xsl:choose>
                }
                </xsl:for-each>
                </xsl:if>
                return text_value;
            }
        </xsl:if>
        
        axiom_node_t* WSF_CALL
	<xsl:value-of select="$CPPNamespace"/><xsl:value-of select="$axis2_name"/>::serialize(axiom_node_t *parent, 
			axiom_element_t *parent_element, 
			int parent_tag_closed, 
			axutil_hash_t *namespaces, 
			int *next_ns_index)
        {
            <!-- first declaration part -->
            <xsl:for-each select="property/@attribute">
             <xsl:if test="position()=1">
               axiom_attribute_t *text_attri = NULL;
             </xsl:if>
            </xsl:for-each>
            <xsl:if test="@type or property/@attribute">
             axis2_char_t *string_to_stream;
            </xsl:if>
         
         axiom_node_t *current_node = NULL;
         int tag_closed = 0;

         <!--now distinguise the properties specific to simple types -->
         <xsl:choose>
           <xsl:when test="@simple">
            axiom_data_source_t *data_source = NULL;
            axutil_stream_t *stream = NULL;
            axis2_char_t *text_value;
             <xsl:for-each select="property/@attribute">
              <xsl:if test="position()=1">
               axiom_namespace_t *ns1 = NULL;
               axis2_char_t *p_prefix = NULL;
              </xsl:if>
             </xsl:for-each>
           </xsl:when>

           <!-- non simple types -->
           <xsl:otherwise>
                axiom_namespace_t *ns1 = NULL;

                axis2_char_t *qname_uri = NULL;
                axis2_char_t *qname_prefix = NULL;
                axis2_char_t *p_prefix = NULL;
            <xsl:for-each select="property/@isarray">
             <xsl:if test="position()=1">
               int i = 0;
               int count = 0;
               void *element = NULL;
             </xsl:if>
            </xsl:for-each>
            <xsl:for-each select="property">
                <xsl:variable name="position"><xsl:value-of select="position()"/></xsl:variable>
                <xsl:choose>
                    <xsl:when test="not(@type) or (@ours='yes' and (@type='uri' or @type='qname' or @type='date_time' or @type='base64_binary' or @type='char')) or @type='char' or @type='std::string' or @type='axutil_base64_binary_t*' or @type='axutil_date_time_t*' or @type='wso2wsf::OMElement*' or @type='axutil_duration_t*' or @type='axutil_uri_t*' or @type='axutil_qname_t*'">
                    axis2_char_t *text_value_<xsl:value-of select="$position"/>;
                    axis2_char_t *text_value_<xsl:value-of select="$position"/>_temp;
                    </xsl:when>
                    <xsl:otherwise>
                    axis2_char_t text_value_<xsl:value-of select="$position"/>[ADB_DEFAULT_DIGIT_LIMIT];
                    </xsl:otherwise>
                </xsl:choose>
            </xsl:for-each>

            <xsl:for-each select="property/@attribute">
             <xsl:if test="position()=1">
                axis2_char_t *text_value = NULL;
             </xsl:if>
            </xsl:for-each>
            <xsl:if test="property and (not(property/@attribute) or property/@attribute='' or property/@notattribute)">
               axis2_char_t *start_input_str = NULL;
               axis2_char_t *end_input_str = NULL;
               unsigned int start_input_str_len = 0;
               unsigned int end_input_str_len = 0;
            </xsl:if>
            <!-- Following is in special situatioin where no properties exist -->
               axiom_data_source_t *data_source = NULL;
               axutil_stream_t *stream = NULL;

            <xsl:if test="not(@type)"> <!-- So this is the root of the serialization call tree -->
                int next_ns_index_value = 0;
            </xsl:if>

            <xsl:if test="not(@type)"> <!-- So this is the root of the serialization call tree -->
                    namespaces = axutil_hash_make(Environment::getEnv());
                    next_ns_index = &amp;next_ns_index_value;
                    <xsl:choose>
                       <xsl:when test="$nsuri and $nsuri != ''"> 
                           ns1 = axiom_namespace_create (Environment::getEnv(),
                                             "<xsl:value-of select="$nsuri"/>",
                                             "n"); <!-- we are usinig "" instead of <xsl:value-of select="@child-nsuri"/>  -->
                           axutil_hash_set(namespaces, "<xsl:value-of select="$nsuri"/>", AXIS2_HASH_KEY_STRING, axutil_strdup(Environment::getEnv(), "n"));
                       </xsl:when>
                       <xsl:otherwise> 
                           ns1 = NULL; 
                       </xsl:otherwise>
                    </xsl:choose>
                    <!-- if not(@type) then no doubt the parent is NULL --> 
                    parent_element = axiom_element_create (Environment::getEnv(), NULL, "<xsl:value-of select="$originalName"/>", ns1 , &amp;parent);
                    
                    <!-- axiom_element_declare_default_namespace(parent_element, Environment::getEnv(), "<xsl:value-of select="$nsuri"/>"); -->
                    axiom_element_set_namespace(parent_element, Environment::getEnv(), ns1, parent);


            </xsl:if>
            </xsl:otherwise> <!--otherwise for @simple -->
            </xsl:choose>

                <xsl:if test="@type or @simple">
                    current_node = parent;
                    data_source = (axiom_data_source_t *)axiom_node_get_data_element(current_node, Environment::getEnv());
                    if (!data_source)
                        return NULL;
                    stream = axiom_data_source_get_stream(data_source, Environment::getEnv()); /* assume parent is of type data source */
                    if (!stream)
                        return NULL;
                  </xsl:if>
                <xsl:if test="count(property)!=0">
                  <xsl:if test="not(@type) and not(@simple)">
                    data_source = axiom_data_source_create(Environment::getEnv(), parent, &amp;current_node);
                    stream = axiom_data_source_get_stream(data_source, Environment::getEnv());
                  </xsl:if>
                </xsl:if>


            
            <!--first write attributes tothe parent-->
            <xsl:if test="count(property[@attribute])!=0 or @type">
            if(!parent_tag_closed)
            {
            </xsl:if>
            <xsl:for-each select="property">
              <xsl:variable name="position"><xsl:value-of select="position()"/></xsl:variable>
              <xsl:variable name="propertyType">
                 <xsl:choose>
                   <xsl:when test="@isarray">std::vector&lt;<xsl:value-of select="@type"/><xsl:if test="@ours or @type='std::string' or @type='unsigned char' or @type='unsigned short' or @type='uint64_t' or @type='unsigned int' or @type='short' or @type='char' or @type='int' or @type='float' or @type='double' or @type='int64_t'"><xsl:text>*</xsl:text></xsl:if>&gt;*</xsl:when>
                   <xsl:when test="not(@type)">wso2wsf::OMElement*</xsl:when> <!-- these are anonymous -->
                   <xsl:otherwise><xsl:value-of select="@type"/><xsl:if test="@ours"><xsl:text>*</xsl:text></xsl:if></xsl:otherwise>
                 </xsl:choose>
              </xsl:variable>
              <xsl:variable name="nativePropertyType"> <!--these are used in arrays to take the native type-->
                 <xsl:choose>
                   <xsl:when test="not(@type)">wso2wsf::OMElement*</xsl:when> <!-- these are anonymous -->
                   <xsl:otherwise><xsl:value-of select="@type"/></xsl:otherwise>
                 </xsl:choose>
              </xsl:variable>
              <xsl:variable name="propertyName"><xsl:value-of select="@originalName"/></xsl:variable>
              <xsl:variable name="CName"><xsl:value-of select="@cname"></xsl:value-of></xsl:variable>

              <xsl:variable name="propertyInstanceName"><!--these are used in arrays to take the native type-->
                 <xsl:choose>
                   <xsl:when test="@isarray">element</xsl:when>
                   <xsl:otherwise>property_<xsl:value-of select="$CName"/></xsl:otherwise>
                 </xsl:choose>
              </xsl:variable>
              <xsl:variable name="justPropertyInstanceName"><!--these are used in arrays to take the native type-->
                 <xsl:choose>
                   <xsl:when test="@isarray">element</xsl:when>
                   <xsl:otherwise>property_<xsl:value-of select="$CName"/></xsl:otherwise>
                 </xsl:choose>
              </xsl:variable>

              <xsl:variable name="namespacePrefix">
                <xsl:choose>
                    <xsl:when test="$nsprefix"><xsl:value-of select="$nsprefix"/><xsl:text>:</xsl:text></xsl:when>
                    <xsl:otherwise><xsl:text></xsl:text></xsl:otherwise>
                </xsl:choose>
              </xsl:variable>
              <xsl:variable name="qualifiedPropertyName">
                <xsl:value-of select="namespacePrefix"/><xsl:value-of select="$propertyName"/>
              </xsl:variable>
              <xsl:variable name="parentPropertyInstanceName">property_<xsl:value-of select="$CName"/></xsl:variable>
                <xsl:if test="@attribute">
                if(isValid<xsl:value-of select="$CName"/>)
                {
                <xsl:choose>
                <xsl:when test="$nativePropertyType='wso2wsf::OMAttribute*' and @isarray"><!-- for anyAttribute -->
                    int i = 0;
                    for( i = 0; i &lt; <xsl:value-of select="$parentPropertyInstanceName"/>->size(); i ++)
                    {
                        axiom_attribute_t *the_attrib = NULL;
                        axiom_attribute_t *dup_attrib = NULL;
                        wso2wsf::OMAttribute * attrib = NULL;
                        axis2_char_t *uri = NULL;
                        axis2_char_t *p_prefix = NULL;
                        axutil_qname_t *qname = NULL;
                        axis2_char_t *value = NULL;
                        axis2_char_t *local_name = NULL;
                        attrib =  (*<xsl:value-of select="$parentPropertyInstanceName"/>)[i];
                        the_attrib =  attrib->getAxiomAttribute();
                        qname = axiom_attribute_get_qname(the_attrib, Environment::getEnv());
                        uri = axutil_qname_get_uri(qname, Environment::getEnv());
                        value = axiom_attribute_get_value(the_attrib, Environment::getEnv());
                        local_name = axutil_qname_get_localpart(qname, Environment::getEnv());

                        p_prefix = NULL;
                        if(uri) /* means we have to go for a prefix */
                        {
                            if(!(p_prefix = (axis2_char_t*)axutil_hash_get(namespaces, uri, AXIS2_HASH_KEY_STRING)))
                            {
                                p_prefix = (axis2_char_t*)AXIS2_MALLOC(Environment::getEnv()->allocator, sizeof (axis2_char_t) * ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT);
                                sprintf(p_prefix, "n%d", (*next_ns_index)++);
                                axutil_hash_set(namespaces, uri, AXIS2_HASH_KEY_STRING, p_prefix);
                                axiom_element_declare_namespace_assume_param_ownership(parent_element, Environment::getEnv(), axiom_namespace_create (Environment::getEnv(),
                                                         uri,
                                                         p_prefix));
                                 
                            }

                        }

                        text_value = (axis2_char_t*) AXIS2_MALLOC (Environment::getEnv()-> allocator, sizeof (axis2_char_t) *
                                                         (5  + ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT +
                                                          axutil_strlen(local_name) + 
                                                             axutil_strlen(value)));
                        sprintf(text_value, " %s%s%s=\"%s\"", p_prefix?p_prefix:"", (p_prefix &amp;&amp; axutil_strcmp(p_prefix, ""))?":":"",
                                             local_name, value);
                        axutil_stream_write(stream, Environment::getEnv(), text_value, axutil_strlen(text_value));
                        AXIS2_FREE(Environment::getEnv()-> allocator, text_value);
                    }
                </xsl:when>
                <xsl:otherwise>
                    <xsl:choose>
                      <xsl:when test="@nsuri and @nsuri != ''">
                        if(!(p_prefix = (axis2_char_t*)axutil_hash_get(namespaces, "<xsl:value-of select="@nsuri"/>", AXIS2_HASH_KEY_STRING)))
                        {
                            p_prefix = (axis2_char_t*)AXIS2_MALLOC(Environment::getEnv()->allocator, sizeof (axis2_char_t) * ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT);
                            sprintf(p_prefix, "n%d", (*next_ns_index)++);
                            axutil_hash_set(namespaces, "<xsl:value-of select="@nsuri"/>", AXIS2_HASH_KEY_STRING, p_prefix);
                            axiom_element_declare_namespace_assume_param_ownership(parent_element, Environment::getEnv(), axiom_namespace_create (Environment::getEnv(),
                                                     "<xsl:value-of select="@nsuri"/>",
                                                     p_prefix));
                        }
                      </xsl:when>
                      <xsl:otherwise>
                        p_prefix = NULL;
                      </xsl:otherwise>
                    </xsl:choose>

                      <!-- here only simple type possible -->
                      <!-- ADB_DEFAULT_DIGIT_LIMIT (64) bytes is used to the store the string representation of the number and the namespace prefix + ":" -->
                      <xsl:choose>
                        <!-- add int s -->
                        <xsl:when test="$nativePropertyType='int' or $nativePropertyType='unsigned int'">
                           text_value = (axis2_char_t*) AXIS2_MALLOC (Environment::getEnv()-> allocator, sizeof (axis2_char_t) *
                                                            (ADB_DEFAULT_DIGIT_LIMIT + 5 + ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT + 
                                                                axutil_strlen("<xsl:value-of select="$propertyName"/>")));
                                                            <!-- here axutil_strlen(":=\"\"") + 1(for NULL terminator) = 5 -->
                           sprintf(text_value, " %s%s%s=\"%d\"", p_prefix?p_prefix:"", (p_prefix &amp;&amp; axutil_strcmp(p_prefix, ""))?":":"",
                                                "<xsl:value-of select="$propertyName"/>", <xsl:value-of select="$propertyInstanceName"/>);
                           axutil_stream_write(stream, Environment::getEnv(), text_value, axutil_strlen(text_value));
                           AXIS2_FREE(Environment::getEnv()-> allocator, text_value);
                        </xsl:when>
                        <!-- add axis2_byte_t s -->
                        <xsl:when test="$nativePropertyType='axis2_byte_t' or $nativePropertyType='axis2_unsigned_byte_t'">
                           text_value = (axis2_char_t*) AXIS2_MALLOC (Environment::getEnv()-> allocator, sizeof (axis2_char_t) *
                                                            (ADB_DEFAULT_DIGIT_LIMIT + 5  + ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT + 
                                                                axutil_strlen("<xsl:value-of select="$propertyName"/>")));
                           sprintf(text_value, " %s%s%s=\"%d\"", p_prefix?p_prefix:"", (p_prefix  &amp;&amp; axutil_strcmp(p_prefix, ""))?":":"",
                                                "<xsl:value-of select="$propertyName"/>", <xsl:value-of select="$propertyInstanceName"/>);
                           axutil_stream_write(stream, Environment::getEnv(), text_value, axutil_strlen(text_value));
                           AXIS2_FREE(Environment::getEnv()-> allocator, text_value);
                        </xsl:when>

                        <!-- add int s -->
                        <xsl:when test="$nativePropertyType='char' or $nativePropertyType='unsigned char'">
                           text_value = (axis2_char_t*) AXIS2_MALLOC (Environment::getEnv()-> allocator, sizeof (axis2_char_t) *
                                                            (ADB_DEFAULT_DIGIT_LIMIT + 5  + ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT + 
                                                                axutil_strlen("<xsl:value-of select="$propertyName"/>")));
                           sprintf(text_value, " %s%s%s=\"%c\"", p_prefix?p_prefix:"", (p_prefix &amp;&amp; axutil_strcmp(p_prefix, ""))?":":"",
                                                "<xsl:value-of select="$propertyName"/>", <xsl:value-of select="$propertyInstanceName"/>);
                           axutil_stream_write(stream, Environment::getEnv(), text_value, axutil_strlen(text_value));
                           AXIS2_FREE(Environment::getEnv()-> allocator, text_value);
                        </xsl:when>

                        <!-- add short s -->
                        <xsl:when test="$nativePropertyType='short' or $nativePropertyType='unsigned short'">
                           text_value = (axis2_char_t*) AXIS2_MALLOC (Environment::getEnv()-> allocator, sizeof (axis2_char_t) *
                                                            (ADB_DEFAULT_DIGIT_LIMIT + 5  + ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT + 
                                                                axutil_strlen("<xsl:value-of select="$propertyName"/>")));
                           sprintf(text_value, " %s%s%s=\"%d\"", p_prefix?p_prefix:"", (p_prefix &amp;&amp; axutil_strcmp(p_prefix, ""))?":":"",
                                                "<xsl:value-of select="$propertyName"/>", <xsl:value-of select="$propertyInstanceName"/>);
                           axutil_stream_write(stream, Environment::getEnv(), text_value, axutil_strlen(text_value));
                           AXIS2_FREE(Environment::getEnv()-> allocator, text_value);
                        </xsl:when>

                        <!-- add int64_t s -->
                        <xsl:when test="$nativePropertyType='int64_t'">
                           text_value = (axis2_char_t*) AXIS2_MALLOC (Environment::getEnv()-> allocator, sizeof (axis2_char_t) *
                                                            (ADB_DEFAULT_DIGIT_LIMIT + 5  + ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT + 
                                                                axutil_strlen("<xsl:value-of select="$propertyName"/>")));
                           sprintf(text_value, " %s%s%s=\"" AXIS2_PRINTF_INT64_FORMAT_SPECIFIER  "\"", p_prefix?p_prefix:"", 
                                                (p_prefix &amp;&amp; axutil_strcmp(p_prefix, ""))?":":"",
                                                "<xsl:value-of select="$propertyName"/>", <xsl:value-of select="$propertyInstanceName"/>);
                           axutil_stream_write(stream, Environment::getEnv(), text_value, axutil_strlen(text_value));
                           AXIS2_FREE(Environment::getEnv()-> allocator, text_value);
                        </xsl:when>

                        <xsl:when test="$nativePropertyType='uint64_t'">
                           text_value = (axis2_char_t*) AXIS2_MALLOC (Environment::getEnv()-> allocator, sizeof (axis2_char_t) *
                                                            (ADB_DEFAULT_DIGIT_LIMIT + 5  + ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT +
                                                                axutil_strlen("<xsl:value-of select="$propertyName"/>")));
                           sprintf(text_value, " %s%s%s=\"" AXIS2_PRINTF_UINT64_FORMAT_SPECIFIER  "\"", p_prefix?p_prefix:"", 
                                                (p_prefix &amp;&amp; axutil_strcmp(p_prefix, ""))?":":"",
                                                "<xsl:value-of select="$propertyName"/>", <xsl:value-of select="$propertyInstanceName"/>);
                           axutil_stream_write(stream, Environment::getEnv(), text_value, axutil_strlen(text_value));
                           AXIS2_FREE(Environment::getEnv()-> allocator, text_value);
                        </xsl:when>

                        <!-- add float s -->
                        <xsl:when test="$nativePropertyType='float'">
                           text_value = (axis2_char_t*) AXIS2_MALLOC (Environment::getEnv()-> allocator, sizeof (axis2_char_t) *
                                                            (ADB_DEFAULT_DIGIT_LIMIT + 5  + ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT + 
                                                                axutil_strlen("<xsl:value-of select="$propertyName"/>")));
                           sprintf(text_value, " %s%s%s=\"%f\"", p_prefix?p_prefix:"", (p_prefix &amp;&amp; axutil_strcmp(p_prefix, ""))?":":"",
                                                "<xsl:value-of select="$propertyName"/>", <xsl:value-of select="$propertyInstanceName"/>);
                           axutil_stream_write(stream, Environment::getEnv(), text_value, axutil_strlen(text_value));
                           AXIS2_FREE(Environment::getEnv()-> allocator, text_value);
                        </xsl:when>

                        <!-- add double s -->
                        <xsl:when test="$nativePropertyType='double'">
                           text_value = (axis2_char_t*) AXIS2_MALLOC (Environment::getEnv()-> allocator, sizeof (axis2_char_t) *
                                                            (ADB_DEFAULT_DIGIT_LIMIT + 5  + ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT + 
                                                                axutil_strlen("<xsl:value-of select="$propertyName"/>")));
                           sprintf(text_value, " %s%s%s=\"%f\"", p_prefix?p_prefix:"", (p_prefix &amp;&amp; axutil_strcmp(p_prefix, ""))?":":"",
                                                "<xsl:value-of select="$propertyName"/>", <xsl:value-of select="$propertyInstanceName"/>);
                           axutil_stream_write(stream, Environment::getEnv(), text_value, axutil_strlen(text_value));
                           AXIS2_FREE(Environment::getEnv()-> allocator, text_value);
                        </xsl:when>

                        <!-- add axis2_char_t s -->
                        <xsl:when test="$nativePropertyType='std::string'">
                           text_value = (axis2_char_t*) AXIS2_MALLOC (Environment::getEnv()-> allocator, sizeof (axis2_char_t) *
                                                            (5  + ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT +
                                                             axutil_strlen(<xsl:value-of select="$propertyInstanceName"/>.c_str()) +
                                                                axutil_strlen("<xsl:value-of select="$propertyName"/>")));
                           sprintf(text_value, " %s%s%s=\"%s\"", p_prefix?p_prefix:"", (p_prefix &amp;&amp; axutil_strcmp(p_prefix, ""))?":":"",
                                                "<xsl:value-of select="$propertyName"/>", <xsl:value-of select="$propertyInstanceName"/>.c_str());
                           axutil_stream_write(stream, Environment::getEnv(), text_value, axutil_strlen(text_value));
                           AXIS2_FREE(Environment::getEnv()-> allocator, text_value);
                        </xsl:when>

                        <!-- add axutil_uri_t s -->
                        <xsl:when test="$nativePropertyType='axutil_uri_t*'">
                           text_value = axutil_uri_to_string(<xsl:value-of select="$propertyInstanceName"/>, Environment::getEnv(), AXIS2_URI_UNP_OMITUSERINFO);
                           string_to_stream = (axis2_char_t*) AXIS2_MALLOC (Environment::getEnv()-> allocator, sizeof (axis2_char_t) *
                                                            (5  + ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT +
                                                             axutil_strlen(text_value) + 
                                                             axutil_strlen("<xsl:value-of select="$propertyName"/>")));
                           sprintf(string_to_stream, " %s%s%s=\"%s\"", p_prefix?p_prefix:"", (p_prefix &amp;&amp; axutil_strcmp(p_prefix, ""))?":":"",
                                                "<xsl:value-of select="$propertyName"/>",  text_value);
                           axutil_stream_write(stream, Environment::getEnv(), string_to_stream, axutil_strlen(string_to_stream));
                           AXIS2_FREE(Environment::getEnv()-> allocator, string_to_stream);
                        </xsl:when>

                        <!-- add axutil_duration_t s -->
                        <xsl:when test="$nativePropertyType='axutil_duration_t*'">
                           text_value = axutil_duration_serialize_duration(<xsl:value-of select="$propertyInstanceName"/>, Environment::getEnv());
                           string_to_stream = (axis2_char_t*) AXIS2_MALLOC (Environment::getEnv()-> allocator, sizeof (axis2_char_t) *
                                                            (5  + ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT +
                                                             axutil_strlen(text_value) + 
                                                             axutil_strlen("<xsl:value-of select="$propertyName"/>")));
                           sprintf(string_to_stream, " %s%s%s=\"%s\"", p_prefix?p_prefix:"", (p_prefix &amp;&amp; axutil_strcmp(p_prefix, ""))?":":"",
                                                "<xsl:value-of select="$propertyName"/>",  text_value);
                           axutil_stream_write(stream, Environment::getEnv(), string_to_stream, axutil_strlen(string_to_stream));
                           AXIS2_FREE(Environment::getEnv()-> allocator, string_to_stream);
                        </xsl:when>

                        <!-- add axutil_qname_t s -->
                        <xsl:when test="$nativePropertyType='axutil_qname_t*'">
                           qname_uri =  axutil_qname_get_uri(<xsl:value-of select="$propertyInstanceName"/>, Environment::getEnv());
                           if(qname_uri &amp;&amp; !axutil_strcmp(qname_uri, ""))
                           {
                               if(!(qname_prefix = (axis2_char_t*)axutil_hash_get(namespaces, qname_uri, AXIS2_HASH_KEY_STRING)))
                               {
                                   qname_prefix = (axis2_char_t*)AXIS2_MALLOC(Environment::getEnv()->allocator, sizeof (axis2_char_t) * ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT);

                                   sprintf(qname_prefix, "q%d", (*next_ns_index) ++); <!-- just different prefix for the special case -->
                                   axutil_hash_set(namespaces, qname_uri, AXIS2_HASH_KEY_STRING, qname_prefix);

                                   axiom_element_declare_namespace_assume_param_ownership(parent_element, Environment::getEnv(), axiom_namespace_create (Environment::getEnv(),
                                                                                        qname_uri,
                                                                                        qname_prefix));
                               }
                               text_value = (axis2_char_t*) AXIS2_MALLOC (Environment::getEnv()-> allocator, sizeof (axis2_char_t) *
                                                                 (2 + axutil_strlen(qname_prefix) +
                                                                    axutil_strlen(axutil_qname_get_localpart(<xsl:value-of select="$propertyInstanceName"/>, Environment::getEnv()))));
                               sprintf(text_value, "%s%s%s", qname_prefix, (p_prefix &amp;&amp; axutil_strcmp(p_prefix, ""))?":":"",
                                                           axutil_qname_get_localpart(<xsl:value-of select="$propertyInstanceName"/>, Environment::getEnv()));
                           }
                           else
                           {
                               text_value = (axis2_char_t*)axutil_strdup(Environment::getEnv(), axutil_qname_get_localpart(<xsl:value-of select="$propertyInstanceName"/>, Environment::getEnv()));
                           }

                           string_to_stream = (axis2_char_t*) AXIS2_MALLOC (Environment::getEnv()-> allocator, sizeof (axis2_char_t) *
                                                            (5  + ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT +
                                                             axutil_strlen(text_value) + 
                                                             axutil_strlen("<xsl:value-of select="$propertyName"/>")));
                           sprintf(string_to_stream, " %s%s%s=\"%s\"", p_prefix?p_prefix:"", (p_prefix &amp;&amp; axutil_strcmp(p_prefix, ""))?":":"",
                                                "<xsl:value-of select="$propertyName"/>",  text_value);

                           axutil_stream_write(stream, Environment::getEnv(), string_to_stream, axutil_strlen(string_to_stream));
                           AXIS2_FREE(Environment::getEnv()->allocator, string_to_stream);
                           AXIS2_FREE(Environment::getEnv()->allocator, text_value);
                        </xsl:when>

                        <!-- add bool s -->
                        <xsl:when test="$nativePropertyType='bool'">
                           <!--text_value = (<xsl:value-of select="$propertyInstanceName"/>)?"true":"false";-->
                           text_value = (axis2_char_t*)((<xsl:value-of select="$propertyInstanceName"/>)?"true":"false");
                           string_to_stream = (axis2_char_t*) AXIS2_MALLOC (Environment::getEnv()-> allocator, sizeof (axis2_char_t) *
                                                            (5  + ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT +
                                                             axutil_strlen(text_value) + 
                                                             axutil_strlen("<xsl:value-of select="$propertyName"/>")));
                           sprintf(string_to_stream, " %s%s%s=\"%s\"", p_prefix?p_prefix:"", (p_prefix &amp;&amp; axutil_strcmp(p_prefix, ""))?":":"",
                                                "<xsl:value-of select="$propertyName"/>",  text_value);
                           axutil_stream_write(stream, Environment::getEnv(), string_to_stream, axutil_strlen(string_to_stream));
                           AXIS2_FREE(Environment::getEnv()-> allocator, string_to_stream);
                        </xsl:when>
                        <!-- add axis2_date_time_t s -->
                        <xsl:when test="$nativePropertyType='axutil_date_time_t*'">
                           text_value =  axutil_date_time_serialize_date_time(<xsl:value-of select="$propertyInstanceName"/>, Environment::getEnv());
                           string_to_stream = (axis2_char_t*) AXIS2_MALLOC (Environment::getEnv()-> allocator, sizeof (axis2_char_t) *
                                                            (5  + ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT +
                                                             axutil_strlen(text_value) + 
                                                             axutil_strlen("<xsl:value-of select="$propertyName"/>")));
                           sprintf(string_to_stream, " %s%s%s=\"%s\"", p_prefix?p_prefix:"", (p_prefix &amp;&amp; axutil_strcmp(p_prefix, ""))?":":"",
                                                "<xsl:value-of select="$propertyName"/>",  text_value);
                           axutil_stream_write(stream, Environment::getEnv(), string_to_stream, axutil_strlen(string_to_stream));
                           AXIS2_FREE(Environment::getEnv()-> allocator, string_to_stream);
                        </xsl:when>
                        <!-- add axis2_base64 _binary_t s -->
                        <xsl:when test="$nativePropertyType='axutil_base64_binary_t*'">
                           text_value =  axutil_base64_binary_get_encoded_binary(<xsl:value-of select="$propertyInstanceName"/>, Environment::getEnv());
                           string_to_stream = (axis2_char_t*) AXIS2_MALLOC (Environment::getEnv()-> allocator, sizeof (axis2_char_t) *
                                                            (5  + ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT +
                                                             axutil_strlen(text_value) + 
                                                             axutil_strlen("<xsl:value-of select="$propertyName"/>")));
                           sprintf(string_to_stream, " %s%s%s=\"%s\"", p_prefix?p_prefix:"", (p_prefix &amp;&amp; axutil_strcmp(p_prefix, ""))?":":"",
                                                "<xsl:value-of select="$propertyName"/>",  text_value);
                           axutil_stream_write(stream, Environment::getEnv(), string_to_stream, axutil_strlen(string_to_stream));
                           AXIS2_FREE(Environment::getEnv()-> allocator, string_to_stream);
                        </xsl:when>
                        <xsl:when test="@ours">
        
                           <xsl:value-of select="$propertyInstanceName"/>->declareParentNamespaces(parent_element, namespaces, next_ns_index);
                           text_value = <xsl:value-of select="$propertyInstanceName"/>->serializeToString(namespaces);
                           string_to_stream = (axis2_char_t*) AXIS2_MALLOC (Environment::getEnv()-> allocator, sizeof (axis2_char_t) *
                                                            (5  + ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT +
                                                             axutil_strlen(text_value) + 
                                                             axutil_strlen("<xsl:value-of select="$propertyName"/>")));
                           sprintf(string_to_stream, " %s%s%s=\"%s\"", p_prefix?p_prefix:"", (p_prefix &amp;&amp; axutil_strcmp(p_prefix, ""))?":":"",
                                                "<xsl:value-of select="$propertyName"/>",  text_value);
                           axutil_stream_write(stream, Environment::getEnv(), string_to_stream, axutil_strlen(string_to_stream));
                           AXIS2_FREE(Environment::getEnv()-> allocator, string_to_stream);
                           AXIS2_FREE(Environment::getEnv()-> allocator, text_value);
                        </xsl:when>
                        <xsl:otherwise>
                          <!--TODO: add new attributes types -->
                          /* can not handle the attribute type <xsl:value-of select="$nativePropertyType"/>*/
                           text_value = NULL;
                        </xsl:otherwise>
                      </xsl:choose>
                     </xsl:otherwise> <!-- whether this is an anyAttribute or not -->
                </xsl:choose>
                   }
                   <xsl:if test="not(@optional)">
                   <xsl:if test="not($nativePropertyType='wso2wsf::OMAttribute*' and @isarray)"><!-- for anyAttribute -->
                   else
                   {
                      WSF_LOG_ERROR_MSG( Environment::getEnv()->log,WSF_LOG_SI,"Nil value found in non-optional attribute <xsl:value-of select="$propertyName"/>");
                      return NULL;
                   }
                   </xsl:if>
                   </xsl:if>
                </xsl:if> <!-- if for attribute, -->
            </xsl:for-each>


            <xsl:if test="@type">
              string_to_stream = "&gt;"; <!-- The ending tag of the parent -->
              axutil_stream_write(stream, Environment::getEnv(), string_to_stream, axutil_strlen(string_to_stream));
              tag_closed = 1;
            </xsl:if>

             <!-- end bracket for if(!parent_tag_closed)-->
            <xsl:if test="count(property[@attribute])!=0 or @type">
            }
            </xsl:if>

            <xsl:if test="$isUnion">
            /* here we need to declare the union type in the xsi:type field */
            
            if(currentValue == "")
            {
                axis2_char_t *xsi_prefix = NULL;

                if(!(xsi_prefix = (axis2_char_t*)axutil_hash_get(namespaces, "http://www.w3.org/2001/XMLSchema-instance", AXIS2_HASH_KEY_STRING)))
                {
                    /* it is better to stick with the standard prefix */
                    xsi_prefix = (axis2_char_t*)axutil_strdup(Environment::getEnv(), "xsi");
                    
                    axutil_hash_set(namespaces, "http://www.w3.org/2001/XMLSchema-instance", AXIS2_HASH_KEY_STRING, xsi_prefix);

                    if(parent_element)
                    {
                          axiom_namespace_t *element_ns = NULL;
                          element_ns = axiom_namespace_create(Environment::getEnv(), "http://www.w3.org/2001/XMLSchema-instance",
                                                              xsi_prefix);
                          axiom_element_declare_namespace_assume_param_ownership(parent_element, Environment::getEnv(), element_ns);
                    }
                }

                <xsl:for-each select="memberType">
                    <xsl:variable name="member_type"><xsl:value-of select="@type"/><xsl:if test="@ours"/></xsl:variable>
                    <xsl:variable name="member_type_ns" select="@nsuri"/>
                    <xsl:variable name="member_name"><xsl:text></xsl:text><xsl:value-of select="@originalName"/></xsl:variable>

                    if(currentValue != "<xsl:value-of select="@originalName"/>")
                    {
                        axis2_char_t *ns_prefix = NULL;

                        if(!(ns_prefix = (axis2_char_t*)axutil_hash_get(namespaces, "<xsl:value-of select="$member_type_ns"/>", AXIS2_HASH_KEY_STRING)))
                        {
                            ns_prefix = (axis2_char_t*)AXIS2_MALLOC(Environment::getEnv()->allocator, sizeof (axis2_char_t) * ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT);
                            
                            sprintf(ns_prefix, "q%d", (*next_ns_index)++); <!-- just different prefix for the special case -->
                            axutil_hash_set(namespaces, "<xsl:value-of select="$member_type_ns"/>", AXIS2_HASH_KEY_STRING, ns_prefix);

                            if(parent_element)
                            {
                                  axiom_namespace_t *element_ns = NULL;
                                  element_ns = axiom_namespace_create(Environment::getEnv(), "<xsl:value-of select="$member_type_ns"/>",
                                                                      ns_prefix);
                                  axiom_element_declare_namespace_assume_param_ownership(parent_element, Environment::getEnv(), element_ns);
                            }
                        }

                        /* now we will set the xsi:type="ns:type" value */

                       if(!parent_tag_closed &amp;&amp; !tag_closed)
                       {
                            text_value = axutil_strcat(Environment::getEnv(), xsi_prefix, " type=", ns_prefix, ":", currentValue.c_str(), NULL);
                            axutil_stream_write(stream, Environment::getEnv(), text_value, axutil_strlen(text_value));

                            AXIS2_FREE(Environment::getEnv()->allocator, text_value);
                        }
                        else 
                        {
                            /* otherwise set it to the prarent itself */

                             axiom_namespace_t *ns1 = NULL;
                             axiom_attribute_t *attrib = NULL;
                        
                             ns1 = axiom_namespace_create (Environment::getEnv(),
                                                         "http://www.w3.org/2001/XMLSchema-instance",
                                                         xsi_prefix);
                        
                             text_value = axutil_strcat(Environment::getEnv(), ns_prefix, ":", currentValue.c_str(), NULL);
                             attrib = axiom_attribute_create (Environment::getEnv(), "type", text_value, ns1);
                             axiom_element_add_attribute (parent_element, Environment::getEnv(), attrib, parent);
                            
                             AXIS2_FREE(Environment::getEnv()->allocator, text_value);
                        }
                    }
                </xsl:for-each>
            }
            </xsl:if>

            <xsl:if test="@simple">
               if(!parent_tag_closed &amp;&amp; !tag_closed)
               {
                  text_value = "&gt;"; <!-- The ending tag of the parent -->
                  axutil_stream_write(stream, Environment::getEnv(), text_value, axutil_strlen(text_value));
               }
               <!-- how if this type is a qname :(, simply we are not handling that situation.. -->
               text_value = serializeToString(namespaces);
               if(text_value)
               {
                    axutil_stream_write(stream, Environment::getEnv(), text_value, axutil_strlen(text_value));
                    AXIS2_FREE(Environment::getEnv()->allocator, text_value);
               }
            </xsl:if>

            <xsl:for-each select="property">
              <xsl:variable name="position"><xsl:value-of select="position()"/></xsl:variable>
              <xsl:variable name="propertyType">
                 <xsl:choose>
                   <xsl:when test="@isarray">std::vector&lt;<xsl:value-of select="@type"/><xsl:if test="@ours or @type='std::string' or @type='unsigned char' or @type='unsigned short' or @type='uint64_t' or @type='unsigned int' or @type='short' or @type='char' or @type='int' or @type='float' or @type='double' or @type='int64_t'"><xsl:text>*</xsl:text></xsl:if>&gt;*</xsl:when>
                   <xsl:when test="not(@type)">wso2wsf::OMElement*</xsl:when> <!-- these are anonymous -->
                   <xsl:otherwise><xsl:value-of select="@type"/><xsl:if test="@ours">*</xsl:if></xsl:otherwise>
                 </xsl:choose>
              </xsl:variable>
              <xsl:variable name="nativePropertyType"> <!--these are used in arrays to take the native type-->
                 <xsl:choose>
                   <xsl:when test="not(@type)">wso2wsf::OMElement*</xsl:when> <!-- these are anonymous -->
                   <xsl:otherwise><xsl:value-of select="@type"/></xsl:otherwise>
                 </xsl:choose>
              </xsl:variable>
              <xsl:variable name="propertyName"><xsl:value-of select="@originalName"></xsl:value-of></xsl:variable>
              <xsl:variable name="CName"><xsl:value-of select="@cname"></xsl:value-of></xsl:variable>

              <xsl:variable name="propertyInstanceName"><!--these are used in arrays to take the native type-->
                 <xsl:choose>
                   <xsl:when test="@isarray">
                       <xsl:choose>
                           <xsl:when test="@type='std::string' or @type='unsigned char' or @type='unsigned short' or @type='uint64_t' or @type='unsigned int' or @type='short' or @type='char' or @type='int' or @type='float' or @type='double' or @type='int64_t'">
                           <xsl:text>(*element)</xsl:text>
                          </xsl:when>
                           <xsl:otherwise>element</xsl:otherwise>
                        </xsl:choose>
                     </xsl:when>
                   <xsl:otherwise>property_<xsl:value-of select="$CName"/></xsl:otherwise>
                 </xsl:choose>
              </xsl:variable>
              <xsl:variable name="justPropertyInstanceName"><!--these are used in arrays to take the native type-->
                 <xsl:choose>
                   <xsl:when test="@isarray">element</xsl:when>
                   <xsl:otherwise>property_<xsl:value-of select="$CName"/></xsl:otherwise>
                 </xsl:choose>
              </xsl:variable>
              <xsl:variable name="parentPropertyInstanceName">property_<xsl:value-of select="$CName"/></xsl:variable>

              <xsl:choose>
                <xsl:when test="@attribute">
                    <!-- here only simple type possible -->
                    if(parent_tag_closed)
                    {
                       if(isValid<xsl:value-of select="$CName"/>)
                       {
                       <xsl:choose>
                       <xsl:when test="$nativePropertyType='wso2wsf::OMAttribute*' and @isarray"><!-- for anyAttribute -->
                        int i = 0;
                        for( i = 0; i &lt;<xsl:value-of select="$parentPropertyInstanceName"/>->size();i++)
                        {
                            axiom_attribute_t *the_attrib = NULL;
                            axiom_attribute_t *dup_attrib = NULL;
                            wso2wsf::OMAttribute *attrib = NULL;
                            axis2_char_t *uri = NULL;
                            axis2_char_t *p_prefix = NULL;
                            axutil_qname_t *qname = NULL;
                            axis2_char_t *value = NULL;
                            axis2_char_t *local_name = NULL;
                            axiom_namespace_t *ns1 = NULL;
                            attrib =  (*<xsl:value-of select="$parentPropertyInstanceName"/>)[i];
                            the_attrib = attrib->getAxiomAttribute();
                            qname = axiom_attribute_get_qname(the_attrib, Environment::getEnv());
                            uri = axutil_qname_get_uri(qname, Environment::getEnv());
                            value = axiom_attribute_get_value(the_attrib, Environment::getEnv());
                            local_name = axutil_qname_get_localpart(qname, Environment::getEnv());

                            p_prefix = NULL;
                            if(uri) /* means we have to go for a prefix */
                            {
                                if(!(p_prefix = (axis2_char_t*)axutil_hash_get(namespaces, uri, AXIS2_HASH_KEY_STRING)))
                                {
                                    p_prefix = (axis2_char_t*)AXIS2_MALLOC(Environment::getEnv()->allocator, sizeof (axis2_char_t) * ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT);
                                    sprintf(p_prefix, "n%d", (*next_ns_index)++);
                                    axutil_hash_set(namespaces, uri, AXIS2_HASH_KEY_STRING, p_prefix);
                                    axiom_element_declare_namespace_assume_param_ownership(parent_element, Environment::getEnv(), axiom_namespace_create (Environment::getEnv(),
                                                             uri,
                                                             p_prefix));
                                     
                                }

                            }

                            ns1 = axiom_namespace_create (Environment::getEnv(),
                                                uri,
                                                p_prefix);

                            dup_attrib = axiom_attribute_create (Environment::getEnv(), local_name, value, ns1);
                            <!-- TODO: parent here can be data_source node, not element node should be fixed -->
                            axiom_element_add_attribute (parent_element, Environment::getEnv(), dup_attrib, parent);

                        }
                       </xsl:when>
                       <xsl:otherwise>
                       <xsl:choose>
                         <xsl:when test="@nsuri and @nsuri != ''">
                           if(!(p_prefix = (axis2_char_t*)axutil_hash_get(namespaces, "<xsl:value-of select="@nsuri"/>", AXIS2_HASH_KEY_STRING)))
                           {
                               p_prefix = (axis2_char_t*)AXIS2_MALLOC(Environment::getEnv()->allocator, sizeof (axis2_char_t) * ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT);
                               sprintf(p_prefix, "n%d", (*next_ns_index)++);
                               axutil_hash_set(namespaces, "<xsl:value-of select="@nsuri"/>", AXIS2_HASH_KEY_STRING, p_prefix);
                               
                               axiom_element_declare_namespace_assume_param_ownership(parent_element, Environment::getEnv(), axiom_namespace_create (Environment::getEnv(),
                                                "<xsl:value-of select="@nsuri"/>",
                                                p_prefix));
                           }
                           ns1 = axiom_namespace_create (Environment::getEnv(),
                                                "<xsl:value-of select="@nsuri"/>",
                                                p_prefix);
                         </xsl:when>
                         <xsl:otherwise>
                           p_prefix = NULL;
                           ns1 = NULL;
                         </xsl:otherwise>
                       </xsl:choose> <!-- close for test nsuri and nsuri != "" -->

                       <xsl:choose>
                        <!-- add int s -->
                        <xsl:when test="$nativePropertyType='int' or $nativePropertyType='unsigned int'">
                           text_value = (axis2_char_t*) AXIS2_MALLOC (Environment::getEnv()-> allocator, sizeof (axis2_char_t) * ADB_DEFAULT_DIGIT_LIMIT);
                           sprintf (text_value, "%d", <xsl:value-of select="$propertyInstanceName"/>);
                           text_attri = axiom_attribute_create (Environment::getEnv(), "<xsl:value-of select="$propertyName"/>", text_value, ns1);
                           <!-- TODO: parent here can be data_source node, not element node should be fixed -->
                           axiom_element_add_attribute (parent_element, Environment::getEnv(), text_attri, parent);
                           AXIS2_FREE(Environment::getEnv()-> allocator, text_value);
                        </xsl:when>

                        <!-- add axis2_byte_t s -->
                        <xsl:when test="$nativePropertyType='axis2_byte_t' or $nativePropertyType='axis2_unsigned_byte_t'">
                           text_value = (axis2_char_t*) AXIS2_MALLOC (Environment::getEnv()-> allocator, sizeof (axis2_char_t) * ADB_DEFAULT_DIGIT_LIMIT);
                           sprintf (text_value, "%d", <xsl:value-of select="$propertyInstanceName"/>);
                           text_attri = axiom_attribute_create (Environment::getEnv(), "<xsl:value-of select="$propertyName"/>", text_value, ns1);
                           axiom_element_add_attribute (parent_element, Environment::getEnv(), text_attri, parent);
                           AXIS2_FREE(Environment::getEnv()-> allocator, text_value);
                        </xsl:when>

                        <!-- add int s -->
                        <xsl:when test="$nativePropertyType='char' or $nativePropertyType='unsigned char'">
                           text_value = (axis2_char_t*) AXIS2_MALLOC (Environment::getEnv()-> allocator, sizeof (axis2_char_t) * ADB_DEFAULT_DIGIT_LIMIT);
                           sprintf (text_value, "%c", <xsl:value-of select="$propertyInstanceName"/>);
                           text_attri = axiom_attribute_create (Environment::getEnv(), "<xsl:value-of select="$propertyName"/>", text_value, ns1);
                           axiom_element_add_attribute (parent_element, Environment::getEnv(), text_attri, parent);
                           AXIS2_FREE(Environment::getEnv()-> allocator, text_value);
                        </xsl:when>

                        <!-- add short s -->
                        <xsl:when test="$nativePropertyType='short' or $nativePropertyType='unsigned short'">
                           text_value = (axis2_char_t*) AXIS2_MALLOC (Environment::getEnv()-> allocator, sizeof (axis2_char_t) * ADB_DEFAULT_DIGIT_LIMIT);
                           sprintf (text_value, "%d", <xsl:value-of select="$propertyInstanceName"/>);
                           text_attri = axiom_attribute_create (Environment::getEnv(), "<xsl:value-of select="$propertyName"/>", text_value, ns1);
                           axiom_element_add_attribute (parent_element, Environment::getEnv(), text_attri, parent);
                           AXIS2_FREE(Environment::getEnv()-> allocator, text_value);
                        </xsl:when>

                        <!-- add int64_t s -->
                        <xsl:when test="$nativePropertyType='int64_t'">
                           text_value = (axis2_char_t*) AXIS2_MALLOC (Environment::getEnv()-> allocator, sizeof (axis2_char_t) * ADB_DEFAULT_DIGIT_LIMIT);
                           sprintf (text_value, AXIS2_PRINTF_INT64_FORMAT_SPECIFIER, (int64_t)<xsl:value-of select="$propertyInstanceName"/>);
                           text_attri = axiom_attribute_create (Environment::getEnv(), "<xsl:value-of select="$propertyName"/>", text_value, ns1);
                           axiom_element_add_attribute (parent_element, Environment::getEnv(), text_attri, parent);
                           AXIS2_FREE(Environment::getEnv()-> allocator, text_value);
                        </xsl:when>

                        <xsl:when test="$nativePropertyType='uint64_t'">
                           text_value = (axis2_char_t*) AXIS2_MALLOC (Environment::getEnv()-> allocator, sizeof (axis2_char_t) * ADB_DEFAULT_DIGIT_LIMIT);
                           sprintf (text_value, AXIS2_PRINTF_UINT64_FORMAT_SPECIFIER, (uint64_t)<xsl:value-of select="$propertyInstanceName"/>);
                           text_attri = axiom_attribute_create (Environment::getEnv(), "<xsl:value-of select="$propertyName"/>", text_value, ns1);
                           axiom_element_add_attribute (parent_element, Environment::getEnv(), text_attri, parent);
                           AXIS2_FREE(Environment::getEnv()-> allocator, text_value);
                        </xsl:when>

                        <!-- add float s -->
                        <xsl:when test="$nativePropertyType='float'">
                           text_value = (axis2_char_t*) AXIS2_MALLOC (Environment::getEnv()-> allocator, sizeof (axis2_char_t) * ADB_DEFAULT_DIGIT_LIMIT);
                           sprintf (text_value, "%f", <xsl:value-of select="$propertyInstanceName"/>);
                           text_attri = axiom_attribute_create (Environment::getEnv(), "<xsl:value-of select="$propertyName"/>", text_value, ns1);
                           axiom_element_add_attribute (parent_element, Environment::getEnv(), text_attri, parent);
                           AXIS2_FREE(Environment::getEnv()-> allocator, text_value);
                        </xsl:when>

                        <!-- add double s -->
                        <xsl:when test="$nativePropertyType='double'">
                           text_value = (axis2_char_t*) AXIS2_MALLOC (Environment::getEnv()-> allocator, sizeof (axis2_char_t) * ADB_DEFAULT_DIGIT_LIMIT);
                           sprintf (text_value, "%f", <xsl:value-of select="$propertyInstanceName"/>);
                           text_attri = axiom_attribute_create (Environment::getEnv(), "<xsl:value-of select="$propertyName"/>", text_value, ns1);
                           axiom_element_add_attribute (parent_element, Environment::getEnv(), text_attri, parent);
                           AXIS2_FREE(Environment::getEnv()-> allocator, text_value);
                        </xsl:when>

                        <!-- add axis2_char_t s -->
                        <xsl:when test="$nativePropertyType='std::string'">
                           text_value = (axis2_char_t*)<xsl:value-of select="$propertyInstanceName"/>.c_str();
                           text_attri = axiom_attribute_create (Environment::getEnv(), "<xsl:value-of select="$propertyName"/>", text_value, ns1);
                           axiom_element_add_attribute (parent_element, Environment::getEnv(), text_attri, parent);
                        </xsl:when>

                        <!-- add axutil_uri_t s -->
                        <xsl:when test="$nativePropertyType='axutil_uri_t*'">
                           text_value = axutil_uri_to_string(<xsl:value-of select="$propertyInstanceName"/>, Environment::getEnv(), AXIS2_URI_UNP_OMITUSERINFO);
                           text_attri = axiom_attribute_create (Environment::getEnv(), "<xsl:value-of select="$propertyName"/>", text_value, ns1);
                           axiom_element_add_attribute (parent_element, Environment::getEnv(), text_attri, parent);
                        </xsl:when>

                        <!-- add axutil_duration_t s -->
                        <xsl:when test="$nativePropertyType='axutil_duration_t*'">
                           text_value = axutil_duration_serialize_duration(<xsl:value-of select="$propertyInstanceName"/>, Environment::getEnv());
                           text_attri = axiom_attribute_create (Environment::getEnv(), "<xsl:value-of select="$propertyName"/>", text_value, ns1);
                           axiom_element_add_attribute (parent_element, Environment::getEnv(), text_attri, parent);
                        </xsl:when>

                        <!-- add axutil_qname_t s -->
                        <xsl:when test="$nativePropertyType='axutil_qname_t*'">

                           qname_uri =  axutil_qname_get_uri(<xsl:value-of select="$propertyInstanceName"/>, Environment::getEnv());
                           if(qname_uri)
                           {
                               if(!(qname_prefix = (axis2_char_t*)axutil_hash_get(namespaces, qname_uri, AXIS2_HASH_KEY_STRING)))
                               {

                                   qname_prefix = (axis2_char_t*)AXIS2_MALLOC(Environment::getEnv()->allocator, sizeof (axis2_char_t) * ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT);

                                   sprintf(qname_prefix, "q%d", (*next_ns_index) ++ ); <!-- just different prefix for the special case -->

                                   axutil_hash_set(namespaces, qname_uri, AXIS2_HASH_KEY_STRING, qname_prefix);
                                   
                                   axiom_element_declare_namespace_assume_param_ownership(parent_element, Environment::getEnv(), axiom_namespace_create (Environment::getEnv(),
                                                     qname_uri,
                                                     qname_prefix));
                               }
                           }

                           text_value = (axis2_char_t*) AXIS2_MALLOC(Environment::getEnv()-> allocator,
                                         sizeof (axis2_char_t) * (ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT +
                                                             axutil_strlen(axutil_qname_get_localpart(<xsl:value-of select="$propertyInstanceName"/>, Environment::getEnv())) + 2));
                           sprintf(text_value, "%s%s%s", qname_uri?qname_prefix:"",
                                                        qname_uri?":":"",
                                                       axutil_qname_get_localpart(<xsl:value-of select="$propertyInstanceName"/>, Environment::getEnv()));

                           text_attri = axiom_attribute_create (Environment::getEnv(), "<xsl:value-of select="$propertyName"/>", text_value, ns1);
                           axiom_element_add_attribute (parent_element, Environment::getEnv(), text_attri, parent);
                           AXIS2_FREE(Environment::getEnv()->allocator, text_value);
                        </xsl:when>

                        <!-- add bool s -->
                        <xsl:when test="$nativePropertyType='bool'">
                           <!--text_value = (<xsl:value-of select="$propertyInstanceName"/>)?"true":"false";-->
                           text_value =  (axis2_char_t*)((<xsl:value-of select="$propertyInstanceName"/>)?axutil_strdup(Environment::getEnv(), "true"):axutil_strdup(Environment::getEnv(), "false"));
                           text_attri = axiom_attribute_create (Environment::getEnv(), "<xsl:value-of select="$propertyName"/>", text_value, ns1);
                           axiom_element_add_attribute (parent_element, Environment::getEnv(), text_attri, parent);
                           AXIS2_FREE(Environment::getEnv()->allocator, text_value);
                        </xsl:when>
                        <!-- add axis2_date_time_t s -->
                        <xsl:when test="$nativePropertyType='axutil_date_time_t*'">
                           text_value =  axutil_date_time_serialize_date_time(<xsl:value-of select="$propertyInstanceName"/>, Environment::getEnv());
                           text_attri = axiom_attribute_create (Environment::getEnv(), "<xsl:value-of select="$propertyName"/>", text_value, ns1);
                           axiom_element_add_attribute (parent_element, Environment::getEnv(), text_attri, parent);
                        </xsl:when>
                       <!-- add axis2_base64_binary_t s -->
                        <xsl:when test="$nativePropertyType='axutil_base64_binary_t*'">
                           text_value =  axutil_base64_binary_get_encoded_binary(<xsl:value-of select="$propertyInstanceName"/>, Environment::getEnv());
                           text_attri = axiom_attribute_create (Environment::getEnv(), "<xsl:value-of select="$propertyName"/>", text_value, ns1);
                           axiom_element_add_attribute (parent_element, Environment::getEnv(), text_attri, parent);
                        </xsl:when>
                        <xsl:when test="@ours">
                           <xsl:value-of select="$propertyInstanceName"/>->declareParentNamespaces(parent_element, namespaces, next_ns_index);
                           text_value = <xsl:value-of select="$propertyInstanceName"/>->serializeToString(namespaces);
                           if(text_value)
                           {
                               text_attri = axiom_attribute_create (Environment::getEnv(), "<xsl:value-of select="$propertyName"/>", text_value, ns1);
                               axiom_element_add_attribute (parent_element, Environment::getEnv(), text_attri, parent);
                               AXIS2_FREE(Environment::getEnv()-> allocator, text_value);
                           }
                        </xsl:when>
                        <xsl:otherwise>
                          <!--TODO: add new attributes types -->
                          /* Can not handle the attribute type <xsl:value-of select="$nativePropertyType"/>*/
                           text_value = NULL;
                           parent_element = NULL;
                           text_attri = NULL;
                        </xsl:otherwise>
                        </xsl:choose>
                       </xsl:otherwise>
                       </xsl:choose>
                      }
                      <xsl:if test="not(@optional)">
                      <xsl:if test="not($nativePropertyType='wso2wsf::OMAttribute*' and @isarray)"><!-- for anyAttribute -->
                      else
                      {
                         WSF_LOG_ERROR_MSG( Environment::getEnv()->log,WSF_LOG_SI,"Nil value found in non-optional attribute <xsl:value-of select="$propertyName"/>");
                         return NULL;
                      }
                      </xsl:if> 
                      </xsl:if> 
                  }<!-- End bracket for if(parent_tag_closed)-->
                </xsl:when>
                <xsl:when test="$simple"></xsl:when> <!--Just to ignore parsing following code at simple types-->
                <xsl:otherwise>
 
                <xsl:if test="$choice">
                if(0 == axutil_strcmp(currentChoice.c_str(), "<xsl:value-of select="@nsuri"/>:<xsl:value-of select="$propertyName"/>"))
                {
                </xsl:if>


                   <xsl:choose>
                     <xsl:when test="@nsuri and @nsuri != ''">
                       if(!(p_prefix = (axis2_char_t*)axutil_hash_get(namespaces, "<xsl:value-of select="@nsuri"/>", AXIS2_HASH_KEY_STRING)))
                       {
                           p_prefix = (axis2_char_t*)AXIS2_MALLOC(Environment::getEnv()->allocator, sizeof (axis2_char_t) * ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT);
                           sprintf(p_prefix, "n%d", (*next_ns_index)++);
                           axutil_hash_set(namespaces, "<xsl:value-of select="@nsuri"/>", AXIS2_HASH_KEY_STRING, p_prefix);
                           
                           axiom_element_declare_namespace_assume_param_ownership(parent_element, Environment::getEnv(), axiom_namespace_create (Environment::getEnv(),
                                            "<xsl:value-of select="@nsuri"/>", p_prefix));
                       }
                     </xsl:when>
                     <xsl:otherwise>
                       p_prefix = NULL;
                     </xsl:otherwise>
                   </xsl:choose> <!-- close for test nsuri and nsuri != "" -->

                   if (!isValid<xsl:value-of select="$CName"/>)
                   {
                      <xsl:if test="@nillable">
                        <xsl:choose>
                          <xsl:when test="@minOccurs=0">
                           /* no need to complain for minoccurs=0 element */
                            <!-- just ignore the element.. -->
                          </xsl:when>
                          <xsl:otherwise>
                            <!-- just write a nil element -->
                            start_input_str = (axis2_char_t*)AXIS2_MALLOC(Environment::getEnv()->allocator, sizeof(axis2_char_t) *
                                        (5 + axutil_strlen(p_prefix) + 
                                         axutil_strlen("<xsl:value-of select="$propertyName"/>") + 
                                         axutil_strlen(" xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\" xsi:nil=\"1\""))); 
                                        <!-- axutil_strlen("<:/>") + 1 = 5 -->
                            
                            sprintf(start_input_str, "&lt;%s%s<xsl:value-of select="$propertyName"/> xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\" xsi:nil=\"1\"/&gt;",
                                        p_prefix?p_prefix:"",
                                        (p_prefix &amp;&amp; axutil_strcmp(p_prefix, ""))?":":"");
                                        
                            axutil_stream_write(stream, Environment::getEnv(), start_input_str, axutil_strlen(start_input_str));
                            AXIS2_FREE(Environment::getEnv()->allocator,start_input_str);
                          </xsl:otherwise>
                        </xsl:choose>
                      </xsl:if>

                      <xsl:if test="not(@nillable)">
                        <xsl:choose>
                          <xsl:when test="@minOccurs=0">
                           /* no need to complain for minoccurs=0 element */
                            <!-- just ignore the element.. -->
                          </xsl:when>
                          <xsl:otherwise>
                            <!-- just return an error -->
                            WSF_LOG_ERROR_MSG( Environment::getEnv()->log,WSF_LOG_SI,"Nil value found in non-nillable property <xsl:value-of select="$propertyName"/>");
                            return NULL;
                          </xsl:otherwise>
                        </xsl:choose>
                      </xsl:if>
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(Environment::getEnv()->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("<xsl:value-of select="$propertyName"/>"))); 
                                 <!-- axutil_strlen("<:>") + 1 = 4 -->
                                 /* axutil_strlen("&lt;:&gt;") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(Environment::getEnv()->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("<xsl:value-of select="$propertyName"/>")));
                                  /* axutil_strlen("&lt;/:&gt;") + 1 = 5 */
                                  <!-- axutil_strlen("</:>") + 1 = 5 -->
                     

                   <!-- handles arrays -->
                   <xsl:if test="@isarray">
                     /*
                      * Parsing <xsl:value-of select="$CName"/> array
                      */
                     if (property_<xsl:value-of select="$CName"/> != NULL)
                     {
                        <xsl:choose>
                            <xsl:when test="@ours">

                            sprintf(start_input_str, "&lt;%s%s<xsl:value-of select="$propertyName"/>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix &amp;&amp; axutil_strcmp(p_prefix, ""))?":":"");
                            </xsl:when>
                            <xsl:otherwise>
                            sprintf(start_input_str, "&lt;%s%s<xsl:value-of select="$propertyName"/>&gt;",
                                 p_prefix?p_prefix:"",
                                 (p_prefix &amp;&amp; axutil_strcmp(p_prefix, ""))?":":""); 
                            </xsl:otherwise>
                        </xsl:choose>
                         start_input_str_len = axutil_strlen(start_input_str);

                         sprintf(end_input_str, "&lt;/%s%s<xsl:value-of select="$propertyName"/>&gt;",
                                 p_prefix?p_prefix:"",
                                 (p_prefix &amp;&amp; axutil_strcmp(p_prefix, ""))?":":"");
                         end_input_str_len = axutil_strlen(end_input_str);

                         count = property_<xsl:value-of select="$CName"/>->size();
                         for(i = 0; i &lt; count; i++)
                         {
                            <xsl:value-of select="@type"/><xsl:choose><xsl:when test="contains(@type,'*')"> </xsl:when><xsl:otherwise>*</xsl:otherwise></xsl:choose> element = (*property_<xsl:value-of select="$CName"/>)[i];

                            if(NULL == element) <!--validty of individual -->
                            {
                                continue;
                            }

                    </xsl:if>
                     <!-- for each non attribute properties there will always be an element-->
                     /*
                      * parsing <xsl:value-of select="$propertyName"/> element
                      */

                    <!-- how to build all the ours things -->
                    <xsl:if test="not(@isarray)">
                        <xsl:choose>
                            <xsl:when test="@ours">
                            sprintf(start_input_str, "&lt;%s%s<xsl:value-of select="$propertyName"/>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix &amp;&amp; axutil_strcmp(p_prefix, ""))?":":""); 
                            </xsl:when>
                            <xsl:otherwise>
                            sprintf(start_input_str, "&lt;%s%s<xsl:value-of select="$propertyName"/>&gt;",
                                 p_prefix?p_prefix:"",
                                 (p_prefix &amp;&amp; axutil_strcmp(p_prefix, ""))?":":"");
                            </xsl:otherwise>
                        </xsl:choose>
                        start_input_str_len = axutil_strlen(start_input_str);
                        sprintf(end_input_str, "&lt;/%s%s<xsl:value-of select="$propertyName"/>&gt;",
                                 p_prefix?p_prefix:"",
                                 (p_prefix &amp;&amp; axutil_strcmp(p_prefix, ""))?":":"");
                        end_input_str_len = axutil_strlen(end_input_str);
                    </xsl:if>


                      <xsl:choose>
                        <xsl:when test="@ours">
                            <xsl:if test="$anon or $istype"> <!-- As this shows, elements are not writing their tags here from stream.
                                                                 It is done using axiom manipualation above..-->
                            if(!<xsl:value-of select="$propertyInstanceName"/>->isParticle())
                            {
                                axutil_stream_write(stream, Environment::getEnv(), start_input_str, start_input_str_len);
                            }
                            </xsl:if>
                            
                            <xsl:variable name="element_closed">
                                <xsl:choose>
                                    <xsl:when test="../@type">false</xsl:when>
                                    <!-- this mean the anonymous header is writing -->
                                    <xsl:when test="$anon or $istype">false</xsl:when>
                                    <xsl:otherwise>true</xsl:otherwise>
                                </xsl:choose>
                            </xsl:variable>
                            <xsl:value-of select="$propertyInstanceName"/>->serialize(current_node, parent_element,
                                                                                 <xsl:value-of select="$propertyInstanceName"/>->isParticle() || <xsl:value-of select="$element_closed"/>, namespaces, next_ns_index);
                            <xsl:if test="$anon or $istype">
                            if(!<xsl:value-of select="$propertyInstanceName"/>->isParticle())
                            {
                                axutil_stream_write(stream, Environment::getEnv(), end_input_str, end_input_str_len);
                            }
                            </xsl:if>
                        </xsl:when>

                        <!-- add int s -->
                        <xsl:when test="$nativePropertyType='int'">
                           <xsl:choose>
                             <xsl:when test="@isarray">
                               sprintf (text_value_<xsl:value-of select="$position"/>, AXIS2_PRINTF_INT32_FORMAT_SPECIFIER, *element);
                             </xsl:when>
                             <xsl:otherwise>
                               sprintf (text_value_<xsl:value-of select="$position"/>, AXIS2_PRINTF_INT32_FORMAT_SPECIFIER, <xsl:value-of select="$propertyInstanceName"/>);
                             </xsl:otherwise>
                           </xsl:choose>
                           <xsl:if test="$anon or $istype">
                           axutil_stream_write(stream, Environment::getEnv(), start_input_str, start_input_str_len);
                           </xsl:if>
                           axutil_stream_write(stream, Environment::getEnv(), text_value_<xsl:value-of select="$position"/>, axutil_strlen(text_value_<xsl:value-of select="$position"/>));
                           <xsl:if test="$anon or $istype">
                           axutil_stream_write(stream, Environment::getEnv(), end_input_str, end_input_str_len);
                           </xsl:if>
                        </xsl:when>

                        <xsl:when test="$nativePropertyType='unsigned int'">
                           <xsl:choose>
                             <xsl:when test="@isarray">
                               sprintf (text_value_<xsl:value-of select="$position"/>, AXIS2_PRINTF_UINT32_FORMAT_SPECIFIER, *element);
                             </xsl:when>
                             <xsl:otherwise>
                               sprintf (text_value_<xsl:value-of select="$position"/>, AXIS2_PRINTF_UINT32_FORMAT_SPECIFIER, <xsl:value-of select="$propertyInstanceName"/>);
                             </xsl:otherwise>
                           </xsl:choose>
                           <xsl:if test="$anon or $istype">
                           axutil_stream_write(stream, Environment::getEnv(), start_input_str, start_input_str_len);
                           </xsl:if>
                           axutil_stream_write(stream, Environment::getEnv(), text_value_<xsl:value-of select="$position"/>, axutil_strlen(text_value_<xsl:value-of select="$position"/>));
                           <xsl:if test="$anon or $istype">
                           axutil_stream_write(stream, Environment::getEnv(), end_input_str, end_input_str_len);
                           </xsl:if>
                        </xsl:when>

                        <!-- add char s -->
                        <xsl:when test="$nativePropertyType='char'">
                           <xsl:choose>
                             <xsl:when test="@isarray">
                               sprintf (text_value_<xsl:value-of select="$position"/>, "%c", element);
                             </xsl:when>
                             <xsl:otherwise>
                               sprintf (text_value_<xsl:value-of select="$position"/>, "%c", <xsl:value-of select="$propertyInstanceName"/>);
                             </xsl:otherwise>
                           </xsl:choose>
                           <xsl:if test="$anon or $istype">
                           axutil_stream_write(stream, Environment::getEnv(), start_input_str, start_input_str_len);
                           </xsl:if>
                           axutil_stream_write(stream, Environment::getEnv(), text_value_<xsl:value-of select="$position"/>, axutil_strlen(text_value_<xsl:value-of select="$position"/>));
                           <xsl:if test="$anon or $istype">
                           axutil_stream_write(stream, Environment::getEnv(), end_input_str, end_input_str_len);
                           </xsl:if>
                        </xsl:when>

                        <xsl:when test="$nativePropertyType='unsigned char'">
                           <xsl:choose>
                             <xsl:when test="@isarray">
                               sprintf (text_value_<xsl:value-of select="$position"/>, "%c", element);
                             </xsl:when>
                             <xsl:otherwise>
                               sprintf (text_value_<xsl:value-of select="$position"/>, "%c", <xsl:value-of select="$propertyInstanceName"/>);
                             </xsl:otherwise>
                           </xsl:choose>
                           <xsl:if test="$anon or $istype">
                           axutil_stream_write(stream, Environment::getEnv(), start_input_str, start_input_str_len);
                           </xsl:if>
                           axutil_stream_write(stream, Environment::getEnv(), text_value_<xsl:value-of select="$position"/>, axutil_strlen(text_value_<xsl:value-of select="$position"/>));
                           <xsl:if test="$anon or $istype">
                           axutil_stream_write(stream, Environment::getEnv(), end_input_str, end_input_str_len);
                           </xsl:if>
                        </xsl:when>

                        <xsl:when test="$nativePropertyType='axis2_byte_t' or $nativePropertyType='axis2_unsigned_byte_t'">
                           <xsl:choose>
                             <xsl:when test="@isarray">
                               sprintf (text_value_<xsl:value-of select="$position"/>, "%d", element);
                             </xsl:when>
                             <xsl:otherwise>
                               sprintf (text_value_<xsl:value-of select="$position"/>, "%d", <xsl:value-of select="$propertyInstanceName"/>);
                             </xsl:otherwise>
                           </xsl:choose>
                           <xsl:if test="$anon or $istype">
                           axutil_stream_write(stream, Environment::getEnv(), start_input_str, start_input_str_len);
                           </xsl:if>
                           axutil_stream_write(stream, Environment::getEnv(), text_value_<xsl:value-of select="$position"/>, axutil_strlen(text_value_<xsl:value-of select="$position"/>));
                           <xsl:if test="$anon or $istype">
                           axutil_stream_write(stream, Environment::getEnv(), end_input_str, end_input_str_len);
                           </xsl:if>
                        </xsl:when>

                        <!-- add short s -->
                        <xsl:when test="$nativePropertyType='short'">
                           <xsl:choose>
                             <xsl:when test="@isarray">
                               sprintf (text_value_<xsl:value-of select="$position"/>, "%d", *element);
                             </xsl:when>
                             <xsl:otherwise>
                               sprintf (text_value_<xsl:value-of select="$position"/>, "%d", <xsl:value-of select="$propertyInstanceName"/>);
                             </xsl:otherwise>
                           </xsl:choose>
                           <xsl:if test="$anon or $istype">
                           axutil_stream_write(stream, Environment::getEnv(), start_input_str, start_input_str_len);
                           </xsl:if>
                           axutil_stream_write(stream, Environment::getEnv(), text_value_<xsl:value-of select="$position"/>, axutil_strlen(text_value_<xsl:value-of select="$position"/>));
                           <xsl:if test="$anon or $istype">
                           axutil_stream_write(stream, Environment::getEnv(), end_input_str, end_input_str_len);
                           </xsl:if>
                        </xsl:when>

                        <xsl:when test="$nativePropertyType='unsigned short'">
                           <xsl:choose>
                             <xsl:when test="@isarray">
                               sprintf (text_value_<xsl:value-of select="$position"/>, "%hu", *element);
                             </xsl:when>
                             <xsl:otherwise>
                               sprintf (text_value_<xsl:value-of select="$position"/>, "%hu", <xsl:value-of select="$propertyInstanceName"/>);
                             </xsl:otherwise>
                           </xsl:choose>
                           <xsl:if test="$anon or $istype">
                           axutil_stream_write(stream, Environment::getEnv(), start_input_str, start_input_str_len);
                           </xsl:if>
                           axutil_stream_write(stream, Environment::getEnv(), text_value_<xsl:value-of select="$position"/>, axutil_strlen(text_value_<xsl:value-of select="$position"/>));
                           <xsl:if test="$anon or $istype">
                           axutil_stream_write(stream, Environment::getEnv(), end_input_str, end_input_str_len);
                           </xsl:if>
                        </xsl:when>


                        <!-- NOTE: arrays for int64_t, float, int are handled differently. they are stored in pointers -->
                        <!-- add int64_t s -->
                        <xsl:when test="$nativePropertyType='int64_t'">
                           <xsl:choose>
                             <xsl:when test="@isarray">
                               sprintf (text_value_<xsl:value-of select="$position"/>, AXIS2_PRINTF_INT64_FORMAT_SPECIFIER, *element);
                             </xsl:when>
                             <xsl:otherwise>
                               sprintf (text_value_<xsl:value-of select="$position"/>, AXIS2_PRINTF_INT64_FORMAT_SPECIFIER, (int64_t) <xsl:value-of select="$propertyInstanceName"/>);
                             </xsl:otherwise>
                           </xsl:choose>
                           <xsl:if test="$anon or $istype">
                           axutil_stream_write(stream, Environment::getEnv(), start_input_str, start_input_str_len);
                           </xsl:if>
                           axutil_stream_write(stream, Environment::getEnv(), text_value_<xsl:value-of select="$position"/>, axutil_strlen(text_value_<xsl:value-of select="$position"/>));
                           <xsl:if test="$anon or $istype">
                           axutil_stream_write(stream, Environment::getEnv(), end_input_str, end_input_str_len);
                           </xsl:if>
                        </xsl:when>

                        <!-- add int64_t s -->
                        <xsl:when test="$nativePropertyType='uint64_t'">
                           <xsl:choose>
                             <xsl:when test="@isarray">
                               sprintf (text_value_<xsl:value-of select="$position"/>, AXIS2_PRINTF_UINT64_FORMAT_SPECIFIER, *element);
                             </xsl:when>
                             <xsl:otherwise>
                               sprintf (text_value_<xsl:value-of select="$position"/>, AXIS2_PRINTF_UINT64_FORMAT_SPECIFIER, (uint64_t)<xsl:value-of select="$propertyInstanceName"/>);
                             </xsl:otherwise>
                           </xsl:choose>
                           <xsl:if test="$anon or $istype">
                           axutil_stream_write(stream, Environment::getEnv(), start_input_str, start_input_str_len);
                           </xsl:if>
                           axutil_stream_write(stream, Environment::getEnv(), text_value_<xsl:value-of select="$position"/>, axutil_strlen(text_value_<xsl:value-of select="$position"/>));
                           <xsl:if test="$anon or $istype">
                           axutil_stream_write(stream, Environment::getEnv(), end_input_str, end_input_str_len);
                           </xsl:if>
                        </xsl:when>

                        <!-- add float s -->
                        <xsl:when test="$nativePropertyType='float'">
                           <xsl:choose>
                             <xsl:when test="@isarray">
                               sprintf (text_value_<xsl:value-of select="$position"/>, "%f", *element);
                             </xsl:when>
                             <xsl:otherwise>
                               sprintf (text_value_<xsl:value-of select="$position"/>, "%f", (float)<xsl:value-of select="$propertyInstanceName"/>);
                             </xsl:otherwise>
                           </xsl:choose>
                           <xsl:if test="$anon or $istype">
                           axutil_stream_write(stream, Environment::getEnv(), start_input_str, start_input_str_len);
                           </xsl:if>
                           axutil_stream_write(stream, Environment::getEnv(), text_value_<xsl:value-of select="$position"/>, axutil_strlen(text_value_<xsl:value-of select="$position"/>));
                           <xsl:if test="$anon or $istype">
                           axutil_stream_write(stream, Environment::getEnv(), end_input_str, end_input_str_len);
                           </xsl:if>
                        </xsl:when>

                        <!-- add double s -->
                        <xsl:when test="$nativePropertyType='double'">
                           <xsl:choose>
                             <xsl:when test="@isarray">
                               sprintf (text_value_<xsl:value-of select="$position"/>, "%f", *element);
                             </xsl:when>
                             <xsl:otherwise>
                               sprintf (text_value_<xsl:value-of select="$position"/>, "%f", (double)<xsl:value-of select="$propertyInstanceName"/>);
                             </xsl:otherwise>
                           </xsl:choose>
                           <xsl:if test="$anon or $istype">
                           axutil_stream_write(stream, Environment::getEnv(), start_input_str, start_input_str_len);
                           </xsl:if>
                           axutil_stream_write(stream, Environment::getEnv(), text_value_<xsl:value-of select="$position"/>, axutil_strlen(text_value_<xsl:value-of select="$position"/>));
                           <xsl:if test="$anon or $istype">
                           axutil_stream_write(stream, Environment::getEnv(), end_input_str, end_input_str_len);
                           </xsl:if>
                        </xsl:when>

                        <!-- add axis2_char_t s -->
                        <xsl:when test="$nativePropertyType='std::string'">
                           text_value_<xsl:value-of select="$position"/> = (axis2_char_t*)<xsl:value-of select="$propertyInstanceName"/>.c_str();
                           <xsl:if test="$anon or $istype">
                           axutil_stream_write(stream, Environment::getEnv(), start_input_str, start_input_str_len);
                           </xsl:if>
                            
                           text_value_<xsl:value-of select="$position"/>_temp = axutil_xml_quote_string(Environment::getEnv(), text_value_<xsl:value-of select="$position"/>, true);
                           if (text_value_<xsl:value-of select="$position"/>_temp)
                           {
                               axutil_stream_write(stream, Environment::getEnv(), text_value_<xsl:value-of select="$position"/>_temp, axutil_strlen(text_value_<xsl:value-of select="$position"/>_temp));
                               AXIS2_FREE(Environment::getEnv()->allocator, text_value_<xsl:value-of select="$position"/>_temp);
                           }
                           else
                           {
                               axutil_stream_write(stream, Environment::getEnv(), text_value_<xsl:value-of select="$position"/>, axutil_strlen(text_value_<xsl:value-of select="$position"/>));
                           }
                           <xsl:if test="$anon or $istype">
                           axutil_stream_write(stream, Environment::getEnv(), end_input_str, end_input_str_len);
                           </xsl:if>
                        </xsl:when>

                        <!-- add axutil_uri_t s -->
                        <xsl:when test="$nativePropertyType='axutil_uri_t*'">
                           text_value_<xsl:value-of select="$position"/> = axutil_uri_to_string(<xsl:value-of select="$propertyInstanceName"/>, Environment::getEnv(), AXIS2_URI_UNP_OMITUSERINFO);
                           <xsl:if test="$anon or $istype">
                           axutil_stream_write(stream, Environment::getEnv(), start_input_str, start_input_str_len);
                           </xsl:if>
                           axutil_stream_write(stream, Environment::getEnv(), text_value_<xsl:value-of select="$position"/>, axutil_strlen(text_value_<xsl:value-of select="$position"/>));
                           <xsl:if test="$anon or $istype">
                           axutil_stream_write(stream, Environment::getEnv(), end_input_str, end_input_str_len);
                           </xsl:if>
                        </xsl:when>

                        <!-- add axutil_duration_t s -->
                        <xsl:when test="$nativePropertyType='axutil_duration_t*'">
                           text_value_<xsl:value-of select="$position"/> = axutil_duration_serialize_duration(<xsl:value-of select="$propertyInstanceName"/>, Environment::getEnv());
                           <xsl:if test="$anon or $istype">
                           axutil_stream_write(stream, Environment::getEnv(), start_input_str, start_input_str_len);
                           </xsl:if>
                           axutil_stream_write(stream, Environment::getEnv(), text_value_<xsl:value-of select="$position"/>, axutil_strlen(text_value_<xsl:value-of select="$position"/>));
                           <xsl:if test="$anon or $istype">
                           axutil_stream_write(stream, Environment::getEnv(), end_input_str, end_input_str_len);
                           </xsl:if>
                        </xsl:when>

                        <!-- add axutil_qname_t s -->
                        <xsl:when test="$nativePropertyType='axutil_qname_t*'">
                           <!-- Handled above -->
                           <xsl:if test="$anon or $istype">
                           axutil_stream_write(stream, Environment::getEnv(), start_input_str, start_input_str_len);
                           </xsl:if>

                           <!-- TODO: Do this in single step -->

                           qname_uri =  axutil_qname_get_uri(<xsl:value-of select="$propertyInstanceName"/>, Environment::getEnv());
                           if(qname_uri)
                           {
                               if(!(qname_prefix = (axis2_char_t*)axutil_hash_get(namespaces, qname_uri, AXIS2_HASH_KEY_STRING)))
                               {

                                   qname_prefix = (axis2_char_t*)AXIS2_MALLOC(Environment::getEnv()->allocator, sizeof (axis2_char_t) * ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT);

                                   sprintf(qname_prefix, "q%d", (*next_ns_index) ++ ); <!-- just different prefix for the special case -->

                                   axutil_hash_set(namespaces, qname_uri, AXIS2_HASH_KEY_STRING, qname_prefix);
                                   axiom_element_declare_namespace_assume_param_ownership(parent_element, Environment::getEnv(), axiom_namespace_create (Environment::getEnv(),
                                            qname_uri,
                                            qname_prefix));
                               }
                           }

                           text_value_<xsl:value-of select="$position"/> = (axis2_char_t*) AXIS2_MALLOC (Environment::getEnv()-> allocator,
                                         sizeof (axis2_char_t) * (ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT +
                                                             axutil_strlen(axutil_qname_get_localpart(<xsl:value-of select="$propertyInstanceName"/>, Environment::getEnv())) + 2));

                           sprintf(text_value_<xsl:value-of select="$position"/>, "%s%s%s",
                                                       qname_uri?qname_prefix:"",
                                                       qname_uri?":":"",
                                                       axutil_qname_get_localpart(<xsl:value-of select="$propertyInstanceName"/>, Environment::getEnv()));

                           axutil_stream_write(stream, Environment::getEnv(), text_value_<xsl:value-of select="$position"/>, axutil_strlen(text_value_<xsl:value-of select="$position"/>));
                           AXIS2_FREE(Environment::getEnv()-> allocator, text_value_<xsl:value-of select="$position"/>);
                           <xsl:if test="$anon or $istype">
                           axutil_stream_write(stream, Environment::getEnv(), end_input_str, end_input_str_len);
                           </xsl:if>
                        </xsl:when>

                          <!-- add bool s -->
                        <xsl:when test="$nativePropertyType='bool'">
                           strcpy(text_value_<xsl:value-of select="$position"/>, (<xsl:value-of select="$propertyInstanceName"/>)?"true":"false");
                           <xsl:if test="$anon or $istype">
                           axutil_stream_write(stream, Environment::getEnv(), start_input_str, start_input_str_len);
                           </xsl:if>
                           axutil_stream_write(stream, Environment::getEnv(), text_value_<xsl:value-of select="$position"/>, axutil_strlen(text_value_<xsl:value-of select="$position"/>));
                           <xsl:if test="$anon or $istype">
                           axutil_stream_write(stream, Environment::getEnv(), end_input_str, end_input_str_len);
                           </xsl:if>
                        </xsl:when>

                        <!-- add nodes -->
                        <xsl:when test="$nativePropertyType='wso2wsf::OMElement*'">
                           <xsl:choose>
                              <xsl:when test="$anon or $istype">
                                std::string s = <xsl:value-of select="$propertyInstanceName"/>->toString();
                                text_value_<xsl:value-of select="$position"/> = (axis2_char_t*)(s.c_str());
                                <xsl:if test="not(@any)">
                                axutil_stream_write(stream, Environment::getEnv(), start_input_str, start_input_str_len);
                                </xsl:if>
                                axutil_stream_write(stream, Environment::getEnv(), text_value_<xsl:value-of select="$position"/>, axutil_strlen(text_value_<xsl:value-of select="$position"/>));
                                <xsl:if test="not(@any)">
                                axutil_stream_write(stream, Environment::getEnv(), end_input_str, end_input_str_len);
                                </xsl:if>
                              </xsl:when>
                              <xsl:otherwise>
                                text_value_<xsl:value-of select="$position"/> = NULL; /* just to bypass the warning unused variable */
                                axiom_node_add_child(parent, Environment::getEnv(), <xsl:value-of select="$propertyInstanceName"/>->getAxiomNode());
                              </xsl:otherwise>
                           </xsl:choose>
                        </xsl:when>

                        <xsl:when test="$nativePropertyType='axutil_date_time_t*'">
                          text_value_<xsl:value-of select="$position"/> = axutil_date_time_serialize_date_time(<xsl:value-of select="$propertyInstanceName"/>, Environment::getEnv());
                           <xsl:if test="$anon or $istype">
                           axutil_stream_write(stream, Environment::getEnv(), start_input_str, start_input_str_len);
                           </xsl:if>
                           axutil_stream_write(stream, Environment::getEnv(), text_value_<xsl:value-of select="$position"/>, axutil_strlen(text_value_<xsl:value-of select="$position"/>));
                           <xsl:if test="$anon or $istype">
                           axutil_stream_write(stream, Environment::getEnv(), end_input_str, end_input_str_len);
                           </xsl:if>
                        </xsl:when>

                        <xsl:when test="$propertyType='axutil_base64_binary_t*'">
                          text_value_<xsl:value-of select="$position"/> =axutil_base64_binary_get_encoded_binary(<xsl:value-of select="$propertyInstanceName"/>, Environment::getEnv());
                           <xsl:if test="$anon or $istype">
                           axutil_stream_write(stream, Environment::getEnv(), start_input_str, start_input_str_len);
                           </xsl:if>
                           axutil_stream_write(stream, Environment::getEnv(), text_value_<xsl:value-of select="$position"/>, axutil_strlen(text_value_<xsl:value-of select="$position"/>));
                           <xsl:if test="$anon or $istype">
                           axutil_stream_write(stream, Environment::getEnv(), end_input_str, end_input_str_len);
                           </xsl:if>
                        </xsl:when>

                        <!--TODO: This should be extended for all the types that should be freed.. -->
                        <xsl:otherwise>
                          /* This is an unknown type or a primitive. handle this manually for unknown type */
                        </xsl:otherwise>
                      </xsl:choose>

                   <!-- close tags arrays -->
                   <xsl:if test="@isarray">
                         }
                     }
                   </xsl:if>
                     <!-- This two should be freed after the loop for array-->
                     AXIS2_FREE(Environment::getEnv()->allocator,start_input_str);
                     AXIS2_FREE(Environment::getEnv()->allocator,end_input_str);
                 } <!-- else for non nillable -->

                 <xsl:if test="$choice">
                 }
                 </xsl:if>

                </xsl:otherwise> <!-- othewise for non attributes -->
              </xsl:choose>
            </xsl:for-each>

            <xsl:if test="not(@type) and not(@simple)"> <!-- So this is the root of the serialization call tree -->
              <xsl:for-each select="property">
                <xsl:if test="position()=1">
                   if(namespaces)
                   {
                       axutil_hash_index_t *hi;
                       void *val;
                       for (hi = axutil_hash_first(namespaces, Environment::getEnv()); hi; hi = axutil_hash_next(Environment::getEnv(), hi))
                       {
                           axutil_hash_this(hi, NULL, NULL, &amp;val);
                           AXIS2_FREE(Environment::getEnv()->allocator, val);
                       }
                       axutil_hash_free(namespaces, Environment::getEnv());
                   }
                </xsl:if>
              </xsl:for-each>
            </xsl:if>

            return parent;
        }


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

              <!-- Just to identiy the pointer to arrays -->
              <!-- Simmilar to native property type except for shor, tint, float, double -->
              <xsl:variable name="PropertyTypeArrayParam"> <!--these are used in arrays to take the native type-->
                 <xsl:choose>
                   <xsl:when test="not(@type)">wso2wsf::OMElement*</xsl:when> <!-- these are anonymous -->
                   <xsl:when test="@type='unsigned short'or @type='std::string' or @type='unsigned char' or @type='unsigned int' or @type='uint64_t' or @type='short' or @type='char' or @type='int' or @type='float' or @type='double' or @type='int64_t' or @type='axis2_unsigned_byte_t' or @type='axis2_byte_t' or @type='bool'">
                    <xsl:value-of select="@type"/><xsl:text>*</xsl:text>
                   </xsl:when>
                   <xsl:otherwise>
                    <xsl:value-of select="@type"/><xsl:if test="@ours"><xsl:text>*</xsl:text></xsl:if>
                   </xsl:otherwise>
                 </xsl:choose>
              </xsl:variable>

              <xsl:variable name="propertyInstanceName"><!--these are used in arrays to take the native type-->
                 <xsl:choose>
                   <xsl:when test="@isarray">element</xsl:when>
                   <xsl:otherwise>property_<xsl:value-of select="$CName"/></xsl:otherwise>
                 </xsl:choose>
              </xsl:variable>

              <xsl:variable name="justPropertyInstanceName"><!--these are used in arrays to take the native type-->
                 <xsl:choose>
                   <xsl:when test="@isarray">element</xsl:when>
                   <xsl:otherwise>property_<xsl:value-of select="$CName"/></xsl:otherwise>
                 </xsl:choose>
              </xsl:variable>
            <xsl:variable name="constValue">
                <xsl:choose>
                   <xsl:when test="@type='std::string' or @type='unsigned short' or @type='uint64_t' or @type='unsigned int' or @type='unsigned char' or @type='short' or @type='char' or @type='int' or @type='float' or @type='double' or @type='int64_t'">const </xsl:when>
                </xsl:choose>
            </xsl:variable>

            /**
             * Getter for <xsl:value-of select="$propertyName"/> by  Property Number <xsl:value-of select="position()"/>
             */
            <xsl:value-of select="$propertyType"/> WSF_CALL
            <xsl:value-of select="$CPPNamespace"/><xsl:value-of select="$axis2_name"/>::getProperty<xsl:value-of select="position()"/>()
            {
                return get<xsl:value-of select="$CName"/>();
            }

            /**
             * getter for <xsl:value-of select="$propertyName"/>.
             */
            <xsl:value-of select="$propertyType"/> WSF_CALL
            <xsl:value-of select="$CPPNamespace"/><xsl:value-of select="$axis2_name"/>::get<xsl:value-of select="$CName"/>()
             {
                return property_<xsl:value-of select="$CName"/>;
             }

            /**
             * setter for <xsl:value-of select="$propertyName"/>
             */
            bool WSF_CALL
            <xsl:value-of select="$CPPNamespace"/><xsl:value-of select="$axis2_name"/>::set<xsl:value-of select="$CName"/>(
                    <xsl:if test="not(@isarray)">
                        <xsl:value-of select="$constValue"/> </xsl:if><xsl:value-of select="$propertyType"/><xsl:text> </xsl:text> arg_<xsl:value-of select="$CName"/>)
             {
                <xsl:if test="@isarray">
                 int size = 0;
                 int i = 0;
                 bool non_nil_exists = false;
                </xsl:if>

                if(isValid<xsl:value-of select="$CName"/> &amp;&amp;
                        arg_<xsl:value-of select="$CName"/> == property_<xsl:value-of select="$CName"/>)
                {
                    <xsl:if test="$choice">
                        currentChoice = "<xsl:value-of select="@nsuri"/>:<xsl:value-of select="$propertyName"/>";
                    </xsl:if>
                    return true;
                }

                <xsl:if test="@isarray">
                 size = arg_<xsl:value-of select="$CName"/>->size();
                 <xsl:if test="not(@unbound)">
                     if (size &gt; <xsl:value-of select="@maxOccurs"/>)
                     {
                         WSF_LOG_ERROR_MSG(Environment::getEnv()->log,WSF_LOG_SI,"<xsl:value-of select="$propertyName"/> has exceed the maxOccurs(<xsl:value-of select="@maxOccurs"/>)");
                         return false;
                     }
                 </xsl:if>
                 if (size &lt; <xsl:value-of select="@minOccurs"/>)
                 {
                     WSF_LOG_ERROR_MSG( Environment::getEnv()->log,WSF_LOG_SI,"<xsl:value-of select="$propertyName"/> has less than minOccurs(<xsl:value-of select="@minOccurs"/>)");
                     return false;
                 }
                 for(i = 0; i &lt; size; i ++ )
                 {
                     if(NULL != (*arg_<xsl:value-of select="$CName"/>)[i])
                     {
                         non_nil_exists = true;
                         break;
                     }
                 }

                 <xsl:if test ="not(@nillabe) and not(@minOccurs='0')">
                    if(!non_nil_exists)
                    {
                        WSF_LOG_ERROR_MSG( Environment::getEnv()->log,WSF_LOG_SI,"All the elements in the array of <xsl:value-of select="$propertyName"/> is being set to NULL, but it is not a nullable or minOccurs=0 element");
                        return false;
                    }
                 </xsl:if>
                </xsl:if> <!-- close for the isarray -->

                <xsl:if test="not(@nillable) and not(@minOccurs='0') and (@ours or not($propertyType='unsigned char' or $propertyType='unsigned int' or $propertyType='unsigned short' or $propertyType='uint64_t' or $propertyType='char' or $propertyType='int' or $propertyType='short' or $propertyType='float' or $propertyType='axis2_unsigned_byte_t' or $propertyType='axis2_byte_t' or $propertyType='double' or $propertyType='int64_t' or $propertyType='bool'))">
                  <xsl:choose>
                      <xsl:when test="$propertyType ='std::string'">
                  if(arg_<xsl:value-of select="$CName"/>.empty())
                       </xsl:when>
                       <xsl:otherwise>
                  if(NULL == arg_<xsl:value-of select="$CName"/>)
                       </xsl:otherwise>
                  </xsl:choose>
                  {
                      WSF_LOG_ERROR_MSG( Environment::getEnv()->log,WSF_LOG_SI,"<xsl:value-of select="$propertyName"/> is being set to NULL, but it is not a nullable element");
                      return AXIS2_FAILURE;
                  }
                </xsl:if>

                <!-- first reset whatever already in there -->
                reset<xsl:value-of select="$CName"/>();

                <xsl:if test="(@ours or not($propertyType='std::string' or $propertyType='unsigned char' or $propertyType='unsigned int' or $propertyType='unsigned short' or $propertyType='uint64_t' or $propertyType='char' or $propertyType='int' or $propertyType='short' or $propertyType='float' or $propertyType='axis2_unsigned_byte_t' or $propertyType='axis2_byte_t' or $propertyType='double' or $propertyType='int64_t' or $propertyType='bool'))">
                    <xsl:choose>
                        <xsl:when test="@propertyType = 'std::string'">
                    if(arg_<xsl:value-of select="$CName"/>->empty())
                         </xsl:when>
                         <xsl:otherwise>
                    if(NULL == arg_<xsl:value-of select="$CName"/>)
                         </xsl:otherwise>
                    </xsl:choose>
                {
                    /* We are already done */
                    return true;
                }
                </xsl:if>

                <xsl:choose>
                    <xsl:when test="@isarray">
                        property_<xsl:value-of select="$CName"/> = arg_<xsl:value-of select="$CName"/>;
                        if(non_nil_exists)
                        {
                            isValid<xsl:value-of select="$CName"/> = true;
                        }
                        <!-- else is_valid_* = false is set by the above reset function -->
                    </xsl:when>
                    <xsl:when test="@type='std::string' and not(@isarray)">
                        property_<xsl:value-of select="$CName"/> = std::string(arg_<xsl:value-of select="$CName"/>.c_str());
                        isValid<xsl:value-of select="$CName"/> = true;
                    </xsl:when>
                    <xsl:otherwise>
                        property_<xsl:value-of select="$CName"/> = arg_<xsl:value-of select="$CName"/>;
                        isValid<xsl:value-of select="$CName"/> = true;
                    </xsl:otherwise>
                </xsl:choose>
                <xsl:if test="$choice">
                    currentChoice = "<xsl:value-of select="@nsuri"/>:<xsl:value-of select="$propertyName"/>";
                </xsl:if>
                return true;
             }

            <xsl:if test="$isEnum=1">
               <xsl:variable name="enum">ADB<xsl:value-of select="$CName"/>Enum</xsl:variable>
             /**
             * specialized enum getter for <xsl:value-of select="$CName"/>.
             */
             <xsl:value-of select="$enum"/> WSF_CALL
             <xsl:value-of select="$CPPNamespace"/><xsl:value-of select="$axis2_name"/>::get<xsl:value-of select="$CName"/>Enum()
             {

                <xsl:for-each select="enumFacet">
                 if (axutil_strcmp(property_<xsl:value-of select="$CName"/>.c_str(), "<xsl:value-of select="@value"/>") == 0)
                    return <xsl:value-of select="parent::node()/@caps-cname"/>_<xsl:value-of select="@id"/>;
             </xsl:for-each>
             
                 /* Error: none of the strings matched; invalid enum value */
                 return (<xsl:value-of select="$enum"/>)-1;
             }
             
             
             /**
             * specialized enum setter for <xsl:value-of select="$propertyName"/>.
             */
             bool WSF_CALL
            <xsl:value-of select="$CPPNamespace"/><xsl:value-of select="$axis2_name"/>::set<xsl:value-of select="$CName"/>Enum(<xsl:value-of select="$constValue"/><xsl:value-of select="$enum"/><xsl:text> </xsl:text> arg_<xsl:value-of select="$CName"/>)
             {
                <xsl:if test="@isarray">
                 int size = 0;
                 int i = 0;
                 bool non_nil_exists = false;
                </xsl:if>

                <!-- first reset whatever already in there -->
                reset<xsl:value-of select="$CName"/>();

                   
                   switch (arg_<xsl:value-of select="$CName"/>)
                   {
                     <xsl:for-each select="enumFacet">
                       case <xsl:value-of select="parent::node()/@caps-cname"/>_<xsl:value-of select="@id"/> :
                            property_<xsl:value-of select="$CName"/> = (axis2_char_t *)axutil_strdup(Environment::getEnv(), "<xsl:value-of select="@value"/>");
                          break;
                     </xsl:for-each>
                     
                       default:
                          isValid<xsl:value-of select="$CName"/> = false;
                          property_<xsl:value-of select="$CName"/> = "";
                          WSF_LOG_ERROR_MSG( Environment::getEnv()->log,WSF_LOG_SI,"Error setting <xsl:value-of select="$propertyName"/>: undefined enum value");
                          return false;
                   }
                
                   if(property_<xsl:value-of select="$CName"/>.empty())
                   {
                       return AXIS2_FAILURE;
                   }
                     isValid<xsl:value-of select="$CName"/> = true;
                        
                <xsl:if test="$choice">
                    currentChoice = "<xsl:value-of select="@nsuri"/>:<xsl:value-of select="$propertyName"/>";
                </xsl:if>
                return true;
             }


             /**
             * specialized enum constructor for <xsl:value-of select="$propertyName"/>.
             */
            <xsl:value-of select="$CPPNamespace"/><xsl:value-of select="$axis2_name"/>::<xsl:value-of select="$axis2_name"/>(<xsl:value-of select="$constValue"/><xsl:value-of select="$enum"/><xsl:text> </xsl:text> arg_<xsl:value-of select="$CName"/>)
             {             <xsl:if test="not($istype)">
                   qname = NULL;
             </xsl:if>


           <xsl:if test="not($istype)">
             <xsl:choose>
               <xsl:when test="$nsuri and $nsuri != ''">
                 qname =  axutil_qname_create (Environment::getEnv(),
                       "<xsl:value-of select="$originalName"/>",
                       "<xsl:value-of select="$nsuri"/>",
                       NULL);
               </xsl:when>
               <xsl:otherwise>
                qname =  axutil_qname_create (Environment::getEnv(),"<xsl:value-of select="$originalName"/>", NULL, NULL);
               </xsl:otherwise>
             </xsl:choose>
           </xsl:if>

            isValid<xsl:value-of select="$CName"/>  = set<xsl:value-of select="$CName"/>Enum( arg_<xsl:value-of select="$CName"/> );
            }

            </xsl:if>

            <xsl:if test="@isarray">
            /**
             * Get ith element of <xsl:value-of select="$propertyName"/>.
             */
            <xsl:value-of select="$nativePropertyType"/> WSF_CALL
            <xsl:value-of select="$CPPNamespace"/><xsl:value-of select="$axis2_name"/>::get<xsl:value-of select="$CName"/>At(int i)
            {
                <xsl:value-of select="$PropertyTypeArrayParam"/> ret_val;
                if(property_<xsl:value-of select="$CName"/> == NULL)
                {
                    return (<xsl:value-of select="$nativePropertyType"/>)0;
                }
                ret_val =   (*property_<xsl:value-of select="$CName"/>)[i];
                <xsl:choose>
                  <xsl:when test="@type='std::string' or @type='unsigned short' or @type='unsigned char' or @type='unsigned int' or @type='uint64_t' or @type='short' or @type='char' or @type='int' or @type='float' or @type='double' or @type='int64_t' or @type='axis2_unsigned_byte_t' or @type='axis2_byte_t' or @type='bool'">
                    if(ret_val)
                    {
                        return *ret_val;
                    }
                    return (<xsl:value-of select="$nativePropertyType"/>)0;
                  </xsl:when>
                  <xsl:otherwise>
                    return ret_val;
                  </xsl:otherwise>
                </xsl:choose>
            }

            /**
             * Set the ith element of <xsl:value-of select="$propertyName"/>.
             */
           bool WSF_CALL
            <xsl:value-of select="$CPPNamespace"/><xsl:value-of select="$axis2_name"/>::set<xsl:value-of select="$CName"/>At(int i,
                    <xsl:value-of select="$constValue"/><xsl:value-of select="$nativePropertyType"/><xsl:text> arg_</xsl:text><xsl:value-of select="$CName"/>)
            {
                 <xsl:value-of select="$PropertyTypeArrayParam"/> element;
                int size = 0;

                int non_nil_count;
                bool non_nil_exists = false;

                 <xsl:if test="@type='unsigned short' or @type='unsigned char' or @type='unsigned int' or @type='uint64_t' or @type='short' or @type='char' or @type='int' or @type='float' or @type='double' or @type='int64_t' or @type='axis2_bool_t' or @type='axis2_unsigned_byte_t' or  @type='axis2_byte_t'">
                   <xsl:value-of select="$PropertyTypeArrayParam"/><xsl:text> ptr_param_</xsl:text><xsl:value-of select="$CName"/>;
                </xsl:if>

                if( isValid<xsl:value-of select="$CName"/> &amp;&amp;
                    property_<xsl:value-of select="$CName"/> &amp;&amp;
                  <xsl:choose>
                  <xsl:when test="@type='unsigned short' or @type='std::string' or @type='unsigned char' or @type='unsigned int' or @type='uint64_t' or @type='short' or @type='char' or @type='int' or @type='float' or @type='double' or @type='int64_t' or @type='axis2_bool_t' or @type='axis2_unsigned_byte_t' or @type='axis2_byte_t'">
                    arg_<xsl:value-of select="$CName"/> == *((*property_<xsl:value-of select="$CName"/>)[i]))
                  </xsl:when>
                  <xsl:otherwise>
                    arg_<xsl:value-of select="$CName"/> == (*property_<xsl:value-of select="$CName"/>)[i])
                  </xsl:otherwise>
                </xsl:choose>
                 {
                    <xsl:if test="$choice">
                        currentChoice = "<xsl:value-of select="@nsuri"/>:<xsl:value-of select="$propertyName"/>";
                    </xsl:if>
                    return AXIS2_SUCCESS; 
                }

                   <xsl:choose>
                    <xsl:when test="@type='unsigned short' or 'std::string' or @type='unsigned char' or @type='unsigned int' or @type='uint64_t' or @type='short' or @type='char' or @type='int' or @type='float' or @type='double' or @type='int64_t' or @type='bool' or @type='axis2_unsigned_byte_t' or @type='axis2_byte_t'">
                     non_nil_exists = true;
                  </xsl:when>
                  <xsl:otherwise>
                    if(NULL != arg_<xsl:value-of select="$CName"/>)
                    {
                        non_nil_exists = true;
                    }
                    else {
                        if(property_<xsl:value-of select="$CName"/> != NULL)
                        {
                            size = property_<xsl:value-of select="$CName"/>->size();
                            for(int j = 0, non_nil_count = 0; j &lt; size; j ++ )
                            {
                                if(i == j) continue; <!-- should not count the ith element -->
                                if(NULL != (*property_<xsl:value-of select="$CName"/>)[i])
                                {
                                    non_nil_count++;
                                    non_nil_exists = true;
                                    if(non_nil_count >= <xsl:value-of select="@minOccurs"/>)
                                    {
                                        break;
                                    }
                                }
                            }

                        <xsl:if test="not(@nillabe) and not(@minOccurs='0')"> <!-- if minOccurs=0 then no need to have error messages -->
                            if( non_nil_count &lt; <xsl:value-of select="@minOccurs"/>)
                            {
                                   WSF_LOG_ERROR_MSG( Environment::getEnv()->log,WSF_LOG_SI,"Size of the array of <xsl:value-of select="$propertyName"/> is being set to be smaller than the specificed number of minOccurs(<xsl:value-of select="@minOccurs"/>)");
                                   return AXIS2_FAILURE;
                            }
                        </xsl:if>
                        }
                    }
                  </xsl:otherwise>
                </xsl:choose>

                <xsl:if test ="not(@nillabe) and not(@minOccurs='0')">
                   if(!non_nil_exists)
                   {
                       WSF_LOG_ERROR_MSG(Environment::getEnv()->log, WSF_LOG_SI, "All the elements in the array of <xsl:value-of select="$propertyName"/> is being set to NULL, but it is not a nullable or minOccurs=0 element");
                       return AXIS2_FAILURE;
                   }
                </xsl:if>

                if(property_<xsl:value-of select="$CName"/> == NULL)
                {
                    property_<xsl:value-of select="$CName"/> = new std::vector&lt;<xsl:value-of select="@type"/><xsl:if test="@ours or @type='std::string' or @type='unsigned char' or @type='unsigned short' or @type='uint64_t' or @type='unsigned int' or @type='short' or @type='char' or @type='int' or @type='float' or @type='double' or @type='int64_t'"><xsl:text>*</xsl:text></xsl:if>&gt;();
                }
                else{
                /* check whether there already exist an element */
                element = (*property_<xsl:value-of select="$CName"/>)[i];
                }

                <xsl:choose>
                    <xsl:when test="@type='unsigned short' or @type='unsigned char' or @type='std::string' or @type='unsigned int' or @type='uint64_t' or @type='short' or @type='char' or @type='int' or @type='float' or @type='double' or @type='int64_t' or @type='bool' or @type='axis2_unsigned_byte_t' or @type='axis2_byte_t'">

                    </xsl:when>
                    <xsl:otherwise>
                        if(NULL != element)
                        {
                          <!-- Some repeated code -->
                          <!-- For all inside the choose, propertyInstanceName = element -->
                          <xsl:choose>
                             <xsl:when test="@ours">
                                delete <xsl:value-of select="$propertyInstanceName"/>;
                             </xsl:when>


                             <!-- free nodes -->
                             <xsl:when test="$nativePropertyType='wso2wsf::OMElement*'">
                                 // TODO Clear om Element
                                 delete <xsl:value-of select="$propertyInstanceName"/>;
                             </xsl:when>

                             <xsl:when test="$nativePropertyType='axutil_qname_t*'">
                              axutil_qname_free(<xsl:value-of select="$propertyInstanceName"/>, Environment::getEnv());
                             </xsl:when>

                             <xsl:when test="$nativePropertyType='axutil_uri_t*'">
                              axutil_uri_free(<xsl:value-of select="$propertyInstanceName"/>, Environment::getEnv());
                             </xsl:when>

                             <xsl:when test="$nativePropertyType='axutil_duration_t*'">
                              axutil_duration_free(<xsl:value-of select="$propertyInstanceName"/>, Environment::getEnv());
                             </xsl:when>

                             <xsl:when test="$nativePropertyType='axutil_date_time_t*'">
                              axutil_date_time_free(<xsl:value-of select="$propertyInstanceName"/>, Environment::getEnv());
                             </xsl:when>

                             <xsl:when test="$propertyType='axutil_base64_binary_t*'">
                              axutil_base64_binary_free (<xsl:value-of select="$propertyInstanceName"/>, Environment::getEnv());
                             </xsl:when>
                               <xsl:when test="$propertyType='axutil_duration_t*'">
                              axutil_duration_free (<xsl:value-of select="$propertyInstanceName"/>, Environment::getEnv());
                             </xsl:when>

                             <!--TODO: This should be extended for all the types that should be freed.. -->
                             <xsl:otherwise>
                               /* This is an unknown type or a primitive. Please free this manually<xsl:value-of select="@type"/>*/
                             </xsl:otherwise>
                          </xsl:choose>
                        }
                        
                    </xsl:otherwise>
                </xsl:choose>

                <xsl:if test ="@nillabe or @minOccurs='0'">
                    if(!non_nil_exists)
                    {
                        <!-- No need to worry further -->
                        isValid<xsl:value-of select="$CName"/> = true;
                        (*property_<xsl:value-of select="$CName"/>)[i]= NULL;
                        <xsl:if test="$choice">
                            <!-- Should not check the current_choice here, since this is a setting to null -->
                        </xsl:if>
                        return AXIS2_SUCCESS;
                    }
                </xsl:if>
                <xsl:choose>
                  <xsl:when test="@type='unsigned short' or @type='unsigned char' or @type='unsigned int' or @type='uint64_t' or @type='short' or @type='char' or @type='int' or @type='float' or @type='double' or @type='int64_t' or @type='axis2_bool_t' or @type='axis2_unsigned_byte_t' or @type='axis2_byte_t'">
                   <xsl:text>ptr_param_</xsl:text><xsl:value-of select="$CName"/> =  (<xsl:value-of select="$PropertyTypeArrayParam"/>)
                            AXIS2_MALLOC(Environment::getEnv()->allocator, sizeof(<xsl:value-of select="@type"/>));
                   <xsl:text>*ptr_param_</xsl:text><xsl:value-of select="$CName"/> = <xsl:text>arg_</xsl:text><xsl:value-of select="$CName"/>;
                    (*property_<xsl:value-of select="$CName"/>)[i] = <xsl:text>ptr_param_</xsl:text><xsl:value-of select="$CName"/>;
                  </xsl:when>
                  <xsl:when test="@type='std::string'">
                    (*property_<xsl:value-of select="$CName"/>)[i]= new string(arg_<xsl:value-of select="$CName"/>.c_str());
                  </xsl:when>
                  <xsl:otherwise>
                    (*property_<xsl:value-of select="$CName"/>)[i] = arg_<xsl:value-of select="$CName"/>;
                  </xsl:otherwise>
                </xsl:choose>

               isValid<xsl:value-of select="$CName"/> = true;
                <xsl:if test="$choice">
                        currentChoice = "<xsl:value-of select="@nsuri"/>:<xsl:value-of select="$propertyName"/>";
                </xsl:if>
                return AXIS2_SUCCESS;
            }

            /**
             * Add to <xsl:value-of select="$propertyName"/>.
             */
            bool WSF_CALL
            <xsl:value-of select="$CPPNamespace"/><xsl:value-of select="$axis2_name"/>::add<xsl:value-of select="$CName"/>(
                    <xsl:value-of select="$constValue"/><xsl:value-of select="$nativePropertyType"/><xsl:text> arg_</xsl:text> <xsl:value-of select="$CName"/>)
             {

                <xsl:if test="@type='unsigned short' or @type='unsigned char' or @type='unsigned int' or @type='uint64_t' or @type='short' or @type='char' or @type='int' or @type='float' or @type='double' or @type='int64_t' or @type='axis2_bool_t' or @type='axis2_unsigned_byte_t' or @type='axis2_byte_t'">
                   <xsl:value-of select="$PropertyTypeArrayParam"/><xsl:text> ptr_param_</xsl:text><xsl:value-of select="$CName"/>;
                </xsl:if>
               <xsl:choose>
                  <xsl:when test="@type='unsigned short' or @type='unsigned char' or @type='unsigned int' or @type='uint64_t' or @type='short' or @type='char' or @type='int' or @type='float' or @type='double' or @type='int64_t' or @type='bool' or @type='axis2_unsigned_byte_t' or @type='axis2_byte_t'">
                  </xsl:when>
                  <xsl:otherwise>
                    if(<xsl:choose><xsl:when test="@type='std::string'">
                      arg_<xsl:value-of select="$CName"/>.empty()
                       </xsl:when>
                       <xsl:otherwise> NULL == arg_<xsl:value-of select="$CName"/></xsl:otherwise>
                  </xsl:choose>
                     )
                    {
                      <xsl:choose>
                        <xsl:when test ="not(@nillabe) and not(@minOccurs='0')">
                           WSF_LOG_ERROR_MSG(Environment::getEnv()->log, WSF_LOG_SI, "All the elements in the array of <xsl:value-of select="$propertyName"/> is being set to NULL, but it is not a nullable or minOccurs=0 element");
                           return false;
                        </xsl:when>
                        <xsl:otherwise>
                           return true; <!-- just no need to waist more time -->
                        </xsl:otherwise>
                      </xsl:choose>
                    }
                  </xsl:otherwise>
                </xsl:choose>

                if(property_<xsl:value-of select="$CName"/> == NULL)
                {
                    property_<xsl:value-of select="$CName"/> = new std::vector&lt;<xsl:value-of select="@type "/><xsl:if test="@ours or @type='std::string' or @type='unsigned char' or @type='unsigned int' or @type='uint64_t' or @type='short' or @type='char' or @type='int' or @type='float' or @type='double' or @type='int64_t' or @type='axis2_bool_t'  or @type='axis2_byte_t'"><xsl:text>*</xsl:text></xsl:if>&gt;();
                }
              <xsl:choose>
              <xsl:when test="@type='unsigned short' or @type='unsigned char' or @type='unsigned int' or @type='uint64_t' or @type='short' or @type='char' or @type='int' or @type='float' or @type='double' or @type='int64_t' or @type='axis2_bool_t' or @type='axis2_unsigned_byte_t' or @type='axis2_byte_t'">
               <xsl:text>ptr_param_</xsl:text><xsl:value-of select="$CName"/> =  (<xsl:value-of select="$PropertyTypeArrayParam"/>)
                        AXIS2_MALLOC(Environment::getEnv()->allocator, sizeof(<xsl:value-of select="@type"/>));
               <xsl:text>*ptr_param_</xsl:text><xsl:value-of select="$CName"/> = <xsl:text>arg_</xsl:text><xsl:value-of select="$CName"/>;
               property_<xsl:value-of select="$CName"/>->push_back(<xsl:text>ptr_param_</xsl:text><xsl:value-of select="$CName"/>);
              </xsl:when>
              <xsl:when test="@type='std::string'">
               property_<xsl:value-of select="$CName"/>->push_back(new string(<xsl:text>arg_</xsl:text><xsl:value-of select="$CName"/>.c_str()));
              </xsl:when>
              <xsl:otherwise>
               property_<xsl:value-of select="$CName"/>->push_back(<xsl:text>arg_</xsl:text><xsl:value-of select="$CName"/>);
              </xsl:otherwise>
                </xsl:choose>
                isValid<xsl:value-of select="$CName"/> = true;
                return true;
             }

            /**
             * Get the size of the <xsl:value-of select="$propertyName"/> array.
             */
            int WSF_CALL
            <xsl:value-of select="$CPPNamespace"/><xsl:value-of select="$axis2_name"/>::sizeof<xsl:value-of select="$CName"/>()
            {

                if(property_<xsl:value-of select="$CName"/> == NULL)
                {
                    return 0;
                }
                return property_<xsl:value-of select="$CName"/>->size();
            }

            /**
             * remove the ith element, same as set_nil_at.
             */
            bool WSF_CALL
            <xsl:value-of select="$CPPNamespace"/><xsl:value-of select="$axis2_name"/>::remove<xsl:value-of select="$CName"/>At(int i)
            {
                return set<xsl:value-of select="$CName"/>NilAt(i);
            }

           </xsl:if> <!-- closes the isarray -->

           /**
            * resetter for <xsl:value-of select="$propertyName"/>
            */
           bool WSF_CALL
           <xsl:value-of select="$CPPNamespace"/><xsl:value-of select="$axis2_name"/>::reset<xsl:value-of select="$CName"/>()
           {
               int i = 0;
               int count = 0;


               <xsl:if test="@isarray and not($nativePropertyType='std::string' or $nativePropertyType='unsigned short' or $nativePropertyType='unsigned char' or $nativePropertyType='unsigned int' or $nativePropertyType='uint64_t' or $nativePropertyType='short' or $nativePropertyType='axis2_unsigned_byte_t' or $nativePropertyType='axis2_byte_t' or $nativePropertyType='bool' or $nativePropertyType='char' or $nativePropertyType='int' or $nativePropertyType='float' or $nativePropertyType='double' or $nativePropertyType='int64_t') or @ours or @type='axutil_qname_t*' or @type='axutil_duration_t*' or @type='axutil_uri_t*' or @type='axutil_date_time_t*' or @type='axutil_base64_binary_t*'">
                <!-- handles arrays -->
                <xsl:if test="@isarray">
                if (property_<xsl:value-of select="$CName"/> != NULL)
                {
                  std::vector&lt;<xsl:value-of select="@type"/><xsl:if test="@ours or @type='std::string' or @type='unsigned char' or @type='unsigned short' or @type='uint64_t' or @type='unsigned int' or @type='short' or @type='char' or @type='int' or @type='float' or @type='double' or @type='int64_t'"><xsl:text>*</xsl:text></xsl:if>&gt;::iterator it =  property_<xsl:value-of select="$CName"/>->begin();
                  for( ; it &lt;  property_<xsl:value-of select="$CName"/>->end() ; ++it)
                  {
                     <xsl:value-of select="$PropertyTypeArrayParam"/> element = *it;
                </xsl:if>
            
                <!-- the following element can be inside array or exist independently-->

                if(<xsl:value-of select="$justPropertyInstanceName"/> != NULL)
                {
                   <!-- how to free all the ours things -->
                   <xsl:choose>
                     <xsl:when test="@ours">
                         delete  <xsl:value-of select="$propertyInstanceName"/>;
                     </xsl:when>

                     <xsl:when test="$nativePropertyType='unsigned short' or $nativePropertyType='unsigned char' or $nativePropertyType='unsigned int' or $nativePropertyType='uint64_t' or $nativePropertyType='short' or $nativePropertyType='axis2_unsigned_byte_t' or $nativePropertyType='axis2_byte_t' or $nativePropertyType='bool' or $nativePropertyType='char' or $nativePropertyType='int' or $nativePropertyType='float' or $nativePropertyType='double' or $nativePropertyType='int64_t'">
                       <xsl:if test="@isarray">
                        <!-- free ints, int64_ts, float in array-->
                        /* we keep primtives as pointers in arrasy, so need to free them */
                        AXIS2_FREE(Environment::getEnv()-> allocator, element);
                       </xsl:if>
                     </xsl:when>

                     <xsl:when test="$nativePropertyType='std::string'">
                         delete <xsl:value-of select="$propertyInstanceName"/>;
                     </xsl:when>
                     <!-- free nodes -->
                     <xsl:when test="$nativePropertyType='wso2wsf::OMElement*'">
                        delete <xsl:value-of select="$propertyInstanceName"/>;
                         <xsl:value-of select="$justPropertyInstanceName"/> = NULL;
                     </xsl:when>

                     <xsl:when test="$nativePropertyType='axutil_qname_t*'">
                      axutil_qname_free(<xsl:value-of select="$propertyInstanceName"/>, Environment::getEnv());
                         <xsl:value-of select="$justPropertyInstanceName"/> = NULL;
                     </xsl:when>

                     <xsl:when test="$nativePropertyType='axutil_uri_t*'">
                      axutil_uri_free(<xsl:value-of select="$propertyInstanceName"/>, Environment::getEnv());
                         <xsl:value-of select="$justPropertyInstanceName"/> = NULL;
                     </xsl:when>

                     <xsl:when test="$nativePropertyType='axutil_duration_t*'">
                      axutil_duration_free(<xsl:value-of select="$propertyInstanceName"/>, Environment::getEnv());
                         <xsl:value-of select="$justPropertyInstanceName"/> = NULL;
                     </xsl:when>

                     <xsl:when test="$nativePropertyType='axutil_date_time_t*'">
                      axutil_date_time_free(<xsl:value-of select="$propertyInstanceName"/>, Environment::getEnv());
                         <xsl:value-of select="$justPropertyInstanceName"/> = NULL;
                     </xsl:when>

                     <xsl:when test="$propertyType='axutil_base64_binary_t*'">
                         axutil_base64_binary_free (<xsl:value-of select="$propertyInstanceName"/>, Environment::getEnv());
                         <xsl:value-of select="$justPropertyInstanceName"/> = NULL;
                     </xsl:when>
                       <xsl:when test="$propertyType='axutil_duration_t*'">
                      axutil_duration_free (<xsl:value-of select="$propertyInstanceName"/>, Environment::getEnv());
                       <xsl:value-of select="$justPropertyInstanceName"/> = NULL;
                     </xsl:when>

                     <!--TODO: This should be extended for all the types that should be freed.. -->
                     <xsl:otherwise>
                       /* This is an unknown type or a primitive. Please free this manually<xsl:value-of select="@type"/> */
                     </xsl:otherwise>
                   </xsl:choose>

                   }

                <!--/xsl:if-->
                <!-- close tags arrays -->
                <xsl:if test="@isarray">
               }

             }
                </xsl:if>
               </xsl:if> <!--close for test of primitive types -->
                <xsl:if test="@isarray">
                    if(NULL != property_<xsl:value-of select="$CName"/>)
                 delete property_<xsl:value-of select="$CName"/>;
                </xsl:if>
               isValid<xsl:value-of select="$CName"/> = false; 
               return true;
           }

           /**
            * Check whether <xsl:value-of select="$propertyName"/> is nill
            */
           bool WSF_CALL
           <xsl:value-of select="$CPPNamespace"/><xsl:value-of select="$axis2_name"/>::is<xsl:value-of select="$CName"/>Nil()
           {
               return !isValid<xsl:value-of select="$CName"/>;
           }

           /**
            * Set <xsl:value-of select="$propertyName"/> to nill (currently the same as reset)
            */
           bool WSF_CALL
           <xsl:value-of select="$CPPNamespace"/><xsl:value-of select="$axis2_name"/>::set<xsl:value-of select="$CName"/>Nil()
           {
               return reset<xsl:value-of select="$CName"/>();
           }

           <xsl:if test="@isarray">
           /**
            * Check whether <xsl:value-of select="$propertyName"/> is nill at i
            */
           bool WSF_CALL
           <xsl:value-of select="$CPPNamespace"/><xsl:value-of select="$axis2_name"/>::is<xsl:value-of select="$CName"/>NilAt(int i)
           {
               return (isValid<xsl:value-of select="$CName"/> == false ||
                       NULL == property_<xsl:value-of select="$CName"/> ||
                     NULL == (*property_<xsl:value-of select="$CName"/>)[i]);
            }

           /**
            * Set <xsl:value-of select="$propertyName"/> to nil at i
            */
           bool WSF_CALL
           <xsl:value-of select="$CPPNamespace"/><xsl:value-of select="$axis2_name"/>::set<xsl:value-of select="$CName"/>NilAt(int i)
           {
                int size = 0;
                int j;
                bool non_nil_exists = false;

                int k = 0;

                if(property_<xsl:value-of select="$CName"/> == NULL ||
                            isValid<xsl:value-of select="$CName"/> == false)
                {
                    <!-- just assume it s null -->
                    non_nil_exists = false;
                }
                else
                {
                    size = property_<xsl:value-of select="$CName"/>->size();
                    for(j = 0, k = 0; j &lt; size; j ++ )
                    {
                        if(i == j) continue; <!-- should not count the ith element -->
                        if(NULL != (*property_<xsl:value-of select="$CName"/>)[i])
                        {
                            k++;
                            non_nil_exists = true;
                            if( k >= <xsl:value-of select="@minOccurs"/>)
                            {
                                break;
                            }
                        }
                    }
                }
                <xsl:if test ="not(@nillabe) and not(@minOccurs='0')">
                   if(!non_nil_exists)
                   {
                       WSF_LOG_ERROR_MSG(Environment::getEnv()->log, WSF_LOG_SI, "All the elements in the array of <xsl:value-of select="$propertyName"/> is being set to NULL, but it is not a nullable or minOccurs=0 element");
                       return AXIS2_FAILURE;
                   }
                </xsl:if>

                if( k &lt; <xsl:value-of select="@minOccurs"/>)
                {
                       WSF_LOG_ERROR_MSG(Environment::getEnv()->log, WSF_LOG_SI, "Size of the array of <xsl:value-of select="$propertyName"/> is beinng set to be smaller than the specificed number of minOccurs(<xsl:value-of select="@minOccurs"/>)");
                       return AXIS2_FAILURE;
                }
 
                if(property_<xsl:value-of select="$CName"/> == NULL)
                {
                    isValid<xsl:value-of select="$CName"/> = false;
                    <!-- just assume it s null -->
                    return true;
                }
                 <xsl:if test="not ($nativePropertyType='std::string' or $nativePropertyType='unsigned short' or $nativePropertyType='unsigned char' or $nativePropertyType='unsigned int' or $nativePropertyType='uint64_t' or $nativePropertyType='short' or $nativePropertyType='axis2_unsigned_byte_t' or $nativePropertyType='axis2_byte_t' or $nativePropertyType='bool' or $nativePropertyType='char' or $nativePropertyType='int' or $nativePropertyType='float' or $nativePropertyType='double' or $nativePropertyType='int64_t')">
                 /* check whether there already exist an element */
                 <xsl:value-of select="$nativePropertyType"/> element = (*property_<xsl:value-of select="$CName"/>)[i];
                if(NULL != element)
                {
                  <!-- Some repeated code -->
                  <!-- For all inside the choose, propertyInstanceName = element -->
                  <xsl:choose>
                     <xsl:when test="@ours">
                        delete <xsl:value-of select="$propertyInstanceName"/>;
                     </xsl:when>
            

            
                     <!-- free axis2_char_t s -->
                     <!-- free nodes -->
                     <xsl:when test="$nativePropertyType='wso2wsf::OMElement*'">
                     delete <xsl:value-of select="$propertyInstanceName"/>;
                     </xsl:when>
            
                     <xsl:when test="$nativePropertyType='axutil_qname_t*'">
                      axutil_qname_free(<xsl:value-of select="$propertyInstanceName"/>, Environment::getEnv());
                     </xsl:when>
            
                     <xsl:when test="$nativePropertyType='axutil_uri_t*'">
                      axutil_uri_free(<xsl:value-of select="$propertyInstanceName"/>, Environment::getEnv());
                     </xsl:when>
            
                     <xsl:when test="$nativePropertyType='axutil_duration_t*'">
                      axutil_duration_free(<xsl:value-of select="$propertyInstanceName"/>, Environment::getEnv());
                     </xsl:when>
            
                     <xsl:when test="$nativePropertyType='axutil_date_time_t*'">
                      axutil_date_time_free(<xsl:value-of select="$propertyInstanceName"/>, Environment::getEnv());
                     </xsl:when>
            
                     <xsl:when test="$propertyType='axutil_base64_binary_t*'">
                      axutil_base64_binary_free (<xsl:value-of select="$propertyInstanceName"/>, Environment::getEnv());
                     </xsl:when>
                       <xsl:when test="$propertyType='axutil_duration_t*'">
                      axutil_duration_free (<xsl:value-of select="$propertyInstanceName"/>, Environment::getEnv());
                     </xsl:when>
            
                     <!--TODO: This should be extended for all the types that should be freed.. -->
                     <xsl:otherwise>
                       /* This is an unknown type or a primitive. Please free this manually <xsl:value-of select="@type"/>*/
                     </xsl:otherwise>
                  </xsl:choose>
                 }
                 </xsl:if>


               <xsl:if test ="@nillabe or @minOccurs='0'">
                    if(!non_nil_exists)
                    {
                        <!-- No need to worry further -->
                        isValid<xsl:value-of select="$CName"/> = false;
                        (*property_<xsl:value-of select="$CName"/>)[i] = NULL;
                        return AXIS2_SUCCESS;
                    }
                </xsl:if>

                <!-- for all the other case just set the ith element NULL -->
                (*property_<xsl:value-of select="$CName"/>)[i] = NULL;
                
                return AXIS2_SUCCESS;

           }

           </xsl:if> <!-- end of checkiing is array -->
        </xsl:for-each>

        <!-- The section covers the list types, this almost rewrite above setters/getters -->
        <xsl:for-each select="itemtype">
            <xsl:variable name="propertyType">std::vector&lt;<xsl:value-of select="@type"/><xsl:if test="@ours or @type='std::string' or @type='unsigned char' or @type='unsigned short' or @type='uint64_t' or @type='unsigned int' or @type='short' or @type='char' or @type='int' or @type='float' or @type='double' or @type='int64_t'"><xsl:text>*</xsl:text></xsl:if>&gt;*</xsl:variable>
            <xsl:variable name="propertyName"><xsl:value-of select="$just_name"></xsl:value-of></xsl:variable>
            <xsl:variable name="CName"><xsl:value-of select="$just_name"></xsl:value-of></xsl:variable>

            <xsl:variable name="nativePropertyType"> <!--these are used in arrays to take the native type-->
               <xsl:choose>
                 <xsl:when test="not(@type)">wso2wsf::OMElement*</xsl:when> <!-- these are anonymous -->
                 <xsl:otherwise><xsl:value-of select="@type"/><xsl:if test="@ours"><xsl:text>*</xsl:text></xsl:if></xsl:otherwise>
               </xsl:choose>
            </xsl:variable>
              <xsl:variable name="PropertyTypeArrayParam"> <!--these are used in arrays to take the type stored in the arraylist-->
                 <xsl:choose>
                   <xsl:when test="not(@type)">wso2wsf::OMElement*</xsl:when> <!-- these are anonymous -->
                   <xsl:when test="@type='unsigned short' or @type='std::string' or @type='uint64_t' or @type='unsigned int' or @type='unsigned char' or @type='short' or @type='char' or @type='int' or @type='float' or @type='double' or @type='int64_t'"><xsl:value-of select="@type"/><xsl:text>*</xsl:text></xsl:when>
                   <xsl:otherwise><xsl:value-of select="@type"/><xsl:if test="@ours"><xsl:text>*</xsl:text></xsl:if></xsl:otherwise>
                 </xsl:choose>
              </xsl:variable>
            
            <xsl:variable name="propertyInstanceName">element</xsl:variable>
            <xsl:variable name="justPropertyInstanceName">element</xsl:variable>
            <xsl:variable name="constValue">
                <xsl:choose>
                   <xsl:when test="@type='std::string' or @type='unsigned short' or @type='uint64_t' or @type='unsigned int' or @type='unsigned char' or @type='short' or @type='char' or @type='int' or @type='float' or @type='double' or @type='int64_t'">const </xsl:when>
                </xsl:choose>
            </xsl:variable>
         
        /**
         * Get the ith element of <xsl:value-of select="$propertyName"/>.
         */
        <xsl:value-of select="$nativePropertyType"/> WSF_CALL
        <xsl:value-of select="$CPPNamespace"/><xsl:value-of select="$axis2_name"/>::get<xsl:value-of select="$CName"/>At(int i)
        {
                <xsl:value-of select="$PropertyTypeArrayParam"/> ret_val;


                if(property_<xsl:value-of select="$CName"/> == NULL)
                {
                    return (<xsl:value-of select="$nativePropertyType"/>)0;
                }
                
                ret_val = (*property_<xsl:value-of select="$CName"/>)[i];
                <xsl:choose>
                  <xsl:when test="$nativePropertyType='unsigned short' or @type='std::string' or $nativePropertyType='unsigned char' or $nativePropertyType='unsigned int' or $nativePropertyType='uint64_t' or $nativePropertyType='short' or $nativePropertyType='axis2_unsigned_byte_t' or $nativePropertyType='axis2_byte_t' or $nativePropertyType='bool' or $nativePropertyType='char' or $nativePropertyType='int' or $nativePropertyType='float' or $nativePropertyType='double' or $nativePropertyType='int64_t'">
                        return *ret_val;
                    </xsl:when>
                  <xsl:otherwise>
                        return ret_val;
                  </xsl:otherwise>
                </xsl:choose>
        }

        /**
         * Set the ith element of <xsl:value-of select="$propertyName"/>. (If the ith already exist, it will be replaced)
         */
        bool WSF_CALL
        <xsl:value-of select="$CPPNamespace"/><xsl:value-of select="$axis2_name"/>::set<xsl:value-of select="$CName"/>At(int i,
                <xsl:value-of select="$constValue"/><xsl:value-of select="$nativePropertyType"/><xsl:text> arg_</xsl:text> <xsl:value-of select="$CName"/>)
        {
                <xsl:value-of select="$PropertyTypeArrayParam"/> element= NULL;
                int size = 0;
                int j;

                <xsl:if test="@type='unsigned short' or @type='unsigned char' or @type='std::string'  or @type='unsigned int' or @type='uint64_t' or @type='short' or @type='char' or @type='int' or @type='float' or @type='double' or @type='int64_t' or @type='bool' or @type='axis2_unsigned_byte_t' or @type='axis2_byte_t'">
                   <xsl:value-of select="$PropertyTypeArrayParam"/><xsl:text> ptr_param_</xsl:text><xsl:value-of select="$CName"/>;
                </xsl:if>

                
                if(isValid<xsl:value-of select="$CName"/> &amp;&amp;
                    property_<xsl:value-of select="$CName"/> &amp;&amp;
                <xsl:choose>
                  <xsl:when test="@type='unsigned short' or @type='unsigned char' or @type='std::string' or @type='unsigned int' or @type='uint64_t' or @type='short' or @type='char' or @type='int' or @type='float' or @type='double' or @type='int64_t' or @type='bool' or @type='axis2_unsigned_byte_t' or @type='axis2_byte_t'">
                    arg_<xsl:value-of select="$CName"/> == *((*property_<xsl:value-of select="$CName"/>)[i]))
                  </xsl:when>
                  <xsl:otherwise>
                    arg_<xsl:value-of select="$CName"/> == (*property_<xsl:value-of select="$CName"/>)[i])
                  </xsl:otherwise>
                </xsl:choose>
                {
                    return true;
                }


                if(property_<xsl:value-of select="$CName"/> == NULL)
                {
                    property_<xsl:value-of select="$CName"/> = new std::vector&lt;<xsl:value-of select="@type"/><xsl:if test="@ours or @type='std::string' or @type='unsigned char' or @type='unsigned short' or @type='uint64_t' or @type='unsigned int' or @type='short' or @type='char' or @type='int' or @type='float' or @type='double' or @type='int64_t'"><xsl:text>*</xsl:text></xsl:if>&gt;();
                }else{
                   /* check whether there already exist an element */
                    element = (*property_<xsl:value-of select="$CName"/>)[i];
                }
                if(NULL != element)
                {
                  <!-- Some repeated code -->
                  <!-- For all inside the choose, propertyInstanceName = element -->
                  <xsl:choose>
                     <xsl:when test="@ours">
                        delete <xsl:value-of select="$propertyInstanceName"/>;
                     </xsl:when>
            
                     <xsl:when test="$nativePropertyType='unsigned short' or $nativePropertyType='unsigned char' or $nativePropertyType='unsigned int' or $nativePropertyType='uint64_t' or $nativePropertyType='short' or $nativePropertyType='axis2_unsigned_byte_t' or $nativePropertyType='axis2_byte_t' or $nativePropertyType='bool' or $nativePropertyType='char' or $nativePropertyType='int' or $nativePropertyType='float' or $nativePropertyType='double' or $nativePropertyType='int64_t'">
                        <!-- free ints, int64_ts, float in array-->
                        /* we keep primtives as pointers in arrasy, so need to free them */
                        AXIS2_FREE(Environment::getEnv()-> allocator, element);
                     </xsl:when>
                      <xsl:when test="@type='std::string'">
                          delete element;
                      </xsl:when>
            
                     <!-- free axis2_char_t s
                     <xsl:when test="$nativePropertyType='std::string' and not(@isarray)">
                        delete <xsl:value-of select="$propertyInstanceName"/>;
                     </xsl:when>
                     -->
                     <!-- free nodes -->
                     <xsl:when test="$nativePropertyType='wso2wsf::OMElement*'">
                      delete <xsl:value-of select="$propertyInstanceName"/>;
                     </xsl:when>
            
                     <xsl:when test="$nativePropertyType='axutil_qname_t*'">
                      axutil_qname_free(<xsl:value-of select="$propertyInstanceName"/>, Environment::getEnv());
                     </xsl:when>
            
                     <xsl:when test="$nativePropertyType='axutil_uri_t*'">
                      axutil_uri_free(<xsl:value-of select="$propertyInstanceName"/>, Environment::getEnv());
                     </xsl:when>
            
                     <xsl:when test="$nativePropertyType='axutil_duration_t*'">
                      axutil_duration_free(<xsl:value-of select="$propertyInstanceName"/>, Environment::getEnv());
                     </xsl:when>
            
                     <xsl:when test="$nativePropertyType='axutil_date_time_t*'">
                      axutil_date_time_free(<xsl:value-of select="$propertyInstanceName"/>, Environment::getEnv());
                     </xsl:when>
            
                     <xsl:when test="$propertyType='axutil_base64_binary_t*'">
                      axutil_base64_binary_free (<xsl:value-of select="$propertyInstanceName"/>, Environment::getEnv());
                     </xsl:when>
                       <xsl:when test="$propertyType='axutil_duration_t*'">
                      axutil_duration_free (<xsl:value-of select="$propertyInstanceName"/>, Environment::getEnv());
                     </xsl:when>
            
                     <!--TODO: This should be extended for all the types that should be freed.. -->
                     <xsl:otherwise>

                       /* This is an unknown type or a primitive. Please free this manually <xsl:value-of select="$propertyType"/>*/
                     </xsl:otherwise>
                  </xsl:choose>
                }

                <xsl:choose>
                  <xsl:when test="@type='unsigned short' or @type='unsigned char' or @type='unsigned int' or @type='uint64_t' or @type='short' or @type='char' or @type='int' or @type='float' or @type='double' or @type='int64_t' or @type='bool' or @type='axis2_unsigned_byte_t' or @type='axis2_byte_t'">
                   <xsl:text>ptr_param_</xsl:text><xsl:value-of select="$CName"/> =  (<xsl:value-of select="$PropertyTypeArrayParam"/>)
                            AXIS2_MALLOC(Environment::getEnv()->allocator, sizeof(<xsl:value-of select="@type"/>));
                   if(property_<xsl:value-of select="$CName"/> == NULL)
                   {
                       WSF_LOG_ERROR_MSG(Environment::getEnv()->log, WSF_LOG_SI, "Failed in allocatting memory for new value of <xsl:value-of select="$propertyName"/>");
                       return AXIS2_FAILURE;
                       
                   }
                   <xsl:text>*ptr_param_</xsl:text><xsl:value-of select="$CName"/> = <xsl:text>arg_</xsl:text><xsl:value-of select="$CName"/>;
                        (*property_<xsl:value-of select="$CName"/>)[i] = <xsl:text>ptr_param_</xsl:text><xsl:value-of select="$CName"/>;
                  </xsl:when>
                  <xsl:when test="@type='std::string'">
                        (*property_<xsl:value-of select="$CName"/>)[i] = new string(<xsl:text>arg_</xsl:text><xsl:value-of select="$CName"/>.c_str());
                  </xsl:when>
                  <xsl:otherwise>
                        (*property_<xsl:value-of select="$CName"/>)[i] = <xsl:text>arg_</xsl:text><xsl:value-of select="$CName"/>;
                  </xsl:otherwise>
                </xsl:choose>
                        isValid<xsl:value-of select="$CName"/> = true;
                return true;

        }

        /**
         * Add to <xsl:value-of select="$propertyName"/>.
         */
        bool WSF_CALL
        <xsl:value-of select="$CPPNamespace"/><xsl:value-of select="$axis2_name"/>::add<xsl:value-of select="$CName"/>(<xsl:value-of select="$constValue"/><xsl:value-of select="$nativePropertyType"/><xsl:text> arg_</xsl:text> <xsl:value-of select="$CName"/>)
        {
                <xsl:if test="@type='unsigned short' or @type='unsigned char' or @type='std::string' or @type='unsigned int' or @type='uint64_t' or @type='short' or @type='char' or @type='int' or @type='float' or @type='double' or @type='int64_t' or @type='bool' or @type='axis2_unsigned_byte_t' or @type='axis2_byte_t'">
                   <xsl:value-of select="$PropertyTypeArrayParam"/><xsl:text> ptr_param_</xsl:text><xsl:value-of select="$CName"/>;
                </xsl:if>

                if(property_<xsl:value-of select="$CName"/> == NULL)
                {
                   property_<xsl:value-of select="$CName"/> = new std::vector&lt;<xsl:value-of select="@type"/><xsl:if test="@ours or @type='std::string' or @type='unsigned char' or @type='unsigned short' or @type='uint64_t' or @type='unsigned int' or @type='short' or @type='char' or @type='int' or @type='float' or @type='double' or @type='int64_t'"><xsl:text>*</xsl:text></xsl:if>&gt;();
                }
                <xsl:choose>
                  <xsl:when test="@type='unsigned short' or @type='std::string' or @type='unsigned char' or @type='unsigned int' or @type='uint64_t' or @type='short' or @type='char' or @type='int' or @type='float' or @type='double' or @type='int64_t' or @type='bool'  or @type='axis2_byte_t'">
                   <xsl:text>ptr_param_</xsl:text><xsl:value-of select="$CName"/> =  (<xsl:value-of select="$PropertyTypeArrayParam"/>)
                            AXIS2_MALLOC(Environment::getEnv()->allocator, sizeof(<xsl:value-of select="@type"/>));
                   if(property_<xsl:value-of select="$CName"/> == NULL)
                   {
                       WSF_LOG_ERROR_MSG(Environment::getEnv()->log, WSF_LOG_SI, "Failed in allocatting memory for new value of <xsl:value-of select="$propertyName"/>");
                       return AXIS2_FAILURE;
                       
                   }
                   <xsl:text>*ptr_param_</xsl:text><xsl:value-of select="$CName"/> = <xsl:text>arg_</xsl:text><xsl:value-of select="$CName"/>;

                    property_<xsl:value-of select="$CName"/>->push_back(<xsl:text>ptr_param_</xsl:text><xsl:value-of select="$CName"/>);
                  </xsl:when>
                  <xsl:when test="@type='std::string'">
                   property_<xsl:value-of select="$CName"/>->push_back(new string(<xsl:text>arg_</xsl:text><xsl:value-of select="$CName"/>.c_str()));
                  </xsl:when>
                  <xsl:otherwise>
                   property_<xsl:value-of select="$CName"/>->push_back(<xsl:text>arg_</xsl:text><xsl:value-of select="$CName"/>);
                  </xsl:otherwise>
                </xsl:choose>
                isValid<xsl:value-of select="$CName"/> = true;
                return true;

        }

        /**
         * Get the size of the <xsl:value-of select="$propertyName"/> array.
         */
        int WSF_CALL
        <xsl:value-of select="$CPPNamespace"/><xsl:value-of select="$axis2_name"/>::sizeof<xsl:value-of select="$CName"/>()
        {
                if(property_<xsl:value-of select="$CName"/> == NULL)
                {
                    return 0;
                }
                return property_<xsl:value-of select="$CName"/>->size();
        }


        /**
         * Remove the ith element of <xsl:value-of select="$propertyName"/>.
         */
        bool WSF_CALL
        <xsl:value-of select="$CPPNamespace"/><xsl:value-of select="$axis2_name"/>::remove<xsl:value-of select="$CName"/>At(int i)
        {
                void *element = NULL;
                int size = 0;
                int j;
                int k = 0;
		
                if(property_<xsl:value-of select="$CName"/> == NULL)
                {
                    isValid<xsl:value-of select="$CName"/> = false;
                    <!-- just assume it s null -->
                    return true;
                }

                /* check whether there already exist an element */
                element = (*property_<xsl:value-of select="$CName"/>)[i];
                if(NULL != element)
                {
                  <!-- Some repeated code -->
                  <!-- For all inside the choose, propertyInstanceName = element -->
                  <xsl:choose>

                      <xsl:when test="@ours">
                         <!-- Handle _t types using another attribute -->
                         <xsl:if test="@type">
                            delete <xsl:value-of select="$propertyInstanceName"/>;
                         </xsl:if>

                     </xsl:when>
            
                     <xsl:when test="$nativePropertyType='unsigned short' or $nativePropertyType='unsigned char' or $nativePropertyType='unsigned int' or $nativePropertyType='uint64_t' or $nativePropertyType='short' or $nativePropertyType='axis2_unsigned_byte_t' or $nativePropertyType='axis2_byte_t' or $nativePropertyType='bool' or $nativePropertyType='char' or $nativePropertyType='int' or $nativePropertyType='float' or $nativePropertyType='double' or $nativePropertyType='int64_t'">
                        <!-- free ints, int64_ts, float in array-->
                        /* we keep primtives as pointers in arrasy, so need to free them */
                        AXIS2_FREE(Environment::getEnv()->allocator, element);
                     </xsl:when>
            
                     <!-- free axis2_char_t s -->
                     <xsl:when test="$nativePropertyType='std::string' and not(@isarray)">
                     <!--    delete <xsl:value-of select="$propertyInstanceName"/>; -->
                     </xsl:when>
            
                     <!-- free nodes -->
                     <xsl:when test="$nativePropertyType='wso2wsf::OMElement*'">
                      delete <xsl:value-of select="$propertyInstanceName"/>;
                     </xsl:when>
            
                     <xsl:when test="$nativePropertyType='axutil_qname_t*'">
                      axutil_qname_free(<xsl:value-of select="$propertyInstanceName"/>, Environment::getEnv());
                     </xsl:when>
            
                     <xsl:when test="$nativePropertyType='axutil_uri_t*'">
                      axutil_uri_free(<xsl:value-of select="$propertyInstanceName"/>, Environment::getEnv());
                     </xsl:when>
            
                     <xsl:when test="$nativePropertyType='axutil_duration_t*'">
                      axutil_duration_free(<xsl:value-of select="$propertyInstanceName"/>, Environment::getEnv());
                     </xsl:when>
            
                     <xsl:when test="$nativePropertyType='axutil_date_time_t*'">
                      axutil_date_time_free(<xsl:value-of select="$propertyInstanceName"/>, Environment::getEnv());
                     </xsl:when>
            
                     <xsl:when test="$propertyType='axutil_base64_binary_t*'">
                      axutil_base64_binary_free (<xsl:value-of select="$propertyInstanceName"/>, Environment::getEnv());
                     </xsl:when>
                       <xsl:when test="$propertyType='axutil_duration_t*'">
                      axutil_duration_free (<xsl:value-of select="$propertyInstanceName"/>, Environment::getEnv());
                     </xsl:when>
            
                     <!--TODO: This should be extended for all the types that should be freed.. -->
                     <xsl:otherwise>
                       /* This is an unknown type or a primitive. Please free this manually*/
                     </xsl:otherwise>
                  </xsl:choose>
                }

                (*property_<xsl:value-of select="$CName"/>)[i]=  NULL;
                return true;
        }

        /**
         * Getter for <xsl:value-of select="$propertyName"/> by  Property Number <xsl:value-of select="position()"/>
         */
        <xsl:value-of select="$propertyType"/> WSF_CALL
        <xsl:value-of select="$CPPNamespace"/><xsl:value-of select="$axis2_name"/>::getProperty<xsl:value-of select="position()"/>()
        {
            return get<xsl:value-of select="$CName"/>();
        }


        /**
         * Getter for <xsl:value-of select="$propertyName"/>.
         */
        <xsl:value-of select="$propertyType"/> WSF_CALL
        <xsl:value-of select="$CPPNamespace"/><xsl:value-of select="$axis2_name"/>::get<xsl:value-of select="$CName"/>()
        {
             return property_<xsl:value-of select="$CName"/>;
        }

        /**
         * Setter for <xsl:value-of select="$propertyName"/>.
         */
        bool WSF_CALL
        <xsl:value-of select="$CPPNamespace"/><xsl:value-of select="$axis2_name"/>::set<xsl:value-of select="$CName"/>(
            <xsl:value-of select="$propertyType"/><xsl:text> </xsl:text> arg_<xsl:value-of select="$CName"/>)
        {


                if(isValid<xsl:value-of select="$CName"/> &amp;&amp;
                        property_<xsl:value-of select="$CName"/> == arg_<xsl:value-of select="$CName"/>)
                {
                    <xsl:if test="$choice">
                        currentChoice = "<xsl:value-of select="@nsuri"/>:<xsl:value-of select="$propertyName"/>";
                    </xsl:if>
                    return true;
                }

                <!-- first reset whatever already in there -->
                reset<xsl:value-of select="$CName"/>();

                <xsl:if test="(@ours or not($propertyType='std::string' or $propertyType='unsigned char' or $propertyType='unsigned int' or $propertyType='unsigned short' or $propertyType='uint64_t' or $propertyType='char' or $propertyType='int' or $propertyType='short' or $propertyType='float' or $propertyType='axis2_unsigned_byte_t' or  $propertyType='axis2_byte_t' or $propertyType='double' or $propertyType='int64_t' or $propertyType='bool'))">
                if(NULL == arg_<xsl:value-of select="$CName"/>)
                {
                    /* We are already done */
                    return true;
                }
                </xsl:if>

                property_<xsl:value-of select="$CName"/> = arg_<xsl:value-of select="$CName"/>;
                isValid<xsl:value-of select="$CName"/> = true;

                return true;
         }
        

        /**
         * Reset method for <xsl:value-of select="$propertyName"/>
         */
        bool WSF_CALL
        <xsl:value-of select="$CPPNamespace"/><xsl:value-of select="$axis2_name"/>::reset<xsl:value-of select="$CName"/>()
        {
                <!-- This is always an array -->
                  if (property_<xsl:value-of select="$CName"/> != NULL)
                  {
                      std::vector&lt;<xsl:value-of select="@type"/><xsl:if test="@ours or @type='std::string' or @type='unsigned char' or @type='unsigned short' or @type='uint64_t' or @type='unsigned int' or @type='short' or @type='char' or @type='int' or @type='float' or @type='double' or @type='int64_t'"><xsl:text>*</xsl:text></xsl:if>&gt;::iterator _it = property_<xsl:value-of select="$CName"/>->begin();
                      for(; _it != property_<xsl:value-of select="$CName"/>->end(); _it++)
                      {
                            <xsl:value-of select="@type"/><xsl:if test="@ours or @type='std::string' or @type='unsigned char' or @type='unsigned short' or @type='uint64_t' or @type='unsigned int' or @type='short' or @type='char' or @type='int' or @type='float' or @type='double' or @type='int64_t'"><xsl:text>*</xsl:text></xsl:if> element =  (*_it);
                        <!-- the following element can be inside array or exist independently-->
                            if(<xsl:value-of select="$justPropertyInstanceName"/> != NULL)
                            {
                               <!-- how to free all the ours things -->
                               <xsl:choose>
                                 <xsl:when test="@ours">
                                    delete <xsl:value-of select="$propertyInstanceName"/>;
                                 </xsl:when>

                                 <!-- free nodes -->
                                 <xsl:when test="$nativePropertyType='wso2wsf::OMElement*'">
                                     delete  <xsl:value-of select="$propertyInstanceName"/>;
                                 </xsl:when>

                                 <xsl:when test="$nativePropertyType='axutil_qname_t*'">
                                  axutil_qname_free(<xsl:value-of select="$propertyInstanceName"/>, Environment::getEnv());
                                 </xsl:when>

                                 <xsl:when test="$nativePropertyType='axutil_uri_t*'">
                                  axutil_uri_free(<xsl:value-of select="$propertyInstanceName"/>, Environment::getEnv());
                                 </xsl:when>

                                 <xsl:when test="$nativePropertyType='axutil_duration_t*'">
                                  axutil_duration_free(<xsl:value-of select="$propertyInstanceName"/>, Environment::getEnv());
                                 </xsl:when>

                                 <xsl:when test="$nativePropertyType='axutil_date_time_t*'">
                                  axutil_date_time_free(<xsl:value-of select="$propertyInstanceName"/>, Environment::getEnv());
                                 </xsl:when>

                                 <xsl:when test="$propertyType='axutil_base64_binary_t*'">
                                  axutil_base64_binary_free (<xsl:value-of select="$propertyInstanceName"/>, Environment::getEnv());
                                 </xsl:when>
                                   <xsl:when test="$propertyType='axutil_duration_t*'">
                                  axutil_duration_free (<xsl:value-of select="$propertyInstanceName"/>, Environment::getEnv());
                                 </xsl:when>
                                  <xsl:when test="@type='std::string'">
                                    delete <xsl:value-of select="$propertyInstanceName"/>;
                                 </xsl:when>
                                 <xsl:when test="@type='unsigned char' or @type='unsigned short' or @type='uint64_t' or @type='unsigned int' or @type='short' or @type='char' or @type='int' or @type='float' or @type='double' or @type='int64_t'">
                                        AXIS2_FREE(Environment::getEnv()->allocator, <xsl:value-of select="$propertyInstanceName"/>);
                                 </xsl:when>
                                   <!--TODO: This should be extended for all the types that should be freed.. -->
                                 <xsl:otherwise>
                                   /* This is an unknown type  Please free this manually*/
                                 </xsl:otherwise>
                               </xsl:choose>

                        }

                <!--/xsl:if-->
                <!-- close tags arrays -->
                   }

                      delete property_<xsl:value-of select="$CName"/>;
                      property_<xsl:value-of select="$CName"/> = NULL;
                  }
               isValid<xsl:value-of select="$CName"/> = false;
               return true;

        }


        </xsl:for-each>

        <xsl:for-each select="memberType">
            <xsl:variable name="member_type"><xsl:value-of select="@type"/><xsl:if test="@ours">*</xsl:if></xsl:variable>
            <xsl:variable name="member_name"><xsl:text></xsl:text><xsl:value-of select="@originalName"/></xsl:variable>
 
            <xsl:value-of select="$member_type"/> WSF_CALL
            <xsl:value-of select="$CPPNamespace"/><xsl:value-of select="$axis2_name"/>::get<xsl:value-of select="$member_name"/>()
            {
                if(!axutil_strcmp(currentValue.c_str(), "<xsl:value-of select="@originalName"/>"))
                {
                    return memberType._<xsl:value-of select="$member_name"/>;
                }
                return (<xsl:value-of select="$member_type"/>)0;
            }
 
            bool WSF_CALL
            <xsl:value-of select="$CPPNamespace"/><xsl:value-of select="$axis2_name"/>::set<xsl:value-of select="$member_name"/>(<xsl:value-of select="$member_type"/> member_type)
            {
                bool status;
                status = resetMembers();
               
                if(status)
                {
                    <xsl:choose>
                    <xsl:when test="$member_type='std::string'">
                        memberType._<xsl:value-of select="$member_name"/> = member_type;
                    </xsl:when>
                    <xsl:otherwise>
                        memberType._<xsl:value-of select="$member_name"/> = member_type;
                    </xsl:otherwise>
                    </xsl:choose>
                        currentValue = "<xsl:value-of select="@originalName"/>";
                }

                return status;
            }

            bool WSF_CALL
            <xsl:value-of select="$axis2_name"/>::isValid<xsl:value-of select="$member_name"/>()
            {
                return !axutil_strcmp(currentValue.c_str(), "<xsl:value-of select="@originalName"/>");
            }
        </xsl:for-each>
    
        <xsl:if test="$isUnion">

        bool WSF_CALL
        <xsl:value-of select="$CPPNamespace"/><xsl:value-of select="$axis2_name"/>::resetMembers()
        {

            if(!axutil_strcmp(currentValue.c_str(), ""))
            {
                /* do nothing */
            }
            <xsl:for-each select="memberType">
        <xsl:variable name="member_type"><xsl:value-of select="@type"/><xsl:if test="@ours">*</xsl:if></xsl:variable>
                <xsl:variable name="member_name"><xsl:text></xsl:text><xsl:value-of select="@originalName"/></xsl:variable>

                else if(!axutil_strcmp(currentValue.c_str(), "<xsl:value-of select="@originalName"/>"))
                {

                    <xsl:choose>
                        <xsl:when test="@ours">
                            delete memberType._<xsl:value-of select="$member_name"/>;
                        </xsl:when>
                        <xsl:when test="$member_type='std::string'">
                            <!-- AXIS2_FREE(Environment::getEnv()->allocator, <xsl:value-of select="$name"/>->member_type._<xsl:value-of select="$member_name"/>); -->
                        </xsl:when>
                        <xsl:otherwise>

                        </xsl:otherwise>
                    </xsl:choose>

                }
            </xsl:for-each>   
            currentValue = "";
            return true;
        }

        std::string WSF_CALL
        <xsl:value-of select="$CPPNamespace"/><xsl:value-of select="$axis2_name"/>::currentMemberType()
        {
            return currentValue;
        }
        </xsl:if>

    </xsl:template>

</xsl:stylesheet>
