#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int GetPicks(int idx, const string& str){
    if(idx == 0){
        return 1;
    }
    
    if(idx == 1){
        if(str=="diamond"){
            return 5;
        }else
            return 1;
    }
    
    if(idx == 2){
        if(str == "diamond"){
            return 25;
        }else if(str == "iron"){
            return 5;
        }else
            return 1;
    }
    
    return -1;
}

#define MAX 2100000000
int g_stemina = MAX;
void Recursive(int idx, int stemina, vector<int> picks, const vector<string>& minerals){
    if(*max_element(picks.begin(), picks.end()) == 0 || idx >= minerals.size())
    {
        g_stemina = min(stemina, g_stemina);
        return;
    }
    
    
    for(int i = 0; i<3;i++){
        if(picks[i] == 0)
            continue;
        
        int sum = 0;
        for(int j = idx; j < idx + 5 && j < minerals.size(); j++){
            sum += GetPicks(i, minerals[j]);
        }
        
        picks[i]--;
        Recursive(idx + 5, stemina+sum, picks, minerals);
        picks[i]++;
    }
}

int solution(vector<int> picks, vector<string> minerals) {
    int answer = 0;
    
    Recursive(0, 0, picks, minerals);
    
    return g_stemina;
}