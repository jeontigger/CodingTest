#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <cmath>
#include <stack>

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

int g_nrow[] = { 0, 1, 0, -1 };
int g_ncol[] = { 1, 0, -1, 0 };

int GetMinValue(string s) {

	vector<int> nums;
	vector<char> op;
	int left = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '+' || s[i] == '-') {
			nums.push_back(stoi(s.substr(left, i - left)));
			op.push_back(s[i]);
			left = i + 1;
		}
	}
	nums.push_back(stoi(s.substr(left)));

	int sum = nums[0];
	bool minus = false;
	for (int i = 0; i < op.size(); i++) {
		if (op[i] == '-') {
			//if (minus) {
			//	sum -= nums[i + 1];
			//}
			//else {
			//	sum += nums[i + 1];
			//}
			minus = true;
		}
		else {
		}

		minus ? sum -= nums[i + 1] : sum += nums[i + 1];

	}

	return sum;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string s;
	cin >> s;

	cout << GetMinValue(s);


	return 0;
}