class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = 0, right = nums.size()-1;

        int targetIdx = 0;

        if(nums.size() == 0) return {-1, -1};
        
        // find left side
        while(left <= right){
            int mid = (left + right) / 2;

            if(nums[mid] == target){
                left = mid + 1;
                targetIdx = mid;
            }else if(nums[mid] > target){
                right = mid - 1;
            }else{
                left = mid + 1;
            }
        }
        if(nums[targetIdx] != target) {return {-1, -1};}
        int endIdx = targetIdx;

        left = 0, right = nums.size()-1;
        // find right side
        while(left <= right){
            int mid = (left + right) / 2;

            if(nums[mid] == target){
                right = mid - 1;
                targetIdx = mid;
            }else if(nums[mid] > target){
                right = mid - 1;
            }else{
                left = mid + 1;
            }
        }
        int startIdx = targetIdx;

        return {startIdx, endIdx};
    }
};