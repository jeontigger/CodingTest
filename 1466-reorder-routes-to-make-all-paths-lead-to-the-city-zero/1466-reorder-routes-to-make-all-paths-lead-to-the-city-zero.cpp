class Solution {
public:
    vector<vector<pair<int, int>>> edges;
    vector<int> visited;
    int N;

    void Init(int n, vector<vector<int>>& connections){
        N = n;
        edges.resize(n);
        visited.resize(n);
        for(int i = 0 ; i < n-1; i++){
            int n1 = connections[i][0], n2 = connections[i][1];
            edges[n1].push_back({n1, n2});
            edges[n2].push_back({n1, n2});
        }
    }

    int DFS(int n){
        int ret = 0;
        for(int i = 0 ; i < edges[n].size(); i++){
            auto cand = edges[n][i];
            bool reverse = (cand.first == n) ? true : false;
            int next = reverse ? cand.second : cand.first;
            
            if(!visited[next]){
                visited[next] = true;
                ret += reverse ? 1 : 0;
                ret += DFS(next);
            }
        }

        return ret;
    }

    int minReorder(int n, vector<vector<int>>& connections) {
        Init(n, connections);

        visited[0] = true;
        return DFS(0);
    }
};