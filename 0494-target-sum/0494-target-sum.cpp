class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        unordered_map<int, int> table;

        table[0] = 1;
        for(int num : nums){
            unordered_map<int, int> tmp;
            for(const auto& [total, count]: table){
                tmp[total + num] += count;
                tmp[total - num] += count;
            }
            table = tmp;
        }

        return table[target];
    }
};