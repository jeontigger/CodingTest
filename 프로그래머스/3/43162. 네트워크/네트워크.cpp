#include <string>
#include <vector>
#include <queue>

struct Pos{
    int row;
    int col;
};

int g_nrow[] = {0, 1, 0, -1};
int g_ncol[] = {1, 0, -1, 0};

using namespace std;

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    vector<vector<int>> maps(computers);
    vector<bool> visited(n);
    queue<int> q;

    for(int i = 0 ; i < n ; i++){
        if(visited[i]) continue;
        
        q.push(i);
        visited[i] = true;
        
        answer++;
        
        while(!q.empty()){
            int idx = q.front();
            q.pop();
            
            for(int j = 0 ; j < n; j++){
                if(computers[idx][j] == 1 && !visited[j]){
                    q.push(j);
                    visited[j] = true;
                }
            }
        }
    }
    
    return answer;
}