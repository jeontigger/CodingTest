class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int childIdx = 0;
        int cookieIdx = 0;

        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        // for(int i: g){
        //     cout << i << " ";
        // }
        // cout << endl;
        // for(int i: s){
        //     cout << i << " ";
        // }
        // cout << endl;

        // cout << g.size() << " " << s.size() << endl;

        int res = 0;
        while(childIdx < g.size() && cookieIdx < s.size()){
            int childValue = g[childIdx];
            int cookieValue = s[cookieIdx];

            if(childValue <= cookieValue){
                childIdx++;
                cookieIdx++;
                res++;
            }else if(childValue > cookieValue){
                cookieIdx++;
            }
        }
        return res;
    }
};