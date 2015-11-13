#define LOWGM_IMPLEMENTATION_

#include "GameSorting.h"

#include <string.h>


LGMGameInfo *GSSort(LGMIN_ LGMGameInfo *beg, LGMIN_ LGMGameInfo *end,
    LGMIN_ GSComparator *cmp)
{
    if (beg->x_next == end) {
        beg->x_next = nullptr;
        return beg;
    }
    LGMGameInfo *mid = beg;
    for (LGMGameInfo *i = end; mid != i && mid->x_next != i;
        mid = mid->x_next, i = i->x_prev);
    beg = GSSort(beg, mid, cmp);
    mid = GSSort(mid, end, cmp);
    LGMGameInfo tmp;
    LGMGameInfo *pgi = &tmp;
    for (LGMGameInfo *i = beg, *j = mid; i || j; ) {
        tmp.x_prev = pgi;
        if (!i) {
            pgi = j;
            j = j->x_next;
        }
        else if (!j) {
            pgi = i;
            i = i->x_next;
        }
        else if (cmp(j, i)) {
            pgi = j;
            j = j->x_next;
        }
        else {
            pgi = i;
            i = i->x_next;
        }
        tmp.x_prev->x_next = pgi;
    }
    pgi->x_next = nullptr;
    return tmp.x_next;
}

LGMGameInfo *GSSortC(LGMIN_ LGMGameInfo *beg, LGMIN_ LGMGameInfo *end,
    LGMIN_ GSComparator *cmp, LGMIN_ LGMCmp idx)
{
    if (beg->x_next == end) {
        beg->x_nxti[idx] = nullptr;
        return beg;
    }
    LGMGameInfo *mid = beg;
    for (LGMGameInfo *i = end; mid != i && mid->x_next != i;
        mid = mid->x_next, i = i->x_prev);
    beg = GSSortC(beg, mid, cmp, idx);
    mid = GSSortC(mid, end, cmp, idx);
    LGMGameInfo tmp;
    LGMGameInfo *pgi = &tmp;
    for (LGMGameInfo *i = beg, *j = mid; i || j; ) {
        tmp.x_prev = pgi;
        if (!i) {
            pgi = j;
            j = j->x_nxti[idx];
        }
        else if (!j) {
            pgi = i;
            i = i->x_nxti[idx];
        }
        else if (cmp(j, i)) {
            pgi = j;
            j = j->x_nxti[idx];
        }
        else {
            pgi = i;
            i = i->x_nxti[idx];
        }
        tmp.x_prev->x_nxti[idx] = pgi;
    }
    pgi->x_nxti[idx] = nullptr;
    return tmp.x_nxti[idx];
}


// Internals

bool X_ByName(LGMIN_ LGMGameInfo *lhs, LGMIN_ LGMGameInfo *rhs) {
    return strcmp(lhs->x_name, rhs->x_name) < 0;
}

bool X_ByDesc(LGMIN_ LGMGameInfo *lhs, LGMIN_ LGMGameInfo *rhs) {
    return strcmp(lhs->x_desc, rhs->x_desc) < 0;
}

bool X_ByTime(LGMIN_ LGMGameInfo *lhs, LGMIN_ LGMGameInfo *rhs) {
    return lhs->x_time < rhs->x_time;
}

bool X_ByAchs(LGMIN_ LGMGameInfo *lhs, LGMIN_ LGMGameInfo *rhs) {
    return lhs->x_nach * rhs->x_mach < rhs->x_nach * lhs->x_mach;
}

GSComparator *const gs_cmps[LGM_ALLCMP_] = {
    X_ByName,
    X_ByDesc,
    X_ByTime,
    X_ByAchs,
};

bool GSStartup() {
    return true;
}

void GSCleanup() {
}

