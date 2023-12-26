class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> m1;
        unordered_map<char, int> m2;

        for(int i=  0; i < s.length();i++){
            m1[s[i]]++;
        }

        for(int i = 0 ; i<t.length();i++){
            m2[t[i]]++;
        }

        if(m1.size() != m2.size()){
            return false;
        }

        for(auto iter = m1.begin(); iter!=m1.end();++iter){
            auto pair = *iter;
            char c = pair.first;
            int cnt = pair.second;

            if(m2[c] != cnt){
                return false;
            }
            
        }
        

        return true;
    }
};