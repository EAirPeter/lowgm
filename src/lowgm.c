#define LOWGM_IMPLEMENTATION_

#include "Common.h"
#include "GameAchievement.h"
#include "GameInfo.h"
#include "GameList.h"
#include "GameSorting.h"
#include "GameVenDesc.h"
#include "IteratorC.h"

static bool x_rdy = false;

bool LGMStartup() {
    if (x_rdy)
        return false;
    if (!VDStartup())
        return false;
    if (!GAStartup())
        return false;
    if (!GIStartup())
        return false;
    if (!ICStartup())
        return false;
    if (!GSStartup())
        return false;
    if (!GLStartup())
        return false;
    return x_rdy = true;
}

void LGMCleanup() {
    GLCleanup();
    GSCleanup();
    ICCleanup();
    GICleanup();
    GACleanup();
    VDCleanup();
    x_rdy = false;
}

bool LGMIsReady() {
    return x_rdy;
}

