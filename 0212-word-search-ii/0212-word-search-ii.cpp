class Solution {
public:
    struct TrieNode {
        TrieNode* child[26];
        string word; // 이 노드에서 끝나는 단어 (없으면 "")

        TrieNode() : word("") {
            memset(child, 0, sizeof(child));
        }
    };

    TrieNode* buildTrie(const vector<string>& words) {
        TrieNode* root = new TrieNode();
        for (const string& w : words) {
            TrieNode* node = root;
            for (char ch : w) {
                int idx = ch - 'a';
                if (!node->child[idx]) node->child[idx] = new TrieNode();
                node = node->child[idx];
            }
            node->word = w; // 단어 끝에 저장
        }
        return root;
    }

    vector<string> res;
    int m, n;
    int dr[4] = {1, -1, 0, 0};
    int dc[4] = {0, 0, 1, -1};

    void dfs(vector<vector<char>>& board, int r, int c, TrieNode* node) {
        char ch = board[r][c];
        int idx = ch - 'a';
        TrieNode* next = node->child[idx];
        if (!next) return; // 이 prefix로 시작하는 단어 없음 -> 가지치기

        if (!next->word.empty()) {
            res.push_back(next->word);
            next->word.clear(); // 같은 단어 중복 방지
        }

        board[r][c] = '#'; // 방문 표시

        for (int k = 0; k < 4; k++) {
            int nr = r + dr[k];
            int nc = c + dc[k];
            if (nr < 0 || nr >= m || nc < 0 || nc >= n) continue;
            if (board[nr][nc] == '#') continue;
            dfs(board, nr, nc, next);
        }

        board[r][c] = ch; // 복구
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        m = board.size();
        if (m == 0) return {};
        n = board[0].size();

        TrieNode* root = buildTrie(words);

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                dfs(board, i, j, root);
            }
        }
        return res;
    }
};
