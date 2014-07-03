

#ifndef SUNDIAL_DAEMON_H_INCLUDED_
#define SUNDIAL_DAEMON_H_INCLUDED_


#include "sundial/sundial.h"


ENV_CPP(extern "C" {)


SUNDIAL_API int daemonize(int nochdir, int noclose);


ENV_CPP(})


#endif /* SUNDIAL_DAEMON_H_INCLUDED_ */

