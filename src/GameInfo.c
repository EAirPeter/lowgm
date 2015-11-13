#define LOWGM_IMPLEMENTATION_

#include "GameInfo.h"

#include <stdlib.h>
#include <string.h>

const char *LGMGIGetName(LGMTHIS_ const LGMGameInfo *pgi) {
    return pgi->x_name;
}

bool LGMGISetDesc(LGMTHIS_ LGMGameInfo *pgi, const char *desc) {
    if (strlen(desc) >= LGM_BUFSIZE)
        return false;
    strcpy(pgi->x_desc, desc);
    return true;
}

const char *LGMGIGetDesc(LGMTHIS_ const LGMGameInfo *pgi) {
    return pgi->x_desc;
}

void LGMGISetTime(LGMTHIS_ LGMGameInfo *pgi, unsigned time) {
    pgi->x_time = time;
}

unsigned LGMGIGetTime(LGMTHIS_ const LGMGameInfo *pgi) {
    return pgi->x_time;
}

LGMGameAchievement *LGMGIAchAdd(LGMTHIS_ LGMGameInfo *pgi,
    LGMIN_ const char *name)
{
    if (strlen(name) >= LGM_BUFSIZE)
        return nullptr;
    //for (LGMGameAchievement *i = pgi->x_achs.x_next; !i->x_nil; i = i->x_next)
    //    if (!strcmp(i->x_name, name))
    //        return nullptr;
    LGMGameAchievement *pga = GACreate(pgi, name);
    if (!pga)
        return nullptr;
    ++pgi->x_mach;
    GALink(pgi->x_achs.x_prev, pga);
    GALink(pga, &pgi->x_achs);
    return pga;
}

bool LGMGIAchRemove(LGMIN_ LGMGameAchievement *pga) {
    if (pga->x_nil)
        return false;
    GALink(pga->x_prev, pga->x_next);
    if (pga->x_achieved)
        --pga->x_pgi->x_nach;
    --pga->x_pgi->x_mach;
    GADestroy(pga);
    return true;
}

LGMGameAchievement *LGMGIAchNil(LGMTHIS_ LGMGameInfo *pgi) {
    return &pgi->x_achs;
}

const LGMGameAchievement *LGMGIAchNilC(LGMTHIS_ const LGMGameInfo *pgi) {
    return &pgi->x_achs;
}

LGMGameVenDesc *LGMGIVenAdd(LGMTHIS_ LGMGameInfo *pgi,
    LGMIN_ const char *desc)
{
    if (strlen(desc) >= LGM_BUFSIZE)
        return nullptr;
    LGMGameVenDesc *pvd = VDCreate(desc);
    if (!pvd)
        return nullptr;
    VDLink(pgi->x_vens.x_prev, pvd);
    VDLink(pvd, &pgi->x_vens);
    return pvd;
}

bool LGMGIVenRemove(LGMIN_ LGMGameVenDesc *pvd) {
    if (pvd->x_nil)
        return false;
    VDLink(pvd->x_prev, pvd->x_next);
    VDDestroy(pvd);
    return true;
}

LGMGameVenDesc *LGMGIVenNil(LGMTHIS_ LGMGameInfo *pgi) {
    return &pgi->x_vens;
}

const LGMGameVenDesc *LGMGIVenNilC(LGMTHIS_ const LGMGameInfo *pgi) {
    return &pgi->x_vens;
}

bool LGMGINil(LGMTHIS_ LGMGameInfo *pgi) {
    return pgi->x_nil;
}

bool LGMGINilC(LGMTHIS_ const LGMGameInfo *pgi) {
    return pgi->x_nil;
}

LGMGameInfo *LGMGIPrev(LGMTHIS_ LGMGameInfo *pgi) {
    return pgi->x_prev;
}

const LGMGameInfo *LGMGIPrevC(LGMTHIS_ const LGMGameInfo *pgi) {
    return pgi->x_prev;
}

LGMGameInfo *LGMGINext(LGMTHIS_ LGMGameInfo *pgi) {
    return pgi->x_next;
}

const LGMGameInfo *LGMGINextC(LGMTHIS_ const LGMGameInfo *pgi) {
    return pgi->x_next;
}

// Internals

static LGMGameInfo *x_gis = nullptr;

void GIInitNil(LGMTHIS_ LGMGameInfo *pgi) {
    pgi->x_nil = true;
    pgi->x_prev = pgi;
    pgi->x_next = pgi;
}

LGMGameInfo *GICreate(LGMIN_ const char *name) {
    LGMGameInfo *pgi = x_gis;
    if (pgi)
        x_gis = pgi->x_next;
    else if (!(pgi = (LGMGameInfo *) malloc(sizeof(LGMGameInfo))))
        return nullptr;
    strcpy(pgi->x_name, name);
    strcpy(pgi->x_desc, "");
    pgi->x_time = 0U;
    pgi->x_nach = 0U;
    pgi->x_mach = 0U;
    GAInitNil(&pgi->x_achs, pgi);
    VDInitNil(&pgi->x_vens);
    pgi->x_nil = false;
    return pgi;
}

void GIDestroy(LGMIN_ LGMGameInfo *pgi) {
    for (LGMGameAchievement *i = pgi->x_achs.x_next; !i->x_nil; ) {
        LGMGameAchievement *p = i;
        i = i->x_next;
        GADestroy(p);
    }
    for (LGMGameVenDesc *i = pgi->x_vens.x_next; !i->x_nil; ) {
        LGMGameVenDesc *p = i;
        i = i->x_next;
        VDDestroy(p);
    }
    pgi->x_next = x_gis;
    x_gis = pgi;
}

void GILink(LGMIN_ LGMGameInfo *lhs, LGMIN_ LGMGameInfo *rhs) {
    lhs->x_next = rhs;
    rhs->x_prev = lhs;
}

void GILinkC(LGMIN_ LGMGameInfo *lhs, LGMIN_ LGMGameInfo *rhs,
    LGMIN_ LGMCmp cmp)
{
    lhs->x_nxti[cmp] = rhs;
    rhs->x_prvi[cmp] = lhs;
}

bool GIStartup() {
    x_gis = nullptr;
    return true;
}

void GICleanup() {
    for (LGMGameInfo *i = x_gis; i; ) {
        LGMGameInfo *p = i;
        i = i->x_next;
        free(p);
    }
}

