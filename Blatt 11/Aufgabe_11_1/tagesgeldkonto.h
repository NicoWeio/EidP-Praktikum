#ifndef TAGESGELDKONTO_H
#define TAGESGELDKONTO_H

#include "girokonto.h"

class Tagesgeldkonto : public Bankkonto {
protected:
    Girokonto &pReferenzkonto;
public:
    Tagesgeldkonto(unsigned long kontonummer, string inhaber, Girokonto &referenzkonto);

    int umbuchen(int betrag);
};


#endif //TAGESGELDKONTO_H
