#include <iostream>
#include <iomanip>

using namespace std;

int menue(void);
float eingabeBetrag(void);
float berechneEndbetrag(float kapital, float zinssatz, int laufzeit);
void berechneEndbetrag_jaehrlich(float kapital, float zinssatz, int laufzeit);
float power(float, int);
void tilgung(int, float, int);
void eingabe(int, float&, float&, int&);

int main() {
	float kapital = 0.0;
	float endkapital = 0.0;
	float zinssatz = 0.0;
	int laufzeit = 0;
	int auswahl = 0;
	char nochmal = 'n';

	do {
		system("clear");

		auswahl = menue();

		switch(auswahl) {
		case 1:
			system("clear");
			cout << "Sparplan berechnen\n\n";
			eingabe(auswahl, kapital, zinssatz, laufzeit);
			endkapital = berechneEndbetrag(kapital, zinssatz, laufzeit);
			cout << "\nNach " << laufzeit << " Jahren: ";
			cout << setprecision(2) << fixed << endkapital << endl;
			break;
		case 2:
			system("clear");
			cout << "Sparplan mit jaehrlicher Ausgabe\n\n";
			eingabe(auswahl, kapital, zinssatz, laufzeit);
			berechneEndbetrag_jaehrlich(kapital, zinssatz, laufzeit);
			break;
		case 3:
			system("clear");
			cout << "Tilgungsplan\n\n";
			eingabe(auswahl, kapital, zinssatz, laufzeit);
			tilgung(kapital, zinssatz, laufzeit);
			break;
		default:
			cout << "Menuepunkt existiert nicht" << endl;
		}

		cout << "\n\nWollen Sie nochmal? <J/N> ";
		cin >> nochmal;

	} while (nochmal == 'j' || nochmal == 'J');

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
void eingabe(int auswahl, float& kapital, float& zinssatz, int& laufzeit)
{
	if (auswahl != 3)
		cout << "Bitte geben Sie die Startkapital in Euro ein: ";
	else
		cout << "Bitte geben Sie die Kreditsumme in Euro ein: ";
	kapital = eingabeBetrag();
	cout << "Bitte geben Sie den Zinssatz in \% ein: ";
	zinssatz = eingabeBetrag();
	cout << "Bitte geben Sie die Laufzeit in Jahren ein: ";
	laufzeit = eingabeBetrag();
}


void tilgung(int ksumme, float zinssatz, int laufzeit)
{
	float q, qn;
	float annuitaet, zinsanteil, tilgung, geszinsen;
	float restschulden = ksumme;

	cout << setprecision(2) << fixed;

	zinssatz /= 100;
	q = zinssatz + 1;
	qn = power(q, laufzeit);

	annuitaet = ksumme * ((zinssatz * qn) / (qn - 1));

	cout << "Jaehrliche Annuitaet: " << annuitaet << endl;
	cout << "\n\t\t\tZinsanteil\tTilgungsanteil\tRestschuld\n\n";

	for(int i = 1; i <= laufzeit; i++) {
		zinsanteil = ksumme * ((qn - power(q, i-1)) / (qn - 1)) * zinssatz;
		geszinsen += zinsanteil;
		tilgung = ksumme * ((q - 1) / (qn - 1)) * power(q, i-1);
		restschulden -= tilgung;
		if (i >= laufzeit)
			restschulden = 0;

		cout << "Nach dem " << i << ".Jahr:\t";
		cout.width(10); cout << right << zinsanteil << "\t";
		cout.width(14); cout << right << tilgung << "\t";
		cout.width(10); cout << right << restschulden << endl;
	}

	cout << "\nGesamte Zinsen: " << geszinsen << endl;
}

float power(float a, int b)
{
	float ergebnis = a;

	if (!b)
		return 1;

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
	cout << setprecision(2) << fixed << "\n\n";

	for(int i = 1; i <= laufzeit; i++) {
		cout << "Nach dem " << i << ".Jahr:\t";
		cout << berechneEndbetrag(kapital, zinssatz, i) << endl;
	}
}
