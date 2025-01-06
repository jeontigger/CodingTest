#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

int g_nrow[2][4] = {{-1, 0, 1, 0}, {0, 1, 0, -1}};
int g_ncol[2][4] = {{0, 1, 0, -1}, {-1, 0, 1, 0}};

struct Pos{
    int row;
    int col;
};
vector<vector<int>> g_rectangle;
bool IsInner(Pos pos){
    
    for(int i = 0 ; i < g_rectangle.size(); i++){
        int l = g_rectangle[i][0]*2;
        int b = g_rectangle[i][1]*2;
        int r = g_rectangle[i][2]*2;
        int t = g_rectangle[i][3]*2;
        
        if(b < pos.row && pos.row < t && l < pos.col && pos.col < r)
            return true;
    }
    
    return false;
    
}

int BFS(Pos start, Pos target, int dir, vector<vector<int>> maps){
    queue<Pos> q;
    q.push(start);
    maps[start.row][start.col] = 0;
    int step = 0;
    while(!q.empty()){
        Pos cur = q.front();
        q.pop();
        step++;
        
        // cout << cur.row << ' ' << cur.col << '\n';
        if(cur.row == target.row && cur.col == target.col){
            // cout << cur.row << ' ' << cur.col << '\n';
            return step/2;
        }
        // if(step == 30) return-1;
        
        for(int i = 0 ; i < 4; i++){
            int nrow = cur.row + g_nrow[dir][i];
            int ncol = cur.col + g_ncol[dir][i];
            
            if(maps[nrow][ncol] && !IsInner({nrow, ncol})){
                maps[nrow][ncol] = 0;
                q.push({nrow, ncol});
                break;
            }
        }
    }
    
    return -1;
}

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    int answer = 0;
    vector<vector<int>> maps(103, vector<int>(103));
    g_rectangle = rectangle;
    for(int i = 0 ; i < rectangle.size(); i++){
        int l = rectangle[i][0]*2;
        int b = rectangle[i][1]*2;
        int r = rectangle[i][2]*2;
        int t = rectangle[i][3]*2;
        
        for(int j = l; j <= r; j++){
            maps[b][j] = 1;
            maps[t][j] = 1;
        }
        
        for(int j = b; j <= t; j++){
            maps[j][l] = 1;
            maps[j][r] = 1;
        }
    }
    
    int res1 = BFS({characterY*2, characterX*2}, {itemY*2, itemX*2}, 0, maps);
    int res2 = BFS({characterY*2, characterX*2}, {itemY*2, itemX*2}, 1, maps);
    
    answer = min(res1, res2);
    
    // for(int i = 0; i <20 ;i++){
    //     for(int j = 0; j < 20; j++){
    //         cout << maps[i][j] << ' ';
    //     }cout << '\n';
    // }
    
    
    
    return answer;
}