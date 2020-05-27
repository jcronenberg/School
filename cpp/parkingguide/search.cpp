#include "search.h"
#include "parkingguide.h"

int freeFloor(void)
{
    for (int i = MAXFLOORS - 1; i >= 0 ; i--)
        for (int j = 0; j < MAXSPACES; j++)
            if (!parkingGarage[i][j])
                return i;

    return -1;
}

int freeSpace(int floorNr)
{
    for (int i = 0; i < MAXSPACES / 2; i++) {
        if (!parkingGarage[floorNr][i])
            return i;
        if (!parkingGarage[floorNr][(MAXSPACES - 1) - i])
            return ((MAXSPACES - 1) - i);
    }

    return -1;
}
