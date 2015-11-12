#include "GameAchievement.h"

const char *LGMGAGetName(LGMTHIS_ const LGMGameAchievement *pga) {
    return pga->x_name;
}

void LGMGASetAchieved(LGMTHIS_ LGMGameAchievement *pga, bool achieved) {
    pga->x_achieved = achieved;
}

bool LGMGAGetAchieved(LGMTHIS_ const LGMGameAchievement *pga) {
    return pga->x_achieved;
}

bool LGMGANil(LGMTHIS_ LGMGameAchievement *pgi) {
    return pgi->x_nil;
}

bool LGMGANilC(LGMTHIS_ const LGMGameAchievement *pgi) {
    return pgi->x_nil;
}

LGMGameAchievement *LGMGAPrev(LGMTHIS_ LGMGameAchievement *pga) {
    return pga->x_prev;
}
const LGMGameAchievement *LGMGAPrevC(LGMTHIS_ const LGMGameAchievement *pga) {
    return pga->x_prev;
}

LGMGameAchievement *LGMGANext(LGMTHIS_ LGMGameAchievement *pga) {
    return pga->x_next;
}

const LGMGameAchievement *LGMGANextC(LGMTHIS_ const LGMGameAchievement *pga) {
    return pga->x_next;
}

