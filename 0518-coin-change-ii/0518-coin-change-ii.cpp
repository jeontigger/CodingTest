class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<long long> dp(amount + 1, 0);
        // if(amount == 0) return 1;
        dp[0] = 1;

        for (int coin : coins) {
            for (int j = coin; j <= amount; j++) {

                dp[j] = (dp[j] +dp[j - coin])%2000000017;
            }
        }

        return dp[amount];
    }
};

// 1 = 1
// 2 = 1+1, 2
// 3 = 1+1+1, 1+2
// 4 = 1+1+1+1, 1+1+2, 2+2
// 5 = 1+1+1+1+