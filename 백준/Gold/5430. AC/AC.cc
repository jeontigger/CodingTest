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

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;

	while (T--) {
		string str;
		cin >> str;
		int n;
		cin >> n;
		string strNums;
		cin >> strNums;
		deque<int>nums;
		istringstream iss(strNums.substr(1, strNums.size() - 2));
		string token;
		while (getline(iss, token, ',')) {
			nums.push_back(stoi(token));
		}


		bool rev = false;
		bool err = false;
		for (int i = 0; i < str.size(); i++) {
			if (str[i] == 'D') {
				if (nums.empty()) {
					err = true;
					break;
				}
				if (rev) {
					nums.pop_back();
				}
				else {
					nums.pop_front();
				}
			}
			else {
				rev = !rev;
			}
		}

		if (err) {
			cout << "error" << '\n';
		}
		else {
			if (rev) {
				reverse(nums.begin(), nums.end());
			}

			string res = "";
			res += '[';
			for (int i = 0; i < nums.size(); i++) {
				res += to_string(nums[i]);
				res += ',';
			}
			if (!nums.empty()) {
				res.pop_back();
			}
			res += "]\n";
			cout << res;
		}

	}

	return 0;
}