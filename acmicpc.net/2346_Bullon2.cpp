#include <cstdio>
#include <deque>
using namespace std;

int main()
{
  int n, num, next;
  scanf("%d", &n);

  deque<pair<int, int> > deq;
  for (int i=1; i<=n; i++) {
    scanf("%d", &num);
    deq.push_back (make_pair(i, num));
  }

  // for (auto& e : deq)
  //   printf("%d, %d\n", e.first, e.second);

  printf("%d", deq.front().first);
  next = deq.front().second;
  deq.pop_front();

  while (!deq.empty()) {
    if (next > 0) {
      for (int j=1; j<=next; j++) {
        if (j != next) {
          deq.push_back(make_pair(deq.front().first, deq.front().second));
          deq.pop_front();
        }
        else {
          printf(" %d", deq.front().first);
          next = deq.front().second;
          deq.pop_front();
          break;
        }
      }
    }
    else {
      for (int k=next; k<=-1; k++) {
        if (k != -1) {
          deq.push_front(make_pair(deq.back().first, deq.back().second));
          deq.pop_back();
        }
        else {
          printf(" %d", deq.back().first);
          next = deq.back().second;
          deq.pop_back();
          break;
        }
      }
    }
  }
  printf("\n");

  return 0;
}
