#include <iostream>
#include <fstream>
#include <iomanip>
#include <list>
#include <random> // for random selection :)
#include "Goat.h"
using namespace std;

const int SZ_NAMES = 200, SZ_COLORS = 25, MAX_AGE = 20;

int select_goat(list<Goat> trip);
void delete_goat(list<Goat> &trip);
void add_goat(list<Goat> &trip, string nm[], string clr[]);
void display_trip(list<Goat> trip);
int main_menu();

int main() {
    srand(time(0));
    bool again = true;
    int choice;

    // create Goat list containing goats
    list<Goat> goatList;

    // read & populate arrays for names and colors
    ifstream fin("names.txt");
    string names[SZ_NAMES];
    int i = 0;
    while (fin >> names[i++]);
    fin.close();
    ifstream fin1("colors.txt");
    string colors[SZ_COLORS];
    i = 0;
    while (fin1 >> colors[i++]);
    fin1.close();

    while (again) {
        choice = main_menu();
        if ( choice == 1 ) {
            add_goat(goatList, names, colors);
        }
        else if ( choice == 2 ) {
            delete_goat(goatList);
        }
        else if ( choice == 3 ) {
            display_trip(goatList);
        }
        else {
            again = false;
        }
    }

    return 0;
}

int main_menu() {
    int choice = -1;

    while (choice < 1 || choice > 4) {
        cout << "*** GOAT MANAGER 3001 ***" << endl;
        cout << "[1] Add a goat" << endl;
        cout << "[2] Delete a goat" << endl;
        cout << "[3] List goats" << endl;
        cout << "[4] Quit" << endl;
        cout << "Choice --> ";
        cin >> choice;
        if (choice < 1 || choice > 4) {
            cout << "Invalid choice. Please input a number between 1 to 4" << endl;
        }
        else {
            return choice;
        }
    }
}

int select_goat(list<Goat> trip) {
    int choice;
    bool again = true;
    while (again) {
        display_trip(trip);
        cout << "Please choose a goat from the list: ";
        cin >> choice;
        if (choice < 1 || choice > trip.size()) {
            cout << "Invalid input. Please input a number between 1 and " << trip.size() << ": ";
        }
        else {
            return choice;
        }
    }
}

void delete_goat(list<Goat> &trip) {
    // added catch for an empty list
    if (trip.size() == 0) {
        cout << "List is empty, cannot delete any goats" << endl;
    } 
    else {
        int choice = select_goat(trip);
        auto it = trip.begin();
        advance(it, choice - 1);
        cout << "Deleting " << it->get_name() << endl;
        trip.erase(it);
    }
    
}

void add_goat(list<Goat> &trip, string nm[], string clr[]) {
    string name = nm[rand() % SZ_NAMES];
    int age = rand() % MAX_AGE + 1;
    string color = clr[rand() % SZ_COLORS];
    Goat tmpGoat(name, age, color);
    trip.push_back(tmpGoat);
}

void display_trip(list<Goat> trip) {
    // catch for empty list
    if (trip.size() == 0) {
        cout << "List is empty." << endl;
    }
    else {
        int j = 1;
        for (auto it = trip.begin(); it != trip.end(); ++it) {
            cout << "\t" << "[" << j << "] " << it->get_name() << " (" << it->get_age() << ", " << it->get_color() << ")" << endl;
            ++j;
        }
    }
}
