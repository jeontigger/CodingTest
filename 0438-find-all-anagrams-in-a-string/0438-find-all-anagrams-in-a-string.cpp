class Solution {
public:
    int sCnts[26], pCnts[26];
    bool IsAnagrams(){
        for(int i = 0 ; i < 26; i++){
            if(sCnts[i] != pCnts[i]) return false;
        }
        return true;
    }
    vector<int> findAnagrams(string s, string p) {
        vector<int> ret;

        if(p.size() > s.size()) return ret;

        for(char c:p){
            pCnts[c-'a']++;
        }

        int left = 0;
        for(int right = 0; right < s.size(); right++){
            sCnts[s[right] - 'a']++;

            if(right - left +1 > p.size()){
                sCnts[s[left] - 'a']--;
                left++;
            }

            if(sCnts[s[right] - 'a'] == pCnts[s[right] - 'a']){
                if(IsAnagrams()){
                    ret.push_back(left);
                }
            }
        }


        return ret;
    }
};