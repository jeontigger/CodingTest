class Solution {
public:
    void sortColors(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;

        for(int i =0; i<nums.size();i++){
            
            int num = nums[i];
            int temp = -1;
            if(num == 0){
                temp = nums[i];
                nums[i] = nums[left];
                nums[left] = temp;
                left++;
            }

            if(num == 2){
                temp = nums[i];
                nums[i] = nums[right];
                nums[right] = temp;
                right--;
                i--;
            }
            
            if(left >= right || right <= i){
                break;
            }
            
        }
    }
};