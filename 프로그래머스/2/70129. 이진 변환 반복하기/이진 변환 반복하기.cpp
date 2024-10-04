#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool OnlyOne(const string& s){
    if(s.size() > 1 || s[0] == '0') return false;
    
    return true;
}

int DeleteZero(string& s){
    int originSize = s.size();
    s.erase(remove(s.begin(), s.end(), '0'), s.end());
    return originSize - s.size();
}

string SizeToBi(const string& s){
    int size = s.size();
    string res = "";
    
    while(size){
        if(size % 2 == 0){
            res = "0" + res;
        }else{
            res = "1" + res;
        }
        size /= 2;
    }
    
    return res;
}

vector<int> solution(string s) {
    vector<int> answer;
    
    int changeCnt = 0, zeroCnt = 0;
    while(true){
        // 1만 있는지 검사
        if(OnlyOne(s)){
            break;
        }
        
        // 0 제거, 제거 개수 리턴
        zeroCnt += DeleteZero(s);

        // 현재 길이를 이진변화
        s = SizeToBi(s);
        
        changeCnt++;
    }
    
    answer.push_back(changeCnt);
    answer.push_back(zeroCnt);
    return answer;
}