#include <cstdio>
#include <map>
#include <vector>
using namespace std;

int main()
{
  map<int, int> m;
  vector<int> result;

  int n, num;
  scanf("%d", &n);
  for (int i=1; i<=n; i++) {
    scanf("%d", &num);
    m[i] = num;
  }

  auto index = m.find(1);
  auto last = m.find(n);
  int k = 1;
  int move;
  int size;
  while (k <= n) {
    printf("%d", index->first);
    if (k < n) { printf(" "); }
    else       { printf("\n"); break; }

    move = index->second;
    size = (int) m.size();
    last = --(m.end());
    m.erase(index);

    if (move < 0)
      move = size - (abs(move) % size);

    for (int h=0; h<move; h++) {
      if (index->first == last->first) {
        index = --(m.end());
      }

      index++;
      if (index == m.end()) {
        index = m.begin();
      }
    }

    k++;
  }
  return 0;
}
