#include <iostream>

using namespace std;

#include "eidpliste.h"

int main() {

    cout << "Hinweis: Die Uebereinstimmung von Soll- mit Ist-Ausgaben ist nur eine notwendige,"
         << " aber keine hinreichende Bedingung für korrekten Code."
         << endl << endl;

    Liste<int> a;
    Liste<int> b;

    cout << "Test der Aufgabe c)" << endl;
    a.clear();
    a.append(1);
    a.append(2);
    a.append(3);
    a.append(4);
    a.append(5);

    b.append(6);
    b.append(7);
    b.append(8);

    cout << "Soll: 1 2 3 4 5" << endl;
    cout << "Ist:  ";
    a.print(true);
    cout << endl;
    cout << "Soll: 5 4 3 2 1" << endl;
    cout << "Ist:  ";
    a.print(false);
    cout << "Ende des Tests der Aufgabe c)" << endl << endl;

    cout << "Test der Aufgabe d)" << endl;
    a.reverse();
    cout << "Soll: 5 4 3 2 1" << endl;
    cout << "Ist:  ";
    a.print(true);
    cout << endl;
    cout << "Soll: 1 2 3 4 5" << endl;
    cout << "Ist:  ";
    a.print(false);
    cout << "Ende des Tests der Aufgabe d)" << endl << endl;

    cout << "Test der Aufgabe e)" << endl;
    a.clear();
    a.append(1);
    a.append(2);
    a.append(3);
    a.append(4);
    a.append(5);
    a.deleteAt(4);
    cout << "Soll: 1 2 3 4" << endl;
    cout << "Ist:  ";
    a.print(true);
    cout << endl;
    cout << "Soll: 4 3 2 1" << endl;
    cout << "Ist:  ";
    a.print(false);
    cout << endl;
    a.deleteAt(0);
    cout << "Soll: 2 3 4" << endl;
    cout << "Ist:  ";
    a.print(true);
    cout << endl;
    cout << "Soll: 4 3 2" << endl;
    cout << "Ist:  ";
    a.print(false);
    cout << endl;
    a.deleteAt(1);
    cout << "Soll: 2 4" << endl;
    cout << "Ist:  ";
    a.print(true);
    cout << endl;
    cout << "Soll: 4 2" << endl;
    cout << "Ist:  ";
    a.print(false);
    cout << endl;
    a.deleteAt(1);
    cout << "Soll: 2" << endl;
    cout << "Ist:  ";
    a.print(true);
    cout << endl;
    cout << "Soll: 2" << endl;
    cout << "Ist:  ";
    a.print(false);
    cout << endl;
    a.deleteAt(0);
    cout << "Soll: " << endl;
    cout << "Ist:  ";
    a.print(true);
    cout << endl;
    cout << "Soll: " << endl;
    cout << "Ist:  ";
    a.print(false);
    cout << "Ende des Tests der Aufgabe e)" << endl << endl;

    return 0;
}
