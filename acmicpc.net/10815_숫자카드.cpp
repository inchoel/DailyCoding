#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
  int n, m;

  scanf (" %d", &n);
  vector<int> cards(n);
  for (int i=0; i<n; i++) {
    scanf (" %d", &cards[i]);
  }

  sort (cards.begin(), cards.end());  // to use binary_search

  scanf (" %d", &m);
  vector<int> results(m, 0);
  int num;
  for (int i=0; i<m; i++) {
    scanf (" %d", &num);
    if (binary_search(cards.begin(), cards.end(), num))
      results[i] = 1;
  }

  for (auto& e : results)
    printf("%d ", e);
  printf("\n");

  return 0;
}
