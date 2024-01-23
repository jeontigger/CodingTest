#pragma once
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;
int MAX_ROW;
int MAX_COL;
void input(vector<vector<int>>& vec) {
    int row, col, k;
    cin >> row >> col >> k;
    MAX_ROW = row;
    MAX_COL = col;
    vec.resize(row);
    for (size_t i = 0; i < row; i++)
    {
        vec[i].resize(col);
    }

    int pos[4];
    for (size_t i = 0; i < k; i++)
    {
        cin >> pos[0] >> pos[1] >> pos[2] >> pos[3];

        for (size_t j = pos[1]; j < pos[3]; j++)
        {
            for (size_t l = pos[0]; l < pos[2]; l++)
            {
                vec[j][l]++;
            }
        }
    }
}

void QueuePush(vector<vector<int>> & grid, list<pair<int, int>>& q, pair<int, int> pos) {
    int row = pos.first;
    int col = pos.second;

    if (0 <= row && row < MAX_ROW && 0 <= col && col < MAX_COL) {
        if (grid[row][col] == 0) {
            grid[row][col]++;
            q.push_back({ row, col });
        }
    }
}

void solution(vector<vector<int>>& grid) {
    
    int sectionCnt = 0;
    vector<int> sectionNum;

    list<pair<int, int>> q;
    for (size_t i = 0; i < grid.size(); i++) {
        for (size_t j = 0; j < grid[i].size(); j++)
        {
            int section = grid[i][j];
            if (section == 0) {
                q.push_back({ i, j });

                grid[i][j]++;
                sectionCnt++;
            }

            int cnt = 0;
            while (!q.empty()) {
                pair<int, int> pos = q.front();
                q.pop_front();

                cnt++;
                QueuePush(grid, q, { pos.first + 1, pos.second });
                QueuePush(grid, q, { pos.first - 1, pos.second });
                QueuePush(grid, q, { pos.first, pos.second + 1});
                QueuePush(grid, q, { pos.first, pos.second - 1});

            }
            if (cnt != 0) {
                sectionNum.push_back(cnt);
            }
        }
    }

    sort(sectionNum.begin(), sectionNum.end());
    cout << sectionCnt << endl;
    for (int i : sectionNum) {
        cout << i << " ";
    }
    cout << endl;
}

int main()
{
    vector<vector<int>> grid;

    input(grid);
    solution(grid);

}
