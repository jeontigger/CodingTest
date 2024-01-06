#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    
    vector<int> bitOR;
    for(int i = 0; i < arr1.size();i++){
        bitOR.push_back(arr1[i]|arr2[i]);
    }
    
    for(int i : bitOR){
        cout << i << " ";
    }
    cout << endl;
    for(int i = 0; i < n ;i++){
        int num = bitOR[i];
        
        string tmp = "";
        
        for(int j = 0; j < n ; j++){
            if(bool(num & (1 << (n - j - 1)))){
                tmp += '#';
            }else{
                tmp += ' ';
            }
        }
        answer.push_back(tmp);
    }
    
    return answer;
}