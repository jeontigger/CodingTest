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

// [type][rot][rc]
struct Pos {
	int row;
	int col;
};

vector<vector<vector<Pos>>> blocks = {
	// type
	{
		{
			{0, 0}, {0, 1}, {0, 2}, {0, 3},
		},
		{
			{ 0, 0 },
			{1, 0},
			{2, 0},
			{3, 0}
		}
	},
	{
		{
			{ 0, 0 }, { 0,  1},
			{ 1, 0}, {1, 1}
		}
	},
	{
		{
			{0, 0},
			{1, 0},
			{2, 0},{2, 1}
		},
		{
			{0, 0}, {0, 1}, {0, 2},
			{1, 0}
		},
		{
			{ 0, 0 }, {0, 1},
							{1, 1},
							{2, 1}
		},
		{
									{0, 0},
			{1, -2}, {1, -1}, {1, 0}
		},
		{
							{0, 0},
							{1, 0},
			{2, -1}, { 2, 0 },
		},
		{
			{0, 0},
			{1, 0}, {1, 1}, {1, 2}
		},
		{
			{0, 0}, {0, 1},
			{1, 0},
			{2, 0}
		},
		{
			{0, 0}, {0, 1}, {0, 2},
									{1, 2}
		}
	},
	{
		{
			{0, 0},
			{1, 0}, {1, 1},
						{2, 1}
		},
		{
						{0, 0}, {0, 1},
			{1, -1}, {1, 0}
		},
		{
						{0, 0},
			{1, -1}, {1, 0},
			{2, -1}
		},
		{
			{0, 0}, {0, 1},
						{1, 1}, {1, 2}
		}
	},
	{
		{
			{0, 0}, {0, 1}, {0, 2},
						{1, 1}
		} ,
		{
						{0, 0},
			{1, -1}, {1, 0},
						 {2, 0}
		},
		{
						{0, 0},
			{1, -1}, {1, 0}, {1, 1}
		},
		{
			{0, 0},
			{1, 0},{1, 1},
			{2, 0},
		}
	}
};

int N, M;
vector<vector<int>> maps;

int GetSum(int row, int col, int type, int rot) {

	int sum = 0;
	for (int i = 0; i < blocks[type][rot].size(); i++) {
		Pos delta = blocks[type][rot][i];
		int nrow = row + delta.row;
		int ncol = col + delta.col;

		if (0 <= nrow && nrow < N && 0 <= ncol && ncol < M) {
			sum += maps[nrow][ncol];
		}
		else {
			// Invalid Bound
			//return 0;
		}
	}

	return sum;
}

int GetSum(int row, int col, int type) {

	int sum = 0;
	// 회전별
	for (int i = 0; i < blocks[type].size(); i++) {
		sum = max(sum, GetSum(row, col, type, i));
	}

	return sum;
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

	int maxValue = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			for (int k = 0; k < 5; k++) {
				maxValue = max(maxValue, GetSum(i, j, k));
			}
		}
	}

	cout << maxValue;

	return 0;
}