#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>

using namespace std;

struct Data{
    int duration;
    int start;
    int idx;
};

struct cmp{
    bool operator()(const Data&d1, const Data&d2){
        if(d1.duration != d2.duration){
            return d1.duration > d2.duration;
        }
        if(d1.start != d2.start){
            return d1.start > d2.start;
        }
        return d1.idx > d2.idx;
    }
};

void PrintVec(vector<vector<int>>& vec){
    for(auto& v: vec){
        for(int i : v){
            cout << i << ' '; 
        }
        cout << endl;
    }
}

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    sort(jobs.begin(), jobs.end());
    priority_queue<Data, vector<Data>, cmp> pq;
    
    int idx = 0;
    for(int i =0; i < 3000000;){
        while(idx < jobs.size() && jobs[idx][0] <= i){
            pq.push({jobs[idx][1], jobs[idx][0], idx});
            idx++;
        }
        
        if(!pq.empty()){
            Data data = pq.top();
            pq.pop();
            i += data.duration;
            answer += i - data.start;
            
        }else{
            i++;
        }
    }
    
    return answer / jobs.size();
}