#include <string>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX 2100000000
int g_Short = MAX;

void ChangeDFS(const string& strCur, const string& strTarget, int cnt, const vector<string>& words, vector<bool>& visited){
    // 종료조건
    if(cnt > g_Short)
        return;
    if(strCur == strTarget){
        g_Short = min(g_Short, cnt);
        return;
    }
    
    for(int i =0; i<words.size();i++){
        if(visited[i])
            continue;
        
        // 하나만 다를 때 재귀
        int diff = 0;
        for(int j = 0; j<words[i].size();j++){
            if(words[i][j] != strCur[j])
                diff++;
            if(diff>2)
                break;
        }
        if(diff == 1){
            visited[i] = true;
            ChangeDFS(words[i], strTarget, cnt+1, words, visited);
            visited[i] = false;
        }
    }
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    
    // 도착지 없는 예외처리
    if(find(words.begin(), words.end(), target) == words.end())
        return answer;
    
    vector<bool>visited (words.size());
    ChangeDFS(begin, target, 0, words, visited);
    
    return g_Short;
}