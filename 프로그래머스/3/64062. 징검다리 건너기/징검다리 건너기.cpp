#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool IsAvailable(const vector<int>& stones, int k, long long cur){
    
    int stack = 0;
    for(int i = 0 ; i < stones.size() ;i++){
        if((long long)stones[i] - cur + 1 <= 0){
            stack++;
            // cout << i << " ";
        }else{
            stack = 0;
        }
        
        if(stack >= k)
            return false;
    }
    
    return true;
}

int solution(vector<int> stones, int k) {
    int answer = 0;
    long long left = 1, right = 200000000;
    
    cout << IsAvailable(stones, k, 2);
    while(left <= right){
        long long mid = (left + right) / 2;
        
        if(IsAvailable(stones, k, mid)){
            answer = mid;
            left = mid + 1;
        }else{
            right = mid -1;
        }
    }
    
    return answer;
}