#ifndef LOWGM_LOWGM_H_
#define LOWGM_LOWGM_H_

// For bool
#include <stdbool.h>

// Basics.

// Initializes lowgm.
bool LGMStartup();

// Cleans up.
void LGMCleanup();

// Determines whether lowgm is initialized.
bool LGMIsReady();

// Used to tell user what an argument is used for.
#define LGMIN_
#define LGMOUT_
#define LGMTHIS_

// The size of a buffer used to store a string in LGM types.
#define LGM_BUFSIZE 256U

// Represents a game list.
typedef struct LGMGameList_         LGMGameList;

// Represents a game's all information.
typedef struct LGMGameInfo_         LGMGameInfo;

// A const iterator for LGMGLSortC.
typedef struct LGMIteratorC_        LGMIteratorC;

// Represents an achievement in an LGMGameInfo.
typedef struct LGMGameAchievement_  LGMGameAchievement;

// Represents a description of vendor in an LGMGameInfo.
typedef struct LGMGameVenDesc_      LGMGameVenDesc;

// Represents the comparator used to sort an LGMGameList.
typedef enum LGMCmp_ {
    // By name.
    LGMCMP_NAME = 0U,
    // By description.
    LGMCMP_DESC,
    // By time (in hour) the game has been played for.
    LGMCMP_TIME,
    // By the ahieving rate of achievements.
    LGMCMP_ACHS,
    // The number of comparators.
    LGM_ALLCMP_,
} LGMCmp;

#define LGMGAMELIST_OPERATIONS

// Create an LGMGameList.
LGMGameList *LGMGLCreate();

// Destroy.
void LGMGLDestroy(LGMTHIS_ LGMGameList *pgl);

// Creates and adds an LGMGameInfo with game's name.
LGMGameInfo *LGMGLAdd(LGMTHIS_ LGMGameList *pgl, const char *name);

// Removes and destroys an LGMGameInfo.
// If success, pgi points to the next LGMGameInfo
bool LGMGLRemove(LGMIN_ LGMGameInfo *pgi);

// Returns a pointer pointing to the LGMGameIndo whose next is the first
//  one and previous is the last one.
LGMGameInfo *LGMGLNil(LGMTHIS_ LGMGameList *pgl);
const LGMGameInfo *LGMGLNilC(LGMTHIS_ const LGMGameList *pgl);

// Returns a pointer pointing the LGMGameInfo with the given name.
// If not found, nil will be returned.
LGMGameInfo *LGMGLFind(LGMTHIS_ LGMGameList *pgl, const char *name);
const LGMGameInfo *LGMGLFindC(LGMTHIS_ const LGMGameList *pgl,
    const char *name);

// Sorts the LGMGameList according to the given comparator.
void LGMGLSort(LGMTHIS_ LGMGameList *pgl, LGMIN_ LGMCmp cmp);

// Sorts the LGMGameList according to the given comparator without changing the
//  order of LGMGameInfo s, but creates an LGMIteratorC binding to nil instead.
LGMIteratorC *LGMGLSortC(LGMTHIS_ LGMGameList *pgl, LGMIN_ LGMCmp cmp);

#undef  LGMGAMELIST_OPERATIONS
#define LGMGMAEINFO_OPERATIONS

// Returns the name of the game.
const char *LGMGIGetName(LGMTHIS_ const LGMGameInfo *pgi);

// Sets the description of the game.
bool LGMGISetDesc(LGMTHIS_ LGMGameInfo *pgi, const char *desc);

// Returns the description of the game.
const char *LGMGIGetDesc(LGMTHIS_ const LGMGameInfo *pgi);

// Sets the time (in hour) the game has been played for.
void LGMGISetTime(LGMTHIS_ LGMGameInfo *pgi, unsigned time);

// Returns the time (in hour) the game has been played for.
unsigned LGMGIGetTime(LGMTHIS_ const LGMGameInfo *pgi);

// Creates and adds an achievement with the achievement's name.
LGMGameAchievement *LGMGIAchAdd(LGMTHIS_ LGMGameInfo *pgi,
    LGMIN_ const char *name);

// Removes and destroys an LGMGameAchievement.
// If success, pga points to the next LGMGameAchievement.
bool LGMGIAchRemove(LGMIN_ LGMGameAchievement *pga);

// Returns a pointer pointing to the LGMGameAchievement whose next is the
//  first one and previous is the last one.
LGMGameAchievement *LGMGIAchNil(LGMTHIS_ LGMGameInfo *pgi);
const LGMGameAchievement *LGMGIAchNilC(LGMTHIS_ const LGMGameInfo *pgi);

// Creates and adds an LGMGameVenDesc with the description of vendor.
LGMGameVenDesc *LGMGIVenAdd(LGMTHIS_ LGMGameInfo *pgi,
    LGMIN_ const char *desc);

// Removes and destroys an LGMGameVenDesc.
// If success, pvd points to the LGMGameVenDesc.
bool LGMGIVenRemove(LGMIN_ LGMGameVenDesc *pvd);

// Returns a pointer pointing to the LGMGameVenDesc whose next is the
//  first one and previous is the last one.
LGMGameVenDesc *LGMGIVenNil(LGMTHIS_ LGMGameInfo *pgi);
const LGMGameVenDesc *LGMGIVenNilC(LGMTHIS_ const LGMGameInfo *pgi);

// Returns whether the pointer is nil.
bool LGMGINil(LGMTHIS_ LGMGameInfo *pgi);
bool LGMGINilC(LGMTHIS_ const LGMGameInfo *pgi);

