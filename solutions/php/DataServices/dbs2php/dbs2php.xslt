<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/XSL/Transform" version="1.0">
    <xsl:output method="text"/>

    <!-- the name for the service -->
    <xsl:variable name="serviceName" select="/data/@name"/>
    <xsl:template match="/data">


        <!-- open the php tag -->
<xsl:text>&lt;?php
</xsl:text>

        <xsl:text>
        // import the DataService Library

        require_once("DataService.php");
        </xsl:text>

        <!-- first of all create the config map -->
        <xsl:call-template name="buildConfig">
            <xsl:with-param name="config" select="config"/>
        </xsl:call-template>

       
        <!-- we first start up for each operation-->
        <xsl:for-each select="operation">
            <xsl:variable name="opName" select="@name"/>
            <xsl:text>

        // ----------building the queries for </xsl:text><xsl:value-of select="$opName"/><xsl:text> ------------
            </xsl:text>
            <!-- there we catch up a query -->
            <xsl:variable name="queryId" select="call-query/@href"/>
            <xsl:variable name="queryInfoVarPrefix" select="$queryId"/>
            
            <!-- at the first step, we don't set any indices to the prefix -->
            <xsl:variable name="recursiveIndex"><xsl:text></xsl:text></xsl:variable>
            <xsl:variable name="iterativeIndex"><xsl:text></xsl:text></xsl:variable>
            
            <!-- for php quries are meaningful only when they are called.. so
                 here we treadted call-query is part of query -->
            <xsl:call-template name="inferQuery">
                <xsl:with-param name="call-query" select="call-query"/>
                <xsl:with-param name="recursiveIndex" select="$recursiveIndex"/>
                <xsl:with-param name="iterativeIndex" select="$iterativeIndex"/>
            </xsl:call-template>

            <!-- and we buid the query info array for the operation -->
            <xsl:text>
        $</xsl:text><xsl:value-of select="$opName"/><xsl:text> = array(</xsl:text>
            <xsl:text>
                    "inputFormat" => $</xsl:text><xsl:value-of select="$queryInfoVarPrefix"/><xsl:text>_input_format,
                    "outputFormat" => $</xsl:text><xsl:value-of select="$queryInfoVarPrefix"/><xsl:text>_output_format,
                    "sql" => $</xsl:text><xsl:value-of select="$queryInfoVarPrefix"/><xsl:text>_sql,
                    "inputMapping" => $</xsl:text><xsl:value-of select="$queryInfoVarPrefix"/><xsl:text>_input_mapping);
            </xsl:text>
        
        <xsl:text>
        // ------------finished queries for </xsl:text><xsl:value-of select="$opName"/><xsl:text>--------------
        </xsl:text>
        </xsl:for-each>

        <xsl:text>

        // building the operations array

        $operations = array(</xsl:text>
        
        <!-- iterate through each operation-->
        <xsl:for-each select="operation">
            <xsl:variable name="opName" select="@name"/>
            <xsl:text>"</xsl:text><xsl:value-of select="$opName"/><xsl:text>" => $</xsl:text>
                            <xsl:value-of select="$opName"/>

            <!--finishing up work for array -->
            <xsl:choose>
                <xsl:when test="position()=last()">
                    <xsl:text>);</xsl:text>
                </xsl:when>
                <xsl:otherwise>
                    <xsl:text>, 
                    </xsl:text>
                </xsl:otherwise>
            </xsl:choose>
        </xsl:for-each>
        <xsl:text>

        // create the DataService object and reply
        $ds = new DataService(array("operations" => $operations,
                              "config" => $config,
                              "serviceName" => "</xsl:text><xsl:value-of select="$serviceName"/><xsl:text>"));
        $ds->reply();
        </xsl:text>

        <!-- close the php tag -->
