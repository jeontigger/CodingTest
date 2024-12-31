#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    sort(people.begin(), people.end(), greater<int>());
    
    int left = 0;
    int right = people.size()-1;
    int sum = 0;
    while(left <= right){
       if(people[left] + people[right] <= limit){
           // cout << "left ";
           left++;
           right--;
       }else {
           left++;
       }
        answer++;
    }
    
    return answer;
}