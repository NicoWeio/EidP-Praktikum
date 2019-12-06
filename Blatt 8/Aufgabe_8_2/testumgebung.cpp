#include "buch.h"
#include "benutzer.h"
#include "bibliothek.h"
#include "bibmanager.h"


int main() {
	Bibliothek bib;

	BibliotheksManager manager(&bib);
	manager.manage();

	return 0;
}
