#include <iostream>
#include <unistd.h>
#include <cstdlib>

using namespace std;


#define DOWN 0
#define UP 1
#define DOWNLEFT 2
#define UPRIGHT 3
#define DOWNRIGHT 4
#define UPLEFT 5
#define RIGHT 6
#define LEFT 7
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
    int newx, inputcolumn, player, roundcounter;
    string playername1, playername2;
    bool playbot = false;
    char repeat, querybot;
    int playfield[maxvertikal][maxhorizontal];

    //Playloop
    do {
        emptyPlayfield(playfield);
        renderPlayfield(playfield);

        //Reset Variables
        player = 2;
        roundcounter = 0;
        inputcolumn = 1;

        //Play against bot?
        cout << "Do you want to play against a bot (He's really bad)?(y|Y) ";
        cin >> querybot;
        if (querybot == 'y' || querybot == 'Y')
            playbot = true;
        else
            playbot = false;

        playername1 = WHITESQUARE;
        playername2 = BLACKSQUARE;

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
            if (roundcounter == maxvertikal * maxhorizontal) {
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

                //Ask player for column or use random for bot
                if (player == 1 || (player == 2 && !playbot)) {
                    do {
                        if (inputcolumn < 0 || inputcolumn > maxhorizontal - 1)
                            cout << "Invalid column number, try again" << endl;

                        cout << "In which column do you want to place your stone ";
                        if (player == 1)
                            cout << playername1;
                        else
                            cout << playername2;
                        cout << "?(1-" << maxhorizontal << ") ";
                        cin >> inputcolumn;
                        inputcolumn--;

                    } while (inputcolumn < 0 || inputcolumn > maxhorizontal - 1);

                } else if (playbot) {
                    srand(time(NULL));
                    inputcolumn = rand() % maxhorizontal;
                }

                newx = placeStone(playfield, inputcolumn, player);

            } while (newx == -1);

            roundcounter++;

        } while (!winCondition(playfield, newx, inputcolumn));

        //Win message
        if (player == 1)
            cout << "Congrats " << playername1 << ". YOU WIN!" << endl;
        if (player == 2)
            cout << "Congrats " << playername2 << ". YOU WIN!" << endl;

playagain:
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

//Render stone falling at column and returns the new x position
int placeStone(int playfield[maxvertikal][maxhorizontal], int column, int player)
{
    int retval;

    if (playfield[maxvertikal - 1][column] != 0)
        return -1;

    for (int i = maxvertikal - 1; i >= 0; i--) {
        if (playfield[i][column] == 0) {
            //Dont change above field if it is the top line
            if (i < maxvertikal - 1)
                playfield[i+1][column] = 0;

            playfield[i][column] = player;
            renderPlayfield(playfield);
            usleep(100000);
            retval = i;
        }
    }

    return retval;
}

void renderPlayfield(int playfield[maxvertikal][maxhorizontal])
{
    system("clear");
    cout << "Connect Four\n\n";

    //Print column numbers
    cout << "  ";
    for (int i = 1; i <= maxhorizontal; i++)
        cout << i << "   ";
    cout << endl;

    //Print upper line
    cout << "-";
    for (int i = 0; i < maxhorizontal; i++)
        cout << "----";
    cout << endl;

    //Print board
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

//Return true if stone at position x, y causes the player to win
bool winCondition(int playfield[maxvertikal][maxhorizontal], int x, int y)
{
    int linecounter;

    for (int i = DOWN; i <= LEFT; i++) {
        if (i % 2 == 0)
            linecounter = 0;

        for (int j = 1; j < 4; j++) {
            if (!checkSpace(playfield, x, y, i, j))
                break;
            else
                linecounter++;

        }
        if (linecounter >= 3)
            return true;
    }
    return false;
}

//Return true, if stone at x, y is the same as stone at the direction and offset
bool checkSpace(int playfield[maxvertikal][maxhorizontal],
        int x, int y, int direction, int offset)
{
    if (playfield[x][y] == 0)
        return false;

    switch (direction) {
    case UP:
        if (x + offset <= maxvertikal - 1)
            return (playfield[x][y] == playfield[x+offset][y] ? true : false);
        break;
    case DOWN:
        if (x - offset >= 0)
            return (playfield[x][y] == playfield[x-offset][y] ? true : false);
        break;
    case RIGHT:
        if (y + offset <= maxhorizontal - 1)
            return (playfield[x][y] == playfield[x][y+offset] ? true : false);
        break;
    case LEFT:
        if (y - offset >= 0)
            return (playfield[x][y] == playfield[x][y-offset] ? true : false);
        break;
    case UPLEFT:
        if (y - offset >= 0 && x + offset <= maxvertikal - 1)
            return (playfield[x][y] == playfield[x+offset][y-offset] ? true : false);
        break;
    case UPRIGHT:
        if (y + offset <= maxhorizontal - 1 && x + offset <= maxvertikal - 1)
            return (playfield[x][y] == playfield[x+offset][y+offset] ? true : false);
        break;
    case DOWNLEFT:
        if (y - offset >= 0 && x - offset >= 0)
            return (playfield[x][y] == playfield[x-offset][y-offset] ? true : false);
        break;
    case DOWNRIGHT:
        if (y + offset <= maxhorizontal - 1 && x - offset >= 0)
            return (playfield[x][y] == playfield[x-offset][y+offset] ? true : false);
        break;
    }
    return false;
}
