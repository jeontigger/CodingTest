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
	cout.tie(NULL);

	unordered_map<string, string> passwordTable;
	int N, M;
	cin >> N >> M;

	string site, password;
	for (int i = 0; i < N; i++) {
		cin >> site >> password;
		passwordTable[site] = password;
	}

	for (int i = 0; i < M; i++) {
		cin >> site;
		cout << passwordTable[site] << ' ';
	}


	return 0;
}