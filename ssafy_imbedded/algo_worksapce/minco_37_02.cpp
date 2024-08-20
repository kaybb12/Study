#include <iostream>
#include <vector>
#include <queue>
#include <array>

using namespace std;

using Map = vector<vector<int>>;
using Point = pair<int, int>;
static array<Point, 4> dir = { {
	{1, 0},
	{-1, 0},
	{0, 1},
	{0, -1}
} };
static constexpr int FIRE = 0;
static constexpr int UNFIRE = 1;

int bfs(Point& p, Map& map) {
	int time = 0;
	queue<Point> q;
	q.emplace(p);
	
	while (!q.empty()) {
		int r = q.front().first;
		int c = q.front().second;
		q.pop();

		for (auto d : dir) {
			int nr = r + d.first;
			int nc = c + d.second;

			if (nr < 0 || nc < 0 ||
				nr >= map.size() || nc >= map.size())
				continue;

			if (map[nr][nc] == UNFIRE)
				continue;

			if (map[nr][nc] == FIRE) {
				map[nr][nc] = map[r][c] + 1;
				time = map[nr][nc];
				q.emplace(nr, nc);
			}
		}
	}

	return time;
}

int get_time(Point& p, Map& map) {
	int time = bfs(p, map);

	return time;
}

int main() {
	int N, M;
	cin >> N >> M;

	Map map(N, vector<int>(M, UNFIRE));

	for (auto& r : map) {
		for (int& c : r) {
			cin >> c;
		}
	}

	Point p = { 0, 0 };
	int r, c;
	cin >> r >> c;
	p = { r, c };

	cout << get_time(p, map) << "\n";

	return 0;
}