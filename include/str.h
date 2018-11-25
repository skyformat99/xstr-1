#ifndef _XSTR_H
#define _XSTR_H

#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <limits.h>

/* Types and stuff */
struct
{
	char * val;
	uint16_t cap;
	uint16_t len;
} typedef * _xstr_t;

char typedef ** xstr_t;

typedef enum
{
	XE_NONE = 0,
	XE_ALLOC,
	XE_OTHER
} x_error_t;

/* Functions and stuff */
x_error_t xstr_init(xstr_t * dest, uint16_t size);

x_error_t xstr_set(xstr_t dest, const char * src);

x_error_t xstr_cpy(xstr_t dest, xstr_t src);

x_error_t xstr_cat(xstr_t dest, xstr_t src);

x_error_t xstr_cat_c(xstr_t dest, const char * src);

inline x_error_t str_init_set(xstr_t dest, const char * src);

inline x_error_t xstr_free(xstr_t src);

/* Inline functions */
inline x_error_t str_init_set(xstr_t dest, const char * src)
{
	_xstr_t str;

	str = NULL;

	xstr_init((xstr_t *) &str, strlen(src));

	if (str->val != NULL)
	{
		strcpy(str->val, src);
	}

	dest = (xstr_t) str;

	return XE_NONE;
}

inline x_error_t xstr_free(xstr_t src)
{
	_xstr_t _src;

	_src = (_xstr_t) src;

	free(_src->val);
	_src->cap = 0;
	_src->val = NULL;

	return XE_NONE;
}

#endif