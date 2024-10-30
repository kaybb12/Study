#include <iostream>
#include <vector>
#include <queue>
#include <array>

using namespace std;

using Map = vector<vector<int>>;
using Point = pair<int, int>;

static constexpr int WALL = 1;
static constexpr int PATH = 0;
static constexpr int CHIKEN = 2;

static array<Point, 4> dir = { {
	{ 1, 0 }, { -1, 0 }, { 0, 1 }, { 0, -1 }
} };

int bfs(const Map& map) {
	Map visited(4, vector<int>(6));
	visited[0][0] = 1;
	queue<Point> q;
	q.emplace(0, 0);
	int cnt = 0;

	while (!q.empty()) {
		int r = q.front().first;
		int c = q.front().second;
		q.pop();

		for (const auto& d : dir) {
			int nr = r + d.first;
			int nc = c + d.second;

			if (nr < 0 || nc < 0 ||
				nr >= 4 || nc >= 6)
				continue;

			if (visited[nr][nc] == 1)
				continue;

			if (map[nr][nc] == WALL)
				continue;

			if (map[nr][nc] == CHIKEN) {
				++cnt;
				visited[nr][nc] = 1;
				q.emplace(nr, nc);
			}
			
			if (map[nr][nc] == PATH) {
				visited[nr][nc] = 1;
				q.emplace(nr, nc);
			}

		}

	}

	return cnt;
}

int get_chiken(const Map& map) {
	return bfs(map);
}

int main() {
	Map map(4, vector<int>(6));
	for (auto& r : map) {
		for (int& c : r)
			cin >> c;
	}

	cout << get_chiken(map) << "\n";

	return 0;
}