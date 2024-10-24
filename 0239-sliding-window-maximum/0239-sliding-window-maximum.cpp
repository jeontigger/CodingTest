class Solution {
public:
    struct Data{
        int idx;
        int val;
    };

    struct cmp{
        bool operator()(const Data& d1, const Data& d2){
            return d1.val == d2.val ? d1.idx > d2.idx : d1.val < d2.val;
        }
    };

    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<Data, vector<Data>, cmp> pq;

        vector<int> res;
        for (int i = 0; i < k; i++) {
            pq.push({i, nums[i]});
        }
        res.push_back(pq.top().val);

        for(int i = k ; i<nums.size(); i++){
            pq.push({i, nums[i]});
            int popNum = nums[i-k];

            if(popNum == pq.top().val){
                while(!pq.empty()){
                    pq.pop();
                    if(pq.top().idx > i-k){
                        break;
                    }
                }
            }
            res.push_back(pq.top().val);
        }
        return res;
    }
};