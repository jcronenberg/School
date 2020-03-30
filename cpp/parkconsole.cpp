#include <iostream>

using namespace std;

#define FREE 0
#define OCCUPIED 1

int findFirstFree(int*);
void printSpaces(int*);
void setArray(int*, int);
int menu(void);
void waitForInput(void);
int countFreeSpaces(int*);

//Anzahl der Parkplaetze
const int spaces = 10;

int main()
{
    int parkarray[spaces];
    int selection = 0;
    int parkselection = 0;
    setArray(parkarray, FREE);

    do {
        selection = menu();
        switch (selection) {
        //Selection 1: Parken
        case 1:
            cout << "Auf welchem Parkplatz wollen sie parken?";
            cout << "(1-" << spaces << ")" << endl;
            cin >> parkselection;
            if (parkarray[parkselection - 1] == FREE) {
                cout << "Parkplatz ist frei, sie koennen parken" << endl;
                parkarray[parkselection - 1] = OCCUPIED;
            } else {
                cout << "Parkplatz ist leider bereits belegt,";
                cout << " bitte fahren sie weiter!" << endl;
            }

            waitForInput();
            break;
        //Selection 2: Ausgabe
        case 2:
            printSpaces(parkarray);

            waitForInput();
            break;
        //Selection 3: Ausparken
        case 3:
            cout << "Auf welchem Parkplatz stehen sie?";
            cout << "(1-" << spaces << ")" << endl;
            cin >> parkselection;
            if (parkarray[parkselection - 1] == OCCUPIED) {
                cout << "Vielen dank dass sie hier geparkt haben!" << endl;
                parkarray[parkselection - 1] = FREE;
            }

            waitForInput();
            break;
        //Selection 4: Mieten
        case 4:
            setArray(parkarray, OCCUPIED);
            cout << "Alle Parkplaetze sind nun fuer sie reserviert!" << endl;
            
            waitForInput();
            break;
        //Selection 5: Ausgabe erster, freier Parkplatz
        case 5:
            if (findFirstFree(parkarray) != -1) {
                cout << "Der erste, freie Parkplatz ist: Nummer ";
                cout << findFirstFree(parkarray) + 1 << endl;
            } else {
                cout << "Alle Parkplaetze sind belegt" << endl;
            }

            waitForInput();
            break;
        //Selection 6: Anzahl freier Parkplaetze
        case 6:
            cout << "Anzahl freier Parkplaetze: ";
            cout << countFreeSpaces(parkarray) << endl;

            waitForInput();
            break;
        }
    } while (selection != 0);
}

int findFirstFree(int parkarray[])
{
    for (int i = 0; i < spaces; i++) {
        if (parkarray[i] == FREE)
            return i;
    }
    return -1;
}

void printSpaces(int parkarray[])
{
    for (int i = 0; i < spaces; i++)
        cout << '|' << parkarray[i];

    cout << '|' << endl;
}

void setArray(int parkarray[], int setvalue)
{
    for (int i = 0; i < spaces; i++)
        parkarray[i] = setvalue;
}

int menu(void)
{
    int selection;

    do {
    system("clear");
    cout << "Park CLI\n--------------------" << endl;
    cout << "0: Programm beenden" << endl;
    cout << "1: Auto parken" << endl;
    cout << "2: Ausgabe der aktuellen Parkplatzbelegung" << endl;
    cout << "3: Auto ausparken" << endl;
    cout << "4: Alle Parkplaetze mieten" << endl;
    cout << "5: Erste, freie Parkplatznummer ausgeben" << endl;
    cout << "6: Anzahl freier Parkplaetze ausgeben" << endl;
    cout << "--------------------" << endl;
    cout << "Auswahl: ";
    cin >> selection;
    cout << "--------------------" << endl;
    } while (selection < 0 || selection > 6);

    return selection;
}

void waitForInput(void)
{
    cout << "\nZum fortfahren beliebige Taste druecken" << endl;
    getchar();
    getchar();
}

int countFreeSpaces(int parkarray[])
{
    int freeSpaces = 0;
    for (int i = 0; i < spaces; i++) {
        if (parkarray[i] == FREE)
            freeSpaces++;
    }
    return freeSpaces;
}
