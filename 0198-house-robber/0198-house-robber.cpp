class Solution {
public:
    int rob(vector<int>& nums) {
        
        vector<int> dp(nums.size());
        
        int sum = 0;
        int res = 0;

        int maxNum = 0;
        for(int i = 0; i < nums.size(); i++){
            int num = nums[i];
            dp[i] = num + maxNum;

            if(i <= 0){
                maxNum = 0;
            }else{
                maxNum = max(maxNum, dp[i-1]);
            }
        }

        maxNum = *max_element(dp.begin(), dp.end());
        
        for(int i:dp){
            cout << i << " " ;
        }
        cout << endl;

        return maxNum;
    }
};