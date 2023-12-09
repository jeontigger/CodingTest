class Solution {
public:

    int targetK = 0;
    set<vector<int>> res;
    void Comb(int cur, int n, vector<int> data){

        if(data.size() == targetK){
            res.insert(data);
            return;
        }
        
        
        for(int i = cur; i< n+1;i++){
            data.push_back(i);
            // for(int in:data){
            //     cout << in << " ";
            // }
            // cout << endl;
            Comb(i+1, n, data);
            data.pop_back();
        }

        return;
    }

    vector<vector<int>> combine(int n, int k) {
        targetK = k;

        Comb(1, n, {});

        vector<vector<int>> result;
        for(vector<int> vec:res){
            result.push_back(vec);
        }
        return result;
    }
};