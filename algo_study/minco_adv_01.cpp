#include <iostream>
#include <array>
#include <vector>
#include <queue>
#include <climits>

using namespace std;
template <class T>
using MAP = vector<vector<T>>;
using Point = pair<int, int>;

static array<Point, 4> dir = { {
	{0, 1}, {1, 0}, {0, -1}, {-1, 0}
} };

// 좌회전 갯수 구하기
// 좌회전 한번은 우회전 3번 이걸로 갱신할 예정
int get_rotation_count(int& next, int& now) {

	// 우회전 1
	if (now - next == 1)
		return 3;
	// 좌회전 
	if (next > now)
		return next - now;

	if (next < now) {
		if (now == 3 && next == 0)
			return 1;
		return now - next;
	}

	// 직진
	return 0;
}

struct Stat {
	Point now;
	int d;
	int cost;
	bool operator<(Stat r)const {
		return cost > r.cost;
	}
};

int bfs(Point& st, Point& fin, int& target, int& std, const MAP<int>& Map) {
	int n = Map.size();
	priority_queue<Stat> pq;
	MAP<bool> visited(n, vector<bool>(n));
	MAP<int> dist(n, vector<int>(n, INT_MAX));
	pq.push({ st, std, 0 });
	//visited[st.first][st.second] = true;
	dist[st.first][st.second] = 0;
	//cout << target << "\n";

	while (!pq.empty()) {
		Stat current = pq.top();
		pq.pop();
		int r = current.now.first;
		int c = current.now.second;
		//cout << r << " " << c << " 방향: " << current.d << " 누적횟수: " << dist[r][c] << "\n";

		if (dist[r][c] < current.cost)
			continue;

		if (r == fin.first && c == fin.second) {
			std = current.d;
			return dist[r][c];
		}

		for (int i = 0; i < dir.size(); ++i) {
			int nr = r + dir[i].first;
			int nc = c + dir[i].second;

			if (nr < 0 || nc < 0 ||
				nr >= n || nc >= n)
				continue;

			// 방문 여부
			/*
			if (visited[nr][nc])
				continue;*/

			int nd = i;
			int ncnt = dist[r][c] + get_rotation_count(nd, current.d);

			if (dist[nr][nc] <= ncnt)
				continue;

			dist[nr][nc] = ncnt;
			//visited[nr][nc] = true;
			pq.push({ { nr, nc }, nd, ncnt });
		}
	}

	return -1;
}

// 솔루션 함수
int get_rotation(const vector<Point>& apples, const MAP<int>& Map) {
	// 출발점, 도착점 for문에서 돌면서 각 사과번호 bfs 돌면서 우회전 횟수 합산해서 결과 구할거임
	int cnt = 0;
	Point st = { 0, 0 };

	// 방향 변수 하나잡고 가면서 갱신
	int d = 0;

	for (int i = 1; i < apples.size(); ++i) {
		Point fin = apples[i];
		cnt += bfs(st, fin, i, d, Map);
		st = fin;
	}

	return cnt;
}

int main() {
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; ++tc) {
		// input
		int n;
		cin >> n;
		int apple_cnt = 0;
		MAP<int> Map(n, vector<int>(n));

		// 맵정보 저장하면서 사과개수 카운팅
		for (int r = 0; r < n; ++r) {
			for (int c = 0; c < n; ++c) {
				cin >> Map[r][c];
				if (Map[r][c] > 0)
					++apple_cnt;
			}
		}

		// 사과위치랑 사과번호 apples에 저장
		vector<Point> apples(apple_cnt + 1);
		for (int r = 0; r < n; ++r) {
			for (int c = 0; c < n; ++c) {
				if (Map[r][c] > 0)
					apples[Map[r][c]] = { r, c };
			}
		}

		// 회전횟수 구하기
		int ans = get_rotation(apples, Map);

		// 출력
		cout << "#" << tc << " " << ans << "\n";
	}

	return 0;
}
