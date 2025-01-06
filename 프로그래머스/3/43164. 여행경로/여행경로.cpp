#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>
#include <exception>
using namespace std;

vector<string> answer;
void DFS(vector<vector<string>>& tickets, vector<int>& visited, int cnt, string cur){
    if(cnt == tickets.size()){
        answer.push_back(cur);
        throw out_of_range("");
        return;
    }
    
    for(int i = 0; i < tickets.size(); i++){
        if(tickets[i][0] == cur){
            if(!visited[i]){
                visited[i] = true;
                answer.push_back(cur);
                DFS(tickets, visited, cnt+1, tickets[i][1]);
                answer.pop_back();
                visited[i] = false;
            }
        }
    }
}

vector<string> solution(vector<vector<string>> tickets) {

    
    sort(tickets.begin(), tickets.end());
    vector<int> visited(tickets.size());
    try{
        DFS(tickets, visited, 0, "ICN");
    }
    catch(exception& e){
        e.what();
    }
    
    return answer;
}