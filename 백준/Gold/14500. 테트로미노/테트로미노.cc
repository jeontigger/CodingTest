#pragma once
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;
vector<vector<int>> g_fields;
int g_row;
int g_col;

typedef  vector<vector<vector<int>>> Tetronomis;
Tetronomis t1 = { { {1, 1, 1, 1} }, {{1}, {1}, {1}, {1} } };
Tetronomis t2 = { { {1, 1}, {1, 1}} };
Tetronomis t3 = { { {1, 0},{1, 0}, {1, 1}}, {{0, 1},{0, 1}, {1, 1}},{{1, 1},{1, 0}, {1, 0} }, { {1, 1},{0, 1}, {0, 1} }, {{1, 0, 0}, {1, 1, 1}}, {{0, 0, 1}, {1, 1, 1}}, {{1, 1, 1}, {1, 0, 0}}, {{1, 1, 1}, {0, 0, 1}} };
Tetronomis t4 = { { {1, 0}, {1, 1}, {0, 1}}, { {0, 1}, {1, 1}, {1, 0}}, {{0, 1, 1}, {1, 1, 0} }, {{1, 1, 0}, {0, 1, 1} } };
Tetronomis t5 = { { {0, 1, 0}, {1, 1, 1} }, { {1, 1, 1}, {0, 1, 0}}, {{1, 0}, {1, 1}, {1, 0}}, {{0, 1}, {1, 1}, {0, 1}} };



void input() {
    cin >> g_row >> g_col;

    g_fields.resize(g_row);
    for (size_t i = 0; i < g_row; i++)
    {
        g_fields[i].resize(g_col);
        for (size_t j = 0; j < g_col; j++)
        {
            cin >> g_fields[i][j];
        }
    }
}

void printTetris(Tetronomis t) {
    for (auto vs : t) {
        cout << "=============" << endl;
        for (auto v : vs) {
            for (auto i : v) {
                cout << i << " ";
            }
            cout << endl;
        }
    }
    cout << endl;
}

int calTetris(int row, int col, const vector<vector<int>>& t) {

    int sum = 0;

    for (int i = 0; i < t.size(); i++)
    {
        for (int j = 0; j < t[i].size(); j++) {
            int mrow = i + row;
            int mcol = j + col;

            if (t[i][j]) {
                if (mrow < g_row && mcol < g_col) {
                    sum += g_fields[mrow][mcol];
                }
            }
        }
    }

    return sum;
}

int maxTetris(const Tetronomis& t) {
    int maxValue = 0;

    for(int k = 0; k < t.size(); k++) {
        for (int i = 0; i < g_row; i++) {
            for (int j = 0; j < g_col; j++) {
                maxValue = max(maxValue, calTetris(i, j, t[k]));
            }
        }
    }

    return maxValue;
}

void solution() {

    int maxValue = 0;
    maxValue = max(maxValue, maxTetris(t1));
    maxValue = max(maxValue, maxTetris(t2));
    maxValue = max(maxValue, maxTetris(t3));
    maxValue = max(maxValue, maxTetris(t4));
    maxValue = max(maxValue, maxTetris(t5));

    cout << maxValue << endl;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    input();
    solution();

}
