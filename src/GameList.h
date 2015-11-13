#ifndef LOWGM_GAME_LIST_H_
#define LOWGM_GAME_LIST_H_

#ifndef LOWGM_IMPLEMENTATION_
#   error "Invalid use of this file."
#endif  // LOWGM_IMPLEMENTATION_

#include "Common.h"

#include "GameInfo.h"
#include "IteratorC.h"

struct LGMGameList_ {
    // The nil object for games.
    LGMGameInfo x_gis;
    // The bitset to determine whether an iterator is ready.
    unsigned x_rdy;
    // For internal use.
    LGMGameList *x_next;
};

// Basics.
bool GLStartup();
void GLCleanup();

// Creates an LGMGameList.
LGMGameList *GLCreate();

// Destroys an LGMGameList.
void GLDestroy(LGMIN_ LGMGameList *pgl);

#endif  // LOWGM_GAME_LIST_H_

