#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>

using namespace std;

struct Data{
    int Play;
    int idx;
};

bool cmp(const Data& d1, const Data& d2){
    return d1.Play != d2.Play ? d1.Play > d2.Play : d1.idx < d2.idx;
}

struct SumData{
    string Name;
    int sum;
};

bool sumCmp(const SumData& d1, const SumData& d2){
    return d1.sum > d2.sum;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    map<string, vector<Data>> m;
    
    vector<SumData> sums;
    
    for(int i = 0; i<genres.size(); i++){
        const string& genre = genres[i];
        m[genre].push_back({plays[i], i});
    }
    
    for(auto p : m){
        int sum = 0;
        for(auto i : p.second){
            sum += i.Play;
        }
        sums.push_back({p.first, sum});
    }
    
    sort(sums.begin(), sums.end(), sumCmp);
    
    for(auto& d: sums){
        vector<Data>& v = m[d.Name];
        sort(v.begin(), v.end(), cmp);
        
        int cnt = 0;
        for(Data& i : v){
            answer.push_back(i.idx);
            cnt++;
            if(cnt == 2)
                break;
        }
    }

    
    return answer;
}