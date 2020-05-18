#include <iostream>

using namespace std;

#define RED 31
#define GREEN 32

void setColor(int);
void drawPark(void);
int freeFloor(void);
int freeSpace(int);
void drawArrow(int);

const int maxFloors = 3;
const int maxSpaces = 10;

int parkingGarage[maxFloors][maxSpaces] = {
    {1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,0},
};

int main()
{
    drawPark();
}

void setColor(int color)
{
    cout << "\033[1;" << color << "m";
}

void drawArrow(int currFloor)
{
    int spaceNr = freeSpace(currFloor);

    setColor(GREEN);

    if (spaceNr == -1) {
        cout << "    ^    ";
    } else if (spaceNr < maxSpaces / 2) {
        cout << " <--     ";
    } else {
        cout << "     --> ";
    }
}

void drawPark(void)
{
    int drawArrowFlag = freeFloor();

    cout << "-------------------------------------------------\n";
    cout << "Parkbox:-0--1--2--3--4-----------5--6--7--8--9---\n";
    for (int i = maxFloors - 1; i >= 0; i--) {
        setColor(false);
        cout << "Floor " << i << ":";

        for (int j = 0; j < maxSpaces; j++) {
            if (j == maxSpaces / 2 && drawArrowFlag != -1 && drawArrowFlag >= i)
                drawArrow(i);
            else if (j == maxSpaces / 2)
                cout << "         ";

            if (parkingGarage[i][j])
                setColor(RED);
            else
                setColor(GREEN);

            cout << " " << parkingGarage[i][j] << " ";
        }
        cout << "\n";
    }
    setColor(false);
    cout << "-------------------------------------------------\n";

}

int freeFloor(void)
{
    for (int i = maxFloors - 1; i >= 0 ; i--)
        for (int j = 0; j < maxSpaces; j++)
            if (!parkingGarage[i][j])
                return i;

    return -1;
}

int freeSpace(int floorNr)
{
    for (int i = 0; i < maxSpaces / 2; i++) {
        if (!parkingGarage[floorNr][i])
            return i;
        if (!parkingGarage[floorNr][9 - i])
            return (9 - i);
    }

    return -1;
}
