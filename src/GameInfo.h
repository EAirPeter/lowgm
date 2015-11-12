#ifndef LOWGM_GAME_INFO_H_
#define LOWGM_GAME_INFO_H_

#include "Common.h"

#include "GameAchievement.h"
#include "GameVenDesc.h"

struct LGMGameInfo_ {
    // Name of the game.
    char x_name[256];
    // Description of the game.
    char x_desc[256];
    // The time (in hour) the game has been played for.
    unsigned x_time;
    // The nil object for achievements.
    LGMGameAchievement x_achs;
    // The nil object for descriptions of vendor.
    LGMGameVenDesc x_vens;
    // For iterating use.
    bool x_nil;
    LGMGameInfo *x_prev, *x_next;
};

// Basics
bool GIStartup();
void GICleanup();

// Initializes an LGMGameInfo to nil.
void GIInitNil(LGMTHIS_ LGMGameInfo *pgi);

// Creates an LGMGameInfo with name.
LGMGameInfo *GICreate(LGMIN_ const char *name);

// Destroys an LGMGameInfo.
void GIDestroy(LGMIN_ LGMGameInfo *pgi);

// Links two LGMGameInfo s.
void GILink(LGMIN_ LGMGameInfo *lhs, LGMIN_ LGMGameInfo *rhs);

#endif  // LOWGM_GAME_INFO_H_

