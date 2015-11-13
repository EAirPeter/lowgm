#ifndef LOWGM_COMMON_H_
#define LOWGM_COMMON_H_

#ifndef LOWGM_IMPLEMENTATION_
#   error "Invalid use of this file."
#endif  // LOWGM_IMPLEMENTATION_

#include "../include/lowgm.h"

#include <stddef.h>

#define nullptr NULL

#define UNUSED(x_) ((void) sizeof((ptrdiff_t) (x_)))

#endif  // LOWGM_COMMON_H_
