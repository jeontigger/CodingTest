#include <bits/stdc++.h>
using namespace std;

struct Trie {
	Trie *node[10];
	bool finish;
	Trie() {
		finish=false;
		for(int i=0; i<10; i++) {
			node[i]=NULL;
		}
	}
	
	void insert(char *str) {
		if(*str==NULL) {
			finish=true;
			return;
		}
		int cur = *str-'0';
		if(node[cur] == NULL) node[cur] = new Trie();
		node[cur]->insert(str+1);
	}
	
	bool find(char *str) {
		if(*str==NULL) {
			return false;
		}
		
		if(finish==true) {
			return true;
		}
		
		int cur = *str-'0';
		if(node[cur]==NULL) return false;
		return node[cur]->find(str+1);
	}
};

char input[100000][11];
vector<string> book;

int main() {
	int tc;
	cin >> tc;
	while(tc--) {
		int n;
		string str;
		cin >> n;
		Trie *root = new Trie();
		for(int i=0; i<n; i++) {
			cin >> input[i];
			book.push_back(input[i]);
			root->insert(input[i]);
		}
		for(int i=0; i<n; i++) {
			if(root->find(input[i])) {
				cout << "NO\n";
				break;
			}
			else if(i==n-1) {
				cout << "YES\n";
			}
		}
	}
}