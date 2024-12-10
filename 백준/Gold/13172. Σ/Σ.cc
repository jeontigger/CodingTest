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

long long mod = 1'000'000'007;
//long long mod = 11;

long long GetPow(int face, int n) {
	if (n == 1)
		return face;

	long long res = 0;
	if (n % 2 == 0) {
		res = GetPow(face, n / 2);
		res = res * res;
	}
	else {
		res = GetPow(face, n - 1);
		res = res * face;
	}

	return res % mod;
}

long long GetFermatRev(int face) {
	long long res = 1;
	res = GetPow(face, mod - 2);
	return res;
}

long long CalFermat(int face, int sum) {
	long long rev = GetFermatRev(face);
	//cout << rev << '\n';
	return rev * sum % mod;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int M;
	cin >> M;

	vector<int> face(M);
	vector<int> sums(M);
	for (int i = 0; i < M; i++) {
		cin >> face[i] >> sums[i];
	}

	long long res = 0;
	for (int i = 0; i < M; i++) {
		res += CalFermat(face[i], sums[i]) % mod;
	}
	cout << res % mod;

	return 0;
}
