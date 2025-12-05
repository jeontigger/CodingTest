class Solution {
public:
    int CountingWithMerge(vector<int>& nums, int left, int right){
        if(left >= right) return 0;

        int mid = (left+right)/2;
        int ret = 0;
        ret += CountingWithMerge(nums, left, mid);
        ret += CountingWithMerge(nums, mid+1, right);

        int lidx = left, ridx = mid+1;
        while(ridx <=right){
            while(lidx <= mid && nums[lidx] <= (long long)nums[ridx] * 2){
                // cout << nums[lidx] << ' ' << nums[ridx] << '\n';
                lidx++;
            }
            // for(int i : nums){
            //     // cout << i << ' ';
            // }
            // cout << '\n';
            // cout << left << ' ' << right << ' ' << lidx << ' ' << mid << ' ' << ridx << ' ' << (mid - lidx + 1) << '\n';
            ridx++;
            ret += (mid - lidx + 1);
        }

        sort(nums.begin() + left, nums.begin() + right + 1);

        return ret;
    }

    int reversePairs(vector<int>& nums) {
        return CountingWithMerge(nums, 0, nums.size()-1);
    }
};