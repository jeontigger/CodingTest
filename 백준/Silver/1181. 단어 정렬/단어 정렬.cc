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

bool cmp(const string& s1, const string& s2) {
	return s1.size() == s2.size() ? s1 < s2 : s1.size() < s2.size();
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	vector<string> words(N);
	for (int i = 0; i < N; i++) {
		cin >> words[i];
	}

	sort(words.begin(), words.end(), cmp);


	cout << words[0] << " ";
	for (int i = 1; i < N; i++) {
		if (words[i] != words[i - 1]) {
			cout << words[i] << " ";
		}
	}


	return 0;
}