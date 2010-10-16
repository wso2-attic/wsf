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


    <xsl:template match="/class">
        <xsl:variable name="callbackName"><xsl:value-of select="@callbackName"/></xsl:variable>
        <xsl:variable name="isSync"><xsl:value-of select="@isSync"/></xsl:variable>
        <xsl:variable name="isAsync"><xsl:value-of select="@isAsync"/></xsl:variable>
        <xsl:variable name="soapVersion"><xsl:value-of select="@soap-version"/></xsl:variable>
        <xsl:variable name="method-prefix"><xsl:value-of select="@prefix"/></xsl:variable>
        <xsl:variable name="qname"><xsl:value-of select="@qname"/></xsl:variable>
        <xsl:variable name="servicename"><xsl:value-of select="@servicename"/></xsl:variable>
        <xsl:variable name="caps_name"><xsl:value-of select="@caps-name"/></xsl:variable>
        <xsl:variable name="enableNS2P"><xsl:value-of select="@enableNS2P"/></xsl:variable>

#ifndef <xsl:value-of select="$caps_name"/>_H
#define <xsl:value-of select="$caps_name"/>_H
/**
* <xsl:value-of select="@name"/>.h
*
* This file was auto-generated from WSDL for "<xsl:value-of select="$qname"/>" service
* by the Apache Axis2/Java version: #axisVersion# #today#
*/

#include &lt;stdio.h&gt;
#include &lt;OMElement.h&gt;
#include &lt;Stub.h&gt;
#include &lt;ServiceClient.h&gt;

<xsl:for-each select="method">
<xsl:for-each select="input/param[@type!='' and @ours ]">
    <xsl:variable name="inputtype">
         <xsl:choose>
             <xsl:when test="$enableNS2P">
                 <xsl:value-of select="@filename"/>
             </xsl:when>
             <xsl:otherwise>
                 <xsl:value-of select="substring-after(@type,'::')"/>
             </xsl:otherwise>
         </xsl:choose>
     </xsl:variable>
#include &lt;<xsl:value-of select="$inputtype"/>.h&gt;
</xsl:for-each>
<xsl:for-each select="output/param[@type!='' and @ours ]">
    <xsl:variable name="outputtype">
         <xsl:choose>
             <xsl:when test="$enableNS2P">
                 <xsl:value-of select="@filename"/>
             </xsl:when>
             <xsl:otherwise>
                 <xsl:value-of select="substring-after(@type,'::')"/>
             </xsl:otherwise>
         </xsl:choose>
     </xsl:variable>
    #include &lt;<xsl:value-of select="$outputtype"/>.h&gt;
</xsl:for-each>
<xsl:for-each select="fault/param[@type!='']">
 <xsl:variable name="faulttype">
     <xsl:choose>
         <xsl:when test="$enableNS2P">
             <xsl:value-of select="@filename"/>
         </xsl:when>
         <xsl:otherwise>
             <xsl:value-of select="substring-after(@type,'::')"/>
         </xsl:otherwise>
     </xsl:choose>
 </xsl:variable>
    #include &lt;<xsl:value-of select="$faulttype"/>.h&gt;
</xsl:for-each>
</xsl:for-each>

namespace <xsl:value-of select="@cppNamespace"/>
{

#define <xsl:value-of select="$caps_name"/>_ERROR_CODES_START (AXIS2_ERROR_LAST + 2000)

typedef enum
{
     <xsl:value-of select="$caps_name"/>_ERROR_NONE = <xsl:value-of select="$caps_name"/>_ERROR_CODES_START,

    <xsl:for-each select="method">
        <xsl:variable name="caps_method_name" select="@caps-name"/>
        <xsl:for-each select="fault/param">
            <xsl:value-of select="$caps_name"/>_<xsl:value-of select="$caps_method_name"/>_FAULT_<xsl:value-of select="@caps-localname"/>,
        </xsl:for-each>
    </xsl:for-each>
    <xsl:value-of select="$caps_name"/>_ERROR_LAST
} <xsl:value-of select="$method-prefix"/>_error_codes;

 class <xsl:value-of select="$callbackName"/>;

 <xsl:for-each select="method">
     <xsl:if test="count(fault/*)">
    /**
     * the generated fault union for operation "<xsl:value-of select="@name"/>",
     * in a case the server return a fault, the corresponding adb object will be loaded for
     * the union variable pointer comes as the last parameter of the method
     */
    typedef union
    {
        <xsl:for-each select="fault/param">
            <xsl:value-of select="@type"/><xsl:text>* </xsl:text><xsl:value-of select="@shorttype"/>;
        </xsl:for-each>
    } <xsl:value-of select="$servicename"/>_<xsl:value-of select="@name"/><xsl:text>_fault</xsl:text>;
 </xsl:if>
</xsl:for-each>

class <xsl:value-of select="@name"/> : public wso2wsf::Stub
{

        public:
        /**
         *  Constructor of <xsl:value-of select="@servicename"/> class
         *  @param client_home WSF/C home directory
         *  
         */
        <xsl:value-of select="@name"/>(std::string&amp; client_home);

