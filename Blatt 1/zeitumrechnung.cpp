#include <iostream>
using namespace std;

int main()
{
	int eingabe = 172169; // Eingabe in Sekunden
	int sekunden = 0;
	int minuten = 0;
	int stunden = 0;
	int tage = 0;

	cout << eingabe << " Sekunden entsprechen :" << endl;

	tage = eingabe / 86400;
	eingabe = eingabe - tage * 86400;
	stunden = eingabe / 3600;
	eingabe = eingabe - stunden * 3600;
	minuten = eingabe / 60;
	eingabe = eingabe - minuten * 60;
	sekunden = eingabe;

	cout
		<< tage << " Tagen , "
		<< stunden << " Stunden , "
		<< minuten << " Minuten und "
		<< sekunden << " Sekunden .\n";
	return 0;
}
