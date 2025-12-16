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
#include <map>

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

int gears[4][8];
int idxs[4];
int K;

struct Command {
	int idx;
	int dir;
};
vector<Command> commands;

bool Inputs() {
	FOR(i, 4) {
		FOR(j, 8) {
			char ch;
			cin >> ch;
			gears[i][j] = ch - '0';
		}
	}

	cin >> K;

	FOR(i, K) {
		int c, d;
		cin >> c >> d;
		commands.push_back({ c - 1, d });
	}

	memset(idxs, 0, sizeof(idxs));

	return true;
}

int ConvertIdx(int idx) {
	return (idx + 8) % 8;
}

void Rotate(int idx, int dir, vector<int>& visited) {
	if (idx < 0 || idx >= 4) return;
	if (visited[idx]) return;
	visited[idx] = true;
	int rightIdx = ConvertIdx(idxs[idx] + 2);
	int leftIdx = ConvertIdx(idxs[idx] - 2);
	if (idx > 0) {
		int lrIdx = ConvertIdx(idxs[idx - 1] + 2);
		if (gears[idx - 1][lrIdx] != gears[idx][leftIdx])
			Rotate(idx - 1, -dir, visited);
	}

	if (idx < 3) {
		int rlIdx = ConvertIdx(idxs[idx + 1] - 2);
		if (gears[idx + 1][rlIdx] != gears[idx][rightIdx])
			Rotate(idx + 1, -dir, visited);
	}

	idxs[idx] = ConvertIdx(idxs[idx] - dir);
}

int CalcScore() {
	int ret = 0;
	for (int i = 0; i < 4; i++) {
		int val = gears[i][idxs[i]];
		if (val == 1) {
			ret += pow(2, i);
		}
	}
	return ret;
}

void PrintIdxs() {
	for (int i = 0; i < 4; i++) {
		cout << idxs[i] << ' ';
	}
	cout << '\n';
}

void Solution() {
	//PrintIdxs();
	for (int i = 0; i < K; i++) {
		auto comm = commands[i];
		vector<int> visited(4);
		Rotate(comm.idx, comm.dir, visited);
		//PrintIdxs();
	}

	cout << CalcScore();
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T = 1;
	//cin >> T;
	while (T--) {
		if (!Inputs()) break;
		Solution();
	}

	return 0;
}