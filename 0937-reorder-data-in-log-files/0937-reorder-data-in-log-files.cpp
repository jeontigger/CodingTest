class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<string> let;
        vector<string> dig;

        for(int i =0 ; i<logs.size();i++){
            string str = logs[i];
            if('0' <= str[str.length() - 1] && str[str.length()-1]<='9'){
                dig.push_back(str);
            }else{
                let.push_back(str);
            }
        }

        sort(let.begin(), let.end(), [](const string& str1, const string& str2){
            if(str1.substr(str1.find(' '), str1.length()) == str2.substr(str2.find(' '), str2.length())){
                if(str1.substr(0, str1.find(' ')) < str2.substr(0, str2.find(' '))){
                    return true;
                }else{
                    return false;
                }
            }
            if(str1.substr(str1.find(' '), str1.length()) > str2.substr(str2.find(' '), str2.length())){
                return false;
            }else{
                return true;
            }
        });

        for(string str: dig){
            let.push_back(str);
        }

        return let;
    }
};