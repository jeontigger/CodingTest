#include<vector>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

int g_nrow[] = {0, 1, 0, -1};
int g_ncol[] = {1, 0, -1, 0};
vector<vector<int>> g_maps;

struct Pos{
    int row;
    int col;
};

int BFS(){
    queue<Pos>q;
    q.push({0, 0});
    g_maps[0][0] = 1;
    int cnt = 0;
    while(!q.empty()){
        cnt++;
        int size = q.size();
        while(size--){
            Pos cur = q.front();
            q.pop();
            
            // cout << cur.row << ' ' << cur.col << '\n';
            if(cur.row == g_maps.size()-1 && cur.col == g_maps[0].size()-1){
                return cnt;
            }
            
            for(int i = 0 ; i < 4; i++){
                int nrow = cur.row + g_nrow[i];
                int ncol = cur.col + g_ncol[i];
                
                if(0 <= nrow && nrow < g_maps.size() && 0 <= ncol && ncol < g_maps[0].size() && g_maps[nrow][ncol]){
                    g_maps[nrow][ncol] = 0;
                    q.push({nrow, ncol});
                }
            }
        }
    }
    
    return -1;
}

int solution(vector<vector<int> > maps)
{
    int answer = 0;
    g_maps = maps;
    
    answer = BFS();
    return answer;
}