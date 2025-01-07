#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

// [2, 9, 3, 3, 4, 4]

bool IsPossible(int mid, int distance, const vector<int>& rocks, int n){
    int sum = 0;
    for(int i = 0; i < rocks.size()-1; i++){
        sum += rocks[i+1] - rocks[i];
        // cout << sum << ' ';
        if(sum < mid){
            n--;
        }else{
            sum = 0;
        }
        
        if(n < 0){
            return false;
        }
        
    }
    
    return true;
}

int solution(int distance, vector<int> rocks, int n) {
    int answer = 0;
    rocks.push_back(0);
    rocks.push_back(distance);
    sort(rocks.begin(), rocks.end());
    
    int left = 0;
    int right = 1e9;
    
    while(left <= right){
        int mid = (left + right)/2;
        if(IsPossible(mid, distance, rocks, n)){
            left = mid + 1;
        }else{
            right = mid -1;
        }
    }
    // cout << left << ' ' << right;
    
    // IsPossible(4, distance, rocks, n);
    
    return right;
}