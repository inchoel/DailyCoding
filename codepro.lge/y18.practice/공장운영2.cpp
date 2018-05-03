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
  int price = C[0];
	long long min = price * Y[0];

  for (int i=1; i<N; ++i) {
    price += S;
    if (price > C[i])
      price = C[i];

    min += (price * Y[i]);
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
