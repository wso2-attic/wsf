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

        /**
         * <xsl:value-of select="@name"/>.cpp
         *
         * This file was auto-generated from WSDL for "<xsl:value-of select="$qname"/>" service
         * by the Apache Axis2 version: #axisVersion# #today#
         *  <xsl:value-of select="$skeletonname"/>
         */

        #include "<xsl:value-of select="$servicename"/>.h"
        #include "<xsl:value-of select="@name"/>.h"  
        #include &lt;ServiceSkeleton.h&gt;
        #include &lt;stdio.h&gt;
        #include &lt;axis2_svc.h&gt;
        #include &lt;Environment.h&gt;
        #include &lt;axiom_soap.h&gt;


        using namespace wso2wsf;
        <xsl:if test="@cppNamespace">
        using namespace <xsl:value-of select="@cppNamespace"/>;
        </xsl:if>

        /** Load the service into axis2 engine */
        WSF_SERVICE_INIT(<xsl:value-of select="@name"/>)

          
         /**
          * function to free any soap input headers
          */
         <xsl:for-each select="method">

            <xsl:if test="input/param[@location='soap_header']">
             void
             axis2_skel_op_<xsl:value-of select="$servicename"/>_<xsl:value-of select="@name"/>_free_input_headers(const axutil_env_t *env, <xsl:for-each select="input/param[@location='soap_header']"><xsl:if test="position()!=1">,</xsl:if>
                                                     <xsl:variable name="inputtype"><xsl:value-of select="@type"/></xsl:variable>
                                                     <xsl:value-of select="$inputtype"/><xsl:text> _</xsl:text><xsl:value-of select="@name"/>
                                                     </xsl:for-each>);
            </xsl:if>
            <xsl:if test="output/param[@location='soap_header']">
             void
             axis2_skel_op_<xsl:value-of select="$servicename"/>_<xsl:value-of select="@name"/>_free_output_headers(const axutil_env_t *env, <xsl:for-each select="output/param[@location='soap_header']"><xsl:if test="position()!=1">,</xsl:if>
                                                     <xsl:variable name="outputtype"><xsl:value-of select="@type"/></xsl:variable>
                                                     <xsl:value-of select="$outputtype"/><xsl:text> _</xsl:text><xsl:value-of select="@name"/>
                                                     </xsl:for-each>);
           </xsl:if>
         </xsl:for-each>

  
         <xsl:for-each select="method/output/param[@location='soap_header']">
            <xsl:if test="position()=1">
            /*
             * Create the response soap envelope when output headers are to be set..
             */
            axiom_soap_envelope_t* WSF_CALL
            create_response_envelope(const axutil_env_t *env,
                                                                            axis2_msg_ctx_t *in_msg_ctx, 
                                                                            axis2_msg_ctx_t *msg_ctx,
                                                                            axiom_node_t *body_content_node);
            </xsl:if>
         </xsl:for-each>

    <xsl:value-of select="$method-prefix"/>::<xsl:value-of select="$method-prefix"/>()
	{
          skel = wsfGet<xsl:value-of select="$svcop-prefix"/>();
    }


	bool WSF_CALL
	<xsl:value-of select="$method-prefix"/>::init()
	{

      return true;
	}


	<xsl:value-of select="$method-prefix"/>::~<xsl:value-of select="$method-prefix"/>()
	{
    }


     <!--
     <xsl:for-each select="method">
        <xsl:if test="input/param[@location='soap_header']">

         /**
          * function to free soap input headers
          */
         void
         axis2_skel_op_<xsl:value-of select="$servicename"/>_<xsl:value-of select="@name"/>_free_input_headers(const axutil_env_t *env, <xsl:for-each select="input/param[@location='soap_header']"><xsl:if test="position()!=1">,</xsl:if>
                                                 <xsl:variable name="inputtype"><xsl:value-of select="@type"/></xsl:variable>
                                                 <xsl:value-of select="$inputtype"/><xsl:text> _</xsl:text><xsl:value-of select="@name"/>
                                                 </xsl:for-each>)
         {
            <xsl:for-each select="input/param[@location='soap_header']">
               <xsl:variable name="header_var"><xsl:text>_</xsl:text><xsl:value-of select="@name"/></xsl:variable>
               <xsl:choose>
                <xsl:when test="@ours">
                    if(<xsl:value-of select="$header_var"/>)
                    {
                        <xsl:value-of select="substring-before(@type, '_t*')"/>_free(<xsl:value-of select="$header_var"/>, env);
                    }
                </xsl:when>
                <xsl:otherwise>
                    /* we don't have anything to free on <xsl:value-of select="$header_var"/> */
                </xsl:otherwise>
               </xsl:choose>
            </xsl:for-each>
         }
        </xsl:if>
     </xsl:for-each>
         -->
