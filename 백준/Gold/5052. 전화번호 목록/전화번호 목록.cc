#include <vector>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Trie {
private:
	Trie* nums[10];
	bool finish;

public:
	Trie() {
		for (int i = 0; i < 10; i++) {
			nums[i] = nullptr;
		}
		finish = false;
	};
	~Trie() {
		for (int i = 0; i < 10; i++) {
			if (nums[i]) delete nums[i];
		}
	}

	void Insert(const char* str) {
		if (*str == NULL) {
			finish = true;
			return;
		}

		if (nums[*str - '0'] != nullptr) {
			// 중복
			nums[*str - '0']->Insert(str + 1);
		}
		else {
			// 첫 기입
			nums[*str - '0'] = new Trie;
			nums[*str - '0']->Insert(str + 1);
		}
	}

	bool HasPrev(const char* str) {
		if (*str == NULL) {
			return false;
		}

		if (finish) return true;

		if (nums[*str - '0'] != nullptr) {
			// 중복
			return nums[*str - '0']->HasPrev(str + 1);
		}
		else {
			// 첫 기입
			return false;
		}
	}
};


int main() {

	int testCnt = 0;
	cin >> testCnt;

	for (int i = 0; i < testCnt; i++) {
		int inputCnt;
		cin >> inputCnt;

		Trie t;
		vector<string> inputs;
		for (int j = 0; j < inputCnt; j++) {
			string str;
			cin >> str;
			t.Insert(str.c_str());
			inputs.push_back(str);
		}

		bool isConsist = true;
		for (int j = 0; j < inputCnt; j++) {
			if (t.HasPrev(inputs[j].c_str())) {
				cout << "NO" << endl;
				isConsist = false;
				break;
			}
		}
		if (isConsist) {
			cout << "YES" << endl;
		}
	}

	return 0;
}