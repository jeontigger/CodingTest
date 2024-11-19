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

	vector<int> fibonacci(41);
	fibonacci[0] = 0;
	fibonacci[1] = 1;

	for (int i = 2; i < fibonacci.size(); i++) {
		fibonacci[i] = fibonacci[i - 1] + fibonacci[i - 2];
	}

	//PrintVec(fibonacci);

	int T;
	cin >> T;
	while (T--) {
		int N;
		cin >> N;
		if (N == 0) {
			cout << 1 << ' ' << 0 << ' ';
		}
		else {
			cout << fibonacci[N - 1] << ' ' << fibonacci[N] << ' ';
		}
	}



	return 0;
}