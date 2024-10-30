#include <iostream>
#include <vector>
#include <algorithm>
#include <array>

using namespace std;

bool check_height(const int& max_h, vector<int>& temp) {
	for (auto& t : temp) {
		if (0 != t)
			return false;
	}

	return true;
}

int get_day(const int& max_h, vector<int>& tries) {
	int target = 0;
	int fin_day = 0;
	vector<int> temp;

	for (auto& tree : tries) {
		if (tree == max_h)
			continue;
		temp.emplace_back(max_h - tree);
	}

	if (check_height(max_h, tries) || temp.size() == 0) {
		return 0;
	}

	int day = 0;
	bool mool = false;

	while (1) {
		++day;

		if (day % 2 == 1) {
			for (int& t: temp) {
				if (t == 0)
					continue;
				if (t % 2 == 1) {
					t -= 1;
					mool = true;
					break;
				}
			}
		}

		else if (day % 2 == 0) {
			for (int& t : temp) {
				if (t == 0)
					continue;
				if (t < 2)
					continue;
				t -= 2;
				mool = true;
				break;
			}
		}

		if (check_height(max_h, temp))
			break;
		
		if (!mool) {
			for (int& t : temp) {
				if (t > 2) {
					t -= 1;
					break;
				}
			}
		}

		mool = false;
	}

	return day;
}

int main() {
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; ++tc) {
		int n;
		cin >> n;
		vector<int> tries(n);
		int max_h = 0;

		for (int i = 0; i < n; ++i) {
			cin >> tries[i];
			max_h = max(max_h, tries[i]);
		}
		
		int ans = get_day(max_h, tries);
		cout << "#" << tc << " " << ans << "\n";
	}

	return 0;
}