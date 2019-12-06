#ifndef BIBLIOTHEK_H_
#define BIBLIOTHEK_H_

#include "buch.h"
#include "benutzer.h"
#include "eidpliste.h"


class Bibliothek {
public:
	enum Resultat {
        AUSLEIHE_OK,
        BUCH_AUSGELIEHEN,
        BUCH_NICHT_VORHANDEN,
        BENUTZER_NICHT_VORHANDEN
    };

	Bibliothek();
	~Bibliothek();
	void erfasse(std::string autor, std::string titel);
	void anmelden(std::string name);
	void listeBuecherAuf();
	void listeBenutzerAuf();
	Resultat ausleihe(unsigned int inventarnummer, unsigned int benutzernummer);
	bool rueckgabe(unsigned int inventarnummer);
    Benutzer* findeBenutzer(unsigned int benutzernummer);
    
private:
	Liste<Buch*> _buecher;
	Liste<Benutzer*> _benutzer;
	unsigned int _naechsteInventarnummer;
	unsigned int _naechsteBenutzernummer;
};

#endif /* BIBLIOTHEK_H_ */
