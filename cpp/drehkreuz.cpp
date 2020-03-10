#include <iostream>

using namespace std;

int main() {
	cout << "Drehkreuzsteuerung" << endl;
	cout << "------------------------\n\n";

	for(int i = 30 ; i > 0 ; i--) {
		if(i != 1)
			cout << "Noch " << i << " Plaetze verfuegbar" << endl;
		else
			cout << "Noch " << i << " Platz verfuegbar" << endl;
		cout << "Bitte einsteigen" << endl;
		getchar();
		cout << "- Signal Drehkreuz -" << endl;
	}
	cout << "Kein freier Platz verfuegbar\nBitte nicht mehr einsteigen" << endl;

}
