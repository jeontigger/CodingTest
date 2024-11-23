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

long long A, B, C;
unordered_map<long long, long long>m;

long long Multiplication(long long cnt) {
	if (cnt == 1) {
		return A;
	}
	if (m[cnt] != 0) {
		return m[cnt];
	}

	long long l = Multiplication(cnt / 2);
	long long r = Multiplication(cnt - cnt / 2);

	m[cnt] = (l * r) % C;

	return m[cnt];
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> A >> B >> C;

	long long res = 1;

	cout << Multiplication(B) % C;

	return 0;
}