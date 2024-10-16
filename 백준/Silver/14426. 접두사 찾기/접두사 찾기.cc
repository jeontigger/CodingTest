#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

constexpr int ALPHACNT = 26;
class Trie {
private:
	Trie* alpha[ALPHACNT];

public:

	Trie() {
		for (int i = 0; i < ALPHACNT; i++) {
			alpha[i] = nullptr;
		}
	}

	~Trie() {
		for (int i = 0; i < ALPHACNT; i++) {
			if (alpha[i]) delete alpha[i];
		}

		return;
	}

	void Insert(const char* str) {
		if (*str == NULL) return;

		if (alpha[*str - 'a'] != nullptr) {
			// 이미 있음
			alpha[*str - 'a']->Insert(str + 1);
		}
		else {
			// 아직 없음
			alpha[*str - 'a'] = new Trie;
			alpha[*str - 'a']->Insert(str + 1);
		}
	}

	bool FindPrev(const char* str) {
		if (*str == NULL) return true;

		if (alpha[*str - 'a'] != nullptr) {
			// 이미 있음
			return alpha[*str - 'a']->FindPrev(str + 1);
		}
		else {
			// 아직 없음
			return false;
		}
	}

};

int main() {

	int N, M;

	cin >> N >> M;

	Trie t;

	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;
		t.Insert(str.c_str());
	}

	int sum = 0;
	for (int i = 0; i < M; i++) {
		string str;
		cin >> str;
		sum += t.FindPrev(str.c_str());
	}

	cout << sum << endl;

	return 0;
}