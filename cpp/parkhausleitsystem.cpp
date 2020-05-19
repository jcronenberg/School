#include <iostream>

using namespace std;

#define RED 31
#define GREEN 32

void fillGarage(int);
void setColor(int);
void drawPark(void);
int freeFloor(void);
int freeSpace(int);
void drawArrow(int);

const int maxFloors = 4;
const int maxSpaces = 12;

int parkingGarage[maxFloors][maxSpaces];

int main()
{
    fillGarage(1);
    parkingGarage[3][10] = 0;
    drawPark();
}

void setColor(int color)
{
    cout << "\033[1;" << color << "m";
}

void fillGarage(int input)
{
    for (int i = 0; i < maxFloors; i++)
        for (int j = 0; j < maxSpaces; j++)
            parkingGarage[i][j] = input;
}

void drawArrow(int currFloor)
{
    int spaceNr = freeSpace(currFloor);

    setColor(GREEN);

    if (spaceNr == -1)
        cout << "    ^    ";
    else if (spaceNr < maxSpaces / 2)
        cout << " <--     ";
    else
        cout << "     --> ";

    setColor(false);
}

void drawPark(void)
{
    int drawArrowFlag = freeFloor();

    //draw upper line
    for (int i = 0; i < 19 + 3 * maxSpaces; i++) {
        cout << "-";
    }
    cout << "\n";

    //draw Parkbox line
    cout << "Parkbox:";
    for (int i = 0; i < maxSpaces; i++) {
        if (i == maxSpaces / 2)
            cout << "---------";

        if (i < 10)
            cout << "-" << i << "-";
        else if (i < 100)
            cout << i << "-";
        else
            cout << i;
    }
    cout << "--\n";

    //draw floors
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

    //draw lower line
    for (int i = 0; i < 19 + 3 * maxSpaces; i++) {
        cout << "-";
    }
    cout << "\n";
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
        if (!parkingGarage[floorNr][(maxSpaces - 1) - i])
            return ((maxSpaces - 1) - i);
    }

    return -1;
}
