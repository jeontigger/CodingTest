class Solution {
public:
    int N, M, m_color;
    vector<vector<int>> m_image;

    bool IsValid(int r, int c, int color){
        if(r < 0 || r >= N || c < 0 || c >= M)return false;
        return m_image[r][c] == color;
    }

    int dr[4] = {0, 1, 0, -1};
    int dc[4] = {1, 0, -1, 0};

    void DFS(int r, int c, int color){
        cout << r << ' ' << c << '\n';
        for(int i = 0 ; i < 4; i++){
            int nr = r + dr[i];
            int nc = c + dc[i];

            if(IsValid(nr, nc, color)){
                m_image[nr][nc] = m_color;
                DFS(nr, nc, color);
            }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        m_image = image;
        m_color = color;

        N = m_image.size(), M = m_image[0].size();

        m_image[sr][sc] = m_color;
        if(image[sr][sc] == color)return image;
        DFS(sr, sc, image[sr][sc]);

        return m_image;
    }
};