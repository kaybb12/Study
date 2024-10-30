#include <iostream>
#include <queue>
#include <vector>
#include <array>

using namespace std;

using Map = vector<vector<int>>;
using Point = pair<int, int>;

static array<Point, 4> dir = { {
	{0, 1}, {0, -1}, {1, 0}, {-1, 0}
} };

static constexpr int SEA = 0;
static constexpr int ISLAND = 1;

int bfs(const Map& map) {
	vector<vector<bool>> visited(map.size(), vector<bool>(map.size()));
	queue<Point> q;
	visited[0][0] = true;
	int dist = 0;
	q.emplace( 0, 0 );

	while (!q.empty()) {
		int r = q.front().first;
		int c = q.front().second;
		q.pop();

		for (auto& d : dir) {
			int nr = r + d.first;
			int nc = c + d.second;

			if (nr < 0 || nc < 0 ||
				nr >= 4 || nc >= 4)
				continue;

			if (map[nr][nc] == SEA)
				continue;

			if (visited[nr][nc])
				continue;

			if (map[nr][nc] == ISLAND) {
				visited[nr][nc] = true;
				q.emplace(nr, nc);
			}
		}

		++dist;
	}

	return dist;
}

int get_size(const Map& map) {
	int size = bfs(map);

	return size;
}

int main() {
	Map map(4, vector<int>(4));
	for (auto& r : map) {
		for (int& c : r) {
			cin >> c;
		}
	}

	cout << get_size(map) << "\n";

	return 0;
}
