#include <iostream>
using namespace std;

const int MAX=50000;
const int MOD=10000;

class S {
  int sp;
  int data[MAX];
  public:
  S() {
    sp = 0;
  }

  void Push(int d) {
    if (sp >= MAX) return;
    data[sp++] = d;
    // printf("push : %d\n", d);
  }

  int Pop(void) {
    //  Pop함수를 완성하세요
    //  스택에서 데이터를 Pop하여 리턴
    //  Pop 시킬 데이터가 없을 경우 -1을 리턴
    if (sp == 0)
      return -1;

    // printf("pop : %d\n", data[sp-1]);
    return data[--sp];
  }
};

class A {
  int N;
  int a[MAX];
  char op[MAX];

  public:
  void Input_Data(void){
    int i;
    cin >> N;
    cin >> a[0];
    for (i = 1; i < N; i++){
      cin >> op[i];
      cin >> a[i];
    }
  }
  int Multiply(int a, int b){
    return (a*b) % MOD;
  }
  int Solve(void){
    int i, d;
    int sol = 0;
    S S;

    S.Push(a[0]);
    for (i = 1; i < N; i++) {
      switch (op[i]) {
        case '*':
          d = S.Pop();
          S.Push(Multiply(d, a[i]));
          break;
        case '+':
          S.Push(a[i]);
          break;
      }
    }

    do {
      int val = S.Pop();
      if (val == -1)
        break;

      sol += val;
    } while (1);

    return (sol % MOD);
  }
};

int main() {
  A aa;
  aa.Input_Data();
  cout << aa.Solve() << endl;
  return 0;
}
