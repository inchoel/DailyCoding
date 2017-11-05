#include <iostream>
using namespace std;

int N;      //  시험 일수
int h[31];  //  시험 시간
int sol;  

void InputData() {
  cin >> N;
  for (int i = 0; i < N; i++){
    cin >> h[i];
  }
}

int main() {

  InputData(); //  입력 함수

  //  최종 계산값이 sol 에 저장될 수 있도록 완성하세요
  for (int i = 0; i < N; i++) {
    int hour = h[i];
    int oneDayPay = 0;
    if (hour < 3)
      continue;
    else if (hour >= 3 && hour <= 6) {
      oneDayPay = 100;
    }
    else if (hour > 6) {
      oneDayPay = 100 + (50 * (hour-6));
    }

    if (oneDayPay > 500)
      oneDayPay = 500;

    sol += oneDayPay;
  }

  // 10% 할인
  if (sol >= 10*1000) {
    sol -= (sol / 10);
  }

  cout << sol << endl;    // 정답 출력
  return 0;
}
