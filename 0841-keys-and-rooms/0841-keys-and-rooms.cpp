class Solution {
public:
    vector<int> visited;
    void DFS(int n, const vector<vector<int>>& rooms){
        // cout << n << ' ';
        for(int i = 0 ; i < rooms[n].size(); i++){
            int next = rooms[n][i];
            if(!visited[next]){
                visited[next] = true;
                DFS(next, rooms);
            }
        }
    }

    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        visited.resize(rooms.size());
        visited[0] = true;
        DFS(0, rooms);

        for(int i = 0; i < visited.size(); i++){
            // cout << visited[i] << ' ' ;
            if(!visited[i])return false;
        }

        return true;
    }
};