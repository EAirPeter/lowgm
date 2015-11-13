#define LOWGM_IMPLEMENTATION_

#include "GameSorting.h"

#include <string.h>


LGMGameInfo *GSSort(LGMIN_ LGMGameInfo *beg, LGMIN_ LGMGameInfo *end,
    LGMIN_ GSComparator *cmp)
{
    if (beg->x_next == end)
        return beg;
    LGMGameInfo *mid = beg;
    for (LGMGameInfo *i = end; mid != i && mid->x_next != i;
        mid = mid->x_next, i = i->x_prev);
    mid = GSSort(mid, end, cmp);
    beg = GSSort(beg, mid, cmp);
    LGMGameInfo tmp;
    GIInitNil(&tmp);
    LGMGameInfo *pgi;
    for (LGMGameInfo *i = beg, *j = mid; i != mid || j != end; ) {
        if (i == mid) {
            pgi = j;
            j = j->x_next;
        }
        else if (j == end) {
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
        GILink(tmp.x_prev, pgi);
        GILink(pgi, &tmp);
    }
    return tmp.x_next;
}

LGMGameInfo *GSSortC(LGMIN_ LGMGameInfo *beg, LGMIN_ LGMGameInfo *end,
    LGMIN_ GSComparator *cmp, LGMIN_ LGMCmp idx);


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

