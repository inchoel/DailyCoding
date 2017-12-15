#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

static vector<int> v = {1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0};
int L, C;
string lock(5);

void generate_lock (size_t l_i, size_t c_i, vector<char>& crypto, size_t vowel) {
  if (vowel > 2) {
    return;
  }

  if (l_i == 4) {
    if (vowel > 0)
      printf("%s\n", lock.c_str());

    return;
  }

  lock[l_i] = crypto[c_i];

  for (int i=c_i; i<C-3; ++) {
    if (v[crypto[i]-'a'])
      generate_lock (l_i+1, i, crypto, vowel+1);
    else
      generate_lock (l_i+1, i, crypto, vowel);
  }
}

int main() {
  scanf (" %d %d", &L, &C);

  vector<char> crypto(c);
  for (int i=0; i<C; i++)
    scanf (" %c", &crypto[i]);

  sort (crypto.begin(), crypto.end());

  generate_lock (0, 0, crypto, 0);
  return 0;
}
