#include <iostream>

using namespace std;

#define FREE 0
#define OCCUPIED 1

int findFirstFree(int*);
void printSpaces(int*);
void setArray(int*, int setvalue);
int menu(void);
void waitForInput(void);
int countFreeSpaces(int*);

//Anzahl der Parkplaetze
const int spaces = 10;

int main()
{
    int parkarray[spaces];
    int auswahl = 0;
    int parkauswahl = 0;
    setArray(parkarray, FREE);

    do {
        auswahl = menu();
        //Auswahl 1: Parken
        if (auswahl == 1) {
            cout << "Auf welchem Parkplatz wollen sie parken?";
            cout << "(1-" << spaces << ")" << endl;
            cin >> parkauswahl;
            if (parkarray[parkauswahl - 1] == FREE) {
                cout << "Parkplatz ist frei, sie koennen parken" << endl;
                parkarray[parkauswahl - 1] = OCCUPIED;
            } else {
                cout << "Parkplatz ist leider bereits belegt,";
                cout << " bitte fahren sie weiter!" << endl;
            }

            waitForInput();
        }
        //Auswahl 2: Ausgabe
        else if (auswahl == 2) {
            printSpaces(parkarray);

            waitForInput();
        }
        //Auswahl 3: Ausparken
        else if (auswahl == 3) {
            cout << "Auf welchem Parkplatz stehen sie?";
            cout << "(1-" << spaces << ")" << endl;
            cin >> parkauswahl;
            if (parkarray[parkauswahl - 1] == OCCUPIED) {
                cout << "Vielen dank dass sie hier geparkt haben!" << endl;
                parkarray[parkauswahl - 1] = FREE;
            }

            waitForInput();
        }
        //Auswahl 4: Mieten
        else if (auswahl == 4) {
            setArray(parkarray, OCCUPIED);
            cout << "Alle Parkplaetze sind nun fuer sie reserviert!" << endl;
            
            waitForInput();
        }
        //Auswahl 5: Ausgabe erster, freier Parkplatz
        else if (auswahl == 5) {
            if (findFirstFree(parkarray) != -1) {
                cout << "Der erste, freie Parkplatz ist: Nummer ";
                cout << findFirstFree(parkarray) + 1 << endl;
            } else {
                cout << "Alle Parkplaetze sind belegt" << endl;
            }

            waitForInput();
        }
        //Auswahl 6: Anzahl freier Parkplaetze
        else if (auswahl == 6) {
            cout << "Anzahl freier Parkplaetze: ";
            cout << countFreeSpaces(parkarray) << endl;

            waitForInput();
        }
    } while (auswahl != 0);
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
    int auswahl;

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
    cin >> auswahl;
    cout << "--------------------" << endl;
    } while (auswahl < 0 || auswahl > 6);

    return auswahl;
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
