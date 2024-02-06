#pragma once
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;

void input(vector<vector<int>>& stickers) {
    int n;
    cin >> n;

    stickers.resize(2);
    for (size_t i = 0; i < 2; i++)
    {
        stickers[i].resize(n);
        for (size_t j = 0; j < n; j++)
        {
            cin >> stickers[i][j];
        }
    }

}

void solution(vector<vector<int>>& stickers) {
    vector<vector<int>> dp;
    dp.resize(2);
    dp[0].resize(stickers[0].size());
    dp[1].resize(stickers[0].size());

    dp[0][0] = stickers[0][0];
    dp[1][0] = stickers[1][0];
    dp[0][1] = stickers[0][1] + stickers[1][0];
    dp[1][1] = stickers[1][1] + stickers[0][0];

    for (int i = 2; i < stickers[0].size(); i++) {
        dp[0][i] = stickers[0][i] + max(dp[1][i - 1], dp[1][i - 2]);
        dp[1][i] = stickers[1][i] + max(dp[0][i - 1], dp[0][i - 2]);
        
    }

    cout << max(dp[0].back(), dp[1].back()) << endl;



}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int caseCnt;
    cin >> caseCnt;

    vector<vector<int>> stickers;
    for (size_t i = 0; i < caseCnt; i++)
    {
        input(stickers);
        solution(stickers);
    }
    
}
