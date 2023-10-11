class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int prod = 1;
        int zeroCount = 0;
        for(int i = 0; i<nums.size();i++){
            prod*=nums[i];
            if(nums[i]==0){
                zeroCount++;
            }
        }
        // cout << zeroCount << endl;
        if(zeroCount==0){
            for(int i = 0; i<nums.size();i++){
                nums[i] = prod / nums[i];
            }
        }else if(zeroCount == 1){
            prod = 1;
            int zeroIdx = 0;
            for(int i = 0; i<nums.size();i++){
                if(nums[i]!=0){
                    prod*=nums[i];
                }else{
                    zeroIdx = i;
                }
                nums[i] = 0;
            }
            nums[zeroIdx] = prod;
        }else{
            for(int i = 0; i<nums.size();i++){
                nums[i] = 0;
            }
        }

        
        return nums;
    }
};