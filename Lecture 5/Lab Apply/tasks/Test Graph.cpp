#include <bits/stdc++.h>
#include "Graph.h"

using namespace std;

int main()
{
    Graph<char, int, UNDIRECTED> g;

    g.addVertice('A');
    g.addVertice('B');
    g.addVertice('C');
    g.addVertice('D');
    g.addVertice('E');

    g.addEdge(1, 2, 1);
    g.addEdge(1, 3, 4);
    g.addEdge(2, 3, 2);
    g.addEdge(2, 4, 5);
    g.addEdge(3, 5, 1);
    g.addEdge(4, 5, 3);

    std::cout << "BFS from A:\n";
    g.bfs(1);
    std::cout << "\n\n";

    std::cout << "Dijkstra from A:\n";
    auto dist = g.dijkstra(1);
    for (auto& [v, d] : dist)
        std::cout << "Vertex " << v << " distance = " << d << "\n";
}