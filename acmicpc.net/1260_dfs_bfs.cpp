#include <iostream>
#include <vector>
#include <map>
#include <iterator>
#include <algorithm>
using namespace std;

typedef struct Graph_{
  int vCount;
  int eCount;
  vector<pair<int, int> > adjacency;
  map<int, bool> visited;
} Graph;

void swap (int& s, int& e)
{
  int temp = s;
  s = e;
  e = temp;
}

void showGraphInfo (const Graph& g)
{
  cout << "num of vertex : " << g.vCount << endl;
  cout << "num of edge : " << g.eCount << endl;

  for (auto v: g.adjacency)
    cout << v.first << " " << v.second << endl;
}

void DFS(Graph& g, const int start)
{
  if (g.visited[start] == false) {
    g.visited[start] = true;
    cout << start << " ";
  }

  for (auto e=g.adjacency.begin(); e!=g.adjacency.end(); e++) {
    if (e->first == start || e->second == start) {
      int nextV = (e->first==start) ? e->second : e->first;
      if (g.visited[nextV] == false)
        DFS(g, nextV);
    }
  }
}

void BFS(Graph& g, const int start)
{
  if (g.visited[start] == false) {
    g.visited[start] = true;
    cout << start << " ";
  }

  vector<int> nextV;
  for (auto e=g.adjacency.begin(); e!=g.adjacency.end(); e++) {
    if (e->first == start || e->second == start) {
      int end = (e->first==start) ? e->second : e->first;
      if (g.visited[end] == false) {
        g.visited[end] = true;
        cout << end << " ";
        nextV.push_back(end);
      }
    }
  }

  for (auto v: nextV) {
    BFS(g, v);
  }
}

int main()
{
  Graph g;
  int startPos;
  cin >> g.vCount >> g.eCount >> startPos;

  int startV, endV;
  for (int i=0; i<g.eCount; i++) {
    cin >> startV >> endV;
    // if (startV > endV)
    //   swap(startV, endV);

    g.adjacency.push_back(make_pair(startV, endV));

    g.visited[startV] = false;
    g.visited[endV] = false;
  }
  sort(g.adjacency.begin(), g.adjacency.end());

  DFS(g, startPos);
  cout << endl;

  for (auto e=g.visited.begin(); e!=g.visited.end(); e++)
    e->second = false; 

  BFS(g, startPos);
  cout << endl;
  return 0;
}
