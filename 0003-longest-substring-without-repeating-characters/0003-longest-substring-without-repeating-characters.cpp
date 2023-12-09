class Solution {
public:
struct fData{
    int idx;
    bool duplicate;
};
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, fData> m;
        int max = 0;
        int len = 0;

        for(int i = 0; i<s.length();i++){
            char c = s[i];

            if(m[c].duplicate == false){
                m[c].duplicate = true;
                m[c].idx = i;
                len++;
            }
            else{
                if(max < len){
                    max = len;
                }
                
                int start = m[c].idx;
                m.clear();
                len = 0;
                for(int j = start + 1 ; j <= i ; j++){
                    m[s[j]].duplicate = true;
                    m[s[j]].idx = j;
                    len++;
                }
            }
        }
        if(max < len){
            max = len;
        }


        return max;
    }
};