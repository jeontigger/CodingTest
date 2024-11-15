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

int Fact(int r) {
	int res = 1;
	for (int i = 2; i <= r; i++) {
		res *= i;
	}
	return res;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string str;

	int num = 0;
	for (int i = 0; i < 3; i++) {
		cin >> str;
		if (str == "Fizz" || str == "Buzz" || str == "FizzBuzz") {
			continue;
		}

		num = stoi(str);

		num += 3 - i;
		break;
	}

	if (num % 3 == 0 && num % 5 == 0) {
		cout << "FizzBuzz";
	}
	else if (num % 3 == 0) {
		cout << "Fizz";
	}
	else if (num % 5 == 0) {
		cout << "Buzz";
	}
	else {
		cout << num;
	}

	//cout << num;


	return 0;
}