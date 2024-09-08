#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer;
    answer.push_back(0);
    answer.push_back(sequence.size());
    
    int leftIdx = 0;
    int rightIdx = 0;
    
    int sum = sequence[0];
    while(leftIdx <= rightIdx){
        if(sum < k){
            rightIdx++;
            if(rightIdx == sequence.size())
                break;
            sum += sequence[rightIdx];
        }else if (sum > k){
            sum -= sequence[leftIdx];
            leftIdx++;
        }else{
            if(answer[1]-answer[0] > rightIdx - leftIdx){
                answer[1] = rightIdx;
                answer[0] = leftIdx;
            }
            sum -= sequence[leftIdx];
            leftIdx++;
        }
    }
    return answer;
}