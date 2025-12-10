class Solution {
public:
    inline bool AdjWord(const string& str1, const string& str2) {
        int cnt = 0;
        for (int i = 0; i < str1.size(); i++) {
            cnt += (str1[i] != str2[i]);
            if (cnt > 1)
                return false;
        }
        return true;
    }

    int ladderLength(string beginWord, string endWord,
                     vector<string>& wordList) {
        queue<string> q;
        q.push(beginWord);
        vector<int> visited(wordList.size());
        unordered_set<string> sWordList(wordList.begin(), wordList.end());

        int ret = 0;

        while (!q.empty()) {
            int size = q.size();
            ret++;
            while (size--) {
                string word = q.front();
                q.pop();

                if(word == endWord){
                    return ret;
                }

                for (auto iter = sWordList.begin(); iter != sWordList.end();) {
                    if (AdjWord(word, *iter)) {
                        q.push(*iter);
                        iter = sWordList.erase(iter);
                    } else {
                        ++iter;
                    }
                }
            }
        }

        return 0;
    }
};