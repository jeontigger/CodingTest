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

struct Chunk {
	int w;
	int h;
	int idx;
	int rank;
};

bool cmp(const Chunk& c1, const Chunk& c2) {
	return c1.w > c2.w;
}

bool cmpIdx(const Chunk& c1, const Chunk& c2) {
	return c1.idx < c2.idx;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	vector<Chunk> humans(N);
	for (int i = 0; i < N; i++) {
		cin >> humans[i].w >> humans[i].h;
		humans[i].idx = i;
	}

	for (int i = 0; i < N; i++) {
		int cnt = 0;
		for (int j = 0; j < N; j++) {
			if (i == j) continue;

			if (humans[i].w < humans[j].w && humans[i].h < humans[j].h) {
				cnt++;
			}
		}

		cout << cnt + 1 << " ";
	}


	return 0;
}