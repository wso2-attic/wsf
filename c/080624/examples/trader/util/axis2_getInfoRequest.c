
       /**
        * axis2_getInfoRequest.h
        *
        * This file was auto-generated from WSDL
        * by the Apache Axis2/C version: #axisVersion# #today#
        *
        */

        #include <axis2_getInfoRequest.h>
          
              /**
               * implmentation of the getInfoRequest|http://www.wso2.org/types element
               */
             


        struct axis2_getInfoRequest
        {
            
                axutil_qname_t* qname;
            
        };


       /************************* Function Implmentations ********************************/
        AXIS2_EXTERN axis2_getInfoRequest_t* AXIS2_CALL
        axis2_getInfoRequest_create(
            const axutil_env_t *env )
        {
            axis2_getInfoRequest_t *getInfoRequest = NULL;
            
              axutil_qname_t* qname = NULL;
            
            AXIS2_ENV_CHECK(env, NULL);

            getInfoRequest = (axis2_getInfoRequest_t *) AXIS2_MALLOC(env->
                allocator, sizeof(axis2_getInfoRequest_t));

            if(NULL == getInfoRequest)
            {
                AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
                return NULL;
            }

            
              qname =  axutil_qname_create (env,
                        "getInfoRequest",
                        "http://www.wso2.org/types",
                        "ns1");

              getInfoRequest->qname = qname;
            

            return getInfoRequest;
         }

        axis2_status_t AXIS2_CALL
        axis2_getInfoRequest_free (
                axis2_getInfoRequest_t* getInfoRequest,
                const axutil_env_t *env)
        {
            
            

            AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

            
              if(getInfoRequest->qname )
              {
                  axutil_qname_free (getInfoRequest->qname, env);
                  getInfoRequest->qname = NULL;
              }
            

            if(getInfoRequest)
            {
                AXIS2_FREE( env->allocator, getInfoRequest);
                getInfoRequest = NULL;
            }
            return AXIS2_SUCCESS;
        }

          
           axutil_qname_t* AXIS2_CALL
           axis2_getInfoRequest_get_qname (
                   axis2_getInfoRequest_t* getInfoRequest,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

               return getInfoRequest-> qname;
           }
        

        axis2_status_t AXIS2_CALL
        axis2_getInfoRequest_deserialize(
                axis2_getInfoRequest_t* getInfoRequest,
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
        axis2_getInfoRequest_serialize(
                axis2_getInfoRequest_t* getInfoRequest,
                const axutil_env_t *env, axiom_node_t* parent, int has_parent)
        {
            
            axiom_namespace_t *ns1 = NULL;
            
            AXIS2_ENV_CHECK(env, NULL);

            ns1 = axiom_namespace_create (env,
                                         "http://www.wso2.org/types",
                                         "ns1");
            
            return parent;
        }

        

