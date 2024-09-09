#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    int comCnt = computers.size();
    vector<bool> visited(comCnt);
    
    queue<int> q;
    
    for(int i =0; i<comCnt;i++){
        if(!visited[i]){
            q.push(i);
            visited[i] = true;
            answer++;
        }
        
        while(!q.empty()){
            int n = q.front();
            q.pop();
            
            for(int i = 0; i<comCnt; i++){
                if(computers[n][i] && !visited[i]){
                    q.push(i);
                    visited[i] = true;
                }
            }
        }
    }
    return answer;
}