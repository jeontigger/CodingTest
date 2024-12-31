#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string solution(string number, int k) {
    string answer = number;
    int idx = 0;
    while(k--){
        int idx = 0;
        for( ; idx < number.size() -1 ; idx++){
            if(number[idx] < number[idx+1]){
                break;
            }
        }
        number.erase(number.begin() + idx);
    }
    return number;
}