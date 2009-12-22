/*
 * Copyright 2005-2009 WSO2, Inc. http://wso2.com
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

#include <stdio.h>
#include <ServiceSkeleton.h>
using namespace wso2wsf;
using namespace std;


Property* ServiceSkeleton::getProperty(std::string key)
{
	axis2_ctx_t *ctx = NULL;
	if(!key.empty())
	{
		if(this->serviceContext)
		{
			ctx = axis2_svc_ctx_get_base(this->serviceContext, Environment::getEnv());
			axutil_property_t *prop = axis2_ctx_get_property(ctx, Environment::getEnv(), key.c_str());
			if(prop)
			{
				return new Property(key, axutil_property_get_value(prop, Environment::getEnv()));
			}else
			{/** Look for property in the conf ctx */
				axis2_svc_grp_ctx_t *svc_grp_ctx = axis2_svc_ctx_get_parent(this->serviceContext, Environment::getEnv());
				if(svc_grp_ctx)
				{
					axis2_conf_ctx_t *confCtx = axis2_svc_grp_ctx_get_parent(svc_grp_ctx, Environment::getEnv());
					if(confCtx)
					{
						axutil_property_t *prop = axis2_conf_ctx_get_property(confCtx, Environment::getEnv(), key.c_str());
						if(prop)
						{
							return new Property(key, axutil_property_get_value(prop, Environment::getEnv()));
						}
					}
				}
			}
		}
	}
	return NULL;
}

bool ServiceSkeleton::setProperty(wso2wsf::ContextType type, std::string key, wso2wsf::Property *prop)
{
	axis2_ctx_t *ctx = NULL;
	axis2_svc_ctx_t *svc_ctx = NULL;
	if(key.empty())
		return false;

	if(type == SERVICE_CONTEXT)
	{
		axutil_property_t *axprop = axutil_property_create_with_args(Environment::getEnv(),
			prop->getScope(),AXIS2_TRUE , NULL, prop->getValue());
		ctx = axis2_svc_ctx_get_base(this->serviceContext, Environment::getEnv());
		axis2_ctx_set_property(ctx, Environment::getEnv(), key.c_str(), axprop);
		return true;
	}else if(type == CONFIGURATION_CONTEXT)
	{
		
		axis2_svc_grp_ctx_t *svc_grp_ctx = axis2_svc_ctx_get_parent(this->serviceContext, Environment::getEnv());
		if(svc_grp_ctx)
		{
			axis2_conf_ctx_t *conf_ctx = axis2_svc_grp_ctx_get_parent(svc_grp_ctx, Environment::getEnv());
			if(conf_ctx)
			{
				axutil_property_t *axprop = axutil_property_create_with_args(Environment::getEnv(),
				prop->getScope(), AXIS2_TRUE, NULL, prop->getValue());
				axis2_conf_ctx_set_property(conf_ctx, Environment::getEnv(), key.c_str(), axprop);
				return true;
			}
		}
	}
	return false;
}

void ServiceSkeleton::setServiceContext(axis2_svc_ctx_t *svcCtx)
{
	this->serviceContext = svcCtx;

}