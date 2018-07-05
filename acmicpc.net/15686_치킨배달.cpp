#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
int c[50][50];
int min_dist = numeric_limits<int>::max();

int get_distance(const vector<pair<int, int>>& stores) {
  int dist = 0;

  for (int i=0; i<N; i++) {
    for (int  j=0; j<N; j++) {
      if (c[i][j] == 1) {
        int min_local = numeric_limits<int>::max();
        for (auto s : stores) {
          int tmp = abs(s.first - i) + abs(s.second - j);
          if (min_local > tmp)
            min_local = tmp;
          // printf("cs(%d, %d), house(%d, %d) : tmpDist=%d\n", s.first, s.second, i, j, tmp);
        }
        dist += min_local;
      }
    }
  }

  return dist;
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
  
  int dist;
  vector<pair<int, int>> stores;
  do {
    /*
       printf("----------- permutation -----------\n");
       for (auto e : ind)
       printf("%d ", e);
       printf("\n");
       */

    dist = 0;
    stores.clear();
    for (int i=0; i<cs.size(); i++) {
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
