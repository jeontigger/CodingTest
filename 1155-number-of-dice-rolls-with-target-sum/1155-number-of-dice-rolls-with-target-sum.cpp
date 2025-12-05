class Solution {
public:
    static constexpr int MOD = 1000000007;
    int numRollsToTarget(int n, int k, int target) {
        vector<int> dp(target + 1);
        dp[0] = 1;

        for (int dice = 1; dice <= n; dice++) {
            auto before = dp;
            fill(dp.begin(), dp.end(), 0);
            for (int face = 1; face <= k; face++) {
                for (int sum = face; sum <= target; sum++) {
                    dp[sum] = (dp[sum] + before[sum - face]) % MOD;
                }
            }
        }

        return dp[target];
    }
};