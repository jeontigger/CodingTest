#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool cmp(const string& str1, const string& str2){
    return str1 + str2 > str2 + str1;
}
string solution(vector<int> numbers) {
    string answer = "";
    vector<string> strs(numbers.size());
    for(int i = 0 ; i < numbers.size(); i++){
        strs[i] = to_string(numbers[i]);
    }
    
    sort(strs.begin(), strs.end(), cmp);
    
    for(auto& str : strs){
        answer += str;
    }
    
    if(answer[0] == '0' && answer.size() > 1)
        answer = "0";
    
    return answer;
}