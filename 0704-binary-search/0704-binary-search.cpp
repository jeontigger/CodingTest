class Solution {
public:
    int search(vector<int>& nums, int target) {
        auto iter = find(nums.begin(), nums.end(), target);
        if(iter == nums.end()){
            return -1;
        }
        return iter - nums.begin();
    }
};