#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>

using namespace std;
map<string, int> playCnt;

bool cmp(const pair<int, int>& p1, const pair<int, int>& p2){
    if(p1.first != p2.first){
        return p1.first > p2.first;
    }else{
        return p1.second < p2.second;
    }
}
vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    int N = genres.size();
    // [genre] => [play, idx]
    map<string, vector<pair<int, int>>> genreSongs;
    for(int i = 0 ; i < N; i++){
        playCnt[genres[i]] += plays[i];
        genreSongs[genres[i]].push_back(make_pair(plays[i], i));
    }
    
    vector<pair<int, string>> byPlays;
    for(auto iter = playCnt.begin(); iter != playCnt.end(); ++iter){
        byPlays.push_back(make_pair(-iter->second, iter->first));
    }
    
    sort(byPlays.begin(), byPlays.end());
    // for(auto p:byPlays){
    //     cout << p.first << ' ' << p.second << '\n';
    // }
    
    for(auto& p:genreSongs){
        sort(p.second.begin(), p.second.end(), cmp);
    }
    
    for(int i = 0 ; i < byPlays.size(); i++){
        string genre = byPlays[i].second;
        auto vec = genreSongs[genre];
        for(int i = 0 ; i < vec.size() && i < 2; i++){
            answer.push_back(vec[i].second);
        }
    }
    
    
    return answer;
}