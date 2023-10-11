class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<int> origin = nums;
        sort(nums.begin(), nums.end());
        
        int leftIdx, rightIdx, leftValue, rightValue, target;
        set<vector<int>> s;
        vector<vector<int>> res;
        for(int i = 0 ; i<nums.size()-1;i++){
            target = -nums[i];
            leftIdx = i+1;
            rightIdx = nums.size()-1;
            int cnt = 0;
            while(true){
                if(leftIdx==rightIdx)
                    break;
                leftValue = nums[leftIdx];
                rightValue = nums[rightIdx];
                if(leftValue + rightValue > target){
                    rightIdx--;
                }else if(leftValue + rightValue < target){
                    leftIdx++;
                }else{
                    vector<int> v = {nums[i], nums[leftIdx], nums[rightIdx]};
                    sort(v.begin(), v.end());
                    s.insert(v);
                    rightIdx--;
                }
            }
        }

        for(const vector<int>& v:s){
            res.push_back(v);
        }


        return res;
    }
};