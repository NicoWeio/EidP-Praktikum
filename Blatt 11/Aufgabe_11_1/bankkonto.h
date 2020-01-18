#ifndef BANKKONTO_H
#define BANKKONTO_H

#include <string>

using namespace std;

class Bankkonto {
protected:
    unsigned long pKontonummer = 0;
    string pInhaber;
    int pKontostand = 0;
public:
    Bankkonto() = default; //benötigt für List<Bankkonto>
    Bankkonto(unsigned long kontonummer, string inhaber);

    virtual void gutschreiben(int betrag);

    int kontostand();

    void anzeigen();

    unsigned long kontonummer() const;
};


#endif //BANKKONTO_H
