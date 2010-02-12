#include "keystore_admin_util.h"

AXIS2_EXTERN axis2_char_t* AXIS2_CALL 
keystore_admin_util_format_date(const axutil_env_t* env,
								axis2_char_t* str)
{
	axis2_char_t* result = NULL;
	axis2_char_t* year = NULL;
	axis2_char_t* month = NULL;
	axis2_char_t* day = NULL;
	axis2_char_t* tok = NULL;

	if (!str)
		return NULL;

	/* Resolve year, month and day */
	tok = strtok(str, " ");
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
			if (tok) /* Year */
			{
				year = tok;
			}
		}
	}

	result = axutil_strcat(env, day, "/", month, "/", year, NULL);

	return result;
}