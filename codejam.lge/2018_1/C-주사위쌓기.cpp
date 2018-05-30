#include <cstdio>
#include <algorithm>
#include <list>
using namespace std;

int N;
int tower;
list<int> sl;

void show() {
  for (auto e: sl)
    printf("%d ", e);
  printf("\n");
}

int main() {
  scanf (" %d", &N);

  int in;
  for (int i=0; i<N; i++) {
    scanf (" %d", &in);
    sl.emplace_back(in);
  }
  sl.sort();
  // show();

  int stack, n;
  while (!sl.empty()) {
    stack = 0;
    for (auto it=sl.begin(); it!=sl.end(); it++) {
      n = *it;
      if (n >= stack) {
        stack++;
        it = sl.erase(it);
        it--;
        // printf("%d ", n);
      }
    }
    // printf("\n");

    tower++;
  }

  printf("%d\n", tower);

  return 0;
}


#if 0
#include <cstdio>
#include <functional>
#include <algorithm>
#include <limits>
#include <vector>
using namespace std;

int N;
vector<int> v;

int main() {
	scanf (" %d", &N);
	v.resize(N);

	for (int i=0; i<N; i++) {
		scanf (" %d", &v[i]);
	}
	sort(v.begin(), v.end(), greater<int>());

	int tower = 0;
	int stackable = 0;
	int x;
	vector<bool> isVisited(N, false);
	while (1) {
		for (x=0; x<N; x++) {
			if (isVisited[x] == false) {
				stackable = v[x];
				isVisited[x] = true;
				break;
			}
		}
		if (x == N)
			break;

		//printf("stackable = %d\n", stackable);
		int next, s;
		while (stackable) {
			int min_dist = numeric_limits<int>::max();
			int dist = -1;
			//for (s=next; s<N; s++) {
			for (s=0; s<N; s++) {
				if (isVisited[s] == true)
					continue;

				dist = abs ((stackable - 1) - v[s]);
				if (min_dist > dist) {
					next = s;
					min_dist = dist;
				}
			}
			if (dist < 0)
				break;

			stackable = min (stackable -1, v[next]);
			//printf("--stackable = %d\n", stackable);
			isVisited[next] = true;
		}

		tower++;
	}

	printf("%d\n", tower);

	return 0;
}
/*
17
3 3 3 3 3 1 1 1 1 1 1 1 1 1 1 1 1

8
3 3 3 3 3 1 1 1
 */


/*
#include <cstdio>
#include <functional>
#include <algorithm>
#include <vector>
using namespace std;

int N;
vector<int> v;

int main() {
	scanf (" %d", &N);
	v.resize(N);

	for (int i=0; i<N; i++) {
		scanf (" %d", &v[i]);
	}
	sort(v.begin(), v.end(), greater<int>());

	int tower = 0;
	int k=0;
	while (k < N) {
		int stackable = v[k];
		k++;

		while (stackable) {
			stackable = min (v[k], stackable-1);
			printf("stackable = %d\n", stackable);

			k++;
			if (k == N)
				break;
		}
		tower++;
		printf("tower: %d\n", tower);
	}

	printf("%d\n", tower);

	return 0;
}
*/
#endif

