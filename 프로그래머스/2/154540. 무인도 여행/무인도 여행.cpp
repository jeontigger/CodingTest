#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>

using namespace std;

struct Data{
    int row;
    int col;
    int val;
};

int g_nrow[4] = {0, 1, 0, -1};
int g_ncol[4] = {1, 0, -1, 0};

vector<int> solution(vector<string> maps) {
    vector<int> answer;
    
    queue<Data> q;
    
    for(int i =0; i< maps.size();i++){
        for(int j = 0; j < maps[0].size();j++){
            if(maps[i][j] != 'X'){
                q.push({i, j, maps[i][j] - '0'});
                maps[i][j] = 'X';
            }
            
            int sum = 0;
            while(!q.empty()){
                Data data = q.front();
                q.pop();
                
                sum += data.val;
                
                for(int k = 0; k < 4 ; k++){
                    int nrow = data.row + g_nrow[k];
                    int ncol = data.col + g_ncol[k];
                    
                    if(0 <= nrow && nrow < maps.size() && 0 <= ncol &&  ncol < maps[0].size()){
                        if(maps[nrow][ncol] != 'X'){
                            q.push({nrow, ncol, maps[nrow][ncol] - '0'});
                            maps[nrow][ncol] = 'X';
                        }
                    }
                }
            }
            
            if(sum != 0){
                answer.push_back(sum);
            }
        }
    }
    
    sort(answer.begin(), answer.end());
    
    if(answer.size() == 0){
        answer.push_back(-1);
    }
    
    return answer;
}