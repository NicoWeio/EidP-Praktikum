#include "girokonto.h"
#include <algorithm>

Girokonto::Girokonto(unsigned long kontonummer, string inhaber) : AuszahlbaresKonto(kontonummer, inhaber) {
    pAuszahlOffset = 1000 * 100;
}

int Girokonto::ueberweisen(Bankkonto &zielKonto, int betrag) {
    int cappedBetrag = std::min(betrag, (pKontostand + pAuszahlOffset));
    zielKonto.gutschreiben(cappedBetrag);
    pKontostand -= cappedBetrag;
    return cappedBetrag;
}
