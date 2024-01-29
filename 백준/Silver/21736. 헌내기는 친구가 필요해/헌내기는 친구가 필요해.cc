#pragma once
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;

pair<int, int> doyeonPos;
void input(vector<vector<char>>& vec) {
    int row, col;
    cin >> row >> col;

    vec.resize(row);
    for (size_t i = 0; i < row; i++)
    {
        vec[i].resize(col);
        for (size_t j = 0; j < col; j++)
        {
            cin >> vec[i][j];
            if (vec[i][j] == 'I') {
                doyeonPos = { i, j };
            }
        }
    }
}

int nRow[4] = {0, 1, 0, -1};
int nCol[4] = {1, 0, -1, 0};

void solution(vector<vector<char>>& grid) {
    list<pair<int, int>> q;

    q.push_back(doyeonPos);
    grid[doyeonPos.first][doyeonPos.second] = 'X';
    
    int cnt = 0;
    while (!q.empty()) {
        auto pos = q.front();
        q.pop_front();

        for (size_t i = 0; i < 4; i++)
        {
            int nextRow = pos.first + nRow[i];
            int nextCol = pos.second + nCol[i];

            if (0 <= nextRow && nextRow < grid.size() && 0 <= nextCol && nextCol < grid[0].size()) {
                if (grid[nextRow][nextCol] != 'X') {
                    if (grid[nextRow][nextCol] == 'P') {
                        cnt++;
                    }
                    grid[nextRow][nextCol] = 'X';
                    q.push_back({ nextRow, nextCol });
                }
            }
        }
    }

    if (cnt == 0) {
        cout << "TT" << endl;
    }
    else {
        cout << cnt << endl;
    }
}


int main()
{
    vector<vector<char>> grid;
    input(grid);

    solution(grid);

}
