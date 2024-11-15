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
	while (getline(cin, str)) {
		if (str == ".") break;
		bool complete = true;
		stack<char>s;

		for (int i = 0; i < str.size(); i++) {
			if (str[i] == '(') {
				s.push(str[i]);
			}
			else if (str[i] == ')') {
				if (!s.empty() && s.top() == '(') {
					s.pop();
				}
				else {
					complete = false;
					break;
				}
			}

			if (str[i] == '[') {
				s.push(str[i]);
			}
			else if (str[i] == ']') {
				if (!s.empty() && s.top() == '[') {
					s.pop();
				}
				else {
					complete = false;
					break;
				}
			}
		}

		if (s.size() != 0)
			complete = false;

		if (complete) {
			cout << "yes ";
		}
		else {
			cout << "no ";
		}
	}


	return 0;
}