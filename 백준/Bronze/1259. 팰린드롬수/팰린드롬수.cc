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

	string str;
	while (true) {
		cin >> str;
		if (str == "0") break;

		bool pallin = true;
		for (int i = 0; i < str.size() / 2; i++) {
			if (str[i] != str[str.size() - 1 - i]) {
				pallin = false;
				break;
			}
		}
		if (pallin) {
			cout << "yes" << " ";
		}
		else {
			cout << "no" << " ";
		}
	}


	return 0;
}

