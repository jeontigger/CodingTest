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

	int N;
	cin >> N;
	string str;
	cin >> str;

	long long sum = 0;
	vector<long long> pows(50);
	pows[0] = 1;
	for (int i = 1; i < 50; i++) {
		pows[i] = (pows[i - 1] * (long long)31) % 1234567891;
	}



	for (int i = 0; i < str.size(); i++) {
		sum += ((str[i] - 'a' + 1) * pows[i]) % 1234567891;
	}

	cout << sum % 1234567891;

	return 0;
}

