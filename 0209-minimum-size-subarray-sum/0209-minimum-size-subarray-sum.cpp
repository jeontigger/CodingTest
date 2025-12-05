class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int sum = 0, ret = nums.size(), left = 0;
        bool never = true;

        for (int right = 0; right < nums.size(); right++) {
            sum += nums[right];

            while (sum >= target) {
                never = false;
                ret = min(ret, right - left + 1);
                sum -= nums[left++];
            }
        }

        return never ? 0 : ret;
    }
};