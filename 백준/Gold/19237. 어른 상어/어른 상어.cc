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

// 상어가 번호에 따라, 같이 만나면 추방됨
// 상어는 번호에 따라, 방향에 따라 방향 우선순위가 달라짐
// 상어가 지나간 곳엔 냄새를 남김
// 냄새는 k시간동안 남음
// 냄새가 나는곳은 안감, 냄새가 안나는곳이 없으면 자신의 냄새가 나는곳으로 감 (여기서도 우선순위가 적용 되는듯?)
// 1상어만 남을때까지

enum ESpaceState {
	NONE, Smell,
};

enum EDir {
	UP, DOWN, LEFT, RIGHT
};

int dr[4] = { -1, 1, 0, 0 };
int dc[4] = { 0, 0, -1, 1 };

struct TPos {
	int r, c;
};

class TShark {
public:
	bool death = false;
	int num = 0;
	EDir dir = UP;
	TPos pos = { 0, 0 };
};

class TSmell {
public:
	int sharkNum = 0;
	int remainTime = 0;
};

struct TNode {
	TSmell smell;
};

int N, M, K;
//[shark][dir][priority]
vector<vector<vector<EDir>>> Priority;
vector<vector<TNode>> maps;
vector<TShark> sharks;

bool Inputs() {
	cin >> N >> M >> K;

	maps.resize(N, vector<TNode>(N));
	sharks.resize(M + 1);
	Priority.resize(M + 1, vector<vector<EDir>>(4, vector<EDir>(4)));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int n;
			cin >> n;
			if (n != 0) {
				maps[i][j].smell.sharkNum = n;
				maps[i][j].smell.remainTime = K;
				sharks[n].num = n;
				sharks[n].death = false;
				sharks[n].pos = { i, j };
			}
		}
	}

	for (int i = 1; i <= M; i++) {
		int dir;
		cin >> dir;
		sharks[i].dir = (EDir)(dir - 1);
	}

	for (int i = 1; i <= M; i++) {
		for (int j = 0; j < 4; j++) {
			for (int k = 0; k < 4; k++) {
				int n;
				cin >> n;
				Priority[i][j][k] = (EDir)(n - 1);
			}
		}
	}

	return true;
}

inline bool Boundary(int r, int c) {
	return !(r < 0 || r >= N || c < 0 || c >= N);
}

inline bool HasSmell(int r, int c) {
	return maps[r][c].smell.remainTime > 0;
}

void PrintShark() {
	for (int i = 1; i <= M; i++) {
		if (sharks[i].death) {
			cout << i << " Shark is Dead\n";
		}
		else {
			cout << i << " shark is Alive and " << sharks[i].pos.r << ' ' << sharks[i].pos.c << ' ' << sharks[i].dir << '\n';
		}
	}
}

TShark NextPos(TShark shark) {
	TShark ret = shark;
	int r = shark.pos.r;
	int c = shark.pos.c;
	EDir d = shark.dir;

	// 냄새 없는 칸이 있다면
	for (int i = 0; i < 4; i++) {
		EDir nd = Priority[shark.num][d][i];
		int nr = r + dr[nd];
		int nc = c + dc[nd];

		if (!Boundary(nr, nc))continue;
		if (HasSmell(nr, nc))continue;

		ret.dir = nd;
		ret.pos.r = nr;
		ret.pos.c = nc;
		return ret;
	}

	// 냄새 없는 칸이 없다면 자기 냄새로
	for (int i = 0; i < 4; i++) {
		EDir nd = Priority[shark.num][d][i];
		int nr = r + dr[nd];
		int nc = c + dc[nd];

		if (!Boundary(nr, nc))continue;
		if (HasSmell(nr, nc) && maps[nr][nc].smell.sharkNum == shark.num) {
			ret.dir = nd;
			ret.pos.r = nr;
			ret.pos.c = nc;
			return ret;
		}
	}

	cout << "자기 냄새조차 없는 상어가 존재합니다. \n";
	return shark;
}

void Step() {
	// 상어들 다음 이동 경로
	vector<TShark> nextSharks;
	for (int i = 1; i <= M; i++) {
		if (sharks[i].death) continue;
		nextSharks.push_back(NextPos(sharks[i]));
	}

	// 실제 이동(작은놈은 사망) 상어 갱신
	vector<vector<int>> visited(N, vector<int>(N, 0));
	for (int i = 0; i < nextSharks.size(); i++) {
		int sharkNum = nextSharks[i].num;
		int r = nextSharks[i].pos.r;
		int c = nextSharks[i].pos.c;
		if (!visited[r][c]) {
			visited[r][c] = sharkNum;
			sharks[sharkNum].pos = nextSharks[i].pos;
			sharks[sharkNum].dir = nextSharks[i].dir;
		}
		else {
			sharks[sharkNum].death = true;
		}
	}

	// 냄새 시간 소모 및 제거
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (HasSmell(i, j)) {
				maps[i][j].smell.remainTime--;
				// 지워져야 하면 삭제
				if (maps[i][j].smell.remainTime == 0) {
					maps[i][j].smell.sharkNum = 0;
				}
			}
		}
	}

	// 냄새 생성
	for (int i = 1; i <= M; i++) {
		if (sharks[i].death)continue;
		auto pos = sharks[i].pos;
		maps[pos.r][pos.c].smell.remainTime = K;
		maps[pos.r][pos.c].smell.sharkNum = i;
	}
}


bool OnlyOne() {
	for (int i = 2; i <= M; i++) {
		if (!sharks[i].death) return false;
	}
	return sharks[1].death == false;
}

void Solution() {
	for (int i = 0; i < 1000; i++) {
		Step();
		if (OnlyOne()) {
			cout << i + 1 << '\n';
			return;
		}
		//PrintShark();
	}

	cout << -1 << '\n';
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