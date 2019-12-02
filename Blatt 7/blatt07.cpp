#include "elektrofahrzeug.h"
#include <iostream>
using namespace std;

void alleAusgeben(Elektrofahrzeug fahrzeuge[]) {
  for (int i = 0; i < 3; i++) {
    cout << "-- Fahrzeug " << i + 1 << ": " << endl;
    fahrzeuge[i].ausgabe();
  }
}

int main() {
  cout << "--- START Test für Teilaufgabe d)" << endl;
  Elektrofahrzeug fahrzeug1 = Elektrofahrzeug();
  fahrzeug1.ausgabe();
  cout << "--- ENDE Test für Teilaufgabe d)" << endl << endl;

  cout << "--- START Test für Teilaufgabe h)" << endl;
  fahrzeug1.setAvgVerbrauch(-1);
  fahrzeug1.setAvgVerbrauch(10);

  fahrzeug1.setMaxGeschwindigkeit(-1);
  fahrzeug1.setMaxGeschwindigkeit(100);

  fahrzeug1.setLadung(-1);
  fahrzeug1.setLadung(50);

  fahrzeug1.setMaxEnergie(-1);
  fahrzeug1.setMaxEnergie(50);

  fahrzeug1.setLadung(60);

  cout << "--- ENDE Test für Teilaufgabe h)" << endl << endl;

  Elektrofahrzeug fahrzeuge[] = {Elektrofahrzeug(),
                                 Elektrofahrzeug(100, 20, 30, 15000, 300),
                                 Elektrofahrzeug(10, 5, 9, 200, 30)};

  alleAusgeben(fahrzeuge);

  cout << endl
       << "+++ 1. Geben Sie für die Fahrzeuge die prozentuale Ladung aus."
       << endl;
  for (int i = 0; i < 3; i++) {
    cout << fahrzeuge[i].prozent() << "% geladen" << endl;
  }

  cout << endl
       << "+++ 2. Geben Sie für die Fahrzeuge die maximale Reichweite aus."
       << endl;
  for (int i = 0; i < 3; i++) {
    cout << fahrzeuge[i].maximaleReichweite() << "km Reichweite" << endl;
  }

  cout << endl << "+++ 3. Lassen Sie alle Fahrzeuge 180 km fahren." << endl;
  for (int i = 0; i < 3; i++) {
    fahrzeuge[i].fahren(180);
  }
  alleAusgeben(fahrzeuge);

  cout << endl << "+++ 4. Laden Sie die Fahrzeuge voll auf." << endl;
  for (int i = 0; i < 3; i++) {
    fahrzeuge[i].aufladen();
  }
  alleAusgeben(fahrzeuge);
}
