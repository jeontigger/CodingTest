class Solution {
public:
    int solution1(vector<int>& nums){
        sort(nums.begin(), nums.end());
        return nums[nums.size()/2];
    }

    int solution2(vector<int>& nums){
        int res;
        int cnt = 0;
        for(int num : nums){
            if(cnt == 0){
                res = num;
            }

            if(res != num){
                cnt--;
            }else{
                cnt++;
            }
        }

        return res;
    }

    int majorityElement(vector<int>& nums) {
        
        // return solution1(nums);
        return solution2(nums);
        
    }
};