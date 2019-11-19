#include <iostream>
using namespace std;

void gibPrimfaktorenAus(int zahl, int anzahl_primzahlen, int primzahlen[]) {
  int n = zahl;
  cout << zahl << ": ";

  if (primzahlen[anzahl_primzahlen - 1] == zahl) {
    cout << "prim" << endl;
    return;
  }

  bool didOutput = false;
  for (int primIndex = 0; primIndex < anzahl_primzahlen; primIndex++) {
    int p = primzahlen[primIndex];

    if (p == zahl) {
      cout << "prim";
      break;
    }

    while (n % p == 0) {
      if (didOutput)
        cout << ", ";
      cout << p;
      didOutput = true;

      n = n / p;
    }
  }

  cout << endl;
}

const int MAX = 1000;

int main() {
  // ist_prim initialisieren: die ersten beiden Werte false, alle anderen true
  bool *ist_prim = new bool[MAX];
  for (int k = 2; k < MAX; k++) {
    ist_prim[k] = true;
  }
  ist_prim[0] = false;
  ist_prim[1] = false;

  int *primzahlen = new int[MAX];
  int anzahl_primzahlen = 0;

  for (int i = 2; i < MAX; i++) {
    if (ist_prim[i] == true) {
      // alle Vielfachen ausschließen
      int j = 2;
      while (i * j < MAX) {
        ist_prim[i * j] = false;
        j++;
      }
      primzahlen[anzahl_primzahlen] = i;
      anzahl_primzahlen++;
    }

    gibPrimfaktorenAus(i, anzahl_primzahlen, primzahlen);
  }

  delete[] ist_prim;
  delete[] primzahlen;
}
