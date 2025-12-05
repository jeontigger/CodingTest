class Solution {
public:
    static constexpr int INF = 1e9;
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, INF);
        dp[0] = 0;
        for(int coin : coins){
            for(int i = coin; i <= amount; i++){
                dp[i] = min(dp[i], dp[i-coin] + 1);
            }
        }

        return dp[amount] == INF? -1 : dp[amount];
    }
};