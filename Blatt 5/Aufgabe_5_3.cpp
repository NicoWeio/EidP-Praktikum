#include <cmath> //nicht explizit erlaubt
#include <iostream>
using namespace std;

bool isSumeQuadratzahlen(int n, int *a, int *b) {
  int aMax = sqrt((float)n / 2);
  *a = 1;
  while (*a <= aMax) {
    *b = round(sqrt(n - pow(*a, 2)));
    if (n == pow(*a, 2) + pow(*b, 2)) {
      return true;
    }
    (*a)++;
  }
  return false;
}

int main() {
  for (int i = 1; i <= 50; i++) {
    int a, b;
    if (isSumeQuadratzahlen(i, &a, &b))
      cout << i << " = " << a << "²+" << b << "²" << endl;
  }
}
