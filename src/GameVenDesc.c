#include "GameVenDesc.h"

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

