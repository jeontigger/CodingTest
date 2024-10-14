class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        
        int targetIdx = 0;

        if(nums.size()==0){
            return {-1, -1};
        }

        while(left <= right){
            int mid = (left + right) / 2;

            if(nums[mid] == target){
                targetIdx = mid;
                break;
            }else if(nums[mid] < target){
                left = mid + 1;
            }else{
                right = mid - 1;
            }
        }

        if(nums[targetIdx] != target){
            return {-1, -1};
        }

        int startIdx, endIdx;
        for(int i = targetIdx; i >= 0; i--){
            if(nums[i] != target)
                break;
            startIdx = i;
        }
        for(int i = targetIdx; i < nums.size(); i++){
            if(nums[i] != target)
                break;
            endIdx = i;
        }

        return {startIdx, endIdx};
    }
};