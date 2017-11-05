#include <iostream>
#include <string>
using namespace std;

int main()
{
  string a, b, c, d;
  cin >> a >> b >> c >> d;

  string left = a + b;
  string right = c + d;

  cout << stol(left) + stol(right) << endl;

  return 0;
}
