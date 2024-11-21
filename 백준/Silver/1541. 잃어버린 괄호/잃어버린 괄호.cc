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

int g_nrow[] = { 0, 1, 0, -1 };
int g_ncol[] = { 1, 0, -1, 0 };

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
	cin >> str;

	vector<int> nums;
	vector<char> ops;

	int start = 0;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '+' || str[i] == '-') {
			nums.push_back(stoi(str.substr(start, i - start)));
			ops.push_back(str[i]);
			start = i + 1;
		}
	}
	nums.push_back(stoi(str.substr(start)));


	bool minus = false;
	int sum = 0;
	for (int i = 0; i < nums.size(); i++) {
		if (!minus) {
			sum += nums[i];
		}
		else {
			sum -= nums[i];
		}

		if (i != nums.size() - 1 && ops[i] == '-') {
			minus = true;
		}
	}

	cout << sum;


	return 0;
}