#include <cstdio>
using namespace std;

bool ans[201];
bool isVisited[201][201];

void dfs (int a, int b, int c) {
  if (a == 0)
    ans[c] = true;

  isVisited[a][b] = true;
  // a->b
  if ()
  // a->c
  // b->a
  // b->c
  // c->a
  // c->b
}

int main() {
  int aa, bb, cc;
  scanf (" %d %d %d", &aa, &bb, &cc);

  dfs (0, 0, cc);

  for (int i=0; i<201; i++) {
  if (ans[i])
  printf("%d ", i);
  }
  printf("\n");
  return 0;
}
