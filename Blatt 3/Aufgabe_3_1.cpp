#include <iostream>
using namespace std;
int main()
{
  double euro, pound, usd, cny;

  cout << "€: ";
  cin >> euro;

  std::cout.setf(std::ios::fixed, std::ios::floatfield);
  std::cout.precision(2);

  pound = euro / 0.86;
  usd = euro * 1.11;
  cny = euro * 7.84;

  cout << endl;
  cout << pound << " Pfund" << endl;
  cout << usd << " US-Dollar" << endl;
  cout << cny << " Chinesische Renminbi" << endl;
}
