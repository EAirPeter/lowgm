#ifndef LOWGM_GAME_SORTING_H_
#define LOWGM_GAME_SORTING_H_

#ifndef LOWGM_IMPLEMENTATION_
#   error "Invalid use of this file."
#endif  // LOWGM_IMPLEMENTATION_

#include "Common.h"

#include "GameInfo.h"

typedef bool (GSComparator)(LGMIN_ LGMGameInfo *lhs, LGMIN_ LGMGameInfo *rhs);

extern GSComparator *const gs_cmps[LGM_ALLCMP_];

// Basics.
bool GSStartup();
void GSCleanup();

// Implements LGMGLSort.
LGMGameInfo *GSSort(LGMIN_ LGMGameInfo *beg, LGMIN_ LGMGameInfo *end,
    LGMIN_ GSComparator *cmp);

// Implements LGMGLSortC.
LGMGameInfo *GSSortC(LGMIN_ LGMGameInfo *beg, LGMIN_ LGMGameInfo *end,
    LGMIN_ GSComparator *cmp, LGMIN_ LGMCmp idx);

#endif  // LOWGM_GAME_SORTING_H_

