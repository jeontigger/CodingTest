#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<int> cards) {
    int answer = 0;
    
    vector<int> cnts;
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
    
    if(cnts.size() <= 1)
        return 0;
    
    auto iter = max_element(cnts.begin(), cnts.end());
    int max1 = *iter;
    cnts.erase(iter);
    int max2 = *max_element(cnts.begin(), cnts.end());
    
    answer = max1 * max2;
    
    return answer;
}