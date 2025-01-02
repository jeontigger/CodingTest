#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    vector<int> dp(triangle.size(), 0);
    dp[0] = triangle[0][0];
    for(int i = 1; i < triangle.size(); i++){
        auto pdp = dp;
        dp[0] += triangle[i][0];
        for(int j = 1; j < triangle[i].size(); j++){
            dp[j] = max(pdp[j-1], pdp[j]) + triangle[i][j];
        }
    //         for(int i : dp){
    //     cout << i << ' ';
    // }cout << '\n';
    }

    
    return *max_element(dp.begin(), dp.end());
}