#include<vector>
#include<iostream>
#include <queue>
using namespace std;

#define MAX 2100000000
int g_minPath = MAX;

int g_row[4] = {0, 1, 0, -1};
int g_col[4] = {1, 0, -1, 0};

int g_targetRow = 0;
int g_targetCol = 0;

void SearchPath_DFS(int row, int col, int cnt, vector<vector<bool>>& visited, const vector<vector<int>>& maps){
    // 더 갈 필요 없는 조건
    if(cnt >= g_minPath){
        return;
    }
    
    // 종료 조건
    if(row == maps.size()-1 && col == maps[0].size()-1){
        g_minPath = min(g_minPath, cnt);
        return;
    }
    
    // 다음 수행
    for(int i =0; i<4;i++){
        int nRow = row + g_row[i];
        int nCol = col + g_col[i];
        
        // 범위 체크
        if(nRow >= 0 && nRow < maps.size() && nCol >= 0 && nCol < maps[0].size()){
            // 길 체크
            if(maps[nRow][nCol] == 0){
                continue;
            }
            // 방문체크
            if(!visited[nRow][nCol]){
                visited[nRow][nCol] = true;
                SearchPath_DFS(nRow, nCol, cnt+1, visited, maps);
                visited[nRow][nCol] = false;
            }
        }
    }
}

struct Pos{
    int row;
    int col;
    int cnt;
};

int SearchPath_BFS(vector<vector<int>>& maps){
    queue<Pos> q;
    
    q.push({0, 0, 1});
    
    int maxRow = maps.size();
    int maxCol = maps[0].size();
    
    while(!q.empty()){
        auto data = q.front();
        q.pop();
        
        // 도달(종료조건)
        if(data.row ==maxRow -1 && data.col == maxCol -1){
            return data.cnt;
        }
        
        for(int i = 0; i < 4; i++){
            int nrow = data.row + g_row[i];
            int ncol = data.col + g_col[i];
            
            // 범위 체크
            if(nrow >= 0 && nrow < maxRow && ncol >= 0 && ncol < maxCol){
                // 벽 체크
                if(maps[nrow][ncol]){
                    q.push({nrow, ncol, data.cnt + 1});
                    maps[nrow][ncol] = 0;
                }
            }
        }
    }
    
    return -1;
}

int solution(vector<vector<int> > maps)
{
    int answer = 0;
    vector<vector<bool>> visited;
    for(int i =0; i < maps.size();i++){
        vector<bool> v(maps[i].size());
        visited.push_back(v);
    }
    
    // SearchPath_DFS(0, 0, 0, visited, maps);
    answer = SearchPath_BFS(maps);

    return answer;
}