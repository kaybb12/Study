#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
#include <climits>

using namespace std;

using Matrix = vector<vector<int>>;
using Point = pair<int, int>;

struct Cals {
	int r, c, s;
};

void print_vec(Matrix& vec) {
	for (auto& ve : vec) {
		for (auto& v : ve) {
			cout << v << " ";
		}
		cout << "\n";
	}
}

void rotate_vec(int r, int c, int s, Matrix& Mat) {
	Point top = { r - s, c - s };
	Point bot = { r + s, c + s };

	Matrix Ch_vec = Mat;

	while (1) {
		for (int i = top.second; i <= bot.second; ++i) {
			int nc = i + 1;

			if (nc > bot.second)
				continue;

			Ch_vec[top.first][nc] = Mat[top.first][i];
		}

		//cout << "1\n";
		//print_vec(Ch_vec);

		for (int i = top.first; i <= bot.first; ++i) {
			int nr = i + 1;

			if (nr > bot.first)
				continue;

			Ch_vec[nr][bot.second] = Mat[i][bot.second];

		}

		//cout << "2\n";
		//print_vec(Ch_vec);

		for (int i = bot.second; i >= top.second; --i) {
			int nc = i - 1;

			if (nc < top.second)
				continue;

			Ch_vec[bot.first][nc] = Mat[bot.first][i];
		}

		//cout << "3\n";
		//print_vec(Ch_vec);

		for (int i = bot.first; i >= top.first; --i) {
			int nr = i - 1;

			if (nr < top.first)
				continue;

			Ch_vec[nr][top.second] = Mat[i][top.second];

		}

		//cout << "4\n";
		//print_vec(Ch_vec);

		Mat = Ch_vec;

		top = { top.first + 1, top.second + 1 };
		bot = { bot.first - 1, bot.second - 1 };

		if (top.first == bot.first && top.second == bot.second)
			break;
	}
}

int get_min_sum(const Matrix& Mat) {
	int min_sum = INT_MAX;
	for (int r = 1; r < Mat.size() - 1; ++r) {
		int temp = 0;
		for (int c = 1; c < Mat[r].size() - 1; ++c) {
			temp += Mat[r][c];
		}
		min_sum = min(temp, min_sum);
	}

	return min_sum;
}

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int T;
	cin >> T;
	for (int tc = 1; tc <= T; ++tc) {
		int n, m, k;
		cin >> n >> m >> k;

		Matrix Mat(n + 2, vector<int>(m + 2));
		for (int r = 1; r <= n; ++r) {
			for (int c = 1; c <= m; ++c) {
				cin >> Mat[r][c];
			}
		}
		//print_vec(Mat);
		vector<Cals> cals(k);
		vector<int> ords(k);
		for (int i = 0; i < k; ++i) {
			int r, c, s;
			cin >> r >> c >> s;
			cals[i] = { r, c, s };
			ords[i] = i;
		}

		vector<vector<int>> permutations;

		do {
			permutations.push_back(ords);
		} while (next_permutation(ords.begin(), ords.end()));

		int res = INT_MAX;
		for (int i = 0; i < permutations.size(); ++i) {
			Matrix temp_vec = Mat;
			for (int j = 0; j < permutations[i].size(); ++j) {
				Cals now = cals[permutations[i][j]];
				rotate_vec(now.r, now.c, now.s, temp_vec);
			}
			int temp = get_min_sum(temp_vec);
			res = min(res, temp);
		}

		cout << "#" << tc << " " << res << "\n";
	}

	return 0;
}