#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
#include <queue>
#include <climits>

using namespace std;
template <class T>
using MAP = vector<vector<T>>;
using Point = pair<int, int>;

static array<Point, 6> dir_odd = { {
	{ 0, -1 }, { 0, 1 }, { -1, 0 }, { 1, 0 }, { 1, -1 }, { 1, 1 }
} };
static array<Point, 6> dir_even = { {
	{ 0, -1 }, { 0, 1 }, { -1, 0 }, { 1, 0 }, { -1, -1 }, { -1, 1 }
} };

struct Edge {
	Point num;
	int cost;
	int cnt;
	bool operator<(Edge r) const {
		return cost < r.cost;
	}
};

int dijkstra(Point& st, MAP<int>& Map) {
	int n = Map.size();
	int m = Map[0].size();
	priority_queue<Edge> pq;
	pq.push({ st, Map[st.first][st.second], 1 });
	MAP<int> dist(n, vector<int>(m, INT_MAX));
	dist[st.first][st.second] = Map[st.first][st.second];

	while (!pq.empty()) {
		Edge now = pq.top();
		pq.pop();
		int r = now.num.first;
		int c = now.num.second;

		if (now.cnt > 3) {
			return dist[r][c];
		}

		if (dist[r][c] < now.cost)
			continue;
		
		if (c % 2 == 0) {
			for (auto& d : dir_even) {
				int nr = r + d.first;
				int nc = c + d.second;

				if (nr < 0 || nc < 0 ||
					nr >= n || nc >= m)
					continue;

				int ncost = dist[r][c] + Map[nr][nc];

				if (dist[nr][nc] <= ncost)
					continue;

				int ncnt = now.cnt + 1;
				dist[nr][nc] = ncost;
 				pq.push({ {nr, nc}, ncost, ncnt });
			}
		}

		if (c % 2 == 1) {
			for (auto& d : dir_odd) {
				int nr = r + d.first;
				int nc = c + d.second;

				if (nr < 0 || nc < 0 ||
					nr >= n || nc >= m)
					continue;

				int ncost = Map[nr][nc] + dist[r][c];

				if (dist[nr][nc] <= ncost)
					continue;

				int ncnt = now.cnt + 1;
				dist[nr][nc] = ncost;
				pq.push({ {nr, nc}, ncost, ncnt });
			}
		}
	}
}

void dfs(Point now, int cnt, int cost, int& max_cost, MAP<bool>& visited, MAP<int>& Map) {
	int n = Map.size();
	int m = Map[0].size();
	
	if (cnt >= 4) {
		max_cost = max(cost, max_cost);
		return;
	}

	int r = now.first;
	int c = now.second;

	if (c % 2 == 0) {
		for (auto& d : dir_even) {
			int nr = r + d.first;
			int nc = c + d.second;

			if (nr < 0 || nc < 0 ||
				nr >= n || nc >= m)
				continue;

			if (visited[nr][nc])
				continue;

			visited[nr][nc] = true;
			dfs({ nr, nc }, cnt + 1, cost + Map[nr][nc], max_cost, visited, Map);
			visited[nr][nc] = false;
		}
	}

	if (c % 2 == 1) {
		for (auto& d : dir_odd) {
			int nr = r + d.first;
			int nc = c + d.second;

			if (nr < 0 || nc < 0 ||
				nr >= n || nc >= m)
				continue;

			if (visited[nr][nc])
				continue;

			visited[nr][nc] = true;
			dfs({ nr, nc }, cnt + 1, cost + Map[nr][nc], max_cost, visited, Map);
			visited[nr][nc] = false;
		}
	}

	return;
}

inline bool cmp(int l, int r) {
	return l > r;
}

int check_arround(int r, int c, MAP<int>& Map) {
	int n = Map.size();
	int m = Map[0].size();
	int sum = Map[r][c];
	vector<int> temp;

	if (c % 2 == 0) {
		for (auto& d : dir_even) {
			int nr = r + d.first;
			int nc = c + d.second;

			if (nr < 0 || nc < 0 ||
				nr >= n || nc >= m)
				continue;

			temp.emplace_back(Map[nr][nc]);
		}
	}

	if (c % 2 == 1) {
		for (auto& d : dir_odd) {
			int nr = r + d.first;
			int nc = c + d.second;

			if (nr < 0 || nc < 0 ||
				nr >= n || nc >= m)
				continue;

			temp.emplace_back(Map[nr][nc]);
		}
	}

	sort(temp.begin(), temp.end(), cmp);
	for (int i = 0; i < temp.size(); ++i) {
		if (i == 3)
			break;
		sum += temp[i];
	}

	return sum;
}

int get_bee_home(MAP<int>& Map) {
	int max_home = 0;
	for (int i = 0; i < Map.size(); ++i) {
		for (int j = 0; j < Map[i].size(); ++j) {
			Point st = { i, j };
			//int home = dijkstra(st, Map);
			
			//max_home = max(max_home, home);
			MAP<bool> visited(Map.size(), vector<bool>(Map[0].size()));
			visited[i][j] = true;
			//dfs(st, 1, Map[i][j], max_home, visited, Map);
			int ch = dijkstra(st, Map);
			int temp = check_arround(i, j, Map);
			//cout << i << " " << j << " " << temp << " " << ch << " " << max_home << "\n";
			max_home = max(max_home, max(temp, ch));
			//cout << i << " " << j << " " << temp << " " <<max_home << "\n";
		}
	}
	return max_home;
}

int main() {
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; ++tc) {
		int n, m;
		cin >> n >> m;
		MAP<int> Map(n, vector<int>(m));
		for (auto& r : Map) {
			for (int& c : r) {
				cin >> c;
			}
		}

		int ans = get_bee_home(Map);
		cout << "#" << tc << " " << ans << "\n";
	}
}