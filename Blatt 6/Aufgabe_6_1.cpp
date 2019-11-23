#include <cmath>
#include <iostream>
using namespace std;

long long rekEidp(unsigned int n, unsigned int &count) {
  if (n > 2) {
    count++;
    return rekEidp(n - 1, count) + 3 * rekEidp(n - 2, count);
  } else {
    return 1;
  }
}

long long itEidp(unsigned int n, unsigned int &count) {
  int i = 2;
  int k = 1, l = 1;
  int m = 1; // Ausgabewert, falls n <= 2
  while (i < n) {
    m = l + 3 * k;
    count++;

    k = l;
    l = m;

    i++;
  }
  return m;
}

long long moivreBinetEidP(unsigned int n) {
  return (pow((1 + sqrt(13)) / 2, n) - pow((1 - sqrt(13)) / 2, n)) / sqrt(13);
}

int main(int argc, char *argv[]) {
  int n = 0;
  cout << "n: ";
  cin >> n;

  unsigned int count = 0;
  cout << "rekEidp: " << rekEidp(n, count) << " (" << count << " Additionen)"
       << endl;
  count = 0;
  cout << "itEidp: " << itEidp(n, count) << " (" << count << " Additionen)"
       << endl;
  cout << "moivreBinetEidP: " << moivreBinetEidP(n) << endl;
}
