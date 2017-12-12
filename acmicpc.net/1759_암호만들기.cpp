#include <cstdio>
#include <algorithm>
#include <utility>
#include <vector>
using namespace std;

static vector<int> v = {1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0};

int main() {
  int l, c;
  scanf (" %d %d", &l, &c);

  vector<char> crypto(c);
  for (int i=0; i<c; i++)
    scanf (" %c", &crypto[i]);

  int vowel, i;
  char ans[5] = {0, };
  do {
    vowel = 0;
    ans[0] = crypto[0];
    for (i=1; i<4; i++) {
      if (crypto[i-1] > crypto[i])
        break;

      if (v[crypto[i]-'a'])
        vowel++;

      ans[i] = crypto[i];
    }

    if (i==4 && (vowel>0 && vowel<3))
      printf("%s\n", ans);

  } while (next_permutation(crypto.begin(), crypto.end()));

  return 0;
}
