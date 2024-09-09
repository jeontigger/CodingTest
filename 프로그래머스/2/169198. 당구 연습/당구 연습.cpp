#include <string>
#include <vector>
#include <iostream>

using namespace std;

struct Pos{
    int x;
    int y;
};

#define MAX 2100000000
vector<int> solution(int m, int n, int startX, int startY, vector<vector<int>> balls) {
    vector<int> answer;
    
    for(int i = 0; i < balls.size(); i++){
        Pos target = {balls[i][0], balls[i][1]};
        
        int res = MAX;
        
        for(int j = 0; j< 4; j++){
            Pos npos = {};
            if(j == 0){
                npos = {-startX, startY};
            }else if(j == 1){
                npos = {startX, -startY};
            }else if(j == 2){
                npos = {2 * m - startX, startY};
            }else{
                npos = {startX, 2 * n - startY};
            }
            
            if(((npos.y - target.y) == 0 && startX > target.x && j == 0) ||
                ((npos.x - target.x) == 0 && startY > target.y && j == 1) ||
                ((npos.y - target.y) == 0 && startX < target.x && j == 2) ||
                ((npos.x - target.x) == 0 && startY < target.y && j == 3))
                continue;
            
            res = min(res, (npos.y-target.y)*(npos.y-target.y) + (npos.x - target.x)*(npos.x - target.x));
            // cout << npos.x << " " << npos.y << " " << res << endl;
        }
        answer.push_back(res);
    }
    
    return answer;
}