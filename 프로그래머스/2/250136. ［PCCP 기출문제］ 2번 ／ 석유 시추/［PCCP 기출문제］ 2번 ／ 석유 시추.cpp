#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> sums;
struct Pos{
    int row;
    int col;
};

int g_nrow[] = {0, 1, 0, -1};
int g_ncol[] = {1, 0, -1, 0};
    
void BFS(Pos start, vector<vector<int>>& land){
    
    queue<Pos> q;
    q.push(start);
    land[start.row][start.col] = 0;
    
    int sum = 0;
    vector<bool> cols(land[0].size());
    while(!q.empty()){
        Pos pos = q.front();
        q.pop();
        cols[pos.col] = true;
        sum++;
        for(int i = 0 ; i < 4; i++){
            int nrow = pos.row + g_nrow[i];
            int ncol = pos.col + g_ncol[i];
            if(0 <= nrow && nrow < land.size() && 0 <= ncol && ncol < land[0].size()){
                if(land[nrow][ncol] == 1){
                    land[nrow][ncol] = 0;
                    q.push({nrow, ncol});
                }
            }
        }
    }
    
    // sums
    for(int i = 0 ; i < sums.size(); i++){
        if(cols[i]){
            sums[i] += sum;
        }
    }
}

int solution(vector<vector<int>> land) {
    int answer = 0;
    int N = land.size();
    int M = land[0].size();
    
    sums.resize(M);
    for(int i = 0 ; i < N; i++){
        for(int j = 0 ; j < M; j++){
            if(land[i][j] == 1){
                BFS({i, j}, land);
            }
        }
    }
    
    // for(int i = 0 ; i < M; i++){
    //     cout << sums[i] << ' ';
    // }
    
    answer = *max_element(sums.begin(), sums.end());
    return answer;
}