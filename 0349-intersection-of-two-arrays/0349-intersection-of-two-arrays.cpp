class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        for(int i:nums1){
            cout << i << " ";
        }
        cout << endl;

        int idx1 = 0, idx2 = 0;
        unordered_set<int> set;

        while(idx1 < nums1.size() && idx2 < nums2.size()){
            int value1 = nums1[idx1];
            int value2 = nums2[idx2];

            if(value1 == value2){
                set.insert(value1);
                idx1++;
                idx2++;
            }
            if(value1 < value2){
                idx1++;
            }else if(value2 < value1){
                idx2++;
            }
        }

        vector<int> res;
        for(int i:set){
            res.push_back(i);
        }
        
        return res;
    }
};