#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<int> money) {
    int answer = 0;
    vector<vector<int>> dp(2, vector<int>(money.size()));
    
    // 동그랗게 되어있으니까 0번집을 털었을 때 마지막 집을 털면 안됨
    // 0번집을 털었을 때와 0번집을 안털었을 때를 기준으로 나눔
    
    // 0번 집을 털었을 때
    dp[0][0] = money[0];
    dp[0][1] = max(money[0], money[1]);
    
    // 0번 집을 안털었을 때
    dp[1][0] = 0;
    dp[1][1] = money[1];
    for(int i = 2; i < money.size()-1; i++){
        dp[0][i] = max(dp[0][i-1], dp[0][i-2] + money[i]);
        dp[1][i] = max(dp[1][i-1], dp[1][i-2] + money[i]);
    }
    int i = money.size()-1;
    dp[1][i] = max(dp[1][i-1], dp[1][i-2] + money[i]);
    
    
    // for(auto& v: dp){
    //     for(int i : v){
    //         cout << i << ' ' ;
    //     }cout << '\n';
    // }
        
    return max(*max_element(dp[0].begin(), dp[0].end()), *max_element(dp[1].begin(), dp[1].end()));
}