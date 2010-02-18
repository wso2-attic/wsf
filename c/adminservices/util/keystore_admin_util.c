#include <stdio.h>
#include "axis2_util.h"
#include "keystore_admin_util.h"

AXIS2_EXTERN axis2_status_t AXIS2_CALL 
keystore_admin_util_format_date(const axutil_env_t* env,
								axis2_char_t* src,
								axis2_char_t* result)
{
	axis2_char_t* year = NULL;
	axis2_char_t* month = NULL;
	axis2_char_t* day = NULL;
	axis2_char_t* time = NULL;
	axis2_char_t* tok = NULL;

	if (!src)
		return AXIS2_FAILURE;

	/* Resolve year, month and day */
	tok = strtok(src, " ");
	if (tok)/* Month */
	{
		if (0 == strcmp(tok, "Jan"))
			month = "01";
		else if (0 == strcmp(tok, "Feb"))
			month = "02";
		else if (0 == strcmp(tok, "Mar"))
			month = "03";
		else if (0 == strcmp(tok, "Apr"))
			month = "04";
		else if (0 == strcmp(tok, "May"))
			month = "05";
		else if (0 == strcmp(tok, "Jun"))
			month = "06";
		else if (0 == strcmp(tok, "Jul"))
			month = "07";
		else if (0 == strcmp(tok, "Aug"))
			month = "08";
		else if (0 == strcmp(tok, "Sep"))
			month = "09";
		else if (0 == strcmp(tok, "Oct"))
			month = "10";
		else if (0 == strcmp(tok, "Nov"))
			month = "11";
		else if (0 == strcmp(tok, "Dec"))
			month = "12";

		tok = strtok(NULL, " ");
		if (tok) /* Day */
		{
			day = tok;

			tok = strtok(NULL, " ");
			if (tok) /* Time */
			{
				time = tok;

				tok = strtok(NULL, " ");
				if (tok) /* Year */
				{
					year = tok;
				}
			}
		}
	}

	sprintf(result, "%s/%s/%s %s", day, month, year, time);

	return AXIS2_SUCCESS;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
keystore_admin_util_get_keystore_details(const axutil_env_t* env,
										 axis2_char_t* repo_path,
										 axis2_char_t* keystore_name,
										 axis2_char_t* password,
										 axis2_char_t* provider,
									     axis2_char_t* pvt_key_pass)
{
	axis2_char_t* keystore_details_file = NULL;
	int file_size = 0;
	axis2_char_t* data_buffer = NULL;
	int data_buffer_size = 0;
	FILE* file = NULL;
	axis2_char_t* tok = NULL;

	memset(password, 0, sizeof(password));
	memset(provider, 0, sizeof(provider));
	memset(pvt_key_pass, 0, sizeof(pvt_key_pass));

	/* Load details file */
	keystore_details_file = axutil_strcat(env, repo_path, AXIS2_PATH_SEP_STR, "services", 
		AXIS2_PATH_SEP_STR, "KeyStoreAdminService", AXIS2_PATH_SEP_STR, "keystores", 
		AXIS2_PATH_SEP_STR, keystore_name, ".dat", NULL);

	file = fopen(keystore_details_file, "r");
	AXIS2_FREE(env->allocator, keystore_details_file);
	if (!file) return AXIS2_FAILURE;

	/* Get file size*/
	fseek(file, 0, SEEK_END);
	file_size = ftell(file);
	rewind(file);

	data_buffer_size = (file_size * sizeof(axis2_char_t)) + 1;
	data_buffer = AXIS2_MALLOC(env->allocator, data_buffer_size);
	memset(data_buffer, 0, data_buffer_size);
	fread(data_buffer, sizeof(axis2_char_t), file_size, file);
	fclose(file);

	/* Read data - password|pvt_key_pass|provider*/
	tok = strtok(data_buffer, "|");
	if (tok) sprintf(password, "%s", tok);

	tok = strtok(NULL, "|");
	if (tok) sprintf(pvt_key_pass, "%s", tok);
	
	tok = strtok(NULL, "|");
	if (tok) sprintf(provider, "%s", tok);
	
	return AXIS2_SUCCESS;
}