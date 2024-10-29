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
	if (str == roots[str]) {
		return roots[str];
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
	if (nodes[s1] < nodes[s2]) {
		roots[s1] = s2;
		nodes[s2] += nodes[s1];
	}
	else {
		roots[s2] = s1;
		nodes[s1] += nodes[s2];
	}
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T, F;
	cin >> T;
	while (T) {
		T--;

		cin >> F;
		roots.clear();
		nodes.clear();
		for (int i = 0; i < F; i++) {
			string s1, s2;
			cin >> s1 >> s2;
			if (roots[s1] == "") {
				roots[s1] = s1;
				nodes[s1] = 1;
			}
			if (roots[s2] == "") {
				roots[s2] = s2;
				nodes[s2] = 1;
			}

			Union(s1, s2);
			cout << Count(s1) << endl;
		}
	}


	return 0;
}