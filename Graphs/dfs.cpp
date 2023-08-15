#include<iostream>
#include<vector>
using namespace std;

class Graph {
  int numVertices;
  vector<int> *adjLists;
  bool *visited;

public:
  Graph(int v) {
    numVertices = v;
    adjLists = new vector<int>[v];
    visited = new bool[v];
    for (int i = 0; i < v; i++) {
      visited[i] = false;
    }
  }

  void addEdge(int u, int v) {
    adjLists[u].push_back(v);
    adjLists[v].push_back(u);
  }

  void DFS(int startVertex) {
    visited[startVertex] = true;
    cout << startVertex << " ";

    vector<int> adjList = adjLists[startVertex];
    for (auto i = adjList.begin(); i != adjList.end(); i++) {
      if (!visited[*i]) {
        DFS(*i);
      }
    }
  }
};

int main() {
  Graph g(4);
  g.addEdge(0, 1);
  g.addEdge(0, 2);
  g.addEdge(1, 2);
  g.addEdge(2, 3);

  g.DFS(0);
  return 0;
}
