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

int N, M;
vector<string> words;

void Inputs() {
	cin >> N >> M;

	FOR(i, N) {
		string str;
		cin >> str;
		if (str.size() >= M) {
			words.push_back(str);
		}
	}
}

struct Data {
	string word;
	int cnt;
};

struct cmp {
	bool operator()(const Data& d1, const Data& d2) {
		if (d1.cnt != d2.cnt) {
			return d1.cnt > d2.cnt;
		}
		else if (d1.word.size() != d2.word.size()) {
			return d1.word.size() > d2.word.size();
		}
		else {
			return d1.word < d2.word;
		}
	}
};

void Solution() {
	vector <Data> datas;
	unordered_map<string, int> freq;
	FOR(i, words.size()) {
		freq[words[i]]++;
	}

	for (auto iter = freq.begin(); iter != freq.end(); ++iter) {
		datas.push_back({ iter->first, iter->second });
	}

	sort(datas.begin(), datas.end(), cmp());

	FOR(i, datas.size()) {
		cout << datas[i].word << '\n';
	}


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