#include <iostream>
#include <time.h>
#include "timemanagement.h"
#include "parkingguide.h"

using namespace std;

void freeParking(int floor, int space, int freeTime)
{
    static bool initializeArrival = true;
    static long arrival[MAXFLOORS][MAXSPACES];
    long newTime = time(NULL);

    if (initializeArrival) {
        initializeArrival = false;
        for (int i = 0; i < MAXFLOORS; i++) {
            for (int j = 0; j < MAXSPACES; j++) {
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
