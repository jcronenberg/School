#include <iostream>

using namespace std;

struct reading
{
	int timestamp;
	int voltage;
	int current;
};

reading *readings_random(int);
void output_readings(reading *, int);
void output_readings_interval(reading *, int, int, int);
int battery_charge(reading *, int);
int battery_discharge(reading *, int);
int battery_level(int, int);
void output_false_readings(reading *, int);

int main()
{
    int length;
    cout << "Input amount of readings: ";
    cin >> length;

    reading *readings = readings_random(length);

    output_readings(readings, length);

    int start, end;

    cout << "Output readings in an interval\n";

    cout << "What's the startpoint? (1 - " << length << ")";
    cin >> start;
    start--;

    cout << "What's the endpoint? (1 - " << length << ")";
    cin >> end;

    output_readings_interval(readings, start, end, length);

    int positive_charge = battery_charge(readings, length);
    int discharge = battery_discharge(readings, length);

    cout << "Battery positive charge: " << positive_charge << " mAh\n";
    cout << "Battery discharge: " << discharge << " mAh\n";
    cout << "Overall battery level: " << battery_level(positive_charge, discharge) << " mAh\n\n";

    cout << "False readings:\n";
    output_false_readings(readings, length);

    delete[] readings;
    readings = nullptr;
}

reading *readings_random(int length)
{
    int i;
    reading *readings = nullptr;
    readings = new reading[length];
    if (readings != nullptr) {
        for (i = 0; i < length; i++) {

            if (i % 10 == 0)
                {
                    readings[i].timestamp = i + 1;
                    (readings + i)->voltage =
                        rand() % 40001 + (380000);
                    (readings + i)->current = 999999;
                } else {
                readings[i].timestamp = i + 1;
                (readings + i)->voltage =
                    rand() % 40001 + (380000);
                (readings + i)->current =
                    rand() % 180001 + (-9000);
            }
        }
    }

    return readings;
}

void output_readings(reading *readings, int length)
{
    for (int i = 0; i < length; i++) {
        cout << "Reading " << i + 1 << "\n";
        cout << "Timestamp: " << readings[i].timestamp << "\n";
        cout << "Voltage: " << readings[i].voltage << "\n";
        cout << "Current: " << readings[i].current << "\n\n";
    }
}
void output_readings_interval(reading *readings, int start, int end, int length)
{
    if (start < 0 || end > length)
        return;

    for (int i = start; i < end; i++) {
        cout << "Reading " << i + 1 << "\n";
        cout << "Timestamp: " << readings[i].timestamp << "\n";
        cout << "Voltage: " << readings[i].voltage << "\n";
        cout << "Current: " << readings[i].current << "\n\n";
    }
}

int battery_charge(reading *readings, int length)
{
    int sum = 0;

    for (int i = 0; i < length; i++) {
        if (readings[i].current > 0) {
            sum += readings[i].current;
        }
    }

    return sum;
}

int battery_discharge(reading *readings, int length)
{
    int sum = 0;

    for (int i = 0; i < length; i++) {
        if (readings[i].current < 0) {
            sum += readings[i].current;
        }
    }

    return sum;
}

int battery_level(int positive_charge, int discharge)
{
    return positive_charge + discharge;
}

void output_false_readings(reading *readings, int length)
{
    for (int i = 0; i < length; i++) {
        if (readings[i].current == 999999) {
            cout << "False reading at position: " << i + 1 << "\n";
        }
    }
}
