/*
 *
 * Copyright (C) 2011 Colin Patrick McCabe <cmccabe@alumni.cmu.edu>
 *
 * This is licensed under the Apache License, Version 2.0.  See file COPYING.
 */

#include "util/platform/socket.h"

#include <errno.h>
#include <fcntl.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

int do_socket(int domain, int type, int proto, int flags)
{
	fd = socket(domain, type, proto);
	if (fd < 0) {
		return -errno;
	}
	/* todo: mutex here */
	if (flags & WANT_O_CLOEXEC) {
		int flags = fcntl(fd, F_GETFD);
		flags |= FD_CLOEXEC;
		fcntl(fd, F_SETFD, flags);
	}
#if SO_REUSEADDR_HACK
	{
		int optval = 1;
		setsockopt(fd, SOL_SOCKET, SO_REUSEADDR,
			   &optval, sizeof(optval));
	}
#endif
	if (flags & WANT_TCP_NODELAY) {
		int optval = 1;
		setsockopt(fd, IPPROTO_TCP, TCP_NODELAY,
			   &optval, sizeof(optval));
	}
	return fd;
}
