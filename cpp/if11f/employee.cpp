#include <iostream>
#include <string>

using namespace std;

struct employee
{
    string lastname;
    int id;
};

const int maxEmployees = 100;
employee employees[maxEmployees];

void sort_lastname() {
    bool sorted = false;
    string tmp;
    for (int j = 0; j < maxEmployees - 1 && !sorted; j++) {
        sorted = true;
        for (int i = 0; i < maxEmployees - 1 - j; i++) {
            char first_char1 = employees[i].lastname[0];
            char first_char2 = employees[i + 1].lastname[0];
            if (first_char1 > first_char2) {
                tmp = employees[i].lastname;
                employees[i].lastname = employees[i + 1].lastname;
                employees[i + 1].lastname = tmp;
                sorted = false;
            }
        }
    }
}

int main() {
  char cAuswahl;
  int freeID = 0;
  for (int i = 0; i < maxEmployees; i++) {
      employees[i].lastname = "None";
      employees[i].id = i;
  }

  do {
    // Menu
    system("clear");
    cout << "Employee management system: " << endl;
    cout << "#####################" << endl;
    cout << "1.\tShow employees" << endl;
    cout << "2.\tCreate employee" << endl;
    cout << "3.\tSort employees" << endl;
    cout << "Your choice: ";

    cin >> cAuswahl;
    system("clear");

    // Query choice
    switch (cAuswahl) {
    case '1': {
        for (int i = 0; i < freeID; i++) {
            if (employees[i].lastname.compare("None") != 0) {
              cout << "Employee name: " << employees[i].lastname << endl;
              cout << "Employee id: " << employees[i].id << "\n\n";
            }
        }
        break;
    }
    case '2': {
        cout << "What is the employees name? ";
        cin >> employees[freeID].lastname;

        freeID++;
        if (freeID >= maxEmployees) {
            cout << "Too many employees" << endl;
            freeID--;
        }
        break;
    }
    case '3': {
        sort_lastname();
        break;
    }
    default: {
        cout << "Not a valid input" << endl;
    }
    }
    getchar();
    getchar();
  } while (cAuswahl != '5');

  return 0;
}
