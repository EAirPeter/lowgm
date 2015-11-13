#define LOWGM_IMPLEMENTATION_

#include "GameList.h"

#include "GameSorting.h"

#include <stdlib.h>
#include <string.h>

LGMGameList *LGMGLCreate() {
    return GLCreate();
}

void LGMGLDestroy(LGMTHIS_ LGMGameList *pgl) {
    GLDestroy(pgl);
}

LGMGameInfo *LGMGLAdd(LGMTHIS_ LGMGameList *pgl, const char *name) {
    if (strlen(name) >= LGM_BUFSIZE)
        return nullptr;
    //for (LGMGameInfo *i = pgl->x_gis.x_next; !i->x_nil; i = i->x_next)
    //    if (!strcmp(i->x_name, name))
    //        return nullptr;
    LGMGameInfo *pgi = GICreate(name);
    if (!pgi)
        return nullptr;
    GILink(pgl->x_gis.x_prev, pgi);
    GILink(pgi, &pgl->x_gis);
    return pgi;
}

bool LGMGLRemove(LGMIN_ LGMGameInfo *pgi) {
    if (pgi->x_nil)
        return false;
    GILink(pgi->x_prev, pgi->x_next);
    GIDestroy(pgi);
    return true;
}

LGMGameInfo *LGMGLNil(LGMTHIS_ LGMGameList *pgl) {
    pgl->x_rdy = 0U;
    return &pgl->x_gis;
}

const LGMGameInfo *LGMGLNilC(LGMTHIS_ const LGMGameList *pgl) {
    return &pgl->x_gis;
}

LGMGameInfo *LGMGLFind(LGMTHIS_ LGMGameList *pgl, const char *name) {
    pgl->x_rdy = 0U;
    for (LGMGameInfo *i = pgl->x_gis.x_next; !i->x_nil; i = i->x_next)
        if (!strcmp(i->x_name, name))
            return i;
    return &pgl->x_gis;
}

const LGMGameInfo *LGMGLFindC(LGMTHIS_ const LGMGameList *pgl,
    const char *name) {
    for (const LGMGameInfo *i = pgl->x_gis.x_next; !i->x_nil; i = i->x_next)
        if (!strcmp(i->x_name, name))
            return i;
    return &pgl->x_gis;
}

void LGMGLSort(LGMTHIS_ LGMGameList *pgl, LGMIN_ LGMCmp cmp) {
    pgl->x_gis.x_next = GSSort(pgl->x_gis.x_next, &pgl->x_gis, gs_cmps[cmp]);
    LGMGameInfo *pgi = &pgl->x_gis;
    while (pgi->x_next) {
        pgi->x_next->x_prev = pgi;
        pgi = pgi->x_next;
    }
    GILink(pgi, &pgl->x_gis);
}

LGMIteratorC *LGMGLSortC(LGMTHIS_ LGMGameList *pgl, LGMIN_ LGMCmp cmp) {
    LGMIteratorC *pic = ICCreate(&pgl->x_gis, cmp);
    if (!pic)
        return nullptr;
    if (pgl->x_rdy & (1U << cmp))
        return pic;
    pgl->x_gis.x_nxti[cmp] = GSSortC(pgl->x_gis.x_next, &pgl->x_gis,
        gs_cmps[cmp], cmp);
    LGMGameInfo *pgi = &pgl->x_gis;
    while (pgi->x_nxti[cmp]) {
        pgi->x_nxti[cmp]->x_prvi[cmp] = pgi;
        pgi = pgi->x_nxti[cmp];
    }
    GILinkC(pgi, &pgl->x_gis, cmp);
    return pic;
}

// Internals

LGMGameList *x_gls = nullptr;

LGMGameList *GLCreate() {
    LGMGameList *pgl = x_gls;
    if (pgl)
        x_gls = pgl->x_next;
    else if (!(pgl = (LGMGameList *) malloc(sizeof(LGMGameList))))
        return nullptr;
    GIInitNil(&pgl->x_gis);
    pgl->x_rdy = 0U;
    return pgl;
}

void GLDestroy(LGMIN_ LGMGameList *pgl) {
    for (LGMGameInfo *i = pgl->x_gis.x_next; !i->x_nil; ) {
        LGMGameInfo *p = i;
        i = i->x_next;
        GIDestroy(p);
    }
    pgl->x_next = x_gls;
    x_gls = pgl;
}

bool GLStartup() {
    x_gls = nullptr;
    return true;
}

void GLCleanup() {
    for (LGMGameList *i = x_gls; i; ) {
        LGMGameList *p = i;
        i = i->x_next;
        free(p);
    }
}

