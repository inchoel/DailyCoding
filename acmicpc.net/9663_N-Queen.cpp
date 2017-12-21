#include <cstdio>
#include <array>
using namespace std;

int N;
int ans;

void put_queen(int n, int pos, array<array<bool, 15>, 15> isVisited) {
  if (n==N) {
    ans++;
    return;
  }

  int left_diagonal = pos-1;
  int right_diagonal = pos+1;
  for (int row=n+1; row<=N; row++) {
    if (left_diagonal>=1)
      isVisited[row][left_diagonal--] = true;

    isVisited[row][pos] = true;

    if (pos && right_diagonal<=N)
      isVisited[row][right_diagonal++] = true;
  }

  for (int i=1; i<=N; i++) {
    if (isVisited[n+1][i]==false)
      put_queen(n+1, i, isVisited);
  }
}


int main() {
  scanf (" %d", &N);

  put_queen(0, 0, array<array<bool, 15>, 15>());
  printf("%d\n", ans);
  return 0;
}
