#include <iostream>

using namespace std;

#define WHITESQUARE "\u25A0"
#define BLACKSQUARE "\u25FB"
#define WHITEPAWN "\u265F"
#define BLACKPAWN "\u2659"
const string whitestartrow[8] = { "\u265C", "\u265E", "\u265D", "\u265B", 
                                  "\u265A", "\u265D", "\u265E", "\u265C" };

const string blackstartrow[8] = { "\u2656", "\u2658", "\u2657", "\u2655",
                                  "\u2654", "\u2657", "\u2658", "\u2656" };

void chessPattern(string chessboard[8][8]);
void startingPositions(string chessboard[8][8]);

int main()
{
    int selection = 0;
    string chessboard[8][8];

    while (true) {
        cout << "\n Bitte waehlen Sie eine Option aus";
        cout << "\n 0: Beenden";
        cout << "\n 1: Schachbrett leeren";
        cout << "\n 2: Figuren aufstellen";
        cout << "\n Gewaehlte Option: ";
        cin >> selection;

        switch (selection)
        {
        case 0:
            cout << "Beende..." << endl;
            return 0;
        case 1: 
            chessPattern(chessboard);
            break;
        case 2: 
            startingPositions(chessboard);
            break;
        default:
            cout << "\nOption existiert nicht. ";
            cout << "Bitte waehlen Sie eine andere Option aus." << endl;
        }
        //print
        for (int y = 0; y < 8; y++) {
            for (int x = 0; x < 8; x++)
                cout << chessboard[x][y] << " ";

            cout << endl;
        }
    }
    return -1;
}

void chessPattern(string chessboard[8][8]) {
    for (int y = 0; y < 8; y++) {
        for (int x = 0; x < 8; x++) {
            if (y % 2 == 0) {
                if (x % 2 == 0)
                    chessboard[x][y] = WHITESQUARE;
                else
                    chessboard[x][y] = BLACKSQUARE;
            } else {
                if (x % 2 != 0)
                    chessboard[x][y] = WHITESQUARE;
                else
                    chessboard[x][y] = BLACKSQUARE;
            }
        }
    }
}

void startingPositions(string chessboard[8][8]) {
    for (int y = 0; y < 8; y++) {
        for (int x = 0; x < 8; x++) {
            if (y == 0) {
                chessboard[x][y] = blackstartrow[x];
            } else if (y == 1) {
                chessboard[x][y] = BLACKPAWN;
            } else if (y == 6) {
                chessboard[x][y] = WHITEPAWN;
            } else if (y == 7) {
                chessboard[x][y] = whitestartrow[x];
            }
        }
    }
}
