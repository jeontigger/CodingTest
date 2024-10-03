#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;

int solution(vector<int> order) {
    int answer = 0;
    
    queue<int> q;
    stack<int> s;
    
    for(int i = 0; i < order.size();i++){
        q.push(i+1);
    }
    
    for(int i = 0; i < order.size();i++){
        
        if(!s.empty() && s.top() == order[i]){
            // cout << "s" << s.top() << endl;
            s.pop();
            answer++;
            continue;
        }
        
        bool isContinue = false;
        while(!q.empty()){
            if(q.front() == order[i]){
                // cout << "q" << q.front() << endl;
                q.pop();
                answer++;
                isContinue = true;
                break;
            }
            s.push(q.front());
            q.pop();
        }
        
        if(isContinue)
            continue;
        break;
    }
    
    
    return answer;
}