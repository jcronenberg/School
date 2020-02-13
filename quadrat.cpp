#include <iostream>

using namespace std;

void quadrat(int, int&, int&);

int main() {
	int flaeche = 0;
	int umfang = 0;
	int eingabe = 0;

	cout << "Bitte Seitenlaenge eingeben: ";
	cin >> eingabe;

	quadrat(eingabe, flaeche, umfang);

	cout << "Flaeche: " << flaeche << endl;
	cout << "Umfang: " << umfang << endl;
}

void quadrat(int seitenlaenge, int& flaeche, int& umfang) {
	flaeche = seitenlaenge * seitenlaenge;
	umfang = 4 * seitenlaenge;
}
