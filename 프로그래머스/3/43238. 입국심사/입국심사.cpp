#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool IsValid(long long time, long long n, const vector<int>& times){
    long long acc = 0;
    for(int i = 0 ; i < times.size(); i++){
        acc += time/times[i];
        
        if(acc >= n) return true;
    }
    
    return false;
}

long long solution(int n, vector<int> times) {
    long long answer = 0;
    
    long long left = 0;
    long long right = 1e15;
    
    while(left <=right){
        long long mid = (left+right)/2;
        
        if(IsValid(mid, n, times)){
            right = mid - 1;
        }else{
            left = mid + 1;
        }
    }
    
    // cout << left << ' ' << right;
    answer = left;
    return answer;
}