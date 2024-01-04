class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> dp(nums.size());

        int maxNum = nums[0];
        dp[0] = maxNum;
        int res = maxNum;
        for(int i = 1; i<nums.size();i++){
            int num = nums[i];
            maxNum = max(num, dp[i-1] + num);
            dp[i] = maxNum;

            res = max(res, maxNum);
        }

        // for(int i: dp){
        //     cout << i << " ";
        // }
        // cout << endl;

        return res;
    }
};