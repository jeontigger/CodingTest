#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

int solution(int number, int limit, int power) {
    int answer = 0;
    
    if(number == 1) return 1;
    if(number == 2) return 3;
    
    answer = 3;
    for(int i = 3; i <= number; i++){
        int cnt = 0;
        for(int j = 1; j <sqrt(i); j++){
            if(i % j == 0){
                cnt++;
            }
        }
        cnt*=2;
        if((int)sqrt(i) * sqrt(i) == i){
            cnt++;
        }
        
        if(cnt > limit){
            answer += power;
        }else{
            answer += cnt;
        }
        
        // cout << answer << " " << cnt << endl;
    }
    
    
    return answer;
}