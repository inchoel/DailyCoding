#include <cstdio>
#include <algorithm>
#include <utility>
#include <queue>
using namespace std;

#define SIZE (105)
int N, M;
bool maze[SIZE][SIZE];
bool isVisited[SIZE][SIZE];
queue<pair<int, int> > q;

void nextPath(int i, int j) {
	if (i < 1)
		return;
	if (i > N)
		return;
	if (j < 1)
		return;
	if (j > M)
		return;

	if (maze[i][j] && isVisited[i][j]==false)
		q.push (make_pair(i, j));
}

int countShortestPath(void) {
	int ans = 1;
	pair<int, int> temp(1, 1);
	q.push(temp);
	size_t q_size = q.size();
	int i, j;
	while (!q.empty()) {
		temp = q.front();
		q.pop();
		q_size--;
		i = temp.first;
		j = temp.second;

		isVisited[i][j] = true;

		if (i==N && j==M)
			break;

		nextPath(i-1, j);
		nextPath(i+1, j);
		nextPath(i, j-1);
		nextPath(i, j+1);

		if (q_size==0) {
			q_size = q.size();
			ans++;
		}
	}
	return ans;
}

int main(void) {
	scanf (" %d %d", &N, &M);
	char input[SIZE];
	for (int i=1; i<=N; i++) {
		scanf (" %s", input+1);
		for (int j=1; j<=M; j++) {
			maze[i][j] = (bool)((input[j] - '0')? true: false);
		}
	}

	printf ("%d\n", countShortestPath ());

	return 0;
}
