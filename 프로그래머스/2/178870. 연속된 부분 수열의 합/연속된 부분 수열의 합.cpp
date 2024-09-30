#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer;
    
    int left = 0, right = 0;
    int curSum = sequence[0];
    while(left <= right){
        
        if(curSum == k){
            if(answer.empty()){
                answer.push_back(left);
                answer.push_back(right);
            }else if(answer[1] - answer[0] > right-left){
                answer.clear();
                answer.push_back(left);
                answer.push_back(right);
            }
            // cout << curSum << " " << left << " " << right<<endl;
            curSum -= sequence[left];
            left++;
            continue;
        }
        // cout << curSum << " " << left << " " << right<<endl;
        if(curSum < k){
            right++;
            curSum += sequence[right];
            if(right == sequence.size()){
                break;
            }
            continue;
        }
        
        if(curSum > k){
            curSum -= sequence[left];
            left++;
        }
        
    }
    return answer;
}