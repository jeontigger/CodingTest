class Solution {
public:
    vector<vector<int>> res;
    vector<int> g_nums;
    void Recursive(vector<int> data, int idx){
        res.push_back(data);

        for(int i = idx; i<g_nums.size();i++){
            data.push_back(g_nums[i]);
            Recursive(data, i+1);
            data.pop_back();
        }

    }

    vector<vector<int>> subsets(vector<int>& nums) {
        g_nums = nums;
        Recursive({}, 0);

        return res;
    }
};