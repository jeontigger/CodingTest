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

// 크기별 물고기 위치 list를 갖는 vec
// 현재 상어 위치, 현재 상어 크기
// 현재 버틴? 시간

// 조건: 자신보다 작은 물고기가 없으면
// 가장 가까운 물고기를 먹으러 가고, 가까운 물고기가 여럿이라면 상단, 그래도 여럿이면 좌측 임
// 먹은 수가 자신의 크기와 같으면 성장

int N;
int map[21][21];
vector<list<pair<int, int>>> fishes;
pair<int, int> sharkPos;

void Inputs() {
	fishes.resize(7);
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			if (map[i][j] != 0) {
				if (map[i][j] == 9) {
					// 상어라면
					sharkPos = { i, j };
					map[i][j] = 0;
				}
				else {
					// 물고기라면
					fishes[map[i][j]].push_back({ i, j });
				}
			}
		}
	}
}

int GetDistance(pair<int, int> src, pair<int, int> dst, int _size) {
	queue<pair<int, int>> q;
	q.push(src);

	int cnt = -1;

	int nrow[4] = { 0, 1, 0, -1 };
	int ncol[4] = { 1, 0, -1, 0 };
	vector<vector<bool>> visited(N + 1, vector<bool>(N + 1));
	visited[src.first][src.second] = true;

	while (!q.empty()) {
		int size = q.size();
		cnt++;

		while (size--) {
			pair<int, int> pos = q.front();
			q.pop();

			if (pos == dst) {
				return cnt;
			}

			for (int i = 0; i < 4; i++) {
				int _nrow = pos.first + nrow[i];
				int _ncol = pos.second + ncol[i];

				if (0 <= _nrow && _nrow < N && 0 <= _ncol && _ncol < N) {
					if (_size >= map[_nrow][_ncol] && !visited[_nrow][_ncol]) {
						q.push({ _nrow, _ncol });
						visited[_nrow][_ncol] = true;
					}
				}
			}
		}
	}

	return INF;
}

bool CanEatFish(pair<int, int> shark, int size) {
	for (int i = 1; i < size && i < fishes.size(); i++) {
		for (auto iter = fishes[i].begin(); iter != fishes[i].end(); ++iter) {
			if (GetDistance(shark, *iter, size) != INF)
				return true;
		}
	}
	return false;
}



pair<int, int> GetNearestFish(pair<int, int> pos, int size) {
	int minDist = INF;
	vector<pair<int, int>> cand;

	for (int i = 1; i < size && i < fishes.size(); i++) {
		for (auto iter = fishes[i].begin(); iter != fishes[i].end(); ++iter) {
			int dist = GetDistance(pos, *iter, size);
			if (dist == minDist) {
				cand.push_back(*iter);
			}
			else if (dist < minDist) {
				cand.clear();
				cand.push_back(*iter);
				minDist = dist;
			}
		}
	}

	sort(cand.begin(), cand.end());
	return cand[0];
}

void EatFish(int size, pair<int, int> pos) {
	for (auto iter = fishes[size].begin(); iter != fishes[size].end();) {
		if (pos == *iter) {
			// 조건 삭제
			iter = fishes[size].erase(iter);
		}
		else {
			++iter;
		}
	}
}

void Solution() {
	int curSize = 2;
	pair<int, int> curPos = sharkPos;
	int time = 0;
	int eatCnt = 0;
	while (true) {
		if (!CanEatFish(curPos, curSize))
			break;

		pair<int, int> pos = GetNearestFish(curPos, curSize);
		time += GetDistance(curPos, pos, curSize);
		EatFish(map[pos.first][pos.second], pos);
		eatCnt++;
		if (eatCnt == curSize) {
			curSize++;
			eatCnt = 0;
		}
		curPos = pos;
		//cout << curPos.first << ' ' << curPos.second << ' ' << curSize << ' ' << eatCnt << ' ' << time << '\n';
	}

	cout << time;
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