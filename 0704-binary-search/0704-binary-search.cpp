class Solution {
public:
    int solution1(vector<int>& nums, int target){
        auto iter = find(nums.begin(), nums.end(), target);
        if(iter == nums.end()){
            return -1;
        }
        return iter - nums.begin();
    }

    int solution2(vector<int>& nums, int target){
        int left = 0;
        int right = nums.size()-1;
        while(true){
            int idx = (right + left) / 2;
            int num = nums[idx];
            cout << idx << " " << num << endl;
            if(num < target){
                left = idx+1;
            }else if(target < num){
                right = idx - 1;
            }else{
                return idx;
            }
            
            if(right < left){
                return -1;
            }
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int res = 0;
        // res = solution1(nums, target);
        res = solution2(nums, target);

        return res;
    }
};