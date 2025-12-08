class Solution {
public:
    int N;
    vector<int> visited;
    vector<vector<int>> m_IsConnected;

    void DFS(int n){
        for(int i = 0 ; i < N; i++){
            if(!visited[i] && m_IsConnected[n][i]){
                visited[i] = true;
                DFS(i);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        m_IsConnected = isConnected;
        N = m_IsConnected.size();
        visited.resize(N);

        int ret = 0;
        for(int i = 0 ; i < N; i++){
            if(!visited[i]){
                visited[i] = true;
                DFS(i);
                ret++;
            }
        }

        return ret;
    }
};