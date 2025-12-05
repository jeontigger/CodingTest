class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int N = s.size(), M = wordDict.size();
        vector<bool> dp(N+1, false);
        dp[0] = true;

        unordered_set<string> dict(wordDict.begin(), wordDict.end());

        for(int i = 0;  i <= N; i++){
            for(int j = 0; j < i; j++){
                if(!dp[j]) continue;

                string str = s.substr(j, i - j);
                
                if(dict.find(str) != dict.end()){
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[N];
    }
};