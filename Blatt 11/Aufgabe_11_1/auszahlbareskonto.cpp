#include "auszahlbareskonto.h"
#include <algorithm>

AuszahlbaresKonto::AuszahlbaresKonto(unsigned long kontonummer, string inhaber) : Bankkonto(kontonummer, inhaber) {}

int AuszahlbaresKonto::auszahlen(int betrag) {
    int cappedBetrag = std::min(betrag, (pKontostand + pAuszahlOffset));
    pKontostand -= cappedBetrag;
    return cappedBetrag;
}
