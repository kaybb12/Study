#include <iostream>
#include <array>
#include <vector>
#include <algorithm>
/*
1
20 3
2 2 3 2 2 2 2 3 3 4 4 3 2 2 3 3 3 2 2 3
4 4 1 4 4 1 4 4 1 1 1 4 1 4 3 3 3 3 3 3
4 4 1 100
7 10 3 40
6 3 2 70
*/
using namespace std;

using Point = pair<int, int>;
using Map = vector<vector<int>>;

struct AP {
	int y;
	int x;
	int C1;
	int P1;
};

static array<Point, 5> dir = { {
	{ 0, 0 }, { -1, 0 }, { 0, 1 }, { 1, 0 }, { 0, -1 }
} };

int check(int bcnum, int y, int x, const vector<AP>& BCs) {
	//bc 확인
	int bcy = BCs[bcnum].y;
	int bcx = BCs[bcnum].x;
	int c = BCs[bcnum].C1;
	int p = BCs[bcnum].P1;

	//범위계산
	int dist = abs(y - bcy) + abs(x - bcx);

	//범위안에 들어왔다면 충전
	if (dist <= c)
		return p;

	return 0;
}

int calc(int ay, int ax, int by, int bx, const vector<AP>& BCs) {
	int A = BCs.size();
	int max_charge = -1;

	for (int a_cnt = 0; a_cnt < A; ++a_cnt) {
		for (int b_cnt = 0; b_cnt < A; ++b_cnt) {
			int sum_charge = 0;
			int Acharge = check(a_cnt, ay, ax, BCs);
			int Bcharge = check(b_cnt, by, bx, BCs);

			//dif
			if (a_cnt != b_cnt)
				sum_charge = Acharge + Bcharge;

			else {
				sum_charge = max(Acharge, Bcharge);
			}

			max_charge = max(max_charge, sum_charge);

			//cout << a_cnt << " " << b_cnt << " : "<< max_charge << "\n";
		}
	}
	//cout << max_charge << " ";

	return max_charge;
}

int get_max_charge_sum(const vector<int>& A_movings, const vector<int>& B_movings, const vector<AP>& BCs) {
	int time = A_movings.size();
	int ay = 1, ax = 1;
	int by = 10, bx = 10;
	int ans = 0;

	for (int t = 0; t <= time; ++t) {
		//계산하는 코드
		ans += calc(ay, ax, by, bx, BCs);

		//이동하는 코드
		Point move_a = dir[A_movings[t % time]];
		Point move_b = dir[B_movings[t % time]];
		ay += move_a.first;
		ax += move_a.second;
		by += move_b.first;
		bx += move_b.second;

		//cout << t << " " << ans << "\n";
	}

	return ans;
}

int main() {
	//input
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; ++tc) {
		int num_move, cnt_BC;
		cin >> num_move >> cnt_BC;
		vector<int> A_movings(num_move), B_movings(num_move);
		for (int& a : A_movings)
			cin >> a;
		for (int& b : B_movings)
			cin >> b;
		vector<AP> BCs;
		for (int i = 0; i < cnt_BC; ++i) {
			int r, c, C1, P1;
			cin >> c >> r >> C1 >> P1;
			BCs.push_back({ r, c, C1, P1 });
		}

		//solution
		int charge_sum = get_max_charge_sum(A_movings, B_movings, BCs);

		//output
		cout << "#" << tc << " " << charge_sum << "\n";
	}
}