#include <iostream>
#include <map>
using namespace std;

int main() {
  int n;
  cin >> n;

  map<long long, int> number_frequency;
  long long num;
  for (int i=0; i<n; i++) {
    cin >> num;
    number_frequency[num]++;
  }

  long long maxNumber = 0;
  int max = 0;
  for (auto n : number_frequency) {
    if (n.second > max) {
      max = n.second;
      maxNumber = n.first;
    }
    else if (n.second == max) {
      if (n.first < maxNumber)
        maxNumber = n.first;
    }
  }

  cout << maxNumber << endl;
  return 0;
}
