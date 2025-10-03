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

int N;
vector<int> nums;

void Inputs() {
	while (true) {
		int num;
		cin >> num;
		if (num == -1) break;

		nums.push_back(num);
	}
	N = nums.size();
}

vector<int> GetDivisor(int num) {
	vector<int> ret;
	for (int i = 1; i <= num; i++) {
		if (num % i == 0) {
			ret.push_back(i);
		}
	}
	return ret;
}

bool IsPerfectNum(int num, const vector<int>& divs) {
	int sum = 0;
	for (int i : divs) {
		sum += i;
	}
	return sum == num;
}

void Solution() {
	for (int i = 0; i < N; i++) {
		auto divs = GetDivisor(nums[i]);
		divs.pop_back();
		if (IsPerfectNum(nums[i], divs)) {
			cout << nums[i] << " = ";
			for (int j = 0; j < divs.size(); j++) {
				cout << divs[j];
				if (j != divs.size() - 1) {
					cout << " + ";
				}
			}
			cout << '\n';
		}
		else {
			cout << nums[i] << " is NOT perfect.\n";
		}

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