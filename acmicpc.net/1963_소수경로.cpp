#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>

//#include <thread>
//#include <chrono>
using namespace std;

vector<int> prime, ans;
int prime_size;

void findPrime (vector<int>& v) {
  int num[10001];
  for (int i=0; i<=9999; i++) {
    num[i] = i;
  }

  for (int i=2; i<=sqrt(9999); i++) {
    for (int j=i+i; j<=9999; j+=i) {
      if (num[j] == -1)
        continue;

      num[j] = -1;
    }
  }

  for (int i=1000; i<=9999; i++) {
    if (num[i] == -1)
      continue;

    v.push_back(num[i]);
    // printf("%d ", num[i]);
  }
}

int getStepToMove(const int cur, const int target) {
  findPrime(prime);
  prime_size = prime.size();

  queue<int> q;
  q.push(cur);
  vector<int> curV(4), nextV(4);

  int num, equal, q_size, step=0;
  while (!q.empty()) {
    q_size = q.size();
    step++;
    // printf("qsize=%d, step=%d\n", q_size, step);
    while (q_size--) {
      num = q.front();
      q.pop();

      curV[0] = num/1000;
      curV[1] = num%1000/100;
      curV[2] = num%100/10;
      curV[3] = num%10;

      for (int i=0; i<prime_size; i++) {
        if (prime[i] == 0)
          continue;

        nextV[0] = prime[i]/1000;
        nextV[1] = prime[i]%1000/100;
        nextV[2] = prime[i]%100/10;
        nextV[3] = prime[i]%10;

        equal = 0;
        for (int j=0; j<4; j++) {
          if (curV[j] == nextV[j])
            equal++; 
        }

        if (equal >= 3) {
          q.push(prime[i]);

          // printf("%d ", prime[i]);

          if (prime[i] == target)
            return step;

          prime[i] = 0;
        }
      }
    }
    // printf("\n");
    // this_thread::sleep_for(chrono::milliseconds(300));
  }
  return -1;
}

int main() {
  int t, old_pw, new_pw;
  scanf (" %d", &t);

  while (t--) {
    scanf (" %d %d", &old_pw, &new_pw);
    if (old_pw == new_pw) {
      ans.push_back(0);
      continue;
    }

    ans.push_back(getStepToMove(old_pw, new_pw));
  }

  for (auto& e : ans) {
    if (e == -1)
      printf("Impossible\n");
    else
      printf("%d\n", e);
  }
  return 0;
}
