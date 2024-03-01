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
vector<int> g_dp;

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

void input(vector<int>& vec) {
    int n;
    cin >> n;

    inputVec(vec, n);
}

int bs(int targetNum) {

    int left = 0;
    int right = g_dp.size() - 1;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (g_dp[mid] < targetNum) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return left;
}

void solution(vector<int>& vec) {
    g_dp.clear();

    g_dp.push_back(vec.front());
    for (int i = 1; i < vec.size(); i++) {
        int lastNum = g_dp.back();
        int curNum = vec[i];

        if (lastNum < curNum) {
            g_dp.push_back(curNum);
        }
        else {
            int idx = bs(curNum);
            g_dp[idx] = curNum;
        }
    }
    //printVec(g_dp);
    cout << g_dp.size();
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> vec;
    input(vec);
    solution(vec);

}