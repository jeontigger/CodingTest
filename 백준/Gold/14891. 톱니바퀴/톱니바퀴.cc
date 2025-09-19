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

// 극이 다르면 반대 방향으로 회전, 극이 같으면 회전 x
// N극은 0, S극은 1. 12시부터 시계방향으로 주어짐
// 회전 횟수 K, 1은 시계방향, -1은 반시계 방향
// 총 점수는 12시 방향의 S극 개수와 유사

// 톱니는 8개니까 회전을 8번하면 제자리
// 회전 0번 기준으로 [2]번과 [6]번이 우측, 좌측을 뜻함
// 회전 1번 기준으로 [1]번과 [5]번이 우측, 좌측
// 회전 -1번 기준으로 [3]번과 [7]번이 우측, 좌측

int gear[4][8];
int K;
int rotNum[101];
int rotDir[101];
int rotCnt[4];

void Inputs() {
	for (int i = 0; i < 4; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < 8; j++) {
			gear[i][j] = str[j] - '0';
		}
	}

	cin >> K;
	for (int i = 0; i < K; i++) {
		cin >> rotNum[i] >> rotDir[i];
		rotNum[i]--;
	}
}

void Rotate(int num, int dir) {
	if (dir == 1) {
		// 시계 방향
		int end = gear[num][7];
		for (int i = 7; i >= 1; i--) {
			gear[num][i] = gear[num][i - 1];
		}
		gear[num][0] = end;
	}
	else {
		// 반시계 방향
		int begin = gear[num][0];
		for (int i = 0; i < 7; i++) {
			gear[num][i] = gear[num][i + 1];
		}
		gear[num][7] = begin;
	}
}

#define LOG

int GetLeft(int num) {
	return gear[num][6];
}

int GetRight(int num) {
	return gear[num][2];
}

void GearRotate(int num, int dir, vector<int>& visited) {
	visited[num] = true;

	// 왼쪽 회전
	if (num > 0 && !visited[num - 1] && GetLeft(num) != GetRight(num - 1)) {
		GearRotate(num - 1, -dir, visited);
	}

	// 오른쪽 회전
	if (num < 3 && !visited[num + 1] && GetLeft(num + 1) != GetRight(num)) {
		GearRotate(num + 1, -dir, visited);
	}

	Rotate(num, dir);

}

int GetScore() {
	int ret = 0;

	for (int i = 0; i < 4; i++) {
		ret += gear[i][0] * pow(2, i);
	}
	// 0 => 0, 1 => 7, 2 =>6, 
	return ret;
}

void Solution() {
	for (int i = 0; i < K; i++) {
		vector<int> visited(4);
		GearRotate(rotNum[i], rotDir[i], visited);
	}

	cout << GetScore();
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