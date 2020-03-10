#include <iostream>

using namespace std;

void sortThreenumbers(int&, int&, int&);
void changeValue(int&, int&);

int main() {
	int iz1, iz2, iz3;
	cin >> iz1;
	cin >> iz2;
	cin >> iz3;
	sortThreenumbers(iz1, iz2, iz3);
	cout << iz1 << " ," << iz2 << " ," << iz3 << endl;
}

void changeValue(int& iz1, int& iz2)
{
	int tmp = iz1;
	iz1 = iz2;
	iz2 = tmp;
}
void sortThreenumbers(int& iz1, int& iz2, int& iz3)
{
	if (iz2 > iz3)
		changeValue(iz2, iz3);
	if (iz1 > iz2)
	{
		changeValue(iz1, iz2);
		if (iz2 > iz3)
			changeValue(iz2, iz3);
	}
}
