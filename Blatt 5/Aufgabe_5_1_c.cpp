#include <iostream>
using namespace std;

void gibPrimfaktorenAus(int zahl, bool ist_prim[]) {
  int n = zahl;
  cout << zahl << ": ";
  if (ist_prim[n]) {
    cout << "prim" << endl;
    return;
  }

  bool didOutput = false;
  for (int p = 2; p <= n; p++) {
    if (!ist_prim[p])
      continue;

    if (n % p == 0) {
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

  for (int i = 2; i < MAX; i++) {
    if (ist_prim[i] == true) {
      // alle Vielfachen ausschließen
      int j = 2;
      while (i * j < MAX) {
        ist_prim[i * j] = false;
        j++;
      }
    }

    gibPrimfaktorenAus(i, ist_prim);
  }

  delete[] ist_prim;
}
