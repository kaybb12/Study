#include <iostream>
#include <array>
#include <queue>

using namespace std;
using Point = pair<int, int>;

static array<array<int, 4>, 4> map = { {
	{ 0, 0, 0, 0 },
	{ 1, 1, 0, 1 },
	{ 0, 0, 0, 0 },
	{ 1, 0, 1, 0 }
} };

static array<Point, 4> dir = { {
	{ 1, 0 }, {-1, 0}, { 0, 1 }, { 0, -1 }
} };

static constexpr int PATH = 0;
static constexpr int WALL = 1;

int bfs(const Point& st, const Point& fin) {
	vector<vector<int>> dist(4, vector<int>(4, -1));
	queue<Point> q;
	
	q.emplace(st.first, st.second);
	dist[st.first][st.second] = 0;

	while (!q.empty()) {
		int r = q.front().first;
		int c = q.front().second;
		q.pop();

		if (r == fin.first && c == fin.second) {
			return dist[r][c];
		}

		for (const auto& d : dir) {
			int nr = r + d.first;
			int nc = c + d.second;

			if (nr < 0 || nc < 0 ||
				nr >= 4 || nc >= 4)
				continue;

			if (map[nr][nc] == WALL)
				continue;

			if (dist[nr][nc] != -1)
				continue;

			if (map[nr][nc] == PATH) {
				dist[nr][nc] = dist[r][c] + 1;
				q.emplace(nr, nc);
			}
		}
	}

	return -1;
}

int get_min_count(const Point& st, const Point& fin) {
	int cnt = bfs(st, fin);
	return cnt;
}

int main() {
	Point start, finish;
	cin >> start.first >> start.second;
	cin >> finish.first >> finish.second;

	cout << get_min_count(start, finish) << "회\n";

	return 0;
}