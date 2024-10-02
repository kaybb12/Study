#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct Stat {
	int w;

	bool operator<(const Stat r) const {
		return w > r.w;
	}
};

int get_min_time(vector<int>& weights) {
	int time = 0;
	sort(weights.begin(), weights.end());
	priority_queue<Stat> pq;
	
	for (int i = 0; i < weights.size(); ++i) {
		pq.push({weights[i]});
	}

	while (!pq.empty()) {
		if (pq.size() == 1)
			break;
		int w1 = pq.top().w;
		pq.pop();
		int w2 = pq.top().w;
		pq.pop();
		int new_w = w1 + w2;
		time += new_w;
		pq.push({ new_w });
	}

	return time;
}

int main() {
	int n;
	cin >> n;
	vector<int> weights(n);
	for (int& w : weights) {
		cin >> w;
	}

	int res = get_min_time(weights);

	cout << res << "\n";

	return 0;
}