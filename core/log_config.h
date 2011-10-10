/*
 *
 * Copyright (C) 2011 Colin Patrick McCabe <cmccabe@alumni.cmu.edu>
 *
 * This is licensed under the Apache License, Version 2.0.  See file COPYING.
 */

#ifndef DUTILS_CORE_LOG_CONFIG_DOT_H
#define DUTILS_CORE_LOG_CONFIG_DOT_H

#include "core/daemon_type.h"

#define JORM_CUR_FILE "core/log_config.jorm"
#include "jorm/jorm_generate_include.h"
#undef JORM_CUR_FILE

#if 0 /* Give the dependency scanner a clue */
#include "core/log_config.jorm"
#endif

#include <unistd.h> /* for size_t */

struct json_object;

/** Harmonize the log_config structure.
 * Mostly, this means filling in defaults based on base_dir.
 *
 * @param lc		The log_config
 * @param err		output buffer for errors
 * @param err_len	length of error buffer
 * @param want_mkdir	True if we want to make base_dir if it doesn't exist
 * @param mon		True if we want to fill in the monitor-only fields
 */
void harmonize_log_config(struct log_config *lc,
		char *err, size_t err_len, int want_mkdir, int mon);

#endif
