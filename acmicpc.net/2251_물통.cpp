#include <cstdio>
using namespace std;

int aa, bb, cc;
bool ans[201];
bool isVisited[201][201] = {false, };

void dfs (int a, int b, int c) {
  if (isVisited[a][b])
    return;

  if (a == 0)
    ans[c] = true;

  isVisited[a][b] = true;

  // a->b
  if (a+b > bb)
    dfs (a-(bb-b), bb, c);
  else
    dfs (0, a+b, c);
  // a->c
  if (a+c > cc)
    dfs (a-(cc-c), b, cc);
  else
    dfs (0, b, a+c);
  // b->a
  if (b+a > aa)
    dfs (aa, b-(aa-a), c);
  else
    dfs (b+a, 0, c);
  // b->c
  if (b+c > cc)
    dfs (a, b-(cc-c), cc);
  else
    dfs (a, 0, b+c);
  // c->a
  if (c+a > aa)
    dfs (aa, b, c-(aa-a));
  else
    dfs (c+a, b, 0);
  // c->b
  if (c+b > bb)
    dfs (a, bb, c-(bb-b));
  else
    dfs (a, c+b, 0);
}

int main() {
  scanf (" %d %d %d", &aa, &bb, &cc);

  dfs (0, 0, cc);

  for (int i=1; i<201; i++) {
    if (ans[i])
      printf("%d ", i);
  }
  printf("\n");
  return 0;
}
