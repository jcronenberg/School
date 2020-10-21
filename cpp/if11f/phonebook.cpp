#include <iostream>
#include <string>

using namespace std;

struct phone_book {
    int id;
    string last_name;
    string phone_number;
};

const int max_entries = 100;

phone_book yellow_pages[max_entries];
int cur_id = 0;

// Prototypes
int menu();
void print_entry(int);
void print_list();
bool new_entry();
bool search_entry(string);
void test_data();
bool delete_entry(int);
void shift_entries(int);
void switch_entries(int);
bool sort_entries(string);

int main()
{
    test_data();
    int selection = 0;
    do {
        selection = menu();

        string s_input;
        int i_input;

        switch (selection) {
        case 1:
            print_list();
            break;
        case 2:
            if (new_entry())
                cout << "Successfully added new entry!\n";
            else
                cout << "Sorry, couldn't add a new entry!\n";

            break;
        case 3:
            cout << "What Name or Number do you want to search for? ";
            cin >> s_input;
            if (!search_entry(s_input))
              cout << "Couldn't find a matching entry\n";
            break;
        case 4:
            cout << "What id do you want to delete? ";
            cin >> i_input;

            if (!delete_entry(i_input)) {
                cout << "id doesn't exist\n";
            }
            else {
                cout << "Successfully deleted entry " << i_input << endl;
                shift_entries(i_input);
            }

            break;
        case 5:
            sort_entries("name");
            break;
        case 6:
            sort_entries("id");
            break;
        case 7:
            break;
        default:
            cout << "Not a valid selection. Try again\n";
        }
    } while (selection != 7);
}

// Functions
int menu()
{
    cout << "My Phone Book:\n";
    cout << "-------------------\n";
    cout << "1.\tPrint phone book\n";
    cout << "2.\tEnter new entry\n";
    cout << "3.\tSearch for name or number\n";
    cout << "4.\tDelete entry by id\n";
    cout << "5.\tSort phone book by name\n";
    cout << "6.\tSort phone book by id\n";
    cout << "7.\tQuit\n\n";

    int selection;

    cout << "Selection: ";
    cin >> selection;

    return selection;
}

void print_entry(int index)
{
    cout << "id: " << yellow_pages[index].id << endl;
    cout << "Name: " << yellow_pages[index].last_name << endl;
    cout << "Phone Number: " << yellow_pages[index].phone_number << endl;
}

void print_list()
{
    for (int i = 0; i < cur_id; i++) {
        print_entry(i);
        cout << "\n";
    }
}

bool new_entry()
{
    if (cur_id >= max_entries)
        cout << "Warning! Reached max entry limit";
    else {
        yellow_pages[cur_id].id = cur_id + 1;

        string input;

        cout << "Enter name: ";
        cin >> input;
        yellow_pages[cur_id].last_name = input;
        cout << "Enter phone number: ";
        cin >> input;
        yellow_pages[cur_id].phone_number = input;

        cur_id++;
        return true;
    }
    return false;
}

bool search_entry(string comparison)
{
    bool retval = false;

    for (int i = 0; i < cur_id; i++) {
        if (yellow_pages[i].last_name == comparison || yellow_pages[i].phone_number == comparison) {
            print_entry(i);
            cout << "\n";
            retval = true;
        }
    }

    return retval;
}

void test_data()
{
  yellow_pages[0].id = 1;
  yellow_pages[0].last_name = "Maler";
  yellow_pages[0].phone_number = "091112345";

  yellow_pages[1].id = 2;
  yellow_pages[1].last_name = "Farst";
  yellow_pages[1].phone_number = "0176123456";

  yellow_pages[2].id = 3;
  yellow_pages[2].last_name = "Leard";
  yellow_pages[2].phone_number = "091234123";

  yellow_pages[3].id = 4;
  yellow_pages[3].last_name = "Maler";
  yellow_pages[3].phone_number = "0176212441";

  cur_id = 4;
}

bool delete_entry(int id)
{
    if (id > cur_id || id < 1)
        return false;

    yellow_pages[id - 1].id = 0;
    yellow_pages[id - 1].last_name = "";
    yellow_pages[id - 1].phone_number = "";

    return true;
}

void shift_entries(int id)
{
    for (int i = id; i < cur_id; i++) {
        yellow_pages[i - 1] = yellow_pages[i];
        yellow_pages[i - 1].id -= 1;
    }

    yellow_pages[cur_id].id = 0;
    yellow_pages[cur_id].last_name = "";
    yellow_pages[cur_id].phone_number = "";
    cur_id--;
}

void switch_entries(int index)
{
    phone_book tmp;
    tmp = yellow_pages[index];
    yellow_pages[index] = yellow_pages[index + 1];
    yellow_pages[index + 1] = tmp;
}

// sel can be "name" or "id" otherwise it returns false
bool sort_entries(string sel)
{
    bool sorted = false;
    for (int j = 0; j < cur_id - 1 && !sorted; j++) {
        sorted = true;
        for (int i = 0; i < cur_id - 1 - j; i++) {
            int comp_1, comp_2;
            if (sel == "name") {
                comp_1 = yellow_pages[i].last_name[0];
                comp_2 = yellow_pages[i + 1].last_name[0];
            } else if (sel == "id") {
                comp_1 = yellow_pages[i].id;
                comp_2 = yellow_pages[i + 1].id;
            } else {
                return false;
            }
            if (comp_1 > comp_2) {
                switch_entries(i);
                sorted = false;
            }
        }
    }
    return true;
}
