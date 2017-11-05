#include <iostream>
#include <array>
#include <algorithm>

using namespace std;

template<typename T, size_t size>
void show_array(array<T, size> const &arr, int valid_size) {
  int i;
  for (i=0; i<valid_size; i++)
    cout << arr[i] << endl;
}

int main(void)
{
  int n=0, input=0, output=0, temp=0;
  int i=0, j=0, k=0, max=0;

  cin >> n;
  array<int, 100> arr;
  arr.fill(0);
  while (i < n) {
    cin >> input;
    arr[i++] = input;
  }
  sort(arr.begin(), arr.begin()+n);
  // show_array<int, 100>(arr, n);

  max = arr[n-1];
  for (i=2; i<=max; i++) {
    temp = i;
    j = 2;
    while (temp <= max) {
      temp = i * j;
      for(k=0; k<n; k++) {
        if (arr[k] == 0)
          continue;
        if (temp == arr[k])
            arr[k] = 0;
      }
      j++;
    }
  }

  for (i=0; i<n; i++) {
    // cout << arr[i] << " ";
    if (arr[i] != 0 && arr[i] != 1)
      output++;
  }

  cout << output << endl;

  return 0;
}
