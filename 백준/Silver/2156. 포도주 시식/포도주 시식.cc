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

void input(vector<int>& wines) {
    int n;
    cin >> n;

    inputVec(wines, n);
}

void solution(vector<int>& wines) {
    vector<int> dp_NEx(wines.size());
    vector<int> dp_PEx(wines.size());
    vector<int> dp_PPEx(wines.size());

    dp_NEx[0] = wines[0];
    dp_PEx[0] = wines[0];
    dp_PPEx[0] = wines[0];
    dp_NEx[1] = wines[0];
    dp_PEx[1] = wines[1];
    dp_PPEx[1] = wines[0] + wines[1];
    for (int i = 2; i < wines.size(); i++) {
        dp_NEx[i] = dp_PPEx[i - 1];
        dp_PEx[i] = max(dp_NEx[i - 1] + wines[i], dp_NEx[i]);
        dp_PPEx[i] = max(dp_PEx[i - 1] + wines[i], dp_PEx[i]);
    }

    //printVec(dp_NEx);
    //printVec(dp_PEx);
    //printVec(dp_PPEx);

    cout << max(*max_element(dp_PEx.begin(), dp_PEx.end()), *max_element(dp_PPEx.begin(), dp_PPEx.end()));
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> wines;
    input(wines);
    solution(wines);

}
