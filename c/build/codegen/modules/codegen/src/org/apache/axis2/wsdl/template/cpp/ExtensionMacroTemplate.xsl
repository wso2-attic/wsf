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
 <xsl:template match="/interface">
    <xsl:variable name="servicename"><xsl:value-of select="@svcname"/></xsl:variable>
    <xsl:variable name="skeletonname"><xsl:value-of select="@name"/></xsl:variable>
    <xsl:variable name="svcop-prefix"><xsl:value-of select="@svcop_prefix"/></xsl:variable>

#include "<xsl:value-of select="$servicename"/>.h"
#include "<xsl:value-of select="@name"/>.h"
#include &lt;ServiceSkeleton.h&gt;
#include &lt;stdio.h&gt;
#include &lt;axis2_svc.h&gt;
#include &lt;Environment.h&gt;

using namespace wso2wsf;
<xsl:if test="@cppNamespace">
using namespace <xsl:value-of select="@cppNamespace"/>;
</xsl:if>


/** Load the service into engine
Note:- If you are extending from the Generated Skeleton class,you need is to change the argument provided to the
macro to your derived class name.
Example
If your service is Calculator, you will have the business logic implementation class as CalculatorSkeleton.
If the extended class is CalculatorSkeletonImpl, then you change the argument to the macro WSF_SERVICE_SKEL_INIT as
WSF_SERVICE_SKEL_INIT(CalculatorSkeletonImpl). Also include the header file of the derived class, in this case CalculatorSkeletonImpl.h

*/

WSF_SERVICE_SKEL_INIT(<xsl:value-of select="$svcop-prefix"/>)

</xsl:template>
</xsl:stylesheet>
