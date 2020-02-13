#include <iostream>

using namespace std;

//////////////////////////////////////
//  Funktionssammlung der DataSol   //
//////////////////////////////////////

//Prototypen

//quadriere(): quadriert eine beliebige Zahl
float quadriere(float x);

//naechste(): gibt die nächste Ganzzahl zurück.
int next(float x);

//kleinste(): nimmt zwei Zahlen entgegen und gibt die kleinste davon zurück
int lower(int x, int y);

//groesste(): nimmt zwei Zahlen entgegen und gibt die größte davon zurück
int bigger(int x, int y);

//istGerade(): nimmt eine Ganzzahl entgegen und gibt mittels eines sinnvollen Datentyps zurück,
//ob die Zahl gerade ist oder nicht.
bool even(int x);

//istUngerade(): siehe istGerade(), aber für ungerade Zahlen
bool uneven(int x);

//runde(): rundet eine float-Variable auf oder ab und gibt ein int zurück
int round(float x, bool up);

//trennlinie(): gibt auf der Kommandozeile eine Trennlinie mit der gewünschten Länge aus (z.B. für Menüs)
//Beispiel: trennlinie (12) => Ergebnis: ============

//menueauswahl(): Fragt den Benutzer, welchen Menüpunkt er auswählen möchte und gibt das Ergebnis als int zurück

///////////////////
// Hauptprogramm //
///////////////////
int main()
{
    float f_Ergebnis = 0;
    int x, y;
    float fx;

   //Hier Funktionen testen:
//	cout << "Teste quadriere(4):\n";
//	f_Ergebnis = quadriere(4);
//	cout << "Ergebnis: " << f_Ergebnis << endl;
//	cin >> f_Ergebnis;
//
//	cout << next(f_Ergebnis) << endl;
	//cin >> x;
	//cin >> y;
	//cout << bigger(x, y) << endl;
	//if (uneven(x))
	//	cout << "Zahl ist ungerade" << endl;
	//else
	//	cout << "Zahl ist gerade" << endl;
	
	cin >> fx;
	cout << round(fx, true) << endl;
	cin >> fx;
	cout << round(fx, false) << endl;

	return 0;
}


/////////////////////////////////////////////////////////////////
// Definieren Sie ab hier die oben deklarierten Funktionen //
/////////////////////////////////////////////////////////////////
float quadriere(float x){
	float f_Quadrat = 0;
	f_Quadrat = x*x;
    return f_Quadrat;
}
int next(float x)
{
	return (int) x + 1;
}
int lower(int x, int y)
{
	if (x < y)
		return x;
	else
		return y;
}
int bigger(int x, int y)
{
	if (x > y)
		return x;
	else
		return y;
}
bool even(int x)
{
	if (!(x % 2))
		return true;
	else
		return false;
}
bool uneven(int x)
{
	if ((x % 2))
		return true;
	else
		return false;
}
int round(float x, bool up)
{
	if (up)
		return (int)x + 1;
	else
		return (int)x;
}