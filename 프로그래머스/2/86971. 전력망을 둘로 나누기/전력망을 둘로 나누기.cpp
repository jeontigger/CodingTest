#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <queue>

using namespace std;

vector<vector<int>> g_edges;

void MakeEdgesExcept(vector<vector<int>>& wires, int idx){
    g_edges.clear();
    g_edges.resize(wires.size()+1 + 1);
    for(int i = 0 ; i < idx; i++){
        int v1 = wires[i][0];
        int v2 = wires[i][1];
        g_edges[v1].push_back(v2);
        g_edges[v2].push_back(v1);
    }
    for(int i = idx + 1; i < wires.size(); i++){
        int v1 = wires[i][0];
        int v2 = wires[i][1];
        g_edges[v1].push_back(v2);
        g_edges[v2].push_back(v1);
    }
}

vector<bool> visited;
int BFS(int start){
    queue<int> q;
    q.push(start);
    visited[start] = true;
    int cnt = 0;
    
    while(!q.empty()){
        int node = q.front();
        q.pop();
        cnt++;
        for(int i = 0 ; i < g_edges[node].size(); i++){
            int next = g_edges[node][i];
            if(visited[next]) continue;
            visited[next] = true;
            q.push(next);
        }
    }
    
    return cnt;
}

int DoubleBFS(){
    visited.clear();
    visited.resize(g_edges.size());
    int one = BFS(1);
    int two = 0;
    
    for(int i = 2 ; i < g_edges.size(); i++){
        if(!visited[i])
        {
            two = BFS(i);
            break;
        }
    }
    
    return abs(one - two);
}

int solution(int n, vector<vector<int>> wires) {
    int answer = 1e9;
    
    for(int i = 0; i < wires.size(); i++){
        MakeEdgesExcept(wires, i);
        answer = min(answer, DoubleBFS());
    }
    return answer;
}