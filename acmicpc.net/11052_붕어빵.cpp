#include <iostream>
#include <queue>
#include <map>
using namespace std;

int maxPrice = 0;

void findMaxPrice(const int n, map<int, int>& pTable, int& max)
{
  if (n == 0) {
    if (maxPrice < max)
      maxPrice = max;
    return;
  }

  for (int i=1; i<=pTable.size(); i++) {
    if (n-i < 0)
      break;

    max += pTable[i];
    findMaxPrice(n-i, pTable, max);
    max -= pTable[i];
  }
}

int main() {
  int n, p;
  cin >> n;

  map<int, int> priceTable;
  for (int i=0; i<n; i++) {
    cin >> p;
    priceTable[i+1] = p;
  }

  int sumPrice = 0;
  findMaxPrice(n, priceTable, sumPrice);

  cout << maxPrice << endl;

  return 0;
}
