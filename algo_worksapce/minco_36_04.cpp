#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Edge {
	int num;
	int cost;
	bool operator < (Edge right)const {
		if (cost > right.cost)
			return true;
		if (cost < right.cost)
			return false;

		return false;
	}
};

using Graph = vector<vector<Edge>>;

int dijkstra(const int& st, const int& fin, const Graph& graph) {
	int N = graph.size();
	vector<int> dist(N, 21e8);
	priority_queue<Edge> pq;
	pq.push({ st, 0 });
	dist[st] = 0;

	while (!pq.empty()) {
		Edge now = pq.top();
		pq.pop();

		if (now.num == fin)
			return dist[now.num];

		if (dist[now.num] < now.cost)
			continue;

		for (const auto& next : graph[now.num]) {
			int next_cost = dist[now.num] + next.cost;

			if (dist[next.num] <= next_cost)
				continue;

			dist[next.num] = next_cost;
			pq.push({ next.num, next_cost });
		}
	}

	return -1;
}

int get_min_cost(const int& st, const int& fin1, const int& fin2, const Graph& graph) {
	int cost1 = dijkstra(st, fin1, graph) + dijkstra(fin1, fin2, graph);
	int cost2 = dijkstra(st, fin2, graph) + dijkstra(fin2, fin1, graph);
	int cost = min(cost1, cost2);
	return cost;
}

int main() {
	//입력
	int C, P, K, A, B;
	cin >> C >> P >> K >> A >> B;
	
	Graph graph(P + 1);
	for (int i = 0; i < C; ++i) {
		int from, to, cost;
		cin >> from >> to >> cost;
		graph[from].push_back({ to, cost });
		graph[to].push_back({ from, cost });
	}

	//solution
	int min_cost = get_min_cost(K, A, B, graph);
	
	// 출력
	cout << min_cost << "\n";

	return 0;
}