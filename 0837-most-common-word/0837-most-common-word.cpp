class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        int start = 0;
        int end = 0;
        std::locale loc;
        for(char& c: paragraph){
            c = isalnum(c)? tolower(c) : ' ' ;
        }


        unordered_map<string, int> m;
        unordered_set<string> ban;
        for(const string& b:banned){
            ban.insert(b);
        }

        stringstream ss(paragraph);
        string str = "";
        while(ss >> str){
            if(ban.find(str)==ban.end()){
                m[str]++;
            }
        }

        string res = "";
        int iMax = 0;
        for(const pair<string, int>& p:m){
            if(iMax<p.second){
                res = p.first;
                iMax = p.second;
            }
            cout << p.first << " " << p.second << endl;
        }

        return res;
    }
};