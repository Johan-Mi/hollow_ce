#define ENEMY HORNET

#define HORNET 1

#if ENEMY == HORNET
#	include "hornet.h"
#else
#	error invalid enemy name specified
#endif
