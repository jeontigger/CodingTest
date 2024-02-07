#pragma once
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;

int g_row;
int g_col;

int g_nrow[4] = { 0, 1, 0, -1 };
int g_ncol[4] = { 1, 0, -1, 0 };


void input(vector<vector<int>>& grid) {
    cin >> g_col >> g_row;

    grid.resize(g_row);

    for (size_t i = 0; i < g_row; i++)
    {
        grid[i].resize(g_col);
        for (size_t j = 0; j < g_col; j++)
        {
            cin >> grid[i][j];
        }
    }
}

void solution(vector<vector<int>> grid) {
    struct fData {
        int row;
        int col;
        int cnt;
    };

    list<fData> q;
    fData data = {};
    for (size_t i = 0; i < g_row; i++)
    {
        for (size_t j = 0; j < g_col; j++)
        {
            if (grid[i][j] == 1) {
                data.row = i;
                data.col = j;
                data.cnt = 0;
                q.push_back(data);
            }
        }
    }

    int maxCnt = 0;

    while (!q.empty()) {
        auto data = q.front();
        q.pop_front();

        for (size_t i = 0; i < 4; i++)
        {
            int nrow = data.row + g_nrow[i];
            int ncol = data.col + g_ncol[i];

            if (0 <= nrow && nrow < g_row && 0 <= ncol && ncol < g_col) {
                if (grid[nrow][ncol] == 0) {
                    fData _data = {};
                    _data.row = nrow;
                    _data.col = ncol;
                    _data.cnt = data.cnt + 1;
                    q.push_back(_data);
                    grid[nrow][ncol] = 1;

                    maxCnt = max(maxCnt, _data.cnt);
                }
            }
        }

    }



    for (size_t i = 0; i < g_row; i++)
    {
        for (size_t j = 0; j < g_col; j++)
        {
            if (grid[i][j] == 0) {
                cout << -1 << endl;
                return;
            }
        }
    }

    cout << maxCnt << endl;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    vector<vector<int>> grid;
    input(grid);
    solution(grid);
    
}
