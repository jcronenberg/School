#include <iostream>

using namespace std;

// prototypes
unsigned int *input_readings(unsigned int *);
void output_readings(unsigned int *, unsigned int);
float calculate_median(unsigned int *, unsigned int);
unsigned int *allocate_one_more(unsigned int *, unsigned int);

int main()
{
    unsigned int count_readings = 0;

    unsigned int *readings = input_readings(&count_readings);

    output_readings(readings, count_readings);

    delete[] readings;
}

unsigned int *input_readings(unsigned int *length)
{
    unsigned int *readings;
    cout << "Input readings now (to quit input a negative value)\n";

    for (int i = 0;; i++) {
        int input;

        cout << "Reading " << i + 1 << " is: ";
        cin >> input;

        if (input < 0) {
            *length = i;
            break;
        } else {
            readings = allocate_one_more(readings, i);
            readings[i] = input;
        }
    }
    return readings;
}

void output_readings(unsigned int *readings, unsigned int length)
{
    cout << "\n\nThe readings:\n";
    for (int i = 0; i < length; i++) {
        cout << "Reading " << i + 1 << " is: " << readings[i] << "\n";
    }

    cout << "Median value: " << calculate_median(readings, length) << "\n";
}

float calculate_median(unsigned int *readings, unsigned int length)
{
    unsigned int sum = 0;

    for (int i = 0; i < length; i++) {
        sum += readings[i];
    }

    return (float)sum / length;
}

// allocates a new unsigned int array with length + 1
// deletes original readings and then returns the pointer to the new array
unsigned int *allocate_one_more(unsigned int *readings, unsigned int length)
{
    unsigned int *new_readings = new unsigned int[length + 1];

    if (length > 0) {
        for (int i = 0; i < length; i++) {
            new_readings[i] = readings[i];
        }
        delete[] readings;
    }
    return new_readings;
}
