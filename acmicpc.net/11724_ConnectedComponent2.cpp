#include <iostream>
#include <array>
using namespace std;

typedef struct Graph_ {
  int vCount;
  int eCount;

  array<array<int, 1001>, 1001> adj;
  array<bool, 1001> isVisited;
} Graph;

Graph g;

void dfs(Graph& g, const int v)
{
  for (int i=1; i<=g.vCount; i++) {
    if (g.isVisited[i]==false && g.adj[v][i]) {
      g.isVisited[i] = true;
      dfs(g, i);
    }
  }
}

int getConnectedComp(Graph& g)
{
  int connectedComp = 0;
  for (int i=1; i<=g.vCount; i++) {
    for (int j=1; j<=g.vCount; j++) {
      if (g.isVisited[i]==false) {
        g.isVisited[i] = true;
        dfs(g, i);
        connectedComp++;
      }
    }
  }

  return connectedComp;
}

int main()
{
  cin >> g.vCount >> g.eCount;

  // g.isVisited.fill(false);
  // for (auto e : adj)
  //   fill(e.begin(), e.end(). 0);

  int start, end;
  for (int i=0; i<g.eCount; i++) {
    cin >> start >> end;
    g.adj[start][end] = g.adj[end][start] = 1;
  }

  cout << getConnectedComp(g) << endl;

  return 0;
}
