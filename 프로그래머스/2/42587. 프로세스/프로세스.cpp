#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

struct Data{
    int idx;
    int priority;
};

bool cmp(const Data& d1, const Data& d2){
     return d1.priority != d2.priority ?d1.priority < d2.priority : d1.idx < d2.idx;
}

int solution(vector<int> priorities, int location) {
    int answer = 0;
    priority_queue<int> pq;
    queue<Data> q;
    
    int idx = 0;
    for(int i:priorities){
        pq.push(i);
        q.push({idx++, i});
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
            
        }else{
            q.push(data);
        }
    }
    
    return answer;
}