class Solution {
public:
    bool isPalindrome(string s) {
        string str = "";

        for(int i = 0 ; i<s.length() ; i++){
            if(isdigit(s[i])){
                str+= s[i];
            }
            if(isalpha(s[i])){
                str+= tolower(s[i]);
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