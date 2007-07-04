
       /**
        * axis2_getSymbolsRequest.h
        *
        * This file was auto-generated from WSDL
        * by the Apache Axis2/C version: #axisVersion# #today#
        *
        */

        #include <axis2_getSymbolsRequest.h>
          
              /**
               * implmentation of the getSymbolsRequest|http://www.wso2.org/types element
               */
             


        struct axis2_getSymbolsRequest
        {
            
                axutil_qname_t* qname;
            
        };


       /************************* Function Implmentations ********************************/
        AXIS2_EXTERN axis2_getSymbolsRequest_t* AXIS2_CALL
        axis2_getSymbolsRequest_create(
            const axutil_env_t *env )
        {
            axis2_getSymbolsRequest_t *getSymbolsRequest = NULL;
            
              axutil_qname_t* qname = NULL;
            
            AXIS2_ENV_CHECK(env, NULL);

            getSymbolsRequest = (axis2_getSymbolsRequest_t *) AXIS2_MALLOC(env->
                allocator, sizeof(axis2_getSymbolsRequest_t));

            if(NULL == getSymbolsRequest)
            {
                AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
                return NULL;
            }

            
              qname =  axutil_qname_create (env,
                        "getSymbolsRequest",
                        "http://www.wso2.org/types",
                        "ns1");

              getSymbolsRequest->qname = qname;
            

            return getSymbolsRequest;
         }

        axis2_status_t AXIS2_CALL
        axis2_getSymbolsRequest_free (
                axis2_getSymbolsRequest_t* getSymbolsRequest,
                const axutil_env_t *env)
        {
            
            

            AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

            
              if(getSymbolsRequest->qname )
              {
                  axutil_qname_free (getSymbolsRequest->qname, env);
                  getSymbolsRequest->qname = NULL;
              }
            

            if(getSymbolsRequest)
            {
                AXIS2_FREE( env->allocator, getSymbolsRequest);
                getSymbolsRequest = NULL;
            }
            return AXIS2_SUCCESS;
        }

          
           axutil_qname_t* AXIS2_CALL
           axis2_getSymbolsRequest_get_qname (
                   axis2_getSymbolsRequest_t* getSymbolsRequest,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

               return getSymbolsRequest-> qname;
           }
        

        axis2_status_t AXIS2_CALL
        axis2_getSymbolsRequest_deserialize(
                axis2_getSymbolsRequest_t* getSymbolsRequest,
                const axutil_env_t *env,
                axiom_node_t* parent)
        {

            axis2_status_t status = AXIS2_SUCCESS;
            axiom_namespace_t *ns1 = NULL;
            
             /*axis2_char_t* text_value = NULL;*/
             /*axutil_qname_t *qname = NULL;*/
            
            
              /*axutil_qname_t *element_qname = NULL;*/
            
            AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

            ns1 = axiom_namespace_create (env,
                                         "http://www.wso2.org/types",
                                         "ns1");
             

          return status;
       }

        axiom_node_t* AXIS2_CALL
        axis2_getSymbolsRequest_serialize(
                axis2_getSymbolsRequest_t* getSymbolsRequest,
                const axutil_env_t *env, axiom_node_t* parent, int has_parent)
        {
            
            axiom_namespace_t *ns1 = NULL;
            
            AXIS2_ENV_CHECK(env, NULL);

            ns1 = axiom_namespace_create (env,
                                         "http://www.wso2.org/types",
                                         "ns1");
            
            return parent;
        }

        

