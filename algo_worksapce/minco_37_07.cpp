#include <iostream>
#include <vector>
#include <queue>
#include <array>

using namespace std;

using Map = vector<vector<char>>;
using Point = pair<int, int>;

static array<Point, 4> dir = { {
	{ 0, 1 }, { 0, -1 }, { 1, 0 }, { -1, 0 }
} };

static constexpr char COUNTRY_RAT = 'S';
static constexpr char CITY_RAT = 'D';
static constexpr char CHEESE = 'C';
static constexpr char PATH = '.';
static constexpr char WALL = 'x';

int bfs(const Map& map, const Point& st, const Point& fin) {
	int row = map.size();
	int cal = map[0].size();
	vector<vector<int>> dist(row, vector<int>(cal, -1));
	queue<Point> q;
	dist[st.first][st.second] = 0;
	q.emplace(st.first, st.second);

	while (!q.empty()) {
		int r = q.front().first;
		int c = q.front().second;
		q.pop();

		if (r == fin.first && c == fin.second)
			return dist[r][c];

		for (const auto& d : dir) {
			int nr = r + d.first;
			int nc = c + d.second;

			if (nr < 0 || nc < 0 ||
				nr >= row || nc >= cal)
				continue;

			if (map[nr][nc] == WALL)
				continue;

			if (dist[nr][nc] != -1)
				continue;

			dist[nr][nc] = dist[r][c] + 1;
			q.emplace(nr, nc);
		}
	}
	return -1;
}

int get_min_time(const Map& map, const Point& cheese, const Point& country, const Point& city) {
	int time = bfs(map, country, cheese) + bfs(map, cheese, city);
	return time;
}

int main() {
	int N, M;
	cin >> N >> M;
	Map map(N, vector<char>(M));
	Point cheese, country_rat, city_rat;
	for (int r = 0; r < N; ++r) {
		for (int c = 0; c < M; ++c) {
			cin >> map[r][c];
			if (map[r][c] == CHEESE)
				cheese = { r, c };
			if (map[r][c] == COUNTRY_RAT)
				country_rat = { r, c };
			if (map[r][c] == CITY_RAT)
				city_rat = { r, c };
		}
	}

	cout << get_min_time(map, cheese, country_rat, city_rat) << "\n";

	return 0;
}