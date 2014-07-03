
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


#ifndef SUNDIAL_INTSET_H_INCLUDED_
#define SUNDIAL_INTSET_H_INCLUDED_


#include "sundial/sundial.h"
#include <stdint.h>
#include <stddef.h>


ENV_CPP(extern "C" {)


typedef struct intset {
    uint32_t encoding;
    uint32_t length;
    int8_t contents[];
} intset;


SUNDIAL_API intset *intsetNew(void);
SUNDIAL_API intset *intsetAdd(intset *is, int64_t value, uint8_t *success);
SUNDIAL_API intset *intsetRemove(intset *is, int64_t value, int *success);
SUNDIAL_API uint8_t intsetFind(intset *is, int64_t value);
SUNDIAL_API int64_t intsetRandom(intset *is);
SUNDIAL_API uint8_t intsetGet(intset *is, uint32_t pos, int64_t *value);
SUNDIAL_API uint32_t intsetLen(intset *is);
SUNDIAL_API size_t intsetBlobLen(intset *is);

/* just for test */
SUNDIAL_API uint8_t _intsetValueEncoding(int64_t v);
SUNDIAL_API int64_t _intsetGetEncoded(intset *is, int pos, uint8_t enc);
SUNDIAL_API int64_t _intsetGet(intset *is, int pos);
SUNDIAL_API uint8_t intsetSearch(intset *is, int64_t value, uint32_t *pos);

/* Note that these encodings are ordered, so:
 * INTSET_ENC_INT16 < INTSET_ENC_INT32 < INTSET_ENC_INT64. */
#define INTSET_ENC_INT16 (sizeof(int16_t))
#define INTSET_ENC_INT32 (sizeof(int32_t))
#define INTSET_ENC_INT64 (sizeof(int64_t))

ENV_CPP(})


#endif /* SUNDIAL_INTSET_H_INCLUDED_ */

