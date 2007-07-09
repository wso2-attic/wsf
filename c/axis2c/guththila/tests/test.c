#include <check.h>
#include <guththila.h>
#include "guththila_defines.h"
#include "test.h"


void
setup (void)
{
allocator = axutil_allocator_init(NULL);
env = axutil_env_create(allocator);
}

void
teardown (void)
{
 guththila_reader_free(env, red);
 guththila_free(env, parser);
 axutil_env_free(env);
}

START_TEST (test_guththila)
{
	red = guththila_reader_create_for_file(env, "resources/om/axis.xml");
    parser = guththila_create(env, red);
	fail_if (red == NULL, "guththila reader failed");
	fail_if (parser == NULL, "guththila parser failed");
}
END_TEST

START_TEST (test_guththila_start_element)
{
	int c = 0;
	char *p;
	red = guththila_reader_create_for_file(env, "resources/om/axis.xml");
    parser = guththila_create(env, red);
	guththila_read (env, parser);
	c = guththila_next (env, parser);

    while ((c != GUTHTHILA_START_ELEMENT))
		c = guththila_next (env, parser);
	p = guththila_get_name(env, parser);
	fail_unless ((c == GUTHTHILA_START_ELEMENT), "no start element found");
	fail_if ((p == NULL), "no name found");
	fail_unless (!strcmp (p, "root"), "root element differed");
	c = 0;

    while ((c != GUTHTHILA_START_ELEMENT))
		c = guththila_next (env, parser);
	p = guththila_get_name(env, parser);
	fail_unless ((c == GUTHTHILA_START_ELEMENT), "no start element found");
	fail_if ((p == NULL), "no name found");
	fail_unless (!strcmp (p, "a"), "a element differed");

	c = 0;
    while ((c != GUTHTHILA_START_ELEMENT))
		c = guththila_next (env, parser);
	p = guththila_get_name(env, parser);
	fail_unless (!strcmp (p, "b"), "b element differed");
}
END_TEST

START_TEST (test_guththila_empty_element)
{
	int c = 0;
	char *p;
	red = guththila_reader_create_for_file(env, "resources/om/axis.xml");
    parser = guththila_create(env, red);
	guththila_read (env, parser);
	c = guththila_next (env, parser);

    while ((c != GUTHTHILA_EMPTY_ELEMENT))
		c = guththila_next (env, parser);
	p = guththila_get_name(env, parser);
	fail_unless ((c == GUTHTHILA_EMPTY_ELEMENT), "no empty element found");
	fail_if ((p == NULL), "no name found");
	fail_unless (!strcmp (p, "a.1"), "a.1 element differed");

	c = 0;

    while ((c != GUTHTHILA_EMPTY_ELEMENT))
		c = guththila_next (env, parser);
	p = guththila_get_name(env, parser);
	fail_unless ((c == GUTHTHILA_EMPTY_ELEMENT), "no empty element found");
	fail_if ((p == NULL), "no name found");
	fail_unless (!strcmp (p, "a.2"), "a.2 element differed");

	c = 0;
    while ((c != GUTHTHILA_START_ELEMENT))
		c = guththila_next (env, parser);

	c = 0;
    while ((c != GUTHTHILA_EMPTY_ELEMENT))
		c = guththila_next (env, parser);
	p = guththila_get_name(env, parser);
	fail_unless ((c == GUTHTHILA_EMPTY_ELEMENT), "no empty element found");
	fail_if ((p == NULL), "no name found");
	fail_unless (!strcmp (p, "b.1"), "b.1 element differed");
}
END_TEST

START_TEST (test_guththila_end_element)
{
	int c = 0;
	char *p;
	red = guththila_reader_create_for_file(env, "resources/om/axis.xml");
    parser = guththila_create(env, red);
	guththila_read (env, parser);
	c = guththila_next (env, parser);

    while ((c != GUTHTHILA_END_ELEMENT))
		c = guththila_next (env, parser);
	p = guththila_get_name(env, parser);
	fail_unless ((c == GUTHTHILA_END_ELEMENT), "no end element found");
	fail_if ((p == NULL), "no name found");
	fail_unless (!strcmp (p, "a"), "a element differed");

	c = 0;
    while ((c != GUTHTHILA_END_ELEMENT))
		c = guththila_next (env, parser);
	p = guththila_get_name(env, parser);
	fail_unless ((c == GUTHTHILA_END_ELEMENT), "no endelement found");
	fail_if ((p == NULL), "no name found");
	fail_unless (!strcmp (p, "b"), "b element differed");

	c = 0;
    while ((c != GUTHTHILA_END_ELEMENT))
		c = guththila_next (env, parser);
	p = guththila_get_name(env, parser);
	fail_unless ((c == GUTHTHILA_END_ELEMENT), "no empty element found");
	fail_if ((p == NULL), "no name found");
	fail_unless (!strcmp (p, "root"), "root element differed");
}
END_TEST

START_TEST (test_guththila_character)
{
	int c = 0;
	int i = 0;
	char *p;
	red = guththila_reader_create_for_file(env, "resources/om/numbers.xml");
    parser = guththila_create(env, red);
	guththila_read (env, parser);
	c = guththila_next (env, parser);
    while (i < 3)
	{
		if (c == GUTHTHILA_START_ELEMENT)
			i++;
		c = guththila_next (env, parser);
	}

	if (c == GUTHTHILA_CHARACTER)
		p = guththila_get_value(env, parser);
	fail_unless (!strcmp (p, "3"), "3 not found");

	c = 0;
	while ((c != GUTHTHILA_CHARACTER) || (parser->is_whitespace))
		c = guththila_next (env, parser);
	p = guththila_get_value(env, parser);
	fail_unless (!strcmp (p, "24"), "24 not found");

}
END_TEST

Suite *
guththila_suite (void)
{
  Suite *s = suite_create ("Guththila");

  /* Core test case */
  TCase *tc_core = tcase_create ("Core");
  tcase_add_checked_fixture (tc_core, setup, teardown);
  tcase_add_test (tc_core, test_guththila);
  tcase_add_test (tc_core, test_guththila_start_element);
  tcase_add_test (tc_core, test_guththila_empty_element);
  tcase_add_test (tc_core, test_guththila_end_element);
  tcase_add_test (tc_core, test_guththila_character);
  suite_add_tcase (s, tc_core);
  return s;
}


int
main (void)
{
  int number_failed;
  Suite *s = guththila_suite ();
  Suite *att = guththila_attribute_suite ();
  SRunner *sr = srunner_create (s);
  srunner_add_suite (sr, att);
  srunner_set_log (sr, "guththila.log");
  srunner_run_all (sr, CK_NORMAL);
  number_failed = srunner_ntests_failed (sr);
  srunner_free (sr);
  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
