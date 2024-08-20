#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>

using namespace std;

using Point = pair<int, int>;
using Graph = vector<vector<Point>>;

struct Edge {
	int idx;
	int cost;

	bool operator<(Edge right)const {
		if (right.cost > cost)
			return false;
		if (right.cost < cost)
			return true;
		return false;
	}
};

bool cmp(Point a, Point b) {
	if (a.second > b.second)
		return false;
	if (a.second < b.second)
		return true;
	return false;
}


int dijkstra(const int& st, const int& fin, const Graph& graph) {
	int N = graph.size();
	vector<int> dist(N, INT_MAX);
	//vector<bool> visited(N);
	priority_queue<Edge> pq;

	pq.push({ st, 0 });
	dist[st] = 0;
	//visited[st] = true;

	while (!pq.empty()) {
		Edge now = pq.top();
		pq.pop();

		if (now.idx == fin)
			return dist[now.idx];

		if (dist[now.idx] < now.cost)
			continue;

		for (auto& info : graph[now.idx]) {
			Edge next = { info.first, info.second };
			int next_cost = dist[now.idx] + next.cost;

			if (dist[next.idx] <= next_cost)
				continue;

			dist[next.idx] = next_cost;

			pq.push({ next.idx, next_cost });
		}
	}

	return -1;
}

//get cost
int get_highway_cost(const int& st, const int& fin, const Graph& graph) {
	return dijkstra(st, fin, graph);
}

//increase cost
void renewal_graph_cost(const int tax, Graph& graph) {
	for (auto& r : graph) {
		for (Point& c : r) {
			c.second += tax;
		}
	}
}

int main() {
	//input
	int N, M, K;
	cin >> N >> M >> K;
	int st, fin;
	cin >> st >> fin;

	Graph graph(N + 1);
	for (int i = 0; i < M; ++i) {
		int from, to, cost;
		cin >> from >> to >> cost;

		graph[from].emplace_back(to, cost);
		graph[to].emplace_back(from, cost);
	}

	vector<int> taxes(K + 1);
	for (int i = 1; i <= K; ++i) {
		cin >> taxes[i];
	}

	for (auto& r : graph) {
		sort(r.begin(), r.end(), cmp);
	}

	//solution
	for (const auto& tax : taxes) {
		renewal_graph_cost(tax, graph);
		int cost = get_highway_cost(st, fin, graph);

		//output
		cout << cost << "\n";
	}
}