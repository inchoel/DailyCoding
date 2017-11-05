#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
int comp(const void* d1, const void* d2)
{
  return (*((int*)d1) > *((int*)d2));
}
*/

int main()
{
  int n, k;
  cin >> n >> k;

  vector<int> data;
  int input;
  for (int i=0; i<n; i++) {
    cin >> input;
    data.push_back(input);
  }

  // sort (data.begin(), data.end());
  // qsort (&data[0], n, sizeof(int), comp);
  nth_element(data.begin(), data.begin()+k-1, data.end());
  cout << data[k-1] << endl;
  return 0;
}
