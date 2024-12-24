#include <string>
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    
    int day = 0;
    
    for(int i = 0; i < progresses.size(); i++){
        int start = progresses[i];
        int before = speeds[i] * day;
        int remain = 100 - start - before;
        if(remain <= 0) {
            answer.back()++;
            continue;
        }
        
        day += ceil((float)remain / speeds[i]);
        
        answer.push_back(1);
    }
    return answer;
}