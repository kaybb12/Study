#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int get_center_car(vector<int>& cars, vector<int>::iterator it) {
	int left = 0, right = 0;

	if (it != cars.begin() && it != cars.end()) {
		left = it - cars.begin();
		right = cars.end() - it - 1;
	}

	return left * right;
}

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int N, T;
	cin >> N >> T;
	vector<int> cars(N);

	for (int& c : cars)
		cin >> c;

	sort(cars.begin(), cars.end());

	for (int tc = 1; tc <= T; ++tc) {
		int target;
		cin >> target;

		int ans = 0;
		auto existed = lower_bound(cars.begin(), cars.end(), target);

		if (existed != cars.end() && *existed == target) {
			ans = get_center_car(cars, existed);
		}

		cout << "#" << tc << " " << ans << '\n';
	}

	return 0;
}