#ifndef BENUTZER_H
#define BENUTZER_H

#include <string>

using namespace std;


class Benutzer {
private:
    string _name;
    unsigned int _benutzernummer;
    
public:
    Benutzer(string name, unsigned int benutzernummer);
    
    unsigned int benutzerNummer();
    void print();
};

#endif /* BENUTZER_H */
