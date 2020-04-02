#include <iostream>
#include <unistd.h>
#include <cstdlib>

using namespace std;


#define UP 0
#define DOWN 1
#define RIGHT 2
#define LEFT 3
#define DOWNLEFT 4
#define DOWNRIGHT 5
#define UPLEFT 6
#define UPRIGHT 7
#define WHITESQUARE "\u25A0"
#define BLACKSQUARE "\u25FB"

const int maxvertikal = 5;
const int maxhorizontal = 8;

void renderPlayfield(int playfield[][maxhorizontal]);
bool winCondition(int playfield[][maxhorizontal], int, int);
bool checkSpace(int playfield[][maxhorizontal], int, int, int, int);
int placeStone(int playfield[][maxhorizontal], int, int);
void emptyPlayfield(int playfield[][maxhorizontal]);

int main()
{
    int newx, inputcolumn, player, counter;
    string playername1, playername2;
    bool playbot = false;
    char repeat, querybot;
    int playfield[maxvertikal][maxhorizontal];
    
    //Playloop
    do {
        emptyPlayfield(playfield);
        renderPlayfield(playfield);
        
        //Reset Player and counter
        player = 2;
        counter = 0;
        
        //Play against bot?
        cout << "Do you want to play against a bot (He's really bad)?(y|Y) ";
        cin >> querybot;
        if (querybot == 'y' || querybot == 'Y')
            playbot = true;
        else
            playbot = false;

        //Ask for player names
        cout << "Input player names:" << endl;
        cout << "Player 1: ";
        cin >> playername1;
        if (!playbot) {
            cout << "Player 2: ";
            cin >> playername2;
        } else {
            playername2 = "BOT";
        }

        //Game loop
        do {
            //Check for full board
            if (counter == maxvertikal * maxhorizontal) {
                cout << "The board is full! No one won." << endl;
                goto playagain;
            }

            //Switch Player
            player == 1 ? player = 2 : player = 1;

            do {
                if (newx == -1 && (!playbot || player == 1)) {
                    cout << "Column is full, please select another" << endl;
                } else {
                    cout << playername1 << " = " << WHITESQUARE << endl;
                    cout << playername2 << " = " << BLACKSQUARE << endl;
                }

                //Ask player for column
                if (player == 1) {
                    cout << "In which column do you want to place your stone ";
                    cout << playername1 << "? (1-" << maxhorizontal << ")";
                    cin >> inputcolumn;
                    inputcolumn--;
                } else if (player == 2 && !playbot) {
                    cout << "In which column do you want to place your stone ";
                    cout << playername2 << "? (1-" << maxhorizontal << ")";
                    cin >> inputcolumn;
                    inputcolumn--;
                } else if (playbot) {
                    inputcolumn = rand() % maxhorizontal;
                }


                newx = placeStone(playfield, inputcolumn, player);
            } while (newx == -1);

            counter++;
            
        } while (!winCondition(playfield, newx, inputcolumn));

        if (player == 1)
            cout << "Congrats " << playername1 << ". YOU WIN!" << endl;
        if (player == 2)
            cout << "Congrats " << playername2 << ". YOU WIN!" << endl;
        
playagain:
        //Play again?
        cout << "Do you want to play again?(y|Y) ";
        cin >> repeat;
    } while (repeat == 'Y' || repeat == 'y');
}

void emptyPlayfield(int playfield[maxvertikal][maxhorizontal])
{
    for (int x = 0; x < maxvertikal; x++)
        for (int y = 0; y < maxhorizontal; y++)
            playfield[x][y] = 0;
}

int placeStone(int playfield[maxvertikal][maxhorizontal], int column, int player)
{
    int retval;

    if (playfield[maxvertikal - 1][column] != 0)
        return -1;

    for (int i = maxvertikal - 1; i >= 0; i--) {
        if (playfield[i][column] == 0) {
            if (i < maxvertikal - 1)
                playfield[i+1][column] = 0;
            playfield[i][column] = player;
            renderPlayfield(playfield);
            usleep(200000);
            retval = i;
        }
    }

    return retval;
}

void renderPlayfield(int playfield[maxvertikal][maxhorizontal])
{
    system("clear");
    cout << "Connect Four\n\n";
    cout << "  ";
    for (int i = 1; i <= maxhorizontal; i++)
        cout << i << "   ";
    cout << endl;
    cout << "-";
    for (int i = 0; i < maxhorizontal; i++)
        cout << "----";
    cout << endl;
    for (int x = maxvertikal - 1; x >= 0; x--) {
        for (int y = 0; y < maxhorizontal; y++) {
            cout << "| ";
            if (playfield[x][y] == 1)
                cout << WHITESQUARE << " ";
            else if (playfield[x][y] == 2)
                cout << BLACKSQUARE << " ";
            else
                cout << "  ";
        }
        cout << "|" << endl;

        cout << "-";
        for (int i = 0; i < maxhorizontal; i++)
            cout << "----";
        cout << endl;

    }
}

bool winCondition(int playfield[maxvertikal][maxhorizontal], int x, int y)
{
    for (int i = UP; i <= UPRIGHT; i++) {
        for (int j = 1; j < 4; j++) {
            if (!checkSpace(playfield, x, y, i, j))
                break;
            else if (j == 3)
                return true;
        }
    }
    return false;
}

bool checkSpace(int playfield[maxvertikal][maxhorizontal], int x, int y, int direction, int offset)
{
    if (playfield[x][y] == 0)
        return false;

    switch (direction) {
    case UP:
        if (x < maxvertikal - 1)
            return (playfield[x][y] == playfield[x+offset][y] ? true : false);
        break;
    case DOWN:
        if (x > 0)
            return (playfield[x][y] == playfield[x-offset][y] ? true : false);
        break;
    case RIGHT:
        if (y < maxhorizontal - 1)
            return (playfield[x][y] == playfield[x][y+offset] ? true : false);
        break;
    case LEFT:
        if (y > 0)
            return (playfield[x][y] == playfield[x][y-offset] ? true : false);
        break;
    case UPLEFT:
        if (y > 0 && x < maxvertikal - 1)
            return (playfield[x][y] == playfield[x+offset][y-offset] ? true : false);
        break;
    case UPRIGHT:
        if (y < maxhorizontal - 1 && x < maxvertikal - 1)
            return (playfield[x][y] == playfield[x+offset][y+offset] ? true : false);
        break;
    case DOWNLEFT:
        if (y > 0 && x > 0)
            return (playfield[x][y] == playfield[x-offset][y-offset] ? true : false);
        break;
    case DOWNRIGHT:
        if (y < maxhorizontal - 1 && x > 0)
            return (playfield[x][y] == playfield[x-offset][y-offset] ? true : false);
        break;
    }
    return false;
}
