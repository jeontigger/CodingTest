#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;

#define INF 1e15


int main() {

	int n;
	cin >> n;

	int cnt = 0;
	while (n > 0) {
		if (n % 5 != 0) {
			n -= 3;
		}
		else {
			n -= 5;
		}
		cnt++;
	}

	if (n == 0) {
		cout << cnt;
	}
	else {
		cout << -1;
	}


	return 0;
}