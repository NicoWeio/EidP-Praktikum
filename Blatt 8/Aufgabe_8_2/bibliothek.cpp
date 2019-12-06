#include "bibliothek.h"
#include <iostream>

using namespace std;


Bibliothek::Bibliothek()
    : _naechsteInventarnummer(1), _naechsteBenutzernummer(1) {
}


Bibliothek::~Bibliothek() {
    for (unsigned int i = 0; i < _buecher.size(); ++i) {
        delete _buecher.elementAt(i);
    }
    for (unsigned int i = 0; i < _benutzer.size(); ++i) {
        delete _benutzer.elementAt(i);
    }
}


void Bibliothek::listeBuecherAuf() {
    if (_buecher.size() == 0)
        cout << "Es wurden noch keine Buecher erfasst!" << endl;
    else{
        // Liste der Buecher durchlaufen und ausgeben
        for (unsigned int i = 0; i < _buecher.size(); ++i) {
            _buecher.elementAt(i)->print();
        }
    }
}


void Bibliothek::listeBenutzerAuf() {
    if (_benutzer.size() == 0)
        cout << "Es wurden noch keine Benutzer angemeldet!" << endl;
    else{
        // Liste der Benutzer durchlaufen und ausgeben
        for (unsigned int i = 0; i < _benutzer.size(); ++i) {
            _benutzer.elementAt(i)->print();
        }
    }
}


Benutzer* Bibliothek::findeBenutzer(unsigned int benutzernummer) {
    // Liste der Benutzer durchlaufen
    for (unsigned int i = 0; i < _benutzer.size(); ++i) {
        // i-ten Benutzer ueberpruefen ob benutzernummer uebereinstimmt
        if (_benutzer.elementAt(i)->benutzerNummer() == benutzernummer)
            return _benutzer.elementAt(i);
    }
    return nullptr;
}


void Bibliothek::anmelden(std::string name) {
    Benutzer* m = new Benutzer(name, _naechsteBenutzernummer);
    _benutzer.append(m);
    ++_naechsteBenutzernummer;
}


void Bibliothek::erfasse(std::string autor, std::string titel) {
    cout << "erfasse() - Leider noch nicht implementiert" << endl;
}


bool Bibliothek::rueckgabe(unsigned int inventarnummer) {
    cout << "rueckgabe() - Leider noch nicht implementiert" << endl;
    return true;
}


Bibliothek::Resultat Bibliothek::ausleihe(unsigned int inventarnummer,
                                          unsigned int benutzernummer) {
    cout << "ausleihe() - Leider noch nicht implementiert" << endl;

    return AUSLEIHE_OK;
}
