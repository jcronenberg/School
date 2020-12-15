#include <iostream>
#include <fstream>

using namespace std;

int christmas();
int int_array();

int main()
{
    // return christmas();
    return int_array();
}

int christmas()
{
    string filename = "christmas.txt";
    char c;
    ifstream readfile;
    readfile.open(filename);

    if (!readfile) {
        cout << "Couldn't read file: " << filename << "\nExiting...\n";
        return 1;
    } else {
        while ((c = readfile.get()) != EOF) {
            cout << c;
        }
        readfile.close();
    }
    return 0;
}

int int_array()
{
    string filename = "int_array.txt";
    int index;
    int i_a1[6];
    int i_a2[6];
    // char i_a[6];
    ifstream readfile;
    readfile.open(filename);

    if (!readfile) {
        cout << "Couldn't read file: " << filename << "\nExiting...\n";
        return 1;
    } else {
        while (!readfile.eof()) {
            if (index % 3 == 0)
                readfile >> i_a1[index / 3];
            else if (index % 3 == 2)
                readfile >> i_a2[index / 3];
            index++;
        }
        readfile.close();
    }

    for (int i = 0; i < (index / 3); i++) {
      cout << i_a1[i] << " ";
      cout << i_a2[i] << "\n";
    }
    return 0;
}
