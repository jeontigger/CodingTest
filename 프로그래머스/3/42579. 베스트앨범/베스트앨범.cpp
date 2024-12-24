#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <algorithm>
using namespace std;

struct Data{
    int val;
    int idx;
};

struct Data2{
    string genre;
    int val;
};

void PrintMap(unordered_map<string, vector<Data>>& um){
    for(auto& p : um){
        cout << p.first << ' ' ;
        for(auto& d : p.second){
            cout << d.val << ' ' ;
        }
        cout << '\n';
    }
}

bool cmp(const Data&d1, const Data&d2){
    return d1.val != d2.val ? d1.val > d2.val : d1.idx < d2.idx;
}

bool cmp2(const Data2&d1, const Data2&d2){
    return d1.val > d2.val;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    
    unordered_map<string, vector<Data>> um;
    unordered_map<string, int> cntMap;
    vector<Data2> v;
    for(int i = 0 ; i < genres.size(); i++){
        um[genres[i]].push_back({plays[i], i});
        cntMap[genres[i]] += plays[i];
    }
    
    for(auto& p: cntMap){
        v.push_back({p.first, p.second});
    }
    
    sort(v.begin(), v.end(), cmp2);
    
    for(auto& p: um){
        sort(p.second.begin(), p.second.end(), cmp);
    }
    
    PrintMap(um);
    
    for(auto& d: v){
        string genre = d.genre;
        vector<Data>& cnts = um[genre];
        for(int i = 0 ; i < 2 && i < cnts.size(); i++){
            answer.push_back(cnts[i].idx);
        }
    }
    
    return answer;
}