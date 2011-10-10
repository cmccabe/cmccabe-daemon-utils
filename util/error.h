/*
 *
 * Copyright 2011, Colin Patrick McCabe <cmccabe@alumni.cmu.edu>
 *
 * This is licensed under the Apache License, Version 2.0.  See file COPYING.
 */

#ifndef DUTILS_UTIL_ERROR_H
#define DUTILS_UTIL_ERROR_H

#include "util/compiler.h"

#include <stdint.h>

#define DUTILS_MAX_ERR 1024

/*
 * Scheme for packing error codes into pointers.
 */
static inline void *ERR_PTR(int error) {
  return (void*)(uintptr_t)error;
}

static inline int PTR_ERR(const void *ptr) {
  return (int)(uintptr_t)ptr;
}

static inline int IS_ERR(const void *ptr) {
  return unlikely((uintptr_t)ptr < (uintptr_t)DUTILS_MAX_ERR);
}

#define RETRY_ON_EINTR(ret, expr) do { \
  ret = expr; \
} while ((ret == -1) && (errno == EINTR));

#define FORCE_NEGATIVE(e) ((e > 0) ? -e : e)

#define DUTILS_TEMP_ERROR 6000

#endif
