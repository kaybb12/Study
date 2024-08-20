#include <iostream>
#include <vector>

using namespace std;

int parent[20];

int Find(int A) {
	if (A == parent[A])
		return A;

	int root = Find(parent[A]);
	parent[A] = root;
	
	return root;
}

/*
int Find(int A) {
	if (A == parent[A])
		return A;

	return parent[A] = Find(parent[A]);;
}
*/

void Union(int A, int B) {
	int rootA = Find(A);
	int rootB = Find(B);

	if (rootA == rootB)
		return;
	
	parent[rootB] = rootA;
}
/*
6 4
1 2
3 4
5 6
2 4
*/
int main() {
	int cntNode, cntQuery;
	cin >> cntNode >> cntQuery;

	for (int i = 0; i < 20; ++i) {
		parent[i] = i;
	}

	for (int i = 0; i < cntQuery; ++i) {
		int a, b;
		cin >> a >> b;
		Union(a, b);
	}

	return 0;
}