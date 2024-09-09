#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;
    
    long long min = 1;
    long long max = (long long)*max_element(times.begin(), times.end()) * n;
    
    while(max - min > 1){
        long long mid = (long long)(max + min)/2;
        long long cnt = 0;
        for(int i = 0; i< times.size();i++){
            cnt += mid / times[i];
        }
        
        if(cnt < n){
            min = mid;
        }else{
            max = mid;
            answer = max;
        }
    }
    
    return answer;
}