/*
 * Gibt Pokemon mit Namen und Typ aus
 */
#include <iostream>

using namespace std;

int main() {

  enum elektro {
    Pikachu,
    Magneton,
    Voltobal
  };
  enum feuer {
    Glumanda,
    Vulpix,
    Arkani
  };

  for (int i = 0; i < 6; i++) {
    if (i < 3) {
      switch (i) {
      case Pikachu:
        {
          cout << "Art Elektropokemon:" << endl;
          cout << "Pikachu";
          break;
        }
      case Magneton:
        {
          cout << "Magneton";
          break;
        }
      case Voltobal:
        {
          cout << "Voltobal";
          break;
        }
      }
    } else {
      switch (i - 3) {
      case Glumanda:
        {
          cout << endl << "Art Feuerpokemon:" << endl;
          cout << "Glumanda";
          break;
        }
      case Vulpix:
        {
          cout << "Vulpix";
          break;
        }
      case Arkani:
        {
          cout << "Arkani";
          break;
        }
      }
    }
		
    cout << endl;
  }

  return 0;
}
