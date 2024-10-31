#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <cmath>
#include <stack>
#include <unordered_map>

using namespace std;

#define INF (int)1e9

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

struct Data {
	int in;
	vector<int> outs;
};

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	vector<Data> students(N + 1);

	int left, right;
	for (int i = 0; i < M; i++) {
		cin >> left >> right;
		students[left].outs.push_back(right);
		students[right].in++;
	}

	queue<int> q;
	//vector<int> visited(N + 1);
	//visited[0] = true;
	for (int i = 1; i < students.size(); i++) {
		if (students[i].in == 0) {
			q.push(i);
			//visited[i] = true;
		}
	}

	while (!q.empty()) {
		int student = q.front();
		q.pop();

		cout << student << " ";

		for (int i = 0; i < students[student].outs.size(); i++) {
			int other = students[student].outs[i];
			students[other].in--;
			if (students[other].in == 0) {
				q.push(other);
			}
		}
	}

	return 0;
}