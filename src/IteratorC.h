#ifndef LOWGM_ITERATOR_C_H_
#define LOWGM_ITERATOR_C_H_

#ifndef LOWGM_IMPLEMENTATION_
#   error "Invalid use of this file."
#endif  // LOWGM_IMPLEMENTATION_

#include "Common.h"

struct LGMIteratorC_ {
    // The LGMGameInfo that this binds to.
    const LGMGameInfo *x_pgi;
    // The comparator.
    LGMCmp x_cmp;
    // For internal use.
    LGMIteratorC *x_next;
};

// Basics.
bool ICStartup();
void ICCleanup();

// Creates an LGMIteratorC.
LGMIteratorC *ICCreate(LGMIN_ const LGMGameInfo *pgi, LGMIN_ LGMCmp cmp);

// Destroys an LGMIteratorC.
void ICDestroy(LGMIN_ LGMIteratorC *pic);

#endif  // LOWGM_ITERATOR_C_H_

