class Solution {
public:
    int N;

    struct Data{
        int visited;
        int cur;
    };

    int shortestPathLength(vector<vector<int>>& graph) {
        N = graph.size();

        int target = pow(2, N)-1;
        vector<vector<int>> visited(target+1, vector<int>(N));
        queue<Data> q;
        for(int i = 0 ; i < N; i++){
            q.push({0, i});
        }

        int cnt = -2;
        while(!q.empty()){
            int size = q.size();
            cnt++;
            while(size--){
                auto data = q.front();
                q.pop();

                if(data.visited == target){
                    return cnt;
                }

                for(int i = 0 ; i < graph[data.cur].size(); i++){
                    int next = graph[data.cur][i];
                    int nextVisited = data.visited | (1 << next);
                    if(!visited[nextVisited][next]){
                        visited[nextVisited][next] = true;
                        q.push({nextVisited, next});
                    }
                }
            }
        }
        return 0;
    }
};