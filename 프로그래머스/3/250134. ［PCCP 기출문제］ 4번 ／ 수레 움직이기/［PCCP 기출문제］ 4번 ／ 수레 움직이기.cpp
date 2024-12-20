#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <cmath>

using namespace std;

struct Pos{
    int row;
    int col;
};

struct RBPos{
    int rrow;
    int rcol;
    int brow;
    int bcol;
};

int g_nrow[] = {0, 1, 0, -1};
int g_ncol[] = {1, 0, -1, 0};

int N, M;
vector<vector<int>> g_maze;
Pos rs, bs, re, be;

vector<vector<bool>> rVisited;
vector<vector<bool>> bVisited;
bool IsValid(int nrrow, int nrcol, int nbrow, int nbcol, Pos rp, Pos bp){
    if(nrrow < 0 || nrrow >= N) return false;
    if(nbrow < 0 || nbrow >= N) return false;
    if(nrcol < 0 || nrcol >= M) return false;
    if(nbcol < 0 || nbcol >= M) return false;
    
    // if(nrrow == 3 && nrcol == 2){
    //     cout << nbrow << ' ' << nbcol << '\n';
    // }
    
    // 벽
    if((g_maze[nrrow][nrcol] == 5) || (g_maze[nbrow][nbcol] == 5)) return false;
    // 같아지는 지점
    if((nrrow == nbrow) && (nrcol == nbcol)) return false;
    // 교차하는 경우
    if((rp.row == nbrow && rp.col == nbcol) && (bp.row == nrrow && bp.col == nrcol)) return false;
    
    if(rVisited[nrrow][nrcol]) return false;
    if(bVisited[nbrow][nbcol]) return false;

    return true;
}


int minValue = 1e9;
void DFS(int rrow, int rcol, int brow, int bcol, int depth){
    
    // cout << rrow << ' ' << rcol << ' ' << brow << ' ' << bcol << ' ' << depth << '\n';
    if(rrow == re.row && rcol == re.col && brow == be.row && bcol == be.col){
        minValue = min(minValue, depth);
        return;
    }
    
    
    
    for(int i = 0 ; i < 4; i++){
        for(int j = 0 ; j < 4; j++){
            int nrrow = rrow + g_nrow[i];
            int nrcol = rcol + g_ncol[i];
            int nbrow = brow + g_nrow[j];
            int nbcol = bcol + g_ncol[j];
            
            if(rrow == re.row && rcol == re.col){
                nrrow = rrow;
                nrcol = rcol;
                rVisited[nrrow][nrcol] = false;
            }
            if(brow == be.row && bcol == be.col){
                nbrow = brow;
                nbcol = bcol;
                bVisited[nbrow][nbcol] = false;
            }
            // cout << nrrow << ' ' << nrcol << ' ' << nbrow << ' ' << nbcol << '\n';

            if(IsValid(nrrow, nrcol, nbrow, nbcol, {rrow, rcol}, {brow, bcol})){
                
                
                rVisited[nrrow][nrcol] = true;
                bVisited[nbrow][nbcol] = true;
                DFS(nrrow, nrcol, nbrow, nbcol, depth+1);
                bVisited[nbrow][nbcol] = false;
                rVisited[nrrow][nrcol] = false;
            }
        }
    }
}

int solution(vector<vector<int>> maze) {
    int answer = 0;
    N = maze.size();
    M = maze[0].size();
    g_maze = maze;
    rVisited.resize(N, vector<bool>(M));
    bVisited.resize(N, vector<bool>(M));
    
    for(int i = 0 ; i < N; i++){
        for(int j = 0 ; j < M; j++){
            int n = maze[i][j];
            if(n == 1){
                rs = {i, j};
            }else if(n == 2){
                bs = {i, j};
            }else if(n == 3){
                re = {i, j};
            }else if(n == 4){
                be = {i, j};
            }
        }
    }
    
    rVisited[rs.row][rs.col] = true;
    bVisited[bs.row][bs.col] = true;
    DFS(rs.row, rs.col, bs.row, bs.col, 0);
    
    if(minValue == 1e9)
        return 0;
    
    return minValue;
}

// int BFS(){
    
//     vector<vector<bool>> rVisited(N, vector<bool>(M));
//     vector<vector<bool>> bVisited(N, vector<bool>(M));
//     rVisited[rs.row][rs.col] = true;
//     bVisited[bs.row][bs.col] = true;
    
//     queue<RBPos> q;
//     q.push({rs.row, rs.col, bs.row, bs.col});
    
//     while(!q.empty()){
//         auto pos = q.front();
//         q.pop();
//         Pos rPos = {pos.rrow, pos.rcol};
//         Pos bPos = {pos.brow, pos.bcol};
        
//         // if(rVisited[])
        
//         for(int i = 0 ; i < 4; i++){
//             for(int j = 0 ; j < 4; j++){
//                 int nrrow = rPos.row + g_nrow[i];
//                 int nrcol = rPos.col + g_ncol[i];
//                 int nbrow = bPos.row + g_nrow[i];
//                 int nbcol = bPos.col + g_ncol[i];
                
//                 if(IsValid(nrrow, nrcol, nbrow, nbcol, rPos, bPos)){
//                     // q.push({nrrow, nrcol, nbrow, nbcol});
                    
//                 }
//             }
//         }
//     }
    
    
//     return 0;
// }