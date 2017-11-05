#include <iostream>
#include <vector>
using namespace std;

typedef struct Node_ {
  char data;
  char left;
  char right;
} Node;

Node* search(const vector<Node*> t, const char data)
{
  Node* found = NULL;
  for (auto e : t) {
    if (e->data == data) {
      found = e;
      break;
    }
  }

  return found;
}

void preorderTraversal(const vector<Node*> t, const char c)
{
  if (c == '.')
    return;

  Node* n = search(t, c);
  if (n == NULL)
    return;

  cout << n->data;
  preorderTraversal(t, n->left);
  preorderTraversal(t, n->right);
}

void inorderTraversal(const vector<Node*> t, const char c)
{
  if (c == '.')
    return;

  Node* n = search(t, c);
  if (n == NULL)
    return;

  inorderTraversal(t, n->left);
  cout << n->data;
  inorderTraversal(t, n->right);
}

void postorderTraversal(const vector<Node*> t, const char c)
{
  if (c == '.')
    return;

  Node* n = search(t, c);
  if (n == NULL)
    return;

  postorderTraversal(t, n->left);
  postorderTraversal(t, n->right);
  cout << n->data;
}

int main() {
  int n;
  cin >> n;

  vector<Node*> tree;
  char data, left, right;
  while (n--) {
    cin  >> data >> left >> right;
    Node* n = new Node;
    n->data = data;
    n->left = left;
    n->right = right;

    tree.push_back(n);
  }

  for (auto n: tree)
    cout << n->data << " " << n->left << " " << n->right << endl;

  preorderTraversal(tree, 'A'); cout << endl;
  inorderTraversal(tree, 'A'); cout << endl;
  postorderTraversal(tree, 'A'); cout << endl;
  return 0;
}
