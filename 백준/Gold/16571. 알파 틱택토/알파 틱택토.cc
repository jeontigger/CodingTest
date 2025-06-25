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

// 누가 이기는지 알아야 함
// 다음 턴에 승부 결과가 나온다면 그를 따르면 됨
// 다음 턴에 상대가 이긴다면 이번 턴의 유저가 패배
// 다음 턴에 상대가 진다면 이번 턴의 유자기 승리
// 다음 턴의 상대가 드로우를 낸다면 나도 드로우
// 드로우 보다는 승패가 결정된다면 그것이 우선

// 현재 상황 판을 3^9로 일대일 대응
// 현재 상황 판과, 턴을 넘겨주어 보드에 수를 놓고 다음 턴으로 넘김
// 가능한 모든 수에 대해 호출

// 가능한 수가 하나도 없다면 드로우

// 이겼는지 판단하는 함수
// 상하 좌우 대각선 중 하나라도 완성됐다면 승리
// 기저사례기 때문에 이전턴의 상대가 놓은 것을 판단해야 함

// 시작할 때 누구 턴인지 판단하는 함수 필요
// x와  o의 개수를 찾아서 x > o면 o차례 x == o 면 x 차례

constexpr int BOARD_SIZE = 3;
constexpr char PLAYER_1 = 'x';
constexpr char PLAYER_2 = 'o';
constexpr char BLANK = '.';
constexpr int WIN = 1;
constexpr int DRAW = 0;
constexpr int LOSE = -1;

int cache[19683];

char WhosTurn(const vector<string>& board) {
	int xCnt = 0, oCnt = 0;
	for (int i = 0; i < BOARD_SIZE; i++) {
		for (int j = 0; j < BOARD_SIZE; j++) {
			if (board[i][j] == PLAYER_1) {
				xCnt++;
			}
			else if (board[i][j] == PLAYER_2) {
				oCnt++;
			}
		}
	}

	return xCnt == oCnt ? PLAYER_1 : PLAYER_2;
}

bool IsFinished(const vector<string>& board, char turn) {
	bool isFinish = true;

	// 좌우 판단
	for (int i = 0; i < BOARD_SIZE; i++) {
		isFinish = true;
		for (int j = 0; j < BOARD_SIZE; j++) {
			if (board[i][j] != turn) {
				isFinish = false;
				break;
			}
		}
		if (isFinish) return true;
	}

	// 상하 판단
	for (int i = 0; i < BOARD_SIZE; i++) {
		isFinish = true;
		for (int j = 0; j < BOARD_SIZE; j++) {
			if (board[j][i] != turn) {
				isFinish = false;
				break;
			}
		}
		if (isFinish) return true;
	}

	// 좌상단 우하단 대각 판단
	isFinish = true;
	for (int i = 0; i < BOARD_SIZE; i++) {
		if (board[i][i] != turn) {
			isFinish = false;
			break;
		}
	}
	if (isFinish) return true;

	// 우상단 좌하단 대각 판단
	isFinish = true;
	for (int i = 0; i < BOARD_SIZE; i++) {
		if (board[i][BOARD_SIZE - 1 - i] != turn) {
			isFinish = false;
			break;
		}
	}
	if (isFinish) return true;


	return false;
}

int bijection(const vector<string>& board) {
	int ret = 0;
	for (int i = 0; i < BOARD_SIZE; i++) {
		for (int j = 0; j < BOARD_SIZE; j++) {
			ret *= 3;

			if (board[i][j] == PLAYER_1) {
				ret += 1;
			}
			else if (board[i][j] == PLAYER_2) {
				ret += 2;
			}
		}
	}

	return ret;
}

int CanWin(vector<string>& board, char turn) {

	// 기저사례
	// 승리판단
	if (IsFinished(board, PLAYER_1 + PLAYER_2 - turn)) {
		return LOSE;
	}

	int& ret = cache[bijection(board)];
	if (ret != -2) return ret;
	int minValue = 2;
	for (int i = 0; i < BOARD_SIZE; i++) {
		for (int j = 0; j < BOARD_SIZE; j++) {
			if (board[i][j] == BLANK) {
				board[i][j] = turn;
				minValue = min(minValue, CanWin(board, PLAYER_1 + PLAYER_2 - turn));
				board[i][j] = BLANK;
			}
		}
	}

	if (minValue == 2 || minValue == 0) return ret = 0;

	return ret = -minValue;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int C = 10;
	//cin >> C;
	for (int i = 0; i < sizeof(cache) / sizeof(int); i++) {
		cache[i] = -2;
	}
	while (true) {
		vector<string> board;

		string input;
		board.assign(BOARD_SIZE, "");

		for (int i = 0; i < BOARD_SIZE; i++) {
			for (int j = 0; j < BOARD_SIZE; j++) {
				int val;
				cin >> val;
				if (val == 0) {
					board[i].push_back(BLANK);
				}
				else if (val == 1) {
					board[i].push_back(PLAYER_1);
				}
				else {
					board[i].push_back(PLAYER_2);
				}
			}
		}

		char turn = WhosTurn(board);

		int result = CanWin(board, turn);
		if (result == 0) {
			cout << "D";
		}
		else if (result == 1) {
			cout << "W";
		}
		else if (result == -1) {
			cout << "L";
		}
		break;
	}

	return 0;
}