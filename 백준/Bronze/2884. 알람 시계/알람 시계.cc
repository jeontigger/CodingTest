#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <cmath>
#include <stack>
#include <unordered_map>
#include <set>

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

int HtoM(int H) {
	return H * 60;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int H, M;
	cin >> H >> M;

	int day = HtoM(H) + M + 60 * 24;

	//cout << day << endl;

	day = (day - 45) % (60 * 24);

	//cout << day << endl;

	M = day % 60;
	H = day / 60;

	cout << H << " " << M;




	return 0;
}