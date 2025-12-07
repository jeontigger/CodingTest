class Solution {
public:
    vector<vector<int>> edges;
    int N;
    vector<int> visited;
    vector<int> finished;

    bool DFS(int n){
        
        for(int i = 0; i < edges[n].size(); i++){
            int next = edges[n][i];
            if(!visited[next]){
                visited[next] = true;
                if(!DFS(next))return false;
            }else if(!finished[next]){
                return false;
            }
        }

        finished[n] = true;
        return true;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // 위상정렬 같긴한데, 그냥 사이클판별하면 되는것 같기도?
        N = numCourses;
        edges.resize(N);
        visited.resize(N);
        finished.resize(N);
        for(const vector<int>& v:prerequisites){
            edges[v[0]].push_back(v[1]);
        }

        for(int i = 0 ; i < N; i++){
            if(!visited[i]){
                visited[i] = true;
                if(!DFS(i))return false;
            }
        }

        return true;
    }
};