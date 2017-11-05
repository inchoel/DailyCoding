#include <iostream>
using namespace std;

int N,Q;
int T[101];
int engineer[6];

void Input_Data(void) {  
  cin >> N >> Q;        // 엔지니어의 수, 고객의 수
  for(int i=1;i<=Q;i++){
    cin >> T[i];        // 고객의 업무처리 시간
  }
}

void solve(int& sol) {
  int k = 1;
  int i, j;
  for (i=1; i<=500*Q; i++) {
    for (j=1; j<=N; j++) {
      if (k > Q)
        break;

      if (engineer[j] == 0) {
        engineer[j] = T[k++];
      }
    }

    int done = true;
    for (j=1; j<=N; j++) {
      if (engineer[j] > 0)
        engineer[j]--;

      if (k <= Q || engineer[j] != 0)
        done = false;
    }

    if (done == true) {
      sol = i;
      return;
    }
  }
}

int main(void) {
  int sol = 0;

  Input_Data();       // 입력 함수

  //  코드를 작성하세요
  solve(sol);

  cout << sol << endl;  // 정답 출력
  return 0;
}
