class Solution {
public:
    unordered_map<string, int> um;
    int openLock(vector<string>& deadends, string target) {
        for (string& str : deadends) {
            um[str]++;
        }

        if(um.count("0000"))return   -1;

        queue<string> q;
        q.push("0000");
        vector<int> visited(10001);
        visited[0] = true;

        int turn = -1;
        while (!q.empty()) {
            turn++;
            int size = q.size();
            while (size--) {
                string cur = q.front();
                q.pop();

                // cout << cur << ' ' << turn << '\n';

                if (cur == target)
                    return turn;

                for (int i = 0; i < 4; i++) {
                    string next = cur;
                    next[i] = (cur[i] - '0' + 10 + 1) % 10 + '0';
                    int inext;
                    inext = stoi(next);
                    if (!visited[inext] && !um.count(next)) {
                        visited[inext] = true;
                        q.push(next);
                    }
                    next[i] = (cur[i] - '0' + 10 - 1) % 10 + '0';
                    inext = stoi(next);
                    if (!visited[inext] && !um.count(next)) {
                        visited[inext] = true;
                        q.push(next);
                    }
                }
            }
        }

        return -1;
    }
};