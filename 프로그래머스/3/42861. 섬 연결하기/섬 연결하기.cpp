#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> parent;
int Find(int x){
    if(x == parent[x]){
        return x;
    }else{
        return parent[x] = Find(parent[x]);
    }
}
bool Union(int a, int b){
    a = Find(a);
    b = Find(b);
    
    if(a == b)
        return false;
    
    parent[a] = b;
    
    return true;
}

struct cmp{
    bool operator()(const vector<int>& v1, const vector<int>& v2){
        return v1[2] > v2[2];
    }
};

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    
    parent.resize(n);
    for(int i = 0 ; i < n; i++){
        parent[i] = i;
    }
    
    priority_queue<vector<int>, vector<vector<int>>, cmp> pq;
    for(int i = 0 ; i < costs.size(); i++){
        // cout << costs[i][0] << ' ' << costs[i][1] << '\n';
        pq.push(costs[i]);
    }
    
    while(!pq.empty()){
        auto data = pq.top();
        pq.pop();
        
        // cout << data[0] << ' ' << data[1] << '\n';
        if(Union(data[0], data[1])){
            answer += data[2];
        }
    }
    
    return answer;
}










