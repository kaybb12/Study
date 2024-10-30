#include <iostream>
#include <vector>
#include <queue>

using namespace std;
template<class T>
using MAP = vector<vector<T>>;
using Point = pair<int, int>;

static constexpr int ZZOL = 1;
static constexpr int PO = 2;
static constexpr int UP = 0;
static constexpr int DOWN = 1;
static constexpr int LEFT = 2;
static constexpr int RIGHT = 3;

vector<Point> get_point(const int& d, Point& now, MAP<int>& Map) {
	int n = Map.size();
	vector<Point> nexts;
	int r = now.first;
	int c = now.second;
	int jumped = 0;

	switch (d)
	{
	case UP:
		for (int i = r - 1; i >= 0; --i) {
			if (jumped == 2) {
				break;
			}
			if (jumped == 1) {
				nexts.emplace_back(i, c);
			}
			if (Map[i][c] == ZZOL) {
				++jumped;
			}
		}
		break;

	case DOWN:
		for (int i = r + 1; i < n; ++i) {
			if (jumped == 2) {
				break;
			}
			if (jumped == 1) {
				nexts.emplace_back(i, c);
			}
			if (Map[i][c] == ZZOL) {
				++jumped;
			}
		}
		break;

	case LEFT:
		for (int i = c - 1; i >= 0; --i) {
			if (jumped == 2)
				break;
			if (jumped == 1) {
				nexts.emplace_back(r, i);
			}
			if (Map[r][i] == ZZOL) {
				++jumped;
			}
		}
		break;

	case RIGHT:
		for (int i = c + 1; i < n; ++i) {
			if (jumped == 2) {
				break;
			}
			if (jumped == 1) {
				nexts.emplace_back(r, i);
			}
			if (Map[r][i] == ZZOL) {
				++jumped;
			}
		}
		break;

	default:
		break;
	}

	return nexts;
}

void dfs(Point& now, int cnt, int& score, MAP<int>& Map, MAP<bool>& visited) {
	if (cnt >= 3) {
		return;
	}
	//cout << now.first << " " << now.second << " " << cnt << " " << score << "\n";
	for (int d = 0; d < 4; ++d) {
		vector<Point> nexts = get_point(d, now, Map);
		for (auto np : nexts) {
			if (Map[np.first][np.second] == ZZOL) {
				if (!visited[np.first][np.second]) {
					score += 1;
					visited[np.first][np.second] = true;
					//cout << np.first << " " << np.second << "\n";
				}
				Map[np.first][np.second] = 0;
				dfs(np, cnt + 1, score, Map, visited);
				Map[np.first][np.second] = ZZOL;
			}
			else {
				dfs(np, cnt + 1, score, Map, visited);
			}
		}
	}

	return;
}

int get_zzol(Point& st, MAP<int>& Map) {
	int score = 0;
	// cnt가 3되면 종료
	// 현재 위치에서 이동가능한 위치 인지 파악
	// 이동 후 위치 갱신
	// 현재 위치에서 쫄을 먹을 수 있는 지 확인
	// 쫄 위치로 이동 후 위치 갱신
	// 확인, 이동, 갱신
	//score = bfs(st, Map);
	int n = Map.size();
	MAP<bool> visited(n, vector<bool>(n));
	dfs(st, 0, score, Map, visited);

	return score;
}

int main() {
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; ++tc) {
		int n;
		cin >> n;
		MAP<int> Map(n, vector<int>(n));
		Point st;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				cin >> Map[i][j];
				if (Map[i][j] == PO) {
					st = { i, j };
				}
			}
		}

		int ans = get_zzol(st, Map);
		cout << "#" << tc << " " << ans << "\n";
	}
}