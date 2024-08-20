#include <iostream>
#include <vector>

using namespace std;

int Find(int a, vector<int>& parents) {
	if (a == parents[a])
		return a;

	return parents[a] = Find(parents[a], parents);
}

void Union(int a, int b, vector<int>& parents) {
	int rootA = parents[a];
	int rootB = parents[b];

	if (rootA == rootB)
		return;

	parents[rootB] = rootA;
}

int count_team(vector<int>& parents, vector<int>& dat) {
	int cnt = 0;
	vector<int> team_dat(26);

	for (int i = 0; i < parents.size(); ++i) {
		if (dat[i] > 0) {
			++team_dat[Find(i, parents)];
		}
	}

	for (int i = 0; i < team_dat.size(); ++i) {
		if (team_dat[i] > 0)
			++cnt;
	}

	return cnt;
}

int count_solo(vector<int>& dat) {
	int cnt = 0;
	for (auto d : dat) {
		if (d > 0)
			++cnt;
	}

	return 26 - cnt;
}

int main() {
	int N;
	cin >> N;

	vector<int> parents(26);
	for (int i = 0; i < parents.size(); ++i) {
		parents[i] = i;
	}

	vector<int> dat(26);

	for (int i = 0; i < N; ++i) {
		char ch1, ch2;
		cin >> ch1 >> ch2;
		int num1 = ch1 - 'A';
		int num2 = ch2 - 'A';
		++dat[num1];
		++dat[num2];
		Union(num1, num2, parents);
	}

	cout << count_team(parents, dat) << "\n";
	cout << count_solo(dat) << "\n";

	return 0;
}