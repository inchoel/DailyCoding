#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
int c[50][50];
int min_dist = numeric_limits<int>::max();

int get_distance(const vector<pair<int, int>>& stores) {
  int s_x = 0;
  int s_y = 0;

  for (int i=0; i<N; i++) {
    for (int  j=0; j<N; j++) {
      if (c[i][j] == 1) {
        // 가정집에서 치킨집들과의 거리비교하여 작은 것을 취한다.
        // 이후에 이를 누적하면 선택된 치킨집에 대한 최단거리가 나온다.
      }
    }
  }

}

int main(void) {
  scanf (" %d %d", &N, &M);

  vector<pair<int, int>> cs;
  for (int i=0; i<N; i++) {
    for (int j=0; j<N; j++) {
      scanf (" %d", &c[i][j]);
      if (c[i][j] == 2) {
        cs.push_back(make_pair(i, j));
      }
    }
  }

  vector<int> ind(cs.size());
  for (int i=0; i<M; i++)
    ind[i] = 1;
  sort (ind.begin(), ind.end());

  do {
    int dist = 0;
    vector<pair<int, int>> stores;
    for (int i=0; i<M; i++) {
      if (ind[i]) {
        stores.push_back(cs[i]);
      }
    }

    dist = get_distance(stores);
    if (min_dist > dist)
      min_dist = dist;

  } while (next_permutation(ind.begin(), ind.end())); 

  printf("%d\n", min_dist);
  return 0;
}
