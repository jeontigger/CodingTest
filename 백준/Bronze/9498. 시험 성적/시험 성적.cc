#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <cmath>
#include <stack>
#include <unordered_map>
#include <set>

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

	int N;
	cin >> N;
	if (N >= 90) {
		cout << "A";
	}
	else if (N >= 80) {
		cout << "B";
	}
	else if (N >= 70) {
		cout << "C";
	}
	else if (N >= 60) {
		cout << "D";
	}
	else {
		cout << "F";
	}


	return 0;
}

