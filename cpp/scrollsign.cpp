#include <iostream>
#include <unistd.h>

using namespace std;

int main()
{
    unsigned int counter = 0;
    unsigned int z, speed;
    int light[5][40] = {
    {1,0,0,1,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0},
    {1,0,0,1,0,0,0,0,1,0,1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0},
    {1,1,1,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,0,1,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0},
    {1,0,0,1,0,0,1,1,1,1,1,1,1,0,0,1,0,0,0,0,1,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0},
    {1,0,0,1,0,1,0,0,0,0,0,0,0,1,0,1,1,1,1,0,1,1,1,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0}
    };

    cout << "How fast should the text scroll? (Refresh rate in msecs): ";
    cin >> speed;
    speed *= 1000;

    while (true) {
        system("clear");

        for (int x = 0; x < 5; x++) {
            for (int y = 0; y < 40; y++) {
                z = (counter + y) % 40;
                cout << light[x][z];
            }

            cout << endl;
        }

        counter++;
        usleep(speed);
    }
}
