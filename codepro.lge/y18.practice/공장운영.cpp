#include <stdio.h>

int N; //일
int S; //보관비용
int C[50010]; //가격
int Y[50010]; //용량

void Input_Data(void){
	int i;
	scanf("%d %d", &N, &S);
	for(i=0 ; i<N ; i++){
		scanf("%d %d", &C[i], &Y[i]);
	}
}

long long min_cost(void) {
	long long min = 0;
	
	int i=0, j=0, k=0;
	int c1, c2, c3;
	while (i < N) {
		min += C[i] * Y[i];
		for (j = i+1; j<N; j++) {
			c1 = C[j] * Y[j];
			for (k=0; k<Y[j]; k++) {
				c2 = C[j-1] * (Y[j]-k) + (Y[j]-k)*S + C[j] * k;
				if (c1 > c2) {
					min += c2;
					break;
				}
			}
			if (k == Y[j])
				break;
		}
		i = j;
	}
	
	return min;
}

int main(void){
	long long ans = -1;
	Input_Data();		// 입력 함수
	
	// TODO : 코드를 작성하세요
	ans = min_cost();
	
	printf("%lld\n", ans);		// 정답 출력
	return 0;
}
