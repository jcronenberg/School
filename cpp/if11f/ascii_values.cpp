#include <iostream>

using namespace std;

// prototypes
void char_to_ascii(char *, int, bool);
void sorted_output(int *, int);
int highest_value(int *, int);
void sort_arr(int *, int);

int main()
{
    const int length = 58;
    char characters[length];
    char input;
    bool sort = false;

    // for testing, fill characters with all ascii value from A - z
    for (int i = 0; i < length; i++) {
        characters[length - 1- i] = (char)(i + 65);
    }

    // ask if output should be sorted
    do {
        cout << "Do you want to sort by ASCII-Value (ascending)?(y/n) ";
        cin >> input;
    } while (!(input == 'y' || input == 'n'));
    if (input == 'y')
        sort = true;

    char_to_ascii(characters, length, sort);
}

// print a table with the chars of char_arr and corresponding ASCII-Value
// parameters: char_arr, the char array on which the table is based
//             length, length of char_arr
//             sort, if the table should be sorted by ASCII-Value
void char_to_ascii(char *char_arr, int length, bool sort)
{
    int int_arr[length];

    // Fill int_arr with corresponding values from char_arr
    for (int i = 0; i < length; i++) {
        int_arr[i] = (int)char_arr[i];
    }

    // Output table header
    cout << "Char\tASCII-VALUE\n";

    // Output table sorted or not
    if (sort) {
        sorted_output(int_arr, length);
    } else {
        for (int i = 0; i < length; i++) {
            cout << char_arr[i] << "\t" << int_arr[i] << "\n";
        }
    }

    // Output highest ascii value
    cout << "\nHighest ASCII-Value: " << highest_value(int_arr, length) << "\n";
}

// output table sorted
// parameters: arr, the array on which the table is based
//             length, length of arr
void sorted_output(int *arr, int length)
{
    sort_arr(arr, length);

    // Output table sorted
    for (int i = 0; i < length; i++) {
        cout << (char)arr[i] << "\t" << arr[i] << "\n";
    }
}

// sort an array (uses bubblesort)
// parameters: arr, the array to sort
//             length, length of arr
void sort_arr(int *arr, int length)
{
    // Bubble sort
    bool sorted = false;
    int tmp;
    for (int j = 0; j < length - 1 && !sorted; j++) {
        sorted = true;
        for (int i = 0; i < length - 1 - j; i++) {
            if (arr[i] > arr[i + 1]) {
                tmp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = tmp;
                sorted = false;
            }
        }
    }
}

// return the highest value of an array
// parameters: arr, the array from which to return the highest value
//             length, length of arr
int highest_value(int *arr, int length)
{
    int tmp = 0;

    for (int i = 0; i < length; i++) {
        if (arr[i] > tmp)
            tmp = arr[i];
    }

    return tmp;
}
