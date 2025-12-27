#pragma once
#include<vector>
#include<list>
#include<map>
#include<queue>
using namespace std;
enum EdgeType {UNDIRECTED, DIRECTED};
template<class T, class U = int, enum EdgeType type = DIRECTED>
struct Graph
{
	size_t verticesCount = 0;
	vector<T> vertices;
	vector<list<pair<size_t, U>>> adjacency;
	Graph() = default;

	void clear() { verticesCount = 0; vertices.clear(); adjacency.clear(); } // make Empty
	bool empty() const { return !verticesCount; }
	// bool isFull() XXX because I am implementing it with dynamic size

	void addVertice(T vertice) { vertices.push_back(vertice); adjacency.push_back({}); verticesCount++; }
	void addEdge(size_t from, size_t to, U weight)
	{
		assert(--from < verticesCount && --to < verticesCount);
		adjacency[from].push_back({to, weight});
		if (type == UNDIRECTED)
			adjacency[to].push_back({from, weight});
	}
	U getWeight(size_t from, size_t to)
	{
		assert(--from < verticesCount && --to < verticesCount);

		for (auto& [v, w] : adjacency[from])
			if (v == to)
				return w;
		assert(0);
	}

	list<T> adjacencyVerctices(size_t parent)
	{
		assert(--parent < verticesCount);
		list<T> ret;
		for (auto& [v, w] : adjacency[parent])
			ret.push_back(vertices[v]);
		return ret;
	}

	void bfs(size_t root)
	{
		assert(--root < verticesCount);
		vector<bool> visited(verticesCount);
		queue<size_t> nxt;
		visited[root] = 1;
		nxt.push(root);

		while (!nxt.empty())
		{
			auto cur = nxt.front(); nxt.pop();
			cout << vertices[cur] << " ";
			for (auto& [v, w] : adjacency[cur])
				if (!visited[v])
					nxt.push(v), visited[v] = 1;
		}
	}

	list<pair<T, size_t>> dijkstra(size_t root)
	{
		assert(--root < verticesCount);
		vector<size_t> distance(verticesCount, UINT64_MAX);
		priority_queue<pair<size_t, size_t>, vector<pair<size_t, size_t>>, greater<>> nxt;
		nxt.push({ 0, root });
		distance[root] = 0;
		while (!nxt.empty())
		{
			auto [cw, cv] = nxt.top(); nxt.pop();
			
			if (cw > distance[cv]) continue;

			for (auto& [u, w] : adjacency[cv])
				if (w + cw < distance[u])
					distance[u] = w + cw, nxt.push({ distance[u], u});
		}
		list<pair<T, size_t>> ret;
		for (int u = 0; u < verticesCount; u++)
			ret.push_back({ vertices[u], distance[u] });
		return ret;
	}


};