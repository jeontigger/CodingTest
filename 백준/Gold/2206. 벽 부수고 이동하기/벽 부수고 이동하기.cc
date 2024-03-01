#pragma once
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <queue>
#include <string>
#include <unordered_set>
#include <limits.h>

using namespace std;
int g_row;
int g_col;
int g_nrow[4] = { 0, 1, 0, -1 };
int g_ncol[4] = { 1, 0, -1, 0 };

int g_cnt = 0;
int g_target = 0;
vector<int> g_dp;

#pragma region FUNC

struct fData {
    int row;
    int col;
    int cnt;
    bool b;
    fData(int _cnt, int _row, int _col, bool _b) { cnt = _cnt; row = _row; col = _col; b = _b; }
    friend ostream& operator <<(ostream& os, const fData& data);
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

void input(vector<vector<int>>& graph) {
    int row, col;
    cin >> row >> col;
    graph.resize(row);
    for (size_t i = 0; i < row; i++)
    {
        graph[i].resize(col);
        string str;
        cin >> str;
        for (size_t j = 0; j < col; j++)
        {
            graph[i][j] = str[j] - '0';
        }
    }
}
int minValue;

void bfs(vector<vector<int>>& graph) {
    list<fData> q;
    q.emplace_back(1, 0, 0, false);
    vector<vector<int>> visited(graph.size(), vector<int>(graph[0].size(), 0));
    vector<vector<int>> visited_b(graph.size(), vector<int>(graph[0].size(), 0));
    visited[0][0] = true;

    //printDoubleVec(visited);

    while (!q.empty()) {
        auto data = q.front();
        q.pop_front();
        //cout << data << endl;

        if (data.row == graph.size() - 1 && data.col == graph[0].size() - 1) {
            minValue = min(minValue, data.cnt);
            
            break;
        }

        for (int i = 0; i < 4; i++) {
            int nrow = data.row + g_nrow[i];
            int ncol = data.col + g_ncol[i];

            if (0 <= nrow && nrow < graph.size() && 0 <= ncol && ncol < graph[0].size()) {
                if (data.b) {
                    if (!visited_b[nrow][ncol] && graph[nrow][ncol] == 0) {
                        q.emplace_back(data.cnt + 1, nrow, ncol, true);
                        visited_b[nrow][ncol] = true;
                    }
                }
                else {
                    if (!visited[nrow][ncol] && graph[nrow][ncol] == 0) {
                        q.emplace_back(data.cnt + 1, nrow, ncol, false);
                        visited[nrow][ncol] = true;
                    }
                    else if (graph[nrow][ncol] == 1) {
                        q.emplace_back(data.cnt + 1, nrow, ncol, true);
                        visited_b[nrow][ncol] = true;
                    }
                }
            }
        }
    }
}

void solution(vector<vector<int>>& graph) {
    minValue = INT_MAX;
    bfs(graph);

    if (minValue == INT_MAX) {
        cout << -1 << endl;
    }
    else {
        cout << minValue << endl;
    }
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    vector<vector<int>> graph;
    input(graph);
    solution(graph);

}
