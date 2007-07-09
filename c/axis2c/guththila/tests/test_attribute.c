#include <guththila.h>
#include <check.h>
#include "test.h"

START_TEST (test_attribute)
{
	int count = 0;;
	int c = 0;
	guththila_attribute_t *att;
	red = guththila_reader_create_for_file(env, "resources/om/evaluate.xml");
    parser = guththila_create(env, red);
	guththila_read (env, parser);
	c = guththila_next (env, parser);
    while (!count)
	{
		c = guththila_next (env, parser);
		count = guththila_get_attribute_count(env, parser);
		if (count)
			att = guththila_get_attribute (env, parser);
	}
	fail_if (count == 0, "guththila attribute count failed");
	fail_unless (!strcmp (guththila_get_attribute_name (env, parser, att), "color"),
				 "guththila attribute name failed");
	fail_unless (!strcmp (guththila_get_attribute_value (env, parser, att), "brown"),
				 "guththila attribute value failed");
}
END_TEST


START_TEST (test_attribute_prefix)
{
	int count = 0;;
	int c = 0;
	guththila_attribute_t *att;
	red = guththila_reader_create_for_file(env, "resources/soap/soapmessage.xml");
    parser = guththila_create(env, red);
	guththila_read (env, parser);
	c = guththila_next (env, parser);
    while (!count)
	{
		c = guththila_next (env, parser);
		count = guththila_get_attribute_count(env, parser);
		if (count)
			att = guththila_get_attribute (env, parser);
	}
	fail_if (count == 0, "guththila attribute count failed");
	fail_unless (!strcmp (guththila_get_attribute_prefix (env, parser, att), "soapenv"),
				 "guththila attribute count failed");
	fail_unless (!strcmp (guththila_get_attribute_name (env, parser, att), "mustUnderstand"),
				 "guththila attribute count failed");
	fail_unless (!strcmp (guththila_get_attribute_value (env, parser, att), "0"),
				 "guththila attribute count failed");
	count = 0;
    while (!count)
	{
		c = guththila_next (env, parser);
		count = guththila_get_attribute_count(env, parser);
		if (count)
			att = guththila_get_attribute (env, parser);
	}
	fail_unless (!strcmp (guththila_get_attribute_prefix (env, parser, att), "soapenv"),
				 "guththila attribute count failed");
	fail_unless (!strcmp (guththila_get_attribute_name (env, parser, att), "mustUnderstand"),
				 "guththila attribute count failed");
	fail_if (!strcmp (guththila_get_attribute_value (env, parser, att), "1"),
				 "guththila attribute count failed");
}
END_TEST


Suite *
guththila_attribute_suite (void)
{
  Suite *s = suite_create ("Guththila_attribute");

  /* Core test case */
  TCase *tc_core = tcase_create ("attribute");
  tcase_add_checked_fixture (tc_core, setup, teardown);
  tcase_add_test (tc_core, test_attribute);
  tcase_add_test (tc_core, test_attribute_prefix);
  suite_add_tcase (s, tc_core);
  return s;
}
