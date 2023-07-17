#include<iostream>
#include<vector>

using namespace std;

class Graph {
  int numVertices;
  vector<int> *adjLists;

public:
  Graph(int vertices) {
    numVertices = vertices;
    adjLists = new vector<int>[vertices];
  }

  void addEdge(int src, int dest) {
    adjLists[src].push_back(dest);
    adjLists[dest].push_back(src);
  }

  void BFS(int StartVertex) {
    vector<bool> visited(numVertices, false);
    vector<int> queue;

    visited[StartVertex] = true;
    queue.push_back(StartVertex);

    while (!queue.empty()) {
      int curvertex = queue.front();
      cout << "visited " << curvertex << endl;
      queue.erase(queue.begin());

      for (auto i = adjLists[curvertex].begin(); i != adjLists[curvertex].end(); i++) {
        int adjVertex = *i;
        if (!visited[adjVertex]) {
          visited[adjVertex] = true;
          queue.push_back(adjVertex);
        }
      }
    }
  }
};

int main() {
  Graph g(4);
  g.addEdge(0, 1);
  g.addEdge(0, 2);
  g.addEdge(1, 2);
  g.addEdge(2, 0);
  g.addEdge(2, 3);
  g.addEdge(3, 3);
  g.BFS(2);  // Starting vertex for BFS

  return 0;
}
