#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

static vector<int> v = {1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0};

int main() {
  int l, c;
  scanf (" %d %d", &l, &c);

  vector<char> crypto(c);
  for (int i=0; i<c; i++)
    scanf (" %c", &crypto[i]);

  sort (crypto.begin(), crypto.end());
  int vowel, i;
  char ans[5] = {0, };
  set<string> ans_set;
  do {

    vowel = 0;
    ans[0] = crypto[0];
    if (v[crypto[0]-'a'])
      vowel++;

    for (i=1; i<4; i++) {
      if (crypto[i-1] > crypto[i])
        break;

      if (v[crypto[i]-'a'])
        vowel++;

      ans[i] = crypto[i];
    }

    if (i==4 && (vowel>0 && vowel<3)) {
      ans_set.emplace(ans);
    }

  } while (next_permutation(crypto.begin(), crypto.end()));

  for (auto a : ans_set)
    printf("%s\n", a.c_str());
  return 0;
}
