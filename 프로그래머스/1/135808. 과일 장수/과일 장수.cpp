#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(int k, int m, vector<int> score) {
    int answer = 0;
    sort(score.begin(), score.end(), greater<int>());
    
    int sum = 0;
    int cnt = 0;
    for(int i = 0; i < score.size(); i++){
        cnt++;
        if(cnt == m){
            sum += score[i];
            cnt = 0;
        }
    }
    
    answer = sum * m;
    
    return answer;
}