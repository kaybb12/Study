#include <unordered_map>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int main() {
	int n;
	cin >> n;

	// 1. 같은 ip4명 밴
	unordered_map<string, int> m1;
	// 2. 같은 ip3명 && 같은 언어 3명 밴
	unordered_map<string, unordered_map<string, int>> m2;
	// 3. 같은 ip2명 && 같은언어 2명 && 같은 점수 2명 밴
	unordered_map<string, unordered_map<string, unordered_map<int, int>>> m3;
	vector<string> ips;
	vector<string> languages;
	vector<int> scores;
	for (int i = 0; i < n; ++i) {
		string ip, lang;
		int sco;
		cin >> ip >> lang >> sco;

		if (lang == "C" || lang == "C++" || lang == "C#")
			lang = "C";

		m1[ip] += 1;
		m2[ip][lang] += 1;
		m3[ip][lang][sco] += 1;
	}

	int res = n;

	//검열
	for (auto& ip : m1) {
		// 조건 1
		int banned = 0;

		if (ip.second >= 4) {
			res -= ip.second;
			banned = 1;
		}
		// 조건 2
		if (ip.second == 3 && banned == 0) {
			for (auto& lang : m2[ip.first]) {
				if (lang.second >= 3) {
					res -= 3;
					banned = 1;
				}
			}
		}
		// 조건 3
		if (ip.second >= 2 && banned == 0) {
			for (auto& lang : m2[ip.first]) {
				for (auto& sco : m3[ip.first][lang.first]) {
					if (sco.second >= 2) {
						res -= 2;
					}
				}
			}
		}
	}

	cout << res << "\n";

	return 0;
}