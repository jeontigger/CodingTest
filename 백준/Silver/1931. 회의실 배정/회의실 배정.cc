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

struct Data {
	int start;
	int end;
};

bool cmp(const Data& d1, const Data& d2) {
	return d1.start == d2.start ? d1.end < d2.end : d1.start < d2.start;
}

int GetMaxMeeting(vector<Data>& datas) {
	sort(datas.begin(), datas.end(), cmp);
	//for (int i = 0; i < datas.size(); i++) {
	//	cout << datas[i].start << " " << datas[i].end << endl;
	//}
	int start = datas[0].start;
	int end = datas[0].end;

	int meeting = 1;

	for (int i = 1; i < datas.size(); i++) {
		int nextStart = datas[i].start;
		int nextEnd = datas[i].end;

		if (nextEnd < end) {
			end = nextEnd;
		}
		else if (end <= nextStart) {
			end = nextEnd;
			start = nextStart;
			meeting++;
			//cout << start << " " << end << endl;
		}

		//cout << start << " " << end << endl;
	}

	return meeting;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;

	cin >> N;

	vector<Data> datas;
	for (int i = 0; i < N; i++) {
		int s, e;
		cin >> s >> e;
		datas.push_back({ s, e });
	}



	cout << GetMaxMeeting(datas);


	return 0;
}