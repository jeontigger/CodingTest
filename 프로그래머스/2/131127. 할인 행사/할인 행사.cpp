#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;
bool isSignUp(unordered_map<string, int> wants, unordered_map<string, int> sales){
    // 원하는 할인 품목 일치 검사 - 맵 2개 비교
    for(auto& pair:wants){
        sales[pair.first] -= pair.second;
    }
    
    for(auto& pair:sales){
        if(sales[pair.first] != 0)
            return false;
    }
    return true;
}


int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    unordered_map<string, int> wants, sales;
    
    // 원하는 품목 맵 만들기
    for(int i =0 ; i < want.size(); i++){
        wants[want[i]] += number[i];
    }
    
    // 10일짜리 슬라이딩 윈도우로 할인품목 맵 만들기
    for(int i = 0 ; i < 10; i++){
        sales[discount[i]]++;
    }
    if(isSignUp(wants, sales))
        answer++;
    
    for(int i = 10 ;i < discount.size();i++){
        sales[discount[i]]++;
        sales[discount[i-10]]--;
        
        if(isSignUp(wants, sales)){
            // for(auto& p : wants){
            //     cout << p.first << " " << p.second << endl;
            // }
            // cout << endl;
            // for(auto& p : sales){
            //     cout << p.first << " " << p.second << endl;
            // }
            
            answer++;
        }
    }
    
    
    
    return answer;
}