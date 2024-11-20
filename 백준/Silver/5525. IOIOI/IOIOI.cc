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

	int N, M;
	cin >> N >> M;

	string str;
	cin >> str;
	int res = 0;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == 'I') {
			int cnt = 0;
			for (int j = 0; j < (2 * N + 1) && i + j < str.size(); j++) {
				if (j % 2 == 0) {
					if (str[i + j] == 'I') {
						cnt++;
					}
				}
				else {
					if (str[i + j] == 'O') {
						cnt++;
					}
				}
			}
			if (cnt == 2 * N + 1) {
				res++;
			}
		}
	}
	cout << res;
	return 0;
}