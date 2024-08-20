#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

using Map = vector<vector<int>>;

struct Stat {
	double power;
	int size;
	int idx;
};

void print(Map& map) {
	int N = map.size();

	cout << '\n';

	for (int r = 0; r < N; ++r) {
		for (int c = 0; c < N; ++c)
			cout << map[r][c] << " ";
		cout << '\n';
	}

	cout << "\n";
}

vector<int> find_starts_row(const Map& map, const int N) {
	vector<int> starts;
	for (int i = 0; i < map[0].size(); ++i) {
		if (map[0][i])
			starts.emplace_back(i);
	}

	return starts;
}

vector<int> find_starts_cal(const Map& map, const int N) {
	vector<int> starts;
	for (int i = 0; i < map.size(); ++i) {
		if (map[i][0])
			starts.emplace_back(i);
	}

	return starts;
}

double get_power_row(int c, int& idx, Map& map) {
	int pw = 0;

	for (int i = idx; i < map.size(); ++i) {
		if (map[i][c] == 0)
			break;
		++pw;
		++idx;
	}

	return pw;
}

inline bool is_strong(double pw1, double pw2) {
	return pw1 > pw2;
}

void rebuild_block_row(int st, Stat block, Map& map) {
	for (int i = 0; i <= block.idx - block.size; ++i) {
		map[i][st] = 0;
	}

	for (int i = block.idx - block.size + 1; i <= block.idx; ++i) {
		map[i][st] = 1;
	}
}

int get_bot_block(Map& map) {
	int N = map.size();
	vector<int> starts = find_starts_row(map, N);

	for (auto& st : starts) {
		Stat block;
		block.idx = 0;
		block.power = 0;
		block.size = 1;

		for (int r = 1; r < N; ++r) {
			if (map[r][st]) {
				int idx = r;
				block.power += block.size * pow(1.9, (r - 1 - block.idx));
				double pw = get_power_row(st, idx, map);

				if (is_strong(block.power, pw)) {
					block.idx = idx - 1;
					block.size += pw;
					r = idx - 1;
				}

				else {
					if (r == 1)
						break;
					block.idx = r;
					rebuild_block_row(st, block, map);
					break;
				}
			}

			if (r == N - 1 || r >= N) {
				r = N - 1;
				block.idx = r;
				rebuild_block_row(st, block, map);
				break;
			}
		}
	}

	int bot = 0;
	for (int c = 0; c < N; ++c) {
		if (map[N - 1][c])
			++bot;
	}

	return bot;
}

double get_power_cal(int r, int& idx, Map& map) {
	int pw = 0;

	for (int i = idx; i < map.size(); ++i) {
		if (map[r][i] == 0)
			break;
		++pw;
		++idx;
	}

	return pw;
}

void rebuild_block_cal(int st, Stat block, Map& map) {
	for (int i = 0; i <= block.idx - block.size; ++i) {
		map[st][i] = 0;
	}

	for (int i = block.idx - block.size + 1; i <= block.idx; ++i) {
		map[st][i] = 1;
	}
}

int get_top_block(Map& map) {
	int N = map.size();
	vector<int> starts = find_starts_cal(map, N);

	for (auto& st : starts) {
		Stat block;
		block.idx = 0;
		block.power = 0;
		block.size = 1;

		for (int c = 1; c < N; ++c) {
			if (map[st][c]) {
				int idx = c;
				block.power += block.size * pow(1.9, (c - 1 - block.idx));
				double pw = get_power_cal(st, idx, map);

				if (is_strong(block.power, pw)) {
					block.idx = idx - 1;
					block.size += pw;
					c = idx - 1;
				}
				else {
					if (c == 1)
						break;
					block.idx = c;
					rebuild_block_cal(st, block, map);
					break;
				}
			}

			if (c == N - 1 || c >= N - 1) {
				c = N - 1;
				block.idx = c;
				rebuild_block_cal(st, block, map);
				break;
			}
		}
	}

	int top = 0;
	for (int r = 0; r < N; ++r) {
		if (map[r][N - 1])
			++top;
	}

	return top;
}

void get_block(int& bot, int& top, Map& map, const int N) {
	//print(map);
	bot = get_bot_block(map);
	//print(map);
	top = get_top_block(map);
	//print(map);
}

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	// input
	int T;
	cin >> T;

	for (int tc = 1; tc <= T; ++tc) {
		
		int N;
		cin >> N;
		Map map(N, vector<int>(N));
		for (int r = 0; r < N; ++r) {
			for (int c = 0; c < N; ++c) {
				cin >> map[r][c];
			}
		}

		// solution
		int bot = 0, top = 0;

		get_block(bot, top, map, N);

		// output
		cout << "#" << tc << " " << bot << " " << top << "\n";
	}
}