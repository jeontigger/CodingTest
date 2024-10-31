

#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <cmath>
#include <stack>
#include <unordered_map>

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

	vector<Data>problems(N + 1);
	//for (int i = 1; i < N + 1; i++) {
	//	problems[i].in = i - 1;
	//	for (int j = i + 1; j < N + 1; j++) {
	//		problems[i].outs.push_back(j);
	//	}
	//}

	int g, d;
	for (int i = 0; i < M; i++) {
		cin >> g >> d;
		problems[g].outs.push_back(d);
		problems[d].in++;
	}

	priority_queue<int, vector<int>, greater<int>> pq;
	for (int i = 1; i < problems.size(); i++) {
		if (problems[i].in == 0) {
			pq.push(i);
		}
	}

	while (!pq.empty()) {
		int curNode = pq.top();
		pq.pop();

		cout << curNode << " ";

		for (int i = 0; i < problems[curNode].outs.size(); i++) {
			int nextNode = problems[curNode].outs[i];
			problems[nextNode].in--;
			if (problems[nextNode].in == 0) {
				pq.push(nextNode);
			}
		}
	}

	//print problems
	//for (int i = 1; i < N + 1; i++) {
	//	cout << i << " " << problems[i].in << " ";
	//	for (int j = 0; j < problems[i].outs.size(); j++) {
	//		cout << problems[i].outs[j] << " ";
	//	}
	//	cout << endl;
	//}


	return 0;
}