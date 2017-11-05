#if 0
#include <cstdio>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

int reArrange (const vector<int>& v, const int i, deque<int>& deq) {
  printf("i=%d, v=%d, deque begin=%d, end=%d\n", i, v[i], *(deq.begin()), *(--deq.end()));
  int sum_front = abs(v[i] - (*(deq.begin())));
  int sum_end = abs((*(--deq.end())) - v[i]);
  if (sum_front > sum_end)
    deq.push_front (v[i]);
  else
    deq.push_back (v[i]);

  return max(sum_front, sum_end);
}

int main() {
  int n;
  scanf (" %d", &n);

  vector<int> v(n, 0);
  for (int i=0; i<n; i++)
    scanf (" %d", &v[i]);

  sort (v.begin(), v.end());

  deque<int> d;
  d.push_back(v[0]);
  d.push_back(v[n-1]);
  int max = abs (v[0] - v[n-1]);
  int i;
  for (i=1; i<n/2; i++) {
    max += reArrange (v, i, d);
    max += reArrange (v, n-1-i, d);
  }

  if (n%2) {
    max += reArrange (v, i, d);
  }

  for (auto& e : d)
    printf("%d ", e);
  printf("\n");

  printf("%d\n", max);
  return 0;
}
#else
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  int n;
  scanf (" %d", &n);

  vector<int> v(n);
  for (int i=0; i<n; i++)
    scanf (" %d", &v[i]);

  sort (v.begin(), v.end());

  int max = 0;
  int temp;
  do {
    temp = 0;
    for (int i=1; i<n; i++)
     temp += abs (v[i-1] - v[i]);

    if (max < temp)
      max = temp;

    // for (auto& e : v)
    //   printf("%d ", e);
    // printf("\n");
  } while (next_permutation(v.begin(), v.end()));

  printf("%d\n", max);
  return 0;
}



#endif
