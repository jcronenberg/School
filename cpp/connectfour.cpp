#include <iostream>

using namespace std;

#define UP 1
#define DOWN 2
#define RIGHT 3
#define LEFT 4
#define DOWNLEFT 5
#define DOWNRIGHT 6
#define UPLEFT 7
#define UPRIGHT 8

void renderPlayfield(int playfield[5][8]);
int winCondition(int playfield[5][8], int, int);
bool checkSpace(int playfield[5][8], int, int, int);

int main()
{
    int playfield[5][8];
    for (int x = 0; x < 5; x++)
        for (int y = 0; y < 8; y++)
            playfield[x][y] = 0;
    
    playfield[0][0] = 1;
    cout << "First check: " << checkSpace(playfield, 0, 0, UPRIGHT) << endl;
    playfield[1][1] = 1;
    cout << "Second check: " << checkSpace(playfield, 0, 0, UPRIGHT) << endl;

    renderPlayfield(playfield);
}

void renderPlayfield(int playfield[5][8])
{
    cout << "\n---------------------------------" << endl;
    for (int x = 4; x >= 0; x--) {
        for (int y = 0; y < 8; y++) {
            cout << "| ";
            if (playfield[x][y] != 0)
                cout << playfield[x][y] << " ";
            else
                cout << "  ";
        }
        cout << "|";

        cout << "\n---------------------------------" << endl;

    }
}

int winCondition(int playfield[5][8], int x, int y)
{
    return 1;
}

bool checkSpace(int playfield[5][8], int x, int y, int direction)
{
    switch (direction) {
    case UP:
        if (x < 4)
            return (playfield[x][y] == playfield[x+1][y] ? true : false);
        break;
    case DOWN:
        if (x > 0)
            return (playfield[x][y] == playfield[x-1][y] ? true : false);
        break;
    case RIGHT:
        if (y < 7)
            return (playfield[x][y] == playfield[x][y+1] ? true : false);
        break;
    case LEFT:
        if (y > 0)
            return (playfield[x][y] == playfield[x][y-1] ? true : false);
        break;
    case UPLEFT:
        if (y > 0 && x < 4)
            return (playfield[x][y] == playfield[x+1][y-1] ? true : false);
        break;
    case UPRIGHT:
        if (y < 7 && x < 4)
            return (playfield[x][y] == playfield[x+1][y+1] ? true : false);
        break;
    case DOWNLEFT:
        if (y > 0 && x > 0)
            return (playfield[x][y] == playfield[x-1][y-1] ? true : false);
        break;
    case DOWNRIGHT:
        if (y < 7 && x > 0)
            return (playfield[x][y] == playfield[x-1][y-1] ? true : false);
        break;
    }
    return false;
}
