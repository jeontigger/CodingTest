class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        
        int left = 0, right = 0, sum = 0;
        int output = nums.size()+1;
        for(;left < nums.size();){
            if(sum < target && right < nums.size()){
                sum += nums[right];
                right++;
            }else if(sum >= target){
                sum -= nums[left];
                left++;
                output = min(output, right - left + 1);
                cout << left << " " << right << endl;
            }else{
                sum -= nums[left];
                left++;
            }
        }
        if(output == nums.size() + 1)
            output = 0;

        return output;
    }
};