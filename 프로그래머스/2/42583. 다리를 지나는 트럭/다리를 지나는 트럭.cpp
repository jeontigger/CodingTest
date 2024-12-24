#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    
    int curWeight = 0;
    int time = 0;
    queue<int> q;
    for(int i = 0 ; i < bridge_length; i++){
        q.push(0);
    }
    
    int idx = 0;
    while(true){
        time++;
        int truck = q.front();
        q.pop();
        curWeight -= truck;
        if(curWeight + truck_weights[idx] <= weight){
            q.push(truck_weights[idx]);
            curWeight += truck_weights[idx];
            idx++;
        }else{
            q.push(0);
        }
        
        if(idx == truck_weights.size())
            break;
    }
    time += bridge_length;
    
    return time;
}