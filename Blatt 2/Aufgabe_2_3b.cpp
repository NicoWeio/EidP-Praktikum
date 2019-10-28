/*
 * Gibt Pokemon mit Namen und Typ aus
 */
#include <iostream>

using namespace std;

int main() {

  for (int i = 0; i < 6; i++) {
    switch (i) {
    case 0:
      {
        cout << "Art Elektropokemon:" << endl;
        cout << "Pikachu";
        break;
      }
    case 1:
      {
        cout << "Magneton";
        break;
      }
    case 2:
      {
        cout << "Voltobal";
        break;
      }
    case 3:
      {
        cout << endl << "Art Feuerpokemon:" << endl;
        cout << "Glumanda";
        break;
      }
    case 4:
      {
        cout << "Vulpix";
        break;
      }
    case 5:
      {
        cout << "Arkani";
        break;
      }
    }

    cout << endl;
  }

  return 0;
}
