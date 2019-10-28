//Dieses Programm berechnet den elektrischen Widerstand
#include <iostream>
using namespace std;
int main() {
	double spannung = 230.0;
	double strom = 5.0;
	double widerstand = spannung / strom;
	cout << "Berechneter Widerstand: ";
	cout << widerstand << endl;
	return 0; // fertig
}
