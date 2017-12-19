#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

static vector<int> v = {1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0};
size_t L, C;

void generate_lock (size_t c_i, string lock, vector<char>& crypto, size_t vowel, size_t consonent) {
  if (lock.size() > L)
    return;

  if (lock.size() == L) {
    if (vowel < 1 || consonent < 2)
      return;

    printf("%s\n", lock.c_str());
  }

  for (size_t i=c_i; i<C; ++i) {
    if (v[crypto[i]-'a'])
      generate_lock (i+1, lock+crypto[i], crypto, vowel+1, consonent);
    else
      generate_lock (i+1, lock+crypto[i], crypto, vowel, consonent+1);
  }
}

int main() {
  scanf (" %lu %lu", &L, &C);

  vector<char> crypto(C);
  for (size_t i=0; i<C; i++)
    scanf (" %c", &crypto[i]);

  sort (crypto.begin(), crypto.end());

  generate_lock (0, "", crypto, 0, 0);
  return 0;
}