        /**
         *  Constructor of <xsl:value-of select="@servicename"/> class
         *  @param client_home WSF/C home directory
         *  @param endpoint_uri The to endpoint uri,
         */

        <xsl:value-of select="@name"/>(std::string&amp; client_home, std::string&amp; endpoint_uri);

        /**
         *  Destructor of <xsl:value-of select="@servicename"/> class
         */

        ~<xsl:value-of select="@name"/>();

        /**
         * Populate Services for <xsl:value-of select="@name"/>
         */
        void WSF_CALL
        populateServicesFor<xsl:value-of select="$servicename"/>();

        /**
         * Get the endpoint uri of the <xsl:value-of select="@name"/>
         */

        std::string WSF_CALL
        getEndpointUriOf<xsl:value-of select="$servicename"/>();

        <xsl:if test="$isSync='1'">
        <xsl:for-each select="method">
          <xsl:if test="@mep='10' or @mep='12'">
            <xsl:variable name="outputours"><xsl:value-of select="output/param/@ours"></xsl:value-of></xsl:variable>
            <xsl:variable name="isUnwrapParameters" select="input/param[@location='body' and @type!='']/@unwrappParameters"/>
            <xsl:variable name="outputtype">
                <xsl:choose>
                    <xsl:when test="$isUnwrapParameters">
                        <xsl:value-of select="output/param/param/@type"/><xsl:if test="output/param/param/@ours">*</xsl:if>
                    </xsl:when>
                    <xsl:otherwise><xsl:value-of select="output/param/@type"></xsl:value-of><xsl:if test="output/param/@ours">*</xsl:if></xsl:otherwise>
                </xsl:choose>
            </xsl:variable>

            /**
             * Auto generated function declaration
             * for "<xsl:value-of select="@qname"/>" operation.
             * <xsl:if test="not($isUnwrapParameters)">
              <xsl:for-each select="input/param[@type!='']"><xsl:text>
             </xsl:text>* @param _<xsl:value-of select="@name"/> of the <xsl:value-of select="@type"/></xsl:for-each></xsl:if>
             <xsl:if test="$isUnwrapParameters"><xsl:for-each select="input/param/param[@type!='']"><xsl:text>
             </xsl:text>* @param _<xsl:value-of select="@name"/> of the <xsl:value-of select="@type"/></xsl:for-each></xsl:if>
             *<xsl:for-each select="output/param[@location='soap_header']"><xsl:text>
             </xsl:text>* @param dp_<xsl:value-of select="@name"/> - output header</xsl:for-each>
             * @return <xsl:value-of select="$outputtype"/>
             */

            <xsl:variable name="inputparams">
                <xsl:choose>
                <xsl:when test="$isUnwrapParameters">
                      <xsl:for-each select="input/param/param[@type!='']">
                          <xsl:if test="position() > 1"><xsl:text>,</xsl:text></xsl:if>
                          <xsl:value-of select="@type"/><xsl:text> _</xsl:text><xsl:value-of select="@name"/>
                      </xsl:for-each>
                </xsl:when>
                <xsl:otherwise>
                      <xsl:for-each select="input/param[@type!='']">
                          <xsl:if test="position() > 1"><xsl:text>,</xsl:text></xsl:if>
                          <xsl:value-of select="@type"/><xsl:if test="@type!='wso2wsf::OMElement*'"><xsl:text>* </xsl:text></xsl:if> _<xsl:value-of select="@name"/>
                      </xsl:for-each>
                </xsl:otherwise>
                </xsl:choose>
            </xsl:variable>
            <xsl:choose>
                <xsl:when test="$outputtype=''">bool WSF_CALL</xsl:when>
                <xsl:when test="$outputtype!=''"><xsl:value-of select="$outputtype"/> WSF_CALL</xsl:when>
            </xsl:choose>
            <xsl:text> </xsl:text>
        <xsl:value-of select="@name"/><xsl:text>( </xsl:text><xsl:value-of select="$inputparams"/>
                                                    <xsl:for-each select="output/param[@location='soap_header']">
                                                        <xsl:variable name="outputtype">
                                                            <xsl:value-of select="@type"/>
                                                            <xsl:if test="@ours">**</xsl:if>
                                                        </xsl:variable>
                                                        <xsl:text>,</xsl:text>
                                                        <xsl:value-of select="$outputtype"/>
                                                        <xsl:text> dp_</xsl:text>
                                                        <xsl:value-of select="@name"/>
                                                        <xsl:text>/* output header double ptr*/</xsl:text>
                                                    </xsl:for-each>
                                                 <xsl:if test="count(fault/*)">,
                                                    <xsl:value-of select="$servicename"/>_<xsl:value-of select="@name"/><xsl:text>_fault</xsl:text> *fault</xsl:if>);
          </xsl:if>
    </xsl:for-each>
    </xsl:if>  <!--close for  test="$isSync='1'-->

