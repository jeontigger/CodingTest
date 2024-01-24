#pragma once
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;

int MAXROW;
int MAXCOL;
void input(vector<vector<char>>& data) {
    int row, col;
    cin >> row >> col;

    MAXROW = row;
    MAXCOL = col;

    data.resize(row);
    for (size_t j = 0; j < row; j++)
    {
        data[j].resize(col);
        for (size_t i = 0; i < col; i++)
        {
            cin >> data[j][i];
        }
    }

}

bool check[26];
int maxValue = 0;
void solution(vector<vector<char>>& data, int _row, int _col, int cnt) {

    // 범위 예외처리
    if (_row < 0 || data.size() <= _row || _col < 0 || data[0].size() <= _col)
        return;

    // 탈출 조건
    char c = data[_row][_col];
    if (check[c - 'A'])
    {
        maxValue = max(cnt, maxValue);
        return;
    }


    check[c - 'A'] = true;

    solution(data, _row + 1, _col, cnt+1);
    solution(data, _row, _col - 1, cnt + 1);
    solution(data, _row - 1, _col, cnt + 1);
    solution(data, _row, _col + 1, cnt + 1);

    check[c - 'A'] = false;


}

int main()
{
    vector<vector<char>> data;

    input(data);

    if (MAXROW == 1 && MAXCOL == 1) {
        cout << 1 << endl;
        return 0;
    }

    solution(data, 0, 0, 0);

    cout << maxValue << endl;

    return 0 ;
}
