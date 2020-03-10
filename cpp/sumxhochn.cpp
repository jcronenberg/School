#include <iostream>
#include <cmath>

using namespace std;

int main() {
	int n;
	float x;
	float ergebnis;

	cout << "Eingabe\n-----------------------" << endl;
	cout << "X:";
	cin >> x;
	cout << "N:";
	cin >> n;
	cout << "Ausgabe\n-----------------------" << endl;

	for(int i = 0; i <= n; i++) {
		ergebnis = ergebnis + pow(x, i);
		cout << ergebnis << endl;
	}
}
