#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cmath>
#include <queue>

using namespace std;

using Matrix = vector<vector<int>>;

bool is_connected(const vector<int>& group, const Matrix& vilages) {
	if (group.empty())
		return true;

	vector<bool> visited(vilages.size());
	vector<int> stack;
	stack.emplace_back(group[0]);
	visited[group[0]] = true;

	while(!stack.empty()) {
		int cur = stack.back();
		stack.pop_back();

		for (int next : group) {
			if (!visited[next] && vilages[cur][next]) {
				visited[next] = true;
				stack.emplace_back(next);
			}
		}
	}

	return all_of(group.begin(), group.end(), [&](int i) {return visited[i]; });
}

int calculate_diffrence(const vector<int>& group_a, const vector<int> group_b, const vector<int>& pops) {
	int sum_a = 0, sum_b = 0;
	for (int i : group_a)
		sum_a += pops[i];
	for (int i : group_b)
		sum_b += pops[i];

	return abs(sum_a - sum_b);
}

void make_comb(int index, vector<int>& group_a, vector<int>& group_b, int& min_differ, const Matrix& vilages, const vector<int>& pops) {

	if (index == pops.size() - 1) {
		if (!group_a.empty() && !group_b.empty() &&
			is_connected(group_a, vilages) && is_connected(group_b, vilages)) {
			int differ = calculate_diffrence(group_a, group_b, pops);
			min_differ = min(min_differ, differ);
		}

		return;
	}

	group_a.emplace_back(index + 1);
	make_comb(index + 1, group_a, group_b, min_differ, vilages, pops);
	group_a.pop_back();

	group_b.emplace_back(index + 1);
	make_comb(index + 1, group_a, group_b, min_differ, vilages, pops);
	group_b.pop_back();
}

int get_populateion_difference(const Matrix& vilages, const vector<int>& pops) {
	int min_differ = INT_MAX;
	vector<int> group_a, group_b;

	make_comb(0, group_a, group_b, min_differ, vilages, pops);

	return min_differ;
}

int main() {
	int T;
	cin >> T;

	for (int tc = 1; tc <= T; ++tc) {
		int N;
		cin >> N;

		Matrix vilages(N + 1, vector<int>(N + 1));
		for (int i = 1; i <= N; ++i) {
			for (int j = 1; j <=N; ++j) {
				cin >> vilages[i][j];
			}
		}

		vector<int> pops(N + 1);
		for (int i = 1; i <= N; ++i) {
			cin >> pops[i];
		}

		int pop_difference = get_populateion_difference(vilages, pops);

		cout << "#" << tc << " " << pop_difference << "\n";
	}

	return 0;
}