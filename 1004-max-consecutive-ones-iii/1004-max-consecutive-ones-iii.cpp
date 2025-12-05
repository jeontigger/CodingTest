class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int change = 0, left = 0, ret = 0;

        for(int right = 0 ; right < nums.size(); right++){
            if(nums[right] == 0){
                change++;
            }

            while(change > k){
                if(nums[left] == 0){
                    change--;
                }
                left++;
            }

            ret = max(ret, right - left + 1);
        }

        return ret;
    }
};