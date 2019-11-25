#include <iostream>
using namespace std;

int ack(int n, int m) {
  if (n == 0) {
    return m + 1;
  } else if (m == 0) {
    return ack(n - 1, 1);
  } else {
    return ack(n - 1, ack(n, m - 1));
  }
}

int ack2(int n, int m) {
  while (n != 0) {
    if (m == 0) {
      m = 1;
    } else {
      m = ack2(n, m - 1);
    }
    n = n - 1;
  }
  return m + 1;
}

int main() {
  int n, m;
  cout << "n: ";
  cin >> n;
  cout << "m: ";
  cin >> m;

  cout << "ack: " << ack(n, m) << ", ack2: " << ack2(n, m) << endl;
}
