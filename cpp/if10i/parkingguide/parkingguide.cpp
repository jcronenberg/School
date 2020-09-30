#include <iostream>
#include "search.h"
#include "timemanagement.h"
#include "parkingguide.h"

using namespace std;

void fillGarage(int);
void drawPark(void);
void drawArrow(int);
void enterLeave(bool);

int parkingGarage[MAXFLOORS][MAXSPACES];

int main()
{
    while (true) {
        system("clear");
        drawPark();
        if (freeFloor() != -1) {
            enterLeave(true);
        } else {
            setColor(RED);
            cout << "Parking garage is full! Only leaving is permitted.\n\n";
            setColor(false);
            enterLeave(false);
        }
    }
}

void setColor(int color)
{
    cout << "\033[1;" << color << "m";
}

void drawArrow(int currFloor)
{
    setColor(GREEN);

    if (currFloor != freeFloor()) {
        cout << "    ^    ";
        return;
    }

    int spaceNr = freeSpace(currFloor);

    if (spaceNr == -1)
        cout << "    ^    ";
    else if (spaceNr < MAXSPACES / 2)
        cout << " <--     ";
    else
        cout << "     --> ";

    setColor(false);
}

void drawPark(void)
{
    int drawArrowFlag = freeFloor();

    //draw upper line
    for (int i = 0; i < 19 + 3 * MAXSPACES; i++) {
        cout << "-";
    }
    cout << "\n";

    //draw Parkbox line
    cout << "Parkbox:";
    for (int i = 0; i < MAXSPACES; i++) {
        if (i == MAXSPACES / 2)
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
    for (int i = MAXFLOORS - 1; i >= 0; i--) {
        setColor(false);
        cout << "Floor " << i << ":";

        for (int j = 0; j < MAXSPACES; j++) {
            if (j == MAXSPACES / 2 && drawArrowFlag != -1 && drawArrowFlag >= i)
                drawArrow(i);
            else if (j == MAXSPACES / 2)
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
    for (int i = 0; i < 19 + 3 * MAXSPACES; i++) {
        cout << "-";
    }
    cout << "\n";
}

void enterLeave(bool isFree)
{
    char input;
    int newFloor, newSpace;
    int inFloor, inSpace;

    if (isFree) {
        cout << "Enter or leave (e/l)? ";
        cin >> input;
    } else {
        input = 'l';
    }

    if (input == 'e' || input == 'E') {
        newFloor = freeFloor();
        newSpace = freeSpace(newFloor);
        cout << "Thank you for using our services!" << endl;
        cout << "Your space is on floor " << newFloor;
        cout << ", space " << newSpace << endl;
        cout << "Please follow the arrows!" << endl;

        parkingGarage[newFloor][newSpace] = 1;
        freeParking(newFloor, newSpace, 10);
    } else if (input == 'l' || input == 'L') {
        cout << "Where is your car parked?" << endl;
        cout << "Floor (0-" << MAXFLOORS - 1 << ")?";
        cin >> inFloor;
        cout << "Space (0-" << MAXSPACES - 1 << ")?";
        cin >> inSpace;


        if (parkingGarage[inFloor][inSpace] == 1) {
            freeParking(inFloor, inSpace, 10);

            cout << "We hope you had a good stay! Goodbye" << endl;
            parkingGarage[inFloor][inSpace] = 0;
        } else {
            cout << "Sorry, there is no car parked at this space!" << endl;
        }
    } else {
        cout << "Unknown option!" << endl;
    }
    getchar();
    getchar();
}
