#ifndef AUSZAHLBARESKONTO_H
#define AUSZAHLBARESKONTO_H


#include "bankkonto.h"

class AuszahlbaresKonto : public Bankkonto {
protected:
    int pAuszahlOffset = 0;
public:
    AuszahlbaresKonto(unsigned long kontonummer, string inhaber);

    int auszahlen(int betrag);
};


#endif //AUSZAHLBARESKONTO_H
