#include <string>
#include <vector>
#include <queue>

using namespace std;

struct Data{
    int val;
    int cnt;
};

int solution(int x, int y, int n) {
    int answer = 0;
    
    queue<Data> q;
    q.push({x, 0});
    vector<bool> visited(y);
    
    while(!q.empty()){
        Data data = q.front();
        q.pop();
        
        if(data.val == y){
            return data.cnt;
        }
        if(data.val > y || visited[data.val]) continue;
        visited[data.val] = true;

        
        q.push({data.val + n, data.cnt+1});
        q.push({data.val * 2, data.cnt+1});
        q.push({data.val * 3, data.cnt+1});
    }
    
    
    
    return -1;
}