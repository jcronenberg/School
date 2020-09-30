// Parkscheinautomat für 45 Minuten

#include <iostream>

using namespace std;

int main(void)
{
	while(true) {
		int iZeit = 0;
		double dBetrag = 0.0;
		char cTaste;
		const int iTakt = 15;
		const double dEinheit = 0.5;
	
		system ("clear");
		cout << "Bedienungs-Anleitung...\n";
		cout << "Maximal 45 Minuten == 3mal P ===\n";
		cout << "Druecken Sie die P-Taste!\n";
		cout << "Bestaetigen Sie mit O-Taste!\n";
		cout << "Start mit Parkzeit 0 min \n\n";

		do {
			cout << "Taste: ";  cin >> cTaste;
			if(cTaste == 'p' || cTaste == 'P') {
				iZeit = iZeit + iTakt;
				dBetrag = dEinheit * iZeit / iTakt;
				cout << "Parkzeit: " << iZeit << ", Zahlbetrag: " << dBetrag << endl;
			}
		} while ((cTaste == 'p' || cTaste == 'P') && iZeit < 45);
		if(iZeit > 0) {
			cout << "Finale Parkzeit: " << iZeit << ", Zahlbetrag: " << dBetrag << endl;
		} else {
			cout << "Fehlerhafte eingabe" << endl;
		}
		getchar();
		getchar();
	}
	return 0;
}



