#include <iostream>

using namespace std;

int main() {
	
	float anhalteweg = 0;
	float geschwindigkeit = 0;
	float weg = 0;
	int verzoegerung = 0;
	int reaktion = 0;
	int verhaeltnisse = 0;
	char nochmal = 'j';

	do
	{
		anhalteweg = 0;
		geschwindigkeit = 0;
		weg = 0;
		verzoegerung = 0;
		reaktion = 0;
		verhaeltnisse = 0;
		nochmal = 'j';

		system("clear");
		cout << "Bestimmung des Anhaltewegs" << endl;
		cout << "Geschwindigkeit: ";
		cin >> geschwindigkeit;
		cout << "Abstand: ";
		cin >> weg;
		cout << "Reaktion: ";
		cin >> reaktion;
		do {
			cout << "Die Verzoegerungswerte zu folgenden Situationen sind vorhanden:\n\n";
			cout << "1: Trockener Beton" << endl;
			cout << "2: Trockener Asphalt" << endl;
			cout << "3: Nasser Beton" << endl;
			cout << "4: Nasser Asphalt" << endl;
			cin >> verzoegerung;
			verhaeltnisse = verzoegerung;
			switch(verzoegerung) {
				case 1:
					verzoegerung = 9;
					break;
				case 2:
					verzoegerung = 7;
					break;
				case 3:
					verzoegerung = 5;
					break;
				case 4:
					verzoegerung = 3;
					break;
				default:
					cout << "Falsche Eingabe" << endl;
			}
					
		} while((verhaeltnisse < 1) || (verhaeltnisse > 4));

		geschwindigkeit = geschwindigkeit / 3.6;
		anhalteweg = geschwindigkeit * reaktion + geschwindigkeit * geschwindigkeit / (2 * verzoegerung);
		if (anhalteweg < weg) {
			cout << "Glueck gehabt!\nAnhalteweg: " << anhalteweg << endl;
		} else {
			cout << "Es kam zum Crash!\nAnhalteweg: " << anhalteweg << endl;
		}
		cout << "Wollen Sie noch eine Berechnung durchfuehren?(J/j)";
		cin >> nochmal;

	} while ((nochmal == 'j') || (nochmal == 'J'));
}
