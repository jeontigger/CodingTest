#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i = 0 ; i < scoville.size(); i++){
        pq.push(scoville[i]);
    }
    
    while(!pq.empty()){
        if(pq.top() >= K){
            return answer;
        }
        int s1 = pq.top();
        pq.pop();
        if(pq.empty()) break;
        int s2 = pq.top();
        pq.pop();
        int sNew = s1 + s2 * 2;
        pq.push(sNew);
        
        answer++;
    }
    return -1;
}