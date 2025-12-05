class Solution {
public:
    
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        struct Cmp {
            bool operator()(const pair<int, int> &a, const pair<int, int> &b)
            {
                if(a.first == b.first){
                    return a.second > b.second;
                }
                return a.first < b.first;
            };
        };

        priority_queue<pair<int, int>, vector<pair<int, int>>, Cmp> pq;
        

        for(int i = 0; i<k;i++){
            pq.push({nums[i], i});
        }
        vector<int>res;


        for(int i = 0; i<nums.size() - k ; i++){
            int curMax = pq.top().first;
            res.push_back(curMax);
            int prevNum = nums[i];
            if(prevNum == curMax){
                while(true){
                    pq.pop();
                    if(pq.top().second >=i){
                        break;
                    }
                }
            }
            pq.push({nums[i+k], i+k});
        }
        res.push_back(pq.top().first);

        return res;    
    }
};