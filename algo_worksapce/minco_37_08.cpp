#include <iostream>
#include <queue>
#include <vector>
#include <array>

using namespace std;

using Map = vector<vector<int>>;
using Point = pair<int, int>;

static array<Point, 4> dir = { {
	{1, 0}, {-1, 0}, {0, 1}, {0, -1}
} };

static constexpr int ISLAND = 1;
static constexpr int SEA = 0;

void bfs(int sr, int sc, Map& map, Map& visited) {
	int row = map.size();
	int col = map[0].size();

	visited[sr][sc] = 1;
	queue<Point> q;
	q.emplace(sr, sc);

	while (!q.empty()) {
		int r = q.front().first;
		int c = q.front().second;
		q.pop();

		for (auto d : dir) {
			int nr = r + d.first;
			int nc = c + d.second;

			if (nr < 0 || nc < 0 ||
				nr >= row || nc >= col)
				continue;

			if (map[nr][nc] == SEA)
				continue;

			if (visited[nr][nc] == 1)
				continue;

			if (map[nr][nc] == ISLAND) {
				visited[nr][nc] = 1;
				q.emplace(nr, nc);
			}

		}
	}

	return;
}

int get_count_island(Map& map) {
	int row = map.size();
	int col = map[0].size();
	int cnt = 0;
	Map visited(row, vector<int>(col));
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < col; ++j) {
			if (map[i][j] == SEA)
				continue;
			if (visited[i][j] == 1)
				continue;
			++cnt;
			bfs(i, j, map, visited);
		}
	}

	return cnt;
}

int main() {
	int n, m;
	cin >> n >> m;
	Map map(n, vector<int>(m));

	for (auto& r : map) {
		for (int& c : r) {
			cin >> c;
		}
	}

	cout << get_count_island(map) << "\n";

	return 0;
}