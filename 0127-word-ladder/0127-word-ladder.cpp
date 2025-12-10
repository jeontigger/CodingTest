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

        int ret = 0;

        while (!q.empty()) {
            int size = q.size();
            ret++;
            while (size--) {
                string word = q.front();
                q.pop();

                if (word == endWord) {
                    return ret;
                }

                for (int i = 0; i < visited.size(); i++) {
                    if (visited[i])
                        continue;
                    if (AdjWord(word, wordList[i])) {
                        visited[i] = true;
                        q.push(wordList[i]);
                    } 
                }
            }
        }

        return 0;
    }
};