#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> mats, vector<vector<string>> park) {
    int answer = -1;
    int N = park.size();
    int M = park[0].size();
    vector<vector<int>> maps(N, vector<int>(M));
    int maxValue = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0 ; j < M; j++){
            if(park[i][j] == "-1"){
                maps[i][j] = 1;
            }
        }
    }
    
    for(int i = 1 ; i < N; i++){
        for(int j = 1; j < M; j++){
            if(park[i][j] != "-1") continue;
            if(park[i-1][j-1] == park[i-1][j] && park[i-1][j-1] == park[i][j-1] && park[i-1][j-1] == "-1"){
                maps[i][j] = min(min(maps[i-1][j-1], maps[i-1][j]), maps[i][j-1]) + 1;
                
            }
        }
    }
    for(int i = 0 ; i < N; i++){
        for(int j = 0; j < M; j++){
            maxValue = max(maxValue, maps[i][j]);
        }
    }
    
    for(int i = 0 ; i < mats.size(); i++){
        // cout << mats[i] << ' ' << maxValue << '\n';
        if(mats[i] <= maxValue){
            answer = max(answer, mats[i]);
        }
    }
    
    // for(int i = 0 ; i < N; i++){
    //     for(int j = 0; j < M; j++){
    //         cout << maps[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    
    return answer;
}