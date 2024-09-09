#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 0;
    
    unordered_map<string, int> m;
    // 모든 부위 0 ~ n 경우의 수
    for(int i = 0; i<clothes.size();i++){
        m[clothes[i][1]]++;
    }
    
    answer = 1;
    for(auto& p:m){
        answer*=p.second + 1;
    }
    
    return answer - 1;
}