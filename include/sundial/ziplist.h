
/*
 * Copyright (c) 2009-2012, Pieter Noordhuis <pcnoordhuis at gmail dot com>
 * Copyright (c) 2009-2012, Salvatore Sanfilippo <antirez at gmail dot com>
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


#ifndef SUNDIAL_ZIPLIST_H_INCLUDED_
#define SUNDIAL_ZIPLIST_H_INCLUDED_



#include "sundial/sundial.h"
#include <stddef.h>


ENV_CPP(extern "C" {)


#define ZIPLIST_HEAD 0
#define ZIPLIST_TAIL 1


SUNDIAL_API unsigned char *ziplistNew(void);
SUNDIAL_API unsigned char *ziplistPush(unsigned char *zl, unsigned char *s,
    unsigned int slen, int where);
SUNDIAL_API unsigned char *ziplistIndex(unsigned char *zl, int index);
SUNDIAL_API unsigned char *ziplistNext(unsigned char *zl, unsigned char *p);
SUNDIAL_API unsigned char *ziplistPrev(unsigned char *zl, unsigned char *p);

SUNDIAL_API unsigned int ziplistGet(unsigned char *p, unsigned char **sval,
    unsigned int *slen, long long *lval);
SUNDIAL_API unsigned char *ziplistInsert(unsigned char *zl, unsigned char *p,
    unsigned char *s, unsigned int slen);
SUNDIAL_API unsigned char *ziplistDelete(unsigned char *zl, unsigned char **p);
SUNDIAL_API unsigned char *ziplistDeleteRange(unsigned char *zl, unsigned int index,
    unsigned int num);

SUNDIAL_API unsigned int ziplistCompare(unsigned char *p, unsigned char *s,
    unsigned int slen);
SUNDIAL_API unsigned char *ziplistFind(unsigned char *p, unsigned char *vstr,
    unsigned int vlen, unsigned int skip);
SUNDIAL_API unsigned int ziplistLen(unsigned char *zl);
SUNDIAL_API size_t ziplistBlobLen(unsigned char *zl);

/* just for test */
typedef struct zlentry {
    unsigned int prevrawlensize, prevrawlen;
    unsigned int lensize, len;
    unsigned int headersize;
    unsigned char encoding;
    unsigned char *p;
} zlentry;

SUNDIAL_API zlentry zipEntry(unsigned char *p);


ENV_CPP(})


#endif /* SUNDIAL_ZIPLIST_H_INCLUDED_ */

