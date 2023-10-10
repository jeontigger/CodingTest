class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        int start = 0;
        int end = 0;
        std::locale loc;

        unordered_map<string, int> m;
        for(int i =0; i<paragraph.length();i++){
            if(paragraph[i]==' '|| paragraph[i]=='!'|| paragraph[i]=='?'|| paragraph[i]=='\''|| paragraph[i]==';'|| paragraph[i]=='.'||paragraph[i]==','){
                end = i;
                if(end != start){
                    string str = paragraph.substr(start, end - start);
                    transform(str.begin(), str.end(), str.begin(), ::tolower);
                    m[str]++;
                    
                }
                start = i+1;
            }
        }
        string str = paragraph.substr(start, paragraph.length() - start);
        if(str != ""){
            transform(str.begin(), str.end(), str.begin(), ::tolower);
            m[str]++;
        }
        
        string res = "";
        int iMax = 0;

        for(const pair<string, int>& p: m){
            if(iMax < p.second){
                if(find(banned.begin(), banned.end(), p.first) == banned.end()){
                    res = p.first;
                    iMax = p.second;
                }
            }
            cout << p.first << " " << p.second << endl;
        }

        return res;
    }
};