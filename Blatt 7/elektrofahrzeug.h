#ifndef ELEKTROFAHRZEUG_H
#define ELEKTROFAHRZEUG_H

class Elektrofahrzeug {
private:
  float maxEnergie;
  float avgVerbrauch;
  float ladung;
  float kilometerstand;
  unsigned int maxGeschwindigkeit;

  static float verbrauchFuerStrecke(float strecke, float verbrauch);

public:
  Elektrofahrzeug();
  void ausgabe();

  float getMaxEnergie();
  float getAvgVerbrauch();
  float getLadung();
  float getKilometerstand();
  unsigned int getMaxGeschwindigkeit();

  void setAvgVerbrauch(float input);
  void setMaxGeschwindigkeit(int input);

  void setLadung(float input);
  void setMaxEnergie(float input);

  void setKilometerstand(float input);

  Elektrofahrzeug(float a, float b, float c, float d, unsigned int e);

  int prozent();

  float aufladen();

  float maximaleReichweite();

  bool fahren(float strecke);
};

#endif
