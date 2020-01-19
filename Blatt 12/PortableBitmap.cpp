#include "PortableBitmap.h"
#include <stdexcept>
#include <fstream>

PortableBitmap::PortableBitmap(unsigned int hoehe, unsigned int breite) : hoehe(hoehe), breite(breite) {
    for (unsigned int i = 0; i < hoehe * breite; i++) {
        pixel.push_back(false);
    }
}

bool PortableBitmap::getPixel(unsigned int x, unsigned int y) const {
    return pixel[y * breite + x];
}

void PortableBitmap::setPixel(bool wert, unsigned int x, unsigned int y) {
    pixel[y * breite + x] = wert;
}

bool endswith(const string &txt, const string &suffix) {
    if (suffix.length() > txt.length()) return false;
    return txt.substr(txt.length() - suffix.length(), suffix.length()) == suffix;
}

void PortableBitmap::save(string const &dateiName) {
    if (!endswith(dateiName, ".pbm")) throw std::invalid_argument("Dateiname endet nicht auf \".pbm\"");
    ofstream file(dateiName);
    if (!file.is_open())
        throw std::ios_base::failure("Fehler beim Öffnen der Datei");
    file << "P1" << endl
         << "# EidP Productions 2019/20" << endl
         << breite << " " << hoehe << endl;
    for (unsigned int y = 0; y < hoehe; y++) {
        for (unsigned int x = 0; x < breite; x++) {
            file << getPixel(x, y) << " ";
        }
        file << endl;
    }
}

PortableBitmap load(const char *dateiName) {
    if (!endswith(dateiName, ".pbm")) throw std::invalid_argument("Dateiname endet nicht auf \".pbm\"");
    ifstream file(dateiName);
    if (!file.is_open())
        throw std::ios_base::failure("Fehler beim Öffnen der Datei");


    string line;
    getline(file, line); // P1

    getline(file, line); // Kommentar oder Größenangabe
    if (line[0] == '#') getline(file, line); // falls Kommentar, Zeile überspringen

    unsigned int spalten = atoi(line.substr(0, line.find(' ')).c_str());
    line.erase(0, line.find(' ') + 1);
    unsigned int zeilen = atoi(line.c_str());

    PortableBitmap bitmap(zeilen, spalten);

    unsigned int i = 0;
    while (std::getline(file, line)) {
        unsigned int j = 0;
        for (char &c : line) {
            if (c == ' ') continue;
            bitmap.setPixel(c != '0', j, i);
            j++;
        }
        i++;
    }


    return bitmap;
}
