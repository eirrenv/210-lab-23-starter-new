// Goat.h

#ifndef GOAT_H
#define GOAT_H
#include <iostream>
using namespace std;

class Goat {
private:
    string name;
    int age;
    string color;
public: 
    Goat()                          { name = ""; age = 0; color = ""; }
    // write three more constructors
    Goat(string nm)                 { name = nm; age = 0; color = ""; }
    Goat(string nm, int a)          { name = nm; age = a; color = ""; }
    Goat(string nm, int a, string clr) { name = nm; age = a; color = clr; }

    // setters and getters
    void set_name(string n)         { name = n; };
    string get_name() const         { return name; };
    void set_age(int a)             { age = a; };
    int get_age() const             { return age; }
    void set_color(string c)        { color = c; }
    string get_color() const        { return color; }

    // write overloaded < operator for the std::list
    bool operator< (const Goat &other) const {
        return name < other.name;
    }
};

#endif