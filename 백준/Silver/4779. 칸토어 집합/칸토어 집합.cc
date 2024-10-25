#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <cmath>
#include <stack>

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

int g_nrow[] = { 0, 1, 0, -1 };
int g_ncol[] = { 1, 0, -1, 0 };

void Kantor(vector<char>& prints, int idx, int len) {
	if (len == 0) return;
	int tri = len / 3;

	for (int i = 0; i < tri; i++) {
		prints[idx + tri + i] = ' ';
	}
	Kantor(prints, idx, tri);
	Kantor(prints, idx + tri * 2, tri);
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	while (cin >> N) {
		int len = pow(3, N);

		vector<char> prints(len, '-');
		Kantor(prints, 0, len);

		for (int i = 0; i < len; i++) {
			printf("%c", prints[i]);
		}
		printf("\n");
	}
	return 0;
}