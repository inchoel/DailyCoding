#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace std;

int main(void)
{
  int start, end, size;
  cin >> start >> end;
  size = end - start + 1;

  int num[size];
  int temp, k, i, j = start;
  for(i=0; i<size; i++) {
    num[i] = j;
    j++;
    // cout << num[i] << endl;
  }

  for(i=2; i<end; i++) {
    j = 2;
    for(j=2; j<end; j++) {
      temp = i * j;
      if (temp < start)
        continue;
      if (temp > end)
        break;

      for(k=0; k<size; k++) {
        if (num[k] > temp)
          break;
        if (num[k] && num[k] == temp) {
          num[k] = 0;
        }
      }
    }
  }

  for(i=0; i<size; i++) {
    if (num[i]==0 || num[i]==1)
      continue;
    cout << num[i] << endl;
  }

  return 0;
}
