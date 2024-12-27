#include <string>
#include <vector>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

bool IsPrime(int num){
    if(num < 2) return false;
    if(num == 2) return true;
    if(num%2 == 0) return false;
    
    for(int i = 3; i <= sqrt(num); i += 2){
        if(num % i == 0){
            return false;
        }
    }
    return true;
}
set<int> s;

vector<bool> visited;
void Recursive(const string& numbers, string& path){
    if(path != ""){
        int num = stoi(path);
        if(IsPrime(num)){
            s.insert(num);
        }
    }
    
    if(path.size() == numbers.size())
        return;
    
    for(int i = 0 ; i < numbers.size(); i++){
        if(visited[i]) continue;
        visited[i] = true;
        path += numbers[i];
        Recursive(numbers, path);
        path.pop_back();
        visited[i] = false;
    }
}

int solution(string numbers) {
    int answer = 0;
    visited.resize(numbers.size());
    
    string path = "";
    Recursive(numbers, path);
    answer = s.size();
    return answer;
}