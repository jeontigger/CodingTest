#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    vector<vector<int>> dp(triangle.size(), vector<int>(triangle.size()));
    
    dp[0][0] = triangle[0][0];
    dp[1][0] = triangle[1][0] + dp[0][0];
    dp[1][1] = triangle[1][1] + dp[0][0];
    
    for(int i =2 ; i < triangle.size();i++){
        dp[i][0] = triangle[i][0] + dp[i-1][0];
        for(int j = 1; j < triangle[i].size();j++){
            dp[i][j] = max(dp[i-1][j-1], dp[i-1][j]) + triangle[i][j];
        }
    }
    
    // for(auto& v:dp){
    //     for(int i : v){
    //         cout << i << " ";
    //     }
    //     cout << endl;
    // }
    
    
    answer = *max_element(dp.back().begin(), dp.back().end());
    
    return answer;
}