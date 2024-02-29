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
vector<vector<int>> g_dp;
vector<vector<int>> g_visited;

#pragma region FUNC

struct fData {
    int row;
    int col;

    fData(int _r, int _c) : row(_r), col(_c) {}

    friend ostream& operator<< (ostream& os, fData data);
};

ostream& operator<<(ostream& os, fData data)
{
    os << data.row << " " << data.col << endl;
    return os;
}


template<typename T>
void printVec(vector<T>& vec) {
    for (size_t i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << " ";
    }
    cout << endl;
}

template <typename T>
void printDoubleVec(vector<vector<T>>& vec) {
    for (size_t i = 0; i < vec.size(); i++)
    {
        printVec(vec[i]);
    }
}

template<typename T>
void inputVec(vector<T>& vec, int n) {
    vec.resize(n);
    for (size_t i = 0; i < vec.size(); i++)
    {
        cin >> vec[i];
    }
}

template<typename T>
void inputDoubleVec(vector<vector<T>>& vec, int r, int c) {
    vec.resize(r);
    for (size_t i = 0; i < r; i++)
    {
        inputVec(vec[i], c);
    }
}
#pragma endregion

void input(vector<vector<int>>& vec) {
    int n;
    cin >> n;
    inputDoubleVec(vec, n, n);
    
    vector<vector<int>> tmp(n, vector<int>(n, 0));
    g_dp = tmp;
    g_visited = tmp;
}
int maxDepth = 0;
int dfs(vector<vector<int>>& bamboos, int _row, int _col, int depth);

void solution(vector<vector<int>>& maps) {
    //printDoubleVec(maps);

    for (size_t i = 0; i < maps.size(); i++)
    {
        for (size_t j = 0; j < maps[i].size(); j++)
        {
            dfs(maps, i, j, 1);
        }
    }

    //dfs(maps, 2, 2, 1);

    //printDoubleVec(g_dp);

    cout << maxDepth << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    vector<vector<int>> maps;
    input(maps);
    solution(maps);

}

int dfs(vector<vector<int>>& bamboos, int _row, int _col, int depth)
{
    if (g_visited[_row][_col] == true)
        return 0;
    
    if (g_dp[_row][_col] != 0)
        return g_dp[_row][_col];

    g_visited[_row][_col] = true;
    for (size_t i = 0; i < 4; i++)
    {
        int nrow = _row + g_nrow[i];
        int ncol = _col + g_ncol[i];

        int sum = 1;
        if (0 <= nrow && nrow < bamboos.size() && 0 <= ncol && ncol < bamboos[0].size()) {
            if(bamboos[_row][_col] < bamboos[nrow][ncol])
                sum += dfs(bamboos, nrow, ncol, depth+1);
        }

        g_dp[_row][_col] = max(g_dp[_row][_col], sum);
        maxDepth = max(maxDepth, g_dp[_row][_col]);
    }

    g_visited[_row][_col] = false;


    return g_dp[_row][_col];
}
