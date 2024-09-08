#include <string>
#include <vector>
#include <stack>
#include <iostream>
#include <algorithm>

using namespace std;

struct Data{
    string Name;
    int StartTime;
    int Duration;
};

int StringToTime(const string& str){
    int res;
    int hour = stoi(str.substr(0, 2));
    int min = stoi(str.substr(3, 2));
    res = hour * 60 + min;
    return res;
}

bool cmp(const Data& d1, const Data& d2){
    return d1.StartTime < d2.StartTime;
};

vector<string> solution(vector<vector<string>> plans) {
    vector<string> answer;
    vector<Data> datas;
    for(int i = 0; i<plans.size();i++){
        Data d = {};
        d.Name = plans[i][0];
        d.StartTime = StringToTime(plans[i][1]);
        d.Duration = stoi(plans[i][2]);
        datas.push_back(d);
    }

    // 최초 시작 부터 가장 늦은 시작까지
    int curIdx = 0;
    stack<Data> s;
    sort(datas.begin(), datas.end(), cmp);
    
    for(int i =datas[0].StartTime ; i <= datas.back().StartTime; i++){
        if(datas[curIdx].StartTime == i){
            s.push(datas[curIdx]);
            curIdx++;
        }
        
        if(s.size()!=0){
            s.top().Duration--;
            if(s.top().Duration == 0){
                answer.push_back(s.top().Name);
                s.pop();
            }
        }
    }
    
    while(s.size()>0){
        answer.push_back(s.top().Name);
        s.pop();
    }

    
    return answer;
}