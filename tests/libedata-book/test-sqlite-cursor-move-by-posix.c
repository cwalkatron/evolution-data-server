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

	data = move_by_test_new ("/EbSdbCursor/POSIX/Move/Forward", "POSIX");
	move_by_test_add_assertion (data, 5, 11, 2, 6, 3, 8);
	move_by_test_add_assertion (data, 6, 10, 19, 20, 1, 5, 4);
	move_by_test_add (data, FALSE);

	data = move_by_test_new ("/EbSdbCursor/POSIX/Move/ForwardOnNameless", "POSIX");
	move_by_test_add_assertion (data, 1, 11);
	move_by_test_add_assertion (data, 3, 2, 6, 3);
	move_by_test_add (data, FALSE);

	data = move_by_test_new ("/EbSdbCursor/POSIX/Move/Backwards", "POSIX");
	move_by_test_add_assertion (data, -5, 9, 13, 12, 14, 18);
	move_by_test_add_assertion (data, -12, 16, 17, 15, 7, 4, 5, 1, 20, 19, 10, 8, 3);
	move_by_test_add (data, FALSE);

	data = move_by_test_new ("/EbSdbCursor/POSIX/Filtered/Move/Forward", "POSIX");
	move_by_test_add_assertion (data, 5, 11, 2, 3, 8, 10);
	move_by_test_add_assertion (data, 8, 1, 5, 17, 16, 18, 14, 12, 9);
	move_by_test_add (data, TRUE);

	data = move_by_test_new ("/EbSdbCursor/POSIX/Filtered/Move/Backwards", "POSIX");
	move_by_test_add_assertion (data, -5, 9, 12, 14, 18, 16);
	move_by_test_add_assertion (data, -8, 17, 5, 1, 10, 8, 3, 2, 11);
	move_by_test_add (data, TRUE);

	return e_test_server_utils_run ();
}