#define LOWGM_IMPLEMENTATION_

#include "IteratorC.h"

#include "GameInfo.h"

#include <stdlib.h>

void LGMICDestroy(LGMIN_ LGMIteratorC *pic) {
    ICDestroy(pic);
}

const LGMGameInfo *LGMICGet(LGMTHIS_ const LGMIteratorC *pic) {
    return pic->x_pgi;
}

LGMIteratorC *LGMICReset(LGMTHIS_ LGMIteratorC *pic) {
    pic->x_pgi = pic->x_nil;
    return pic;
}

bool LGMICNil(LGMTHIS_ const LGMIteratorC *pic) {
    return pic->x_pgi->x_nil;
}

LGMIteratorC *LGMICPrev(LGMTHIS_ LGMIteratorC *pic) {
    pic->x_pgi = pic->x_pgi->x_prvi[pic->x_cmp];
    return pic;
}

LGMIteratorC *LGMICNext(LGMTHIS_ LGMIteratorC *pic) {
    pic->x_pgi = pic->x_pgi->x_nxti[pic->x_cmp];
    return pic;
}

// Internals

static LGMIteratorC *x_ics = nullptr;

LGMIteratorC *ICCreate(LGMIN_ const LGMGameInfo *pgi, LGMIN_ LGMCmp cmp) {
    LGMIteratorC *pic = x_ics;
    if (pic)
        x_ics = pic->x_next;
    else if (!(pic = (LGMIteratorC *) malloc(sizeof(LGMIteratorC))))
        return nullptr;
    pic->x_pgi = pgi;
    pic->x_cmp = cmp;
    pic->x_nil = pgi;
    return pic;
}

void ICDestroy(LGMIN_ LGMIteratorC *pic) {
    pic->x_next = x_ics;
    x_ics = pic;
}

bool ICStartup() {
    x_ics = nullptr;
    return true;
}

void ICCleanup() {
    for (LGMIteratorC *i = x_ics; i; ) {
        LGMIteratorC *p = i;
        i = i->x_next;
        free(p);
    }
}

