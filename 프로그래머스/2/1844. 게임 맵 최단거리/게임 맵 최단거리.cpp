#include <vector>
#include <queue>
using namespace std;

struct Data{
    int row;
    int col;
    int cnt;
};

int g_nrow[] = {0, 1, 0, -1};
int g_ncol[] = {1, 0, -1, 0};

int solution(vector<vector<int>> maps)
{
    int answer = 0;
    queue<Data> q;
    q.push({0, 0, 1});
    maps[0][0] = 0;
    
    while(!q.empty()){
        Data data = q.front();
        q.pop();
        
        if(data.row == maps.size()-1 && data.col == maps[0].size()-1){
            return data.cnt;
        }
        
        for(int i = 0; i< 4; i++){
            int nrow = data.row + g_nrow[i];
            int ncol = data.col + g_ncol[i];
            
            if(0 <= nrow && nrow < maps.size() && 0 <= ncol && ncol < maps[0].size()){
                if(maps[nrow][ncol] == 1){
                    q.push({nrow, ncol, data.cnt+1});
                    maps[nrow][ncol] = 0;
                }
            }
        }
    }
    
    return -1;
}










