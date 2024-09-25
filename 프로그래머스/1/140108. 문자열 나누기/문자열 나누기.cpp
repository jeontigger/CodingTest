#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string s) {
    int answer = 0;
    
    char x;
    int cntX = 0;
    int cntN = 0;
    for(int i = 0; i < s.size() ; i++){
        if(cntX == cntN){
            x = s[i];
            cntX = 0;
            cntN = 0;
            answer++;
        }
        
        if(s[i] == x){
            cntX++;
        }else{
            cntN++;
        }
        
    }
    
    return answer;
}