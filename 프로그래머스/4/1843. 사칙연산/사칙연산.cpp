#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

vector<vector<int>> dp;
vector<vector<int>> mindp;
void DC(vector<string>& arr, int start, int end){
    if(start == end)
    {
        // cout << start << '\n';
        dp[start][start] = stoi(arr[start]);
        mindp[start][start] = stoi(arr[start]);
    }
    for(int i = start + 1 ; i < end; i+=2){
        if(dp[start][i-1] == -1e9)
            DC(arr, start, i-1);
        if(dp[i+1][end] == -1e9)
            DC(arr, i+1, end);
        // cout << i+1 << ' ' << end << '\n';
        
        if(arr[i] == "+"){
            dp[start][end] = max(dp[start][end], dp[start][i-1] + dp[i+1][end]);
            mindp[start][end] = min(mindp[start][end], mindp[start][i-1] + mindp[i+1][end]);
        }else{
            dp[start][end] = max(dp[start][end], dp[start][i-1] - mindp[i+1][end]);
            mindp[start][end] = min(dp[start][end], mindp[start][i-1] - dp[i+1][end]);
        }
        
    }
}

int solution(vector<string> arr)
{
    int answer = -1;
    dp.resize(arr.size(), vector<int>(arr.size(), -1e9));
    mindp.resize(arr.size(), vector<int>(arr.size(), 1e9));
    DC(arr, 0, arr.size()-1);
    
    // for(auto& v:dp){
    //     for(int i: v){
    //         cout << i << ' ';
    //     }
    //     cout << '\n';
    // }
    return dp[0].back();
}