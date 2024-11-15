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

	int num = 666;
	while (N) {
		string str = to_string(num);

		int sixCnt = 0;
		for (int i = 0; i < str.size(); i++) {
			if (str[i] == '6') {
				sixCnt++;
			}
			else
				sixCnt = 0;
			if (sixCnt == 3) {
				N--;
				break;
			}
		}

		num++;
	}

	cout << num - 1;
	return 0;
}