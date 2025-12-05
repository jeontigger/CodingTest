class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        // 입력을 0과 1의 개수로 변경
        // dp[0개수][1개수] => 구성할 수 있는 최대 개수?
        // m => 0, n => 1 개수
        int N = strs.size();
        vector<pair<int, int>> nums(N);
        for (int i = 0; i < N; i++) {
            int one = 0, zero = 0;
            for (int j = 0; j < strs[i].size(); j++) {
                if (strs[i][j] == '0')
                    zero++;
                else
                    one++;
            }
            nums[i] = {zero, one};
        }

        int dp[101][101];
        memset(dp, 0, sizeof(dp));

        dp[0][0] = 0;
        for (auto& [zero, one] : nums) {
            for (int i = m; i >= zero; i--) {
                for (int j = n; j >= one; j--) {
                    
                    // if (dp[i - zero][j - one] != 0)
                        dp[i][j] = max(dp[i][j], dp[i - zero][j - one] + 1);
                }
            }
        }
        return dp[m][n];
    }
};