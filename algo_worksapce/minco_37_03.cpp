#include <iostream>
#include <vector>
#include <queue>
#include <array>

using namespace std;
using Map = vector<vector<int>>;
using Point = pair<int, int>;

static array<Point, 8> dir = { {
	{1, 0},
	{-1, 0},
	{0, 1},
	{0, -1},
	{1, 1},
	{1, -1},
	{-1, 1},
	{-1, -1}
} };
static constexpr int FIREWORK = 1;
static constexpr int SKY = 0;

int bfs(Map& map, vector<Point>& ps) {
	queue<Point> q;
	for (auto& p : ps) {
		q.emplace(p);
	}
	int time = 0;

	while (!q.empty()) {
		int r = q.front().first;
		int c = q.front().second;
		q.pop();

		for (auto& d : dir) {
			int nr = r + d.first;
			int nc = c + d.second;
			

			if (nr < 0 || nc < 0 ||
				nr >= 4 || nc >= 5)
				continue;

			if (map[nr][nc] == FIREWORK)
				continue;
		
			if (map[nr][nc] == SKY) {
				map[nr][nc] = map[r][c] + 1;
				time = map[nr][nc];
				q.emplace(nr, nc);
			}
		}
	}

	return time - 1;
}

int get_time(Map& map, vector<Point>& ps) {
	int time = bfs(map, ps);

	return time;
}

int main() {
	Map map(4, vector<int>(5));
	vector<Point> ps;
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 5; ++j) {
			cin >> map[i][j];
			if (map[i][j] == FIREWORK)
				ps.emplace_back(i, j);
		}
	}

	cout << get_time(map, ps) << "\n";

	return 0;
}