#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <array>
#include <climits>

using namespace std;
using Map = vector<vector<int>>;
using Point = pair<int, int>;

static constexpr int HOME = 1;
static array <Point, 4> dir = { {
	{ 1, 0 }, { -1, 0 }, { 0, 1 }, { 0, -1 }
} };

inline int get_cost(int k) {
	return (k * k + ((k - 1) * (k - 1)));
}

inline int get_revenue(int k, int homecnt, int rev) {
	return homecnt * rev - get_cost(k);
}

int bfs(Point st, const int& rev, Map& map) {
	//1. queue
	queue<Point> q;
	q.emplace(st);
	//2. visited
	Map visited(map.size(), vector<int>(map.size()));
	visited[st.first][st.second] = true;
	//3.setting
	int cnt = 0;
	int k = 1;
	int temp = 0;

	if (map[st.first][st.second] == HOME) {
		++cnt;
	}

	if (get_revenue(k, cnt, rev) >= 0) {
		temp = cnt;
	}

	//4.bfs
	while (!q.empty()) {
		++k;
		int cur_size = q.size();

		for (int i = 0; i < cur_size; ++i) {
			int r = q.front().first;
			int c = q.front().second;
			q.pop();

			for (const auto& d : dir) {
				int nr = r + d.first;
				int nc = c + d.second;

				if (nr < 0 || nc < 0 ||
					nr >= map.size() || nc >= map.size())
					continue;

				if (visited[nr][nc] == 1)
					continue;

				if (map[nr][nc] == HOME)
					++cnt;

				visited[nr][nc] = 1;
				q.emplace(nr, nc);
			}
		}

		if (get_revenue(k, cnt, rev) >= 0 && cnt > temp)
			temp = cnt;
	}

	return temp;
}

int count_home(const vector<Point>& starts, const int revenue, Map& map) {
	//맵의 모든 좌표애서 bfs돌려보고
	//그중에 최대값이 정답.
	int max_home = 0;

	for (int i = 0; i < map.size(); ++i) {
		for (int j = 0; j < map.size(); ++j) {
			int home = bfs({i, j}, revenue, map);
			max_home = max(max_home, home);
		//cout << max_area << "\n";
		}
	}

	return  max_home;
}

int main() {
	int T;
	/*
	   아래의 freopen 함수는 input.txt 를 read only 형식으로 연 후,
	   앞으로 표준 입력(키보드) 대신 input.txt 파일로부터 읽어오겠다는 의미의 코드입니다.
	   //여러분이 작성한 코드를 테스트 할 때, 편의를 위해서 input.txt에 입력을 저장한 후,
	   freopen 함수를 이용하면 이후 cin 을 수행할 때 표준 입력 대신 파일로부터 입력을 받아올 수 있습니다.
	   따라서 테스트를 수행할 때에는 아래 주석을 지우고 이 함수를 사용하셔도 좋습니다.
	   freopen 함수를 사용하기 위해서는 #include <cstdio>, 혹은 #include <stdio.h> 가 필요합니다.
	   단, 채점을 위해 코드를 제출하실 때에는 반드시 freopen 함수를 지우거나 주석 처리 하셔야 합니다.
	*/
	//freopen("input.txt", "r", stdin);
	cin >> T;
	/*
	   여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
	*/
	for (int test_case = 1; test_case <= T; ++test_case)
	{
		int N; // 맵크기 
		int M; // 집당 수익
		cin >> N >> M;
		Map map(N, vector<int>(N));
		vector<Point> starts;
		for (int i = 0; i < map.size(); ++i) {
			for (int j = 0; j < map.size(); ++j) {
				cin >> map[i][j];
				if (map[i][j] == 1)
					starts.emplace_back(i, j);
			}
		}

		cout << "#" << test_case << " " << count_home(starts, M, map) << "\n";
	}

	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}