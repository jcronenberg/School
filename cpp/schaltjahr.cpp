#include <iostream>

using namespace std;

int main() {
	int eingjahr;
	bool istsj;

	cout << "Geben sie das zu pruefende Jahr ein: ";
	cin >> eingjahr;

	if (eingjahr % 4 == 0) {	 
		if (eingjahr % 100 == 0) {
			if (eingjahr % 400 == 0) {
				istsj = true;
			} else {
				istsj = false;
			}
		} else {
			istsj = 1;
		}
	} else {
		istsj = 0;
	}

	if (istsj == true) {
		cout << "Es ist ein Schaltjahr!\n";
	} else {
		cout << "Es ist kein Schaltjahr!\n";
	}
}
