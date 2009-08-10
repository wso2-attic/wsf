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
    <xsl:output method="xml" indent="yes" omit-xml-declaration="no"/>
    <xsl:template match="/class">
    <xsl:variable name="callbackName"><xsl:value-of select="@callbackName"/></xsl:variable>
    <xsl:variable name="isSync"><xsl:value-of select="@isSync"/></xsl:variable>
    <xsl:variable name="isServer"><xsl:value-of select="@isServer"/></xsl:variable>
    <xsl:variable name="isAsync"><xsl:value-of select="@isAsync"/></xsl:variable>
    <xsl:variable name="soapVersion"><xsl:value-of select="@soap-version"/></xsl:variable>
    <xsl:variable name="method-prefix"><xsl:value-of select="@prefix"/></xsl:variable>
    <xsl:variable name="qname"><xsl:value-of select="@qname"/></xsl:variable>
    <xsl:variable name="servicename"><xsl:value-of select="@servicename"/></xsl:variable>
    <xsl:variable name="caps_name"><xsl:value-of select="@caps-name"/></xsl:variable>
 <VisualStudioProject
	ProjectType="Visual C++"
	Version="8.00"
	Name="client"
	RootNamespace="client"
	Keyword="Win32Proj"
	>
  <Platforms>
    <Platform Name="Win32"/>
  </Platforms>
  <ToolFiles>
  </ToolFiles>
  <Configurations>
    <Configuration
	Name="Debug|Win32"
	OutputDirectory="$(SolutionDir)$(ConfigurationName)"
	IntermediateDirectory="$(ConfigurationName)"
	ConfigurationType="1"
	CharacterSet="1">
      <Tool Name="VCPreBuildEventTool"/>
      <Tool Name="VCCustomBuildTool"/>
      <Tool Name="VCXMLDataGeneratorTool"/>
      <Tool Name="VCWebServiceProxyGeneratorTool"/>
      <Tool Name="VCMIDLTool" />
      <Tool Name="VCCLCompilerTool"
		Optimization="0"
		AdditionalIncludeDirectories="."
		PreprocessorDefinitions="WIN32;_DEBUG;_CONSOLE;AXIS2_DECLARE_EXPORT"
		MinimalRebuild="true"
		BasicRuntimeChecks="3"
		RuntimeLibrary="3"
		UsePrecompiledHeader="0"
		WarningLevel="3"
		Detect64BitPortabilityProblems="true"
		DebugInformationFormat="4"
		/>
      <Tool Name="VCManagedResourceCompilerTool"/>
      <Tool Name="VCResourceCompilerTool" />
      <Tool Name="VCPreLinkEventTool" />
      <Tool Name="VCLinkerTool"
	AdditionalDependencies="wso2_wsf.lib axiom.lib axis2_engine.lib axutil.lib"
	LinkIncremental="2"
	GenerateDebugInformation="true"
	SubSystem="1"
	TargetMachine="1"/>
      <Tool Name="VCALinkTool"/>
      <Tool Name="VCManifestTool"/>
      <Tool Name="VCXDCMakeTool"/>
      <Tool Name="VCBscMakeTool"/>
      <Tool Name="VCFxCopTool"/>
      <Tool Name="VCAppVerifierTool"/>
      <Tool Name="VCWebDeploymentTool"/>
      <Tool Name="VCPostBuildEventTool"/>
    </Configuration>
    <Configuration
	Name="Release|Win32"
	OutputDirectory="$(SolutionDir)$(ConfigurationName)"
	IntermediateDirectory="$(ConfigurationName)"
	ConfigurationType="1"
	CharacterSet="1"
	WholeProgramOptimization="1">
      <Tool Name="VCPreBuildEventTool"/>
      <Tool Name="VCCustomBuildTool"/>
      <Tool Name="VCXMLDataGeneratorTool"/>
      <Tool Name="VCWebServiceProxyGeneratorTool"/>
      <Tool Name="VCMIDLTool"/>
      <Tool
	Name="VCCLCompilerTool"
	PreprocessorDefinitions="WIN32;NDEBUG;_CONSOLE"
	RuntimeLibrary="2"
	UsePrecompiledHeader="0"
	WarningLevel="3"
	Detect64BitPortabilityProblems="true"
	DebugInformationFormat="3"/>
      <Tool Name="VCManagedResourceCompilerTool"/>
      <Tool Name="VCResourceCompilerTool"/>
      <Tool Name="VCPreLinkEventTool"/>
      <Tool
	Name="VCLinkerTool"
	LinkIncremental="1"
	GenerateDebugInformation="true"
	SubSystem="1"
	OptimizeReferences="2"
	EnableCOMDATFolding="2"
	TargetMachine="1"/>
      <Tool Name="VCALinkTool"/>
      <Tool Name="VCManifestTool"/>
      <Tool Name="VCXDCMakeTool"/>
      <Tool Name="VCBscMakeTool"/>
      <Tool Name="VCFxCopTool"/>
      <Tool Name="VCAppVerifierTool"/>
      <Tool Name="VCWebDeploymentTool"/>
      <Tool Name="VCPostBuildEventTool"/>
    </Configuration>
  </Configurations>
  <References>
  </References>
  <Files>
    <Filter Name="Source Files"
	    Filter="cpp;c;cc;cxx;def;odl;idl;hpj;bat;asm;asmx">
        <xsl:if test="$isServer='0'">
             <File>
                <xsl:attribute name="RelativePath">.\<xsl:value-of select="@name"/>.cpp</xsl:attribute>
             </File>
        </xsl:if>
        <xsl:if test="$isServer='1'">
             <File>
                <xsl:attribute name="RelativePath">.\<xsl:value-of select="@servicename"/>.cpp</xsl:attribute>
             </File>
        </xsl:if>
        <xsl:for-each select="method">
            <xsl:for-each select="input/param[@type!='' and @ours ]">
            <xsl:variable name="inputtype" select="substring-after(@type,'::')"/>
                 <File>
                     <xsl:attribute name="RelativePath">.\<xsl:value-of select='$inputtype'/>.cpp</xsl:attribute>
                </File>
           </xsl:for-each>
            <xsl:for-each select="output/param[@type!='' and @ours]">
             <xsl:variable name="outputtype1" select="substring-after(@type,'::')"/>
                    <File>
                     <xsl:attribute name="RelativePath">.\<xsl:value-of select="$outputtype1"/>.cpp</xsl:attribute>
                </File>
           </xsl:for-each>
             <xsl:for-each select="fault/param[@type!='']">
                <xsl:variable name="faulttype" select="substring-after(@type,'::')"/>
                    <File>
                     <xsl:attribute name="RelativePath">.\<xsl:value-of select="$faulttype"/>.cpp</xsl:attribute>
                    </File>
            </xsl:for-each>
        </xsl:for-each>
    </Filter>
    <Filter Name="Header Files"
	    Filter="h;hpp;hxx;hm;inl;inc;xsd">
        <xsl:if test="$isServer='0'">
             <File>
                <xsl:attribute name="RelativePath">.\<xsl:value-of select="@name"/>.h</xsl:attribute>
             </File>
            <File>
                <xsl:attribute name="RelativePath">.\<xsl:value-of select="@callbackName"/>.h</xsl:attribute>
             </File>
        </xsl:if>
        <xsl:if test="$isServer='1'">
             <File>
                <xsl:attribute name="RelativePath">.\<xsl:value-of select="@servicename"/>.h</xsl:attribute>
             </File>
        </xsl:if>
        <xsl:for-each select="method">
            <xsl:for-each select="input/param[@type!='' and @ours ]">
            <xsl:variable name="inputtype" select="substring-after(@type,'::')"/>
                 <File>
                     <xsl:attribute name="RelativePath">.\<xsl:value-of select='$inputtype'/>.h</xsl:attribute>
                </File>
           </xsl:for-each>
            <xsl:for-each select="output/param[@type!='' and @ours]">
             <xsl:variable name="outputtype1" select="substring-after(@type,'::')"/>
                    <File>
                     <xsl:attribute name="RelativePath">.\<xsl:value-of select="$outputtype1"/>.h</xsl:attribute>
                    </File>
            </xsl:for-each>
            <xsl:for-each select="fault/param[@type!='']">
                <xsl:variable name="faulttype" select="substring-after(@type,'::')"/>
                    <File>
                     <xsl:attribute name="RelativePath">.\<xsl:value-of select="$faulttype"/>.h</xsl:attribute>
                    </File>
            </xsl:for-each>
        </xsl:for-each>
    </Filter>

    <Filter Name="Resource Files"
	    Filter="rc;ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe;resx;tiff;tif;png;wav">
    </Filter>
  </Files>
  <Globals>
  </Globals>
</VisualStudioProject>    
    </xsl:template>
    </xsl:stylesheet>

