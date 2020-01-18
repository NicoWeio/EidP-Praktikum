#ifndef GIROKONTO_H
#define GIROKONTO_H

#include "auszahlbareskonto.h"

class Girokonto : public AuszahlbaresKonto {
public:
    Girokonto(unsigned long kontonummer, string inhaber);

    int ueberweisen(Bankkonto &zielKonto, int betrag);
};


#endif //GIROKONTO_H
