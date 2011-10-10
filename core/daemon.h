/*
 *
 * Copyright (C) 2011 Colin Patrick McCabe <cmccabe@alumni.cmu.edu>
 *
 * This is licensed under the Apache License, Version 2.0.  See file COPYING.
 */

#ifndef DUTILS_CORE_DAEMON_DOT_H
#define DUTILS_CORE_DAEMON_DOT_H

#include "core/log_config.h"

#define JORM_CUR_FILE "core/daemon.jorm"
#include "jorm/jorm_generate_include.h"
#undef JORM_CUR_FILE

#if 0 /* Give the dependency scanner a clue */
#include "core/daemon.jorm"
#endif

#endif
