#ifndef BIBMANAGER_H_
#define BIBMANAGER_H_

#include "bibliothek.h"


class BibliotheksManager {
public:
	BibliotheksManager(Bibliothek* bib);
	void manage();
private:
	Bibliothek* _bib;
};

#endif /* BIBMANAGER_H_ */
