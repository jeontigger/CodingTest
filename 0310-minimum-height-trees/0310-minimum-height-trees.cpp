class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {

        if(n==1){
            return {0};
        }

        vector<vector<int>> graph(n);
        vector<int> edgeCnt(n);
        for(int i =0; i < edges.size();i++){
            int node1 = edges[i][0];
            int node2 = edges[i][1];

            graph[node1].push_back(node2);
            graph[node2].push_back(node1);
            edgeCnt[node1]++;
            edgeCnt[node2]++;
        }


        list<int> q;
        for(int i = 0; i< edgeCnt.size() ;i++){
            if(edgeCnt[i]==1){
                q.push_back(i);
                edgeCnt[i]--;
            }
        }

        vector<int> res;
        while(!q.empty()){
            int len = q.size();
            res.clear();
            for(int i = 0; i<len;i++){
                int idx = q.front(); q.pop_front();
                res.push_back(idx);
                for(int i:graph[idx]){
                    edgeCnt[i]--;
                    if(edgeCnt[i] == 1) q.push_back(i);
                }
            }
        }

        // for(vector<int> v: graph){
        //     for(int i:v){
        //         cout << i << " ";
        //     }
        //     cout << endl;
        // }
        // cout << "====================" << endl;

        // for(int i:edgeCnt){
        //     cout << i << " ";
        // }
        // cout << endl;

        // for(int i:res){
        //     cout << i << " ";
        // }
        // cout << endl;

        return res;
    }
};