#include <iostream>
#include <vector>

using namespace std;

int Find(int A, vector<int>& parents) {
	if (A == parents[A])
		return A;
	return parents[A] = Find(parents[A], parents);
}

bool is_group(int A, int B, vector<int>& parents) {
	return(Find(A, parents) == Find(B, parents));
}

void Union(int A, int B, vector<int>& parents) {
	int rootA = Find(A, parents);
	int rootB = Find(B, parents);

	if (rootA == rootB)
		return;

	parents[rootB] = rootA;
}

void get_order(vector<int>& parents) {
	int order, A, B;
	cin >> order >> A >> B;
	
	switch (order)
	{
	case 0:
		if (is_group(A, B, parents))
			cout << "YES" << "\n";
		else
			cout << "NO" << "\n";
		break;
	case 1:
		Union(A, B, parents);
		break;
	default:
		break;
	}
}

int main() {
	int N, Q;
	cin >> N >> Q;
	vector<int> parents(N + 1);
	for (int i = 1; i <= N; ++i) {
		parents[i] = i;
	}

	for (int i = 0; i < Q; ++i) {
		get_order(parents);
	}
}