
/*
 * Copyright (c) 1999,2000,2004 Damien Miller <djm@mindrot.org>
 *
 * Permission to use, copy, modify, and distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */


#ifndef SUNDIAL_ARC4RANDOM_H_INCLUDED
#define SUNDIAL_ARC4RANDOM_H_INCLUDED


#include "sundial/sundial.h"
#include <stddef.h>
#include <stdint.h>
#include <sys/types.h>


ENV_CPP(extern "C" {)


#ifndef HAVE_ARC4RANDOM
SUNDIAL_API unsigned int arc4random(void);
SUNDIAL_API void arc4random_stir(void);
#endif

#ifndef HAVE_ARC4RANDOM_BUF
SUNDIAL_API void arc4random_buf(void *_buf, size_t n);
#endif

#ifndef HAVE_ARC4RANDOM_UNIFORM
SUNDIAL_API uint32_t arc4random_uniform(uint32_t upper_bound);
#endif


ENV_CPP(})


#endif /* SUNDIAL_ARC4RANDOM_H_INCLUDED */