    <!-- Async method prototype generation -->
    <xsl:if test="$isAsync='1'">
    <xsl:for-each select="method">

        <xsl:variable name="mep"><xsl:value-of select="@mep"/></xsl:variable>
        <xsl:variable name="isUnwrapParameters" select="input/param[@location='body' and @type!='']/@unwrappParameters"/>
        <xsl:variable name="outputtype">
            <xsl:choose>
                <xsl:when test="$isUnwrapParameters">
                            <xsl:value-of select="output/param/param/@type"/><xsl:if test="output/param/param/@ours">*</xsl:if>
                </xsl:when>
                <xsl:otherwise><xsl:value-of select="output/param/@type"></xsl:value-of></xsl:otherwise>
            </xsl:choose>
        </xsl:variable>

        <xsl:if test="$mep='12'">

        <xsl:variable name="inputparams">
            <xsl:choose>
            <xsl:when test="$isUnwrapParameters">
                                              <xsl:for-each select="input/param/param[@type!='']">
                                                  <xsl:if test="position() > 1"><xsl:text>,</xsl:text></xsl:if>
                                                  <xsl:value-of select="@type"/><xsl:text> _</xsl:text><xsl:value-of select="@name"/>
                                                </xsl:for-each>
            </xsl:when>
            <xsl:otherwise>
                                              <xsl:for-each select="input/param[@type!='']">
                                                  <xsl:if test="position() > 1"><xsl:text>,</xsl:text></xsl:if>
                                                  <xsl:value-of select="@type"/><xsl:if test="@type! ='wso2wsf::OMElement*'"><xsl:text>* </xsl:text></xsl:if> _<xsl:value-of select="@name"/>
                                              </xsl:for-each>
            </xsl:otherwise>
            </xsl:choose>
        </xsl:variable>

        /**
         * Auto generated function for asynchronous invocations
         * for "<xsl:value-of select="@qname"/><xsl:text>" operation.
         * @param stub The stub
         * </xsl:text>
         <!--  select only the body parameters  -->
         <xsl:if test="not($isUnwrapParameters)"><xsl:for-each select="input/param[@type!='']"><xsl:text>
         * @param _</xsl:text><xsl:value-of select="@name"/> of the <xsl:value-of select="@type"/></xsl:for-each></xsl:if>
         <xsl:if test="$isUnwrapParameters"><xsl:for-each select="input/param/param[@type!='']"><xsl:text>
         * @param _</xsl:text><xsl:value-of select="@name"/> of the <xsl:value-of select="@type"/></xsl:for-each></xsl:if>
         * @param ICallback callback handler
         */


        void WSF_CALL
        start_<xsl:value-of select="@name"/>(<xsl:if test="$inputparams != ''"><xsl:value-of select="$inputparams"/>,</xsl:if><xsl:value-of select="$callbackName"/>* callback);

        </xsl:if>  <!--close for  test="$mep='http://www.w3.org/2004/08/wsdl/in-out'"-->
        </xsl:for-each>
        </xsl:if>  <!--close for  test="$isAsync='1'-->
<!--
     <xsl:if test="method/input/param[@location='soap_header']">
      /**
       * function to free any soap input headers
       * @param env environment ( mandatory)
       */
     </xsl:if>
     <xsl:for-each select="method">
        <xsl:if test="input/param[@location='soap_header']">
         void AXIS2_CALL
         axis2_stub_op_<xsl:value-of select="$servicename"/>_<xsl:value-of select="@name"/>_free_input_headers(const axutil_env_t *env, <xsl:for-each select="input/param[@location='soap_header']"><xsl:if test="position()!=1">,</xsl:if>
                                                 <xsl:variable name="inputtype"><xsl:value-of select="@type"/></xsl:variable>
                                                 <xsl:value-of select="$inputtype"/><xsl:text> _</xsl:text><xsl:value-of select="@name"/>
                                                 </xsl:for-each>);
        </xsl:if>
    </xsl:for-each>

     <xsl:if test="method/output/param[@location='soap_header']">
      /**
       * function to free any soap output headers
       * @param env environment ( mandatory)
       */
     </xsl:if>
     <xsl:for-each select="method">
        <xsl:if test="output/param[@location='soap_header']">
         void AXIS2_CALL
         axis2_stub_op_<xsl:value-of select="$servicename"/>_<xsl:value-of select="@name"/>_free_output_headers(const axutil_env_t *env, <xsl:for-each select="output/param[@location='soap_header']"><xsl:if test="position()!=1">,</xsl:if>
                                                 <xsl:variable name="outputtype"><xsl:value-of select="@type"/></xsl:variable>
                                                 <xsl:value-of select="$outputtype"/><xsl:text> _</xsl:text><xsl:value-of select="@name"/>
                                                 </xsl:for-each>);
        </xsl:if>
    </xsl:for-each>
-->

};

/** we have to reserve some error codes for adb and for custom messages */



}


        
#endif        
   </xsl:template>
</xsl:stylesheet>

