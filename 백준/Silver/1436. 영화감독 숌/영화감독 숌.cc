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

bool IsDevilNum(int num) {

	int cnt = 3;
	while (num) {
		if (num % 10 == 6) {
			cnt--;
		}
		else {
			cnt = 3;
		}

		if (cnt == 0)return true;

		num /= 10;
	}

	return false;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	int num = 666;

	//cout << IsDevilNum(666);

	while (N) {
		if (IsDevilNum(num)) {
			N--;
		}
		num++;
	}

	cout << num - 1;

	return 0;
}
