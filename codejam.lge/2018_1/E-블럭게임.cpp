#include <cstdio>
#include <algorithm>
#include <list>
#include <vector>
using namespace std;

int N;
int com;
list<int> b;


void show() {
	for (auto it=b.begin(); it!=b.end(); it++)
		printf("%d ", *it);
	printf("\n");
}

int findDirection(list<int>::iterator& pos, const int target) {
	int direction = 1;
	for (auto it=b.begin(); it!=pos; it++) {
		if (*it == target) {
			direction = -1;
			pos--;
			break;
		}
	}
	return direction;
}

int main() {
	scanf (" %d", &N);
	vector<int> asc(N+1);

	for (int i=1; i<=N; i++) {
		scanf (" %d", &asc[i]);
		b.push_back(asc[i]);
	}
	sort(asc.begin(), asc.end());

	int direction = 1;
	auto pos = b.begin();
	auto it = pos;
	for (int i=1; i<=N; i++) {
		int target = asc[i];
		// pos == begin이면 오른쪽
		// pos + 1 == end 이면 왼쪽
		// list.size() 1이면 삭제만 한다.
		int c = 0;
		if (direction == 1) {
			for (it=pos; it!=b.end(); it++) {
				if (*it == target) {
					pos = b.erase(it);
					com += (c+1);

					//printf("r: com=%d, c=%d\n", com, c);
					//show();
					direction = findDirection(pos, asc[i+1]);
					break;
				}
				c++;
			}
		}
		else if (direction == -1) {
			for (it=pos; it!=b.begin(); it--) {
				if (*it == target) {
					pos = b.erase(it);
					com += (c+1);

					//printf("l: com=%d, c=%d\n", com, c);
					//show();
					direction = findDirection(pos, asc[i+1]);
					break;
				}
				c++;
			}

			if (it == b.begin()) {
				pos = b.erase(it);
				com += (c+1);
				//printf("begin: com=%d, c=%d\n", com, c);
				direction = findDirection(pos, asc[i+1]);
			}
		}
	}

	printf("%d\n", com);

	return 0;
}

