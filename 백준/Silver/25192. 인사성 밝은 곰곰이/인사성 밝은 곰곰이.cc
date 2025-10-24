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
#include <iomanip>
#include <cassert>
#include <cstring>
#include <list>

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
#define FOR(idx, limit) for(int idx = 0; idx < limit; idx++)

int N;
vector<string> names;

void Inputs() {
	cin >> N;
	names.resize(N);
	FOR(i, N) {
		cin >> names[i];
	}
}

void Solution() {
	int answer = 0;
	set<string> s;
	FOR(i, N) {
		auto name = names[i];

		if (name == "ENTER") {
			answer += s.size();
			s.clear();
		}
		else {
			s.insert(name);
		}
	}
	answer += s.size();

	cout << answer;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	int T = 1;
	//cin >> T;
	while (T--) {
		Inputs();
		Solution();
	}


	return 0;
}