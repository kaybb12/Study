#include <iostream>
#include <vector>
#include <array>
#include <map>

using namespace std;
using Point = pair<int, int>;

static array<Point, 4> dir = { {
	{ 1, 0 }, { -1, 0 }, { 0, -1 }, { 0, 1 }
} };

static constexpr int Up = 0;
static constexpr int Down = 1;
static constexpr int Left = 2;
static constexpr int Right = 3;
static constexpr int Alive = 1;
static constexpr int Dead = -1;

// 원자정보
struct Atom {
	int x;
	int y;
	int d;
	int e;
	int isalive;
};

int get_total_energy(vector<Atom>& atoms) {
	int n = atoms.size(); // 살아있는 갯수
	int res = 0;

	while (n > 0) {
		map<Point, int> Map;

		for (int i = 0; i < atoms.size(); ++i) {
			if (atoms[i].isalive == Dead) // 죽은애면 컨티뉴
				continue;

			int ny, nx;

			switch (atoms[i].d) // 방향 맞춰 다음좌표갱신
			{
			case Up:
				ny = atoms[i].y + dir[Up].first;
				nx = atoms[i].x + dir[Up].second;
				if (ny > 2000 || nx > 2000 ||
					ny < -2000 || nx < -2000) {
					atoms[i].isalive = Dead;
					--n;
					break;
				}
				atoms[i].y = ny;
				atoms[i].x = nx;
				Map[{ny, nx}] += 1;
				break;
			case Down:
				ny = atoms[i].y + dir[Down].first;
				nx = atoms[i].x + dir[Down].second;
				if (ny > 2000 || nx > 2000 ||
					ny < -2000 || nx < -2000) {
					atoms[i].isalive = Dead;
					--n;
					break;
				}
				atoms[i].y = ny;
				atoms[i].x = nx;
				Map[{ny, nx}] += 1;
				break;
			case Left:
				ny = atoms[i].y + dir[Left].first;
				nx = atoms[i].x + dir[Left].second;
				if (ny > 2000 || nx > 2000 ||
					ny < -2000 || nx < -2000) {
					atoms[i].isalive = Dead;
					--n;
					break;
				}
				atoms[i].y = ny;
				atoms[i].x = nx;
				Map[{ny, nx}] += 1;
				break;
			case Right:
				ny = atoms[i].y + dir[Right].first;
				nx = atoms[i].x + dir[Right].second;
				if (ny > 2000 || nx > 2000 ||
					ny < -2000 || nx < -2000) {
					atoms[i].isalive = Dead;
					--n;
					break;
				}
				atoms[i].y = ny;
				atoms[i].x = nx;
				Map[{ny, nx}] += 1;
				break;
			default:
				break;
			}
		}

		for (int i = 0; i < atoms.size(); ++i) {
			if (atoms[i].isalive == Dead)
				continue;

			int y = atoms[i].y;
			int x = atoms[i].x;

			if (Map[{y, x}] <= 1)
				continue;

			res += atoms[i].e;
			atoms[i].isalive = Dead;
			--n;
		}
	}

	return res;
}

int main() {
	int T;
	cin >> T;
	// input
	for (int tc = 1; tc <= T; ++tc) {
		int N;
		cin >> N;
		vector<Atom> atoms(N);
		for (int i = 0; i < atoms.size(); ++i) {
			int x, y, d, e;
			cin >> x >> y >> d >> e;
			// 0.5sec 처리 위해 *2
			atoms[i] = { x * 2, y * 2, d, e, Alive };
		}

		int ans = get_total_energy(atoms);

		std::cout << "#" << tc << " " << ans << "\n";
	}
	return 0;
}