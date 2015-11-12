#ifndef LOWGM_GAME_ACHIEVEMENT_H_
#define LOWGM_GAME_ACHIEVEMENT_H_

#include "Common.h"

struct LGMGameAchievement_ {
    // Name of the achievement
    char x_name[256];
    // Whether the achievement has already been achieved.
    bool x_achieved;
    // For iterating use.
    bool x_nil;
    LGMGameAchievement  *x_prev, *x_next;
};

// Initializes an LGMGameAchievement to nil.
void GAInitNil(LGMTHIS_ LGMGameAchievement *pga);

// Creates an LGMGameAchievement with name.
LGMGameAchievement *GACreate(LGMIN_ const char *name);

// Destroy an LGMGameAchievement.
void *GADestroy(LGMIN_ LGMGameAchievement *pga);

// Links two LGMGameAchievement s.
void GALink(LGMIN_ LGMGameAchievement *lhs, LGMIN_ LGMGameAchievement *rhs);

#endif  // LOWGM_GAME_ACHIEVEMENT_H_

