#include "Student.h"

Student::Student(std::string name, unsigned int matrikelnummer) : name(name), matrikelnummer(matrikelnummer) {}

const std::string &Student::getName() const {
    return name;
}


unsigned int Student::getMatrikelnummer() const {
    return matrikelnummer;
}

bool Student::operator<(Student const &s2) const {
    return matrikelnummer < s2.matrikelnummer;
}

ostream &operator<<(ostream &os, const Student &student) {
    os << "Name " << student.getName() << ",  Matrikelnummer " << student.getMatrikelnummer();
    return os;
}

bool duplikat(vector<Student> &studenten) {
    if (studenten.size() <= 1) return false;

    for (int i = 1; i < studenten.size(); i++) {
//        if (!(i == 0 || studenten[i-1].getMatrikelnummer() == studenten[i].getMatrikelnummer()));
if (studenten[i - 1].getMatrikelnummer() > studenten[i].getMatrikelnummer()) throw StudentListNotSortedException();
        if (studenten[i - 1].getMatrikelnummer() == studenten[i].getMatrikelnummer()) return true;
    }
    return false;
}
