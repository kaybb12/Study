#include <iostream>
#include <vector>

using namespace std;

bool is_pass_code(const vector<int>& samples, const vector<int>& passes) {

	int pass_idx = 0;
	for (int i = 0; i < samples.size(); ++i) {
		if (samples[i] == passes[pass_idx]) {
			++pass_idx;
			if (pass_idx == passes.size())
				break;
		}
	}

	if (pass_idx == passes.size())
		return true;
	else
		return false;
}

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int T;
	cin >> T;

	for (int tc = 1; tc <= T; ++tc) {
		int N, K;
		cin >> N >> K;

		vector<int> samples(N);
		vector<int> passes(K);

		for (int& s : samples)
			cin >> s;
		for (int& p : passes)
			cin >> p;

		bool passed = is_pass_code(samples, passes);

		if (passed)
			cout << "#" << tc << " 1" << "\n";
		else
			cout << "#" << tc << " 0" << "\n";
	}

	return 0;
}