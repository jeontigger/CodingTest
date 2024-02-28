#pragma once
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <queue>
#include <string>
#include <unordered_set>

using namespace std;
int g_row;
int g_col;
int g_nrow[4] = { 0, 1, 0, -1 };
int g_ncol[4] = { 1, 0, -1, 0 };

int g_cnt = 0;
int g_target = 0;

void input() {
    
}

void solution() {
    
    unordered_set<string> set;
    vector<string> res;
    int listen, watch;
    cin >> listen >> watch;

    for (size_t i = 0; i < listen; i++)
    {
        string str;
        cin >> str;
        set.insert(str);
    }
    for (size_t i = 0; i < listen; i++)
    {
        string str;
        cin >> str;
        if (set.find(str) != set.end()) {
            res.push_back(str);
        }
    }
    sort(res.begin(), res.end());
    cout << res.size() << endl;
    for (size_t i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
    
}



int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    input();
    solution();

}
