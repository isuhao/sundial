

#ifndef SUNDIAL_CRC64_H_INCLUDED_
#define SUNDIAL_CRC64_H_INCLUDED_


#include "sundial/sundial.h"
#include <stdint.h>


ENV_CPP(extern "C" {)


SUNDIAL_API uint64_t crc64(uint64_t crc, const unsigned char *s, uint64_t l);


ENV_CPP(})


#endif /* SUNDIAL_CRC64_H_INCLUDED_ */

