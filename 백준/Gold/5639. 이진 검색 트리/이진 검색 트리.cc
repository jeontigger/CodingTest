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

struct Node {
	int val;
	Node* left = nullptr;
	Node* right = nullptr;
};

void Insert(Node* curNode, int n) {
	if (curNode->val > n) {
		if (curNode->left) {
			Insert(curNode->left, n);
		}
		else {
			curNode->left = new Node;
			curNode->left->val = n;
		}
	}
	else if (curNode->val < n) {
		if (curNode->right) {
			Insert(curNode->right, n);
		}
		else {
			curNode->right = new Node;
			curNode->right->val = n;
		}
	}
}

void PrintNode(Node* curNode) {

	if (curNode->left)
		PrintNode(curNode->left);

	if (curNode->right)
		PrintNode(curNode->right);
	cout << curNode->val << ' ';

}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	Node* root = new Node;
	string s;
	getline(cin, s);
	root->val = stoi(s);


	int N = 8;
	while (getline(cin, s)) {
		int n = stoi(s);

		Insert(root, n);
	}

	PrintNode(root);

	return 0;
}
