#include <guththila_token.h>
#include <guththila_attribute.h>

AXIS2_EXTERN guththila_attribute_t *AXIS2_CALL
guththila_attribute_create (
	axutil_env_t *env, 
	guththila_token_t *prefix, 
	guththila_token_t *name, 
	guththila_token_t *value,
	guththila_token_t *namespace_uri)
{
	guththila_attribute_t *att = NULL;
	att =
        (guththila_attribute_t *) AXIS2_MALLOC(env->allocator,
                sizeof (guththila_attribute_t));
    att->name = name;
    att->value = value;
    att->prefix = prefix;
	att->namespace_uri = namespace_uri;
	return att;
}

AXIS2_EXTERN void AXIS2_CALL
guththila_attribute_free (
	axutil_env_t *env,
	guththila_attribute_t *attribute)
{
	if (attribute)
	{
		if (attribute->prefix)
			guththila_token_free (env, attribute->prefix);
		if (attribute->name)
			guththila_token_free (env, attribute->name);
		if (attribute->value)
			guththila_token_free (env, attribute->value);
		if (attribute->namespace_uri)
			guththila_token_free (env, attribute->namespace_uri);
		AXIS2_FREE (env->allocator, attribute);
		attribute = NULL;
	}
}

