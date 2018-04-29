#include <iostream>
#include <iterator>
#include <algorithm>
using namespace std;

template<class InputIt, class OutputIt, class UnaryPredicate>
void xcopy_if (InputIt in_start, InputIt in_end, OutputIt out_start, UnaryPredicate f)
{
  while (in_start != in_end) {
    if ( f(*in_start) ) {
      *out_start = *in_start;
      ++out_start;
    }

    ++in_start;
  }
}

int main()
{
  int x[12] = { 1,2,3,4,5,6,7,8,9,10 };
  int y[10] = { 0 };

  xcopy_if(x, x+10, y, [](int a){ return a%2 == 0; });

  for (auto n : y)
    cout << n << endl;
}
