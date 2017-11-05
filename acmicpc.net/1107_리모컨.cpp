#include <cstdio>
#include <cstring>
#include <bitset>
using namespace std;

// 100->500000 으로 증가하여 도달하거나, 999900 -> 500000 감소하여 도달하는 경우가 있다.
// 그러므로 MAX의 범위는 약 2배로 설정하여, 완전탐색을 하면 된다.
#define MAX (500000*2)

int main() {
  int channel;
  scanf (" %d", &channel);

  bitset<10> remote;
  remote.set();
  int broken, num;
  scanf (" %d", &broken);
  for (int i=0; i<broken; i++) {
    scanf (" %d", &num);
    remote.set(num, 0);
  }

  int ans = abs (channel - 100); // +, - 로 이동하는 경우
  int dist, digitSize;
  bool valid;
  for (int i=0; i<MAX; i++) { // 리모컨숫자키와 +, - 로 이동하는 경우
    valid = true;
    num = i;
    digitSize = 0;
    while (num) {
      if (remote.test(num%10) == false)
        valid = false;

      num = num / 10;
      digitSize++;    // 99를 100에서 감소하는 경우에 자리수를 체크하기 위해서.
    }

    if (i == 0) {
      if (remote.test(0) == false)
        valid = false;

      digitSize++;
    }

    if (valid) {
      dist = abs(channel-i) + digitSize;
      if (ans > dist)
        ans = dist;
    }
  }

  printf("%d\n", ans);

  return 0;
}
