class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int del = 0, left = 0, ret = 0;

        for(int right = 0; right < nums.size(); right++){

            if(nums[right] == 0) del++;

            while(del > 1){
                if(nums[left] == 0) del--;
                left++;
            }
            ret = max(ret, right - left + 1);
        }


        return ret -1;
    }
};