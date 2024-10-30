#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

using Node = pair<int, int>;
using Graph = vector<vector<Node>>;

struct Edge {
	int to;
	int cost;
	bool operator < (Edge right)const {
		if (cost > right.cost)
			return true;
		if (cost < right.cost)
			return false;

		return false;
	}
};

int dijkstra(const int& st, const int& fin, const Graph& graph) {
	int N = graph.size();
	vector<int> dist(N, 21e8);
	priority_queue<Edge> pq;
	pq.push({ st, 0 });
	dist[st] = 0;

	while (!pq.empty()) {
		Edge now = pq.top();
		pq.pop();

		if (now.to == fin)
			return dist[now.to];

		if (dist[now.to] < now.cost)
			continue;

		for (auto& node : graph[now.to]) {
			int to = node.first;
			int nc = node.second;
			int next_cost = dist[now.to] + nc;

			if (dist[to] <= next_cost)
				continue;

			dist[to] = next_cost;

			pq.push({ to, next_cost });
		}

	}

	return -1;
}

Node get_cost(const int& st, const int& fin, const Graph& graph) {
	int to_cost = dijkstra(st, fin, graph);
	int back_cost = dijkstra(fin, st, graph);
	int cost = to_cost + back_cost;
	return { st, cost };
}

bool cmp(Node a, Node b) {
	return a.second > b.second;
}

int get_max_cost(const int& p, const Graph& graph) {
	vector<Node> costs;

	for (int i = 1; i < graph.size(); ++i) {
		if (i == p)
			continue;
		Node node = get_cost(i, p, graph);
		costs.emplace_back(node);
	}
	sort(costs.begin(), costs.end(), cmp);

	return costs.front().second;
}

int main() {
	int N, M, P;
	cin >> N >> M >> P;
	Graph graph(N + 1);

	for (int i = 0; i < M; ++i) {
		int from, to, cost;
		cin >> from >> to >> cost;
		graph[from].emplace_back(to, cost);
	}

	cout << get_max_cost(P, graph) << "\n";

	int de = -1;

	return 0;
}