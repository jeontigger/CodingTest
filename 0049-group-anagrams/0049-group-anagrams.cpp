class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        unordered_map<string, vector<string>> m;

        for(int i =0; i<strs.size();i++){
            string str = strs[i];
            
            sort(str.begin(), str.end());
            m[str].push_back(strs[i]);
        }
        
        vector<vector<string>> res;
        for(const pair<string, vector<string>> & p:m){
            res.push_back(p.second);
        }

        return res;
    }
};