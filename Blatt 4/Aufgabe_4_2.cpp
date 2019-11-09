#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

double wurzel(double a, int & iter) {
  double x = (a + 1) / 2;
  int i = 0;
  while (i < 100) {
    double xNext = (x + (a / x)) / 2;
    if (x == xNext) {
      break;
    }
    else {
      x = xNext;
      i++;
    }
  }
  iter = i + 1;
  return x;
}

int main() {
  int a = 0;
  cout << "a: ";
  cin >> a;

  int iter;
  double wurzelErgebnis = wurzel(a, iter);
  cout << "→ wurzel(a) terminierte nach " << iter << " Iteration(en)" << endl;

  cout << setprecision(17);
  cout << "Mit wurzel(a): \t√a=" << wurzelErgebnis << endl;
  cout << "Mit sqrt(a): \t√a=" << sqrt(a) << endl;
  cout << "sqrt(a) - wurzel(a): " << sqrt(a) - wurzelErgebnis << endl;
}
