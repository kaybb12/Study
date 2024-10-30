#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;


void dfs(string nums, int cnt, int& max_v, vector<bool>& visited) {
	if (cnt == 0) {
		max_v = max(max_v, stoi(nums));
		return;
	}

	if (visited[stoi(nums)] > 0)
		return;

	visited[stoi(nums)] = 1;

	for (int i = 0; i < nums.size(); ++i) {
		for (int j = i + 1; j < nums.size(); ++j) {
			swap(nums[i], nums[j]);
			dfs(nums, cnt - 1, max_v, visited);
			swap(nums[i], nums[j]);
		}
	}
}

int get_max(string nums, int cnt) {
	int max_v = 0;
	vector<bool> visited(1000000);
	dfs(nums, cnt, max_v, visited);

	return max_v;
}

int main() {
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; ++tc) {
		string num;
		int cnt;
		cin >> num >> cnt;

		int ans = get_max(num, cnt);
		cout << "#" << tc << " " << "\n";
	}

	return 0;
}