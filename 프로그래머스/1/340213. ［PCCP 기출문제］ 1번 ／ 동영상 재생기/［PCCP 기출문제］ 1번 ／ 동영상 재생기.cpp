#include <string>
#include <vector>
#include <iostream>

using namespace std;

int StrToSec(const string& str){
    int res = 0;
    res += stoi(str)*60;
    res += stoi(str.substr(3));
    
    return res;
}

string SecToStr(int num){
    string res = "00:00";
    int min = num/60;
    res[1] = min%10 + '0';
    res[0] = min/10 + '0';
    int sec = num%60;
    res[4] = sec%10 + '0';
    res[3] = sec/10 + '0';
    
    return res;
}

void SkipOpening(int& cur, int start, int end){
    if(start <= cur && cur <= end){
        cur = end;
    }
}

string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands) {
    string answer = "";
    int cur = StrToSec(pos);
    int opStart = StrToSec(op_start);
    int opEnd = StrToSec(op_end);
    int len = StrToSec(video_len);
    
    SkipOpening(cur, opStart, opEnd);
    
    for(int i = 0 ; i < commands.size(); i++){
        string com = commands[i];
        if(com == "next"){
            cur += 10;
            if(cur > len)
                cur = len;
        }else{
            cur -= 10;
            if(cur < 0)
                cur = 0;
        }
        
        SkipOpening(cur, opStart, opEnd);
    }
    
    answer = SecToStr(cur);
    
    
    return answer;
}