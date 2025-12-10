class Solution {
public:
int N;
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        N = rooms.size();
        vector<int> visited(N);
        visited[0] = true;
        queue<int> q;
        q.push(0);

        int unlock = 1;
        while(!q.empty()){
            int cur = q.front();
            q.pop();

            for(int i = 0 ; i < rooms[cur].size(); i++){
                int next = rooms[cur][i];
                if(!visited[next]){
                    visited[next] = true;
                    q.push(next);
                    unlock++;
                }
            }
        }

        return unlock == N;
    }
};