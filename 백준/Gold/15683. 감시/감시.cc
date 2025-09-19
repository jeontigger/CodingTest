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

int N, M, K;
int cache[65536 + 1];
int map[8][8];
int r[8], c[8], type[8];

void Inputs() {
	cin >> N >> M;

	K = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j] != 0 && map[i][j] != 6) {
				r[K] = i;
				c[K] = j;
				type[K] = map[i][j] - 1;
				K++;
			}

			if (map[i][j] == 6) {
				map[i][j] = -1;
			}
		}
	}

	memset(cache, -1, sizeof(cache));
}

int CountInvisible() {
	int res = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 0) res++;
		}
	}
	return res;
}

void Light(int _r, int _c, int dir, int delta) {
	int dr[4] = { 0, 1, 0, -1 };
	int dc[4] = { 1, 0, -1, 0 };

	while (true) {
		int nr = _r + dr[dir];
		int nc = _c + dc[dir];

		// 범위
		if (0 > nr || nr >= N || 0 > nc || nc >= M)break;
		// 벽 만남
		if (map[nr][nc] == -1) break;

		map[nr][nc] += delta;

		_r = nr;
		_c = nc;
	}
}

void Draw(int cctv, int dir, int delta) {
	if (cctv == -1) return;
	int _r = r[cctv];
	int _c = c[cctv];
	int _t = type[cctv];

	// 우 하 좌 상
	switch (_t)
	{
	case 0:
		Light(_r, _c, (0 + dir) % 4, delta);
		break;
	case 1:
		Light(_r, _c, (0 + dir) % 4, delta);
		Light(_r, _c, (2 + dir) % 4, delta);
		break;
	case 2:
		Light(_r, _c, (0 + dir) % 4, delta);
		Light(_r, _c, (3 + dir) % 4, delta);
		break;
	case 3:
		Light(_r, _c, (0 + dir) % 4, delta);
		Light(_r, _c, (3 + dir) % 4, delta);
		Light(_r, _c, (2 + dir) % 4, delta);
		break;
	case 4:
		Light(_r, _c, (0 + dir) % 4, delta);
		Light(_r, _c, (1 + dir) % 4, delta);
		Light(_r, _c, (2 + dir) % 4, delta);
		Light(_r, _c, (3 + dir) % 4, delta);
		break;
	default:
		break;
	}


}

void PrintMap() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << map[i][j] << ' ';
		}
		cout << '\n';
	}
	cout << '\n';
}

int DFS(int cctv, int visited) {
	if (cctv == K) {
		//PrintMap();
		if (CountInvisible() == 3) {
			//PrintMap();
		}
		return CountInvisible();
	}

	int& ret = cache[visited];
	if (ret != -1) return ret;

	for (int i = 0; i < 4; i++) {
		Draw(cctv, i, 1);
		if (ret == -1)
			ret = DFS(cctv + 1, visited + (i << (cctv * 2)));
		else
			ret = min(ret, DFS(cctv + 1, visited + (i << (cctv * 2))));
		Draw(cctv, i, -1);
	}

	return ret;
}

void Solution() {
	cout << DFS(0, 0);
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