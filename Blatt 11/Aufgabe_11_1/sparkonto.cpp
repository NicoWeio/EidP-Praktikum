#include <iostream>
#include "sparkonto.h"

Sparkonto::Sparkonto(unsigned long kontonummer, string inhaber) : AuszahlbaresKonto(kontonummer, inhaber) {
    pAuszahlOffset = -1 * 100;
    pKontostand = 1 * 100;
}

int Sparkonto::aufloesen() {
    pIstAufgeloest = true;
    int merkerKontostand = pKontostand;
    pKontostand = 0;
    return merkerKontostand;
}

void Sparkonto::gutschreiben(int betrag) {
    if (pIstAufgeloest) {
        cerr << "Sparkonto ist aufgelöst!" << endl;
        return;
    }
    Bankkonto::gutschreiben(betrag); //die gutschreiben-Methode der Basisklasse aufrufen
}
