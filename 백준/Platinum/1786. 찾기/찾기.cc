
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <cmath>
#include <stack>
#include <unordered_map>

using namespace std;

#define INF 1e9

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

vector<int> MakeTable(string s) {
	vector<int> table(s.size());

	int idx = 0;
	int j = 1;
	while (j < s.size()) {
		if (s[idx] == s[j]) {
			idx++;
			table[j] = idx;
			j++;
		}
		else if (idx > 0) {
			idx = table[idx - 1];
		}
		else {
			j++;
		}
	}
	return table;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string s, c;
	getline(cin, s);
	getline(cin, c);

	vector<int> table = MakeTable(c);

	int j = 0;

	vector<int> res;
	for (int i = 0; i < s.size(); i++) {
		while ((j > 0) && (s[i] != c[j])) {
			j = table[j - 1];
		}
		if (s[i] == c[j]) {
			if (j == c.size() - 1) {
				res.push_back(i - c.size() + 2);
				j = table[j];
			}
			else {
				j++;
			}
		}
	}
	//PrintVec(table);
	cout << res.size() << endl;
	for (int i : res) {
		cout << i << " ";
	}


	return 0;
}