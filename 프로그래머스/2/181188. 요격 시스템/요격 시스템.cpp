#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> targets) {
    int answer = 1;
    
    sort(targets.begin(), targets.end());    
    
    int left = targets[0][0], right = targets[0][1];
    
    for(int i = 1; i<targets.size();i++){
        if(right <= targets[i][0]){
            answer++;
            right = targets[i][1];
        }else{
            right = min(right, targets[i][1]);
        }
    }
    return answer;
}