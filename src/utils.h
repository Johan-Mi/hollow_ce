#pragma once

#define CLAMP_ABOVE(value, minimum) \
	do { \
		if((value) < (minimum)) \
			(value) = (minimum); \
	} while(0)

#define CLAMP_BELOW(value, maximum) \
	do { \
		if((value) > (maximum)) \
			(value) = (maximum); \
	} while(0)
