class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> origin = nums;
        sort(nums.begin(), nums.end());

        vector<int> res;
        for(int i =0; i<nums.size();i++){
            for(int j = i+1; j< nums.size();j++){
                int first = nums[i];
                int second =nums[j];

                if(first+second == target){
                    auto it = find(origin.begin(), origin.end(), first);
                    int firstIdx = it - origin.begin();
                    origin.erase(it);
                    int secondIdx = find(origin.begin(), origin.end(), second) - origin.begin();
                    
                    if(firstIdx <=secondIdx){
                        secondIdx++;
                    }
                    
                    cout << first << " " << second << endl;
                    cout << firstIdx << " " << secondIdx << endl;
                    res.push_back(firstIdx);
                    res.push_back(secondIdx);
                    return res;
                }
            }
        }
        return res;
    }
};