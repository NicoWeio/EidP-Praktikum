#include "tagesgeldkonto.h"
#include <algorithm>

Tagesgeldkonto::Tagesgeldkonto(unsigned long kontonummer, string inhaber, Girokonto &referenzkonto) : Bankkonto(
        kontonummer, inhaber), pReferenzkonto(referenzkonto) {}

int Tagesgeldkonto::umbuchen(int betrag) {
    int cappedBetrag = std::min(betrag, pKontostand);
    pKontostand -= cappedBetrag;
    pReferenzkonto.gutschreiben(cappedBetrag);
    return cappedBetrag;
}
