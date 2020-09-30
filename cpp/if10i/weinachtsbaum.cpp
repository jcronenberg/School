#include <iostream>

using namespace std;

int main() {
	int selection = 0;
	int hoehe = 0;
	char weiter = 'n';
	do {
		cout << "--- Weinachtsbaum\n\nWelche Variante soll gezeichnet werden? <1-4>: ";
		cin >> selection;
		switch(selection) {
			case 1:
				cout << "- Variante 1 -\n\nHoehe des Baumes eingeben <5-40>: ";
				cin >> hoehe;
				for(int i = 0; i <= hoehe; i++) {
					cout << "x" << endl;
				}
				break;
			case 2:
				cout << "- Variante 2 -\n\nHoehe des Baumes eingeben <5-40>: ";
				cin >> hoehe;
				for(int i = 1; i <= hoehe; i++) {
					for(int j = 1; j <= i; j++) {
						cout << "x ";
					}
					cout << endl;
				}
				break;
			case 3:
				cout << "- Variante 3 -\n\nHoehe des Baumes eingeben <5-40>: ";
				cin >> hoehe;
				for(int i = 1; i <= hoehe; i++) {
					for(int l = hoehe; l > i; l--) {
						cout << "  ";
					}
					for(int j = 1; j <= (i * 2) - 1; j++) {
						cout << "x ";
					}
					cout << endl;
				}
				break;
			case 4:
				cout << "- Variante 4 -\n\nHoehe des Baumes eingeben <5-40>: ";
				cin >> hoehe;
				int i;
				for(i = 1; i <= hoehe; i++) {
					for(int l = hoehe; l > i; l--) {
						cout << "  ";
					}
					for(int j = 1; j <= (i * 2) - 1; j++) {
						cout << "x ";
					}
					cout << endl;
				}
				for(int k = 0; k < 2; k++) { //alternativ hoehe/2
					for(int l = 0; l < i - 2; l++) {
						cout << "  ";
					}
					cout << "H" << endl;
				}
				break;
			default:
				cout << "Falsche Eingabe" << endl;
		}
		cout << "Soll ein weiterer Baum gezeichnet werden? <J/N>: ";
		cin >> weiter;
	} while (weiter == 'j' || weiter == 'J');
}
