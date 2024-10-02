#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int get_min_cal(int a, int b) {
	int cnt = 0;
	while (b > a) {
		if (b % 10 == 1)
			b /= 10;
		else
			b /= 2;

		cnt++;
		
		if (a == b)
			return cnt;
	}

	return -1;
}

int main() {
	int a, b;
	cin >> a >> b;

	int res = get_min_cal(a, b);

	cout << res << "\n";

	return 0;
}