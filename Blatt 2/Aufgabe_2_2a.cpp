/*
 * gerade.cpp
 * Das Programm berechnt die Geradenparameter~$m, b$ fuer die Geradengleichung
 * f(x) = mx + b
 * Als Eingabe dienen die Punkte (x1, y1), (x2, y2)
 */

#include <iostream>
using namespace std;

int main()
{
	double x1, y1, x2, y2, m, b;
	bool s;

	cout << "x1: ";
	cin >> x1;
	cout << "y1: ";
	cin >> y1;
	cout << "x2: ";
	cin >> x2;
	cout << "y2: ";
	cin >> y2;

	m = (y1 - y2) / (x1 - x2);

	//    y = mx + b
	//(=) y - mx = b

	b = y1 - m * x1;

	cout << "Die Gerade hat folgende Gleichung: f(x) = " << m << " * x + " << b << endl;

	return 0;
}
