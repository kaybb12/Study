#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int Find(int a, vector<int>& houses) {
	if (a == houses[a])
		return a;

	return houses[a] = Find(houses[a], houses);
}

void Union(int a, int b, vector<int>& houses) {
	int rootA = a;
	int rootB = b;

	if (rootA == rootB)
		return;

	houses[rootB] = rootA;
}

void make_houses(int idx, vector<int>& houses) {
	int N = houses.size();
	houses[idx] = idx;

	int left = idx - 1;
	int right = idx + 1;

	if (left >= 0) {
		if (houses[left] != -1) {
			Union(left, idx, houses);
		}
	}

	if (right < N) {
		if (houses[right] != -1) {
			Union(idx, right, houses);
		}
	}
	
}

pair<int,int> count_houses(vector<int>& houses) {
	int n = houses.size();
	vector<int> dat(n);

	for (int i = 0; i < n; ++i) {
		if (houses[i] != -1) {
			++dat[Find(i, houses)];
		}
	}

	int cnt_h = 0;
	int max_h = 0;

	for (auto& d : dat) {
		if (d > 0) {
			++cnt_h;
			max_h = max(max_h, d);
		}
	}

	return { cnt_h, max_h };
}

void print_houses_num(vector<int>& houses) {
	pair<int, int> nums = count_houses(houses);
	
	int cnt_h = nums.first;
	int max_h = nums.second;

	cout << cnt_h << " " << max_h << "\n";
}

int main() {
	int width, N;
	cin >> width >> N;

	vector<int> houses(width, -1);

	for (int n = 0; n < N; ++n) {
		int idx;
		cin >> idx;

		make_houses(idx, houses);

		print_houses_num(houses);
	}

	return 0;
}