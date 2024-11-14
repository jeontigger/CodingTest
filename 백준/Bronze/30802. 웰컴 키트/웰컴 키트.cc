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
	vector<int> people(6);
	for (int i = 0; i < people.size(); i++) {
		cin >> people[i];
	}

	int T, P;
	cin >> T >> P;

	int shirt = 0;
	for (int i = 0; i < people.size(); i++) {
		shirt += ceil((double)people[i] / T);
	}

	cout << shirt << '\n';

	int bundle = 0, mod = 0;
	bundle = N / P;
	mod = N % P;

	cout << bundle << " " << mod;


	return 0;
}

