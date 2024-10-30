#include <iostream>
#include <array>
#include <queue>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

using Map = vector<vector<int>>;
using Point = pair<int, int>;

static constexpr int WALL = -1;
static const array<Point, 4> dir = { {
	{ 0, 1 }, { 0, -1 }, { 1, 0 }, { -1, 0 } 
} };

//pq status
struct Edge {
	Point num;
	int cost;
	bool operator < (Edge right)const {
		if (cost > right.cost)
			return true;
		if (cost < right.cost)
			return false;
		return false;
	}
};

inline bool cmp(int a, int b) {
	return a > b;
}

//djikstra
int djikstra(const Point& start, const Map& map) {
	int N = map.size();
	Map dist(N, vector<int>(N, INT_MAX));
	priority_queue<Edge> pq;
	pq.push({ start, 0 });
	dist[start.first][start.second] = map[start.first][start.second];

	while (!pq.empty()) {
		Edge now = pq.top();
		pq.pop();

		int r = now.num.first;
		int c = now.num.second;
		
		if (dist[r][c] < now.cost)
			continue;

		for (const auto& d : dir) {
			int nr = r + d.first;
			int nc = c + d.second;

			if (nr < 0 || nc < 0 ||
				nr >= N || nc >= N)
				continue;
			
			if (map[nr][nc] == WALL)
				continue;
			
			int pay = map[nr][nc];
			int next_cost = dist[r][c] + pay;

			if (dist[nr][nc] <= next_cost)
				continue;

			dist[nr][nc] = next_cost;
			pq.push({ {nr, nc}, next_cost });
		}
	}

	int cost = INT_MIN;
	for (auto& vec : dist) {
		sort(vec.begin(), vec.end(), cmp);
		int temp = 0;
		for (int i = 0; i < vec.size(); ++i) {
			if (vec[i] >= INT_MAX)
				continue;
			else {
				temp = vec[i];
				break;
			}
		}
		cost = max(temp, cost);
	}

	return cost;
}

//solve
int get_max_cost(const Point& start, const Map& map) {
	int cost = djikstra(start, map);
	return cost;
}

int main() {
	//input
	Point start;
	cin >> start.first >> start.second;
	int N;
	cin >> N;
	Map map(N, vector<int>(N, -1));
	for (auto& r : map) {
		for (int& c : r)
			cin >> c;
	}

	//solution
	int cost = get_max_cost(start, map);

	//output
	cout << cost << "\n";

	return 0;
}