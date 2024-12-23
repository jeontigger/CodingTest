#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    unordered_map<string, int> um;
    for(int i = 0 ; i < phone_book.size(); i++){
        um[phone_book[i]]++;
    }
    
    for(int i = 0 ; i < phone_book.size(); i++){
        for(int j = 0 ; j < phone_book[i].size()-1; j++){
            // cout << phone_book[i].substr(0, j+1) << ' ';
            if(um[phone_book[i].substr(0, j+1)] != 0){
                return false;
            }
        }
        // cout << '\n';
    }
    
    return true;
}