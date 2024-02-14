#include <array>
#include <iostream>
#include <queue>
#include <vector>
#include <tuple>

using namespace std;

using Matrix = vector<vector<int>>;
using Point = tuple<int, int, int>;

class RobotCleaner {
	static constexpr int WALL = 1;
	static constexpr int BLANK = 0;
	static constexpr int NORTH = 0;
	static constexpr int EAST = 1;
	static constexpr int SOUTH = 2;
	static constexpr int WEST = 3;
	static constexpr int STOP = 0;
	static constexpr int RUN = 1;

	static constexpr array<pair<int, int>, 4> dirs = {{
		{ 0, 1 }, { 1, 0}, { 0, -1 }, { -1, 0}
	}};

	Matrix map;
	int n;
	int m;

public:
		RobotCleaner(const int n, const int m) : n{n}, m{m} {
		map = Matrix(n + 2, vector<int>(m + 2, WALL));
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= m; ++j)
				cin >> map[i][j];
	}

	int get_cleaning_area(const int r, const int c, const int d) {
		int area_cnt = 0;

		area_cnt = bfs(r, c, d);

		return area_cnt;
	}

	int bfs(const int st_r, const int st_c, const int st_d) {
		vector<vector<bool>> visited(n + 2, vector<bool>(m + 2));
		queue<Point> q;
		q.emplace(st_r, st_c, st_d);
		visited[st_r][st_c] = true;
		int area_cnt = 0;

		while(!q.empty()) {
			auto [ r, c, d ] = q.front();
			q.pop();
			cout << " 1 " << "\n";

			for (const auto& [ dr, dc ] : dirs) {
				int nr = r + dr;
				int nc = c + dc;
				
				if (map[nr][nc] == BLANK) {
					if (!visited[nr][nc]) {
						auto [ tr, tc, td ] = go_straight(r, c, d, visited);
						q.emplace(tr, tc, td);
						visited[tr][tc] = true;
						++area_cnt; 
						cout << "area_cnt " << area_cnt << "\n";
					}

					else {
						auto [ nr, nc ] = go_backward(r, c, d);
						if (map[nr][nc] != WALL)
							q.emplace(nr, nc, d);
						else
							return area_cnt;
					}
				}
			}
		}

		return -1;
	}

	Point go_straight(const int r, const int c, const int d, const vector<vector<bool>>& visited) {
		int direction = turn_robot(d);
		int nr, nc;

		switch(direction) {
		case NORTH:
			nr = r - 1;
			nc = c;
			if (map[nr][nc] == BLANK) {
				if (!visited[nr][nc])					
					return { nr, nc, direction };
			}
			else
				break;
		case EAST:
			nr = r;
			nc = c + 1;
			if (map[nr][nc] == BLANK) {
				if (!visited[nr][nc])					
					return { nr, nc, direction };
			}
			else
				break;
		case SOUTH:
			nr = r + 1;
			nc = c;
			if (map[nr][nc] == BLANK) {
				if (!visited[nr][nc])					
					return { nr, nc, direction };
			}
			else
				break;
		case WEST:
			nr = r;
			nc = c - 1;
			if (map[nr][nc] == BLANK) {
				if (!visited[nr][nc])					
					return { nr, nc, direction };
			}
			else
				break;
		}

		return go_straight(r, c, direction, visited);
	}

	pair<int, int> go_backward(const int r, const int c, const int d) {
		int nr, nc;

		switch(d) {
		case NORTH:
			nr = r + 1;
			nc = c;
			break;
		case EAST:
			nr = r;
			nc = c - 1;
			break;
		case SOUTH:
			nr = r - 1;
			nc = c;
			break;
		case WEST:
			nr = r;
			nc = c + 1;
			break;
		}

		return { nr, nc };
	}

	inline int turn_robot(const int d) {
		switch(d) {
		case NORTH:
			return WEST;
		case EAST:
			return NORTH;
		case SOUTH:
			return EAST;
		case WEST:
			return SOUTH;
		}

		return -1;
	}

	bool is_run(const int r, const int c, const int d, const vector<vector<bool>>& visited) {

		for (const auto& [ dr, dc ] : dirs) {
			int nr = r + dr;
			int nc = c + dc;

			if(!visited[nr][nc])
				if(map[nr][nc] == BLANK)
					return true;
		}

		switch(d) {
		case NORTH:
			if (map[r + 1][c] == BLANK)
				return true;
		case EAST:
			if (map[r][c - 1] == BLANK)
				return true;
		case SOUTH:
			if (map[r - 1][c] == BLANK)
				return true;
		case WEST:
			if (map[r][c + 1] == BLANK)
				return true;
		}

		return false;
	}
};

int main() {
	int n, m;
	cin >> n >> m;
	int r, c, d;
	cin >> r >> c >> d;

	RobotCleaner robotcleaner(n, m);
	cout << robotcleaner.get_cleaning_area(r, c, d) << "\n";

	return 0;
}