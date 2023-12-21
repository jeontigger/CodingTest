class Solution {
public:
    int INF = 2000000;
    vector<bool> visited;
    int min_idx(vector<int> vec){
        int min = INF;
        int min_index = -1;
        for(int i = 0; i<vec.size();i++){
            if(vec[i] == INF){
                continue;
            }
            if(visited[i])
                continue;

            if(vec[i] < min){
                min = vec[i];
                min_index = i;
            }
        }
        return min_index;
    }
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        //[from][to]
        vector<int> v(n, INF);
        vector<vector<int>> dijkstra(n, v);
        visited.resize(n);

        for(int i = 0; i<times.size();i++){
            vector<int> vec = times[i];
            int from = vec[0];
            int to = vec[1];
            int weight = vec[2];

            dijkstra[from-1][to-1] = weight;
        }


        
        for(int i =0; i< n ; i++){
            int idx = min_idx(dijkstra[k-1]);
            if(idx == -1)
                break;
            if(!visited[idx]){
                for(int j =0; j< n ; j++){
                    if(idx == j)
                        continue;
                    if(dijkstra[idx][j] == INF){
                        continue;
                    }
                    if(visited[j]){
                        continue;
                    }

                    // cout << idx << " " << j << endl;
                    // cout << dijkstra[idx][j] << " " << dijkstra[k-1][idx] << " " << dijkstra[k-1][j] << endl;
                    // for(vector<int> v:dijkstra){
                    //     for(int i:v){
                    //         cout << i << " ";
                    //     }
                    //     cout << endl;
                    // }
                    // cout << " =================== " << endl;
                    if(dijkstra[idx][j] + dijkstra[k-1][idx] < dijkstra[k-1][j]){
                        dijkstra[k-1][j] = dijkstra[idx][j] + dijkstra[k-1][idx];
                    }
                }
            }
            visited[idx] = true;
            
        }
        // for(vector<int> v:dijkstra){
        //     for(int i:v){
        //         cout << i << " ";
        //     }
        //     cout << endl;
        // }
        // cout << " =================== " << endl;

        int maximum = 0;
        for(int i = 0; i< n ; i ++){
            if(i == k-1){
                continue;
            }

            maximum = max(maximum, dijkstra[k-1][i]);
        }

        if(maximum == INF){
            return -1;
        }
        return maximum;
    }
};