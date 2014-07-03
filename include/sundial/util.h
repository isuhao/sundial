
/*
 * Wrappers around strtoull/strtoll that are safer and easier to
 * use.  For tests and assumptions, see internal_tests.c.
 *
 * str   a NULL-terminated base decimal 10 unsigned integer
 * out   out parameter, if conversion succeeded
 *
 * returns true if conversion succeeded.
 */


#ifndef SUNDIAL_UTIL_H_INCLUDED_
#define SUNDIAL_UTIL_H_INCLUDED_


#include "sundial/sds.h"
#include "sundial/sundial.h"
#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>


ENV_CPP(extern "C" {)


SUNDIAL_API bool safe_strtoull(const char *str, uint64_t *out);
SUNDIAL_API bool safe_strtoll(const char *str, int64_t *out);
SUNDIAL_API bool safe_strtoul(const char *str, uint32_t *out);
SUNDIAL_API bool safe_strtol(const char *str, int32_t *out);

#ifndef HAVE_HTONLL
SUNDIAL_API uint64_t htonll(uint64_t);
SUNDIAL_API uint64_t ntohll(uint64_t);
#endif

#ifdef __GCC
# define __gcc_attribute__ __attribute__
#else
# define __gcc_attribute__(x)
#endif

/**
 * Vararg variant of perror that makes for more useful error messages
 * when reporting with parameters.
 *
 * @param fmt a printf format
 */
SUNDIAL_API void vperror(const char *fmt, ...)
    __gcc_attribute__ ((format (printf, 1, 2)));


int stringmatchlen(const char *p, int plen, const char *s, int slen, int nocase);
int stringmatch(const char *p, const char *s, int nocase);
long long memtoll(const char *p, int *err);
int ll2string(char *s, size_t len, long long value);
int string2ll(const char *s, size_t slen, long long *value);
int string2l(const char *s, size_t slen, long *value);
int d2string(char *buf, size_t len, double value);
sds getAbsolutePath(char *filename);
int pathIsBaseName(char *path);

ENV_CPP(})


#endif /* SUNDIAL_UTIL_H_INCLUDED_ */

