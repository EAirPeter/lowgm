#ifndef LOWGM_GAME_ACHIEVEMENT_H_
#define LOWGM_GAME_ACHIEVEMENT_H_

#ifndef LOWGM_IMPLEMENTATION_
#   error "Invalid use of this file."
#endif  // LOWGM_IMPLEMENTATION_

#include "Common.h"

struct LGMGameAchievement_ {
    // The LGMGameInfo this belongs to.
    LGMGameInfo *x_pgi;
    // Name of the achievement
    char x_name[256];
    // Whether the achievement has already been achieved.
    bool x_achieved;
    // For iterating use.
    bool x_nil;
    LGMGameAchievement  *x_prev, *x_next;
};

// Basics.
bool GAStartup();
void GACleanup();

// Initializes an LGMGameAchievement to nil.
void GAInitNil(LGMTHIS_ LGMGameAchievement *pga, LGMIN_ LGMGameInfo *pgi);

// Creates an LGMGameAchievement with name.
LGMGameAchievement *GACreate(LGMIN_ LGMGameInfo *pgi, LGMIN_ const char *name);

// Destroy an LGMGameAchievement.
void GADestroy(LGMIN_ LGMGameAchievement *pga);

// Links two LGMGameAchievement s.
void GALink(LGMIN_ LGMGameAchievement *lhs, LGMIN_ LGMGameAchievement *rhs);

#endif  // LOWGM_GAME_ACHIEVEMENT_H_

