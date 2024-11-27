#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <cmath>
#include <stack>
#include <unordered_map>
#include <set>
#include <sstream>

using namespace std;

#define INF 1e9

template<typename T>
void PrintVec(const vector<T>& v) {
	for (T i : v) {
		cout << i << " ";
	}
	cout << '\n';
}

template<typename T>
void PrintVec(const vector<vector<T>>& vec) {
	for (auto& v : vec) {
		PrintVec(v);
	}
}

vector<vector<char>> edges;

void Print(char curNode, int type) {

	if (type == 1)
		cout << curNode;

	if (edges[curNode][0] != '.')
		Print(edges[curNode][0], type);

	if (type == 2)
		cout << curNode;

	if (edges[curNode][1] != '.')
		Print(edges[curNode][1], type);

	if (type == 3)
		cout << curNode;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	edges.resize(128);
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		char v1, v2, v3;
		cin >> v1 >> v2 >> v3;
		edges[v1].push_back(v2);
		edges[v1].push_back(v3);
	}

	Print('A', 1);
	cout << '\n';
	Print('A', 2);
	cout << '\n';
	Print('A', 3);
	cout << '\n';



	return 0;
}