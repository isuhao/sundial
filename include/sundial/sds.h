
/* SDSLib, A C dynamic strings library
 *
 * Copyright (c) 2006-2010, Salvatore Sanfilippo <antirez at gmail dot com>
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 *   * Redistributions of source code must retain the above copyright notice,
 *     this list of conditions and the following disclaimer.
 *   * Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimer in the
 *     documentation and/or other materials provided with the distribution.
 *   * Neither the name of Redis nor the names of its contributors may be used
 *     to endorse or promote products derived from this software without
 *     specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */


#ifndef SUNDIAL_SDS_H_INCLUDED_
#define SUNDIAL_SDS_H_INCLUDED_


#include "sundial/sundial.h"
#include <sys/types.h>
#include <stdarg.h>


ENV_CPP(extern "C" {)


#define SDS_MAX_PREALLOC (1024*1024)


typedef char *sds;

struct sdshdr {
    int len;
    int free;
    char buf[];
};

SUNDIAL_FUNC inline size_t sdslen(const sds s) {
    struct sdshdr *sh = (void*)(s-(sizeof(struct sdshdr)));
    return sh->len;
}

SUNDIAL_FUNC inline size_t sdsavail(const sds s) {
    struct sdshdr *sh = (void*)(s-(sizeof(struct sdshdr)));
    return sh->free;
}


SUNDIAL_API sds sdsnewlen(const void *init, size_t initlen);
SUNDIAL_API sds sdsnew(const char *init);
SUNDIAL_API sds sdsempty(void);
SUNDIAL_API size_t sdslen(const sds s);
SUNDIAL_API sds sdsdup(const sds s);

SUNDIAL_API void sdsfree(sds s);
SUNDIAL_API size_t sdsavail(const sds s);
SUNDIAL_API sds sdsgrowzero(sds s, size_t len);
SUNDIAL_API sds sdscatlen(sds s, const void *t, size_t len);
SUNDIAL_API sds sdscat(sds s, const char *t);

SUNDIAL_API sds sdscatsds(sds s, const sds t);
SUNDIAL_API sds sdscpylen(sds s, const char *t, size_t len);
SUNDIAL_API sds sdscpy(sds s, const char *t);
SUNDIAL_API sds sdscatvprintf(sds s, const char *fmt, va_list ap);
#ifdef __GNUC__
SUNDIAL_API sds sdscatprintf(sds s, const char *fmt, ...)
    __attribute__((format(printf, 2, 3)));
#else
SUNDIAL_API sds sdscatprintf(sds s, const char *fmt, ...);
#endif

SUNDIAL_API sds sdscatfmt(sds s, char const *fmt, ...);
SUNDIAL_API sds sdstrim(sds s, const char *cset);
SUNDIAL_API void sdsrange(sds s, int start, int end);
SUNDIAL_API void sdsupdatelen(sds s);
SUNDIAL_API void sdsclear(sds s);

SUNDIAL_API int sdscmp(const sds s1, const sds s2);
SUNDIAL_API sds *sdssplitlen(const char *s, int len, const char *sep, int seplen,
    int *count);
SUNDIAL_API void sdsfreesplitres(sds *tokens, int count);
SUNDIAL_API void sdstolower(sds s);
SUNDIAL_API void sdstoupper(sds s);

SUNDIAL_API sds sdsfromlonglong(long long value);
SUNDIAL_API sds sdscatrepr(sds s, const char *p, size_t len);
SUNDIAL_API sds *sdssplitargs(const char *line, int *argc);
SUNDIAL_API sds sdsmapchars(sds s, const char *from, const char *to, size_t setlen);
SUNDIAL_API sds sdsjoin(char **argv, int argc, char *sep);

/* Low level functions exposed to the user API */
SUNDIAL_API sds sdsMakeRoomFor(sds s, size_t addlen);
SUNDIAL_API void sdsIncrLen(sds s, int incr);
SUNDIAL_API sds sdsRemoveFreeSpace(sds s);
SUNDIAL_API size_t sdsAllocSize(sds s);


ENV_CPP(})


#endif /* SUNDIAL_SDS_H_INCLUDED_ */

