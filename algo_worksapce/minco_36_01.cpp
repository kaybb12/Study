#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>

using namespace std;

struct Edge {
	int num;
	int cost;
	bool operator<(Edge right)const {
		if (cost < right.cost)
			return false;
		if (cost > right.cost)
			return true;

		return false;
	}
};

int dijkstra(int st, int fin, vector<vector<Edge>>& graph) {
	int N = graph.size();
	vector<int> dist(N, INT_MAX);
	vector<bool> visited(N);

	priority_queue<Edge> pq;

	pq.push({ st, 0 });
	dist[st] = 0;
	visited[st] = true;

	while (!pq.empty()) {

		Edge now = pq.top();
		pq.pop();
		//cout << now.num << " " << now.cost << "\n";
		
		if (now.num == fin)
			return dist[now.num];

		if (dist[now.num] < now.cost)
			continue;

		for (int i = 0; i < graph[now.num].size(); ++i) {
			Edge next = graph[now.num][i];
			int nextcost = dist[now.num] + next.cost;

			if (visited[next.num])
				continue;

			if (dist[next.num] <= nextcost) 
				continue;

			dist[next.num] = nextcost;

			pq.push({ next.num, nextcost });
		}
	}

	return -1;
}


int main() {
	int N, T;
	cin >> N >> T;

	vector<vector<Edge>> graph(N);
	

	for (int i = 0; i < T; ++i) {
		int from, to, cost;
		cin >> from >> to >> cost;
		graph[from].push_back({ to, cost });
		//graph[to].push_back({ from, cost });
	}

	int de = -1;

	int total_cost = dijkstra(0, N - 1, graph);
	if (total_cost < 0)
		cout << "impossible" << "\n";
	else {
		cout << total_cost << "\n";
	}
	

	return 0;
}