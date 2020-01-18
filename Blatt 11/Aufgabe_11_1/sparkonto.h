#ifndef SPARKONTO_H
#define SPARKONTO_H

#include "auszahlbareskonto.h"

class Sparkonto : public AuszahlbaresKonto {
protected:
    bool pIstAufgeloest = false;
public:
    Sparkonto(unsigned long kontonummer, string inhaber);

    int aufloesen();

    void gutschreiben(int betrag) override;
};


#endif //SPARKONTO_H
