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

int Left(int cur) {
	int d1 = cur / 1000;
	int d = (cur % 1000) * 10;

	return d + d1;
}

int Right(int cur) {
	int d = cur / 10;
	int d4 = cur % 10;

	return d4 * 1000 + d;
}

struct Data {
	int val;
	string path;
};

void DSLR(int cur, int target, string path) {

	queue<Data> q;
	q.push({ cur, path });

	vector<bool>visited(10001);
	visited[cur] = true;

	while (!q.empty()) {
		Data data = q.front();
		q.pop();

		if (data.val == target) {
			cout << data.path << '\n';
			break;
		}

		int next;
		next = (data.val * 2) % 10000;
		if (!visited[next])
		{
			q.push({ next, data.path + 'D' });
			visited[next] = true;
		}

		next = (data.val + 9999) % 10000;
		if (!visited[next])
		{
			q.push({ next, data.path + 'S' });
			visited[next] = true;
		}

		next = Left(data.val);
		if (!visited[next])
		{
			q.push({ next, data.path + 'L' });
			visited[next] = true;
		}

		next = Right(data.val);
		if (!visited[next])
		{
			q.push({ next, data.path + 'R' });
			visited[next] = true;
		}
	}
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;

	while (T--) {
		int start, target;
		cin >> start >> target;
		DSLR(start, target, "");
	}


	return 0;
}