#define LOWGM_IMPLEMENTATION_

#include "GameAchievement.h"

#include "GameInfo.h"

#include <stdlib.h>
#include <string.h>

const char *LGMGAGetName(LGMTHIS_ const LGMGameAchievement *pga) {
    return pga->x_name;
}

void LGMGASetAchieved(LGMTHIS_ LGMGameAchievement *pga, bool achieved) {
    if (pga->x_achieved ^ achieved) {
        pga->x_achieved ? --pga->x_pgi->x_nach : ++pga->x_pgi->x_nach;
        pga->x_achieved = achieved;
    }
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

// Internals

static LGMGameAchievement *x_gas = nullptr;

void GAInitNil(LGMTHIS_ LGMGameAchievement *pga, LGMIN_ LGMGameInfo *pgi) {
    pga->x_pgi = pgi;
    pga->x_nil = true;
    pga->x_prev = pga;
    pga->x_next = pga;
}

LGMGameAchievement *GACreate(LGMIN_ LGMGameInfo *pgi, LGMIN_ const char *name)
{
    LGMGameAchievement *pga = x_gas;
    if (pga)
        x_gas = pga->x_next;
    else if (!(pga = (LGMGameAchievement *)
        malloc(sizeof(LGMGameAchievement))))
    {
        return nullptr;
    }
    pga->x_pgi = pgi;
    strcpy(pga->x_name, name);
    pga->x_achieved = false;
    pga->x_nil = false;
    return pga;
}

void GADestroy(LGMIN_ LGMGameAchievement *pga) {
    pga->x_next = x_gas;
    x_gas = pga;
}

void GALink(LGMIN_ LGMGameAchievement *lhs, LGMIN_ LGMGameAchievement *rhs) {
    lhs->x_next = rhs;
    rhs->x_prev = lhs;
}

bool GAStartup() {
    x_gas = nullptr;
    return true;
}

void GACleanup() {
    for (LGMGameAchievement *i = x_gas; i; ) {
        LGMGameAchievement *p = i;
        i = i->x_next;
        free(p);
    }
}

