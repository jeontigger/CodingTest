#include <string>
#include <vector>

using namespace std;

int Recursive(int idx, int sum, const vector<int>& numbers, int target){
    int res = 0;
    
    if(idx == numbers.size()){
        if(sum == target)
            return 1;
        else
            return 0;
    }
    
    res += Recursive(idx + 1, sum + numbers[idx], numbers, target);
    res += Recursive(idx + 1, sum - numbers[idx], numbers, target);
    
    return res;
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    
    answer = Recursive(0, 0, numbers, target);
    return answer;
}