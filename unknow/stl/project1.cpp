#include <iostream>
#include <iterator>
#include <algorithm>
using namespace std;

xcopy_if ()

int main()
{
  int x[10] = { 1,2,3,4,5,6,7,8,9,10 };
  int y[10] = { 0 };

  xcopy_if(x, x+10, y+5, [](int a){ return a%2 == 0; });

  for (auto n : y)
    cout << n << endl;
}
