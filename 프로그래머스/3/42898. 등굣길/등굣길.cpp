#include <string>
#include <vector>
#include <iostream>

using namespace std;



int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    vector<vector<int>> dp(n, vector<int>(m));
    
    // [j][i] = [j-1][i] + [j][i-1];
    dp[0][0] = 1;
    for(int i = 1 ; i < m; i++){
        bool isPuddle = false;
       for(int k = 0; k < puddles.size(); k++){
           if(puddles[k][0]-1 == i && puddles[k][1] -1 == 0){
               isPuddle = true;
               break;
           }
       }

       if(isPuddle) break;
        dp[0][i] = dp[0][i-1];
    }
    
    for(int i = 1 ; i < n; i++){
        bool isPuddle = false;
       for(int k = 0; k < puddles.size(); k++){
           if(puddles[k][0]-1 == 0 && puddles[k][1] -1 == i){
               isPuddle = true;
               break;
           }
       }

       if(isPuddle) break;
        dp[i][0] = dp[i-1][0];
    }
    
    
    
    for(int i = 1 ; i < n ; i++){
       for(int j = 1 ; j < m; j++){
           
           bool isPuddle = false;
           for(int k = 0; k < puddles.size(); k++){
               if(puddles[k][0]-1 == j && puddles[k][1] -1 == i){
                   isPuddle = true;
                   break;
               }
           }
           
           if(isPuddle) continue;
           
           dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % 1000000007;
           
           
           // for(vector<int>& v:dp){
           //     for(int num : v){
           //         cout << num << " " ;
           //     }
           //      cout << endl;
           // }
           // cout << endl;
       }
        
    }
    
    answer = (dp[n-1][m-1]) % 1000000007;
    
    return answer;
}