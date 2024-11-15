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

struct User {
	int age;
	int idx;
	string name;
};

bool cmp(const User& u1, const User& u2) {
	return u1.age == u2.age ? u1.idx < u2.idx : u1.age < u2.age;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	vector<User>users(N);
	for (int i = 0; i < N; i++) {
		cin >> users[i].age >> users[i].name;
		users[i].idx = i;
	}

	sort(users.begin(), users.end(), cmp);

	for (int i = 0; i < N; i++) {
		cout << users[i].age << " " << users[i].name << '\n';
	}


	return 0;
}