<xsl:text>
?&gt;
</xsl:text>

    </xsl:template>

    <!-- build the config property array -->
    <xsl:template name="buildConfig">
        <xsl:param name="config"/>

        <xsl:text>
        // building the config array

        $config = array("db" => "mysql", // change this to your db engine name </xsl:text>

        <xsl:variable name="username" select="$config/property[@name='org.wso2.ws.dataservice.user']"/>
        <xsl:variable name="password" select="$config/property[@name='org.wso2.ws.dataservice.password']"/>

        <xsl:choose>
            <xsl:when test="$username">
                <xsl:text>
                    "username" => "</xsl:text><xsl:value-of select="$username"/><xsl:text>", </xsl:text>
            </xsl:when>
            <xsl:otherwise>
                <xsl:text>
                    "username" => "your database user name", // change this to your db user name</xsl:text>
            </xsl:otherwise>
        </xsl:choose>

        <xsl:choose>
            <xsl:when test="$password">
                <xsl:text>
                    "password" => "</xsl:text><xsl:value-of select="$password"/><xsl:text>", </xsl:text>
            </xsl:when>
            <xsl:otherwise>
                <xsl:text>
                    "password" => "your database password", // change this to your db password</xsl:text>
            </xsl:otherwise>
        </xsl:choose>
        <xsl:text>
                    "dbname" => "your database name", // change this to your db name</xsl:text>
        <xsl:text>
                    "dbhost" => "your database host"); // change this to your db host</xsl:text>
    </xsl:template>

    <!-- this will generate the variables for parameters related to the query -->
    <xsl:template name="inferQuery">
        <xsl:param name="call-query"/>
        <xsl:param name="recursiveIndex"/>
        <xsl:param name="iterativeIndex"/>

        <xsl:variable name="queryId" select="$call-query/@href"/>
        <!-- the prefix related to query made variables -->
        <xsl:variable name="queryInfoVarPrefix">
            <xsl:call-template name="generateQueryInfoVarPrefix">
                <xsl:with-param name="queryId" select="$queryId"/>
                <xsl:with-param name="recursiveIndex" select="$recursiveIndex"/>
                <xsl:with-param name="iterativeIndex" select="$iterativeIndex"/>
            </xsl:call-template>
        </xsl:variable>
        <!-- query element -->
        <xsl:variable name="query" select="/data/query[@id=$queryId]"/>
        
        <!-- generate the input format for the query -->
        <xsl:call-template name="inferInputFormat">
            <xsl:with-param name="query" select="$query"/>
            <xsl:with-param name="recursiveIndex" select="$recursiveIndex"/>
            <xsl:with-param name="iterativeIndex" select="$iterativeIndex"/>
        </xsl:call-template>

        <!-- generate the output format for the query -->
        <xsl:call-template name="inferOutputFormat">
            <xsl:with-param name="query" select="$query"/>
            <xsl:with-param name="recursiveIndex" select="$recursiveIndex"/>
            <xsl:with-param name="iterativeIndex" select="$iterativeIndex"/>
        </xsl:call-template>

        <!-- generate the sql for the query -->
        <xsl:call-template name="inferSql">
            <xsl:with-param name="query" select="$query"/>
            <xsl:with-param name="recursiveIndex" select="$recursiveIndex"/>
            <xsl:with-param name="iterativeIndex" select="$iterativeIndex"/>
        </xsl:call-template>
        
        <!-- generate the input mapping for the query -->
        <xsl:call-template name="inferInputMapping">
            <xsl:with-param name="query" select="$query"/>
            <xsl:with-param name="call-query" select="$call-query"/>
            <xsl:with-param name="recursiveIndex" select="$recursiveIndex"/>
            <xsl:with-param name="iterativeIndex" select="$iterativeIndex"/>
        </xsl:call-template>
    </xsl:template>

    <!-- this wil generate the input_format variable for the query -->
    <xsl:template name="inferInputFormat">
        <xsl:param name="query"/>
        <xsl:param name="recursiveIndex"/>
        <xsl:param name="iterativeIndex"/>

        <!-- the prefix related to query made variables -->
        <xsl:variable name="queryId" select="$query/@id"/>
        <xsl:variable name="queryInfoVarPrefix">
            <xsl:call-template name="generateQueryInfoVarPrefix">
                <xsl:with-param name="queryId" select="$queryId"/>
                <xsl:with-param name="recursiveIndex" select="$recursiveIndex"/>
                <xsl:with-param name="iterativeIndex" select="$iterativeIndex"/>
            </xsl:call-template>
        </xsl:variable>
  
        <xsl:text>
        // building the input format for the </xsl:text><xsl:value-of select="$queryId"/><xsl:text>
        </xsl:text>

        <xsl:choose>
            <xsl:when test="count($query/param)=0">
                <!-- if no input param available we simple set it NULL -->
                <xsl:text>
        $</xsl:text><xsl:value-of select="$queryInfoVarPrefix"/><xsl:text>_input_format =  NULL;</xsl:text>
            </xsl:when>
            <xsl:otherwise>
                <xsl:text>
        $</xsl:text><xsl:value-of select="$queryInfoVarPrefix"/><xsl:text>_input_format = array(</xsl:text>
                
                <!-- iterate through each param in the query-->
                <xsl:for-each select="$query/param">
                    <xsl:variable name="paramName" select="@name"/>
                    <xsl:variable name="paramType" select="@sqlType"/>
                    <xsl:text>"</xsl:text><xsl:value-of select="$paramName"/><xsl:text>" => "</xsl:text>
                                    <xsl:value-of select="$paramType"/><xsl:text>"</xsl:text>
              
                    <!--finishing up work for array -->
                    <xsl:choose>
                        <xsl:when test="position()=last()">
                            <xsl:text>);</xsl:text>
                        </xsl:when>
                        <xsl:otherwise>
                            <xsl:text>, 
                            </xsl:text>
                        </xsl:otherwise>
                    </xsl:choose>
                </xsl:for-each>
            </xsl:otherwise>
        </xsl:choose>
        
        <!-- new line at the end -->
        <xsl:text>
        </xsl:text>

    </xsl:template>

    <!-- this wil generate the output_format variable for the query -->
    <xsl:template name="inferOutputFormat">
        <xsl:param name="query"/>
        <xsl:param name="recursiveIndex"/>
        <xsl:param name="iterativeIndex"/>

        <!-- the prefix related to query made variables -->
        <xsl:variable name="queryId" select="$query/@id"/>
        <xsl:variable name="queryInfoVarPrefix">
            <xsl:call-template name="generateQueryInfoVarPrefix">
                <xsl:with-param name="queryId" select="$queryId"/>
                <xsl:with-param name="recursiveIndex" select="$recursiveIndex"/>
                <xsl:with-param name="iterativeIndex" select="$iterativeIndex"/>
            </xsl:call-template>
        </xsl:variable>

        <!-- generate the output element mapping for the query -->
        <xsl:call-template name="inferOutputElements">
            <xsl:with-param name="queryId" select="$queryId"/>
            <xsl:with-param name="result" select="$query/result"/>
            <xsl:with-param name="queryInfoVarPrefix" select="$queryInfoVarPrefix"/>
            <xsl:with-param name="recursiveIndex" select="$recursiveIndex"/>
            <xsl:with-param name="iterativeIndex" select="$iterativeIndex"/>
        </xsl:call-template>

        <!-- generate the output attributes mapping for the query -->
        <xsl:call-template name="inferOutputAttributes">
            <xsl:with-param name="queryId" select="$queryId"/>
            <xsl:with-param name="result" select="$query/result"/>
            <xsl:with-param name="queryInfoVarPrefix" select="$queryInfoVarPrefix"/>
            <xsl:with-param name="recursiveIndex" select="$recursiveIndex"/>
            <xsl:with-param name="iterativeIndex" select="$iterativeIndex"/>
        </xsl:call-template>

        <!-- generate the output texts mapping for the query -->
        <xsl:call-template name="inferOutputTexts">
            <xsl:with-param name="queryId" select="$queryId"/>
            <xsl:with-param name="result" select="$query/result"/>
            <xsl:with-param name="queryInfoVarPrefix" select="$queryInfoVarPrefix"/>
            <xsl:with-param name="recursiveIndex" select="$recursiveIndex"/>
            <xsl:with-param name="iterativeIndex" select="$iterativeIndex"/>
        </xsl:call-template>

        <!-- generate the output queries mapping for the query -->
        <xsl:call-template name="inferOutputQueries">
            <xsl:with-param name="queryId" select="$queryId"/>
            <xsl:with-param name="result" select="$query/result"/>
            <xsl:with-param name="queryInfoVarPrefix" select="$queryInfoVarPrefix"/>
            <xsl:with-param name="recursiveIndex" select="$recursiveIndex"/>
            <xsl:with-param name="iterativeIndex" select="$iterativeIndex"/>
        </xsl:call-template>

        <!-- generte the elements order for the query -->
        <xsl:call-template name="inferElementsOrder">
            <xsl:with-param name="queryId" select="$queryId"/>
            <xsl:with-param name="result" select="$query/result"/>
            <xsl:with-param name="queryInfoVarPrefix" select="$queryInfoVarPrefix"/>
            <xsl:with-param name="recursiveIndex" select="$recursiveIndex"/>
            <xsl:with-param name="iterativeIndex" select="$iterativeIndex"/>
        </xsl:call-template>
  
        <xsl:text>
        // building the output format for the </xsl:text><xsl:value-of select="$queryId"/><xsl:text>
        </xsl:text>

        <xsl:variable name="resultElement" select="$query/result/@element"/>
        <xsl:variable name="rowElement" select="$query/result/@rowName"/>

        <xsl:text>
        $</xsl:text><xsl:value-of select="$queryInfoVarPrefix"/><xsl:text>_output_format =  array(
            "resultElement" => "</xsl:text><xsl:value-of select="$resultElement"/><xsl:text>",
            "rowElement" => "</xsl:text><xsl:value-of select="$rowElement"/><xsl:text>",
            </xsl:text>
        <xsl:if test="$query/result/@useNil">
            <xsl:text>"useNil" => "</xsl:text><xsl:value-of select="$query/result/@useNil"/><xsl:text>",
            </xsl:text>
        </xsl:if>
        <xsl:if test="$query/result/@defaultNamespace">
            <xsl:text>"defaultNamespace" => "</xsl:text><xsl:value-of select="$query/result/@defaultNamespace"/><xsl:text>",
            </xsl:text>
        </xsl:if>
        <xsl:if test="$query/result/@columnDefault">
            <xsl:text>"columnDefault" => "</xsl:text><xsl:value-of select="$query/result/@columnDefault"/><xsl:text>",
            </xsl:text>
        </xsl:if>
        <xsl:if test="$query/result/element">
            <xsl:text>"elements" => $</xsl:text><xsl:value-of select="$queryInfoVarPrefix"/>_elements<xsl:text>,
            </xsl:text>
        </xsl:if>
        <xsl:if test="$query/result/attribute">
            <xsl:text>"attributes" => $</xsl:text><xsl:value-of select="$queryInfoVarPrefix"/>_attributes<xsl:text>,
            </xsl:text>
        </xsl:if>
        <xsl:if test="$query/result/text">
            <xsl:text>"texts" => $</xsl:text><xsl:value-of select="$queryInfoVarPrefix"/>_texts<xsl:text>,
            </xsl:text>
        </xsl:if>
        <xsl:if test="$query/result/call-query">
            <xsl:text>"queries" => $</xsl:text><xsl:value-of select="$queryInfoVarPrefix"/>_queries<xsl:text>,
            </xsl:text>
        </xsl:if>
            <xsl:text>"elementsOrder" => $</xsl:text><xsl:value-of select="$queryInfoVarPrefix"/>_elements_order<xsl:text>);
        </xsl:text>

        <!-- new line at the end -->
        <xsl:text>
        </xsl:text>


    </xsl:template>

    <!-- this wil generate the sql variable for the query -->
    <xsl:template name="inferSql">
        <xsl:param name="query"/>
        <xsl:param name="recursiveIndex"/>
        <xsl:param name="iterativeIndex"/>

        <!-- the prefix related to query made variables -->
        <xsl:variable name="queryId" select="$query/@id"/>
        <xsl:variable name="queryInfoVarPrefix">
            <xsl:call-template name="generateQueryInfoVarPrefix">
                <xsl:with-param name="queryId" select="$queryId"/>
                <xsl:with-param name="recursiveIndex" select="$recursiveIndex"/>
                <xsl:with-param name="iterativeIndex" select="$iterativeIndex"/>
            </xsl:call-template>
        </xsl:variable>
        <xsl:variable name="sql" select="$query/sql"/>
  
        <xsl:text>
        // building the sql for the </xsl:text><xsl:value-of select="$queryId"/><xsl:text>
        </xsl:text>

        <xsl:text>
        $</xsl:text><xsl:value-of select="$queryInfoVarPrefix"/><xsl:text>_sql = "</xsl:text><xsl:value-of select="translate($sql,'&#xA;', ' ')"/><xsl:text>";</xsl:text>
        
        <!-- new line at the end -->
        <xsl:text>
        </xsl:text>

    </xsl:template>

    <!-- this wil generate the input mapping variable for the query -->
    <xsl:template name="inferInputMapping">
        <xsl:param name="query"/>
        <xsl:param name="call-query"/>
        <xsl:param name="recursiveIndex"/>
        <xsl:param name="iterativeIndex"/>

        <!-- the prefix related to query made variables -->
        <xsl:variable name="queryId" select="$query/@id"/>
        <xsl:variable name="queryInfoVarPrefix">
            <xsl:call-template name="generateQueryInfoVarPrefix">
                <xsl:with-param name="queryId" select="$queryId"/>
                <xsl:with-param name="recursiveIndex" select="$recursiveIndex"/>
                <xsl:with-param name="iterativeIndex" select="$iterativeIndex"/>
            </xsl:call-template>
        </xsl:variable>
  
        <xsl:text>
        // building the input mapping for the </xsl:text><xsl:value-of select="$queryId"/><xsl:text>
        </xsl:text>

        <xsl:choose>
            <xsl:when test="count($call-query/with-param)=0">
                <!-- if no input param available we simple set it NULL -->
                <xsl:text>
        $</xsl:text><xsl:value-of select="$queryInfoVarPrefix"/><xsl:text>_input_mapping =  NULL;</xsl:text>
            </xsl:when>
            <xsl:otherwise>
                <xsl:text>
        $</xsl:text><xsl:value-of select="$queryInfoVarPrefix"/><xsl:text>_input_mapping = array(</xsl:text>
                
                <!-- iterate through each param in the query-->
                <xsl:for-each select="$call-query/with-param">
                    <xsl:variable name="paramName" select="@name"/>
                    <xsl:variable name="paramMappedName" select="@query-param"/>
                    <xsl:text>"</xsl:text><xsl:value-of select="$paramName"/><xsl:text>" => "</xsl:text>
                                    <xsl:value-of select="$paramMappedName"/><xsl:text>"</xsl:text>
              
                    <!--finishing up work for array -->
                    <xsl:choose>
                        <xsl:when test="position()=last()">
                            <xsl:text>);</xsl:text>
                        </xsl:when>
                        <xsl:otherwise>
                            <xsl:text>, 
                            </xsl:text>
                        </xsl:otherwise>
                    </xsl:choose>
                </xsl:for-each>
            </xsl:otherwise>
        </xsl:choose>
        
        <!-- new line at the end -->
        <xsl:text>
        </xsl:text>

    </xsl:template>

    <!-- this wil generate the elements for the output_format variable of the query -->
    <xsl:template name="inferOutputElements">
        <xsl:param name="queryId"/>
        <xsl:param name="result"/>
        <xsl:param name="queryInfoVarPrefix"/><!-- the prefix related to query made variables -->

        <xsl:choose>
            <xsl:when test="count($result/element)=0">
                <!-- if no input param available we simple doesn't set it -->
            </xsl:when>
            <xsl:otherwise>

                <xsl:text>
        // building the output elements for the </xsl:text><xsl:value-of select="$queryId"/><xsl:text>
                </xsl:text>

                <xsl:text>
        $</xsl:text><xsl:value-of select="$queryInfoVarPrefix"/><xsl:text>_elements = array(</xsl:text>
                
                <!-- iterate through each param in the query-->
                <xsl:for-each select="$result/element">
                    <xsl:variable name="elementName" select="@name"/>
                    <xsl:variable name="elementValue">
                        <xsl:choose>
                            <xsl:when test="@column">
                                <xsl:text>"</xsl:text><xsl:value-of select="@column"/><xsl:text>"</xsl:text>
                            </xsl:when>
                            <xsl:when test="@param">
                                <xsl:text>array("param" => "</xsl:text><xsl:value-of select="@param"/><xsl:text>")</xsl:text>
                            </xsl:when>
                            <xsl:when test="@value">
                                <xsl:text>array("value" => "</xsl:text><xsl:value-of select="@value"/><xsl:text>")</xsl:text>
                            </xsl:when>
                        </xsl:choose>
                    </xsl:variable>
                    <xsl:variable name="paramMappedName" select="@query-param"/>
                    <xsl:text>"</xsl:text><xsl:value-of select="$elementName"/><xsl:text>" => </xsl:text>
                                    <xsl:value-of select="$elementValue"/>
              
                    <!--finishing up work for array -->
                    <xsl:choose>
                        <xsl:when test="position()=last()">
                            <xsl:text>);</xsl:text>
                        </xsl:when>
                        <xsl:otherwise>
                            <xsl:text>, 
                            </xsl:text>
                        </xsl:otherwise>
                    </xsl:choose>
                </xsl:for-each>
        
                <!-- new line at the end -->
                <xsl:text>
                </xsl:text>
            </xsl:otherwise>
        </xsl:choose>

    </xsl:template>
 
    <!-- this wil generate the attributes for the output_format variable of the query -->
    <xsl:template name="inferOutputAttributes">
        <xsl:param name="queryId"/>
        <xsl:param name="result"/>
        <xsl:param name="queryInfoVarPrefix"/><!-- the prefix related to query made variables -->
        <xsl:param name="recursiveIndex"/>
        <xsl:param name="iterativeIndex"/>

        <xsl:choose>
            <xsl:when test="count($result/attribute)=0">
                <!-- if no input param available we simple set it NULL -->
            </xsl:when>
            <xsl:otherwise>

                <xsl:text>
        // building the output attributes for the </xsl:text><xsl:value-of select="$queryId"/><xsl:text>
                </xsl:text>

                <xsl:text>
        $</xsl:text><xsl:value-of select="$queryInfoVarPrefix"/><xsl:text>_attributes = array(</xsl:text>
                
                <!-- iterate through each param in the query-->
                <xsl:for-each select="$result/attribute">
                    <xsl:variable name="attributeName" select="@name"/>
                    <xsl:variable name="attributeValue">
                        <xsl:choose>
                            <xsl:when test="@column">
                                <xsl:text>"</xsl:text><xsl:value-of select="@column"/><xsl:text>"</xsl:text>
                            </xsl:when>
                            <xsl:when test="@param">
                                <xsl:text>array("param" => "</xsl:text><xsl:value-of select="@param"/><xsl:text>")</xsl:text>
                            </xsl:when>
                            <xsl:when test="@value">
                                <xsl:text>array("value" => "</xsl:text><xsl:value-of select="@value"/><xsl:text>")</xsl:text>
                            </xsl:when>
                        </xsl:choose>
                    </xsl:variable>
                    <xsl:variable name="paramMappedName" select="@query-param"/>
                    <xsl:text>"</xsl:text><xsl:value-of select="$attributeName"/><xsl:text>" => </xsl:text>
                                    <xsl:value-of select="$attributeValue"/>
              
                    <!--finishing up work for array -->
                    <xsl:choose>
                        <xsl:when test="position()=last()">
                            <xsl:text>);</xsl:text>
                        </xsl:when>
                        <xsl:otherwise>
                            <xsl:text>, 
                            </xsl:text>
                        </xsl:otherwise>
                    </xsl:choose>
                </xsl:for-each>
        
                <!-- new line at the end -->
                <xsl:text>
                </xsl:text>
            </xsl:otherwise>
        </xsl:choose>

    </xsl:template>
 
    <!-- this wil generate the texts for the output_format variable of the query -->
    <xsl:template name="inferOutputTexts">
        <xsl:param name="queryId"/>
        <xsl:param name="result"/>
        <xsl:param name="queryInfoVarPrefix"/><!-- the prefix related to query made variables -->
        <xsl:param name="recursiveIndex"/>
        <xsl:param name="iterativeIndex"/>

        <xsl:choose>
            <xsl:when test="count($result/text)=0">
                <!-- if no input param available we simple set it NULL -->
            </xsl:when>
            <xsl:otherwise>

                <xsl:text>
        // building the output texts for the </xsl:text><xsl:value-of select="$queryId"/><xsl:text>
                </xsl:text>

                <xsl:text>
        $</xsl:text><xsl:value-of select="$queryInfoVarPrefix"/><xsl:text>_texts = array(</xsl:text>
                
                <!-- iterate through each param in the query-->
                <xsl:for-each select="$result/text">
                    <xsl:variable name="textName">
                        <!-- here we don't have a way to keep the text name, 
                            so we use text# pattern to the name-->
                        <xsl:text>text</xsl:text><xsl:value-of select="position()"/>
                    </xsl:variable>
                    <xsl:variable name="textValue">
                        <xsl:choose>
                            <xsl:when test="@column">
                                <xsl:text>"</xsl:text><xsl:value-of select="@column"/><xsl:text>"</xsl:text>
                            </xsl:when>
                            <xsl:when test="@param">
                                <xsl:text>array("param" => "</xsl:text><xsl:value-of select="@param"/><xsl:text>")</xsl:text>
                            </xsl:when>
                            <xsl:when test="@value">
                                <xsl:text>array("value" => "</xsl:text><xsl:value-of select="@value"/><xsl:text>")</xsl:text>
                            </xsl:when>
                        </xsl:choose>
                    </xsl:variable>
                    <xsl:variable name="paramMappedName" select="@query-param"/>
                    <xsl:text>"</xsl:text><xsl:value-of select="$textName"/><xsl:text>" => </xsl:text>
                                    <xsl:value-of select="$textValue"/>
              
                    <!--finishing up work for array -->
                    <xsl:choose>
                        <xsl:when test="position()=last()">
                            <xsl:text>);</xsl:text>
                        </xsl:when>
                        <xsl:otherwise>
                            <xsl:text>, 
                            </xsl:text>
                        </xsl:otherwise>
                    </xsl:choose>
                </xsl:for-each>
        
                <!-- new line at the end -->
                <xsl:text>
                </xsl:text>
            </xsl:otherwise>
        </xsl:choose>

    </xsl:template>

 
    <!-- this wil generate the attributes for the output_format variable of the query -->
    <xsl:template name="inferOutputQueries">
        <xsl:param name="queryId"/>
        <xsl:param name="result"/>
        <xsl:param name="queryInfoVarPrefix"/><!-- the prefix related to query made variables -->
        <xsl:param name="recursiveIndex"/>
        <xsl:param name="iterativeIndex"/>

        <!-- update the recursive index -->
        <xsl:variable name="newRecursiveIndex">
            <xsl:choose>
                <xsl:when test="$recursiveIndex=''">
                    <xsl:text>1</xsl:text> <!-- starting from the 1 -->
                </xsl:when>
                <xsl:otherwise>
                    <xsl:value-of select="$recursiveIndex + 1"/>
                </xsl:otherwise>
            </xsl:choose>
        </xsl:variable>

        <!-- we calls the inner queries recursively -->
        <xsl:for-each select="$result/call-query">
            <xsl:variable name="newQueryId" select="@href"/>
            <xsl:variable name="newIterativeIndex" select="position()"/>
            <xsl:variable name="newQueryInfoVarPrefix">
                <xsl:call-template name="generateQueryInfoVarPrefix">
                    <xsl:with-param name="queryId" select="$newQueryId"/>
                    <xsl:with-param name="recursiveIndex" select="$newRecursiveIndex"/>
                    <xsl:with-param name="iterativeIndex" select="$newIterativeIndex"/>
                </xsl:call-template>
            </xsl:variable>
            
            <xsl:text>
        // ------- building the query </xsl:text><xsl:value-of select="$newQueryId"/><xsl:text> called from query </xsl:text><xsl:value-of select="$queryId"/><xsl:text> ------
        </xsl:text>

            <!-- for php queries are meaningful only when they are called.. so
                 here we treadted call-query is part of query -->
            <xsl:call-template name="inferQuery">
                <xsl:with-param name="call-query" select="."/>
                <xsl:with-param name="recursiveIndex" select="$newRecursiveIndex"/>
                <xsl:with-param name="iterativeIndex" select="$newIterativeIndex"/>
            </xsl:call-template>

            <!-- and we buid the query info array for the operation -->
            <xsl:text>
        $</xsl:text><xsl:value-of select="$newQueryInfoVarPrefix"/><xsl:text>_query = array(</xsl:text>
            <xsl:text>
                    "inputFormat" => $</xsl:text><xsl:value-of select="$newQueryInfoVarPrefix"/><xsl:text>_input_format,
                    "outputFormat" => $</xsl:text><xsl:value-of select="$newQueryInfoVarPrefix"/><xsl:text>_output_format,
                    "sql" => $</xsl:text><xsl:value-of select="$newQueryInfoVarPrefix"/><xsl:text>_sql,
                    "inputMapping" => $</xsl:text><xsl:value-of select="$newQueryInfoVarPrefix"/><xsl:text>_input_mapping);

            </xsl:text>

            <xsl:text>
        // ------- finished the query </xsl:text><xsl:value-of select="$newQueryId"/><xsl:text> called from query </xsl:text><xsl:value-of select="$queryId"/><xsl:text> -------
        </xsl:text>
        </xsl:for-each>

        <xsl:choose>
            <xsl:when test="count($result/call-query)=0">
                <!-- if no input param available we simple set it NULL -->
            </xsl:when>
            <xsl:otherwise>

                <xsl:text>
        // building the output queries for the </xsl:text><xsl:value-of select="$queryId"/><xsl:text>
                </xsl:text>

                <xsl:text>
        $</xsl:text><xsl:value-of select="$queryInfoVarPrefix"/><xsl:text>_queries = array(</xsl:text>
                
                <!-- iterate through each param in the query-->
                <xsl:for-each select="$result/call-query">
                    <xsl:variable name="queryName">
                        <!-- simmilar to texts we keep query# structure-->
                        <xsl:text>query</xsl:text><xsl:value-of select="position()"/>
                    </xsl:variable>
                    <xsl:variable name="newQueryId" select="@href"/>
                    <xsl:variable name="newIterativeIndex" select="position()"/>
                    <xsl:variable name="newQueryInfoVarPrefix">
                        <xsl:call-template name="generateQueryInfoVarPrefix">
                            <xsl:with-param name="queryId" select="$newQueryId"/>
                            <xsl:with-param name="recursiveIndex" select="$newRecursiveIndex"/>
                            <xsl:with-param name="iterativeIndex" select="$newIterativeIndex"/>
                        </xsl:call-template>
                    </xsl:variable>
                    <xsl:variable name="queryValue">
                        <xsl:text>$</xsl:text><xsl:value-of select="$newQueryInfoVarPrefix"/><xsl:text>_query</xsl:text>
                    </xsl:variable>
                    <xsl:variable name="paramMappedName" select="@query-param"/>
                    <xsl:text>"</xsl:text><xsl:value-of select="$queryName"/><xsl:text>" => </xsl:text>
                                    <xsl:value-of select="$queryValue"/>
              
                    <!--finishing up work for array -->
                    <xsl:choose>
                        <xsl:when test="position()=last()">
                            <xsl:text>);</xsl:text>
                        </xsl:when>
                        <xsl:otherwise>
                            <xsl:text>, 
                            </xsl:text>
                        </xsl:otherwise>
                    </xsl:choose>
                </xsl:for-each>
        
                <!-- new line at the end -->
                <xsl:text>
                </xsl:text>
            </xsl:otherwise>
        </xsl:choose>

    </xsl:template>

    <!-- this will generte the elements order for the query -->
    <xsl:template name="inferElementsOrder">
        <xsl:param name="queryId"/>
        <xsl:param name="result"/>
        <xsl:param name="queryInfoVarPrefix"/>
        <xsl:param name="recursiveIndex"/>
        <xsl:param name="iterativeIndex"/>


        <xsl:text>
        // building the output elements order for the </xsl:text><xsl:value-of select="$queryId"/><xsl:text>
        </xsl:text>

        <xsl:variable name="resultChilds" select="$result/child::*"/>
        <xsl:choose>
            <xsl:when test="count($resultChilds)=0">
                <xsl:text>
        $</xsl:text><xsl:value-of select="$queryInfoVarPrefix"/><xsl:text>_elements_order = NULL;</xsl:text>
            </xsl:when>

            <xsl:otherwise>
                <xsl:text>
        $</xsl:text><xsl:value-of select="$queryInfoVarPrefix"/><xsl:text>_elements_order = array(</xsl:text>

                <xsl:variable name="nextTextId"><xsl:text>1</xsl:text></xsl:variable>
                <xsl:variable name="nextNestedQueryId"><xsl:text>1</xsl:text></xsl:variable>
                
                <!-- call the inferNextResultElement to recursivly populate the elements -->
                <xsl:call-template name="inferNextResultElement">
                    <xsl:with-param name="currentElement" select="$resultChilds"/> <!-- we only pick of first of the set -->
                    <xsl:with-param name="nextTextId" select="$nextTextId"/>
                    <xsl:with-param name="nextNestedQueryId" select="$nextNestedQueryId"/>
                </xsl:call-template>
            </xsl:otherwise>
        </xsl:choose>
       
        <!-- new line at the end -->
        <xsl:text>
        </xsl:text>
    </xsl:template>

    <!-- template used by inferElementsOrder to recursively build up the entries -->
    <xsl:template name="inferNextResultElement">
        <xsl:param name="currentElement"/>
        <xsl:param name="nextTextId"/>
        <xsl:param name="nextNestedQueryId"/>

        <xsl:variable name="currentLocalName" select="local-name($currentElement)"/>
        <xsl:variable name="nextElementKey">
            <xsl:choose>
                <xsl:when test="$currentLocalName='element' or $currentLocalName='attribute'">
                    <xsl:value-of select="$currentElement/@name"/>
                </xsl:when>
                <xsl:when test="$currentLocalName='text'">
                    <xsl:text>text</xsl:text><xsl:value-of select="$nextTextId"/>
                </xsl:when>
                <xsl:when test="$currentLocalName='call-query'">
                    <xsl:text>query</xsl:text><xsl:value-of select="$nextNestedQueryId"/>
                </xsl:when>
            </xsl:choose>
        </xsl:variable>
        
        <!--print th current element key -->
        <xsl:text>"</xsl:text><xsl:value-of select="$nextElementKey"/><xsl:text>"</xsl:text>

        <!-- update the text and query ids -->
        <xsl:variable name="newNextTextId">
            <xsl:choose>
                <xsl:when test="$currentLocalName='text'">
                    <xsl:value-of select="$nextTextId +1"/>
                </xsl:when>
                <xsl:otherwise>
                    <xsl:value-of select="$nextTextId"/>
                </xsl:otherwise>
            </xsl:choose>
        </xsl:variable>

        <xsl:variable name="newNextNestedQueryId">
            <xsl:choose>
                <xsl:when test="$currentLocalName='call-query'">
                    <xsl:value-of select="$nextNestedQueryId +1"/>
                </xsl:when>
                <xsl:otherwise>
                    <xsl:value-of select="$nextNestedQueryId"/>
                </xsl:otherwise>
            </xsl:choose>
        </xsl:variable>
        
        <!-- go to the next element -->
        <xsl:variable name="nextElement" select="$currentElement/following-sibling::*"/>
        
        <!-- print the ending up lines and the recursive calls -->
        <xsl:choose>
            <xsl:when test="$nextElement">
                <!-- we have to for another step -->
                <!-- first print the , and the line break-->
                <xsl:text>,
                    </xsl:text>

                <!-- and the recursive call -->
                <xsl:call-template name="inferNextResultElement">
                    <xsl:with-param name="currentElement" select="$nextElement"/>
                    <xsl:with-param name="nextTextId" select="$newNextTextId"/>
                    <xsl:with-param name="nextNestedQueryId" select="$newNextNestedQueryId"/>
                </xsl:call-template>
            </xsl:when>
            <xsl:otherwise>
                <!-- just finish up the work -->
                <xsl:text>);</xsl:text>
            </xsl:otherwise>
        </xsl:choose>

    </xsl:template>
    
    <!-- this will generate the query info variable prefix $queryInfoVarPrefix -->
    <xsl:template name="generateQueryInfoVarPrefix">
        <xsl:param name="queryId"/>
        <xsl:param name="recursiveIndex"/>
        <xsl:param name="iterativeIndex"/>
        
        <xsl:choose>
            <xsl:when test="$recursiveIndex !='' or $iterativeIndex != ''">
                <xsl:value-of select="$queryId"/><xsl:text>_</xsl:text><xsl:value-of select="$recursiveIndex"/>
                <xsl:text>_</xsl:text><xsl:value-of select="$iterativeIndex"/>
            </xsl:when>
            <xsl:otherwise>
                <xsl:value-of select="$queryId"/>
            </xsl:otherwise>
        </xsl:choose>
    </xsl:template>
</xsl:stylesheet>
