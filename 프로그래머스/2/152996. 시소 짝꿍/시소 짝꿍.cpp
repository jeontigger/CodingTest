#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

long long solution(vector<int> weights) {
    long long answer = 0;
    
    sort(weights.begin(), weights.end());
    
    for(int i = 0 ; i < weights.size(); i++){
        for(int j = i + 1 ; j < weights.size(); j++){
            float ratio = (float)weights[j] / weights[i];
            if(ratio > 2) break;
            
            if(ratio == 1){
                answer++;
            }else if(ratio == 4.f/3){
                answer++;
            }else if(ratio == 1.5){
                answer++;
            }else if(ratio == 2){
                answer++;
            }
        }
    }
    
    return answer;
}