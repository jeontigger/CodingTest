#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

bool OneDiff(const string& str1, const string& str2){
    int cnt = 0;
    for(int i = 0 ; i < str1.size(); i++){
        if(str1[i] != str2[i]){
            cnt++;
            if(cnt > 1)
                return false;
        }
    }
    
    return true;
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    
    vector<bool> visited(words.size());
    
    queue<string> q;
    q.push(begin);
    
    int cnt = -1;
    while(!q.empty()){
        int size = q.size();
        cnt++;
        while(size--){
            string cur = q.front();
            q.pop();
            
            if(cur == target){
                return cnt;
            }
            
            for(int i = 0 ; i < words.size(); i++){
                string next = words[i];
                if(!visited[i] && OneDiff(cur, next)){
                    visited[i] = true;
                    q.push(next);
                }
            }
        }
        
    }
    
    
    return 0;
}