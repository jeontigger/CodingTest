#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    sort(citations.begin(), citations.end());
    
    for(int i = 0; i < citations.size(); i++){
        int curCnt = citations.size()-i;
        if(citations[i] >= curCnt)
            return curCnt;
    }
    
    return answer;
}