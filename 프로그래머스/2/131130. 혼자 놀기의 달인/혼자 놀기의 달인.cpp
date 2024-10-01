#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<int> cards) {
    int answer = 0;
    
    vector<int> cnts;
    cnts.push_back(0);
    for(int i = 0; i < cards.size();i++){
        int curIdx = cards[i] - 1;
        if(cards[i] == 0)
            continue;
        
        cards[i] = 0;
        
        int cnt = 1;
        while(cards[curIdx]){
            int tmp = cards[curIdx] - 1;
            cards[curIdx] = 0;
            curIdx = tmp;
            cnt++;
        }
        cnts.push_back(cnt);
    }
    
    sort(cnts.begin(), cnts.end(), greater<int>());
    
    answer = cnts[0] * cnts[1];
    
    return answer;
}