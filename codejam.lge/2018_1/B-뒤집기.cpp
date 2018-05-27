#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int N, K, M;

int main() {
	scanf (" %d %d %d", &N, &K, &M);
	int tmp;
	for (int i=0; i<N; i++) {
		scanf (" %d", &tmp);
	}

	int pos = K;
	int op;
	for (int i=0; i<M; i++) {
		scanf (" %d", &op);
		//printf("op = %d\n", op);
		if (op > 0) {
			if (pos <= op) {
				pos = 1 + (op - pos);
				//printf("pos=%d\n", pos);
			}
		}
		else {
			op = abs(op);
			if ((N - op) < pos) {
				pos = (N-pos+1) + (N-op);
				//printf("pos=%d\n", pos);
			}
		}
	}

	printf("%d\n", pos);

	return 0;
}

