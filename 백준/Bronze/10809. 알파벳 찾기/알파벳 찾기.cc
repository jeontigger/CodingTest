#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <cmath>
#include <stack>

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

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string s;

	cin >> s;

	vector<int> position(26, -1);
	for (int i = 0; i < 26; i++) {
		auto iter = s.find(i + 'a');
		if (iter != string::npos) {
			cout << iter << " ";
		}
		else {
			cout << -1 << " ";
		}
	}



	return 0;
}