#include <string>
#include <vector>
#include <queue>

using namespace std;

struct Result{
    vector<int> win;
    vector<int> lose;
};

int Cnt(const vector<Result>& res, bool win, int idx){
    vector<int> visited(res.size());
    visited[idx] = true;
    queue<int> q;
    q.push(idx);
    
    int ret = 0;
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        
        if(win){
            for(int i = 0 ; i < res[cur].win.size(); i++){
                int next = res[cur].win[i];
                if(!visited[next]){
                    visited[next] = true;
                    q.push(next);
                    ret++;
                }
            }
        }else{
            for(int i = 0 ; i < res[cur].lose.size(); i++){
                int next = res[cur].lose[i];
                if(!visited[next]){
                    visited[next] = true;
                    q.push(next);
                    ret++;
                }
            }
        }
    }
    
    return ret;
}

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    vector<Result> res(n+1);
    for(int i = 0 ; i < results.size(); i++){
        int win = results[i][0];
        int lose = results[i][1];
        res[win].lose.push_back(lose);
        res[lose].win.push_back(win);
    }
    
    for(int i = 1; i < res.size(); i++){
        int w = Cnt(res, 1, i);
        int l = Cnt(res, 0, i);
        if(w + l == n-1)
            answer++;
    }
    return answer;
}