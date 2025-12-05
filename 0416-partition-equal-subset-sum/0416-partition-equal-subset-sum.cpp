class Solution {
public:
    // constexpr int INF = 1e9;
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int num : nums) {
            sum += num;
        }
        if (sum % 2 == 1)
            return false;

        int targetSum = sum / 2;
        vector<bool> diff(targetSum + 1, false);
        diff[0] = true;

        for (int i = 0; i < nums.size(); i++) {
            for (int j = targetSum; j >= nums[i]; j--) {
                diff[j] = diff[j] | diff[j - nums[i]];
            }
        }

        return diff[targetSum];
    }
};