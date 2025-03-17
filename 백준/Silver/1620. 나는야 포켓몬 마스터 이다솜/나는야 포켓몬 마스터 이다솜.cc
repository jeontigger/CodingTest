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

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	vector<string> vec(N);
	unordered_map<string, int> maps;

	string str;
	for (int i = 0; i < N; i++) {
		cin >> str;
		vec[i] = str;
		maps[str] = i;
	}

	for (int i = 0; i < M; i++) {
		cin >> str;
		if (isalpha(str[0])) {
			cout << maps[str] + 1 << '\n';
		}
		else {
			cout << vec[stoi(str) - 1] << '\n';
		}
	}


	return 0;
}
