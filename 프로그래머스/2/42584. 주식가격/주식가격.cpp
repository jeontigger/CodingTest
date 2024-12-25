#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

struct Data{
    int idx;
    int val;
};

vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size());
    stack<Data> s;
    int i;
    for(i = 0; i < prices.size(); i++){
        while(!s.empty() && s.top().val > prices[i]){
            Data data = s.top();
            s.pop();
            answer[data.idx] = i - data.idx;
            // cout << data.idx << ' ' << i - data.idx << ' '; 
        }
        // cout << '\n';
        s.push({i, prices[i]});
    }
    while(!s.empty()){
        Data data = s.top();
        s.pop();
        answer[data.idx] = i - data.idx - 1;
        // cout << i - data.idx - 1<< ' '; 
    }
    
    return answer;
}