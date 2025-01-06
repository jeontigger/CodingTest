#include <string>
#include <vector>

using namespace std;

int g_targetCnt;
void TargetCnt(vector<int>& numbers, int idx, int target, int sum){
    if(idx == numbers.size()){
        if(sum == target)
            g_targetCnt++;
        
        return;
    }
    
    TargetCnt(numbers, idx+1, target, sum + numbers[idx]);
    TargetCnt(numbers, idx+1, target, sum - numbers[idx]);
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    TargetCnt(numbers, 0, target, 0);
    return g_targetCnt;
}