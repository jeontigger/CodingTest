class Solution {
public:
    bool isPalindrome(string s) {
        string str = "";

        int start = 0;
        int last = s.length()-1;

        while(true){
            if(last <= start)
                return true;
            if(!isalnum(s[start])){
                start++;
                continue;
            }
            if(!isalnum(s[last])){
                last--;
                continue;
            }

            if(tolower(s[start]) != tolower(s[last])){
                return false;
            }
            
            start++;
            last--;
        }
        return true;
    }
};