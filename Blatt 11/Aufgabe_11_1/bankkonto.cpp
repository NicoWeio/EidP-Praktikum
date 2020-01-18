#include <iostream>
#include "bankkonto.h"

using namespace std;

Bankkonto::Bankkonto(unsigned long kontonummer, string inhaber) : pKontonummer(kontonummer), pInhaber(inhaber) {}

void Bankkonto::gutschreiben(int betrag) {
    if (betrag < 0) {
        cerr << "Negativer Betrag!" << endl;
        return;
    }
    pKontostand += betrag;
}

int Bankkonto::kontostand() {
    return pKontostand;
}

void Bankkonto::anzeigen() {
    cout << "Kontonummer: " << pKontonummer << endl
         << "Inhaber: " << pInhaber << endl
         << "Kontostand: " << pKontostand << " (" << pKontostand / 100 << " €)" << endl
         << endl;
}

unsigned long Bankkonto::kontonummer() const {
    return pKontonummer;
}
