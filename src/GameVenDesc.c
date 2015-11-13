#define LOWGM_IMPLEMENTATION_

#include "GameVenDesc.h"

#include <stdlib.h>
#include <string.h>

const char *LGMVDGet(LGMTHIS_ LGMGameVenDesc *pvd) {
    return pvd->x_desc;
}

bool LGMVDNil(LGMTHIS_ LGMGameVenDesc *pvd) {
    return pvd->x_nil;
}

bool LGMVDNilC(LGMTHIS_ const LGMGameVenDesc *pvd) {
    return pvd->x_nil;
}

LGMGameVenDesc *LGMVDPrev(LGMTHIS_ LGMGameVenDesc *pvd) {
    return pvd->x_prev;
}

const LGMGameVenDesc *LGMVDPrevC(LGMTHIS_ const LGMGameVenDesc *pvd) {
    return pvd->x_prev;
}

LGMGameVenDesc *LGMVDNext(LGMTHIS_ LGMGameVenDesc *pvd) {
    return pvd->x_next;
}

const LGMGameVenDesc *LGMVDNextC(LGMTHIS_ const LGMGameVenDesc *pvd) {
    return pvd->x_next;
}

// Internals

static LGMGameVenDesc *x_vds = nullptr;

void VDInitNil(LGMTHIS_ LGMGameVenDesc *pvd) {
    pvd->x_nil = true;
    pvd->x_prev = pvd;
    pvd->x_next = pvd;
}

LGMGameVenDesc *VDCreate(LGMIN_ const char *desc) {
    LGMGameVenDesc *pvd = x_vds;
    if (pvd)
        x_vds = pvd->x_next;
    else if (!(pvd = (LGMGameVenDesc *) malloc(sizeof(LGMGameVenDesc))))
        return nullptr;
    strcpy(pvd->x_desc, desc);
    pvd->x_nil = false;
    return pvd;
}

void VDDestroy(LGMIN_ LGMGameVenDesc *pvd) {
    pvd->x_next = x_vds;
    x_vds = pvd;
}

void VDLink(LGMIN_ LGMGameVenDesc *lhs, LGMIN_ LGMGameVenDesc *rhs) {
    lhs->x_next = rhs;
    rhs->x_prev = lhs;
}

bool VDStartup() {
    x_vds = nullptr;
    return true;
}

void VDCleanup() {
    for (LGMGameVenDesc *i = x_vds; i; ) {
        LGMGameVenDesc *p = i;
        i = i->x_next;
        free(p);
    }
}

