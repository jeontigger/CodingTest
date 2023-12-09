class Solution {
public:
    vector<int> g_candidates;
    int g_target;
    vector<vector<int>> res;
    void Comb(vector<int> data, int sum, int idx){
        if(g_target == sum){
            res.push_back(data);
            return;
        }

        if(g_target < sum){
            return;
        }

        for(int i = idx; i<g_candidates.size();i++){
            data.push_back(g_candidates[i]);
            sum+=g_candidates[i];
            Comb(data, sum, i);
            sum-= g_candidates[i];
            data.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        g_candidates = candidates;
        g_target = target;
        Comb({}, 0, 0);

        return res;
    }
};