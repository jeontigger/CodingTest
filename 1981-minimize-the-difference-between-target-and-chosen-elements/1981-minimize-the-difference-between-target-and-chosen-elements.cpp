class Solution {
public:
    int minimizeTheDifference(vector<vector<int>>& mat, int target) {
        // [가능한 합] => 최대 4900
        int N = mat.size();
        int M = mat[0].size();

        vector<int> dp(4901, 0);
        dp[0] = 1;
        for (int row = 0; row < N; row++) {
            auto before = dp;
            fill(dp.begin(), dp.end(), 0);
            for (int col = 0; col < M; col++) {
                int num = mat[row][col];
                for (int i = num; i < dp.size(); i++) {
                    dp[i] = dp[i] | before[i - num];
                }
            }
        }

        if (dp[target])
            return 0;
        int left = target - 1, right = target + 1;
        while(left >= 0 || right < dp.size()){
            if((left >= 0 && dp[left]) || (right < dp.size() && dp[right])){
                return abs(target - left);
            }
            left--;
            right++;
        }
        return 0;
    }
};