#include <iostream>
#include <vector>
#include <array>
#include <queue>
#include <algorithm>

using namespace std;
using Point = pair<int, int>;
using Map = vector<vector<char>>;

static constexpr char GROUND = '(';
static constexpr char WATER = ')';

static array<Point, 4> dir = { {
	{ 1, 0 }, { -1, 0 }, { 0, 1 }, { 0, -1 }
} };

int get_fuel(const int a, const int b, const Map& map) {
	int max_fuel = 0;
	return max_fuel;
}

struct Edge {
	Point num;
	int cost;
};

int main() {
	int n, a, b;
	cin >> n >> a >> b;
	Map map(n, vector<char>(n));
	for (auto& r : map) {
		for (char& c : r)
			cin >> c;
	}

	int fuel = get_fuel(a, b, map);

	cout << fuel << "\n";
	
	return 0;
}