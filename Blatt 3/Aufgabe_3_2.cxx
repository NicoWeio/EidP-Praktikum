#include <iostream>
using namespace std;

int main() {
  unsigned int a, b, c;

  cout << "a: ";
  cin >> a;
  cout << "b: ";
  cin >> b;
  cout << "c: ";
  cin >> c;

  if (!(a > 0 && b > 0 && c > 0)) {
    cout << "Nicht alle Variablen sind positiv" << endl;
    return 1;
  }

  if (a > c) {
    unsigned int m = a;
    a = c;
    c = m;
  }
  if (b > c) {
    unsigned int m = b;
    b = c;
    c = m;
  }

  bool isRechtwinklig = (a * a + b * b == c * c);

  cout << "Das Dreieck mit den Seitenlaengen " << a << ", " << b << ", " << c << " ist " << (isRechtwinklig ? "" : "nicht ") << "rechtwinklig" << endl;
}
