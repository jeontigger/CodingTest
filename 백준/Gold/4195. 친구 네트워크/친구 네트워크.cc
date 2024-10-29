#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <cmath>
#include <stack>
#include <unordered_map>

using namespace std;

//#define INF 1e9

template<typename T>
void PrintVec(const vector<T>& v) {
	for (T i : v) {
		cout << i << " ";
	}
	cout << endl;
}

template<typename T>
void PrintVec(const vector<vector<T>>& vec) {
	for (auto& v : vec) {
		PrintVec(v);
	}
}

unordered_map<string, string> roots;
unordered_map<string, int> nodes;

string Find(string str) {
	if (roots.find(str) == roots.end()) {
		return str;
	}
	else {
		return roots[str] = Find(roots[str]);
	}
}

int Count(string str) {
	return nodes[Find(str)];
}

void Union(string s1, string s2) {
	s1 = Find(s1);
	s2 = Find(s2);

	if (s1 == s2) return;

	roots[s1] = s2;
	nodes[s2] += nodes[s1];
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T, F;
	string s1, s2;
	cin >> T;
	while (T) {
		T--;
		cin >> F;
		roots.clear();
		nodes.clear();
		for (int i = 0; i < F; i++) {
			cin >> s1 >> s2;
			if (!nodes[s1]) {
				nodes[s1] = 1;
			}
			if (!nodes[s2]) {
				nodes[s2] = 1;
			}

			Union(s1, s2);
			cout << Count(s1) << '\n';
		}
	}


	return 0;
}