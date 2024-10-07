#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

void Initialize(vector<string>& words, string word, int cnt){
    
    if(cnt == 5){
        return;
    }
    string str = word + "A";
    words.push_back(str);
    Initialize(words, str, cnt + 1);
    str = word + "E";
    words.push_back(str);
    Initialize(words, str, cnt + 1);
    str = word + "I";
    words.push_back(str);
    Initialize(words, str, cnt + 1);
    str = word + "O";
    words.push_back(str);
    Initialize(words, str, cnt + 1);
    str = word + "U";
    words.push_back(str);
    Initialize(words, str, cnt + 1);
    
}

int solution(string word) {
    int answer = 0;
    vector<string> words;
    
    Initialize(words, "", 0);
    
    answer = find(words.begin(), words.end(), word) - words.begin() + 1;
    // for(string str:words){
    //     cout << str << " ";
    // }
    
    return answer;
}