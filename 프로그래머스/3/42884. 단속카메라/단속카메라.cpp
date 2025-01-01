#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool cmp (const vector<int>& v1, const vector<int>& v2){
    return v1[1] != v2[1] ? v1[1] < v2[1] : v1[0] < v2[0];
}

int solution(vector<vector<int>> routes) {
    int answer = 0;
    // for(auto& v: routes){
    //     sort(v.begin(), v.end());
    // }
    
    sort(routes.begin(), routes.end(), cmp);
    // for(auto& v: routes){
    //     for(int i :v){
    //         cout << i << ' ' ;
    //     }cout << '\n';
    // }
    int endPoint = -1e9;
    for(int i = 0 ; i < routes.size(); i++){
        if(routes[i][0] > endPoint){
            answer++;
            endPoint = routes[i][1];
            // cout << endPoint << ' ';
        }
    }
    
    return answer;
}