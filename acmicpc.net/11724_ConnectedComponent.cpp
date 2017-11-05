#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

typedef struct Graph_ {
  int vCount;
  int eCount;
  vector<pair<int, int> > adjacencyMatrix;
  map<int, bool> visited;
} Graph;

void depthfs(Graph& g, const int v)
{
  g.visited[v] = true;

  for (auto adj=g.adjacencyMatrix.begin(); adj!=g.adjacencyMatrix.end(); adj++) {
    if (adj->first == v || adj->second == v) {
      int nextV;
      if (adj->first == v)
        nextV = adj->second;
      else
        nextV = adj->first;

      if (g.visited[nextV] == false)
        depthfs(g, nextV);
    }
  }
}

int getConnectedComponent (Graph& g)
{
  int connectedComponentCount = 0;

  for (auto e : g.visited) {
    if (e.second == false) {
      depthfs(g, e.first);
      connectedComponentCount++;
    }
  }

  return connectedComponentCount;
}

int main() {
  Graph g;
  cin >> g.vCount >> g.eCount;

  pair<int, int> adj;
  for (int i=0; i<g.eCount; i++) {
    cin >> adj.first >> adj.second;
    g.adjacencyMatrix.push_back(adj);
    g.visited[adj.first] = false;
    g.visited[adj.second] = false;
  }

  cout << getConnectedComponent(g) << endl;

  return 0;
}