// Returns a pointer pointing to the previous LGMGameInfo.
LGMGameInfo *LGMGIPrev(LGMTHIS_ LGMGameInfo *pgi);
const LGMGameInfo *LGMGIPrevC(LGMTHIS_ const LGMGameInfo *pgi);

// Returns a pointer pointing to the next LGMGameInfo.
LGMGameInfo *LGMGINext(LGMTHIS_ LGMGameInfo *pgi);
const LGMGameInfo *LGMGINextC(LGMTHIS_ const LGMGameInfo *pgi);

#undef  LGMGAMEINFO_OPERATIONS
#define LGMITERATORC_OPERATIONS

// Destroys.
void LGMICDestroy(LGMIN_ LGMIteratorC *pic);

// Get the LGMGameInfo that pic binds to.
const LGMGameInfo *LGMGICGet(LGMTHIS_ const LGMIteratorC *pic);

// Returns whether the pointer is nil.
bool LGMICNil(LGMTHIS_ const LGMIteratorC *pic);

// Binds pic to the previous LGMGameInfo and return it.
LGMIteratorC *LGMICPrev(LGMTHIS_ LGMIteratorC *pic);

// Binds pic to the next LGMGameInfo and return it.
LGMIteratorC *LGMICNext(LGMTHIS_ LGMIteratorC *pic);

#undef  LGMITERATORC_OPERATIONS
#define LGMGAMEACHIEVEMENT_OPERATIONS

// Get the name.
const char *LGMGAGetName(LGMTHIS_ const LGMGameAchievement *pga);

// Set if the this is achieved.
void LGMGASetAchieved(LGMTHIS_ LGMGameAchievement *pga, bool achieved);

// Get if the this is achieved.
bool LGMGAGetAchieved(LGMTHIS_ const LGMGameAchievement *pga);

// Returns whether the pointer is nil.
bool LGMGANil(LGMTHIS_ LGMGameAchievement *pga);
bool LGMGANilC(LGMTHIS_ const LGMGameAchievement *pga);

// Returns a pointer pointing to the previous LGMGameAchievement.
LGMGameAchievement *LGMGAPrev(LGMTHIS_ LGMGameAchievement *pga);
const LGMGameAchievement *LGMGAPrevC(LGMTHIS_ const LGMGameAchievement *pga);

// Returns a pointer pointing to the next LGMGameAchievement.
LGMGameAchievement *LGMGANext(LGMTHIS_ LGMGameAchievement *pga);
const LGMGameAchievement *LGMGANextC(LGMTHIS_ const LGMGameAchievement *pga);

#undef  LGMGAMEACHIEVEMENT_OPERATIONS
#define LGMGAMEVENDESC_OPERATIONS

// Get the description.
const char *LGMVDGet(LGMTHIS_ LGMGameVenDesc *pvd);

// Returns whether the pointer is nil.
bool LGMVDNil(LGMTHIS_ LGMGameVenDesc *pvd);
bool LGMVDNilC(LGMTHIS_ const LGMGameVenDesc *pvd);

// Returns a pointer pointing to the previous LGMGameVenDesc.
LGMGameVenDesc *LGMVDPrev(LGMTHIS_ LGMGameVenDesc *pvd);
const LGMGameVenDesc *LGMVDPrevC(LGMTHIS_ const LGMGameVenDesc *pvd);

// Returns a pointer pointing to the next LGMGameVenDesc.
LGMGameVenDesc *LGMVDNext(LGMTHIS_ LGMGameVenDesc *pvd);
const LGMGameVenDesc *LGMVDNextC(LGMTHIS_ const LGMGameVenDesc *pvd);

#undef  LGMGAMEVENDESC_OPERATIONS

// For general iterating use.
#define LGMREMOVE(it_)  (_Generic((it_),        \
    LGMGameInfo             *:  LGMGLRemove,    \
    LGMGameAchievement      *:  LGMGIAchRemove, \
    LGMGameVenDesc          *:  LGMGIVenRemove  \
)(it_))
#define LGMNIL(it_)     (_Generic((it_),        \
            LGMGameInfo         *:  LGMGINil,   \
    const   LGMGameInfo         *:  LGMGINilC,  \
            LGMIteratorC        *:  LGMICNil,   \
            LGMGameAchievement  *:  LGMGANil,   \
    const   LGMGameAchievement  *:  LGMGANilC,  \
            LGMGameVenDesc      *:  LGMVDNil,   \
    const   LGMGameVenDesc      *:  LGMVDNilC   \
)(it_))
#define LGMPREV(it_)    (_Generic((it_),        \
            LGMGameInfo         *:  LGMGIPrev,  \
    const   LGMGameInfo         *:  LGMGIPrevC, \
            LGMIteratorC        *:  LGMICPrev,  \
            LGMGameAchievement  *:  LGMGAPrev,  \
    const   LGMGameAchievement  *:  LGMGAPrevC, \
            LGMGameVenDesc      *:  LGMVDPrev,  \
    const   LGMGameVenDesc      *:  LGMVDPrevC  \
)(it_))
#define LGMNEXT(it_)    (_Generic((it_),        \
            LGMGameInfo         *:  LGMGINext,  \
    const   LGMGameInfo         *:  LGMGINextC, \
            LGMIteratorC        *:  LGMICNext,  \
            LGMGameAchievement  *:  LGMGANext,  \
    const   LGMGameAchievement  *:  LGMGANextC, \
            LGMGameVenDesc      *:  LGMVDNext,  \
    const   LGMGameVenDesc      *:  LGMVDNextC  \
)(it_))

#endif  // LOWGM_LOWGM_H_

