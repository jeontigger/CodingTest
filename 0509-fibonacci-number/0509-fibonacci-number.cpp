class Solution {
public:
    int solution1(int n){
        if(n <= 1){
            return n;
        }

        return fib(n-1) + fib(n-2);
    }

    int solution2(int n){
        if(n <= 1){
            return n;
        }

        vector<int>dp(n+1);
        dp[0] = 0;
        dp[1] = 1;
        
        for(int i = 2; i < n+1; i++){
            dp[i] = dp[i-1] + dp[i-2];
        }

        // for(int i:dp){
        //     cout << i << " ";
        // }
        // cout << endl;

        return dp[n];
    }
    int fib(int n) {
        // return solution1(n);
        return solution2(n);
    }
};