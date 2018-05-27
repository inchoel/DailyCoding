#include <cstdio>
#include <utility>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

#define POW(x) ((x)*(x))

int N, M, K, P;
bool isVisited[1001][1001];
vector<int> v[1001];
pair<int,int> info[1000+1][1000+1];

int main() {
	scanf (" %d %d %d", &N, &M, &K);
/*
	bool isVisited[N+1][N+1];
	vector<int> v[N+1];
	pair<int,int> info[N+1][N+1];
	for (int i=1; i<=N; i++) {
		for (int j=1; j<=N; j++) {
			info[i][j] = make_pair(0, 0);
			isVisited[i][j] = false;
		}
	}
*/
	int a, b, c, t;
	for (int i=0; i<M; i++) {
		scanf (" %d %d %d %d", &a, &b, &c, &t);
		info[a][b] = make_pair(c, t);
		v[a].push_back(b);
	}

#if 0
	for (int i=1; i<=N; i++) {
		for (int j=1; j<=N; j++) {
			printf("%d %d %d %d\n", i, j, info[i][j].first, info[i][j].second);
		}

		printf("--------\n");
		printf("%d: ", i);
		for (auto e : v[i])
			printf("%d ", e);
		printf("\n");
	}
#endif

	vector<pair<int,int>> path;
	stack<int> s;
	s.push(1);

	while (!s.empty()) {
		int v1 = s.top();
		bool isEndNode = true;
		for (auto v2 : v[v1]) {
			if (isVisited[v1][v2]==false) {
				isEndNode = false;
				s.push(v2);
				isVisited[v1][v2] = true;
				path.push_back((make_pair(v1, v2)));
				break;
			}
		}

		if (isEndNode) {
			// -----------path 완료 : P계산
			if (path.back().second == N) {
#if 0
				printf("----- path ----\n");
				for (auto e : path) {
					printf("%d -> %d\n", e.first, e.second);
				}
#endif
				int cost = 0;
				int p = 500;
				for (auto e : path) {
					pair<int, int> ct = info[e.first][e.second];
					if (p - ct.second > 0)
						cost += ct.first * POW(p - ct.second);
				}

				if (cost < K) {
					while (cost < K) {
						cost = 0;
						for (auto e : path) {
							pair<int, int> ct = info[e.first][e.second];
							if (p - ct.second > 0)
								cost += ct.first * POW(p - ct.second);
						}
						//printf("inc: cost=%d, K=%d, p=%d\n", cost, K, p);
						p++;
					}
					P = max(P, p-1);
				}
				else {
					while (cost > K) {
						cost = 0;
						for (auto e : path) {
							pair<int, int> ct = info[e.first][e.second];
							if (p - ct.second > 0)
								cost += ct.first * POW(p - ct.second);
						}
						//printf("dec: cost=%d, K=%d, p=%d\n", cost, K, p);
						p--;
					}
					P = max(P, p+1);
				}
			}
			// --------------------------

			s.pop();
			//--------- 경로 정리
			if (!path.empty()) {
				path.pop_back();
			}

			if (v1+1 < N) {
				for (int k=1; k<=N+1; k++)
					isVisited[v1+1][k] = false;
			}
			//----------
		}
	}

	printf("%d\n", P);

	return 0;
}



#if 0
#include <cstdio>
#include <utility>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

#define POW(x) ((x)*(x))

int N, M, K, P;
bool isVisited[1001][1001];
vector<int> v[1001];
pair<int,int> info[1000+1][1000+1];

int main() {
	scanf (" %d %d %d", &N, &M, &K);
/*
	bool isVisited[N+1][N+1];
	vector<int> v[N+1];
	pair<int,int> info[N+1][N+1];
	for (int i=1; i<=N; i++) {
		for (int j=1; j<=N; j++) {
			info[i][j] = make_pair(0, 0);
			isVisited[i][j] = false;
		}
	}
*/
	int a, b, c, t;
	for (int i=0; i<M; i++) {
		scanf (" %d %d %d %d", &a, &b, &c, &t);
		info[a][b] = make_pair(c, t);
		v[a].push_back(b);
	}

#if 0
	for (int i=1; i<=N; i++) {
		for (int j=1; j<=N; j++) {
			printf("%d %d %d %d\n", i, j, info[i][j].first, info[i][j].second);
		}

		printf("--------\n");
		printf("%d: ", i);
		for (auto e : v[i])
			printf("%d ", e);
		printf("\n");
	}
#endif

	vector<pair<int,int>> path;
	stack<int> s;
	s.push(1);

	while (!s.empty()) {
		int v1 = s.top();
		bool isEndNode = true;
		for (auto v2 : v[v1]) {
			if (isVisited[v1][v2]==false) {
				isEndNode = false;
				s.push(v2);
				isVisited[v1][v2] = true;
				path.push_back((make_pair(v1, v2)));
				break;
			}
		}

		if (isEndNode) {
			// path 완료 : P계산
			if (path.back().second == N) {
#if 0
				printf("----- path ----\n");
				for (auto e : path) {
					printf("%d -> %d\n", e.first, e.second);
				}
#endif
				int cost = 0;
				int p = k;
				while (cost < K) {
					p++;
					cost = 0;
					for (auto e : path) {
						pair<int, int> ct = info[e.first][e.second];
						if (p - ct.second > 0)
							cost += ct.first * POW(p - ct.second);
					}
				}
				P = max(P, p-1);
			}

			s.pop();
			//--------- 경로 정리
			if (!path.empty()) {
				path.pop_back();
			}

			if (v1+1 < N) {
				for (int k=1; k<=N+1; k++)
					isVisited[v1+1][k] = false;
			}
			//----------
		}
	}

	printf("%d\n", P);

	return 0;
}
#endif



#if 0
#include <cstdio>
#include <utility>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

#define POW(x) ((x)*(x))

bool isVisited[N][N];
int N, M, K;

int main() {
	scanf (" %d %d %d", &N, &M, &K);

	vector<pair<int, pair<int, int>>> v[N+1];

	for (int i=0; i<M; i++) {
		int a, b, c, t;
		scanf (" %d %d %d %d", &a, &b, &c, &t);

		v[a].push_back(make_pair(b, make_pair(c, t)));
	}
/*
	for (int i=1; i<=N; i++) {
		for (auto e : v[i]) {
			printf("%d %d %d %d\n", i, e.first, e.second.first, e.second.second);
		}
	}
*/
	// DFS

	stack<int> s;
	s.push(1);
	while (!s.empty()) {
		int i = s.top();

		if (v[i].empty()) {
			// 노드의 마지막이므로 P 구하자.
			s.pop();
			continue;
		}

		printf("%d ", i);

		int size = v[i].size();
		vector<int> isVisited(size);
		for (int j=0; j<size; j++) {
			if (isVisited[j] == false) {
				s.push(v[i][j]);
				isVisited[j] = true;
				run();
			}
		}

		s.push(v[i][j]);

	}

	return 0;
}
#endif
