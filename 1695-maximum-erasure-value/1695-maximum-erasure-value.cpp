class Solution {
public:
    int cnts[10001];

    // 유일한 원소들로 이루어진 가장 긴 sub array 반환
    int maximumUniqueSubarray(vector<int>& nums) {
        memset(cnts, 0, sizeof(cnts));
        int ret = 0, sum = 0, left = 0;
        for (int right = 0; right < nums.size(); right++) {
            cnts[nums[right]]++;
            sum += nums[right];

            while(cnts[nums[right]] >= 2){
                sum -= nums[left];
                cnts[nums[left]]--;
                left++;
            }

            ret = max(ret, sum);
        }

        return ret;
    }
};