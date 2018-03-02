#include <cstdio>
#include <algorithm>
#include <utility>
#include <map>
using namespace std;

map<char, pair<char, char>> m;

void preorder_traversal(const char& node) {
  if (m.find(node)==m.end())
    return;

  if (node=='.')
    return;

  printf("%c", node);
  preorder_traversal(m[node].first);
  preorder_traversal(m[node].second);
}

void inorder_traversal(const char& node) {
  if (m.find(node)==m.end())
    return;

  if (node=='.')
    return;

  inorder_traversal(m[node].first);
  printf("%c", node);
  inorder_traversal(m[node].second);
}

void postorder_traversal(const char& node) {
  if (m.find(node)==m.end())
    return;

  if (node=='.')
    return;

  postorder_traversal(m[node].first);
  postorder_traversal(m[node].second);
  printf("%c", node);
}

int main(void) {
  int n = -1;
  scanf (" %d", &n);

  char node, left, right;
  for (int i=0; i<n; i++) {
    scanf (" %c %c %c", &node, &left, &right);
    m[node] = make_pair(left, right);
  }

  preorder_traversal('A');
  printf("\n");
  inorder_traversal('A');
  printf("\n");
  postorder_traversal('A');
  printf("\n");
  return 0;
}
