#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  int n;
  cin >> n;

  vector<long long> numbers;
  long long num;
  for (int i=0; i<n; i++) {
    cin >> num;
    numbers.push_back(num);
  }

  sort (numbers.begin(), numbers.end());

  long long maxData = 0;
  long long data = numbers[0];
  int maxCount = 0;
  int count = 1;

  for (int i=1; i<n; i++) {
    if (data == numbers[i]) {
      count++;
    }
    else {
      if (maxCount < count) {
        maxCount = count;
        maxData = data;
      }
      else if (maxCount == count) {
        if (maxData > data)
          maxData = data;
      }

      data = numbers[i];
      count = 1;
    }
  }

  cout << maxData << endl;

  return 0;
}
