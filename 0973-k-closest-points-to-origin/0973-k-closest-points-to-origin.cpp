class Solution {
public:
    struct data{
        int idx;
        int length;
    };
    int Length(const vector<int>& _vec){
        int x = _vec[0];
        int y = _vec[1];
        return x*x+y*y;
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<data> vec;
        vector<vector<int>> res;

        for(int i = 0; i<points.size();i++){
            auto point = points[i];
            int len = Length(point);
            vec.push_back({i, len});
        }

        sort(vec.begin(), vec.end(), [](const data& d1, const data& d2){
            return d1.length < d2.length;
        });

        for(int i = 0; i < k ; i++){
            int idx = vec[i].idx;
            res.push_back(points[idx]);
        }


        return res;
    }
};