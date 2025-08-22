#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int time = 0;
    int waitIdx = 0;
    int curWeight = 0;
    queue<int> bridge;
    for(int i = 0 ; i < bridge_length; i++){
        bridge.push(0);
    }
    while(waitIdx != truck_weights.size()){
        // 빼고
        // 들어가기
        curWeight -= bridge.front();
        bridge.pop();
        time++;
        int predWeight = curWeight + truck_weights[waitIdx];
        if(predWeight <= weight){
            bridge.push(truck_weights[waitIdx]);
            curWeight += truck_weights[waitIdx++];
        }else{
            bridge.push(0);
        }
        
        // auto copyQ = bridge;
        // while(!copyQ.empty()){
        //     cout << copyQ.front() << ' ';
        //     copyQ.pop();
        // }
        // cout << '\n';
    }
    
    
    return time + bridge_length;
}