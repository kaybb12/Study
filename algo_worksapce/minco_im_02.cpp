#include <iostream>
#include <vector>
#include <string>
#include <climits>
#include <algorithm>

using namespace std;

using Matrix = vector<vector<int>>;

int get_score_diffrence(const Matrix& scores, const vector<int>& answers) {
	int max_score = 0;
	int min_score = INT_MAX;

	for (const auto& sc : scores) {
		int temp_score = 0;
		int streaked = 0;
		for (int i = 0; i < sc.size(); ++i) {
			if (sc[i] != answers[i]) {
				streaked = 0;
			}
			else if (sc[i] == answers[i]) {
				++streaked;
			}
			temp_score += streaked;
		}
		max_score = max(max_score, temp_score);
		min_score = min(min_score, temp_score);
	}

	return max_score - min_score;
}

int main() {
	int T;
	cin >> T;

	for (int tc = 1; tc <= T; ++tc) {
		int N, M;
		cin >> N >> M;
		Matrix scores(N, vector<int>(M));
		vector<int> answers(M);

		for (int& a : answers) {
			cin >> a;
		}

		for (auto& sc : scores) {
			for (int& s : sc)
				cin >> s;
		}

		int score_diffrence = get_score_diffrence(scores, answers);
		cout << "#" << tc << " " << score_diffrence << "\n";
	}

	return 0;
}