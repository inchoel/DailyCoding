#include <cstdio>
#include <algorithm>
#include <utility>
#include <string>
#include <vector>
using namespace std;

#define DIV (1000000000)

int N;
const char num[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};

int main(void) {
  scanf (" %d", &N);

  vector<string> v;
  for (int i=0; i<9; i++)
    v.push_back(string(1, num[i]));

  printf("%ld\n", (v.size())%DIV);
  return 0;
}