<!--

     <xsl:for-each select="method">
        <xsl:if test="output/param[@location='soap_header']">

         /**
          * function to free any soap output headers
          */
         void
         axis2_skel_op_<xsl:value-of select="$servicename"/>_<xsl:value-of select="@name"/>_free_output_headers(const axutil_env_t *env, <xsl:for-each select="output/param[@location='soap_header']"><xsl:if test="position()!=1">,</xsl:if>
                                                 <xsl:variable name="outputtype"><xsl:value-of select="@type"/></xsl:variable>
                                                 <xsl:value-of select="$outputtype"/><xsl:text> _</xsl:text><xsl:value-of select="@name"/>
                                                 </xsl:for-each>)
         {
            <xsl:for-each select="output/param[@location='soap_header']">
               <xsl:variable name="header_var"><xsl:text>_</xsl:text><xsl:value-of select="@name"/></xsl:variable>
               <xsl:choose>
                <xsl:when test="@ours">
                    if(<xsl:value-of select="$header_var"/>)
                    {
                        <xsl:value-of select="substring-before(@type, '_t*')"/>_free(<xsl:value-of select="$header_var"/>, env);
                    }
                </xsl:when>
                <xsl:otherwise> 
                    /* we don't have anything to free on <xsl:value-of select="$header_var"/> */
                </xsl:otherwise>
               </xsl:choose>
            </xsl:for-each>
         }
        </xsl:if>
     </xsl:for-each>
