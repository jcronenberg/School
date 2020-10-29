#include <iostream>

using namespace std;

// prototypes
void input_readings(unsigned int *, unsigned int *);
void output_readings(unsigned int *, unsigned int);
float calculate_average(unsigned int *, unsigned int);

int main()
{
    unsigned int count_readings;

    cout << "How many readings do you want to save? ";
    cin >> count_readings;

    unsigned int *readings = new unsigned int[count_readings];

    input_readings(readings, &count_readings);

    output_readings(readings, count_readings);

    delete [] readings;
}

void input_readings(unsigned int *readings, unsigned int *length)
{
    cout << "Input readings now (to quit input a negative value)\n";

    for (int i = 0; i < *length; i++) {
        int input;

        cout << "Reading " << i + 1 << " is: ";
        cin >> input;

        if (input < 0) {
            *length = i;
            break;
        } else {
            readings[i] = input;
        }
    }
}

void output_readings(unsigned int *readings, unsigned int length)
{
    cout << "\n\nThe readings:\n";
    for (int i = 0; i < length; i++) {
        cout << "Reading " << i + 1 << " is: " << readings[i] << "\n";
    }

    cout << "Average value: " << calculate_average(readings, length) << "\n";
}

float calculate_average(unsigned int *readings, unsigned int length)
{
    unsigned int sum = 0;

    for (int i = 0; i < length; i++) {
        sum += readings[i];
    }

    return (float)sum / length;
}
