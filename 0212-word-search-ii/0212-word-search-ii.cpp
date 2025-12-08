class Solution {
public:
    struct Trie {
        Trie* child[26];
        string word;

        Trie() {
            word = "";
            memset(child, 0, sizeof(child));
        }
    };

    void BuildTrie(Trie* root, const vector<string>& words) {
        for (int i = 0; i < words.size(); i++) {
            string word = words[i];

            Trie* node = root;
            for (int j = 0; j < word.size(); j++) {
                int idx = word[j] - 'a';
                if (node->child[idx] == nullptr) {
                    node->child[idx] = new Trie;
                }
                node = node->child[idx];
            }
            node->word = word;
        }
    }

    vector<vector<char>> m_board;
    vector<string> ret;
    int N, M;
    int dr[4] = {1, 0, -1, 0};
    int dc[4] = {0, 1, 0, -1};

    bool IsValid(int r, int c, const vector<vector<int>>& visited) {
        if (r < 0 || r >= N || c < 0 || c >= M)
            return false;
        return !visited[r][c];
    }
    void DFS(int r, int c, vector<vector<int>>& visited, Trie* node) {
        char ch = m_board[r][c];
        int idx = ch - 'a';
        Trie* next = node->child[idx];
        if (next == nullptr)
            return;

        if (next->word != "") {
            ret.push_back(next->word);
            next->word.clear();
        }

        for(int i = 0; i <4 ;i++){
            int nr = r + dr[i];
            int nc = c + dc[i];
            if(IsValid(nr, nc, visited)){
                visited[nr][nc] = true;
                DFS(nr, nc, visited, next);
                visited[nr][nc] = false;
            }
        }
    }

    vector<string> findWords(vector<vector<char>>& board,
                             vector<string>& words) {
        Trie* root = new Trie;
        BuildTrie(root, words);
        m_board = board;
        N = m_board.size(), M = m_board[0].size();
        vector<vector<int>> visited(N, vector<int>(M));
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                visited[i][j] = true;
                DFS(i, j, visited, root);
                visited[i][j] = false;
            }
        }

        return ret;
    }
};