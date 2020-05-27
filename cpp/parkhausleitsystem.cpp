#include <iostream>
#include <time.h>

using namespace std;

#define RED 31
#define GREEN 32

void fillGarage(int);
void setColor(int);
void drawPark(void);
int freeFloor(void);
int freeSpace(int);
void drawArrow(int);
void freeParking(int, int, int);

const int maxFloors = 4;
const int maxSpaces = 12;

int parkingGarage[maxFloors][maxSpaces];

int main()
{
    char input;
    int newFloor, newSpace;
    int inFloor, inSpace;

    while (true) {
        system("clear");
        drawPark();
        if (freeFloor() != -1) {
            cout << "Enter or leave (e/l)? ";
            cin >> input;
        } else {
            cout << "Parking garage is full! Only leaving is permitted?\n\n";
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
            cout << "Floor (0-" << maxFloors - 1 << ")?";
            cin >> inFloor;
            cout << "Space (0-" << maxSpaces - 1 << ")?";
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
}

void setColor(int color)
{
    cout << "\033[1;" << color << "m";
}

void freeParking(int floor, int space, int freeTime)
{
    static bool initializeArrival = true;
    static long arrival[maxFloors][maxSpaces];
    long newTime = time(NULL);

    if (initializeArrival) {
        initializeArrival = false;
        for (int i = 0; i < maxFloors; i++) {
            for (int j = 0; j < maxSpaces; j++) {
                arrival[i][j] = 0;
            }
        }
    }

    if (arrival[floor][space] == 0) {
        arrival[floor][space] = newTime;
    } else {
        if (newTime - arrival[floor][space] > freeTime) {
            setColor(RED);
            cout << "You have to pay for ";
            cout << (newTime - freeTime - arrival[floor][space]) / 60 + 1;
            cout << " minutes." << endl;
            setColor(false);

            arrival[floor][space] = 0;

            getchar();
            getchar();
        } else {
            setColor(GREEN);
            cout << "Free Parking!" << endl;
            setColor(false);
        }
    }
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
