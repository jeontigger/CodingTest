#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<int> first = {1, 2, 3, 4, 5};
    vector<int> second = {2, 1, 2, 3, 2, 4, 2, 5};
    vector<int> third = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    
    int cnt1 = 0, cnt2 =0, cnt3 = 0;
    for(int i =0; i < answers.size();i++){
        if(answers[i] == first[i%first.size()])
            cnt1++;
        
        if(answers[i] == second[i%second.size()])
            cnt2++;
        
        if(answers[i] == third[i%third.size()])
            cnt3++;
    }
    
    int m = max(cnt1, max(cnt2, cnt3));
    
    if(cnt1 == m)
        answer.push_back(1);
    if(cnt2 == m)
        answer.push_back(2);
    if(cnt3 == m)
        answer.push_back(3);
    
    return answer;
}