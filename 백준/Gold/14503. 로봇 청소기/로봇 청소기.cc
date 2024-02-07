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
int g_startRow;
int g_startCol;
int g_dir;

int g_nRows[4] = {-1, 0, 1, 0};
int g_nCols[4] = { 0, 1, 0, -1 };

void input(vector<vector<int>>& grid) {
    cin >> g_row >> g_col;
    cin >> g_startRow >> g_startCol >> g_dir;

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
    if (grid[g_startRow][g_startCol] != 0) {
        cout << 0 << endl;
        return;
    }

    pair<int, int> Pos = { g_startRow, g_startCol };
    int cleanCnt = 0;
    int curDir = g_dir;
    grid[Pos.first][Pos.second] = 2;
    int resCnt = 1;
    while (true) {
        //for (auto v : grid) {
        //    for (auto i : v) {
        //        cout << i << " ";
        //    }
        //    cout << endl;
        //}
        //cout << "====================" << endl;
        //getchar();

        pair<int, int> nPos ;
        for (size_t i = 0; i < 4; i++)
        {
            curDir--;
            if (curDir < 0)
                curDir = 3;

            nPos.first = Pos.first + g_nRows[curDir];
            nPos.second = Pos.second + g_nCols[curDir];

            if (grid[nPos.first][nPos.second] == 0) {
                break;
            }
        }

        if (grid[nPos.first][nPos.second] == 0) {
            grid[nPos.first][nPos.second] = 2;
            Pos = nPos;
            resCnt++;
        }
        else {
            nPos.first = Pos.first + g_nRows[(curDir + 2) % 4];
            nPos.second = Pos.second + g_nCols[(curDir + 2) % 4];

            if (grid[nPos.first][nPos.second] == 1) {
                break;
            }
            else if(grid[nPos.first][nPos.second] == 2){
                Pos = nPos;
            }
        }
    }
    cout << resCnt << endl;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    vector<vector<int>> grid;
    input(grid);
    solution(grid);
    
}
