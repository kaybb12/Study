#include <iostream>
#include <vector>
#include <queue>

using namespace std;
template <class T>
using Graph = vector<vector<T>>;

int get_group(Graph<int>& graph) {
	vector<bool> visited(graph.size());
	int cnt = 0;
	for (int i = 1; i < graph.size(); ++i) {
		if (!visited[i]) {
			queue<int> q;
			q.emplace(i);
			visited[i] = true;
			while (!q.empty()) {
				int now = q.front();
				q.pop();
				for (int j = 0; j < graph[now].size(); ++j) {
					int next = graph[now][j];
					if (visited[next])
						continue;
					q.emplace(next);
					visited[next] = true;
				}
			}
			++cnt;
		}
		else
			continue;
	}

	return cnt;
}

int main() {
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; ++tc) {
		int n, m;
		cin >> n >> m;
		Graph<int> graph(n + 1);
		for (int i = 0; i < m; ++i) {
			int from, to;
			cin >> from >> to;
			graph[from].push_back(to);
			graph[to].push_back(from);
		}

		int ans = get_group(graph);
		cout << "#" << tc << " " << ans << "\n";
	}

	return 0;
}