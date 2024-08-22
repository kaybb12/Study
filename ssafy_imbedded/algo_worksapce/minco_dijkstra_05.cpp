#include <iostream>
#include <array>
#include <vector>
#include <queue>

using namespace std;

struct Edge {
	int num;
	int cost;
	bool operator<(Edge right)const {
		if (cost > right.cost)
			return true;
		if (cost < right.cost)
			return false;

		return false;
	}
};

using Graph = vector<vector<Edge>>;

int dijkstra(const int st, const int fin, const Graph& graph) {
	int n = graph.size();
	vector<int> dist(n, 1e9);
	priority_queue<Edge> pq;
	pq.push({ st, 0 });
	dist[st] = 0;

	while(!pq.empty()) {
		Edge now = pq.top();
		pq.pop();

		if (now.num == fin)
			return dist[now.num];

		if (dist[now.num] < now.cost)
			continue;
		
		for (auto& next : graph[now.num]) {
			int nc = dist[now.num] + next.cost;

			if (dist[next.num] <= nc)
				continue;

			pq.push({ next.num, nc });
			dist[next.num] = nc;
		}
	}

	return dist[fin];
}

bool is_possible(const int p, const Graph& graph) {
	int st = 1;
	int fin = graph.size() - 1;
	int direct = dijkstra(st, fin, graph);
	int layover = dijkstra(st, p, graph) + dijkstra(p, fin, graph);
	
	//cout << direct << "" << layover << "\n";
	return direct >= layover;
}

int main() {
	int v, e, p;
	cin >> v >> e >> p;
	Graph graph(v + 1);
	for (int i = 0; i < e; ++i) {
		int from, to, cost;
		cin >> from >> to >> cost;
		graph[from].push_back({ to, cost });
		graph[to].push_back({ from, cost });
	}

	if (is_possible(p, graph))
		cout << "OKAY" << "\n";
	else
		cout << "SORRY" << "\n";

	return 0;
}