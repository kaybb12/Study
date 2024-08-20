#include <iostream>
#include <vector>
#include <string>

using namespace std;

int Find(int a, vector<pair<int, int>>& countries) {
	if (a == countries[a].first)
		return a;

	return countries[a].first = Find(countries[a].first, countries);
}

void Union(int a, int b, vector<pair<int, int>>& countries) {
	int rootA = Find(countries[a].first, countries);
	int rootB = Find(countries[b].first, countries);

	if (rootA == rootB)
		return;

	countries[rootB].first = rootA;
	countries[rootA].second += countries[rootB].second;
}

void War(int num1, int num2, vector<pair<int, int>>& countries) {
	int c1 = Find(num1, countries);
	int c2 = Find(num2, countries);

	if (countries[c1].second > countries[c2].second) {
		for (auto& c : countries) {
			if (c.first == c2) {
				c.second = -1;
			}
		}
	}

	else if (countries[c1].second < countries[c2].second) {
		for (auto& c : countries) {
			if (c.first == c1) {
				c.second = -1;
			}
		}
	}

	else {
		for (auto& c : countries) {
			if (c.first == c2 || c.first == c1) {
				c.second = -1;
			}
		}
	}
}

int get_alive_countries(vector<pair<int, int>>& countries) {
	int cnt = 0;
	for (auto& c : countries) {
		if (c.second > 0)
			++cnt;
	}

	return cnt;
}

int main() {
	int N;
	cin >> N;

	vector<pair<int,int>> countries(N);
	for (int i = 0; i < countries.size(); ++i) {
		countries[i].first = i;
		cin >> countries[i].second;
	}

	int T;
	cin >> T;

	for (int tc = 0; tc < T; ++tc) {
		string order;
		char ch1, ch2;
		cin >> order >> ch1 >> ch2;

		int num1 = ch1 - 'A';
		int num2 = ch2 - 'A';

		if (order == "alliance") {
			Union(num1, num2, countries);
		}

		else if (order == "war") {
			War(num1, num2, countries);
		}
	}

	cout << get_alive_countries(countries) << "\n";

	return 0;
}