
#include <iostream>
#include <vector>

using namespace std;

void Input(vector<int>& logs, int& target) {
	int m;

	cin >> m >> target;

	logs.resize(m);

	for (int i = 0; i < m; i++) {
		cin >> logs[i];
	}
};

bool IsPossible(const vector<int>& logs, int target, int len) {

	int sum = 0;
	for (int i = 0; i < logs.size(); i++) {
		if (logs[i] > len) {
			sum += logs[i] - len;
		}
		if (sum >= target) return true;
	}

	return false;
}

int main()
{
	int target;
	vector<int> logs;

	Input(logs, target);

	int left = 0, right = 1000000000;

	while (left <= right) {
		int mid = (left + right) / 2;

		if (IsPossible(logs, target, mid)) {
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}

	cout << right << endl;

}