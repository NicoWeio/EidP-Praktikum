#include "buch.h"
#include <iostream>
#include <string>
using namespace std;

// 1b)
Buch::Buch(string autor, string titel, unsigned int inventarnummer)
    : _autor(autor), _titel(titel), _inventarnummer(inventarnummer),
      _benutzernummer(0) {}

// 1c)
bool Buch::istVerliehen() { return _benutzernummer != 0; }
unsigned int Buch::inventarNummer() { return _inventarnummer; }
unsigned int Buch::ausgeliehenVon() { return _benutzernummer; }
bool Buch::verleiheAn(unsigned int benutzernummer) {
  if (_benutzernummer != 0) {
    return false;
  }
  _benutzernummer = benutzernummer;
  return true;
}
void Buch::rueckgabe() { _benutzernummer = 0; }
void Buch::print() {
  cout << "Buch - Inventarnummer " << _inventarnummer << ": " << _titel
       << " von " << _autor;
  if (_benutzernummer == 0)
    cout << ", verfügbar" << endl;
  else
    cout << ", ausgeliehen von Benutzer " << _benutzernummer << endl;
}
