#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

long long solution(vector<int> weights) {
    long long answer = 0;
//     vector<int> cnts(1001, 0);
    
//     for(int i: weights){
//         cnts[i]++;
//     }
    
//     for(int i = 100; i < cnts.size(); i++){
//         float ratio;
//         ratio = i;
//         answer += cnts[i] * (cnts[ratio]-1) / 2;
//         ratio = i * 4.f/3;
//         if((i * 4) % 3== 0)
//             answer += cnts[i] * (cnts[ratio]);
//         ratio = i * 1.5f;
//         if((i * 3) % 2 == 0)
//             answer += cnts[i] * (cnts[ratio]);
//         ratio = i * 2.f;
//         answer += cnts[i] * (cnts[ratio]);
//     }
    
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