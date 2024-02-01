#pragma once
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;


void input(vector<vector<int>>& vec) {
    int row, col;
    cin >> row >> col;

    vec.resize(row);
    for (size_t i = 0; i < row; i++)
    {
        vec[i].resize(col);
        for (size_t j = 0; j < col; j++)
        {
            cin >> vec[i][j];
        }
    }
}

int CountZero(vector<vector<int>>& lab) {
    int cnt = 0;
    for (auto v : lab) {
        for (int i : v) {
            if (i == 0) {
                cnt++;
            }
        }
    }
    return cnt;
}

int nrow[4] = { 0, 1, 0, -1 };
int ncol[4] = { 1, 0, -1, 0 };
int BFS(vector<vector<int>> lab) {
    list<pair<int, int>> q;

    for (int i = 0; i < lab.size(); i++) {
        for (size_t j = 0; j < lab[i].size(); j++)
        {
            if (lab[i][j] != 2) {
                continue;
            }

            q.push_back({ i,j });
            while (!q.empty()) {
                auto curpos = q.front();
                q.pop_front();
                for (size_t k = 0; k < 4; k++)
                {
                    int newrow = curpos.first + nrow[k];
                    int newcol = curpos.second + ncol[k];
                    if (0 <= newrow && newrow < lab.size() && 0 <= newcol && newcol < lab[0].size()) {
                        if (lab[newrow][newcol] == 0) {
                            lab[newrow][newcol] = 2;
                            q.push_back({ newrow, newcol });
                        }
                    }
                }
            }
        }
    }

    return CountZero(lab);
}

void solution(vector<vector<int>>& lab) {
    int row = lab.size();
    int col = lab[0].size();
    int totalCnt = row * col;
    int maxi = 0;
    for (size_t i = 0; i < totalCnt; i++)
    {
        pair<int, int> ipos = { i / col, i % col };
        if (lab[ipos.first][ipos.second] != 0)
            continue;
        lab[ipos.first][ipos.second] = 1;

        for (size_t j = i + 1; j < totalCnt; j++)
        {
            pair<int, int> jpos = { j / col, j % col };
            if (lab[jpos.first][jpos.second] != 0)
                continue;
            lab[jpos.first][jpos.second] = 1;

            for (size_t k = j + 1; k < totalCnt; k++)
            {
                pair<int, int> kpos = { k / col, k % col };
                if (lab[kpos.first][kpos.second] != 0)
                    continue;

                lab[kpos.first][kpos.second] = 1;
                maxi = max(maxi, BFS(lab));
                lab[kpos.first][kpos.second] = 0;
                
            }
            lab[jpos.first][jpos.second] = 0;
        }
        lab[ipos.first][ipos.second] = 0;
    }


    cout << maxi << endl;
}


int main()
{
    vector<vector<int>> lab;

    input(lab);

    solution(lab);

}
