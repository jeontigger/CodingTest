class Solution {
public:
    vector<bool> confirm;
    vector<vector<int>> res;
    void permutation(vector<int> product,int cnt, const vector<int>& nums){
        if(cnt == nums.size()){
            res.push_back(product);
            return;
        }

        int i;
        for(i = 0; i<nums.size();i++){
            if(!confirm[nums[i]+10]){
                confirm[nums[i]+10] = true;
                product.push_back(nums[i]);
                permutation(product, cnt+1, nums);
                product.pop_back();
                confirm[nums[i]+10] = false;
            }
            
        }

        
    }
    vector<vector<int>> permute(vector<int>& nums) {
        confirm.resize(21);

        permutation({}, 0, nums);

        return res;

    }
};