#include <iostream>

using namespace std;

int menue(void);
float eingabeBetrag(void);
float berechneEndbetrag(float kapital, float zinssatz, int laufzeit);
void berechneEndbetrag_jaehrlich(float kapital, float zinssatz, int laufzeit);
float power(float, int);
int tilgung(int, float, int);

int main() {
	float kapital = 0.0;
	float endkapital = 0.0;
	float zinssatz = 0;
	int laufzeit = 0;
	int auswahl = 0;
	char nochmal = 'n';

	do {
		system("clear");

		auswahl = menue();

		switch(auswahl) {
		case 1:
			cout << "Bitte geben Sie das Startkapital in Euro ein: ";
			kapital = eingabeBetrag();
			cout << "Bitte geben Sie den Zinssatz in \% ein: ";
			zinssatz = eingabeBetrag();
			cout << "Bitte geben Sie die Laufzeit in Jahren ein: ";
			laufzeit = eingabeBetrag();
			endkapital = berechneEndbetrag(kapital, zinssatz, laufzeit);
			cout << endkapital << endl;
			break;
		case 2:
			cout << "Bitte geben Sie das Startkapital in Euro ein: ";
			kapital = eingabeBetrag();
			cout << "Bitte geben Sie den Zinssatz in \% ein: ";
			zinssatz = eingabeBetrag();
			cout << "Bitte geben Sie die Laufzeit in Jahren ein: ";
			laufzeit = eingabeBetrag();
			berechneEndbetrag_jaehrlich(kapital, zinssatz, laufzeit);
			break;
		case 3:
			cout << "Bitte geben Sie die Kreditsumme in Euro ein: ";
			kapital = eingabeBetrag();
			cout << "Bitte geben Sie den Zinssatz in \% ein: ";
			zinssatz = eingabeBetrag();
			cout << "Bitte geben Sie die Laufzeit in Jahren ein: ";
			laufzeit = eingabeBetrag();
			tilgung(kapital, zinssatz, laufzeit);
			break;
		default:
			cout << "Menuepunkt existiert nicht" << endl;
		}
		cout << "\n\n\nWollen Sie nochmal? <J/N> ";
		cin >> nochmal;

	} while(nochmal == 'j' || nochmal == 'J');

}

int menue(void)
{
	int auswahl;

	cout << "------------------------------------\n\n";
	cout << " Bitte Menuepunkt auswaehlen\n\n";
	cout << " <1> Sparplan berechnen" << endl;
	cout << " <2> Sparplan mit jaehrlicher Ausgabe" << endl;
	cout << " <3> Tilgungsplan\n\n";
	cout << "------------------------------------\n";
	cout << "Ihre Wahl: ";

	cin >> auswahl;
	return auswahl;
}
int tilgung(int ksumme, float zinssatz, int laufzeit)
{
	float annuitaet;
	float q;

	zinssatz /= 100;
	q = zinssatz + 1;

	annuitaet = ksumme * ((zinssatz * power(q, laufzeit)) / (power(q, laufzeit) - 1));


	cout << "Jaehrliche Annuitaet: " << annuitaet;

	for(int i = 1; i <= laufzeit; i++) {
		//zinsanteil = ksumme * ((q - 1) / (power(q, laufzeit) - 1)) * power(q, i - 1)
		//tilgung
		//restschulden
	}

	return 0;
}

float power(float a, int b)
{
	float ergebnis = a;

	for (int i = 1; i < b; i++)
		ergebnis *= a;

	return ergebnis;
}

float eingabeBetrag(void)
{
	float betrag = 0;

	cin >> betrag;

	if (betrag >= 0)
		return betrag;
	else
	{
		cout << "Vorsicht! Eingabe negativ, nehme mathematischen Betrag.\n";
		return betrag * -1;
	}
}
float berechneEndbetrag(float kapital, float zinssatz, int laufzeit)
{
	for(int i = 1; i <= laufzeit; i++)
		kapital *= 1 + (zinssatz / 100);

	return kapital;
}
void berechneEndbetrag_jaehrlich(float kapital, float zinssatz, int laufzeit)
{
	cout << "\n\n";

	for(int i = 1; i <= laufzeit; i++) {
		cout << "Nach dem " << i << ".Jahr:\t";
		cout << berechneEndbetrag(kapital, zinssatz, i) << endl;
	}
}
