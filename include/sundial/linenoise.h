
/* linenoise.h -- guerrilla line editing library against the idea that a
 * line editing lib needs to be 20,000 lines of C code.
 *
 * See linenoise.c for more information.
 *
 * ------------------------------------------------------------------------
 *
 * Copyright (c) 2010, Salvatore Sanfilippo <antirez at gmail dot com>
 * Copyright (c) 2010, Pieter Noordhuis <pcnoordhuis at gmail dot com>
 *
 * All rights reserved.
 * 
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 * 
 *  *  Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *
 *  *  Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimer in the
 *     documentation and/or other materials provided with the distribution.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */


#ifndef SUNDIAL_LINENOSE_H_INCLUDED_
#define SUNDIAL_LINENOSE_H_INCLUDED_


#include "sundial/sundial.h"
#include <stddef.h>


ENV_CPP(extern "C" {)


typedef struct linenoiseCompletions {
  size_t len;
  char **cvec;
} linenoiseCompletions;


typedef void(linenoiseCompletionCallback)(const char *, linenoiseCompletions *);


SUNDIAL_API void linenoiseSetCompletionCallback(linenoiseCompletionCallback *);
SUNDIAL_API void linenoiseAddCompletion(linenoiseCompletions *, const char *);


SUNDIAL_API char *linenoise(const char *prompt);
SUNDIAL_API int linenoiseHistoryAdd(const char *line);
SUNDIAL_API int linenoiseHistorySetMaxLen(int len);
SUNDIAL_API int linenoiseHistorySave(const char *filename);
SUNDIAL_API int linenoiseHistoryLoad(const char *filename);
SUNDIAL_API void linenoiseClearScreen(void);
SUNDIAL_API void linenoiseSetMultiLine(int ml);
SUNDIAL_API void linenoisePrintKeyCodes(void);


ENV_CPP(})


#endif /* SUNDIAL_LINENOSE_H_INCLUDED_ */

