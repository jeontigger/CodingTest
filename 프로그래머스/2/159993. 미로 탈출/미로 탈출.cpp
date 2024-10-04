#include <string>
#include <vector>

#include <queue>
#include <iostream>

using namespace std;

struct Pos{
    int row;
    int col;
    int cnt;
};

int g_nrow[] = {0, 1, 0, -1};
int g_ncol[] = {1, 0, -1, 0};

int bfs(Pos start, Pos target, vector<string> maps){
    queue<Pos> q;
    q.push(start);
    
    while(!q.empty()){
        Pos pos = q.front();
        q.pop();
        
        if(pos.row == target.row && pos.col == target.col)
            return pos.cnt;
        
        for(int i = 0; i < 4; i++){
            int nrow = pos.row + g_nrow[i];
            int ncol = pos.col + g_ncol[i];
            
            if(0 <= nrow && nrow < maps.size() && 0 <= ncol && ncol < maps[0].size()){
                if(maps[nrow][ncol] == 'X') continue;
                q.push({nrow, ncol, pos.cnt+1});
                maps[nrow][ncol] = 'X';
            }
        }
    }
    return 0;
}

int solution(vector<string> maps) {
    int answer = 0;
    Pos start, lever, exit;
    
    // start, lever, exit 찾기
    for(int i = 0; i < maps.size(); i++){
        for(int j = 0; j < maps[0].size();j++){
            if(maps[i][j] == 'S'){
                start = {i, j, 0};
            }
            if(maps[i][j] == 'L'){
                lever = {i, j, 0};
            }
            if(maps[i][j] == 'E'){
                exit = {i, j, 0};
            }
        }
    }
    
    // start에서 lever까지 최단거리
    int res = bfs(start, lever, maps);
    // start에서 lever까지 도달 불가
    if(res == 0) return -1;
    answer += res;
    // // lever에서 exit까지 최단거리
    res = bfs(lever, exit, maps);
    // // lever에서 exit까지 도달 불가
    if(res == 0) return -1;
    answer += res;
    
    return answer;
}