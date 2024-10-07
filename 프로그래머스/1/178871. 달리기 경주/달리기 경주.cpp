#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    vector<string> answer;
    
    unordered_map<string, int> idxs;
    int idx = 0;
    for(auto& str:players){
        idxs[str] = idx++;
    }
    
    for(auto& str:callings){
        idx = idxs[str];
        string tmp = players[idx-1];
        players[idx-1] = players[idx];
        players[idx] = tmp;
        idxs[players[idx]] = idx;
        idxs[players[idx-1]] = idx-1;
        
        // for(auto& str:players){
        //     cout << str << " ";
        // }
        // cout << endl;
    }
    
    
    
    return players;
}