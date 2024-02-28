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

void input(vector<vector<int>>& vec) {

    int n;
    cin >> n;

    vec.resize(n);
    for (size_t i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        vec[i].resize(n);
        for (size_t j = 0; j < str.length(); j++)
        {
            if (str[j] == '0') {
                vec[i][j] = 0;
            }
            else {
                vec[i][j] = 1;
            }
        }
    }
    
}

void solution(vector<vector<int>>& maps) {
    
    list<pair<int, int>> q;
    vector<int> res;
    for (size_t i = 0; i < maps.size(); i++)
    {
        for (size_t j = 0; j < maps[i].size(); j++)
        {
            if (maps[i][j] == 1) {
                q.emplace_back(i, j);
                maps[i][j] = 0;
            }
            int cnt = 0;
            while (!q.empty()) {
                auto pos = q.front();
                q.pop_front();
                cnt++;

                for (size_t k = 0; k < 4; k++)
                {
                    int nrow = pos.first + g_nrow[k];
                    int ncol = pos.second + g_ncol[k];

                    if (0 <= nrow && nrow < maps.size() && 0 <= ncol && ncol < maps.size()) {
                        if (maps[nrow][ncol] == 1) {
                            q.emplace_back(nrow, ncol);
                            maps[nrow][ncol] = 0;
                        }
                    }
                }
            }
            if(cnt != 0)
                res.push_back(cnt);
        }
    }
    sort(res.begin(), res.end());
    cout << res.size() << endl;
    for (auto i : res) {
        cout << i << " ";
    }
}



int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    vector<vector<int>> maps;
    input(maps);
    solution(maps);

}
