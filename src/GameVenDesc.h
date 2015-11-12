#ifndef LOWGM_GAME_VEN_DESC_H_
#define LOWGM_GAME_VEN_DESC_H_

#include "Common.h"

struct LGMGameVenDesc_ {
    // The description.
    char x_desc[256];
    // For iterating use.
    bool x_nil;
    LGMGameVenDesc *x_prev, *x_next;
};

// Initializes an LGMGameVenDesc to nil.
void VDInitNil(LGMTHIS_ LGMGameVenDesc *pvd);

// Creates an LGMGameVenDesc with descrption.
LGMGameVenDesc *VDCreate(const char *desc);

// Destroy an LGMGameVenDesc.
void *VDDestroy(LGMIN_ LGMGameVenDesc *pvd);

// Links two LGMGameVenDescs s.
void VDLink(LGMIN_ LGMGameVenDesc *lhs, LGMIN_ LGMGameVenDesc *rhs);

#endif  // LOWGM_GAME_VEN_DESC_H_

