#ifndef LOWGM_GAME_INFO_H_
#define LOWGM_GAME_INFO_H_

#ifndef LOWGM_IMPLEMENTATION_
#   error "Invalid use of this file."
#endif  // LOWGM_IMPLEMENTATION_

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
    // The number of achievements already achieved.
    unsigned x_nach;
    // The number of achievements.
    unsigned x_mach;
    // The nil object for achievements.
    LGMGameAchievement x_achs;
    // The nil object for descriptions of vendor.
    LGMGameVenDesc x_vens;
    // For iterating use.
    bool x_nil;
    LGMGameInfo *x_prev, *x_next;
    // For LGMIteratorC use.
    const LGMGameInfo *x_prvi[LGM_ALLCMP_];
    const LGMGameInfo *x_nxti[LGM_ALLCMP_];
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
void GILinkC(LGMIN_ LGMGameInfo *lhs, LGMIN_ LGMGameInfo *rhs,
    LGMIN_ LGMCmp cmp);

#endif  // LOWGM_GAME_INFO_H_

