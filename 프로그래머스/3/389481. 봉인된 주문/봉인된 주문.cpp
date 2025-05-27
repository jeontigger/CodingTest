#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

string NumToString(long long n){
    string ret = "";
    while(n != 0){
        int mod = (--n) % 26;
        ret = (char)(mod + 'a') + ret;
        n /= 26;
    }
    
    return ret;
}

long long StringToNum(string str){
    long long ret = 0;
    
    for(int i = 0; i < str.size(); i++){
        ret += (str[str.size() - i - 1] - 'a'+1) * pow(26, i);
    }
    
    return ret;
}

string solution(long long n, vector<string> bans) {
    string answer = "";
    vector<long long> banNums(bans.size());
    
    for(int i = 0 ; i < bans.size(); i++){
        banNums[i] = StringToNum(bans[i]);
    }
    
    sort(banNums.begin(), banNums.end());
    
    for(int i = 0 ; i < banNums.size(); i++){
        if(banNums[i] <= n) n++;
    }
    
    answer = NumToString(n);
    
    return answer;
}