class Solution {
public:
    map<int, int> idxs;
    vector<int> smaller;
    vector<pair<int, int>> MergeSort(int left, int right, vector<pair<int, int>>& nums){
        if(left == right) return {nums[left]};

        int mid = (left+right)/2;
        auto l = MergeSort(left, mid, nums);
        auto r = MergeSort(mid+1, right, nums);

        int lidx = 0, ridx = 0;
        vector<pair<int, int>> ret;
        while(lidx < l.size() || ridx < r.size()){
            if(ridx < r.size() && (lidx >= l.size() || l[lidx] > r[ridx])){
                // smaller[idxs[r[ridx]]] += l.size() - lidx;
                ret.push_back(r[ridx++]);
            }else{
                smaller[l[lidx].second] += ridx;
                // cout << l[lidx].second << ' ' << ridx << '\n';
                ret.push_back(l[lidx++]);
            }
        }
        return ret;
    }
    vector<int> countSmaller(vector<int>& nums) {
        vector<pair<int, int>> numWithIdx(nums.size());
        for(int i = 0 ; i < numWithIdx.size(); i++){
            numWithIdx[i].first = nums[i];
            numWithIdx[i].second = i;
        }
        smaller.resize(nums.size());
        MergeSort(0, nums.size()-1, numWithIdx);
        return smaller;
    }
};