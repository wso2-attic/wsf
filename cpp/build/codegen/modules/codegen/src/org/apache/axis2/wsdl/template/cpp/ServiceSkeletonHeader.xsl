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

      <!--Template for in out message receiver -->
      <xsl:template match="/interface">
        <xsl:variable name="skeletonname"><xsl:value-of select="@name"/></xsl:variable>
        <xsl:variable name="caps_svc_name"><xsl:value-of select="@caps-svc-name"/></xsl:variable>
        <xsl:variable name="qname"><xsl:value-of select="@qname"/></xsl:variable>
        <xsl:variable name="method-prefix"><xsl:value-of select="@prefix"/></xsl:variable>
        <xsl:variable name="svcop-prefix"><xsl:value-of select="@svcop_prefix"/></xsl:variable>
        <xsl:variable name="svcname"><xsl:value-of select="@svcname"/></xsl:variable>
        <xsl:variable name="servicename"><xsl:value-of select="@svcname"/></xsl:variable>
        <xsl:variable name="soapVersion"><xsl:value-of select="@soap-version"/></xsl:variable>

          #ifndef <xsl:value-of select="@caps-svcname"/>_H
          #define <xsl:value-of select="@caps-svcname"/>_H

        /**
         * <xsl:value-of select="@name"/>.h
         *
         * This file was auto-generated from WSDL for "<xsl:value-of select="$qname"/>" service
         * by the Apache Axis2 version: #axisVersion# #today#
         *  <xsl:value-of select="$skeletonname"/>
         */

#include &lt;ServiceSkeleton.h&gt;
#include &lt;stdio.h&gt;
#include &lt;axis2_svc.h&gt;

using namespace wso2wsf;

<xsl:if test="@cppNamespace">
using namespace <xsl:value-of select="@cppNamespace"/>;
</xsl:if>


#define WSF_SERVICE_SKEL_INIT(class_name) \
<xsl:value-of select="$svcop-prefix"/>* wsfGet<xsl:value-of select="$svcop-prefix"/>(){ return new class_name(); }

<xsl:value-of select="$svcop-prefix"/>* wsfGet<xsl:value-of select="$svcop-prefix"/>(); 



        class <xsl:value-of select="@name"/> : public ServiceSkeleton
        {
            private:
                <xsl:value-of select="$svcop-prefix"/> *skel;

            public:

               union {
                     <xsl:for-each select="method">
                         <xsl:if test="count(fault/*)">
                         <xsl:value-of select="$servicename"/>_<xsl:value-of select="@name"/><xsl:text>_fault </xsl:text> *<xsl:value-of select="@name"/>_fault;
                         </xsl:if>
                     </xsl:for-each>
               } fault;


              WSF_EXTERN WSF_CALL <xsl:value-of select="@name"/>();

              OMElement* WSF_CALL invoke(OMElement *message, MessageContext *msgCtx);

              OMElement* WSF_CALL onFault(OMElement *message);

              virtual bool WSF_CALL init();

              ~<xsl:value-of select="@name"/>(); 
      };



#endif    //     <xsl:value-of select="@caps-svcname"/>_H

    </xsl:template>

</xsl:stylesheet>
