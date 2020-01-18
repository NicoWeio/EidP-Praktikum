#include <iostream>
#include "girokonto.h"
#include "sparkonto.h"
#include "tagesgeldkonto.h"
#include "eidpliste.h"

int main() {

    Girokonto girokonto(1234, "GIRO: Ute Löw");
    Sparkonto sparkonto(5678, "SPAR: Horst Schirmeier");
    Tagesgeldkonto tagesgeldkonto(9876, "TAGESGELD: Ute Löw", girokonto);

    sparkonto.anzeigen();
    sparkonto.gutschreiben(9 * 100);
    sparkonto.anzeigen();
    cout << "-- 2€ auszahlen: "
         << sparkonto.auszahlen(2 * 100)
         << endl;
    sparkonto.anzeigen();
    cout << "-- 20€ auszahlen: "
         << sparkonto.auszahlen(20 * 100)
         << endl;
    sparkonto.anzeigen();


    girokonto.gutschreiben(100 * 100);
    girokonto.anzeigen();
    cout << "-- 2000€ auszahlen: "
         << girokonto.auszahlen(2000 * 100)
         << endl;
    girokonto.anzeigen();


    girokonto.gutschreiben(3000 * 100);
    girokonto.anzeigen();
    cout << "-- 2000€ überweisen: "
         << girokonto.ueberweisen(sparkonto, 2000 * 100)
         << endl;
    girokonto.anzeigen();
    sparkonto.anzeigen();
    cout << "-- 2000€ überweisen: "
         << girokonto.ueberweisen(tagesgeldkonto, 2000 * 100)
         << endl;
    girokonto.anzeigen();
    tagesgeldkonto.anzeigen();


    cout << "-- 2000€ umbuchen: "
         << tagesgeldkonto.umbuchen(2000 * 100)
         << endl;
    tagesgeldkonto.anzeigen();
    girokonto.anzeigen();


    Liste<Bankkonto> konten;
    konten.append(sparkonto);
    konten.append(girokonto);
    konten.append(tagesgeldkonto);

    cout << "*** Ausgabe mittels Liste ***" << endl;

    for (unsigned int i = 0; i < konten.size(); i++) {
        konten.elementAt(i).anzeigen();
    }

    return 0;
}
