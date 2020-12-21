#include <iostream>
#include <fstream>

using namespace std;

struct reading
{
	int timestamp;
	int voltage;
	int current;
};

void read_append_readings(reading *&, int *, string);
reading *readings_random(int);
void output_readings(reading *, int);
void output_readings_interval(reading *, int, int, int);
int battery_charge(reading *, int);
int battery_discharge(reading *, int);
int battery_level(int, int);
void output_false_readings(reading *, int);
reading *allocate_one_more(reading *, int);
void write_readings(reading *, int, string );

int main()
{
    int length = 0;
    reading *readings = nullptr;

    // reading *readings = readings_random(length);
    read_append_readings(readings, &length, "input_readings.txt");
    read_append_readings(readings, &length, "input_readings2.txt");

    output_readings(readings, length);

    write_readings(readings, length, "output_readings.txt");

    // int start, end;

    // cout << "Output readings in an interval\n";

    // cout << "What's the startpoint? (1 - " << length << ")";
    // cin >> start;
    // start--;

    // cout << "What's the endpoint? (1 - " << length << ")";
    // cin >> end;

    // output_readings_interval(readings, start, end, length);

    // int positive_charge = battery_charge(readings, length);
    // int discharge = battery_discharge(readings, length);

    // cout << "Battery positive charge: " << positive_charge << " mAh\n";
    // cout << "Battery discharge: " << discharge << " mAh\n";
    // cout << "Overall battery level: " << battery_level(positive_charge, discharge) << " mAh\n\n";

    // cout << "False readings:\n";
    // output_false_readings(readings, length);

    delete[] readings;
    readings = nullptr;
}

void read_append_readings(reading *&readings, int *length, string filename)
{
    int index = *length;
    ifstream readfile;
    readfile.open(filename);

    if (!readfile) {
        cout << "Couldn't read file: " << filename << "\nExiting...\n";
        exit(1);
    } else {
        while (!readfile.eof()) {
            readings = allocate_one_more(readings, index);
            readfile >> readings[index].timestamp >> readings[index].voltage >> readings[index].current;
            index++;
        }
        readfile.close();
    }
    *length = index - 1;
}

void write_readings(reading *readings, int length, string filename)
{
    ofstream writefile;
    writefile.open(filename);

    if (!writefile) {
        cout << "Couldn't read file: " << filename << "\nExiting...\n";
        exit(1);
    } else {
        for (int i = 0; i < length; i++) {
            writefile << readings[i].timestamp << " ";
            writefile << readings[i].voltage << " ";
            writefile << readings[i].current << "\n";
        }
        writefile.close();
    }
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

reading *allocate_one_more(reading *readings, int length)
{
    reading *new_readings = new reading[length + 1];

    if (length > 0) {
        for (int i = 0; i < length; i++) {
            new_readings[i] = readings[i];
        }
        delete[] readings;
    }
    return new_readings;
}
