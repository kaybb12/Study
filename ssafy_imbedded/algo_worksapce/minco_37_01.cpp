#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

using Map = vector<vector<int>>;
using Point = pair<int, int>;

const int dx[] = { -1, 1, 0, 0 };
const int dy[] = { 0, 0, -1, 1 };

void bfs(Point start, Map& map) {
	int N = map.size();
	queue<Point> q;
	q.push(start);
	map[start.first][start.second] = 1;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
				if (map[nx][ny] == 0 || map[nx][ny] > map[x][y] + 1) {
					map[nx][ny] = min(map[x][y] + 1, 9);
					if (map[nx][ny] < 9) {
						q.push({ nx, ny });
					}
				}
			}
		}
	}
}

int main() {
	int N;
	cin >> N;
	Map map(N, vector<int>(N, 0));

	int y1, x1, y2, x2;
	cin >> y1 >> x1 >> y2 >> x2;

	bfs({ y1, x1 }, map);
	bfs({ y2, x2 }, map);

	for (const auto& row : map) {
		for (int cell : row) {
			cout << cell;
		}
		cout << '\n';
	}

	return 0;
}