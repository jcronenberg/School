#include <iostream>

using namespace std;

int main() {
	unsigned int kand1 = 0;
	unsigned int kand2 = 0;
	unsigned int summe = 0;
	float f_prozkand1 = 0;
	float f_prozkand2 = 0;

	//Eingabe
	cout << "Stimmen von Kandidat 1: ";
	cin >> kand1;
	cout << "Stimmen von Kandidat 2: ";
	cin >> kand2;
	
	//Rechnung
	summe = kand1 + kand2;
	cout << summe;
	f_prozkand1 = (float) kand1 / summe * 100;
	f_prozkand2 = (float) kand2 / summe * 100;

	//Ausgabe
	cout << "\nKandidat 1 hat: " << f_prozkand1 << "%";
	cout << "\nKandidat 2 hat: " << f_prozkand2 << "%\n";



	getchar();
	return 0;
}
