#include <iostream>
#include <vector>

using namespace std;
using Matrix = vector<vector<int>>;
/*
int Find(int A, vector<int>& parents) {
	if (A == parents[A])
		return A;
	return parents[A] = Find(parents[A], parents);
}

void Union(int A, int B, vector<int>& parents) {
	int rootA = Find(A, parents);
	int rootB = Find(B, parents);

	if (rootA == rootB)
		return;

	parents[rootB] = rootA;
}*/

void check_stable(const Matrix& mat) {
	int cnt = 0;
	vector<int> dat(mat.size() - 1);

	for (int i = 0; i < mat.size(); ++i) {
		for (int j = 0; j < mat[i].size(); ++j) {
			if (mat[i][j]) {
				++dat[j];
			}
		}
	}

	int de2 = -1;

	for (auto d : dat) {
		if (d > 2) {
			cout << "WARNING" << "\n";
			return;
		}
	}

	cout << "STABLE" << "\n";
}

int main() {
	int N;
	cin >> N;
	Matrix mat(N, vector<int>(N));

	for (int r = 0; r < N; ++r) {
		for (int c = 0; c < N; ++c) {
			cin >> mat[r][c];
		}
	}

	check_stable(mat);

	return 0;
}