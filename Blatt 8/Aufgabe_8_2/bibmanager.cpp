#include "bibmanager.h"

#include <iostream>
#include <limits>
#include <string>
#include <sstream>

using namespace std;


template<typename T> T readFromCIN() {
    T r;
    bool tryAgain = true;
    while (tryAgain) {
        string s;
        cin >> s;
        stringstream helper(s);
        helper >> r;
        if (helper.fail()) {
            cout << "Ungueltige Eingabe" << endl;
        } else {
            tryAgain = false;
        }
    }
    return r;
}


BibliotheksManager::BibliotheksManager(Bibliothek* bib)
    : _bib(bib) {
//  _bib->erfasse("George R. R. Martin", "A game of thrones");
//  _bib->erfasse("George R. R. Martin", "A clash of kings");
//  _bib->erfasse("George R. R. Martin", "A storm of swords");
//  _bib->erfasse("George R. R. Martin", "A feast for crows");
//  _bib->erfasse("George R. R. Martin", "A dance with dragons");
//  _bib->erfasse("George R. R. Martin", "The winds of winter");
//  _bib->erfasse("George R. R. Martin", "A dream of spring");
    _bib->erfasse("Donald E. Knuth",
            "The Art of Computer Programming 1 - Fundamental algorithms");
    _bib->erfasse("Donald E. Knuth",
            "The Art of Computer Programming 2 - Seminumerical algorithms");
    _bib->erfasse("Donald E. Knuth",
            "The Art of Computer Programming 3 - Sorting and searching");
    _bib->erfasse("Stephen Hawking", "A brief history of time");
    _bib->erfasse("Stephen Hawking", "The universe in a nutshell");

    _bib->anmelden("Max Mustermann");
    _bib->anmelden("Dagobert Duck");
    _bib->anmelden("Bruce Wayne");
    _bib->anmelden("Peter Parker");
    _bib->anmelden("Jon Snow");
}


void BibliotheksManager::manage() {
    bool run = true;

    while (run) {
        cout
                << "-----EidP Bibliothek-----"
                << endl;
        cout << "Unterstuetzte Aktionen:" << endl;
        cout << "\t b = Beenden." << endl;
        cout << "\t l = Liste aller Buecher anzeigen." << endl;
        cout << "\t m = Liste aller Benutzer anzeigen." << endl;
        cout << "\t r = Buch zurueckgeben." << endl;
        cout << "\t a = Buch ausleihen." << endl;
        cout << "Befehl? " << endl;
        char c = readFromCIN<char>();
        switch (c) {
        case 'b': {
            cout << "System beendet." << endl;
            run = false;
            break;
        }
        case 'l': {
            _bib->listeBuecherAuf();
            break;
        }
        case 'm': {
            _bib->listeBenutzerAuf();
            break;
        }
        case 'a': {
            cout << "Ausleihen: Inventarnummer des Buches?" << endl;
            unsigned int buch = readFromCIN<unsigned int>();
            cout << "Ausleihen: Benutzernummer?" << endl;
            unsigned int benutzernummer = readFromCIN<unsigned int>();
            Bibliothek::Resultat result = _bib->ausleihe(buch, benutzernummer);

            switch (result) {
            case Bibliothek::AUSLEIHE_OK:
                cout << "Buch ausgeliehen" << endl;
                break;
            case Bibliothek::BENUTZER_NICHT_VORHANDEN:
                cout << "Unbekannte Benutzersnummer" << endl;
                break;
            case Bibliothek::BUCH_AUSGELIEHEN:
                cout << "Buch leider bereits ausgeliehen" << endl;
                break;
            case Bibliothek::BUCH_NICHT_VORHANDEN:
                cout << "Unbekanntes Buch, Inventarnummer nicht gefunden" << endl;
                break;
            }
            break;
        }
        case 'r': {
            cout << "Rueckgabe: Inventarnummer des Buches?" << endl;
            unsigned int buch = readFromCIN<unsigned int>();
            if (_bib->rueckgabe(buch)) {
                cout << "Rueckgabe eingetragen." << endl;
            } else {
                cout << "Unbekanntes Buch, Inventarnummer nicht gefunden"
                        << endl;
            }
            break;
        }
        default: {
            cout << "Unbekannter Befehl: " << c << endl;
        }
        }
        cout << endl;
    }
}
