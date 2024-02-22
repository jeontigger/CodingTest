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
int g_target = 0;

vector<int> dp;

struct fData {
    int cost;
    int memory;
};

void input(vector<fData>& apps) {
    cin >> g_cnt >> g_target;

    apps.resize(g_cnt);
    for (size_t i = 0; i < g_cnt; i++)
    {
        cin >> apps[i].memory;
    }
    for (size_t i = 0; i < g_cnt; i++)
    {
        cin >> apps[i].cost;
    }

    sort(apps.begin(), apps.end(), [](const fData& d1, const fData& d2) { return (float)d1.memory / d1.cost > (float)d2.memory / d2.cost; });
}


void solution(vector<fData>& apps) {
    dp.resize(10001);

    dp[0] = 0;

    vector<int> prev;

    for (int i = 0; i < apps.size(); i++)
    {
        auto app = apps[i];
        prev = dp;
        for (int j = app.cost; j < dp.size(); j++) {
            dp[j] = max(prev[j], prev[j - app.cost] + app.memory);
        }
    }

    for (size_t i = 0; i < dp.size(); i++)
    {
        //cout << dp[i] << " ";
        if (dp[i] >= g_target) {
            cout << i;
            return;
        }
    }
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    vector<fData> apps;
    input(apps);
    solution(apps);

}
