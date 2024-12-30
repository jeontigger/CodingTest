#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>

using namespace std;

char aeiou[] = {'A', 'E', 'I', 'O', 'U'};
vector<string> dictionary;

void MakeDictionary(int depth, string str){
    dictionary.push_back(str);
    if(depth == 5) return;
    
    for(int i = 0 ; i < 5;i++){
        str += aeiou[i];
        MakeDictionary(depth+1, str);
        str.pop_back();
    }
}

int solution(string word) {
    int answer = 0;
    
    MakeDictionary(0, "");
    auto iter = find(dictionary.begin(), dictionary.end(), word);
    answer = iter - dictionary.begin();
    return answer;
}