class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int N = nums1.size(), M = nums2.size();
        vector<vector<int>> dp(N, vector<int>(M));

        for (int i = 0; i < nums1.size(); i++) {
            for (int j = 0; j < nums2.size(); j++) {
                int a = nums1[i], b = nums2[j];
                dp[i][j] = a*b;
                // a, b의 dot
                if (i > 0 && j > 0)
                    dp[i][j] = max(dp[i][j], max(0, dp[i - 1][j - 1]) + a * b);

                // i 만 빠질경우
                if (i > 0)
                    dp[i][j] = max(dp[i][j], dp[i - 1][j]);

                if (j > 0)
                    dp[i][j] = max(dp[i][j], dp[i][j - 1]);
            }
        }

        return dp[N - 1][M - 1];
    }
};