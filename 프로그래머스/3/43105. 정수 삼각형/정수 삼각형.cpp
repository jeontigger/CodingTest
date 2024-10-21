#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    vector<int> dp(triangle.back().size());
    dp[0] = triangle[0][0];
    
    for(int i = 1; i < triangle.size(); i++){
        vector<int> origin = dp;
        dp[0] = dp[0] + triangle[i][0];
        
        for(int j = 1 ; j < triangle[i].size(); j++){
            dp[j] = max(origin[j-1], origin[j]) + triangle[i][j];
        }
    }
    
    answer = *max_element(dp.begin(), dp.end());
    return answer;
}