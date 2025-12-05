class Solution {
public:
    bool IsNice(const string& str){
        bool lower[26] = {false,}, upper[26] = {false,};
        for(int i = 0 ; i < str.size(); i++){
            char c = str[i];
            if('a' <= c && c <= 'z'){
                lower[c-'a'] = true;
            }else{
                upper[c-'A'] = true;
            }
        }

        for(int i = 0 ; i < 26; i++){
            if(lower[i] != upper[i]) return false;
        }

        return true;
    }

    string longestNiceSubstring(string s) {
        string ret = "";
        // 가장 긴것부터 가장 짧은거 순으로 완탐
        int N = s.size();
        for(int len = N; len > 0; len--){
            for(int i = 0; i <= N-len; i++){
                string str = s.substr(i, len);
                if(IsNice(str)){
                    return str;
                }
            }
        }
        return ret;
    }
};