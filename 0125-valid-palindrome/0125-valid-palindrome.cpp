class Solution {
public:
    bool isPalindrome(string s) {
        string str = "";

        for(int i = 0 ; i<s.length() ; i++){
            if(s[i] >= '0' && s[i] <='9'){
                str+= s[i];
            }
            if(tolower(s[i]) >= 'a' && tolower(s[i]) <= 'z'){
                str+=tolower(s[i]);
            }
        }

        if(str ==""){
            return true;
        }
        cout << str << endl;
        for(int i = 0; i<str.length()/2+1 ; i++){
            if(str[i]!=str[str.length()-1-i]){
                return false;
            }
        }
        return true;
    }
};