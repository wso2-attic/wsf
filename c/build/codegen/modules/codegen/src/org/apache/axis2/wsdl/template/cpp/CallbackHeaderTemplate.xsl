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
    <xsl:template match="/callback">

#ifndef <xsl:value-of select="@caps-name"/>_H
#define <xsl:value-of select="@caps-name"/>_H
/**
 * <xsl:value-of select="@name"/>.h
 *
 * This file was auto-generated from WSDL
 * by the Apache Axis2 version: #axisVersion# #today#
 */
       <xsl:variable name="servicename" select="@servicename"></xsl:variable>
       <xsl:variable name="enableNS2P" select="@enableNS2P"></xsl:variable>

    <xsl:for-each select="method">
        <xsl:variable name="outParamType" select="output/param[@location='body']/@type"></xsl:variable>
        <xsl:variable name="filename" select="output/param[@location='body']/@filename"></xsl:variable>
        <xsl:variable name="outParamName" select="output/param/@name"></xsl:variable>
        <xsl:variable name="outParamComplexType" select="output/param[@location='body']/@complextype"></xsl:variable>
        <xsl:variable name="outParamCount" select="count(output/param[@location='body']/param)"></xsl:variable>
        <xsl:variable name="mep"><xsl:value-of select="@mep"/></xsl:variable>
        <xsl:variable name="isUnwrapParameters" select="input/param[@location='body' and @type!='']/@unwrappParameters"/>
        <xsl:if test="output/param/@ours">
            <xsl:variable name="outParamFilename">
                <xsl:choose>
                    <xsl:when test="$enableNS2P">
                        <xsl:value-of select="$filename"/>
                    </xsl:when>
                    <xsl:otherwise>
                        <xsl:value-of select="substring-after($outParamType,'::')"/>
                    </xsl:otherwise>
                </xsl:choose>
            </xsl:variable>
#include "<xsl:value-of select="$outParamFilename"/>.h"
        </xsl:if>
       <xsl:for-each select="output/param[@location='soap_header']">
       <xsl:variable name="outParamHeader"><xsl:value-of select="@type"/></xsl:variable>
           <xsl:if test="@ours">
#include "<xsl:value-of select="substring-after($outParamHeader,'::')"/>.h"
           </xsl:if>
       </xsl:for-each>
    </xsl:for-each>

#include "<xsl:value-of select="substring-before(substring-after(@name,'I'),'Callback')"/>Stub.h" 

 namespace <xsl:value-of select="@cppNamespace"/>
   {

    /**
     *  <xsl:value-of select="@name"/> Callback class, Users can extend this class and implement
     *  their own receiveResult and receiveError methods.
     */

    class <xsl:value-of select="@name"/>
{


    protected:

    void* clientData;

    public:

    /**
    * User can pass in any object that needs to be accessed once the NonBlocking
    * Web service call is finished and appropriate method of this CallBack is called.
    * @param clientData Object mechanism by which the user can pass in user data
    * that will be available at the time this callback is called.
    */
    <xsl:value-of select="@name"/>(void* clientData);

    /**
    * Please use this constructor if you don't want to set any clientData
    */
    <xsl:value-of select="@name"/>();


    /**
     * Get the client data
     */

     void* getClientData();

    <xsl:for-each select="method">
            <xsl:variable name="outParamType" select="output/param[@location='body']/@type"></xsl:variable>
            <xsl:variable name="outParamName" select="output/param/@name"></xsl:variable>
            <xsl:variable name="outParamComplexType" select="output/param[@location='body']/@complextype"></xsl:variable>
            <xsl:variable name="outParamCount" select="count(output/param[@location='body']/param)"></xsl:variable>
            <xsl:variable name="mep"><xsl:value-of select="@mep"/></xsl:variable>
            <xsl:variable name="isUnwrapParameters" select="input/param[@location='body' and @type!='']/@unwrappParameters"/>
            <xsl:choose>
                <!-- Code generation for in-out only. Need to consider the other meps also
                    They should be parts of this xsl:choose loop -->
          <xsl:when test="$mep='12'">
            <xsl:variable name="outputtype">
                <xsl:choose>
                    <xsl:when test="$isUnwrapParameters">
                        <xsl:value-of select="output/param/param/@type"/><xsl:if test="output/param/param/@ours"><xsl:text>*</xsl:text></xsl:if>
                    </xsl:when>
                    <xsl:otherwise><xsl:value-of select="output/param/@type"></xsl:value-of><xsl:if test="output/param/@ours"><xsl:text>*</xsl:text></xsl:if></xsl:otherwise>
                </xsl:choose>
            </xsl:variable>
           /**
            * auto generated WSF/C++ call back method for <xsl:value-of select="@name"/> method
            * override this method for handling normal response from <xsl:value-of select="@name"/> operation
            */
          virtual void receiveResult_<xsl:value-of select="@name"/>(
              <!--
                    <xsl:choose>
                        <xsl:when test="$outParamCount=1">
                             <xsl:value-of select="output/param[@location='body']/param/@type"/><xsl:if test="output/param/@ours"><xsl:text>*</xsl:text></xsl:if><xsl:text> </xsl:text>result
                        </xsl:when>
                        <xsl:when test="string-length(normalize-space($outParamComplexType)) > 0">
                            <xsl:value-of select="$outParamComplexType"/><xsl:if test="output/param/@ours"><xsl:text>*</xsl:text></xsl:if><xsl:text> </xsl:text>result
                        </xsl:when>
                        <xsl:when test="($outParamCount=0) and ($isUnwrapParameters)">
                        </xsl:when>
                        <xsl:when test="string-length(normalize-space($outParamType)) > 0">
                            <xsl:value-of select="$outParamType"/><xsl:if test="output/param/@ours"><xsl:text>*</xsl:text></xsl:if><xsl:text> </xsl:text>result
                        </xsl:when>
                    </xsl:choose>
                    -->
                    <xsl:value-of select="$outputtype"/> result
                    <xsl:for-each select="output/param[@location='soap_header']">
                           <xsl:if test="position()>0">,</xsl:if>
                           <xsl:variable name="outputtype"><xsl:value-of select="@type"/><xsl:if test="@ours">*</xsl:if></xsl:variable>
                           <xsl:value-of select="$outputtype"/><xsl:text> dp_</xsl:text><xsl:value-of select="@name"/>                
                    </xsl:for-each>
                     <xsl:if test="count(fault/*)">,<xsl:value-of select="$servicename"/>_<xsl:value-of select="@name"/><xsl:text>_fault</xsl:text> fault</xsl:if>
                    ){}


          /**
           * auto generated WSF/C++ Error handler
           * override this method for handling error response from <xsl:value-of select="@name"/> operation
           */
           virtual void receiveError_<xsl:value-of select="@name"/>(int exception){}
            </xsl:when>
            <xsl:otherwise>
           // No methods generated for meps other than in-out
            </xsl:otherwise>
        </xsl:choose>


    </xsl:for-each>


    };
}

#endif  //<xsl:value-of select="@caps-name"/>_H
    </xsl:template>
</xsl:stylesheet>
