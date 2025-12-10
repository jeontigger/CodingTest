class Solution {
public:
    bool IsValid(int r, int c, int origin, vector<vector<int>>& image,
                 vector<vector<int>>& visited) {
        return !(r < 0 || r >= visited.size() || c < 0 ||
                 c >= visited[0].size()) &&
               !visited[r][c] && image[r][c] == origin;
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int color) {
        queue<pair<int, int>> q;
        int dr[4] = {0, 1, 0, -1};
        int dc[4] = {1, 0, -1, 0};
        int origin = image[sr][sc];

        vector<vector<int>> visited(image.size(), vector<int>(image[0].size()));
        q.push({sr, sc});
        visited[sr][sc] = true;
        image[sr][sc] = color;

        while (!q.empty()) {
            auto pos = q.front();
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nr = pos.first + dr[i];
                int nc = pos.second + dc[i];
                if (IsValid(nr, nc, origin, image, visited)) {
                    // cout << pos.first << ' ' << pos.second << ' ' << nr << ' ' << nc << '\n';
                    visited[nr][nc] = true;
                    image[nr][nc] = color;
                    q.push({nr, nc});
                }
            }
        }
        return image;
    }
};