#include "elektrofahrzeug.h"
#include <iostream>
using namespace std;

void Elektrofahrzeug::ausgabe() {
  cout << "Maximale Energie: " << maxEnergie << " kWh" << endl;
  cout << "Durchschnittsverbrauch: " << avgVerbrauch << " kWh/100km" << endl;
  cout << "Ladung: " << ladung << " kWh" << endl;
  cout << "Kilometerstand: " << kilometerstand << " km" << endl;
  cout << "Höchstgeschwindigkeit: " << maxGeschwindigkeit << " km/h" << endl;
}

float Elektrofahrzeug::getMaxEnergie() { return maxEnergie; }
float Elektrofahrzeug::getAvgVerbrauch() { return avgVerbrauch; }
float Elektrofahrzeug::getLadung() { return ladung; }
float Elektrofahrzeug::getKilometerstand() { return kilometerstand; }
unsigned int Elektrofahrzeug::getMaxGeschwindigkeit() {
  return maxGeschwindigkeit;
}

void Elektrofahrzeug::setAvgVerbrauch(float input) {
  if (input > 0) {
    avgVerbrauch = input;
  } else {
    cerr << "Durchschnittsverbrauch muss größer als 0 sein!" << endl;
    avgVerbrauch = 12.5;
  }
}
void Elektrofahrzeug::setMaxGeschwindigkeit(int input) {
  // wir nehmen ein signed int entgegen, um ungültige Eingaben abzufangen
  if (input > 0) {
    maxGeschwindigkeit = input;
  } else {
    cerr << "Höchstgeschwindigkeit muss größer als 0 sein!" << endl;
    maxGeschwindigkeit = 160;
  }
}

void Elektrofahrzeug::setLadung(float input) {
  if (0 <= input) {
    if (input <= maxEnergie) {
      ladung = input;
    } else {
      cerr << "Ladung muss kleiner/gleich der maximalen Energie sein!" << endl;
      ladung = maxEnergie;
    }
  } else {
    cerr << "Ladung muss größer/gleich 0 sein!" << endl;
    ladung = 50;
  }
}
void Elektrofahrzeug::setMaxEnergie(float input) {
  if (0 < input) {
    if (input >= ladung) {
      maxEnergie = input;
    } else {
      cerr << "Maximale Energie muss größer/gleich der Ladung sein!" << endl;
      ladung = maxEnergie;
    }
  } else {
    cerr << "Maximale Energie muss größer als 0 sein!" << endl;
    maxEnergie = 80;
  }
}

Elektrofahrzeug::Elektrofahrzeug(float a, float b, float c, float d,
                                 unsigned int e) {
  // einmal blind initialisieren, damit die Setter nicht meckern…
  maxEnergie = a;
  ladung = c;

  setMaxEnergie(a);
  setLadung(c);

  setAvgVerbrauch(b);
  kilometerstand = d;
  setMaxGeschwindigkeit(e);
}

int Elektrofahrzeug::prozent() { return (ladung * 100) / maxEnergie; }

float Elektrofahrzeug::aufladen() {
  int menge = maxEnergie - ladung;
  ladung = maxEnergie;
  return menge;
}

float Elektrofahrzeug::maximaleReichweite() {
  return (ladung / avgVerbrauch) * 100;
}

float Elektrofahrzeug::verbrauchFuerStrecke(float strecke, float verbrauch) {
  return (strecke * verbrauch) / 100;
}

bool Elektrofahrzeug::fahren(float strecke) {
  if (strecke <= maximaleReichweite()) {
    ladung -= verbrauchFuerStrecke(strecke, avgVerbrauch);
    kilometerstand += strecke;
    return true;
  } else {
    return false;
  }
}
