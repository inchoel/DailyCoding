#include <iostream>
#include <list>
#include <iterator>
#include <algorithm>
using namespace std;

int main() {
  list<int> s = {1,2,3,4,5};

  int M = 7;
  auto cur = s.begin();
  cur = next(cur, 1);
  cout << *cur << endl;

  auto dist = distance (cur, s.end());
  cur = s.begin();
  int move = M - (dist) - 1;

  advance (cur, move);
  cout << *cur << endl;

  return 0;
}
