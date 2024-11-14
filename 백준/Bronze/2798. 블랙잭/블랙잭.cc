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
	vector<int> cards(N);
	for (int i = 0; i < N; i++) {
		cin >> cards[i];
	}

	int curSum = 0;
	for (int i = 0; i < N; i++) {
		int a = cards[i];
		for (int j = i + 1; j < N; j++) {
			int b = cards[j];
			for (int k = j + 1; k < N; k++) {
				int c = cards[k];

				if ((a + b + c <= M) && (M - curSum > M - a - b - c)) {
					//cout << a + b + c << " " << a << " " << b << " " << c << endl;
					curSum = a + b + c;
				}

			}
		}
	}

	cout << curSum;


	return 0;
}

