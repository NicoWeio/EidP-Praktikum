#include <iostream>
using namespace std;

void ausgeben(int &x, int &y, int &z, int* a, int* b,  int* c) {
	cout << "\t\tAdresse\t\tInhalt\t\treferenzierter Wert" << endl;

	cout << "Variable x \t" << &x << "\t" << x << endl;
	cout << "Variable y \t" << &y << "\t" << y << endl;
	cout << "Variable z \t" << &z << "\t" << z << endl;

	cout << "Zeiger a \t" << &a << "\t" << a << "\t" << *a << endl;
	cout << "Zeiger b \t" << &b << "\t" << b << "\t" << *b << endl;
	cout << "Zeiger c \t" << &c << "\t" << c << "\t" << *c << endl;
}

int main()
{
	int x = 42, y = -13, z = 23;
	int *a=&x, *b=&y, *c=&z;

	ausgeben(x, y, z, a, b, c);

	// Teilaufgabe c)
	a = &y;
	b = &x;

	cout << endl << endl << "--- Ausgabe nach Teilaufgabe c) ---" << endl;
	ausgeben(x, y, z, a, b, c);

	// Teilaufgabe e)
	*c+=8;

	cout << endl << endl << "--- Ausgabe nach Teilaufgabe e) ---" << endl;
	ausgeben(x, y, z, a, b, c);

}
