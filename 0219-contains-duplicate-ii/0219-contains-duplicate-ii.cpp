class Solution {
public:
    unordered_map<int, int> cnts;
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        bool ret = false;

        int left = 0;
        for(int right = 0; right < nums.size(); right++){
            cnts[nums[right]]++;
            if(cnts[nums[right]]>=2){
                ret = true;
                break;
            }
            
            if(right - left >= k){
                cnts[nums[left++]]--;
            }
        }


        return ret;
    }
};