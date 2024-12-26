#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <queue>
#include <unordered_map>

using namespace std;

char ExtractCommand(const string& str){
    return str[0];
}
int ExtractVal(const string& str){
    return stoi(str.substr(2));
}

priority_queue<int, vector<int>, greater<int>> minpq;
priority_queue<int> maxpq;
unordered_map<int, int> um;

void Insert(int val){
    minpq.push(val);
    maxpq.push(val);
    um[val]++;
}

void Pop(int delta){
    if(delta == 1){
        // 최대값 삭제
        while(!maxpq.empty() && um[maxpq.top()] == 0){
            maxpq.pop();
        }
        if(!maxpq.empty())
        {
            um[maxpq.top()]--;
            maxpq.pop();
        }
    }else{
        // 최소값 삭제
        while(!minpq.empty() && um[minpq.top()] == 0){
            minpq.pop();
        }
        if(!minpq.empty())
        {
            um[minpq.top()]--;
            minpq.pop();
        }
    }
}

int GetVal(int delta){
    if(delta == 1){
        // GetMax
        while(!maxpq.empty() && um[maxpq.top()] == 0){
            maxpq.pop();
        }
        if(!maxpq.empty()){
            return maxpq.top();
        }
    }else{
        // GetMin
        while(!minpq.empty() && um[minpq.top()] == 0){
            minpq.pop();
        }
        if(!minpq.empty()){
            return minpq.top();
        }
    }
    
    return 0;
}

vector<int> solution(vector<string> operations) {
    vector<int> answer(2);
    
    for(int i = 0 ; i < operations.size(); i++){
        char com = ExtractCommand(operations[i]);
        int val = ExtractVal(operations[i]);
        if(com == 'I'){
            Insert(val);
        }else{
            Pop(val);
        }
    }
    
    answer[0] = GetVal(1);
    answer[1] = GetVal(-1);
    return answer;
}