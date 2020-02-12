#include <iostream>

using namespace std;

int nettoberechnen(int brutto, int mwst);

int main() {
	int brutto = 0;

	cout << "Brutto Betrag eingeben: ";
	cin >> brutto;

	cout << "Netto: " << nettoberechnen(brutto, 19) << endl;
}

int nettoberechnen(int brutto, int mwst)
{
	float fmwst;
	fmwst = (float) mwst / 100;
	return brutto - (brutto * fmwst);
}
