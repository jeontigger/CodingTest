#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    
    vector<bool> visited(n+1);
    
    vector<vector<int>> edges(n+1);
    for(int i = 0 ; i < edge.size(); i++){
        int v1 = edge[i][0];
        int v2 = edge[i][1];
        
        edges[v1].push_back(v2);
        edges[v2].push_back(v1);
    }
    
    queue<int> q;
    q.push(1);
    visited[1] = true;
    
    int lastSize = 0;
    while(!q.empty()){
        int size = q.size();
        lastSize = size;
        while(size--){
            int cur = q.front();
            q.pop();
            
            for(int i = 0; i < edges[cur].size(); i++){
                int next = edges[cur][i];
                if(!visited[next]){
                    visited[next] = true;
                    q.push(next);
                }
            }
        }
    }
    
    return lastSize;
}