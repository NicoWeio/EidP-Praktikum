#include "buch.h"

// 1d)
int main() {
  Buch buch1 = Buch("Dr.-Ing. Horst Schirmeier", "Briefe an den Zukunfts-Horst", 42);
  buch1.print();
  buch1.verleiheAn(3141);
  buch1.print();
}
