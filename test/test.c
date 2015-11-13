#include "../include/lowgm.h"

#include <stdio.h>

char S[256];

int Main() {
    LGMGameList *pgl = LGMGLCreate();
    if (!pgl)
        return -1;
    while (scanf("%s", S) == 1) {
        LGMGameInfo *pgi = LGMGLAdd(pgl, S);
        if (!pgi)
            break;
        scanf("%s", S);
        LGMGISetDesc(pgi, S);
    }
    printf("inputed, next:\n");
    for (const LGMGameInfo *i = LGMNEXT(LGMGLNilC(pgl)); !LGMNIL(i); i = LGMNEXT(i))
        printf("Name: %s, Desc: %s\n", LGMGIGetName(i), LGMGIGetDesc(i));

    LGMGLSort(pgl, LGMCMP_NAME);
    LGMIteratorC *c = LGMGLSortC(pgl, LGMCMP_DESC);

    printf("name, cdesc, cnext:\n");
    for (LGMNEXT(c); !LGMNIL(c); LGMNEXT(c))
        printf("Name: %s, Desc: %s\n", LGMGIGetName(LGMICGet(c)), LGMGIGetDesc(LGMICGet(c)));
    printf("name, cdesc, cprev:\n");
    for (LGMPREV(c); !LGMNIL(c); LGMPREV(c))
        printf("Name: %s, Desc: %s\n", LGMGIGetName(LGMICGet(c)), LGMGIGetDesc(LGMICGet(c)));

    LGMNEXT(c);
    printf("name, cdesc, cfirst:\n");
    printf("Name: %s, Desc: %s\n", LGMGIGetName(LGMICGet(c)), LGMGIGetDesc(LGMICGet(c)));

    LGMICReset(c);

    LGMPREV(c);
    printf("name, cdesc, clast:\n");
    printf("Name: %s, Desc: %s\n", LGMGIGetName(LGMICGet(c)), LGMGIGetDesc(LGMICGet(c)));
    
    printf("name, cdesc, next:\n");
    for (const LGMGameInfo *i = LGMNEXT(LGMGLNilC(pgl)); !LGMNIL(i); i = LGMNEXT(i))
        printf("Name: %s, Desc: %s\n", LGMGIGetName(i), LGMGIGetDesc(i));
    printf("name, cdesc, prev:\n");
    for (const LGMGameInfo *i = LGMPREV(LGMGLNilC(pgl)); !LGMNIL(i); i = LGMPREV(i))
        printf("Name: %s, Desc: %s\n", LGMGIGetName(i), LGMGIGetDesc(i));

    LGMICDestroy(c);
    LGMGLDestroy(pgl);
    return 0;
}

int main() {
    if (!LGMStartup())
        return -1;
    int res = Main();
    LGMCleanup();
    return res;
}

