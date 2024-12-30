#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    sort(lost.begin(), lost.end());
    sort(reserve.begin(), reserve.end());
    vector<bool>visited(n+1, true);

    for(int i = 0 ; i < lost.size(); i++){
        auto iter = find(reserve.begin(), reserve.end(), lost[i]);
        if(iter == reserve.end()){
            visited[lost[i]] = false;
        }else if(iter != reserve.end()){
            // cout << lost[i] << ' ' << *iter << '\n';
            *iter = 0;
        }
    }
    // for(int i : reserve){
    //     cout << i << ' ';
    // }
    for(int i = 0 ; i < reserve.size(); i++){
        // cout << reserve[i] << ' ';
        if(reserve[i] == 0) continue;
        
        int cur = reserve[i];
        for(int j = 0; j < 3; j++){
            int next = cur - 1 + j;
            if(next < 0 || next >= visited.size()) continue;
            if(!visited[next]){
                reserve[i] = 0;
                visited[next] = true;
                break;
            }
        }
    }
    
    // for(int i : visited){
    //     cout << i << ' ';
    // }
    for(int i = 1; i < visited.size(); i++){
        answer += visited[i];
    }
    return answer;
}