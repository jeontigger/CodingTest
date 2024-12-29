#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

int maxValue = 0;
vector<int> visited;
vector<vector<int>> g_dungeons;

void Explore(int k, int depth){
    maxValue = max(maxValue, depth);
    
    for(int i = 0 ; i < g_dungeons.size(); i++){
        if(visited[i]) continue;
        if(k < g_dungeons[i][0]) continue;
        visited[i] = true;
        Explore(k - g_dungeons[i][1], depth+1);
        visited[i] = false;
    }
}

int solution(int k, vector<vector<int>> dungeons) {
    int answer = -1;
    g_dungeons = dungeons;
    visited.resize(dungeons.size());
    
    Explore(k, 0);
    answer = maxValue;
    return answer;
}