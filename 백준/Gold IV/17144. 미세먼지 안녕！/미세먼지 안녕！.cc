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
int g_time;

pair<int, int> g_conPos;

void printHouse(vector<vector<int>>& house) {
    for (size_t i = 0; i < g_row; i++)
    {
        for (size_t j = 0; j < g_col; j++)
        {
            cout << house[i][j] << " ";
        }
        cout << endl;
    }
    cout << "======================" << endl;
}

void input(vector<vector<int>>& house) {

    cin >> g_row >> g_col >> g_time;

    house.resize(g_row);
    for (int i = 0; i < g_row; i++)
    {
        house[i].resize(g_col);
        for (int j = 0; j < g_col; j++)
        {
            cin >> house[i][j];

            if (house[i][j] == -1) {
                g_conPos = { i - 1, j };
            }
        }
    }
}

int g_nrow[4] = { 0, 1, 0, -1 };
int g_ncol[4] = { 1, 0, -1, 0 };

int sumdust(const vector<vector<int>>& house);
void diffusion(vector<vector<int>>& house) {
    vector<vector<int>> diff;
    diff.resize(g_row);
    for (size_t i = 0; i < g_row; i++)
    {
        diff[i].resize(g_col);
    }
    

    for (size_t i = 0; i < g_row; i++)
    {
        for (size_t j = 0; j < g_col; j++)
        {
            int dust = house[i][j];
            

            diff[i][j] += dust;
            int diffDust = dust / 5;
            
            for (size_t k = 0; k < 4; k++)
            {
                int nrow = i + g_nrow[k];
                int ncol = j + g_ncol[k];

                if (nrow < 0 || nrow >= g_row || ncol < 0 || ncol >= g_col)
                    continue;
                if ((nrow == g_conPos.first && ncol == g_conPos.second) || (nrow == g_conPos.first + 1 && ncol == g_conPos.second))
                    continue;

                diff[nrow][ncol] += diffDust;
                diff[i][j] -= diffDust;
            }
        }
    }
    house = diff;
}
void airrotation(vector<vector<int>>& house) {

    // 위쪽 순환
    for (size_t i = g_conPos.first; i > 0; i--)
    {
        house[i][0] = house[i - 1][0];
    }

    for (size_t i = g_conPos.second; i < g_col - 1; i++)
    {
        house[0][i] = house[0][i + 1];
    }

    for (size_t i = 0; i < g_conPos.first ; i++)
    {
        house[i][g_col - 1] = house[i+1][g_col - 1];
    }

    for (size_t i = g_col - 1; i > 0; i--)
    {
        house[g_conPos.first][i] = house[g_conPos.first][i-1];
    }

    // 아래쪽 순환
    for (size_t i = g_conPos.first + 1; i < g_row - 1; i++)
    {
        house[i][0] = house[i + 1][0];
    }

    for (size_t i = 0; i < g_col - 1; i++)
    {
        house[g_row - 1][i] = house[g_row - 1][i + 1];
    }

    for (size_t i = g_row-1; i  > g_conPos.first; i--)
    {
        house[i][g_col - 1] = house[i - 1][g_col - 1];
    }

    for (size_t i = g_col - 1; i > 0; i--)
    {
        house[g_conPos.first + 1][i] = house[g_conPos.first + 1][i - 1];
    }

    house[g_conPos.first][0] = -1;
    house[g_conPos.first+1][0] = -1;
    house[g_conPos.first][1] = 0;
    house[g_conPos.first+1][1] = 0;

    
}
int sumdust(const vector<vector<int>>& house) { 
    int sum = 0;

    for (size_t i = 0; i < g_row; i++)
    {
        for (size_t j = 0; j < g_col; j++)
        {
            sum += house[i][j];
        }
    }

    return sum + 2; 
}

void solution(vector<vector<int>>& house) {

    

    for(int i = 0; i< g_time ; i++)
    {
        diffusion(house);
        airrotation(house);
    }

    cout << sumdust(house);

}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    vector<vector<int>> house;
    input(house);
    solution(house);

}
