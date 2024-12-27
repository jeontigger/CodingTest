#include <string>
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    int big = 0;
    int small = 0;
    
    for(int i = 0 ; i < sizes.size(); i++){
        int a = sizes[i][0];
        int b = sizes[i][1];
        if(a > b) swap(a, b);
        small = max(small, a);
        big = max(big, b);
    }
    
    answer = small * big;
    
    return answer;
}