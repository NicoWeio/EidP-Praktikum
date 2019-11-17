#include <iostream>
using namespace std;

int umwandlung(char c) {
  if (c == 'x')
    return 10;
  else
    return c - '0';
}

bool isbn10check(char isbn[]) {
  int sum = 0;
  for (int i = 0; i < 9; i++) {
    sum += ((i + 1) * umwandlung(isbn[i]));
  }
  int checksum = sum % 11;
  return umwandlung(isbn[9]) == checksum;
}

int main() {
  char isbn1[] = "349913599x";
  char isbn2[] = "2871499367";

  cout << "ISBN " << isbn1
       << (isbn10check(isbn1) ? " ist gültig :)" : " ist nicht gültig :(")
       << endl;

  cout << "ISBN " << isbn2
       << (isbn10check(isbn2) ? " ist gültig :)" : " ist nicht gültig :(")
       << endl;
}
