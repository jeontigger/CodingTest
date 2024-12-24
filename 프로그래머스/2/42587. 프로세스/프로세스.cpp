#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

struct Data{
    int idx;
    int priority;
};

int solution(vector<int> priorities, int location) {
    int answer = 0;
    priority_queue<int> pq;
    queue<Data> q;
    for(int i = 0 ; i < priorities.size(); i++){
        pq.push(priorities[i]);
        q.push({i, priorities[i]});
    }
    
    while(!q.empty()){
        Data data = q.front();
        q.pop();
        
        if(data.priority == pq.top()){
            pq.pop();
            answer++;
            if(data.idx == location){
                return answer;
            }
            continue;
        }else{
            q.push(data);
        }
    }

    return answer;
}