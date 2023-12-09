class Solution {
public:
    struct fData{
        int key;
        int cnt;
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        vector<fData> vec;

        // 키 : 해당 숫자, 값 : 숫자 개수 맵 생성
        for(int i = 0; i < nums.size(); i++){
            int num = nums[i];
            m[num]++;
        }

        for(pair<int, int> p : m){
            vec.push_back({p.first, p.second});
        }

        sort(vec.begin(), vec.end(), [](fData d1, fData d2){return d1.cnt > d2.cnt;});


        vector<int> res;
        for(int i =0; i<k ; i++){
            res.push_back(vec[i].key);
        }

        // for(fData d:vec){
        //     cout << d.key << " " << d.cnt << endl;
        // }

        

        return res;
    }
};