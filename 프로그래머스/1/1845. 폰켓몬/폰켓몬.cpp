#include <vector>
#include <unordered_map>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    unordered_map<int, int> um;
    for(int i = 0 ; i < nums.size(); i++){
        um[nums[i]]++;
    }
    
    answer = min(um.size(), nums.size()/2);
    return answer;
}