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

enum EDir { UP, DOWN, LEFT, RIGHT, END };
int dr[EDir::END] = { -1, 1, 0, 0 };
int dc[EDir::END] = { 0, 0, -1, 1 };
struct Pos {
	int r = 0, c = 0;
};
struct Command {
	EDir dir = EDir::END;
	int len = 0;
};
int N, M;
vector<int> lines;
vector<vector<int>> mapToLineIdx;
vector<Command>commands;
Pos center;

void MapToLine(const vector<vector<int>>& maps, vector<int>& line, vector<vector<int>>& mapToLineIdx) {
	mapToLineIdx.resize(N, vector<int>(N));
	lines.resize(N * N - 1);
	EDir rotate[4] = { LEFT, DOWN, RIGHT, UP };
	int dir = 0;
	Pos cur = center;

	int idx = 0;

	int steps = 0, rotCnt = 0, stepLv = 1;
	while (cur.r != 0 || cur.c != 0) {
		// 위치 변화
		cur.r = cur.r + dr[rotate[dir]];
		cur.c = cur.c + dc[rotate[dir]];

		//cout << cur.r << ' ' << cur.c << '\n';

		// 데이터 기입
		mapToLineIdx[cur.r][cur.c] = idx;
		lines[idx] = maps[cur.r][cur.c];
		idx++;

		// 위치 변화를 위한 데이터 변화
		steps++;
		if (steps == stepLv) {
			steps = 0;
			rotCnt++;
			dir = (dir + 1) % 4;
			if (rotCnt == 2) {
				rotCnt = 0;
				stepLv++;
			}
		}
	}
}

bool Inputs() {
	cin >> N >> M;
	vector<vector<int>> maps(N, vector<int>(N));
	commands.resize(M);
	center = { N / 2, N / 2 };
	FOR(r, N)
		FOR(c, N)
		cin >> maps[r][c];

	FOR(i, M) {
		int dir;
		cin >> dir >> commands[i].len;
		commands[i].dir = (EDir)(dir - 1);
	}

	MapToLine(maps, lines, mapToLineIdx);

	//PrintVec(mapToLineIdx);

	return true;
}

void Blizard(Command comm) {
	for (int i = 0; i < comm.len; i++) {
		int nr = center.r + dr[comm.dir] * (i + 1);
		int nc = center.c + dc[comm.dir] * (i + 1);
		int idx = mapToLineIdx[nr][nc];
		lines[idx] = 0;
	}
}

void LineRefresh() {
	int curIdx = 0;
	int zeroCnt = 0;
	for (int i = 0; i < lines.size(); i++) {
		if (lines[i] == 0) {
			zeroCnt++;
		}
		else {
			lines[curIdx] = lines[curIdx + zeroCnt];
			curIdx++;
		}
	}

	for (int i = 0; i < zeroCnt; i++) {
		lines[lines.size() - 1 - i] = 0;
	}
}

int oneP = 0, twoP = 0, threeP = 0;
bool Pang() {
	int ret = false;

	int cur = 0;
	int sequence = 0;
	for (int i = 0; i < lines.size(); i++) {
		//if (lines[i] == 0) break;

		if (cur != lines[i]) {
			// 4이상이면
			// i - sequence ~ i까지 0으로 만들어야 함
			if (sequence >= 3) {
				if (cur == 1) {
					oneP += sequence + 1;
				}
				else if (cur == 2) {
					twoP += sequence + 1;
				}
				else {
					threeP += sequence + 1;
				}
				for (int j = i - sequence - 1; j < i; j++) {
					lines[j] = 0;
				}
				ret = true;
			}

			cur = lines[i];
			sequence = 0;
		}
		else {
			sequence++;
		}

	}

	return ret;
}

void PrintLine() {
	PrintVec(lines);
}

void Increase() {
	vector<int> tmp(lines.size());
	int tmpIdx = 0;

	int sequence = 1;
	int cur = lines[0];
	for (int i = 1; i < lines.size(); i++) {
		if (cur != lines[i]) {
			tmp[tmpIdx++] = sequence;
			tmp[tmpIdx++] = cur;
			if (sequence >= 4) {
				cout << "터지지 않은 문제가 존재합니다.\n";
			}
			cur = lines[i];
			sequence = 1;
		}
		else {
			sequence++;
		}
		if (tmpIdx >= lines.size()) break;
	}
	swap(tmp, lines);
}

void Solution() {
	for (int i = 0; i < M; i++) {
		// 블리자드
		Blizard(commands[i]);

		// 4개짜리 파괴 안될때까지 반복
		while (true) {
			// 구슬 내려오기
			LineRefresh();

			//PrintLine();
			// 4개짜리 파괴
			int broken = Pang();
			//PrintLine();
			if (broken == 0) break;

		}
		// 구슬 증식
		Increase();

		//PrintLine();
	}
	cout << oneP + 2 * twoP + 3 * threeP;
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