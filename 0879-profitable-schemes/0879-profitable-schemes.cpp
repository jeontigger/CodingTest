class Solution {
public:
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        const int MOD = 1e9 + 7;
        vector<vector<int>> dp(n+1, vector<int>(minProfit+1, 0));

        dp[0][0] = 1;

        for (int i = 0; i < group.size(); i++) {
            int g = group[i];
            int p = profit[i];

            for (int j = n; j >= g; j--) {
                for (int k = minProfit; k >= 0; k--) {
                    int newProfit = min(minProfit, k + p);
                    dp[j][newProfit] = (dp[j][newProfit] + dp[j - g][k]) % MOD;
                }
            }
        }

        int res = 0;
        for (int j = 0; j <= n; j++) {
            res = (res + dp[j][minProfit]) % MOD;
        }
        return res;
    }
};
