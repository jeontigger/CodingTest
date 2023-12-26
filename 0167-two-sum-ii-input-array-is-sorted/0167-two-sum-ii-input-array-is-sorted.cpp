class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int idx1 = 0;
        int idx2 = numbers.size()-1;

        while(idx1 <= idx2){
            int leftV = numbers[idx1];
            int rightV = numbers[idx2];

            if(leftV + rightV < target){
                idx1++;
            }
            else if(target < leftV + rightV){
                idx2--;
            }
            else{
                return {idx1+1, idx2+1};
            }
        }

        return {};
    }
};