-->
     <xsl:for-each select="method/output/param[@location='soap_header']">
       <xsl:if test="position()=1">
	/*
	 * Create the response soap envelope when output headers are to be set..
	 */
	axiom_soap_envelope_t* AXIS2_CALL
	create_response_envelope(const axutil_env_t *env,
                            axis2_msg_ctx_t *in_msg_ctx,
                            axis2_msg_ctx_t *msg_ctx,
                            axiom_node_t *body_content_node)
{
        const axis2_char_t *soap_ns = AXIOM_SOAP12_SOAP_ENVELOPE_NAMESPACE_URI;
        int soap_version = AXIOM_SOAP12;
        axiom_namespace_t *env_ns = NULL;
        axiom_soap_envelope_t *default_envelope = NULL;
        axiom_soap_header_t *out_header = NULL;
        axiom_soap_body_t *out_body = NULL;
        axiom_node_t *out_node = NULL;
        
        if (in_msg_ctx &amp;&amp; axis2_msg_ctx_get_is_soap_11(in_msg_ctx, env))
        {
            soap_ns = AXIOM_SOAP11_SOAP_ENVELOPE_NAMESPACE_URI; /* default is 1.2 */
            soap_version = AXIOM_SOAP11;
        }

        /* create the soap envelope here */
        env_ns = axiom_namespace_create(env, soap_ns, "soapenv");
        if (!env_ns)
        {
            return NULL;
        }

        default_envelope = axiom_soap_envelope_create(env, env_ns);

        if (!default_envelope)
        {
            axiom_namespace_free(env_ns, env);
            return NULL;
        }

        out_header = axiom_soap_header_create_with_parent(env, default_envelope);
        if (!out_header)
        {
            axiom_soap_envelope_free(default_envelope, env);
            axiom_namespace_free(env_ns, env);
            return NULL;
        }

        out_body = axiom_soap_body_create_with_parent(env, default_envelope);
        if (!out_body)
        {
            axiom_soap_body_free(out_body, env);
            axiom_soap_envelope_free(default_envelope, env);
            axiom_namespace_free(env_ns, env);
            return NULL;
        }

        out_node = axiom_soap_body_get_base_node(out_body, env);
        if (!out_node)
        {
            axiom_soap_body_free(out_body, env);
            axiom_soap_envelope_free(default_envelope, env);
            axiom_namespace_free(env_ns, env);
            return NULL;
        }
 
        if (body_content_node)
        {
            axiom_node_add_child(out_node, env, body_content_node);
        }
        
        if(axis2_msg_ctx_set_soap_envelope(msg_ctx, env, default_envelope) == AXIS2_FAILURE)
        {
            axiom_soap_body_free(out_body, env);
            axiom_soap_envelope_free(default_envelope, env);
            axiom_namespace_free(env_ns, env);
            if (body_content_node)
            {
                axiom_node_free_tree(body_content_node, env);
            }
            return NULL;
        }
        return default_envelope;
    }
        </xsl:if>
      </xsl:for-each>




	/*
	 * This method invokes the right service method
	 */
	OMElement* WSF_CALL
	<xsl:value-of select="$method-prefix"/>::invoke(OMElement *omEle, MessageContext *msgCtx)
	{
         /* Using the function name, invoke the corresponding method
          */

          axis2_op_ctx_t *operation_ctx = NULL;
          axis2_op_t *operation = NULL;
          axutil_qname_t *op_qname = NULL;
          axis2_char_t *op_name = NULL;
          axis2_msg_ctx_t *in_msg_ctx = NULL;
          
          axiom_soap_envelope_t *req_soap_env = NULL;
          axiom_soap_header_t *req_soap_header = NULL;
          axiom_soap_envelope_t *res_soap_env = NULL;
          axiom_soap_header_t *res_soap_header = NULL;

          axiom_node_t *ret_node = NULL;
          axiom_node_t *input_header = NULL;
          axiom_node_t *output_header = NULL;
          axiom_node_t *header_base_node = NULL;
          axis2_msg_ctx_t *msg_ctx = NULL;
          axiom_node_t* content_node = omEle->getAxiomNode();

          <xsl:for-each select="method">
            <xsl:text>
            </xsl:text>
            <xsl:variable name="position"><xsl:value-of select="position()"/></xsl:variable>
            <xsl:variable name="outputtype">
              <xsl:choose>
                <xsl:when test="not(output/param/@type)">axis2_status_t</xsl:when>
                <xsl:otherwise><xsl:value-of select="output/param/@type"/><xsl:if test="output/param/@ours">*</xsl:if></xsl:otherwise>
              </xsl:choose>
            </xsl:variable>
            <xsl:value-of select="$outputtype"/> ret_val<xsl:value-of select="$position"/>;
            <xsl:if test="input/param/@type!=''">
              <xsl:value-of select="input/param/@type"/><xsl:if test="input/param/@ours">*</xsl:if> input_val<xsl:value-of select="$position"/>;
            </xsl:if>
            <xsl:for-each select="input/param[@location='soap_header']">
                <xsl:value-of select="@type"/><xsl:if test="@ours">*</xsl:if><xsl:text> _</xsl:text><xsl:value-of select="@name"/><xsl:value-of select="$position"/> = NULL;
            </xsl:for-each>
            <xsl:for-each select="output/param[@location='soap_header']">
                <xsl:value-of select="@type"/><xsl:if test="@ours">*</xsl:if><xsl:text> _</xsl:text><xsl:value-of select="@name"/><xsl:value-of select="$position"/> = NULL;
            </xsl:for-each>
          </xsl:for-each>
       
          msg_ctx = msgCtx->getAxis2MessageContext();
          operation_ctx = axis2_msg_ctx_get_op_ctx(msg_ctx, Environment::getEnv());
          operation = axis2_op_ctx_get_op(operation_ctx, Environment::getEnv());
          op_qname = (axutil_qname_t *)axis2_op_get_qname(operation, Environment::getEnv());
          op_name = axutil_qname_get_localpart(op_qname, Environment::getEnv());

          if (op_name)
          {
               <xsl:for-each select="method/input/param[@location='soap_header']">
                <xsl:if test="position()=1">
                if(operation_ctx)
                {
                   in_msg_ctx = axis2_op_ctx_get_msg_ctx(operation_ctx, Environment::getEnv(), AXIS2_WSDL_MESSAGE_LABEL_IN);
                }
                if(in_msg_ctx)
                {
                    req_soap_env = axis2_msg_ctx_get_soap_envelope(in_msg_ctx, Environment::getEnv());
                }
                if(!req_soap_env)
                {
                    AXIS2_LOG_ERROR( Environment::getEnv()->log, AXIS2_LOG_SI, "request evelope is NULL");
                    return NULL;
                }
                req_soap_header = axiom_soap_envelope_get_header(req_soap_env, Environment::getEnv());

                if(req_soap_header)
                {
                    header_base_node = axiom_soap_header_get_base_node(req_soap_header, Environment::getEnv());
                }
               </xsl:if>
               </xsl:for-each>


            <xsl:for-each select="method">
                <xsl:variable name="position"><xsl:value-of select="position()"/></xsl:variable>
                <xsl:variable name="name"><xsl:value-of select="@name"/></xsl:variable>
                <xsl:variable name="method-name"><xsl:value-of select="@name"/></xsl:variable>
                <xsl:variable name="method-ns"><xsl:value-of select="@namespace"/> </xsl:variable>
                <xsl:variable name="outputCapsType"><xsl:value-of select="output/param/@caps-type"/> </xsl:variable>
                <xsl:variable name="outputtype"><xsl:value-of select="output/param/@type"/></xsl:variable>
                <xsl:variable name="inputtype"><xsl:value-of select="input/param/@type"/></xsl:variable>
                <xsl:variable name="isUnwrapParameters" select="input/param[@location='body' and @type!='']/@unwrappParameters"/>

                if ( axutil_strcmp(op_name, "<xsl:value-of select="@localpart"/>") == 0 )
                {

                    <xsl:if test="input/param/@type!=''">
                    input_val<xsl:value-of select="$position"/> =
                        <xsl:choose>
                        <xsl:when test="input/param/@ours">
                        new <xsl:value-of select="input/param/@type"/>();
                        if( AXIS2_FAILURE ==  input_val<xsl:value-of select="$position"/>->deserialize(&amp;content_node, NULL, false))
                        {
                                        <!--
                            <xsl:value-of select="substring-before(input/param/@type, '_t*')"/>_free(input_val<xsl:value-of select="$position"/>, env);
                                            -->
                            AXIS2_ERROR_SET(Environment::getEnv()->error, AXIS2_ERROR_DATA_ELEMENT_IS_NULL, AXIS2_FAILURE);
                            AXIS2_LOG_ERROR( Environment::getEnv()->log, AXIS2_LOG_SI, "NULL returned from the <xsl:value-of select="input/param/@type"/>_deserialize: "
                                        "This should be due to an invalid XML");
                            return NULL;      
                        }
                        </xsl:when>
                        <xsl:otherwise>new OMElement(NULL, content_node);</xsl:otherwise>
                        </xsl:choose>
                    </xsl:if>

                    <xsl:for-each select="input/param[@location='soap_header']">
                    <xsl:choose>
                    <xsl:when test="position()=1">
                        input_header = axiom_node_get_first_child(header_base_node, Environment::getEnv());

                        while(input_header &amp;&amp; axiom_node_get_node_type(input_header, Environment::getEnv()) != AXIOM_ELEMENT)
                        {
                            input_header = axiom_node_get_next_sibling(input_header, Environment::getEnv());
                        }
                    </xsl:when>
                    <xsl:otherwise>
                        input_header = axiom_node_get_next_sibling(input_header, Environment::getEnv());

                        while(input_header &amp;&amp; axiom_node_get_node_type(input_header, Environment::getEnv()) != AXIOM_ELEMENT)
                        {
                            input_header = axiom_node_get_next_sibling(input_header, Environment::getEnv());
                        }
                    </xsl:otherwise>
                    </xsl:choose>

                    <!-- here the position mean the number of the method -->
                    <xsl:variable name="header_var"><xsl:text>_</xsl:text><xsl:value-of select="@name"/><xsl:value-of select="$position"/></xsl:variable>

                    if( NULL == input_header)
                    {
                        AXIS2_LOG_ERROR( Environment::getEnv()->log, AXIS2_LOG_SI, "Response header <xsl:value-of select="@name"/> is NULL");
                        <xsl:if test="@ours">
                        /* you can't have a response header NULL, just free things and exit */
                        <xsl:for-each select="../../input/param[@location='soap_header']">
                                  delete <xsl:text>_</xsl:text><xsl:value-of select="@name"/><xsl:value-of select="$position"/>;
                        </xsl:for-each>
                            delete input_val<xsl:value-of select="$position"/>;
                        </xsl:if>

                        return NULL;
                    }
              
                    <xsl:choose>
                    <xsl:when test="@ours">
                        <xsl:value-of select="$header_var"/> = new <xsl:value-of select="@type"/>();

                        if(<xsl:value-of select="$header_var"/>->deserialize(&amp;input_header, NULL, AXIS2_FALSE ) == AXIS2_FAILURE)
                        {
                            if(<xsl:value-of select="$header_var"/> != NULL)
                            {
                                delete <xsl:value-of select="$header_var"/>;
                            }
                            AXIS2_LOG_ERROR( Environment::getEnv()->log, AXIS2_LOG_SI, "NULL returnted from th deserialize: "
                                                                    "This should be due to an invalid input header");
                            <xsl:for-each select="../../input/param[@location='soap_header']">
                                <xsl:text>delete _</xsl:text><xsl:value-of select="@name"/><xsl:value-of select="$position"/>;
                            </xsl:for-each>
                                delete input_val<xsl:value-of select="$position"/>;
                            return NULL;
                        }
                    </xsl:when>
                    <xsl:otherwise>
                        <xsl:value-of select="header_var"/> = input_header;
                    </xsl:otherwise>
                    </xsl:choose>

                    </xsl:for-each>


                    <xsl:choose>
                    <xsl:when test="$isUnwrapParameters">
                        <xsl:variable name="inputparam_values">
                            <xsl:choose>
                                <xsl:when test="input/param/@complextype">
                                                <xsl:for-each select="input/param/param[@type!='']"><xsl:text>,</xsl:text>
                                                    <!--xsl:if test="position() > 1"><xsl:text>,</xsl:text></xsl:if-->
                                                    input_val<xsl:value-of select="$position"/>->getProperty1()->getProperty<xsl:value-of select="position()"/>()
                                                </xsl:for-each>
                                </xsl:when>
                                <xsl:otherwise>
                                                <xsl:for-each select="input/param/param[@type!='']"><xsl:text>,</xsl:text>
                                                     <!--xsl:if test="position() > 1"><xsl:text>,</xsl:text></xsl:if-->
                                                     input_val<xsl:value-of select="$position"/>->getProperty<xsl:value-of select="position()"/>()
                                                </xsl:for-each>
                                </xsl:otherwise>
                            </xsl:choose>
                        </xsl:variable>
                        <xsl:variable name="outputparam_types"><xsl:value-of select="output/param/param/@type"/><xsl:if test="output/param/param/@ours">*</xsl:if></xsl:variable>
                        {
                           // <xsl:value-of select="$svcop-prefix"/> skel;
                           <xsl:value-of select="$outputparam_types"/> ret_unwrapped = skel-><xsl:value-of select="$method-name"/><xsl:text>(msgCtx </xsl:text>
                                                <xsl:value-of select="$inputparam_values"/>
                                                <xsl:for-each select="output/param[@location='soap_header']">,
                                                    <xsl:text>&amp;_</xsl:text><xsl:value-of select="@name"/><xsl:value-of select="$position"/>
                                                </xsl:for-each><xsl:if test="count(fault/*)">,
                                                (<xsl:value-of select="$servicename"/>_<xsl:value-of select="@name"/><xsl:text>_fault*</xsl:text>)&amp;(this->fault)</xsl:if>);
                            <xsl:choose>
                                <xsl:when test="output/param/@complextype">
                                    ret_val<xsl:value-of select="$position"/> = new <xsl:value-of select="output/param/@type"/>(
                                            new <xsl:value-of select="output/param/@complextype"/>(ret_unwrapped));
                                </xsl:when>
                                <xsl:otherwise>
                                    ret_val<xsl:value-of select="$position"/> =new <xsl:value-of select="output/param/@type"/>(ret_unwrapped);
                                </xsl:otherwise>
                            </xsl:choose>
                            
                            <!-- if the output type is a string, we have to free it, just since user don't have a way to free it, and the wrapper
                                 keep a deep copy of the string,-->
                            <xsl:if test="$outputparam_types='axis2_char_t*'">
                                if(ret_unwrapped)
                                {
                                    /* we are freeing this for the user */
                                    AXIS2_FREE(Environment::getEnv()->allocator, ret_unwrapped);
                                }
                            </xsl:if>
                        }
                    </xsl:when>
                    <xsl:otherwise>
                        <xsl:variable name="inputparam_values">
                                                    <xsl:if test="input/param/@type!=''">,input_val<xsl:value-of select="$position"/>
                                                    </xsl:if><xsl:for-each select="input/param[@location='soap_header']">,
                                                    <xsl:text>_</xsl:text><xsl:value-of select="@name"/><xsl:value-of select="$position"/>
                                                </xsl:for-each>
                        </xsl:variable>
                        //<xsl:value-of select="$svcop-prefix"/> skel;
                        ret_val<xsl:value-of select="$position"/> =  skel-><xsl:value-of select="$method-name"/><xsl:text>(msgCtx </xsl:text>
                                                <xsl:value-of select="$inputparam_values"/><xsl:for-each select="output/param[@location='soap_header']">,
                                                    <xsl:text>&amp;_</xsl:text><xsl:value-of select="@name"/><xsl:value-of select="$position"/>
                                                </xsl:for-each><xsl:if test="count(fault/*)">,
                                                (<xsl:value-of select="$servicename"/>_<xsl:value-of select="@name"/><xsl:text>_fault*</xsl:text>)&amp;(this->fault)</xsl:if>);
                    </xsl:otherwise>
                    </xsl:choose>
                    <xsl:choose>
                    <xsl:when test="output/param/@type">
                        if ( NULL == ret_val<xsl:value-of select="$position"/> )
                        {
                            <xsl:if test="input/param/@ours">
                                delete input_val<xsl:value-of select="$position"/>;
                            </xsl:if>
                            <xsl:if test="input/param/@location='soap_header'">
                                <xsl:for-each select="input/param[@location='soap_header']">
                                    delete <xsl:text>_</xsl:text><xsl:value-of select="@name"/><xsl:value-of select="$position"/>;
                                </xsl:for-each>
                            </xsl:if>
                            <xsl:if test="output/param/@location='soap_header'">
                                <xsl:for-each select="output/param[@location='soap_header']">
                                    delete <xsl:text> _</xsl:text><xsl:value-of select="@name"/><xsl:value-of select="$position"/>;
                                </xsl:for-each>
                            </xsl:if>
                            return NULL; 
                        }
                        ret_node = <xsl:choose>
                                       <xsl:when test="output/param/@ours">
                                            ret_val<xsl:value-of select="$position"/>->serialize(NULL, NULL, AXIS2_TRUE, NULL, NULL);
                                            delete ret_val<xsl:value-of select="$position"/>;
                                        <xsl:if test="input/param/@type!=''">
                                            delete input_val<xsl:value-of select="$position"/>;
                                        </xsl:if>
                                      </xsl:when>
                                      <xsl:otherwise>
                                          ret_val<xsl:value-of select="$position"/>->getAxiomNode();
                                          ret_val<xsl:value-of select="$position"/>->setAxiomNode(NULL);
                                          delete ret_val<xsl:value-of select="$position"/>;
                                      </xsl:otherwise>
                                    </xsl:choose>
                        <xsl:if test="output/param[@location='soap_header']">
                        res_soap_env = axis2_msg_ctx_get_response_soap_envelope(msg_ctx, Environment::getEnv());
                        if(!res_soap_env)
                        {
                            res_soap_env = create_response_envelope(Environment::getEnv(), in_msg_ctx, msg_ctx, ret_node);
                        }
                        if(!res_soap_env)
                        {
                            AXIS2_LOG_ERROR( Environment::getEnv()->log, AXIS2_LOG_SI, "response evelope is NULL");
                            <xsl:if test="input/param/@location='soap_header'">
                                <xsl:for-each select="input/param[@location='soap_header']">
                                    <xsl:text>delete _</xsl:text><xsl:value-of select="@name"/><xsl:value-of select="$position"/>;
                                </xsl:for-each>
                            </xsl:if>
                            <xsl:if test="output/param/@location='soap_header'">
                                <xsl:for-each select="output/param[@location='soap_header']">
                                     <xsl:text>delete _</xsl:text><xsl:value-of select="@name"/><xsl:value-of select="$position"/>;
                                 </xsl:for-each>
                            </xsl:if>
                            return NULL;
                        }
                        res_soap_header = axiom_soap_envelope_get_header(res_soap_env, Environment::getEnv());
 
                        if(res_soap_header)
                        {
                            header_base_node = axiom_soap_header_get_base_node(res_soap_header, Environment::getEnv());
                        }
  
                        if(!header_base_node)
                        {
                            <xsl:if test="input/param/@location='soap_header'">
                            <xsl:for-each select="input/param[@location='soap_header']">
                                    <xsl:text>delete _</xsl:text><xsl:value-of select="@name"/><xsl:value-of select="$position"/>;
                                </xsl:for-each>
                                </xsl:if>
                                <xsl:if test="output/param/@location='soap_header'">
                                <xsl:for-each select="output/param[@location='soap_header']">
                                 <xsl:text>delete _</xsl:text><xsl:value-of select="@name"/><xsl:value-of select="$position"/>;
                             </xsl:for-each>
                            </xsl:if>
                            AXIS2_LOG_ERROR( Environment::getEnv()->log, AXIS2_LOG_SI, "Required response header is NULL");
                            return NULL;
                        }
                        </xsl:if>
                        <!-- adding output headers -->
                        <xsl:for-each select="output/param[@location='soap_header']">
                            <xsl:choose>
                            <xsl:when test="@ours">
                            output_header = _<xsl:value-of select="@name"/><xsl:value-of select="$position"/>->serialize(NULL, NULL, AXIS2_TRUE, NULL, NULL);
                            </xsl:when>
                            <xsl:otherwise>
                            output_header = _<xsl:value-of select="@name"/>;
                            </xsl:otherwise>
                            </xsl:choose>
                            axiom_node_add_child(header_base_node, Environment::getEnv(), output_header);
                        </xsl:for-each>

                        <xsl:if test="input/param/@location='soap_header'">
                                <xsl:for-each select="input/param[@location='soap_header']">
                                    <xsl:text>delete _</xsl:text><xsl:value-of select="@name"/><xsl:value-of select="$position"/>;
                                 </xsl:for-each>
                        </xsl:if>
                        <xsl:if test="output/param/@location='soap_header'">
                            <xsl:for-each select="output/param[@location='soap_header']">
                            <xsl:text>delete _</xsl:text><xsl:value-of select="@name"/><xsl:value-of select="$position"/>;
                            </xsl:for-each>
                        </xsl:if>

                        return new OMElement(NULL,ret_node);
                    </xsl:when>
                    <xsl:otherwise>
                        if( AXIS2_FAILURE == ret_val<xsl:value-of select="$position"/> )
                        {
                            AXIS2_LOG_ERROR(Environment::getEnv()->log, AXIS2_LOG_SI, "NULL returnted from the business logic from <xsl:value-of select="$method-name"/> ");
                        }
                        <xsl:if test="input/param/@type!=''">
                           delete input_val<xsl:value-of select="$position"/>;
                        </xsl:if>
                        <xsl:if test="input/param/@location='soap_header'">
                            <xsl:for-each select="input/param[@location='soap_header']">
                                                     <xsl:text>delete _</xsl:text><xsl:value-of select="@name"/><xsl:value-of select="position()"/>;
                            </xsl:for-each>
                            return NULL;
                        </xsl:if>
                    </xsl:otherwise>
                    </xsl:choose>

                    /* since this has no output params it just returns NULL */                    
                    <xsl:if test="$outputtype=''">return NULL;</xsl:if>

                }
             </xsl:for-each>
             }
            
          AXIS2_LOG_ERROR(Environment::getEnv()->log, AXIS2_LOG_SI, "<xsl:value-of select="$skeletonname"/> service ERROR: invalid OM parameters in request\n");
          return NULL;
    }

    OMElement* WSF_CALL
    <xsl:value-of select="$method-prefix"/>::onFault(OMElement* omEle)
	{
		axiom_node_t *error_node = NULL;
		axiom_element_t *error_ele = NULL;
        axutil_error_codes_t error_code;
        axiom_node_t *node = omEle->getAxiomNode();
        error_code = (axutil_error_codes_t)Environment::getEnv()->error->error_number;

        if(error_code &lt;= <xsl:value-of select="$caps_svc_name"/>_ERROR_NONE ||
                error_code &gt;= <xsl:value-of select="$caps_svc_name"/>_ERROR_LAST )
        {
            error_ele = axiom_element_create(Environment::getEnv(), node, "fault", NULL,
                            &amp;error_node);
            axiom_element_set_text(error_ele, Environment::getEnv(), "<xsl:value-of select="$qname"/> failed",
                            error_node);
        }
        <xsl:for-each select="method">
            <xsl:variable name="caps_method_name" select="@caps-name"/>
            <xsl:variable name="method_name" select="@name"/>
            <xsl:for-each select="fault/param">
                <xsl:variable name="fault-caps-name"><xsl:value-of select="$caps_svc_name"/>_<xsl:value-of select="$caps_method_name"/>_FAULT_<xsl:value-of select="@caps-localname"/></xsl:variable>

                else if(error_code == <xsl:value-of select="$fault-caps-name"/>)
                {
                    /* found which error code */
                    <xsl:value-of select="@type"/><xsl:text> *</xsl:text>adb_obj = NULL;
                   
                    adb_obj = (<xsl:value-of select="@type"/>*)this->fault.<xsl:value-of select="$method_name"/>_fault-><xsl:value-of select="@shorttype"/>;
                    if(adb_obj)
                    {
                        error_node = adb_obj->serialize(NULL, NULL, AXIS2_TRUE, NULL, NULL);
                        delete adb_obj;
                    }

                }
            </xsl:for-each>
        </xsl:for-each>

		return new OMElement(NULL,error_node);
	}

    </xsl:template>

</xsl:stylesheet>
