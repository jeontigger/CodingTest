#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    priority_queue<int, vector<int>, greater<int>> pq;
    int answer = 0;
    
    for(int i:scoville){
        pq.push(i);
    }
    
    while(pq.size()>1 && pq.top() <K){
        int first = pq.top();
        pq.pop();
        int second = pq.top();
        pq.pop();
        
        pq.push(first + second*2);
        answer++;
    }
    
    if(pq.top() < K)
        return -1;
    
    
    return answer;   
    
}