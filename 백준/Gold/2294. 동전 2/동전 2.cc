#pragma once
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <queue>
#include <string>
#include <limits.h>

using namespace std;

int g_cnt;
vector<int> g_dp;

void input(vector<int>& coins) {
    int n;
    cin >> n >> g_cnt;
    coins.resize(n);
    g_dp.resize(g_cnt+1, 1000000);
    for (size_t i = 0; i < n; i++)
    {
        cin >> coins[i];
    }
}
void solution(vector<int>& coins) {
    
    // idx = value, value = coins nums
    for (int i = 0; i < coins.size(); i++) {
        g_dp[coins[i]] = 1;
        for (int j = coins[i]; j < g_dp.size(); j++) {
            g_dp[j] = min(g_dp[j], g_dp[j - coins[i]] + 1);
        }
    }

    if (g_dp.back() == 1000000) {
        cout << -1 << endl;
    }
    else {
        cout << g_dp.back() << endl;
    }
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> coins;
    input(coins);
    solution(coins);

}
