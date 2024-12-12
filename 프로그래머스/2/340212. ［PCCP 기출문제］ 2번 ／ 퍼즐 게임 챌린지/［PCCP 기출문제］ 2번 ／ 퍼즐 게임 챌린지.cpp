#include <string>
#include <vector>
#include <iostream>


using namespace std;

bool IsValid(const vector<int>& diffs, const vector<int>& times, long long limit, int level){
    int time_prev = 0;
    long long time_sum = 0;
    for(int i = 0 ; i < diffs.size(); i++){
        if(diffs[i] <= level){
            time_sum += times[i];
        }else{
            time_sum += (diffs[i] - level) * (time_prev + times[i]) + times[i];
        }
        
        // cout << i << ' ' << time_sum << '\n';
        
        if(time_sum > limit){
            return false;
        }
        
        time_prev = times[i];
    }
    
    return true;
}

int solution(vector<int> diffs, vector<int> times, long long limit) {
    int answer = 0;
    
    // 최소 레벨: diffs의 0번째 퍼즐
    // 최대 레벨: 300'000
    int left = diffs[0];
    int right = 300'000;
    
    while(left <= right){
        int mid = (left+right)/2;
        
        if(IsValid(diffs, times, limit, mid)){
            right = mid -1;
        }else{
            left = mid + 1;
        }
    }
    
    // IsValid(diffs, times, limit, 3);
    
    // cout << left << ' ' << right << '\n';
    
    return left;
}