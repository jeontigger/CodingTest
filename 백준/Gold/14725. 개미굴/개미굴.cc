#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Trie {
private:
	vector<Trie*> v;
	string str;
	bool finish;
	int cnt = -1;


public:
	Trie() {
	}

	void insert(const vector<string>& strings) {
		if (strings.size() == 0) return;

		for (int i = 0; i < v.size(); i++) {
			if (v[i]->str == strings[0]) {
				v[i]->insert({ strings.begin() + 1, strings.end() });
				return;
			}
		}

		Trie* pTrie = new Trie;
		pTrie->str = strings[0];
		pTrie->cnt = cnt + 1;

		bool last = true;
		for (int i = 0; i < v.size(); i++) {
			if (pTrie->str < v[i]->str)
			{
				v.insert(v.begin() + i, pTrie);
				last = false;
				break;
			}
		}
		if (last)
			v.push_back(pTrie);
		pTrie->insert({ strings.begin() + 1, strings.end() });
		return;
	}

	void print() {

		if (str != "") {
			for (int i = 0; i < cnt; i++) {
				cout << "--";
			}
			cout << str << endl;
		}
		for (int i = 0; i < v.size(); i++) {
			v[i]->print();
		}
	}


};

void Input(vector<vector<string>>& inputs) {
	int num;
	cin >> num;

	inputs.resize(num);

	for (int i = 0; i < num; i++) {
		int cnt;
		cin >> cnt;

		inputs[i].resize(cnt);
		for (int j = 0; j < cnt; j++) {
			cin >> inputs[i][j];
		}
	}


}

int main() {

	vector<vector<string>> inputs;
	Input(inputs);

	Trie t;
	for (int i = 0; i < inputs.size(); i++) {
		t.insert(inputs[i]);
	}

	t.print();
	return 0;
}