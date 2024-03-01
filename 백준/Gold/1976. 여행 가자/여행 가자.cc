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

void input(vector<vector<int>>& graph, vector<int>& sequence) {
    int row, col;
    cin >> row >> col;
    inputDoubleVec(graph, row, row);
    inputVec(sequence, col);
}

void solution(vector<vector<int>>& graph, vector<int>& sequence) {
    
    vector<int> check(graph.size());
    check[sequence.front()-1] = true;

    list<int> q;
    q.push_back(sequence.front() - 1);
    while (!q.empty()) {
        int idx = q.front();
        q.pop_front();
        for (int i = 0; i < graph[idx].size(); i++) {
            if (graph[idx][i] == 1 && !check[i]) {
                q.push_back(i);
                check[i] = true;
            }
        }
    }
    
    //printVec(check);

    for (int i = 0; i < sequence.size(); i++) {
        int idx = sequence[i] - 1;
        if (!check[idx]) {
            cout << "NO" << endl;
            return;
        }
    }

    cout << "YES" << endl;
    return;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    vector<vector<int>> graph;
    vector<int> sequence;
    input(graph, sequence);
    solution(graph, sequence);

}
