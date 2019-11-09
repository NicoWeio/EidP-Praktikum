#include <iostream>
using namespace std; //im ORIGINAL fehlt diese Zeile !?

int position(char c) {
  return (c - 'A' > 25) ? (c - 'a') : (c - 'A');
}

void zaehleHoch(char const buchstabe, int anzahlen[]) {
  anzahlen[position(buchstabe)]++;
}

void zaehleRunter(char const buchstabe, int anzahlen[]) {
  anzahlen[position(buchstabe)]--;
}

void zaehleAlleHoch(char const wort[], int laenge, int anzahlen[]) {
  for (int i = 0; i < laenge; i++) {
    zaehleHoch(wort[i], anzahlen);
  }
}

void zaehleAlleRunter(char const wort[], int laenge, int anzahlen[]) {
  for (int i = 0; i < laenge; i++) {
    zaehleRunter(wort[i], anzahlen);
  }
}

bool sindAlleNull(int anzahlen[], int laenge) {
  for (int i = 0; i < laenge; i++) {
    if (anzahlen[i] != 0) return false;
  }
  return true;
}

int main() {
    char const wort1[] = "ThomasMueller";
    int laenge1 = sizeof(wort1) / sizeof(char) - 1; //ORIGINAL: char int !?
    char const wort2[] = "LuemmelSahRot";
    int laenge2 = sizeof(wort2) / sizeof(char) - 1; //ORIGINAL: char int !?

    if (laenge1 != laenge2) {
        std::cout << "Die Woerter \"" << wort1 << "\" und \"" << wort2 << "\" sind unterschiedlich lang.\n";
        return 1;
    }

    static int const alphabet_groesse = 'z' - 'a' + 1;
    int anzahlen[alphabet_groesse] = {0};

    zaehleAlleHoch(wort1, laenge1, anzahlen);
    zaehleAlleRunter(wort2, laenge2, anzahlen);

    bool const istAnagramm = sindAlleNull(anzahlen, alphabet_groesse);
    if (istAnagramm) {
        cout << '\"' << wort1
             << "\" ist ein Anagramm von \""
             << wort2 << "\".\n";
        return 0;
    } else {
        cout << '\"' << wort1
             << "\" ist leider kein Anagramm von \""
             << wort2 << "\". :-((((((((((\n";
        return 1;
    }
}
