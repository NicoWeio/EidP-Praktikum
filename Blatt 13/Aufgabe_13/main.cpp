#include <iostream>
#include <vector>
#include <algorithm>
#include "Student.h"

int main() {
    cout << boolalpha;

    // c)
    // unsortierte Liste mit Studenten erstellen
    vector<Student> studenten;
    studenten.push_back(Student("Ute Löw", 345678));
    studenten.push_back(Student("Horst Schirmeier", 123456));
    studenten.push_back(Student("Metin Tolan", 456789));
    studenten.push_back(Student("Joachim Stöckler", 567890));
    studenten.push_back(Student("Max Mustermann", 234567));

    // d)
    cout << "––– d): " << endl;
    for (auto it = studenten.begin(); it != studenten.end(); it++)
        cout << it->getName() << ", " << it->getMatrikelnummer() << endl;

    // e)
    // der "range-based for loop" erleichtert das Iterieren:
    cout << endl << "––– e): " << endl;
    for (auto &it : studenten)
        cout << "Student: " << it << endl;

    // h)
    try {
        cout << endl << "––– h): " << endl << "Duplikat: " << duplikat(studenten) << endl;
    }
    catch (StudentListNotSortedException &e) {
        cout << "!!! Fehler: Studenten-Vektor ist nicht sortiert !!!" << endl;
    }

    // f)
    sort(studenten.begin(), studenten.end());
    cout << endl << "––– f): " << endl;
    for (auto &it : studenten)
        cout << "Student: " << it << endl;

    // g) und h)
    try {
        cout << endl << "––– g): " << endl
        << "Duplikat (soll false sein): " << duplikat(studenten) << endl;
    }
    catch (StudentListNotSortedException &e) {
        cout << "!!! Fehler: Studenten-Vektor ist nicht sortiert !!!" << endl;
    }

    // Duplikat hinzufügen
    studenten.push_back(Student("Joachim Stöckler", 567890));
    sort(studenten.begin(), studenten.end());

    try {
        cout << "Duplikat (soll true sein): " << duplikat(studenten) << endl;
    }
    catch (StudentListNotSortedException &e) {
        cout << "!!! Fehler: Studenten-Vektor ist nicht sortiert !!!" << endl;
    }

    return 0;
}
