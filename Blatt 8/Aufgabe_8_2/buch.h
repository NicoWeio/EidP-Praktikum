#ifndef BUCH_H
#define BUCH_H

#include <string>
using namespace std;

// 1a)
class Buch {
private:
  string _autor;
  string _titel;
  unsigned int _inventarnummer;
  unsigned int _benutzernummer;

public:
  // 1b)
  Buch(string autor, string titel, unsigned int inventarnummer);

  // 1c)
  bool istVerliehen();
  unsigned int inventarNummer();
  unsigned int ausgeliehenVon();
  bool verleiheAn(unsigned int benutzernummer);
  void rueckgabe();
  void print();
};

#endif
