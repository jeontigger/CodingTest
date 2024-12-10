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
	cout << '\n';
}

template<typename T>
void PrintVec(const vector<vector<T>>& vec) {
	for (auto& v : vec) {
		PrintVec(v);
	}
}
int N, M;
vector<vector<int>> maps;
enum {
	AirInChesse,
	Chesse,
	Air,
};

struct Pos {
	int row;
	int col;
};

int g_nrow[] = { 0, 1, 0, -1 };
int g_ncol[] = { 1, 0, -1, 0 };

void BFS(Pos start) {
	queue<Pos> q;
	q.push(start);
	maps[start.row][start.col] = Air;

	while (!q.empty()) {
		Pos pos = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nrow = pos.row + g_nrow[i];
			int ncol = pos.col + g_ncol[i];

			if (0 <= nrow && nrow < N && 0 <= ncol && ncol < M) {
				if (maps[nrow][ncol] == AirInChesse) {
					maps[nrow][ncol] = Air;
					q.push({ nrow, ncol });
				}
			}
		}
	}
}

void MakeAir() {
	// 상하
	for (int i = 0; i < M; i++) {
		if (maps[0][i] == AirInChesse) {
			BFS({ 0, i });
		}
		if (maps[N - 1][i] == AirInChesse) {
			BFS({ N - 1, i });
		}
	}

	// 좌우
	for (int i = 0; i < N; i++) {
		if (maps[i][0] == AirInChesse) {
			BFS({ i, 0 });
		}
		if (maps[i][M - 1] == AirInChesse) {
			BFS({ i, M - 1 });
		}
	}
}

vector<Pos> meltingPos;
void MeltCheese() {
	auto next = maps;
	meltingPos.clear();
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (maps[i][j] == Chesse) {
				int cnt = 0;
				for (int k = 0; k < 4; k++) {
					int nrow = i + g_nrow[k];
					int ncol = j + g_ncol[k];
					if (maps[nrow][ncol] == Air)
						cnt++;
				}
				if (cnt >= Air) {
					next[i][j] = Air;
					meltingPos.push_back({ i, j });
				}
			}
		}
	}

	maps = next;
}

void Airing() {
	for (int i = 0; i < meltingPos.size(); i++) {
		Pos pos = meltingPos[i];
		for (int j = 0; j < 4; j++) {
			int nrow = pos.row + g_nrow[j];
			int ncol = pos.col + g_ncol[j];

			if (maps[nrow][ncol] == AirInChesse) {
				BFS({ nrow, ncol });
			}
		}
	}
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	maps.resize(N, vector<int>(M));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> maps[i][j];
		}
	}

	MakeAir();

	int cnt = 0;
	while (true) {
		cnt++;

		// 치즈 녹이기
		MeltCheese();

		if (meltingPos.size() == 0) break;

		// 치즈속 공간 산화시키기
		Airing();
	}

	cout << cnt - 1;

	return 0;
}
