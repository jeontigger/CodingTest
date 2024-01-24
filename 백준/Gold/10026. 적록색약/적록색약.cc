#pragma once
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;

vector<vector<bool>> check;
vector<vector<char>> g_data;
void input() {

    int n;
    cin >> n;
    g_data.resize(n);
    check.resize(n);
    for (size_t j = 0; j < n; j++)
    {
        g_data[j].resize(n);
        check[j].resize(n);
        for (size_t i = 0; i < n; i++)
        {
            cin >> g_data[j][i];
        }
    }

}
bool IsOK(int row, int col, char cur) {
    if (row < 0 || check.size() <= row || col < 0 || check.size() <= col) {
        return false;
    }

    if (check[row][col]) {
        return false;
    }

    if (g_data[row][col] != cur) {
        return false;
    }

    return true;
}

bool IsRGOK(int row, int col, char cur) {
    if (row < 0 || check.size() <= row || col < 0 || check.size() <= col) {
        return false;
    }

    if (check[row][col]) {
        return false;
    }

    if ((cur == 'R' || cur == 'G') && (g_data[row][col] == 'B')){
        return false;
    }

    if (cur == 'B' && g_data[row][col] != cur ) {
        return false;
    }
    

    return true;
}

void solution() {
    

    list<pair<int, int>> q;
    int cnt = 0;
    for (size_t i = 0; i < g_data.size(); i++)
    {
        for (size_t j = 0; j < g_data.size(); j++)
        {
            bool start = check[i][j];
            if (start) {
                continue;
            }

            q.emplace_back(i, j);
            char cur = g_data[i][j];
            check[i][j] = true;

            while (!q.empty()) {
                auto pos = q.front();
                q.pop_front();

                if (IsOK(pos.first + 1, pos.second, cur)) {
                    q.emplace_back(pos.first + 1, pos.second);
                    check[pos.first + 1][pos.second] = true;
                }
                if (IsOK(pos.first - 1, pos.second, cur)) {
                    q.emplace_back(pos.first - 1, pos.second);
                    check[pos.first - 1][pos.second] = true;
                }
                if (IsOK(pos.first, pos.second + 1, cur)) {
                    q.emplace_back(pos.first, pos.second + 1);
                    check[pos.first][pos.second + 1] = true;
                }
                if (IsOK(pos.first, pos.second - 1, cur)) {
                    q.emplace_back(pos.first, pos.second - 1);
                    check[pos.first][pos.second - 1] = true;
                }
            }
            cnt++;
        }
    }

    cout << cnt << " ";

    // 체크 초기화
    cnt = 0;
    for (size_t i = 0; i < check.size(); i++)
    {
        for (size_t j = 0; j < check.size(); j++)
        {
            check[i][j] = false;
        }
    }

    // 적록색맹 BFS
    for (size_t i = 0; i < g_data.size(); i++)
    {
        for (size_t j = 0; j < g_data.size(); j++)
        {
            bool start = check[i][j];
            if (start) {
                continue;
            }

            q.emplace_back(i, j);
            char cur = g_data[i][j];
            check[i][j] = true;

            while (!q.empty()) {
                auto pos = q.front();
                q.pop_front();

                if (IsRGOK(pos.first + 1, pos.second, cur)) {
                    q.emplace_back(pos.first + 1, pos.second);
                    check[pos.first + 1][pos.second] = true;
                }
                if (IsRGOK(pos.first - 1, pos.second, cur)) {
                    q.emplace_back(pos.first - 1, pos.second);
                    check[pos.first - 1][pos.second] = true;
                }
                if (IsRGOK(pos.first, pos.second + 1, cur)) {
                    q.emplace_back(pos.first, pos.second + 1);
                    check[pos.first][pos.second + 1] = true;
                }
                if (IsRGOK(pos.first, pos.second - 1, cur)) {
                    q.emplace_back(pos.first, pos.second - 1);
                    check[pos.first][pos.second - 1] = true;
                }
            }
            cnt++;
        }
    }
    cout << cnt << " ";
}

int main()
{
    input();

    solution();

    return 0 ;
}
