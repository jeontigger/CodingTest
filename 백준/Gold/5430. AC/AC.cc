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

void Execute(deque<int>& nums, const string& command) {
	bool rev = false;

	for (int i = 0; i < command.size(); i++) {
		if (command[i] == 'R') {
			rev = !rev;
		}

		if (command[i] == 'D') {
			if (nums.empty()) {
				cout << "error\n";
				return;
			}

			if (rev) {
				nums.pop_back();
			}
			else {
				nums.pop_front();
			}
		}
	}

	if (rev) {
		reverse(nums.begin(), nums.end());
	}

	cout << '[';
	if (nums.size() > 0) {
		cout << nums[0];
	}
	for (int i = 1; i < nums.size(); i++) {
		cout << ',' << nums[i];
	}
	cout << "]\n";
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;
	while (T--) {
		string command;
		cin >> command;

		int n;
		cin >> n;

		string s;
		cin >> s;

		deque<int> nums;
		istringstream iss(s.substr(1, s.size() - 2));

		while (getline(iss, s, ',')) {
			nums.push_back(stoi(s));
		}

		Execute(nums, command);
	}
	return 0;
}