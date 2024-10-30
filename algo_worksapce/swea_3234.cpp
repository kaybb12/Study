#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
using ll = long long;

int sum_vec(vector<int>& vec) {
	int sum = 0;
	for (auto& v : vec) {
		sum += v;
	}
	return sum;
}

bool compare_sum(int left, int total) {
	return 2 * left >= total;
}

bool cmp(int a, int b) {
	return a > b;
}

ll factorial(int n) {
	long long result = 1;
	for (int i = 2; i <= n; ++i) {
		result *= i;
	}
	return result;
}

ll count_case(int n) {
	//cout << n << "! = " << temp << "\n";
	ll temp = 1;
	for (int i = 0; i < n; ++i) {
		temp *= 2;
	}
	return temp * factorial(n);
}

void dfs(int now, int left, int right, ll& res, int total, vector<int>& visited, vector<int>& weights) {
	if (now >= weights.size()) {
		res += 1;
		return;
	}


	if (compare_sum(left, total)) {
		int len = weights.size();
		res += count_case(len - now);
		return;
	}

	for (int i = 0; i < weights.size(); ++i) {
		if (visited[i] >= 1)
			continue;

		//left
		visited[i] = 1;
		dfs(now + 1, left + weights[i], right, res, total, visited, weights);
		visited[i] = 0;

		if (right + weights[i] > left)
			continue;

		//right
		visited[i] = 1;
		dfs(now + 1, left, right + weights[i], res, total, visited, weights);
		visited[i] = 0;
	}
}

ll get_case(vector<int>& weights, int total) {
	ll res = 0;
	int len = weights.size();

	vector<int> visited(len);
	dfs(0, 0, 0, res, total, visited, weights);

	return res;
}

int main() {
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; ++tc) {
		int N;
		cin >> N;
		vector<int> weights(N);
		int total = 0;
		for (int& w : weights) {
			cin >> w;
			total += w;
		}

		sort(weights.begin(), weights.end(), cmp);
		ll ans = get_case(weights, total);
		cout << "#" << tc << " " << ans << "\n";
	}

	return 0;
}