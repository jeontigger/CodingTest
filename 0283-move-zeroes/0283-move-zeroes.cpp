class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        auto iter = remove(nums.begin(), nums.end(), 0);
        for(;iter != nums.end(); ++iter){
            *iter = 0;
        }
    }
};