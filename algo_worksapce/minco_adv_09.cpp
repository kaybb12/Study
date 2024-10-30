#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int calculate_validity(int a, int b, int c, int d) {
	return (a + b) * (a + b) + (c + d) * (c + d);
}

int get_max_validity(const vector<int>& stations) {
	int max_val = 0;
	int N = stations.size();

	for (int i1 = 0; i1 < N; ++i1) {
		for (int j1 = i1 + 2; j1 < N; ++j1) {
			if (i1 == 0 && j1 == N - 1)
				continue;
			for (int i2 = 0; i2 < N; ++i2) {
				if (j1 == N - 1 && i2 == 0)
					continue;
				if (i2 == i1 || i2 == j1)
					continue;
				if (i2 == i1 - 1 || i2 == i1 + 1)
					continue;
				if (i2 == j1 - 1 || i2 == j1 + 1)
					continue;

				for (int j2 = i2 + 2; j2 < N; ++j2) {
					if (i2 == 0 && j2 == N - 1)
						continue;
					if (j2 == i1 || j2 == j1)
						continue;
					if (j2 == i1 - 1 || j2 == i1 + 1)
						continue;
					if (j2 == j1 - 1 || j2 == j1 + 1)
						continue;
					if (i1 > j2) {
						int temp_val = calculate_validity(stations[i1], stations[j1], stations[i2], stations[j2]);
						max_val = max(max_val, temp_val);
					}
					else if (i1 < i2 && j1 < j2)
						continue;
					else if (i1 > i2 && j1 > j2)
						continue;

					int temp_val = calculate_validity(stations[i1], stations[j1], stations[i2], stations[j2]);
					max_val = max(max_val, temp_val);
					//cout << i1 << " " << j1 << " " << i2 << " " << j2 << " : " << temp_val << "\n";
				}
			}
		}
	}

	return max_val;
}

int main() {
	int T;
	cin >> T;

	for (int tc = 1; tc <= T; ++tc) {
		int N;
		cin >> N;
		vector<int> stations(N);
		for (int& s : stations) {
			cin >> s;
		}

		int val = get_max_validity(stations);

		cout << "#" << tc << " " << val << "\n";
	}

	return 0;
}
