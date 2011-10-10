/*
 *
 * Copyright (C) 2011 Colin Patrick McCabe <cmccabe@alumni.cmu.edu>
 *
 * This is licensed under the Apache License, Version 2.0.  See file COPYING.
 */

#include "jorm/jorm_const.h"

#include <stdlib.h> /* for calloc, realloc */
#include <string.h> /* for memmove */

#define JORM_CONTAINER_BEGIN(ty) \
struct ty* JORM_ARRAY_APPEND_##ty(struct ty ***arr) { \
	struct ty **narr; \
	int i; \
	if (*arr == JORM_INVAL_ARRAY) { \
		i = 0; \
		narr = calloc(0 + 2, sizeof(struct ty*)); \
		if (!narr) \
			return NULL; \
		*arr = narr; \
	} \
	else { \
		/* find the current array size */ \
		for (i = 0; (*arr)[i] != NULL; ++i) { \
			; \
		} \
		narr = realloc(*arr, (i + 2) * sizeof(struct ty*)); \
		if (!narr) \
			return NULL; \
		*arr = narr; \
	} \
	narr[i+1] = NULL; \
	narr[i] = JORM_INIT_##ty(); \
	if (!narr[i]) \
		return NULL; \
	return narr[i]; \
} \
\
void JORM_ARRAY_REMOVE_##ty(struct ty ***arr, struct ty *elem) { \
	struct ty **xarr; \
	int tw, nw; \
	if (*arr == NULL) \
		return; \
	for (nw = 0, tw = 0; (*arr)[tw]; ++tw) { \
		if ((*arr)[tw] == elem) { \
			nw = tw; \
			break; \
		} \
	} \
	for (; (*arr)[tw]; ++tw) { \
		; \
	} \
	if (nw == tw) \
		return; \
	JORM_FREE_##ty((*arr)[nw]); \
	memmove((*arr) + nw, (*arr) + nw + 1, \
		sizeof(struct ty*) * (tw - nw - 1)); \
	(*arr)[tw - 1] = NULL; \
	xarr = realloc(*arr, sizeof(struct ty*) * tw); \
	if (xarr) \
		*arr = xarr; \
} \
\
void JORM_ARRAY_FREE_##ty(struct ty ***arr) { \
	struct ty **a; \
	if (*arr == JORM_INVAL_ARRAY) \
		return; \
	for (a = *arr; *a; ++a) { \
		JORM_FREE_##ty(*a); \
	} \
	free(*arr); \
	*arr = JORM_INVAL_ARRAY; \
} \
\
struct ty** JORM_ARRAY_COPY_##ty(struct ty **arr) { \
	int i, slen = 0; \
	struct ty **narr; \
	if (*arr != JORM_INVAL_ARRAY) { \
		for (; arr[slen]; ++slen) { \
			; \
		} \
	} \
	narr = calloc(slen + 1, sizeof(struct ty*)); \
	if (!narr) \
		return NULL; \
	for (i = 0; i < slen; ++i) { \
		narr[i] = JORM_INIT_##ty(); \
		if ((!narr[i]) || JORM_COPY_##ty(arr[i], narr[i])) { \
			for (--i; i > 0; --i) { \
				JORM_FREE_##ty(narr[i]); \
				free(narr); \
				return NULL; \
			} \
		} \
	} \
	return narr; \
}

#define JORM_INT(name)
#define JORM_DOUBLE(name)
#define JORM_STR(name)
#define JORM_NESTED(name, ty)
#define JORM_EMBEDDED(name, ty)
#define JORM_BOOL(name)
#define JORM_ARRAY(name, ty)
#define JORM_CONTAINER_END
#define JORM_IGNORE(x)
