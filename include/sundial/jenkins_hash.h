

#ifndef SUNDIAL_JENKINS_HASH_H_INCLUDED_
#define SUNDIAL_JENKINS_HASH_H_INCLUDED_


#include "sundial/sundial.h"
#include <stddef.h>
#include <stdint.h>


ENV_CPP(extern "C" {)


SUNDIAL_API uint32_t jenkins_hash(const void *key, size_t length);


ENV_CPP(})


#endif    /* SUNDIAL_JENKINS_HASH_H_INCLUDED_ */

