/* -*- Mode: C; tab-width: 8; indent-tabs-mode: t; c-basic-offset: 8 -*- */

#include <stdlib.h>
#include <locale.h>
#include <libebook/libebook.h>

#include "data-test-utils.h"

gint
main (gint argc,
      gchar **argv)
{
	MoveByData *data;

#if !GLIB_CHECK_VERSION (2, 35, 1)
	g_type_init ();
#endif
	g_test_init (&argc, &argv, NULL);

	g_assert (g_setenv ("MIGRATION_TEST_SOURCE_NAME", "migration-test-source", TRUE));

	/* This test actually creates the addressbook, subsequent migration tests dont
	 * recreate the contacts but rely on the addressbook to have migrated the sort keys
	 * into the new locales
	 */
	data = move_by_test_new ("/EbSdbCursor/Locale/POSIX/Initial", "POSIX");
	move_by_test_add_assertion (data, 5, 11, 2,  6,  3,  8);
	move_by_test_add_assertion (data, 5, 1,  5,  4,  7,  15);
	move_by_test_add_assertion (data, 5, 17, 16, 18, 10, 14);
	move_by_test_add_assertion (data, 5, 12, 13, 9,  19, 20);
	move_by_test_add (data, FALSE);

	/* On this case, we want to delete the work directory and start afresh */
	return e_test_server_utils_run ();
}