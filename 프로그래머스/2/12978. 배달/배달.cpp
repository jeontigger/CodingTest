#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct Edge{
    int to;
    int w;
};

vector<vector<Edge>> edges;
int g_N;
struct cmp{
    bool operator()(const Edge& e1, const Edge&e2){
        return e1.w != e2.w ? e1.w > e2.w : e1.to > e2.to;
    }
};
vector<int> Dijkstra(int start){
    vector<int> dist(g_N+1, 1e9);
    
    priority_queue<Edge, vector<Edge>, cmp> pq;
    dist[start] = 0;
    pq.push({start, 0});
    
    while(!pq.empty()){
        Edge edge = pq.top();
        pq.pop();
        
        if(dist[edge.to] < edge.w) continue;
        
        for(int i = 0; i < edges[edge.to].size(); i++){
            Edge nextEdge = edges[edge.to][i];
            int weight = edge.w + nextEdge.w;
            if(dist[nextEdge.to] > weight){
                dist[nextEdge.to] = weight;
                pq.push({nextEdge.to, weight});
            }
        }
        
    }
    return dist;
}

int solution(int N, vector<vector<int>> road, int K) {
    int answer = 0;
    g_N = N;
    edges.assign(N+1, vector<Edge>());
    for(int i = 0 ; i < road.size(); i++){
        int a = road[i][0];
        int b = road[i][1];
        int c = road[i][2];
        
        edges[a].push_back({b, c});
        edges[b].push_back({a, c});
    }
    
    auto vec = Dijkstra(1);
    for(int i : vec){
        if(i <=K){
            answer++;
        }
    }

    return answer;
}