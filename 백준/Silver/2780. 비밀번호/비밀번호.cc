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
int g_nrow[4] = { 0, 1, 0, -1 };
int g_ncol[4] = { 1, 0, -1, 0 };

int g_cnt = 0;
int g_depth;

vector<vector<int>> g_LockMachine;

void input() {
}

void bfs(int curNum) {

    list<pair<int, int>> q;
    int sum = 1;
    // cnt, number
    q.push_back({1, curNum});

    while (!q.empty())
    {
        auto data = q.front();

        if (data.first == g_depth) {
            g_cnt += q.size();
            return;
        }

        q.pop_front();

        sum += g_LockMachine[data.second].size();
        for (size_t i = 0; i < g_LockMachine[data.second].size(); i++)
        {
            q.push_back({data.first+1, g_LockMachine[data.second][i] });
        }
    }

    


}

void solution(int len) {
    g_cnt = 0;
    g_depth = len;

    vector<unsigned long long> dp(10, 1);
    vector<unsigned long long> prev;
    for (size_t i = 0; i < len - 1; i++)
    {
        prev = dp;
        for (size_t j = 0; j < 10; j++)
        {
            unsigned long long sum = 0;
            for (size_t k = 0; k < g_LockMachine[j].size(); k++)
            {
                sum += prev[g_LockMachine[j][k]];
            }
            sum %= 1234567;
            dp[j] = sum;
        }
    }

    unsigned long long res = 0;
    for (size_t i = 0; i < 10; i++)
    {
        res += dp[i];
    }
    cout << res % 1234567 << endl;
}

void initMachine() {
    g_LockMachine.resize(10);
    g_LockMachine[0].push_back(7);

    g_LockMachine[1].push_back(2);
    g_LockMachine[1].push_back(4);
    g_LockMachine[2].push_back(1);
    g_LockMachine[2].push_back(3);
    g_LockMachine[2].push_back(5);
    g_LockMachine[3].push_back(2);
    g_LockMachine[3].push_back(6);

    g_LockMachine[4].push_back(1);
    g_LockMachine[4].push_back(5);
    g_LockMachine[4].push_back(7);
    g_LockMachine[5].push_back(2);
    g_LockMachine[5].push_back(4);
    g_LockMachine[5].push_back(6);
    g_LockMachine[5].push_back(8);
    g_LockMachine[6].push_back(3);
    g_LockMachine[6].push_back(5);
    g_LockMachine[6].push_back(9);

    g_LockMachine[7].push_back(4);
    g_LockMachine[7].push_back(8);
    g_LockMachine[7].push_back(0);
    g_LockMachine[8].push_back(5);
    g_LockMachine[8].push_back(7);
    g_LockMachine[8].push_back(9);
    g_LockMachine[9].push_back(6);
    g_LockMachine[9].push_back(8);

}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;

    initMachine();

    for (size_t i = 0; i < n; i++)
    {
        int casenum;
        cin >> casenum;
        solution(casenum);
    }

}
