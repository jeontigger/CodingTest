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
struct Pos {
	int x;
	int y;
};

vector<Pos> pos;

void Inputs() {
	cin >> N;
	pos.resize(N);
	FOR(i, N) {
		cin >> pos[i].x >> pos[i].y;
	}
}

int Dist(const Pos& l, const Pos& r) {
	return (l.x - r.x) * (l.x - r.x) + (l.y - r.y) * (l.y - r.y);
}

int DC(int left, int right) {
	if (right - left + 1 == 1) return INF;

	int ret = INF;
	int mid = (left + right) / 2;
	ret = min(DC(left, mid), DC(mid + 1, right));

	vector<Pos> cand;
	for (int i = left; i <= right; i++) {
		int diff = pos[mid].x - pos[i].x;
		if (diff * diff < ret)
			cand.push_back(pos[i]);
	}

	sort(cand.begin(), cand.end(), [](const Pos& p1, const Pos& p2) {
		return p1.y < p2.y;
		});

	for (int i = 0; i + 1 < cand.size(); i++) {
		for (int j = i + 1; j < cand.size(); j++) {
			int diff = cand[i].y - cand[j].y;
			if (diff * diff < ret) {
				ret = min(ret, Dist(cand[i], cand[j]));
			}
			else
				break;
		}
	}

	return ret;
}

void Solution() {
	sort(pos.begin(), pos.end(), [](const Pos& p1, const Pos& p2) {
		return p1.x < p2.x;
		});

	cout << DC(0, N - 1);
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