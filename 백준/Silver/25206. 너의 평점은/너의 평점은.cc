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

string subjects[20], grades[20];
double credits[20];
void Inputs() {
	for (int i = 0; i < 20; i++) {
		cin >> subjects[i] >> credits[i] >> grades[i];
	}
}

double GradeToScore(string grade) {
	double ret = 0;
	if (grade == "A+") {
		ret = 4.5;
	}
	else if (grade == "A0") {
		ret = 4.0;
	}
	else if (grade == "B+") {
		ret = 3.5;
	}
	else if (grade == "B0") {
		ret = 3.0;
	}
	else if (grade == "C+") {
		ret = 2.5;
	}
	else if (grade == "C0") {
		ret = 2.0;
	}
	else if (grade == "D+") {
		ret = 1.5;
	}
	else if (grade == "D0") {
		ret = 1.0;
	}
	else if (grade == "F") {
		ret = 0;
	}

	return ret;
}


void Solution() {
	double sum = 0;
	FOR(i, 20) {
		if (grades[i] != "P")
			sum += credits[i];
	}

	double total = 0;
	for (int i = 0; i < 20; i++) {
		if (grades[i] != "P")
			total += credits[i] * GradeToScore(grades[i]);
	}

	cout << total / sum;

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