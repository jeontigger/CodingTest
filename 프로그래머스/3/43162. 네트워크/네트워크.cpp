#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

vector<vector<int>> g_computers;
vector<bool> visited;

void NearComputer(int start){
    visited[start] = true;
    queue<int> q;
    q.push(start);
    
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        
        // cout << cur << ' ';
        
        for(int i = 0 ; i < g_computers[cur].size(); i++){
            int next = i;
            if(!visited[next] && g_computers[cur][next]){
                visited[next] = true;
                q.push(next);
            }
        }
    }
}
int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    visited.resize(n);
    g_computers = computers;
    
    for(int i = 0 ;i <n; i++){
        if(!visited[i]){
            NearComputer(i);
            // cout << i << ' ';
            // cout << '\n';
            answer++;
        }
    }
    
    
    return answer;
}