#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int N, Q;

int main() {
	scanf (" %d %d", &N, &Q);
	vector<int> v(Q+1);
	for (int i=1; i<=Q; i++) {
		scanf (" %d", &v[i]);
	}
	
	vector<int> eng(N, 0);
	int min, minC;
	int i,j;
	for (i=1; i<=Q; i++) {
	  min = numeric_limits<int>::max();
		for (j=1; j<=N; j++) {
			if (min > eng[j]) {
				minC = j;
				min = eng[j];
			}
		}
		eng[minC] += v[i];
		//printf("%d\n", eng[minC]);
	}
	
	int max = 0;
	for (int k=1; k<=N; k++) {
		if (max < eng[k])
			max = eng[k];
	}
	
	printf("%d\n", max);
	
	return 0;
}
