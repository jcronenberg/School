#include <iostream>

using namespace std;

// prototypes
void char_to_ascii(char *, int, bool);
void sorted_output(int *, int);
int highest_value(int *, int);
void sort_arr(int *, int);
int menu(bool *, int);
void manual_input_chars(char *, int *);
void fill_with_test_values(char *, int);

int main()
{
    int length = 58;
    char characters[length];
    bool sort = false;

    int sel = menu(&sort, length);

    switch (sel) {

    // manual input
    case 1:
        manual_input_chars(characters, &length);
        break;

    // preset
    case 2:
        fill_with_test_values(characters, length);
        break;

    default:
        cout << "WEIRD! This really shouldn't happen\n";
    }


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

// show a menu and return the selection
// parameters: sort, gets set to true if the user selects they want the array to be sorted, otherwise untouched
//             length, length of the characters array
int menu(bool *sort, int length)
{
    char c_input;

    // ask if output should be sorted
    do {
        cout << "Do you want to sort by ASCII-Value (ascending)?(y/n) ";
        cin >> c_input;
    } while (!(c_input == 'y' || c_input == 'n'));
    if (c_input == 'y')
        *sort = true;

    int i_input;

    // ask if manual input or preset
    do {
        cout << "Do you want to manually input characters (max: " << length << ") (1)\n";
        cout << "Or do you want to use a preset (All characters from A-z in "
                "reverse order) (2)\n";
        cin >> i_input;
    } while (i_input > 2 || i_input < 1);
    return i_input;
}

// manual input of characters into characters array
// parameters: characters, array that gets written into
//             length, max length of characters array, gets changed to the index of the last char if user exist prematurely
void manual_input_chars(char *characters, int *length)
{
    char input;

    cout << "If you want to stop inputting characters, input a '?'\n";
    for (int i = 0; i < *length; i++) {
        cout << "Input char: ";
        cin >> characters[i];
        if (characters[i] == '?') {
            cout << "If you want to add '?' to the array input 'a' now, everything "
                    "else will stop adding characters ";
            cin >> input;
            if (input != 'a') {
                *length = i;
                break;
            }
        }
    }
}

// fill array with preset values
// parameters: characters, array that gets written into
//             length, length of characters array
void fill_with_test_values(char *characters, int length)
{
    for (int i = 0; i < length; i++) {
        characters[length - 1 - i] = (char)(i + 65);
    }
}
