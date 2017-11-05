#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

int main() {
  int n, num;
  cin >> n;
  vector<pair<int, bool> > numbers;

  for (int i=0; i<n; i++) {
    cin >> num;
    numbers.push_back(make_pair(num, false));
  }

  int maxCount = 0;
  int maxData = 0;
  for (int i=0; i<n; i++) {
    int data = numbers[i].first;
    int count = 0;
    for (int j=0; j<n; j++) {
      if (data == numbers[j].first && numbers[j].second == false) {
        numbers[j].second = true;
        count++;
      }
    }

    if (maxCount < count) {
      maxData = data;
      maxCount = count;
    }
    else if (maxCount == count) {
      if (maxData > data)
        maxData = data;
    }
  }

  cout << maxData << endl;
  return 0;
}
