/*
 *
 * Copyright 2011, Colin Patrick McCabe <cmccabe@alumni.cmu.edu>
 *
 * This is licensed under the Apache License, Version 2.0.  See file COPYING.
 */

#ifndef DUTILS_CORE_DAEMON_TYPE_H
#define DUTILS_CORE_DAEMON_TYPE_H

enum fish_daemon_ty
{
	DUTILS_DAEMON_TYPE_OSD = 0,
	DUTILS_DAEMON_TYPE_MDS = 1,
	DUTILS_DAEMON_TYPE_MON = 2,
	DUTILS_DAEMON_TYPE_NUM = 3,
};

#endif
