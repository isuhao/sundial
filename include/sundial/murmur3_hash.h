
/* MurmurHash3 was written by Austin Appleby, and is placed in the public
 * domain. The author hereby disclaims copyright to this source code.
 */


#ifndef SUNDIAL_MURMUR3_HASH_H_INCLUDED_
#define SUNDIAL_MURMUR3_HASH_H_INCLUDED_


#include "sundial/sundial.h"
#include <stddef.h>
#include <stdint.h>


ENV_CPP(extern "C" {)


SUNDIAL_API uint32_t MurmurHash3_x86_32(const void *key, size_t length);


ENV_CPP(})


#endif /* SUNDIAL_MURMUR3_HASH_H_INCLUDED_ */

