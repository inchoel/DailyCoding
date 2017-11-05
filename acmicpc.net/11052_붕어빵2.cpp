#include <iostream>
#include <array>
using namespace std;

int findMaxSumPrice(const int n, const array<int, 1001>& unitPrice, array<int, 1001>& sum) {
  if (n==1)
    return unitPrice[n];

  if (sum[n] > 0)
    return sum[n];

  for (int i=1; i<=n; i++) {
    sum[n] = max (sum[n], findMaxSumPrice(n-i, unitPrice, sum) + unitPrice[i]);
  }

  return sum[n];
}

int main() {
  int n;
  cin >> n;

  array<int, 1001> unitPrice;
  array<int, 1001> sumPrice;
  sumPrice.fill(0);
  for (int i=1; i<=n; i++) {
    cin >> unitPrice[i];
  }

  cout << findMaxSumPrice(n, unitPrice, sumPrice) << endl;
  return 0;
}
