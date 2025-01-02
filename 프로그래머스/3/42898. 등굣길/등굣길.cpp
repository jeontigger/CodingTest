#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    vector<vector<int>> maps(n, vector<int>(m));
    
    for(int i = 0 ; i < puddles.size(); i++){
        int row = puddles[i][1]-1;
        int col = puddles[i][0]-1;
        maps[row][col] = -1;
    }
    
    maps[0][0] = 1;
    for(int i = 0 ; i < n; i++){
        for(int j = 0 ; j < m; j++){
            if(i == 0 && j == 0) continue;
            if(maps[i][j] == -1) continue;
            
            int top = 0;
            int left = 0;
            if(i > 0)
                top = maps[i-1][j];
            if(j > 0)
                left = maps[i][j-1];
            
            if(top == -1) top = 0;
            if(left == -1) left = 0;
            maps[i][j] = (top + left) % 1'000'000'007;
        }
    }
    
    // for(auto v: maps){
    //     for(int i : v){
    //         cout << i << ' ';
    //     }cout << '\n';
    // }
    
    return maps[n-1][m-1];
}