#ifndef AUFGABE_13_STUDENT_H
#define AUFGABE_13_STUDENT_H

#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Student {
private:
    string name;
    unsigned int matrikelnummer;
public:
    Student(string name, unsigned int matrikelnummer);

    const string &getName() const;

    unsigned int getMatrikelnummer() const;

    bool operator<(Student const &s2) const;

};

ostream &operator<<(ostream &os, const Student &student);

bool duplikat(vector<Student> &studenten);

class StudentListNotSortedException : exception {
};

#endif //AUFGABE_13_STUDENT_H
