#include "benutzer.h"
#include <iostream>

using namespace std;


Benutzer::Benutzer(string name, unsigned int benutzernummer)
    : _name(name), _benutzernummer(benutzernummer)
{}


unsigned int Benutzer::benutzerNummer() {
    return _benutzernummer;
}


void Benutzer::print() {
    cout << "Benutzer " << _benutzernummer << " " << _name << endl;
}
