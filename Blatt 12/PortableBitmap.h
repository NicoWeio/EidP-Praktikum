#ifndef PORTABLEBITMAP_H
#define PORTABLEBITMAP_H

#include <vector>
#include <string>

using namespace std;

class PortableBitmap {
private:
    unsigned int hoehe;
    unsigned int breite;
    vector<bool> pixel;
public:
    PortableBitmap(unsigned int hoehe, unsigned int breite);

    // Ein Destruktor wird wegen der Nutzung von std::vector nicht benötigt.
    bool getPixel(unsigned int x, unsigned int y) const;

    void setPixel(bool wert, unsigned int x, unsigned int y);

    void save(string const &dateiName);
};

bool endswith(const string &txt, const string &suffix);

PortableBitmap load(const char *dateiName);


#endif //PORTABLEBITMAP_H
