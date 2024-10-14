#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool IsCover(const vector<int>& times, long long curll, int n){
    long long coverCnt = 0;
    
    for(int i = 0 ; i < times.size();i++){
        coverCnt += (curll / times[i]);
    }
    
    return coverCnt >= n ? true : false;
}

long long solution(int n, vector<int> times) {
    long long answer = 0;
    long long right = *max_element(times.begin(), times.end());
    right *= n;
    long long left = 0;
    
    
    while(left < right){
        long long mid = (left + right) / 2;
        
        if(IsCover(times, mid, n)){
            right = mid;
            answer = right;
        }else{
            left = mid+1;
        }
    }
    
    return answer;
}