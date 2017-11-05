#include <cstdio>
#include <cmath>
#include <iostream>
#include <string>
using namespace std;

void modConvert (const int mod, string&& num)
{
  int sum = 0;
  int exponent = num.size() - 1;
  if (mod == 16) {
    for (auto c : num) {
      if (c >= 'a')
        sum += (10 + (c-'a')) * (int)(pow (mod, exponent));
      else
        sum += (c - '0') * (int)(pow (mod, exponent));

      exponent--;
    }
  }
  else if (mod == 8) {
    for (auto c : num) {
      sum += (c - '0') * (int)(pow (mod, exponent));
      exponent--;
    }
  }
  else {
    sum = stoi(num);
  }

  printf("%d\n", sum);
}

int main()
{
  int num_index = 0;
  int mod = 10;
  string x;
  cin >> x;

  if (x[0] == '0') {
    if (x[1] == 'x') {
      mod = 16;
      num_index = 2;
    }
    else {
      mod = 8;
      num_index = 1;
    }
  }
  else {
    num_index = 0;
  }

  modConvert(mod, &x[num_index]);

  return 0;
}
