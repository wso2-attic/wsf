<?xml version="1.0"?>
<xsl:stylesheet
        xmlns:xsl="http://www.w3.org/1999/XSL/Transform"
        version="1.0">
    <xsl:output method="xml" indent="yes"/>

    <xsl:template match="/">
        <xsl:apply-templates select="Map"/>
    </xsl:template>

    <xsl:template match="Map">
        <xsl:comment>
        /*
        * Copyright 2005,2006 WSO2, Inc. http://www.wso2.org
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
        </xsl:comment>
        <project default="build.archive">
             
            <xsl:attribute name="name">
            	<xsl:variable name="key" select="Entry[@key='serviceName']/@value" />
                <xsl:text><xsl:value-of select="$key" /></xsl:text>
                 <xsl:text>AARBuild</xsl:text>
            </xsl:attribute>

            <property name="projectName">
            	<xsl:attribute name="location">
            		<xsl:variable name="key" select="Entry[@key='serviceName']/@value" />
            		<xsl:text><xsl:value-of select="$key"/></xsl:text>
            	</xsl:attribute>
            </property>

            <xsl:comment>==================================</xsl:comment>
            <xsl:comment>        COMPILE ARCHIVE           </xsl:comment>
            <xsl:comment>==================================</xsl:comment>

            <target name="compile" description="compile the source ">
            	<xsl:comment> Compile the java code </xsl:comment>
            	<javac>
            		<xsl:attribute name="srcdir">
            			<xsl:variable name="key" select="Entry[@key='serviceName']/@value" />
            			<xsl:text>./<xsl:value-of select="$key"/></xsl:text>
            		</xsl:attribute>
            		<xsl:attribute name="destdir">
            			<xsl:variable name="key" select="Entry[@key='serviceName']/@value" />
            			<xsl:text>./<xsl:value-of select="$key"/></xsl:text>
            		</xsl:attribute>
            	</javac>
            </target>

            <xsl:comment>==================================</xsl:comment>
            <xsl:comment>         BUILD ARCHIVE            </xsl:comment>
            <xsl:comment>==================================</xsl:comment>

            <target name="build.archive" depends="clean, compile" >
                <zip destfile="./target/${projectName}.aar" basedir="./${projectName}" >
                    <xsl:attribute name="destfile">
                    	<xsl:variable name="key" select="Entry[@key='serviceName']/@value" />
                    	<xsl:text>./target/<xsl:value-of select="$key"/></xsl:text>
                    	<xsl:text>.aar</xsl:text>
                    </xsl:attribute>
            		<xsl:attribute name="basedir">
            			<xsl:variable name="key" select="Entry[@key='serviceName']/@value" />
            			<xsl:text>./<xsl:value-of select="$key"/></xsl:text>
            		</xsl:attribute>
                </zip>
            </target>

            <xsl:comment>==================================</xsl:comment>
            <xsl:comment>             CLEAN                </xsl:comment>
            <xsl:comment>==================================</xsl:comment>

            <target name="clean">
                <delete>
                	<xsl:attribute name="file">
                		<xsl:variable name="key" select="Entry[@key='serviceName']/@value" />
                		<xsl:text>./target/<xsl:value-of select="$key"/></xsl:text>
                    	<xsl:text>.aar</xsl:text>
                	</xsl:attribute>
                </delete>
            </target>

        </project>

    </xsl:template>
</xsl:stylesheet>

